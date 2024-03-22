#ifndef CSLRMATRIX_H
#define CSLRMATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

class OutOfRangeException : public std::exception {
public:
  const char *what() const noexcept override {
    return "Индекс вышел за пределы";
  }
};

class IncompatibleDimException : public std::exception {
public:
  const char *what() const noexcept override { return "Ошибка размерности"; }
};

class CSLRMatrix {
private:
  unsigned size;
  std::vector<double> values;
  std::vector<unsigned> col_indexes;
  std::vector<unsigned> row_ptrs;

public:
  CSLRMatrix(unsigned size);

  CSLRMatrix operator*(double scalar) const;
  friend CSLRMatrix operator*(double scalar, const CSLRMatrix &matrix);

  unsigned count_nonzero_elements() const;

  void set_element(unsigned row, unsigned col, double value);
  double get_element(unsigned row, unsigned col) const;
  double &operator()(unsigned row, unsigned col);

  friend std::istream &operator>>(std::istream &is, CSLRMatrix &matrix);
  friend std::ostream &operator<<(std::ostream &os, const CSLRMatrix &matrix);
};

#endif // CSLRMATRIX_H
