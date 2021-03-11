
#include <stdio.h>

void foo(double p)
{
  printf("foo before p = %g\n", p);
  p = 10.;
  printf("foo after p = %g\n", p);
}

int main()
{
  double p = 99.;
  printf("main before p = %g\n", p);
  foo(p);
  printf("main after p = %g\n", p);
}