#! /bin/bash

gcc -Wall -c hello.c
gcc -Wall -c greeting.c
gcc -Wall -c factorial.c
gcc hello.o greeting.o factorial.o -o hello
