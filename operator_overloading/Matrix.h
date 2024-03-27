#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h" // Добавляем включение заголовочного файла для использования класса Vector
#include <iostream>

class CSLRMatrix {
public:
  CSLRMatrix(int numRows, int numNonZeros, const double *valuesArray,
             const int *columnsArray, const int *rowPointersArray);
  ~CSLRMatrix();

  void printMatrix() const;
  int getNumRows() const;
  int getNumNonZeros() const;

  friend std::istream &operator>>(std::istream &in, CSLRMatrix &matrix);
  friend std::ostream &operator<<(std::ostream &out, const CSLRMatrix &matrix);
  friend CSLRMatrix operator*(double scalar, const CSLRMatrix &matrix);

  Vector operator*(const Vector &vec) const;

private:
  int numRows;
  int numNonZeros;
  double *values;
  int *columns;
  int *rowPointers;
};

#endif // MATRIX_H
