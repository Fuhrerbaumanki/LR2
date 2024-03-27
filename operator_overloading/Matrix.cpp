#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <sstream>

CSLRMatrix::CSLRMatrix(int numRows, int numNonZeros, const double *valuesArray,
                       const int *columnsArray, const int *rowPointersArray)
    : numRows(numRows), numNonZeros(numNonZeros) {
  values = new double[numNonZeros];
  columns = new int[numNonZeros];
  rowPointers = new int[numRows + 1];

  std::copy(valuesArray, valuesArray + numNonZeros, values);
  std::copy(columnsArray, columnsArray + numNonZeros, columns);
  std::copy(rowPointersArray, rowPointersArray + numRows + 1, rowPointers);
}

CSLRMatrix::~CSLRMatrix() {
  delete[] values;
  delete[] columns;
  delete[] rowPointers;
}

void CSLRMatrix::printMatrix() const {
  for (int i = 0; i < numRows; ++i) {
    for (int j = rowPointers[i]; j < rowPointers[i + 1]; ++j) {
      std::cout << "Строка: " << i << ", Столбец: " << columns[j]
                << ", Значение: " << values[j] << std::endl;
    }
  }
}

int CSLRMatrix::getNumRows() const { return numRows; }

int CSLRMatrix::getNumNonZeros() const { return numNonZeros; }

std::istream &operator>>(std::istream &in, CSLRMatrix &matrix) {
  int numRows, numNonZeros;
  in >> numRows >> numNonZeros;

  double *values = new double[numNonZeros];
  int *columns = new int[numNonZeros];
  int *rowPointers = new int[numRows + 1];

  for (int i = 0; i < numNonZeros; ++i) {
    in >> values[i] >> columns[i];
  }

  for (int i = 0; i < numRows + 1; ++i) {
    in >> rowPointers[i];
  }

  matrix = CSLRMatrix(numRows, numNonZeros, values, columns, rowPointers);

  delete[] values;
  delete[] columns;
  delete[] rowPointers;

  return in;
}

std::ostream &operator<<(std::ostream &out, const CSLRMatrix &matrix) {
  std::ostringstream oss;

  for (int i = 0; i < matrix.numRows; ++i) {
    for (int j = matrix.rowPointers[i]; j < matrix.rowPointers[i + 1]; ++j) {
      oss << "Строка: " << i << ", Столбец: " << matrix.columns[j]
          << ", Значение: " << matrix.values[j] << std::endl;
    }
  }

  out << oss.str();
  return out;
}

CSLRMatrix operator*(double scalar, const CSLRMatrix &matrix) {
  double *newValues = new double[matrix.numNonZeros];
  int *newColumns = new int[matrix.numNonZeros];
  int *newRowPointers = new int[matrix.numRows + 1];

  for (int i = 0; i < matrix.numNonZeros; ++i) {
    newValues[i] = scalar * matrix.values[i];
    newColumns[i] = matrix.columns[i];
  }

  for (int i = 0; i < matrix.numRows + 1; ++i) {
    newRowPointers[i] = matrix.rowPointers[i];
  }

  return CSLRMatrix(matrix.numRows, matrix.numNonZeros, newValues, newColumns,
                    newRowPointers);
}

Vector CSLRMatrix::operator*(const Vector &vec) const {
  Vector result(numRows);

  for (int i = 0; i < numRows; ++i) {
    double sum = 0.0;
    for (int j = rowPointers[i]; j < rowPointers[i + 1]; ++j) {
      sum += values[j] * vec[columns[j]];
    }
    result[i] = sum;
  }

  return result;
}
