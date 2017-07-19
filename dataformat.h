// Common data format tools

char *dataformat_telephone_n(char *target,int len,const char *source,int space,int uktel);
#define	dataformat_telephone(source,space,uktel) dataformat_telephone_n(alloca(40),40,source,space,uktel)

char *dataformat_email_n(char *target,int len,const char *source);
#define dataformat_email(source) dataformat_email_n(alloca(256),256,source)

char *dataformat_postcode_n(char *target,int len,const char *source,int space);
#define	dataformat_postcode(source,space) dataformat_postcode_n(alloca(9),9,source,space)

char *dataformat_domain_n(char *target,int len,const char *source);
#define dataformat_domain(source) dataformat_domain_n(alloca(256),256,source)

char * dataformat_token_n (char *target, int len, const char *source,const char*chars);
#define dataformat_token(source,chars) dataformat_token_n(alloca(strlen(source)+1),strlen(source)+1,source,chars)

char * dataformat_posttown_n (char *target, int len, const char *source);
#define dataformat_posttown(source) dataformat_posttown_n(alloca(strlen(source)+1),strlen(source)+1,source)

char * dataformat_name_n (char *target, int len, const char *source);
#define dataformat_name(source) dataformat_name_n(alloca(strlen(source)+1),strlen(source)+1,source)

