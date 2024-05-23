// General data field format (e.g. postcodes and telephone numbers)

    /*
       Copyright (C) 2001-2017  RevK and Andrews & Arnold Ltd

       This program is free software: you can redistribute it and/or modify
       it under the terms of the GNU General Public License as published by
       the Free Software Foundation, either version 3 of the License, or
       (at your option) any later version.

       This program is distributed in the hope that it will be useful,
       but WITHOUT ANY WARRANTY; without even the implied warranty of
       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
       GNU General Public License for more details.

       You should have received a copy of the GNU General Public License
       along with this program.  If not, see <http://www.gnu.org/licenses/>.
     */

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <err.h>
#include "dataformat.h"
#include "unicodeaz.h"

char space = 0;
char uktel = 0;
char ftype = 'a';

// format a postcode (formats to static buffer)
char *
dataformat_postcode_n (char *res, int len, const char *p, int space)
{
   if (!p)
      return NULL;
   int f = 0,
      t = 0;
   while (p[f] && t < len - 2)  // make sure not too long, allowing for space to be added later
      if (isalnum (p[f]))
         res[t++] = toupper (p[f++]);
      else
         f++;
   if (p[f])
      return NULL;              // too long 
   res[t] = 0;
   if (t < 5 || t > 7)
      return NULL;              // wrong length
   f = 0;
   if (isalpha (res[f]))        // letter
   {
      f++;
      if (isalpha (res[f]))
         f++;                   // optional second letter
      if (isdigit (res[f]))     // digit
      {
         f++;
         if (t - f == 4)
            f++;                // optional second digit or letter
         if (t - f == 3 && isdigit (res[f]) && isalpha (res[f + 1]) && isalpha (res[f + 2]))
         {                      // digit letter letter
            if (space)
            {
               memmove (res + t - 2, res + t - 3, 4);
               res[t - 3] = ' ';
               t++;
            }
            return res;
         }
      }
   }
   return NULL;                 // bad format
}

// format a telephone number (formats to a static buffer)
// space means add appropriate spaces (for UK numbers)
// uktel means output as Uk national number (otherwise int format)
char *
dataformat_telephone_n (char *res, int len, const char *p, int space, int uktel)
{
   if (!p)
      return NULL;
   int f = 0,
      t = 0;
   // first normalise number to international format
   if (p[f] == '+')
      res[t++] = p[f++];        // int prefix
   while (p[f] && t < len - 10)
      if (isdigit (p[f]))
         res[t++] = p[f++];
      else if (p[f] == '-' || p[f] == '(' || p[f] == ')' || p[f] == '-' || p[f] == '.' || p[f] == ' ')
         f++;
      else
         return NULL;
   if (p[f])
      return NULL;              // too long
   res[t] = 0;
   if (res[0] == '0' && res[1] == '0' && res[2] != '0') // International 00 prefix
   {
      res[0] = '+';
      memmove (res + 1, res + 2, t - 1);
      t--;
   }
   if (res[0] == '0' && res[1] != '0')  // Local 0 prefix, assume UK
   {
      memmove (res + 3, res + 1, t);
      res[0] = '+';
      res[1] = '4';
      res[2] = '4';
      t += 2;
   }
   if (res[0] != '+' && res[0] != '0' && t > 10 && t + 1 < len - 10)
   {                            // Messy, assume international without the +
      memmove (res + 1, res, ++t);
      res[0] = '+';
   }
   if (res[0] != '+')
      return NULL;              // local number, or something wrong
   if (res[1] == '0')
      return NULL;              // +0 is not sensible

   if (res[1] == '4' && res[2] == '4')
   {                            // is a UK number
      if (t < 12 || t > 13)
         return NULL;           // bad length
      if (space)
      {                         // space out the number
         unsigned long spacing = 0;     // bit map of where to put spaces...
         if (res[3] == '2')
         {
            if (t != 13)
               return NULL;     // bad length
            if (res[4] == '0' && res[5] == '0')
            {
               if (res[6] == '0')
               {
                  if (res[8] == '0' && res[9] == '0' && res[10] == '0')
                     spacing = 0x444;
                  else
                     spacing = 0x44;
               }
            } else
            {
               if (res[5] <= '1' || (res[5] == '9' && res[6] == '9' && res[7] == '9'))
                  return NULL;  // bad content
               spacing = 0x114; // +44 2X XXXX XXXX
            }
         } else if (res[3] == '1' && (res[4] == '1' || res[5] == '1'))
         {
            if (t != 13)
               return NULL;     // bad length
            if (res[6] <= '1' || (res[6] == '9' && res[7] == '9' && res[8] == '9'))
               return NULL;     // bad content
            spacing = 0x124;    // +44 1XX XXX XXXX
         } else if (res[3] == '1')
         {
            if (res[7] <= '1' || (res[7] == '9' && res[8] == '9' && res[9] == '9'))
               return NULL;     // bad content
            spacing = 0x44;     // +44 1XXX XXXXXX
         } else if (res[3] == '3' || res[3] == '5')
         {
            if (t != 13)
               return NULL;     // bad length
            spacing = 0x54;     // +44 3X XX XXXXXX
         } else if (res[3] == '7')
         {
            if (t != 13)
               return NULL;     // bad length
            spacing = 0x44;     // +44 7XXX XXXXXX
         } else if (res[3] == '8')
         {
            if (t == 13)
               spacing = 0x44;  // +44 8XXX XXXXXX
            else
               spacing = 0x24;  // +44 8XX XXXXXX
         }
         // extra spacing on ... XXXXXX
         if (space == 2 && (spacing & 0xFFE0) == 0x40)
         {
            if (res[t - 6] == res[t - 3] || res[t - 5] == res[t - 4])
               spacing |= (1 << (t - 4));
            else if ((res[t - 6] == res[t - 4] && res[t - 4] == res[t - 2])
                     || (res[t - 5] == res[t - 3] && res[t - 3] == res[t - 1]))
               spacing |= (1 << (t - 5)) | (1 << (t - 3));
         }
         // apply spacing
         for (f = t - 2; f >= 0; f--)
            if (spacing & (1 << f))
            {
               memmove (res + f + 2, res + f + 1, t - f);
               res[f + 1] = ' ';
               t++;
            }
      }
      if (uktel)
      {                         // change to UK dialling
         if (res[3] == ' ')
         {
            memmove (res + 1, res + 4, t - 3);
            t -= 3;
         } else
            memmove (res + 1, res + 3, t - 2);
         t -= 2;
         res[0] = '0';
      }
   } else if (t > 16)
      return NULL;              // too long
   else if (t < 8)
      return NULL;              // too short
   return res;
}

char *
ccard (char *d)
{
   char *i,
    *o,
     c = 0;
   int p;

   for (i = d, o = i; *i; i++)
      if (isdigit (*i))
         *o++ = *i;
   *o = 0;

   if (strlen (d) < 6)
      return NULL;
   if (strlen (d) > 19)
      return NULL;
   for (p = strlen (d) - 1; p >= 0; p--)
   {
      c += d[p] - '0';
      c %= 10;
      if (p > 0)
      {
         char q;

         p--;
         q = d[p] - '0';
         q *= 2;
         if (q > 9)
            q -= 9;
         c += q;
         c %= 10;
      }
   }
   if (c)
      return NULL;
   if (space)
   {
      static char res[50];
      o = res;
      if (strlen (d) == 16)
      {
         for (p = 0; p < 16; p++)
         {
            if (p && !(p % 4))
               *o++ = ' ';
            *o++ = d[p];
         }
      } else
      {
         for (p = 0; p < 6 && p < (int) strlen (d); p++)
            *o++ = d[p];
         for (; p < (int) strlen (d); p++)
         {
            if (p % 4 == 2)
               *o++ = ' ';
            *o++ = d[p];
         }
      }
      *o = 0;
      d = res;
   }
   return d;
}

char *
words (char *c)
{
   char *a = c,
      *b = c;
   while (*a)
   {
      if (*a == '(')
      {
         *b++ = *a++;
         while (isalpha (*a))
            *b++ = *a++;
         if (*a == ')')
            *b++ = *a++;
      } else if (isalpha (*a))
      {
         if (uktel || a == c || isspace (a[-1]))
            *b++ = toupper (*a);
         else if (isalpha (a[-1]) && (a < c + 3 || a[-3] != 'M' || a[-2] != 'a' || a[-1] != 'c')
                  && (a < c + 2 || a[-2] != 'M' || a[-1] != 'c'))
            *b++ = tolower (*a);
         else
            *b++ = *a;
         a++;
      } else if (isdigit (*a) || *a == '-' || *a == '\'' || *a == '&' || *a == '.')
         *b++ = *a++;
      else if (space && isspace (*a) && a != c && !isspace (a[-1]))
      {
         *b++ = ' ';
         a++;
      } else
         a++;
   }
   while (b > c && isspace (b[-1]))
      b--;
   if (*b)
      *b = 0;
#if 0
   for (a = c; *a; a++)
   {
      if (*a == 'M' && (a == c || isspace (a[-1])) && a[1] == 'c' && isalpha (a[2]))
         a[2] = toupper (a[2]);
   }
#endif
   return c;
}

char *
dataformat_email_n (char *target, int len, const char *source)
{                               // Email syntax check and case fix
   if (!source)
      return NULL;
   if ((int) strlen (source) >= len)
      return NULL;
   strcpy (target, source);
   int dot = 0;
   char *i = target;
   if (*i == '"')
   {                            // quoted local part
      i++;
      while (*i && *i != '"')
      {
         if (*i == '\\' && i[1])
            i++;
         i++;
      }
      if (*i != '"')
         return NULL;
      i++;
   } else
      while (*i && *i != '@')
      {
         if (*i == '.')
         {
            if (i == target || i[1] == '@' || i[1] == '.')
               return NULL;     // invalid use of a dot
         } else if (!(isalnum (*i) || strchr ("!#$%&'*+-/=?^_`{|}~", *i)))
            return NULL;
         i++;
      }
   if (!*i)
      return NULL;
   if (*i != '@')
      return NULL;
   i++;
   if (!*i)
      return NULL;
   while (*i)
   {
      *i = tolower (*i);
      if (*i != '.' && *i != '-' && !isalnum (*i))
         return NULL;
      if ((*i == '-' || *i == '.') && (i[-1] == '@' || i[-1] == '.' || i[1] == '.' || !i[1]))
         return NULL;
      if (*i == '.')
         dot++;
      i++;
   }
   if (i[-2] == '.' || i[-2] == '@')
      return NULL;
   if (!dot)
      return NULL;
   return target;
}

char *
dataformat_email_hidden_n (char *target, int len, const char *source)
{                               // Email syntax check and case fix
   target = dataformat_email_n (target, len, source);
   if (target)
   {                            // Obfuscate local part
      int n;
      for (n = 0; target[n] != '@'; n++);
// The domain should be fully visible to aid the customer to
// identify the email hosting provider the email went to. It Is
// recommended to mask all but 2 characters of the email
// address. If the addressee is 4 or 5 characters, then all but 1
// character must be masked, and if the addressee is less than 4
// characters then all characters of the addressee must be
// obfuscated. For example…
      int a = 0;
      if (n > 5)
         a = 2;
      else if (n > 3)
         a = 1;
      n -= a;
      int s = a / 2;
      while (n--)
         target[s++] = '*';
   }
   return target;

}

char *
dataformat_domain_n (char *target, int len, const char *source)
{                               // Domain syntax check and lower case
   if ((int) strlen (source) >= len)
      return NULL;
   if (source != target)
      strcpy (target, source);
   int dot = 0;
   char *i = target;
   while (*i)
   {
      *i = tolower (*i);
      if (*i != '.' && *i != '-' && !isalnum (*i))
         return NULL;
      if ((*i == '-' || *i == '.') && (i == target || i[-1] == '.' || i[1] == '.' || !i[1]))
         return NULL;
      if (*i == '.')
         dot++;
      i++;
   }
   if (i >= target + 2 && i[-2] == '.')
      return NULL;
   if (!dot)
      return NULL;
   return target;
}

char *
dataformat_token_n (char *target, int len, const char *source, const char *chars)
{                               // Check for token (letter then letters+numbers + chars) and upper case
   if ((int) strlen (source) >= len)
      return NULL;
   strcpy (target, source);
   char *i = target;
   if (!isalpha (*target))
      return NULL;
   *i = toupper (*i);
   i++;
   while (*i)
   {
      *i = toupper (*i);
      if (!isalnum (*i) && (!chars || !strchr (chars, *i)))
         return NULL;
      i++;
   }
   return target;
}

char *
dataformat_posttown_n (char *target, int len, const char *source)
{                               // Check for post town - letters only allowing hyphens, and upper case
   if ((int) strlen (source) >= len)
      return NULL;
   strcpy (target, source);
   char *i = target;
   while (*i)
   {
      *i = toupper (*i);
      if (*i != ' ' && !isalpha (*i))
         return NULL;
      i++;
   }
   return target;
}

char *
dataformat_name_n (char *target, int len, const char *source)
{                               // Check format for a name - force to initial upper then lower on each word
   if ((int) strlen (source) >= len)
      return NULL;
   strcpy (target, source);
   char *i = target,
      last = ' ';
   while (*i)
   {
      if (isalpha (last))
         *i = tolower (*i);
      else
         *i = toupper (*i);
      last = *i++;
   }
   return target;
}

char *
dataformat_az_n (char *target, int len, const char *source)
{                               // Reduce to just letters A-Z and single space separators
   // • Any accented characters will be replaced by the equivalent non-accented character.
   // • All characters will be converted to upper case.
   // • Any characters outside of A-Z will be removed.
   char *o = target;
   char *end = o + len - 1;
   char space = 0;
   while (*source)
   {
      char c[6],
       *cp = c;
      *cp++ = *source++;
      while (cp < c + sizeof (c) - 1 && (*source & 0xC0) == 0x80)
         *cp++ = *source++;
      *cp = 0;
      if (strstr (unicode_space, c))
         space = 1;
      else
         for (int i = 0; i < 26; i++)
            if (strstr (unicode_az[i], c))
            {
               if (space && o > target && o < end)
                  *o++ = ' ';
               if (o < end)
                  *o++ = 'A' + i;
               space = 0;
               break;
            }
   }
   if (o < end)
      *o++ = 0;
   return target;
}

char *
dataformat_toot_n (char *target, int len, const char *source)
{                               // Check and normalise format for a fediverse handle (some assumptions here)
   if ((int) strlen (source) >= len)
      return NULL;
   if (!strncasecmp (source, "https://", 8))
   {                            // Work on basis of https://host/@handle and normalise
      char *o = target;
      const char *i = strrchr (source, '@');
      if (!i)
         return NULL;
      while (*i)
         *o++ = *i++;
      *o++ = '@';
      i = source + 8;
      while (*i != '/')
         *o++ = *i++;
      *o = 0;
   } else
      strcpy (target, source);
   // Expect @handle@host
   char *i = target;
   if (*i++ != '@')
      return NULL;
   while (isalnum (*i) || *i == '_')
      i++;
   if (i == target + 1)
      return NULL;
   if (*i++ != '@')
      return NULL;
   if (!dataformat_domain_n (i, len - (i - target), i))
      return NULL;
   return target;
}

char *
dated (char *s)
{
   int a,
     b,
     c;
   char timed = 0;
   static char o[100];
   struct tm t = { 0 };

   if (sscanf (s, "%d-%d-%d", &a, &b, &c) == 3)
      t.tm_year = a - 1900, t.tm_mon = b - 1, t.tm_mday = c;
   else if (sscanf (s, "%d/%d/%d", &a, &b, &c) == 3 && c >= 100 && b <= 12)
      t.tm_year = c - 1900, t.tm_mon = b - 1, t.tm_mday = a;
   else if (sscanf (s, "%d/%d/%d", &a, &b, &c) == 3 && c < 100 && b <= 12)
   {
      t.tm_year = c, t.tm_mon = b - 1, t.tm_mday = a;
      if (c < 50)
         t.tm_year += 100;
   }

   while (*s && *s != ' ' && *s != 'T')
      s++;
   if (*s == ' ' || *s == 'T')
      s++;

   if (sscanf (s, "%d:%d:%d", &a, &b, &c) == 3)
      t.tm_hour = a, t.tm_min = b, t.tm_sec = c, timed = 1;
   else if (sscanf (s, "%d:%d", &a, &b) == 2)
      t.tm_hour = a, t.tm_min = b, timed = 1;

   t.tm_isdst = -1;
   mktime (&t);
   sprintf (o, "%04d-%02d-%02d %02d:%02d:%02d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
   if (!timed)
      o[10] = 0;
   if (*o == '0')
      return "";
   return o;
}

char *
net (char *s)
{
   static char o[50];
   char temp[100];
   int bits = -1,
      res;
   char *p = strchr (s, '/');
   if (p)
   {
      *p++ = 0;
      bits = atoi (p);
   }
   int af;
   res = inet_pton (af = AF_INET, s, temp);
   if (res <= 0)
      res = inet_pton (af = AF_INET6, s, temp);
   if (res <= 0)
      return "";
   int max = (af == AF_INET ? 32 : 128);
   if (bits > max)
      return "";
   if (space && bits > 0)
   {
      int b = bits;
      if (b & 7)
      {
         temp[b / 8] &= (0xFF00 >> (b & 7));
         b = (b | 7) + 1;
      }
      while (b < max)
      {
         temp[b / 8] = 0;
         b += 8;
      }
   }
   inet_ntop (af, temp, o, sizeof (o));
   if (bits >= 0 && !uktel)
      sprintf (o + strlen (o), "/%d", bits);
   return o;
}

char *
form (char *i)
{
   static char out[1000];
   char *o = out,
      *e = out + sizeof (out);
   while (*i && o + 4 < e)
   {
      if (*i == ' ')
         *o++ = '+';
      else if (*i < ' ' || *i >= 0x7F || !isalnum (*i))
         o += snprintf (o, e - o, "%%%02X", *i);
      else
         *o++ = *i;
      i++;
   }
   *o = 0;
   return out;
}

#ifndef LIB
// main
int
main (int argc, char *argv[])
{
   char envexpand = 0;
   int a,
     y = 0,
      n = 0;
   for (a = 1; a < argc; a++)
   {
      if (*argv[a] == '-')
      {
         char *s = argv[a] + 1;
         while (*s)
            switch (*s++)
            {
            case 's':
               if (space)
                  space = 0;
               else
               {
                  space = 1;
                  if (s[-1] == 'S')
                     space = 2;
               }
               break;
            case 'u':
               uktel = 1;
               break;
            case 'i':
               uktel = 0;
               break;
            case 'x':
               envexpand = 1;
               break;
            default:
               ftype = s[-1];
               break;
            }
      } else
      {                         // format
         char *res = 0;
         char *e = argv[a];
         if (envexpand)
            e = getenv (e);
         if (!e)
            e = "";
         if (ftype == 't' || (ftype == 'a' && (*e == '+' || isdigit (*e))))
            res = dataformat_telephone (e, space, uktel);
         else if (ftype == 'p' || (ftype == 'a' && isalpha (*e)))
            res = dataformat_postcode (e, space);
         else if (ftype == 'c')
            res = ccard (e);
         else if (ftype == 'w')
            res = words (e);
         else if (ftype == 'e')
            res = dataformat_email (e);
         else if (ftype == 'E')
            res = dataformat_email_hidden (e);
         else if (ftype == 'z')
            res = dataformat_az (e);
         else if (ftype == 'D')
            res = dataformat_domain (e);
         else if (ftype == 'T')
            res = dataformat_toot (e);
         else if (ftype == 'd')
            res = dated (e);
         else if (ftype == 'n')
            res = net (e);
         else if (ftype == 'f')
            res = form (e);
         else
            errx (1, "Unknown format");
         if (res)
         {
            if (y)
               printf ("\n");   // More than one result
            y++;
            printf ("%s", res);
         } else
            n++;
      }
   }
   if (!y && !n)
      fprintf (stderr,
               "dataformat [-tpasuicwedxD] <fields>\n-t\tTelephone numbers expected\n-p\tPostcodes expected\n-a\tAuto identify\n-s\tSpace the output\n-i\tInt format telephone number\n-u\tUK format telephone numbers\n-c\tCredit card number\n-w\tWords\n-e\tEmail\n-d\tDate\n-x\tExpand env name\n-n\tNetwork ip/bits\n-D\tDomain\n");
   return !y;
}
#endif
