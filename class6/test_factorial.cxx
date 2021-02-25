
#include "hello.h"

#include <cassert>

int main() {
  assert(factorial(4) == 24);
  assert(factorial(1) == 1);
  assert(factorial(0) == 1);
  // we don't have a good way to handle negative arguments, so we don't.
  // Hence it doesn't make sense to test this case, either. FIXME
}
