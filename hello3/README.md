# HW 2 sample solution

### Copy `hello.c` to `hello.cxx`

I copy&pasted the all-in-one-file `hello.c` from class 3 as `hello.cxx` in a new `hello3/` directory. I also added a `build.sh` for it. It's now C++, but exactly the same code, and it still works exactly the same way.

```sh
kai@kais-mbp  ~/class/iam851/iam851/hello3   hw2s ✚  ./build.sh && ./hello
+ g++ hello.cxx -o hello
Hi there.
10 factorial is 3628800

```

### Use C++ I/O

I switched things to using C++'s iostream instead of C's printf. Everything still works just fine. (I'm not including the actual code changes here, since they can be seen as part of the git history.)

### Move `greeting()` function into separate file

When I moved the `greeting()` function into `greeting.cxx`, and added it into the build, I ended up with two errors:

```sh
 ✘ kai@kais-mbp  ~/class/iam851/iam851/hello3   hw2s ●  ./build.sh
+ g++ hello.cxx greeting.cxx -o hello
hello.cxx: In function 'int main(int, char**)':
hello.cxx:16:3: error: 'greeting' was not declared in this scope
   16 |   greeting();
      |   ^~~~~~~~
greeting.cxx: In function 'void greeting()':
greeting.cxx:2:28: error: 'cout' is not a member of 'std'
    2 | void greeting(void) { std::cout << "Hi there.\n"; }
      |                            ^~~~
greeting.cxx:1:1: note: 'std::cout' is defined in header '<iostream>'; did you forget to '#include <iostream>'?
```

This is different from how it went with C -- C complained about the same things, but just as warnings, while C++ is more strict and refuses to compile the code.

### Fix the errors

Both errors happened because I'm using things that the compiler doesn't yet know about out. In `greeting.cxx`, I need to `#include <iostream>` since I'm using `std::cout`, that's a standard feature of C++.

For the `greeting()` function, I need to add my own header, I'm calling it `hello.h`. After doing this, everything works again.

### Personalize the greeting

I tried to personalize the greeting the same way as it was done in C. Instead of the crash we saw when using C, we now got a build error instead (which is a bit nicer, I'd say):

```sh
 kai@kais-mbp  ~/class/iam851/iam851/hello3   hw2s ●  ./build.sh && ./hello
+ g++ hello.cxx greeting.cxx -o hello
Undefined symbols for architecture x86_64:
  "greeting()", referenced from:
      _main in cc3urauL.o
ld: symbol(s) not found for architecture x86_64
collect2: error: ld returned 1 exit status
```

What happens here is that in C++, functions remember what arguments they are called with. The `main()` program calls `greeting()` with no arguments, but the function we defined is `greeting(const char *)`, which doesn't match, so no `greeting()` function was found, that's what the error is about.

After the header consistent, everything works again.

Finally, I went and used the C++ `std::string` instead of `const char *`.

### Separate out `factorial()` function

Moved it into `factorial.cxx`, added it to the header `hello.h` and to the build, and everything works ;)

### Add a `Makefile`

I replaced the `build.sh` by a basic Makefile, just like we did for C.


