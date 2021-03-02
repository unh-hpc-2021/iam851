# HW

## Fixing the bugs

I got those two warnings:

```sh
[ 14%] Building CXX object CMakeFiles/stuff.dir/factorial.cxx.o
/Users/kai/class/iam851/iam851/class6/factorial.cxx:7:9: warning: using the result of an assignment
      as a condition without parentheses [-Wparentheses]
  if (n = 0) {
      ~~^~~
/Users/kai/class/iam851/iam851/class6/factorial.cxx:7:9: note: place parentheses around the
      assignment to silence this warning
  if (n = 0) {
        ^
      (    )
/Users/kai/class/iam851/iam851/class6/factorial.cxx:7:9: note: use '==' to turn this assignment into
      an equality comparison
  if (n = 0) {
        ^
        ==
/Users/kai/class/iam851/iam851/class6/factorial.cxx:12:1: warning: control reaches end of non-void
      function [-Wreturn-type]
}
```

I replaced `if (n = 0)` with `if (n == 0)`, which is the proper way of doing a equality comparison, fixing the first warning just as the compiler suggested.

The second warning is less clear, but what the compiler means to say is "I got to the end of the `factorial()` function, which is supposed to return an integer, but I have not encountered a `return` statement at all."
