// Common data format tools
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

char *dataformat_telephone_n(char *target,int len,const char *source,int space,int uktel);
#define	dataformat_telephone(source,space,uktel) dataformat_telephone_n(alloca(40),40,source,space,uktel)

char *dataformat_email_n(char *target,int len,const char *source);
#define dataformat_email(source) dataformat_email_n(alloca(256),256,source)

char *dataformat_email_hidden_n(char *target,int len,const char *source);
#define dataformat_email_hidden(source) dataformat_email_hidden_n(alloca(256),256,source)

char *dataformat_postcode_n(char *target,int len,const char *source,int space);
#define	dataformat_postcode(source,space) dataformat_postcode_n(alloca(9),9,source,space)

char *dataformat_domain_n(char *target,int len,const char *source);
#define dataformat_domain(source) dataformat_domain_n(alloca(256),256,source)

char * dataformat_token_n (char *target, int len, const char *source,const char*chars);
#define dataformat_token(source,chars) dataformat_token_n(alloca(strlen(source?:"")+1),strlen(source?:"")+1,source,chars)

char * dataformat_posttown_n (char *target, int len, const char *source);
#define dataformat_posttown(source) dataformat_posttown_n(alloca(strlen(source?:"")+1),strlen(source?:"")+1,source)

char * dataformat_name_n (char *target, int len, const char *source);
#define dataformat_name(source) dataformat_name_n(alloca(strlen(source?:"")+1),strlen(source?:"")+1,source)

char * dataformat_toot_n (char *target, int len, const char *source);
#define dataformat_toot(source) dataformat_toot_n(alloca(strlen(source?:"")+1),strlen(source?:"")+1,source)

char * dataformat_azn_n (char *target, int len, const char *source);
#define dataformat_azn(source) dataformat_azn_n(alloca(strlen(source?:"")+1),strlen(source?:"")+1,source)

