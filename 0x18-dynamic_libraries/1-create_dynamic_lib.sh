#!/bin/bash
gcc -Wall -Wextra -Werror -pedantic -c -fPIC abs.c   isalpha.c  islower.c  memcpy.c  putchar.c  strcat.c  strcmp.c  strlen.c   strncpy.c  strspn.c atoi.c  isdigit.c  isupper.c  memset.c  puts.c     strchr.c  strcpy.c  strncat.c  strpbrk.c  strstr.c
gcc -shared -o liball.so abs.o   isalpha.o  islower.o  memcpy.o  putchar.o  strcat.o  strcmp.o  strlen.o  strncpy.o  strspn.o
atoi.o  isdigit.o  isupper.o  memset.o  puts.o  strchr.o  strcpy.o  strncat.o  strpbrk.o  strstr.o
