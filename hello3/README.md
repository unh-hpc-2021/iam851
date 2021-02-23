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
