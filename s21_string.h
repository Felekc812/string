#ifndef SRC_S21_STRING_H_  //  SRC_S21_STRING_H_
#define SRC_S21_STRING_H_  //  SRC_S21_STRING_H_
#define s21_size_t unsigned long long int
#define s21_NULL (void*)0
#include <stdarg.h>
#define FLAGS "-+ #0"

s21_size_t s21_strlen(const char *s);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strspn(const char* str1, const char* str2);
char *s21_strcpy(char* destination, const char* source);
char *s21_strncpy(char *destination, const char *source, s21_size_t n);
char *s21_strcat(char *destination, const char *source);
char* s21_strncat(char* destination, const char* source, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strtok(char *str, const char* delim);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strerror(int errnum);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
void s21_reverse(char tmp[], int len);

// scanf

unsigned char hdigit(unsigned char c);
unsigned HEX_TO_DEC(char* hx);
unsigned long LONG_HEX_TO_DEC(char* hx);
unsigned int OCT_TO_DEC(int n);
long unsigned int LONG_OCT_TO_DEC(long int n);

int s21_sscanf(char *buf, const char *format, ...);
int s21_intlen(int n);
long int s21_longintlen(long int n);
int strToInt(char* buf, int *j, int width, int *returning);
long int strToLongInt(char* buf, int *j, int width, int *returning);
int strToIntFormat(const char* buf, int* j);
void strTostr(char* buf, char* str, int* j, int width, int *returning);
float strToFloat(char* buf, int*j, int width, int *returning);
unsigned int strToIntX(char* buf, int* j, int width, int *returning);
long unsigned int strToLongIntX(char* buf, int* j, int width, int *returning);
unsigned int strToIntO(char* buf, int* j, int width, int *returning);
long unsigned int strToLongIntO(char* buf, int* j, int width, int *returning);
long double strToDouble(char* buf, int*j, int width, int *returning);



// sprintf

int s21_sprintf(char *buf, const char *format, ...);

void trasletionFromIntegerInStr(long long d, char *str, int flagPlus,
                                 int flagSpace, int lenInteger, int nPrecision);
void trasletionFromFloatInStr(double f, char *str, int flagPlus
                               , int flagSpace, int nPrecision, int flagDrid);
void trasletionFromUnsignedIntegerInStr(unsigned long d, char *str, int nPrecision);
void writeInBuf(char *buf, char *str, int *j, int *nSpace, int flagMinus, int flag0);
int digitCounter(const char* format, int* i);
int countNumbersInterger(long long d);
void transletionEInStr(double e, char *str, int flagPlus, int flagSpace, int nPrecision, int flagDrid);
char digit(int num);
int dectox_int(unsigned long long a, int p, char *s);
void transletionGInStr(double g, char *str, int flagPlus, int flagSpace, int nPrecision, int flagDrid);
void flags(const char *format, int *i, int *flagPlus,
            int *flagMinus, int *flagSpace, int *flagDrid, int *flag0);



#endif  // SRC_S21_STRING_H_


