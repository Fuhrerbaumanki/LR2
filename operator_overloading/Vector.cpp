#include "Vector.h"
#include <iostream>

Vector::Vector(const Vector &other) {
  size = other.size;
  array = new double[size];
  for (int i = 0; i < size; ++i) {
    array[i] = other.array[i];
  }
}

// Конструктор с заданным размером
Vector::Vector(int size) {
  this->size = size;
  array = new double[size];
}

// Деструктор
Vector::~Vector() {
  delete[] array;
  std::cout << "Деструктор вызван" << std::endl;
}

// Оператор присваивания
Vector &Vector::operator=(const Vector &other) {
  if (this != &other) {
    delete[] array;
    size = other.size;
    array = new double[size];
    for (int i = 0; i < size; ++i) {
      array[i] = other.array[i];
    }
  }
  return *this;
}

// Метод для получения размера вектора
int Vector::getSize() const { return size; }

// Оператор +=
Vector &Vector::operator+=(const Vector &other) {
  for (int i = 0; i < size; ++i) {
    array[i] += other.array[i];
  }
  return *this;
}

// Оператор -=
Vector &Vector::operator-=(const Vector &other) {
  for (int i = 0; i < size; ++i) {
    array[i] -= other.array[i];
  }
  return *this;
}

// Оператор + (бинарный)
Vector Vector::operator+(const Vector &other) const {
  Vector result(size);
  for (int i = 0; i < size; ++i) {
    result.array[i] = array[i] + other.array[i];
  }
  return result;
}

// Оператор + (унарный)
Vector Vector::operator+() const {
  Vector result(size);
  for (int i = 0; i < size; ++i) {
    result.array[i] = array[i];
  }
  return result;
}

// Оператор - (бинарный)
Vector Vector::operator-(const Vector &other) const {
  Vector result(size);
  for (int i = 0; i < size; ++i) {
    result.array[i] = array[i] - other.array[i];
  }
  return result;
}

// Оператор - (унарный)
Vector Vector::operator-() const {
  Vector result(size);
  for (int i = 0; i < size; ++i) {
    result.array[i] = -array[i];
  }
  return result;
}

// Оператор * (умножение на число)
Vector Vector::operator*(double scalar) const {
  Vector result(size);
  for (int i = 0; i < size; ++i) {
    result.array[i] = array[i] * scalar;
  }
  return result;
}

// Оператор * (скалярное произведение)
double Vector::operator*(const Vector &other) const {
  double dotProduct = 0.0;
  for (int i = 0; i < size; ++i) {
    dotProduct += array[i] * other.array[i];
  }
  return dotProduct;
}
/*
Vector Vector::operator*(const double *matrix, int matrixSize) const {
  Vector result(matrixSize);
  for (int i = 0; i < matrixSize; ++i) {
    double sum = 0.0;
    for (int j = 0; j < size; ++j) {
      sum += matrix[i][j] * array[j];
    }
    result[i] = sum;
  }
  return result;
}
*/
// Оператор * (умножение числа на вектор)
Vector operator*(double scalar, const Vector &vec) { return vec * scalar; }

// Оператор []
double &Vector::operator[](int index) { return array[index]; }

// Оператор вывода <<
std::ostream &operator<<(std::ostream &out, const Vector &vec) {
  out << "[";
  for (int i = 0; i < vec.size; ++i) {
    out << vec.array[i];
    if (i != vec.size - 1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}

// Оператор ввода >>
std::istream &operator>>(std::istream &in, Vector &vec) {
  for (int i = 0; i < vec.size; ++i) {
    in >> vec.array[i];
  }
  return in;
}

// Оператор приведения типа к указателю на double
Vector::operator double *() const { return array; }
