#include <iostream>
#include <vector>

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
  CSLRMatrix(unsigned size) : size(size) { row_ptrs.push_back(0); }

  CSLRMatrix operator*(double scalar) const {
    CSLRMatrix result(size * scalar);
    for (unsigned i = 0; i < values.size(); ++i) {
      result.values.push_back(values[i] * scalar);
      result.col_indexes.push_back(col_indexes[i]);
      if (i % size == 0) {
        result.row_ptrs.push_back(result.values.size());
      }
    }
    return result;
  }

  friend CSLRMatrix operator*(double scalar, const CSLRMatrix &matrix) {
    return matrix * scalar;
  }

  unsigned count_nonzero_elements() const { return values.size(); }

  void set_element(unsigned row, unsigned col, double value) {
    unsigned index = row_ptrs[row];
    while (index < row_ptrs[row + 1] && col_indexes[index] <= col) {
      if (col_indexes[index] == col) {
        values[index] = value;
        return;
      }
      index++;
    }
    values.insert(values.begin() + index, value);
    col_indexes.insert(col_indexes.begin() + index, col);
    for (unsigned i = row + 1; i < row_ptrs.size(); ++i) {
      row_ptrs[i]++;
    }
  }

  double get_element(unsigned row, unsigned col) const {
    for (unsigned i = row_ptrs[row]; i < row_ptrs[row + 1]; ++i) {
      if (col_indexes[i] == col) {
        return values[i];
      }
    }
    return 0.0; // Assuming 0 for missing elements
  }

  double &operator()(unsigned row, unsigned col) {
    unsigned index = row_ptrs[row];
    while (index < row_ptrs[row + 1] && col_indexes[index] <= col) {
      if (col_indexes[index] == col) {
        return values[index];
      }
      index++;
    }
    values.insert(values.begin() + index, 0.0);
    col_indexes.insert(col_indexes.begin() + index, col);
    for (unsigned i = row + 1; i < row_ptrs.size(); ++i) {
      row_ptrs[i]++;
    }
    return values[index];
  }

  friend std::istream &operator>>(std::istream &is, CSLRMatrix &matrix) {
    double value;
    for (unsigned i = 0; i < matrix.size; ++i) {
      for (unsigned j = 0; j < matrix.size; ++j) {
        is >> value;
        if (value != 0.0) {
          matrix.set_element(i, j, value);
        }
      }
    }
    return is;
  }

  friend std::ostream &operator<<(std::ostream &os, const CSLRMatrix &matrix) {
    for (unsigned i = 0; i < matrix.size; ++i) {
      for (unsigned j = 0; j < matrix.size; ++j) {
        os << matrix.get_element(i, j) << " ";
      }
      os << std::endl;
    }
    return os;
  }
};
