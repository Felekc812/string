#include "s21_string.h"

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  if (str != s21_NULL) {
    for (i = 0; str[i] != '\0'; i++) {
    }
  }
  return i;
}

char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  int i, j;
  for (i = 0; dest[i] != '\0'; i++) {
  }
  for (j = 0; src[j] != '\0'; j++) {
    dest[i + j] = src[j];
  }
  dest[i + j] = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest + s21_strlen(dest);
  while (*src != '\0' && n--) {
    *ptr++ = *src++;
  }
  *ptr = '\0';
  return dest;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  s21_size_t len = s21_strlen((char *)(needle));
  if (len) {
    for (; *haystack && !result; haystack++) {
      if (!s21_strncmp(haystack, needle, len)) {
        result = (char *)haystack;
      }
    }
  } else {
    result = (char *)haystack;
  }
  return result;
}

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  while (*str++ && !res) {
    if ((char)c == *str) {
      res = (char *)str;
    }
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  for (int i = s21_strlen((char *)str); i >= 0; i--) {
    if (str[i] == c) {
      res = (char *)(str + i);
      break;
    }
  }
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  char u1, u2;
  int result = 0;
  while (n-- > 0) {
    u1 = (char)*str1++;
    u2 = (char)*str2++;
    if (u1 != u2) {
      result = u1 - u2;
      break;
    }
    if ((u1 == '\0') || (u2 == '\0') || (!n)) {
      result = 0;
      break;
    }
  }
  return result;
}

int s21_strcmp(const char *str1, const char *str2) {
  int result = s21_strncmp(str1, str2, s21_strlen((char *)str1) + 1);
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  for (const char *temp = str2; *str1 != '\0' && *temp != '\0'; str1++) {
    temp = str2;
    for (; *temp != '\0'; temp++) {
      if (*temp == *str1) {
        count++;
        break;
      }
    }
  }
  return count;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *s1, *s2;
  for (s1 = str1; *s1 != '\0'; ++s1) {
    for (s2 = str2; *s2 != '\0'; ++s2) {
      if (*s1 == *s2) {
        return (s1 - str1);
      }
    }
  }
  return (s1 - str1);
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *pointer = s21_NULL;
  for (; *str1 != '\0' && pointer == s21_NULL; str1++) {
    for (const char *temp = str2; *temp != '\0'; temp++) {
      if (*temp == *str1) {
        pointer = str1;
        break;
      }
    }
  }
  return (char *)pointer;
}

char *s21_strtok(char *str, const char *delim) {
  static char *token;
  char *result;
  if (str == s21_NULL) {
    result = token;
  } else {
    result = str;
  }
  result = result + s21_strspn(result, delim);
  if ((token = s21_strpbrk(result, delim)) != s21_NULL) {
    *token = '\0';
    token++;
  } else {
    token = result + s21_strlen(result);
  }
  if (*result == '\0') {
    result = s21_NULL;
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest_s = (char *)dest;
  const char *src_s = (char *)src;
  s21_size_t len = 0;
  for (len = 0; len < n; len++) {
    *(dest_s + len) = *(src_s + len);
  }
  return (void *)dest_s;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *dest_char = (char *)dest;
  char *src_char = calloc(n, sizeof(char));
  s21_memcpy(src_char, src, n);
  char *src_cpy = (char *)src_char;
  for (; n > 0; n--) {
    *dest_char = *src_char;
    dest_char++;
    src_char++;
  }
  free(src_cpy);
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    char sym = c;
    *((char *)str + i) = sym;
  }
  return str;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = s21_NULL;
  for (int i = 0; i < (int)n && result == s21_NULL; i++) {
    if (*((unsigned char *)str + i) == (unsigned char)c) {
      result = (unsigned char *)str + i;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  unsigned char *ps1 = (unsigned char *)str1;
  unsigned char *ps2 = (unsigned char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (*ps1 == *ps2) {
      ps1++;
      ps2++;
    } else {
      result = *ps1 - *ps2;
      n = 0;
    }
  }
  return result;
}

char *s21_strerror(int errnum) {
#if __linux__
  static char *Error_[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error",
  };
#else
  static char *Error_[] = {
      "Undefined error: 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "Device not configured",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Resource busy",
      "File exists",
      "Cross-device link",
      "Operation not supported by device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Result too large",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Can't assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Can't send after socket shutdown",
      "Too many references: can't splice",
      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",
      "Stale NFS file handle",
      "Too many levels of remote in path",
      "RPC struct is bad",
      "RPC version wrong",
      "RPC prog. not avail",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",
      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",
      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "Attribute not found",
      "Bad message",
      "EMULTIHOP (Reserved)",
      "No message available on STREAM",
      "ENOLINK (Reserved)",
      "No STREAM resources",
      "Not a STREAM",
      "Protocol error",
      "STREAM ioctl timeout",
      "Operation not supported on socket",
      "Policy not found",
      "State not recoverable",
      "Previous owner died",
      "Interface output queue is full",
  };
#endif
  return Error_[errnum];
}

void *s21_to_upper(const char *str) {
  char *array = s21_NULL;
  if (str != s21_NULL) {
    array = calloc(s21_strlen((char *)str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen((char *)str); i++) {
      array[i] = str[i];
      if (array[i] >= 'a' && array[i] <= 'z') {
        array[i] -= 0x20;
      }
    }
  }
  return array;
}

void *s21_to_lower(const char *str) {
  char *array = s21_NULL;
  if (str != s21_NULL) {
    array = calloc(s21_strlen((char *)str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen((char *)str); i++) {
      array[i] = str[i];
      if (array[i] >= 'A' && str[i] <= 'Z') {
        array[i] += 0x20;
      }
    }
  }
  return array;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src != s21_NULL) {
    char *src1 = calloc(s21_strlen(src) + 1, sizeof(char));
    s21_size_t t8 = s21_strlen(src);
    for (s21_size_t i = 0; i < t8; i++) {
      src1[i] = src[i];
    }
    s21_size_t t1 = s21_strlen(src1);
    char *trim_null_chars = " \n\t\v\f\r";
    s21_size_t x;
    s21_size_t y;
    if (trim_chars == s21_NULL) {
      x = s21_strspn(src1, trim_null_chars);
      s21_reverse(src1, t1);
      y = s21_strspn(src1, trim_null_chars);
    } else {
      x = s21_strspn(src1, trim_chars);
      s21_reverse(src1, t1);
      y = s21_strspn(src1, trim_chars);
    }
    s21_reverse(src1, t1);
    res = calloc(t1 - y - x + 1, sizeof(char));
    int j = 0;
    for (s21_size_t i = x; i < t1 - y; i++) {
      res[j] = src1[i];
      j++;
    }
    res[j] = '\0';
    free(src1);
  }
  return res;
}

void s21_reverse(char tmp[], int len) {
  int i = 0, j = len - 1, prom;
  while (i < j) {
    prom = tmp[i];
    tmp[i] = tmp[j];
    tmp[j] = prom;
    i++;
    j--;
  }
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (str == s21_NULL) return s21_NULL;
  if (src == s21_NULL) return s21_NULL;
  if (start_index > s21_strlen(src)) return s21_NULL;
  char *result = calloc(s21_strlen(str) + s21_strlen(src) + 1, sizeof(char));
  s21_strncpy(result, src, start_index);
  s21_strcat(result, str);
  s21_strcat(result, src + start_index);
  s21_strcat(result, "\0");
  return result;
}

int s21_sprintf(char *buf, const char *format, ...) {
  int nSpace, len, nPrecision = -1, flagPlus = 0, flagMinus = 0, flagSpace = 0,
                   flagH = 0, flagSmallL = 0, flagBigL = 0, flagDrid = 0,
                   flag0 = 0, flagStar = 0, flagStarPrecision = 0;
  long long d;
  unsigned long long u;
  unsigned int o, x;
  unsigned long long *p;
  int *n;
  char str[1000] = "";
  char strS[255];
  char *strStr = s21_NULL;
  long double f;
  double e, g;
  char c;
  va_list parameter;
  va_start(parameter, format);
  int j = 0;
  for (int i = 0; i < (int)s21_strlen(format); i++, j++) {
    flagPlus = 0;
    flagMinus = 0;
    flagSpace = 0, nPrecision = -1, flagH = 0, flagSmallL = 0, flagDrid = 0,
    flag0 = 0, flagStar = 0, flagStarPrecision = 0, flagBigL = 0;
    if (format[i] == '%') {
      i++;
      flags(format, &i, &flagPlus, &flagMinus, &flagSpace, &flagDrid, &flag0);
      if (format[i] == '*') {
        flagStar = 1;
        i++;
      }
      nSpace = digitCounter(format, &i);

      if (format[i] == '.') {
        i++;
        if (format[i] != '*') {
          nPrecision = digitCounter(format, &i);
        } else {
          flagStarPrecision = 1;
          i++;
        }
      }
      if (format[i] == 'h') {
        flagH = 1;
        i++;
        if (format[i] == 'h') {
          flagH = 2;
          i++;
        }
      }
      if (format[i] == 'l') {
        flagSmallL = 1;
        i++;
        if (format[i] == 'l') {
          flagSmallL = 2;
          i++;
        }
      }
      if (format[i] == 'L') {
        flagBigL = 1;
        i++;
      }

      switch (format[i]) {
        case 'i':
        case 'd':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          if (flagStarPrecision == 1) nPrecision = va_arg(parameter, int);
          if (flagH == 1) {
            d = (short int)va_arg(parameter, int);
          } else if (flagSmallL == 1) {
            d = va_arg(parameter, long int);
          } else if (flagSmallL == 2) {
            d = va_arg(parameter, long long);
          } else if (flagH == 2) {
            d = va_arg(parameter, long long);
            while (d <= -128 || d >= 128) {
              if (d < 0)
                d += 128;
              else
                d -= 128;
            }
          } else {
            d = va_arg(parameter, int);
          }
          if (d == 0 && nPrecision == 0) {
            if (flagPlus == 1) {
              writeInBuf(buf, "+", &j, &nSpace, flagMinus, flag0);
            } else if (flagSpace == 1) {
              writeInBuf(buf, " ", &j, &nSpace, flagMinus, flag0);
            } else {
              writeInBuf(buf, "", &j, &nSpace, flagMinus, flag0);
            }
            continue;
          } else {
            trasletionFromIntegerInStr(d, str, flagPlus, flagSpace,
                                       countNumbersInterger(d), nPrecision);
            writeInBuf(buf, str, &j, &nSpace, flagMinus, flag0);
          }
          break;
        case 'f':
          if (flagStar == 1) {
            nSpace = va_arg(parameter, int);
          }
          if (flagStarPrecision == 1) {
            nPrecision = va_arg(parameter, int);
          }
          if (flagBigL == 1)
            f = va_arg(parameter, double);
          else
            f = va_arg(parameter, double);
          trasletionFromFloatInStr(f, str, flagPlus, flagSpace, nPrecision,
                                   flagDrid);
          writeInBuf(buf, str, &j, &nSpace, flagMinus, flag0);
          break;
        case 'c':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          c = va_arg(parameter, int);
          char space;
          if (flag0 == 0)
            space = ' ';
          else
            space = '0';
          if (flagMinus == 0) {
            for (int g = 0; g < nSpace - 1; j++, g++) buf[j] = space;
            buf[j] = c;
          } else {
            buf[j] = c;
            j++;
            for (int g = 0; g < nSpace - 1; j++, g++) buf[j] = space;
            buf[j] = ' ';
            j--;
          }
          break;
        case 's':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          if (flagStarPrecision == 1) nPrecision = va_arg(parameter, int);
          char *strStr2;
          strStr2 = va_arg(parameter, char *);
          if ((int)s21_strlen(strStr2) > nPrecision && nPrecision != -1) {
            char str2[1000];
            for (int i = 0; i < nPrecision; i++) str2[i] = strStr2[i];
            str2[nPrecision] = '\0';
            writeInBuf(buf, str2, &j, &nSpace, flagMinus, flag0);
          } else {
            writeInBuf(buf, strStr2, &j, &nSpace, flagMinus, flag0);
          }
          break;
        case 'u':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          if (flagStarPrecision == 1) nPrecision = va_arg(parameter, int);
          if (flagH == 1)
            u = (unsigned short int)va_arg(parameter, int);
          else if (flagSmallL == 1)
            u = va_arg(parameter, unsigned long int);
          else if (flagSmallL == 2)
            u = va_arg(parameter, unsigned long long);
          else
            u = va_arg(parameter, unsigned int);
          if (u == 0 && nPrecision == 0) {
            writeInBuf(buf, "", &j, &nSpace, flagMinus, flag0);
          } else {
            trasletionFromUnsignedIntegerInStr(u, str, nPrecision);
            writeInBuf(buf, str, &j, &nSpace, flagMinus, flag0);
          }
          break;
        case 'e':
          if (flagStar == 1) {
            nSpace = va_arg(parameter, int);
          }
          if (flagStarPrecision == 1) {
            nPrecision = va_arg(parameter, int);
          }
          e = va_arg(parameter, double);
          transletionEInStr(e, str, flagPlus, flagSpace, nPrecision, flagDrid);
          writeInBuf(buf, str, &j, &nSpace, flagMinus, flag0);
          break;
        case 'E':
          if (flagStar == 1) {
            nSpace = va_arg(parameter, int);
          }
          if (flagStarPrecision == 1) {
            nPrecision = va_arg(parameter, int);
          }
          e = va_arg(parameter, double);
          transletionEInStr(e, str, flagPlus, flagSpace, nPrecision, flagDrid);
          strStr = s21_to_upper(str);
          writeInBuf(buf, strStr, &j, &nSpace, flagMinus, flag0);
          break;
        case 'o':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          if (flagStarPrecision == 1) nPrecision = va_arg(parameter, int);
          if (flagH == 1)
            o = (unsigned short int)va_arg(parameter, unsigned int);
          else if (flagSmallL == 1)
            o = va_arg(parameter, unsigned long int);
          else if (flagSmallL == 2)
            o = va_arg(parameter, unsigned long long);
          else
            o = va_arg(parameter, unsigned int);

          if (o == 0 && nPrecision == 0) {
            writeInBuf(buf, "", &j, &nSpace, flagMinus, flag0);
            continue;
          } else {
            len = dectox_int(o, 8, strS);
          }
          if (len < nPrecision) {
            char strWithPrecision[1000];
            for (int i = 0; i < len + (nPrecision - len); i++)
              strWithPrecision[i] = '0';
            int rt = 0;
            for (int i = nPrecision - len; i < len + (nPrecision - len);
                 i++, rt++)
              strWithPrecision[i] = strS[rt];
            strS[len] = '\0';
            s21_strcpy(strS, strWithPrecision);
          } else {
            strS[len] = '\0';
          }
          if (flagDrid == 0) {
            writeInBuf(buf, strS, &j, &nSpace, flagMinus, flag0);
          } else {
            char str2[1000];
            s21_strcpy(str2, "0");
            s21_strcat(str2, strS);
            writeInBuf(buf, strS, &j, &nSpace, flagMinus, flag0);
          }
          break;
        case 'x':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          if (flagStarPrecision == 1) nPrecision = va_arg(parameter, int);

          if (flagH == 1)
            x = (unsigned short int)va_arg(parameter, unsigned int);
          else if (flagSmallL == 1)
            x = va_arg(parameter, unsigned long int);
          else if (flagSmallL == 2)
            x = va_arg(parameter, unsigned long long);
          else
            x = va_arg(parameter, unsigned int);
          if (x == 0 && nPrecision == 0) {
            writeInBuf(buf, "", &j, &nSpace, flagMinus, flag0);
            continue;
          } else {
            len = dectox_int(x, 16, strS);
          }
          if (len < nPrecision) {
            char strWithPrecision[255];
            for (int i = 0; i < len + (nPrecision - len); i++)
              strWithPrecision[i] = '0';
            int rt = 0;
            for (int i = nPrecision - len; i < len + (nPrecision - len);
                 i++, rt++)
              strWithPrecision[i] = strS[rt];
            strS[len] = '\0';
            s21_strcpy(strS, strWithPrecision);
          } else {
            strS[len] = '\0';
          }
          if (flagDrid == 0) {
            strStr = s21_to_lower(strS);
            writeInBuf(buf, strStr, &j, &nSpace, flagMinus, flag0);
          } else {
            char str2[255];
            s21_strcpy(str2, "0X");
            s21_strcat(str2, strS);
            strStr = s21_to_lower(strS);
            writeInBuf(buf, strStr, &j, &nSpace, flagMinus, flag0);
          }
          break;
        case 'X':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          if (flagStarPrecision == 1) nPrecision = va_arg(parameter, int);
          if (flagH == 1)
            x = (unsigned short int)va_arg(parameter, unsigned int);
          else if (flagSmallL == 1)
            x = va_arg(parameter, unsigned long int);
          else if (flagSmallL == 2)
            x = va_arg(parameter, unsigned long long);
          else
            x = va_arg(parameter, unsigned int);
          if (x == 0 && nPrecision == 0) {
            writeInBuf(buf, "", &j, &nSpace, flagMinus, flag0);
            continue;
          } else {
            len = dectox_int(x, 16, strS);
          }
          if (len < nPrecision) {
            char strWithPrecision[255];
            for (int i = 0; i < len + (nPrecision - len); i++)
              strWithPrecision[i] = '0';
            int rt = 0;
            for (int i = nPrecision - len; i < len + (nPrecision - len);
                 i++, rt++)
              strWithPrecision[i] = strS[rt];
            strS[len] = '\0';
            s21_strcpy(strS, strWithPrecision);
          } else {
            strS[len] = '\0';
          }
          if (flagDrid == 0) {
            writeInBuf(buf, strS, &j, &nSpace, flagMinus, flag0);
          } else {
            char str2[255];
            s21_strcpy(str2, "0X");
            s21_strcat(str2, strS);
            writeInBuf(buf, strS, &j, &nSpace, flagMinus, flag0);
          }
          break;
        case 'p':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          p = va_arg(parameter, unsigned long long *);
          long long d = (long long)p;
          len = dectox_int(d, 16, strS);
          strS[len] = '\0';
          char strForP[255] = "";
          strForP[0] = '0';
          strForP[1] = 'x';
          strStr = s21_to_lower(strS);
          s21_strcat(strForP, strStr);
          writeInBuf(buf, strForP, &j, &nSpace, flagMinus, flag0);
          break;
        case 'n':
          if (flagStar == 1) nSpace = va_arg(parameter, int);
          n = va_arg(parameter, int *);
          *n = j;
          buf[j] = ' ';
          j--;
          break;
        case 'g':
          if (flagStar == 1) {
            nSpace = va_arg(parameter, int);
          }
          if (flagStarPrecision == 1) {
            nPrecision = va_arg(parameter, int);
          }
          g = va_arg(parameter, double);
          transletionGInStr(g, str, flagPlus, flagSpace, nPrecision, flagDrid);
          writeInBuf(buf, str, &j, &nSpace, flagMinus, flag0);
          break;
        case 'G':
          if (flagStar == 1) {
            nSpace = va_arg(parameter, int);
          }
          if (flagStarPrecision == 1) {
            nPrecision = va_arg(parameter, int);
          }
          g = va_arg(parameter, double);
          transletionGInStr(g, str, flagPlus, flagSpace, nPrecision, flagDrid);
          strStr = s21_to_upper(str);
          writeInBuf(buf, strStr, &j, &nSpace, flagMinus, flag0);
          break;
        default:
          if (format[i] != ' ')
            buf[j] = format[i];
          else
            j--;
      }
    } else {
      buf[j] = format[i];
    }
  }
  buf[j] = '\0';
  va_end(parameter);
  free(strStr);
  return (int)s21_strlen(buf);
}
void flags(const char *format, int *i, int *flagPlus, int *flagMinus,
           int *flagSpace, int *flagDrid, int *flag0) {
  while (format[*i] == '+' || format[*i] == '-' || format[*i] == ' ' ||
         format[*i] == '#' || format[*i] == '0') {
    if (format[*i] == '+') {
      *flagPlus = 1;
      (*i)++;
    }
    if (format[*i] == '-') {
      *flagMinus = 1;
      (*i)++;
    }

    if (format[*i] == ' ') {
      *flagSpace = 1;
      (*i)++;
    }

    if (format[*i] == '#') {
      *flagDrid = 1;
      (*i)++;
    }

    if (format[*i] == '0') {
      *flag0 = 1;
      (*i)++;
    }
  }
}

void transletionGInStr(double g, char *str, int flagPlus, int flagSpace,
                       int nPrecision, int flagDrid) {
  if (nPrecision == -1) nPrecision = 6;
  int partBeforeDot = 0;
  long double copyG;
  int signMinus = 0;
  if (g < 0) {
    signMinus = 1;
    copyG = -g;
    g *= -1;
  } else {
    copyG = g;
  }
  if (g >= 1) {
    if (signMinus == 1) g *= -1;

    partBeforeDot = (int)g;
    int lenPartBeforeDot = countNumbersInterger(partBeforeDot);
    if (lenPartBeforeDot > nPrecision) {
      if (nPrecision != 0) {
        for (int i = 0; i < lenPartBeforeDot - nPrecision; i++) copyG /= 10;
        int n = 1;
        while (1) {
          if ((int)copyG % 10 == 0) {
            n++;
            copyG /= 10;
          } else {
            break;
          }
        }
        if (flagDrid == 0)
          transletionEInStr(g, str, flagPlus, flagSpace, nPrecision - n,
                            flagDrid);
        else
          transletionEInStr(g, str, flagPlus, flagSpace, nPrecision - 1,
                            flagDrid);
      } else {
        transletionEInStr(g, str, flagPlus, flagSpace, 0, flagDrid);
      }
    } else {
      trasletionFromFloatInStr(g, str, flagPlus, flagSpace,
                               nPrecision - lenPartBeforeDot, flagDrid);
      if (flagDrid == 0) {
        int dot = 0, n = -1, boo = 0;
        for (int i = 0; i < (int)s21_strlen(str); i++) {
          if (str[i] == '.') dot = 1;
          if (str[i] == '0' && dot == 1) {
            if (boo == 0) {
              n = i;
              boo = 1;
            } else if (n > i && boo == 1) {
              n = i;
            }
          } else {
            n = -1;
            boo = 0;
          }
        }
        if (n != -1 && str[n - 1] != '.')
          str[n] = '\0';
        else if (n != -1 && str[n - 1] == '.')
          str[n - 1] = '\0';
      }
    }
  } else {
    if (signMinus == 1) g *= -1;
    int n = 0, z = 0;
    while (1) {
      partBeforeDot = (int)copyG;
      if (partBeforeDot == 0) {
        copyG *= 10;
        n++;
      } else {
        break;
      }
      z++;
      if (z == 100) {
        n = 0;
        break;
      }
    }
    if (n > 4) {
      double partAfterDot = copyG - (int)copyG;
      int z = 1;
      for (int i = 0; i < nPrecision - 1; i++) partAfterDot *= 10;
      if ((int)partAfterDot != 0) {
        while (1) {
          if ((int)partAfterDot % 10 == 0) {
            z++;
            partAfterDot /= 10;
          } else {
            break;
          }
        }

        if (flagDrid == 0)
          transletionEInStr(g, str, flagPlus, flagSpace, nPrecision - z,
                            flagDrid);
        else
          transletionEInStr(g, str, flagPlus, flagSpace, nPrecision - 1,
                            flagDrid);
      } else {
        if (flagDrid == 0)
          transletionEInStr(g, str, flagPlus, flagSpace, 0, flagDrid);
        else
          transletionEInStr(g, str, flagPlus, flagSpace, nPrecision - 1,
                            flagDrid);
      }
    } else {
      trasletionFromFloatInStr(g, str, flagPlus, flagSpace, nPrecision + n - 1,
                               flagDrid);
      if (flagDrid == 0) {
        int dot = 0, n = -1, boo = 0;
        for (int i = 0; i < (int)s21_strlen(str); i++) {
          if (str[i] == '.') dot = 1;
          if (str[i] == '0' && dot == 1) {
            if (boo == 0) {
              n = i;
              boo = 1;
            } else if (n > i && boo == 1) {
              n = i;
            }
          } else {
            n = -1;
            boo = 0;
          }
        }
        if (n != -1 && str[n - 1] != '.')
          str[n] = '\0';
        else if (n != -1 && str[n - 1] == '.')
          str[n - 1] = '\0';
      }
    }
  }
}

void transletionEInStr(double e, char *str, int flagPlus, int flagSpace,
                       int nPrecision, int flagDrid) {
  if (nPrecision == -1) nPrecision = 6;
  int signMinus = 0;
  if (e < 0) {
    e *= -1;
    signMinus = 1;
  }
  int n = 0;
  char eStr[1000] = "";
  char strD[1000] = "";
  if (e >= 1) {
    while (1) {
      if (e / 10 >= 1) {
        e /= 10;
        n++;
      } else {
        trasletionFromIntegerInStr(n, strD, 0, 0, countNumbersInterger(n), 0);
        if (n >= 10) {
          s21_strcpy(eStr, "e+");
        } else {
          s21_strcpy(eStr, "e+0");
        }
        if (n != 0)
          s21_strcat(eStr, strD);
        else
          s21_strcat(eStr, "0");
        break;
      }
    }
  } else {
    int z = 0;
    while (1) {
      if (e * 10 < 10) {
        e *= 10;
        n++;
      } else {
        trasletionFromIntegerInStr(n, strD, 0, 0, countNumbersInterger(n), 0);
        if (n > 10) {
          s21_strcpy(eStr, "e-");
        } else {
          s21_strcpy(eStr, "e-0");
        }
        if (n != 0) {
          s21_strcat(eStr, strD);
        } else {
          s21_strcat(eStr, "0");
          break;
        }
        z++;
        if (z == 100) {
          s21_strcpy(eStr, "e+00");
          break;
        }
      }
    }
  }
  if (signMinus == 0) {
    trasletionFromFloatInStr(e, str, flagPlus, flagSpace, nPrecision, flagDrid);
    s21_strcat(str, eStr);
  } else {
    trasletionFromFloatInStr(-e, str, flagPlus, flagSpace, nPrecision,
                             flagDrid);
    s21_strcat(str, eStr);
  }
}

int digitCounter(const char *format, int *i) {
  int nSpace = 0;
  while (format[*i] >= '0' && format[*i] <= '9') {
    nSpace += format[*i] - '0';
    if (format[(*i) + 1] >= '0' && format[(*i) + 1] <= '9') nSpace *= 10;
    (*i)++;
  }
  return nSpace;
}

void writeInBuf(char *buf, char *str, int *j, int *nSpace, int flagMinus,
                int flag0) {
  char s;
  if (flag0 == 0)
    s = ' ';
  else
    s = '0';
  if (flagMinus == 0) {
    for (int g = 0; g < *nSpace - (int)s21_strlen(str); (*j)++, g++)
      buf[*j] = s;
    for (int g = 0; g < (int)s21_strlen(str); (*j)++, g++) buf[*j] = str[g];
    buf[*j] = ' ';
    (*j)--;
    *nSpace = 0;
  } else {
    for (int g = 0; g < (int)s21_strlen(str); (*j)++, g++) buf[*j] = str[g];
    for (int g = 0; g < *nSpace - (int)s21_strlen(str); (*j)++, g++)
      buf[*j] = s;
    buf[*j] = ' ';
    (*j)--;
    *nSpace = 0;
  }
}
int countNumbersInterger(long long d) {
  int i = 0;
  if (d < 0) d *= -1;

  if (d == 0) i++;
  for (; d > 0; i++) d /= 10;
  return i;
}
void trasletionFromIntegerInStr(long long int d, char *str, int flagPlus,
                                int flagSpace, int lenInteger, int nPrecision) {
  int n, boo = 0;
  if (d < 0) {
    d *= -1;
    boo = 1;
  }

  int nZero = 0;
  if (nPrecision - lenInteger > 0) nZero = nPrecision - lenInteger;

  if (boo == 0 && flagPlus == 0 && flagSpace == 0) {
    lenInteger += nZero;
    str[lenInteger] = '\0';
    for (int i = 0; i < nZero; i++) {
      str[i] = '0';
    }
    if (d == 0) str[lenInteger - 1] = '0';

    for (int i = 1; d > 0; i++) {
      n = d % 10;
      d /= 10;
      str[lenInteger - i] = n + '0';
    }
  } else if (boo == 0 && flagPlus == 1 && flagSpace == 0) {
    lenInteger += nZero;
    str[0] = '+';
    for (int i = 1; i < nZero + 1; i++) {
      str[i] = '0';
    }
    str[lenInteger + 1] = '\0';
    if (d == 0) str[lenInteger] = '0';
    for (int i = 1; d > 0; i++) {
      n = d % 10;
      d /= 10;
      str[lenInteger - (i) + 1] = n + '0';
    }
  } else if (boo == 0 && flagPlus == 1 && flagSpace == 1) {
    lenInteger += nZero;
    str[0] = '+';
    for (int i = 1; i < nZero + 1; i++) {
      str[i] = '0';
    }
    str[lenInteger + 1] = '\0';
    if (d == 0) str[lenInteger] = '0';
    for (int i = 1; d > 0; i++) {
      n = d % 10;
      d /= 10;
      str[lenInteger - (i) + 1] = n + '0';
    }
  } else if (boo == 0 && flagPlus == 0 && flagSpace == 1) {
    lenInteger += nZero;
    str[0] = ' ';
    for (int i = 1; i < nZero + 1; i++) {
      str[i] = '0';
    }
    str[lenInteger + 1] = '\0';
    if (d == 0) str[lenInteger] = '0';
    for (int i = 1; d > 0; i++) {
      n = d % 10;
      d /= 10;
      str[lenInteger - (i) + 1] = n + '0';
    }
  } else {
    lenInteger += nZero;
    str[0] = '-';
    if (d == 0) str[lenInteger - 1] = '0';
    for (int i = 1; i < nZero + 1; i++) {
      str[i] = '0';
    }
    str[lenInteger + 1] = '\0';
    for (int i = 1; d > 0; i++) {
      n = d % 10;
      d /= 10;
      str[lenInteger - (i) + 1] = n + '0';
    }
  }
}

void trasletionFromUnsignedIntegerInStr(unsigned long d, char *str,
                                        int nPrecision) {
  int i = 0;
  long unsigned int n;
  n = d;
  int nZero = 0;
  for (; n > 0; i++) n /= 10;
  if (nPrecision - i > 0) nZero = nPrecision - i;
  int len = i + nZero;
  if (d == 0) {
    if (len != 0) {
      for (int i = 0; i < len; i++) str[i] = '0';
    } else {
      str[0] = '0';
    }
    if (len == 0)
      str[len + 1] = '\0';
    else
      str[len] = '\0';
  } else {
    for (int i = 0; i < nZero; i++) {
      str[i] = '0';
    }
    str[len] = '\0';
    for (i = 0; d > 0; i++) {
      n = d % 10;
      d /= 10;
      str[len - (i + 1)] = n + '0';
    }
  }
}

void trasletionFromFloatInStr(double f, char *str, int flagPlus, int flagSpace,
                              int nPrecision, int flagDrid) {
  int z = 1;
  if (nPrecision == -1) nPrecision = 6;

  for (int i = 0; i < nPrecision; i++) z *= 10;
  long long partBeforeDot = (long long)f;
  double partAfterDot;
  if (partBeforeDot < 0)
    partAfterDot = fabsl(f) - partBeforeDot * -1;
  else
    partAfterDot = fabsl(f) - partBeforeDot;
  if (nPrecision == 0) {
    partAfterDot *= 10;
    if ((int)partAfterDot % 10 == 5) {
      partAfterDot /= 10;
      if ((int)partBeforeDot % 2 == 1) partBeforeDot += 1;
    }
  }

  char strD[1000];
  if (partBeforeDot != 0 && nPrecision != 0) {
    trasletionFromIntegerInStr(partBeforeDot, strD, flagPlus, flagSpace,
                               countNumbersInterger(partBeforeDot), 0);
    s21_strcpy(str, strD);
    s21_strcat(str, ".");
  } else if (partBeforeDot == 0 && nPrecision != 0) {
    if (f >= 0.0 && flagPlus == 0 && flagSpace == 0)
      s21_strcat(str, "0.");
    else if (f >= 0.0 && flagPlus != 0)
      s21_strcat(str, "+0.");
    else if (f >= 0.0 && flagPlus == 0 && flagSpace != 0)
      s21_strcat(str, " 0.");
    else
      s21_strcat(str, "-0.");
  } else if (partBeforeDot != 0 && nPrecision == 0 && flagDrid != 0) {
    trasletionFromIntegerInStr(partBeforeDot, strD, flagPlus, flagSpace,
                               countNumbersInterger(partBeforeDot), 0);
    s21_strcpy(str, strD);
    s21_strcat(str, ".");
  } else if (partBeforeDot != 0 && nPrecision == 0 && flagDrid == 0) {
    trasletionFromIntegerInStr(partBeforeDot, strD, flagPlus, flagSpace,
                               countNumbersInterger(partBeforeDot), 0);
    s21_strcpy(str, strD);
  } else if (partBeforeDot == 0 && nPrecision == 0 && flagDrid != 0) {
    if (f >= 0.0 && flagPlus == 0 && flagSpace == 0)
      s21_strcat(str, "0.");
    else if (f >= 0.0 && flagPlus != 0)
      s21_strcat(str, "+0.");
    else if (f >= 0.0 && flagPlus == 0 && flagSpace != 0)
      s21_strcat(str, " 0.");
    else
      s21_strcat(str, "-0.");
  } else if (partBeforeDot == 0 && nPrecision == 0 && flagDrid == 0) {
    if (f >= 0.0 && flagPlus == 0 && flagSpace == 0)
      s21_strcat(str, "0");
    else if (f >= 0.0 && flagPlus != 0)
      s21_strcat(str, "+0");
    else if (f >= 0.0 && flagPlus == 0 && flagSpace != 0)
      s21_strcat(str, " 0");
    else
      s21_strcat(str, "-0");
  } else {
    if (f >= 0.0 && flagPlus == 0 && flagSpace == 0)
      s21_strcat(str, "0.");
    else if (f >= 0.0 && flagPlus != 0)
      s21_strcat(str, "+0.");
    else if (f >= 0.0 && flagPlus == 0 && flagSpace != 0)
      s21_strcat(str, " 0.");
    else
      s21_strcat(str, "-0.");
  }
  int strLenBeforeDot = s21_strlen(str);
  if (partAfterDot < 0) partAfterDot *= -1;
  double copyPartAfterDot = partAfterDot;
  for (int j = 0; j < nPrecision / 9 + 1; j++) {
    copyPartAfterDot *= pow(10, nPrecision);
    if (j == nPrecision / 9) {
      if ((int)copyPartAfterDot % 10 == 5) {
        copyPartAfterDot /= 10;
        if ((int)copyPartAfterDot % 2 == 1 || (int)copyPartAfterDot == 0) {
          partAfterDot = round(partAfterDot * z) / z;
        }
      } else {
        partAfterDot = round(partAfterDot * z) / z;
      }
    }
    partAfterDot *= pow(10, 9);
    int d = (int)partAfterDot;
    partAfterDot -= d;
    trasletionFromIntegerInStr(d, strD, 0, 0, countNumbersInterger(d), 9);
    s21_strcat(str, strD);
  }
  int len = s21_strlen(str);
  if (nPrecision <= len) {
    str[nPrecision + strLenBeforeDot] = '\0';
  } else {
    for (int i = 0; i < nPrecision - (len - strLenBeforeDot); i++) {
      str[len + i] = '0';
    }
  }
}

char digit(int num) {
  char sym;
  switch (num) {
    case 0:
      sym = '0';
      break;
    case 1:
      sym = '1';
      break;
    case 2:
      sym = '2';
      break;
    case 3:
      sym = '3';
      break;
    case 4:
      sym = '4';
      break;
    case 5:
      sym = '5';
      break;
    case 6:
      sym = '6';
      break;
    case 7:
      sym = '7';
      break;
    case 8:
      sym = '8';
      break;
    case 9:
      sym = '9';
      break;
    case 10:
      sym = 'A';
      break;
    case 11:
      sym = 'B';
      break;
    case 12:
      sym = 'C';
      break;
    case 13:
      sym = 'D';
      break;
    case 14:
      sym = 'E';
      break;
    case 15:
      sym = 'F';
      break;
  }
  return sym;
}
// Получение целой части числа
int dectox_int(unsigned long long a, int p, char *s) {
  unsigned long long num = a;
  int rest = num % p;
  num /= p;
  int k;
  if (num == 0) {
    s[0] = digit(rest);
    k = 1;
  } else {
    k = dectox_int(num, p, s);
    s[k++] = digit(rest);
  }
  return k;
}
