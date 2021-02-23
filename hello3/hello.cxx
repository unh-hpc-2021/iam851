
#include "hello.h"

#include <iostream>

int factorial(int n) {
  int i;
  int retval = 1;

  for (i = 1; i <= n; i++) {
    retval *= i;
  }

  return retval;
}

int main(int argc, char **argv) {
  greeting();

  std::cout << "10 factorial is " << factorial(10) << "\n";
}
