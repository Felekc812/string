CC = gcc
CFLAGS =-Wall -Wextra -Werror -std=c11
CFLAGS_GCOV =-fprofile-arcs --coverage

OS=$(shell uname)
ifeq ($(OS), Linux)
  LIBS=-lcheck -lpthread -lrt -lm -g
else
  LIBS=-lcheck
endif

all: s21_string.a test gcov_report

test: s21_string.o s21_string.a
	gcc $(CFLAGS_GCOV)  s21_string_test.c s21_string.c $(LIBS)
	./a.out

s21_string.a:
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o
	ar rc s21_string.a s21_string.o

gcov_report:
	gcovr --html --html-details -o report.html

style:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extensions=c s21_string.c s21_string_test.c

leaks: test
	CK_FORK=no leaks -atExit -- ./a.out

clean:
	rm -rf ./lcov_report
	rm *.o *.a *.gcno *.gcda *.html *.css *.out
