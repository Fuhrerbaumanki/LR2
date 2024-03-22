#include "Matrix.h"
#include "Vector.h"
#include <iostream>

int main() {
  Vector v1(3, 1.0);
  Vector v2(3, 2.0);
  Vector v3(3, 3.0);
  double c1 = 2.0;
  double c2 = 1.5;
  double c3 = 0.5;

  CSLRMatrix m1(3);
  m1(0, 0) = 1.0;
  m1(1, 1) = 2.0;
  m1(2, 2) = 3.0;

  // Testing vector operations
  Vector res = -c1 * m1 * (v1 - c2 * v2) + v3 * c3;

  std::cout << "Result Vector: " << res << std::endl;

  return 0;
}
