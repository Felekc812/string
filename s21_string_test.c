#include "s21_string.h"

#include <check.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

START_TEST(getPassTest) {
  char str1[] = "000";
  char str2[] = "111111";
  int n = 2;
  char str[] = "qwer tr";
  char delim[] = " ";

  char src[255] = "qwer tr";
  char dest[255] = "pppppp";
  char dest1[255] = "pppppp";
  char dest2[255] = "pppppp";
  char src1[255] = "qwer tr";
  char src2[255] = "qwer tr";
  int c = 119;

  char haystack[] = "qwer tr";
  char needle[] = "tr";
  int errnum = 15;

  const char str111[] = "simpl#XCVatesta";
  int str222 = 'l';

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));

  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));

  ck_assert_str_eq(s21_strcat(dest1, src1), strcat(dest2, src2));
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
  ck_assert_str_eq(s21_strncat(dest, src, 30), strncat(dest, src, 30));
  ck_assert_ptr_eq(strrchr(str111, str222), s21_strrchr(str111, str222));
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));

  ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest, src));
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(getPassTest2) {
  char str1[255] = "qwer";
  char str2[255] = "qwer";
  int n = 3;

  char str[255] = "000000";
  char delim[255] = "0";

  char src[255] = "11111";
  char dest[225] = "0000";
  int c = 3;

  char haystack[255] = "qwer tr";
  char needle[255] = "qr";
  int errnum = 26;

  const char str333[] = "testot1191";
  int str444 = '9';

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));

  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));

  ck_assert_str_eq(s21_strcat(dest, src), strcat(dest, src));
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
  ck_assert_ptr_eq(strrchr(str333, str444), s21_strrchr(str333, str444));
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));

  ck_assert_pstr_eq(s21_strcpy(dest, "abcd"), strcpy(dest, "1234"));
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(getPassTest3) {
  char str1[255] = "asdfg";
  char str2[255] = "zxcvvvvvvv";
  int n = 5;

  char str[255] = "wwwwww";
  char str4[255] = "wwwwww";
  char delim[25] = "k";
  char src[255] = "wwwwww";
  char dest[255] = "wwwwww";
  int c = 55;

  char haystack[255] = "qwer tr";
  char needle[255] = "";

  int errnum = 66;

  const char str555[] = "\n";
  int str666 = '\0';

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));

  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
  ck_assert_str_eq(s21_memset(str, c, n), memset(str4, c, n));
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));

  ck_assert_str_eq(s21_strcat(dest, src), strcat(dest, src));
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
  ck_assert_ptr_eq(strrchr(str555, str666), s21_strrchr(str555, str666));
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));

  ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest, src));
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(getPassTest4) {
  char str1[255] = "hrtyhthtyhtyh";
  char str2[255] = "";
  int n = 0;

  char str[255] = "wwww1w";
  char delim[255] = "1";
  char src[255] = "wwww1w";
  char dest[255] = "wwwwww";
  int c = 0;

  char haystack[255] = "qwer tr";
  char needle[255] = " ";

  int errnum = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));

  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));

  ck_assert_str_eq(s21_strcat(dest, src), strcat(dest, src));
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));

  ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest, src));
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(getPassTest5) {
  char str1[255] = " ";
  char str2[255] = " ";
  int n = 0;

  char str[255] = " ";
  char delim[255] = " ";
  char src[255] = " ";
  char dest[255] = " ";
  int c = 0;

  char haystack[255] = "";
  char needle[255] = " ";

  int errnum = 76;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));

  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));

  ck_assert_str_eq(s21_strcat(dest, src), strcat(dest, src));
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));

  ck_assert_str_eq(s21_strcpy(dest, src), strcpy(dest, src));
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}

END_TEST

START_TEST(getPassTest6) {
  char str1[1000];
  char str[1000];
  ck_assert_int_eq(s21_sprintf(str, "%d", 5), sprintf(str1, "%d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%i", 5), sprintf(str1, "%i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%.0f", 2.5), sprintf(str1, "%.0f", 2.5));
  ck_assert_int_eq(s21_sprintf(str, "%.0f", 3.5), sprintf(str1, "%.0f", 3.5));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.45), sprintf(str1, "%.1f", 0.45));
  ck_assert_int_eq(s21_sprintf(str, "%.0f", 5.5), sprintf(str1, "%.0f", 5.5));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.65), sprintf(str1, "%.1f", 0.65));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.75), sprintf(str1, "%.1f", 0.75));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.85), sprintf(str1, "%.1f", 0.85));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.95), sprintf(str1, "%.1f", 0.95));
  ck_assert_int_eq(s21_sprintf(str, "%s", "abcd"), sprintf(str1, "%s", "abcd"));
  ck_assert_int_eq(s21_sprintf(str, "%u", -1), sprintf(str1, "%u", -1));
  ck_assert_int_eq(s21_sprintf(str, "%%"), sprintf(str1, "%%"));
  ck_assert_int_eq(s21_sprintf(str, "%c", '_'), sprintf(str1, "%c", '_'));
  ck_assert_int_eq(s21_sprintf(str, "%d", 1234), sprintf(str1, "%d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%i", 1234), sprintf(str1, "%i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%f", 1565.1337),
                   sprintf(str1, "%f", 1565.1337));
  ck_assert_int_eq(s21_sprintf(str, "%s", "aSS.FASa"),
                   sprintf(str1, "%s", "aSS.FASa"));
  ck_assert_int_eq(s21_sprintf(str, "%u", 65535), sprintf(str1, "%u", 65535));
  ck_assert_int_eq(s21_sprintf(str, "%c", 'd'), sprintf(str1, "%c", 'd'));
  ck_assert_int_eq(s21_sprintf(str, "%d", -1234), sprintf(str1, "%d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "%i", 0), sprintf(str1, "%i", 0));
  ck_assert_int_eq(s21_sprintf(str, "%f", -5.1234),
                   sprintf(str1, "%f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%s", ""), sprintf(str1, "%s", ""));
  ck_assert_int_eq(s21_sprintf(str, "%u", 77), sprintf(str1, "%u", 77));

  ck_assert_int_eq(s21_sprintf(str, "%-d", 5), sprintf(str1, "%-d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%-i", 5), sprintf(str1, "%-i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%-f", 5.1234),
                   sprintf(str1, "%-f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%-s", "abcd"),
                   sprintf(str1, "%-s", "abcd"));
  ck_assert_int_eq(s21_sprintf(str, "%-u", -1), sprintf(str1, "%-u", -1));
  ck_assert_int_eq(s21_sprintf(str, "%-d", 1234), sprintf(str1, "%-d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%-i", 1234), sprintf(str1, "%-i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%-f", 1565.1337),
                   sprintf(str1, "%-f", 1565.1337));
  ck_assert_int_eq(s21_sprintf(str, "%-s", "aSS.FASa"),
                   sprintf(str1, "%-s", "aSS.FASa"));
  ck_assert_int_eq(s21_sprintf(str, "%-u", 65535), sprintf(str1, "%-u", 65535));
  ck_assert_int_eq(s21_sprintf(str, "%-d", -1234), sprintf(str1, "%-d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "%-i", 0), sprintf(str1, "%-i", 0));
  ck_assert_int_eq(s21_sprintf(str, "%-f", -5.1234),
                   sprintf(str1, "%-f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%-s", ""), sprintf(str1, "%-s", ""));
  ck_assert_int_eq(s21_sprintf(str, "%-u", 25), sprintf(str1, "%-u", 25));

  ck_assert_int_eq(s21_sprintf(str, "% -d", -1234),
                   sprintf(str1, "% -d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "% -i", 0), sprintf(str1, "% -i", 0));
  ck_assert_int_eq(s21_sprintf(str, "% -f", -5.1234),
                   sprintf(str1, "% -f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "% -d", 1234), sprintf(str1, "% -d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "% -i", 1234), sprintf(str1, "% -i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "% -f", 1565.1337),
                   sprintf(str1, "% -f", 1565.1337));

  ck_assert_int_eq(s21_sprintf(str, "%-+d", 5), sprintf(str1, "%-+d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%-+i", 5), sprintf(str1, "%-+i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%-+f", 5.1234),
                   sprintf(str1, "%-+f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%-+d", 1234), sprintf(str1, "%-+d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%-+i", 1234), sprintf(str1, "%-+i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%-+f", -5.1234),
                   sprintf(str1, "%-+f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%-+d", -1234),
                   sprintf(str1, "%-+d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "%-+i", 0), sprintf(str1, "%-+i", 0));
  ck_assert_int_eq(s21_sprintf(str, "%-+f", 555.0),
                   sprintf(str1, "%-+f", 555.0));

  ck_assert_int_eq(s21_sprintf(str, "%+d", 5), sprintf(str1, "%+d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%+i", 5), sprintf(str1, "%+i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%+f", 5.1234),
                   sprintf(str1, "%+f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%+d", 1234), sprintf(str1, "%+d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%+i", 1234), sprintf(str1, "%+i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%+f", -5.1234),
                   sprintf(str1, "%+f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%+d", -1234), sprintf(str1, "%+d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "%+i", 0), sprintf(str1, "%+i", 0));
  ck_assert_int_eq(s21_sprintf(str, "%+f", 555.0), sprintf(str1, "%+f", 555.0));

  ck_assert_int_eq(s21_sprintf(str, "% d", 5), sprintf(str1, "% d", 5));
  ck_assert_int_eq(s21_sprintf(str, "% i", 5), sprintf(str1, "% i", 5));
  ck_assert_int_eq(s21_sprintf(str, "% f", 5.1234),
                   sprintf(str1, "% f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "% d", 1234), sprintf(str1, "% d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "% i", 1234), sprintf(str1, "% i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "% f", -5.1234),
                   sprintf(str1, "% f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "% d", -1234), sprintf(str1, "% d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "% i", 0), sprintf(str1, "% i", 0));
  ck_assert_int_eq(s21_sprintf(str, "% f", 555.0), sprintf(str1, "% f", 555.0));

  ck_assert_int_eq(s21_sprintf(str, "%10c", 'a'), sprintf(str1, "%10c", 'a'));
  ck_assert_int_eq(s21_sprintf(str, "%10i", 5), sprintf(str1, "%10i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%10f", 5.1234),
                   sprintf(str1, "%10f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%50f", 5.1234),
                   sprintf(str1, "%50f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%50f", -5.1234),
                   sprintf(str1, "%50f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%10s", "abcd"),
                   sprintf(str1, "%10s", "abcd"));
  ck_assert_int_eq(s21_sprintf(str, "%10u", -1), sprintf(str1, "%10u", -1));
  ck_assert_int_eq(s21_sprintf(str, "%1d", 1234), sprintf(str1, "%1d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%1i", 1234), sprintf(str1, "%1i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%1f", -5.1234),
                   sprintf(str1, "%1f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%1c", '_'), sprintf(str1, "%1c", '_'));
  ck_assert_int_eq(s21_sprintf(str, "%1s", "aSS.FASa"),
                   sprintf(str1, "%1s", "aSS.FASa"));
  ck_assert_int_eq(s21_sprintf(str, "%20d", -1234),
                   sprintf(str1, "%20d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "%20i", 0), sprintf(str1, "%20i", 0));
  ck_assert_int_eq(s21_sprintf(str, "%20f", 555.0),
                   sprintf(str1, "%20f", 555.0));
  ck_assert_int_eq(s21_sprintf(str, "%20c", 'd'), sprintf(str1, "%20c", 'd'));
  ck_assert_int_eq(s21_sprintf(str, "%20s", ""), sprintf(str1, "%20s", ""));
  ck_assert_int_eq(s21_sprintf(str, "%.2000s", "avc"),
                   sprintf(str1, "%.2000s", "avc"));
  // tochnost
  ck_assert_int_eq(s21_sprintf(str, "%.10d", 5), sprintf(str1, "%.10d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%.10i", 5), sprintf(str1, "%.10i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%.10f", 5.1234),
                   sprintf(str1, "%.10f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%.10s", "abcd"),
                   sprintf(str1, "%.10s", "abcd"));
  ck_assert_int_eq(s21_sprintf(str, "%.10u", -1), sprintf(str1, "%.10u", -1));
  ck_assert_int_eq(s21_sprintf(str, "%.1d", 1234), sprintf(str1, "%.1d", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%.1i", 1234), sprintf(str1, "%.1i", 1234));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", -5.1234),
                   sprintf(str1, "%.1f", -5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%.1s", "aSS.FASa"),
                   sprintf(str1, "%.1s", "aSS.FASa"));
  ck_assert_int_eq(s21_sprintf(str, "%.1u", 25), sprintf(str1, "%.1u", 25));
  ck_assert_int_eq(s21_sprintf(str, "%.25d", -1234),
                   sprintf(str1, "%.25d", -1234));
  ck_assert_int_eq(s21_sprintf(str, "%.25i", -1234),
                   sprintf(str1, "%.25i", -1234));
  ck_assert_int_eq(s21_sprintf(str, "%.25f", 555.1234),
                   sprintf(str1, "%.25f", 555.1234));
  ck_assert_int_eq(s21_sprintf(str, "%.25s", ""), sprintf(str1, "%.25s", ""));
  ck_assert_int_eq(s21_sprintf(str, "%.25u", 65535),
                   sprintf(str1, "%.25u", 65535));

  ck_assert_int_eq(s21_sprintf(str, "%hd", 5), sprintf(str1, "%hd", 5));
  ck_assert_int_eq(s21_sprintf(str, "%hi", 5), sprintf(str1, "%hi", 5));
  ck_assert_int_eq(s21_sprintf(str, "%hu", 65355), sprintf(str1, "%hu", 65355));

  ck_assert_int_eq(s21_sprintf(str, "%ld", 65535555555555),
                   sprintf(str1, "%ld", 65535555555555));
  ck_assert_int_eq(s21_sprintf(str, "%li", 65535555555555),
                   sprintf(str1, "%li", 65535555555555));
  ck_assert_int_eq(s21_sprintf(str, "%lu", 65535555555555),
                   sprintf(str1, "%lu", 65535555555555));

  ck_assert_int_eq(s21_sprintf(str, "%10.5d", 5), sprintf(str1, "%10.5d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%10.5i", 5), sprintf(str1, "%10.5i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%10.5f", 5.1234),
                   sprintf(str1, "%10.5f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%10.5s", "abcd"),
                   sprintf(str1, "%10.5s", "abcd"));
  ck_assert_int_eq(s21_sprintf(str, "%10.5u", -1), sprintf(str1, "%10.5u", -1));
  ck_assert_int_eq(s21_sprintf(str, "%10.0d", 5), sprintf(str1, "%10.0d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%10.0i", 5), sprintf(str1, "%10.0i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%10.0f", 5.1234),
                   sprintf(str1, "%10.0f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%10.5s", "abcd"),
                   sprintf(str1, "%10.5s", "abcd"));
  ck_assert_int_eq(s21_sprintf(str, "%10.0u", -1), sprintf(str1, "%10.0u", -1));

  ck_assert_int_eq(s21_sprintf(str, "%-10d", 5), sprintf(str1, "%-10d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%-10i", 5), sprintf(str1, "%-10i", 5));
  ck_assert_int_eq(s21_sprintf(str, "%-10f", 5.1234),
                   sprintf(str1, "%-10f", 5.1234));
  ck_assert_int_eq(s21_sprintf(str, "%-10s", "abcd"),
                   sprintf(str1, "%-10s", "abcd"));
  ck_assert_int_eq(s21_sprintf(str, "%-10u", -1), sprintf(str1, "%-10u", -1));

  ck_assert_int_eq(s21_sprintf(str, "%+d", -1), sprintf(str1, "%+d", -1));
  ck_assert_int_eq(s21_sprintf(str, "%+f", -1.98), sprintf(str1, "%+f", -1.98));

  ck_assert_int_eq(s21_sprintf(str, "%+-10d", 5), sprintf(str1, "%+-10d", 5));
  ck_assert_int_eq(s21_sprintf(str, "%+-10f", 5.123),
                   sprintf(str1, "%+-10f", 5.123));
  ck_assert_int_eq(s21_sprintf(str, "%-10c", 'a'), sprintf(str1, "%-10c", 'a'));
  ck_assert_int_eq(s21_sprintf(str, "%-+10d", -5), sprintf(str1, "%-+10d", -5));
  ck_assert_int_eq(s21_sprintf(str, "%-+15ld", -123456789123),
                   sprintf(str1, "%-+15ld", -123456789123));
  ck_assert_int_eq(s21_sprintf(str, "aaaa%daaaaa", 5),
                   sprintf(str1, "aaaa%daaaaa", 5));

  ck_assert_int_eq(s21_sprintf(str, "%x", 11259375),
                   sprintf(str1, "%x", 11259375));
  ck_assert_int_eq(s21_sprintf(str, "%.3x", 11259375),
                   sprintf(str1, "%.3x", 11259375));
  ck_assert_int_eq(s21_sprintf(str, "%.3X", 11259375),
                   sprintf(str1, "%.3X", 11259375));
  ck_assert_int_eq(s21_sprintf(str, "%.3o", 11259375),
                   sprintf(str1, "%.3o", 11259375));

  ck_assert_int_eq(s21_sprintf(str, "%x", 93520), sprintf(str1, "%x", 93520));

  ck_assert_int_eq(s21_sprintf(str, "%X", 11259375),
                   sprintf(str1, "%X", 11259375));
  ck_assert_int_eq(s21_sprintf(str, "%X", 78187), sprintf(str1, "%X", 78187));

  ck_assert_int_eq(s21_sprintf(str, "%o", 2739128),
                   sprintf(str1, "%o", 2739128));

  ck_assert_int_eq(s21_sprintf(str, "%e", 0.0034), sprintf(str1, "%e", 0.0034));
  ck_assert_int_eq(s21_sprintf(str, "%E", 0.0034), sprintf(str1, "%E", 0.0034));

  ck_assert_int_eq(s21_sprintf(str, "%100.2g", 0.0034),
                   sprintf(str1, "%100.2g", 0.0034));
  ck_assert_int_eq(s21_sprintf(str, "%g", 0.0000034),
                   sprintf(str1, "%g", 0.0000034));
  ck_assert_int_eq(s21_sprintf(str, "%G", 0.0000034),
                   sprintf(str1, "%G", 0.0000034));

  int a = 0;
  int *p = &a;
  ck_assert_int_eq(s21_sprintf(str, "%p", &a), sprintf(str1, "%p", &a));
  ck_assert_ptr_eq(p, p);
  ck_assert_int_eq(s21_sprintf(str, "%n", &a), sprintf(str1, "%n", &a));
  ck_assert_int_eq(a, a);

  // ck_assert_int_eq(s21_sprintf(str, "%-100.1e", 7810000.0), sprintf(str1,
  // "%-100.1e", 7810000.0));

  ck_assert_int_eq(s21_sprintf(str, "% .0d", 0), sprintf(str1, "% .0d", 0));
  ck_assert_int_eq(s21_sprintf(str, "%+.0d", 0), sprintf(str1, "%+.0d", 0));

  ck_assert_int_eq(s21_sprintf(str, "%.*d", 3, 0), sprintf(str1, "%.*d", 3, 0));
  ck_assert_int_eq(s21_sprintf(str, "%*d", 10, 0), sprintf(str1, "%*d", 10, 0));

  END_TEST
}

START_TEST(getPassTest7) {
  char str1[255];
  char str[255];

  ck_assert_int_eq(s21_sprintf(str, "%d", 5), sprintf(str1, "%d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%i", 5), sprintf(str1, "%i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.25), sprintf(str1, "%.1f", 0.25));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.35), sprintf(str1, "%.1f", 0.35));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.45), sprintf(str1, "%.1f", 0.45));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.55), sprintf(str1, "%.1f", 0.55));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.65), sprintf(str1, "%.1f", 0.65));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.75), sprintf(str1, "%.1f", 0.75));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.85), sprintf(str1, "%.1f", 0.5));
  ck_assert_int_eq(s21_sprintf(str, "%.1f", 0.95), sprintf(str1, "%.1f", 0.95));
  ck_assert_int_eq(s21_sprintf(str, "%s", "abcd"), sprintf(str1, "%s", "abcd"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%u", -1), sprintf(str1, "%u", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%%"), sprintf(str1, "%%"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%c", '_'), sprintf(str1, "%c", '_'));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%d", 1234), sprintf(str1, "%d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%i", 1234), sprintf(str1, "%i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%f", 1565.1337),
                   sprintf(str1, "%f", 1565.1337));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%s", "aSS.FASa"),
                   sprintf(str1, "%s", "aSS.FASa"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%u", 65535), sprintf(str1, "%u", 65535));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%c", 'd'), sprintf(str1, "%c", 'd'));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%d", -1234), sprintf(str1, "%d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%i", 0), sprintf(str1, "%i", 0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%f", -5.1234),
                   sprintf(str1, "%f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%s", ""), sprintf(str1, "%s", ""));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%u", 25), sprintf(str1, "%u", 25));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-d", 5), sprintf(str1, "%-d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-i", 5), sprintf(str1, "%-i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-f", 5.1234),
                   sprintf(str1, "%-f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-s", "abcd"),
                   sprintf(str1, "%-s", "abcd"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-u", -1), sprintf(str1, "%-u", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-d", 1234), sprintf(str1, "%-d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-i", 1234), sprintf(str1, "%-i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-f", 1565.1337),
                   sprintf(str1, "%-f", 1565.1337));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-s", "aSS.FASa"),
                   sprintf(str1, "%-s", "aSS.FASa"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-u", 65535), sprintf(str1, "%-u", 65535));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-d", -1234), sprintf(str1, "%-d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-i", 0), sprintf(str1, "%-i", 0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-f", -5.1234),
                   sprintf(str1, "%-f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-s", ""), sprintf(str1, "%-s", ""));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-u", 25), sprintf(str1, "%-u", 25));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% -d", -1234),
                   sprintf(str1, "% -d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% -i", 0), sprintf(str1, "% -i", 0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% -f", -5.1234),
                   sprintf(str1, "% -f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% -d", 1234), sprintf(str1, "% -d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% -i", 1234), sprintf(str1, "% -i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% -f", 1565.1337),
                   sprintf(str1, "% -f", 1565.1337));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+d", 5), sprintf(str1, "%-+d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+i", 5), sprintf(str1, "%-+i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+f", 5.1234),
                   sprintf(str1, "%-+f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+d", 1234), sprintf(str1, "%-+d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+i", 1234), sprintf(str1, "%-+i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+f", -5.1234),
                   sprintf(str1, "%-+f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+d", -1234),
                   sprintf(str1, "%-+d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+i", 0), sprintf(str1, "%-+i", 0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+f", 555.0),
                   sprintf(str1, "%-+f", 555.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+d", 5), sprintf(str1, "%+d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+i", 5), sprintf(str1, "%+i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+f", 5.1234),
                   sprintf(str1, "%+f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+d", 1234), sprintf(str1, "%+d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+i", 1234), sprintf(str1, "%+i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+f", -5.1234),
                   sprintf(str1, "%+f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+d", -1234), sprintf(str1, "%+d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+i", 0), sprintf(str1, "%+i", 0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+f", 555.0), sprintf(str1, "%+f", 555.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% d", 5), sprintf(str1, "% d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% i", 5), sprintf(str1, "% i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% f", 5.1234),
                   sprintf(str1, "% f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% d", 1234), sprintf(str1, "% d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% i", 1234), sprintf(str1, "% i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% f", -5.1234),
                   sprintf(str1, "% f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% d", -1234), sprintf(str1, "% d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% i", 0), sprintf(str1, "% i", 0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% f", 555.0), sprintf(str1, "% f", 555.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10c", 'a'), sprintf(str1, "%10c", 'a'));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10i", 5), sprintf(str1, "%10i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10f", 5.1234),
                   sprintf(str1, "%10f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%50f", 5.1234),
                   sprintf(str1, "%50f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%50f", -5.1234),
                   sprintf(str1, "%50f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10s", "abcd"),
                   sprintf(str1, "%10s", "abcd"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10u", -1), sprintf(str1, "%10u", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%1d", 1234), sprintf(str1, "%1d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%1i", 1234), sprintf(str1, "%1i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%1f", -5.1234),
                   sprintf(str1, "%1f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%1c", '_'), sprintf(str1, "%1c", '_'));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%1s", "aSS.FASa"),
                   sprintf(str1, "%1s", "aSS.FASa"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%20d", -1234),
                   sprintf(str1, "%20d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%20i", 0), sprintf(str1, "%20i", 0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%20f", 555.0),
                   sprintf(str1, "%20f", 555.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%20c", 'd'), sprintf(str1, "%20c", 'd'));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%20s", ""), sprintf(str1, "%20s", ""));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.2000s", "avc"),
                   sprintf(str1, "%.2000s", "avc"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.10d", 5), sprintf(str1, "%.10d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.10i", 5), sprintf(str1, "%.10i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.10f", 5.1234),
                   sprintf(str1, "%.10f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.10s", "abcd"),
                   sprintf(str1, "%.10s", "abcd"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.10u", -1), sprintf(str1, "%.10u", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.1d", 1234), sprintf(str1, "%.1d", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.1i", 1234), sprintf(str1, "%.1i", 1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.1f", -5.1234),
                   sprintf(str1, "%.1f", -5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.1s", "aSS.FASa"),
                   sprintf(str1, "%.1s", "aSS.FASa"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.1u", 25), sprintf(str1, "%.1u", 25));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.25d", -1234),
                   sprintf(str1, "%.25d", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.25i", -1234),
                   sprintf(str1, "%.25i", -1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.25f", 555.1234),
                   sprintf(str1, "%.25f", 555.1234));
  ck_assert_int_eq(s21_sprintf(str, "%.25s", ""), sprintf(str1, "%.25s", ""));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.25u", 65535),
                   sprintf(str1, "%.25u", 65535));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%hd", 5), sprintf(str1, "%hd", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%hi", 5), sprintf(str1, "%hi", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%hu", 65355), sprintf(str1, "%hu", 65355));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%ld", 65535555555555),
                   sprintf(str1, "%ld", 65535555555555));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%li", 65535555555555),
                   sprintf(str1, "%li", 65535555555555));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%lu", 65535555555555),
                   sprintf(str1, "%lu", 65535555555555));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.5d", 5), sprintf(str1, "%10.5d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.5i", 5), sprintf(str1, "%10.5i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.5f", 5.1234),
                   sprintf(str1, "%10.5f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.5s", "abcd"),
                   sprintf(str1, "%10.5s", "abcd"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.5u", -1), sprintf(str1, "%10.5u", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.0d", 5), sprintf(str1, "%10.0d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.0i", 5), sprintf(str1, "%10.0i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.0f", 5.1234),
                   sprintf(str1, "%10.0f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.5s", "abcd"),
                   sprintf(str1, "%10.5s", "abcd"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.0u", -1), sprintf(str1, "%10.0u", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-10d", 5), sprintf(str1, "%-10d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-10i", 5), sprintf(str1, "%-10i", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-10f", 5.1234),
                   sprintf(str1, "%-10f", 5.1234));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-10s", "abcd"),
                   sprintf(str1, "%-10s", "abcd"));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-10u", -1), sprintf(str1, "%-10u", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+d", -1), sprintf(str1, "%+d", -1));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+f", -1.98), sprintf(str1, "%+f", -1.98));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+-10d", 5), sprintf(str1, "%+-10d", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+-10f", 5.123),
                   sprintf(str1, "%+-10f", 5.123));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-10c", 'a'), sprintf(str1, "%-10c", 'a'));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+10d", -5), sprintf(str1, "%-+10d", -5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-+15ld", -123456789123),
                   sprintf(str1, "%-+15ld", -123456789123));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "aaaa%daaaaa", 5),
                   sprintf(str1, "aaaa%daaaaa", 5));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%.2g", 124124.0),
                   sprintf(str1, "%.2g", 124124.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-.2g", 124124.0),
                   sprintf(str1, "%-.2g", 124124.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+.2g", 124124.0),
                   sprintf(str1, "%+.2g", 124124.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.2g", -124124.0),
                   sprintf(str1, "%10.2g", -124124.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+-.2g", -124124.0),
                   sprintf(str1, "%+-.2g", -124124.0));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%hhd", 256), sprintf(str1, "%hhd", 256));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%-hhd", 256), sprintf(str1, "%-hhd", 256));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%+hhd", 256), sprintf(str1, "%+hhd", 256));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "%10.5hhd", 256),
                   sprintf(str1, "%10.5hhd", 256));
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_sprintf(str, "% hhd", 256), sprintf(str1, "% hhd", 256));
  ck_assert_str_eq(str, str1);
  END_TEST
}

START_TEST(getPassTest8) {
  char *str = s21_NULL;
  char *str1 = s21_to_upper("1234abc56");
  ck_assert_str_eq(str1, "1234ABC56");
  free(str1);
  char *str2 = s21_to_upper("abcde_f");
  ck_assert_str_eq(str2, "ABCDE_F");
  free(str2);
  char *str3 = s21_to_upper(" ");
  ck_assert_str_eq(str3, " ");
  free(str3);
  char *str4 = s21_to_upper(str);
  ck_assert_pstr_eq(str4, s21_NULL);
  free(str4);
  END_TEST
}

START_TEST(getPassTest9) {
  char *str = s21_NULL;
  char *str1 = s21_to_lower("1234ABC56");
  ck_assert_str_eq(str1, "1234abc56");
  free(str1);
  char *str2 = s21_to_lower("ABCDE_F");
  ck_assert_str_eq(str2, "abcde_f");
  free(str2);
  char *str3 = s21_to_lower(" ");
  ck_assert_str_eq(str3, " ");
  free(str3);
  char *str4 = s21_to_lower(str);
  ck_assert_pstr_eq(str4, s21_NULL);
  free(str4);
  END_TEST
}

START_TEST(insert) {
  char src[255] = "123456";
  char src1[255] = "abcdef";
  char str[10] = "abc";
  char *strr = s21_insert(src1, str, 1);
  ck_assert_str_eq(strr, "aabcbcdef");
  free(strr);
  char *str1 = s21_insert(src, str, 5);
  ck_assert_str_eq(str1, "12345abc6");
  free(str1);
  char *str2 = s21_insert(s21_NULL, str, 5);
  ck_assert_pstr_eq(str2, s21_NULL);
  free(str2);
  char *str3 = s21_insert(src, s21_NULL, 5);
  ck_assert_pstr_eq(str3, s21_NULL);
  free(str3);
  char *str4 = s21_insert(src, str, 50);
  ck_assert_pstr_eq(str4, s21_NULL);
  free(str4);
  END_TEST
}

START_TEST(trim) {
  char *trim_chars = "-*_";
  char *str = "-*_---_qwerty--***";
  char *str1 = s21_trim(str, trim_chars);
  ck_assert_str_eq(str1, "qwerty");
  free(str1);
  char *str2 = s21_trim("-*_---_qwe--**rty--***", trim_chars);
  ck_assert_str_eq(str2, "qwe--**rty");
  free(str2);
  char *str3 = s21_trim("-*_---_qwerty--***", s21_NULL);
  ck_assert_str_eq(str3, "-*_---_qwerty--***");
  free(str3);
  char *str4 = s21_trim(s21_NULL, trim_chars);
  ck_assert_pstr_eq(str4, s21_NULL);
  free(str4);
  char *str5 = s21_trim("", trim_chars);
  ck_assert_str_eq(str5, "");
  free(str5);
  END_TEST
}
int main() {
  Suite *s1 = suite_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  TCase *getCase = tcase_create("sumBaseTest");
  suite_add_tcase(s1, getCase);
  tcase_add_test(getCase, getPassTest);
  tcase_add_test(getCase, getPassTest2);
  tcase_add_test(getCase, getPassTest3);
  tcase_add_test(getCase, getPassTest4);
  tcase_add_test(getCase, getPassTest5);
  tcase_add_test(getCase, getPassTest6);
  tcase_add_test(getCase, getPassTest7);
  tcase_add_test(getCase, getPassTest8);
  tcase_add_test(getCase, getPassTest9);
  tcase_add_test(getCase, insert);
  tcase_add_test(getCase, trim);

  srunner_run_all(sr, CK_ENV);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf;
}
