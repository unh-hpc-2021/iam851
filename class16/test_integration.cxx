
#include <cmath>
#include <iostream>

double f(double x)
{
  return std::sqrt(1. - x * x);
}

int main(int argc, char** argv)
{
  const int N = 10;

  double sum = 0.;
  double dx = 1. / N;
  for (int i = 0; i < N; i++) {
    sum += .5 * dx * (f(i * dx) + f((i + 1) * dx));
  }

  std::cout << "integral is approximately " << sum << "\n";
}
