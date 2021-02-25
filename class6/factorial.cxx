
#include "hello.h"

int factorial(int n) {
  int result;

  if (n = 0) {
    result = 1;
  } else {
    result = n * factorial(n - 1);
  }
}
