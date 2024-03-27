#include "Matrix.h"
#include "Vector.h"
#include <iostream>

int main(int argc, char *argv[]) {
  const int vectorSize = 3;
  double v1_data[vectorSize] = {1.0, 2.0, 3.0};
  double v2_data[vectorSize] = {4.0, 5.0, 6.0};
  double v3_data[vectorSize] = {7.0, 8.0, 9.0};
  double c1_data[vectorSize] = {0.5, 0.5, 0.5};
  double c2_data[vectorSize] = {1.0, 1.0, 1.0};
  double c3_data[vectorSize] = {2.0, 2.0, 2.0};

  Vector v1(vectorSize);
  Vector v2(vectorSize);
  Vector v3(vectorSize);
  Vector c1(vectorSize);
  Vector c2(vectorSize);
  Vector c3(vectorSize);

  for (int i = 0; i < vectorSize; ++i) {
    v1[i] = v1_data[i];
    v2[i] = v2_data[i];
    v3[i] = v3_data[i];
    c1[i] = c1_data[i];
    c2[i] = c2_data[i];
    c3[i] = c3_data[i];
  }

  const int numRows = 3;
  const int numNonZeros = 3;
  double values[numNonZeros] = {1.0, 2.0, 3.0};
  int columns[numNonZeros] = {0, 1, 2};
  int rowPointers[numRows + 1] = {0, 1, 2, 3};

  CSLRMatrix m1(numRows, numNonZeros, values, columns, rowPointers);

  // Тестирование
  Vector temp1 = v1 - (c2 * v2);
  Vector temp2 = c1 * m1 * temp1;
  Vector temp3 = temp2 + v3 * c3;
  Vector res = -temp3;

  std::cout << "Результат: " << res << std::endl;

  return 0;
}
