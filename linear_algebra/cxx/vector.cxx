
#include "linear_algebra.h"

vector::vector(int n) : data_(n) {}

int vector::size() const
{
  return data_.size();
}

double vector::operator()(int i) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < size());
#endif
  return data_[i];
}

double& vector::operator()(int i)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < size());
#endif
  return data_[i];
}

bool operator==(const vector& x, const vector& y)
{
  if (x.size() != y.size()) {
    return false;
  }

  for (int i = 0; i < x.size(); i++) {
    if (x(i) != y(i)) {
      return false;
    }
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const vector& v)
{
  os << "{";
  for (int i = 0; i < v.size(); i++) {
    os << " " << v(i);
  }
  os << " }";

  return os;
}
