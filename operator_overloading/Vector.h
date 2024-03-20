#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <iostream>
#include <vector>

class OutOfRangeException : public std::exception {
public:
  const char *what() const noexcept override {
    return "Индекс вышел за пределы вектора";
  }
};

class IncompatibleDimException : public std::exception {
public:
  const char *what() const noexcept override {
    return "Несовместимые размеры для матричных или векторных операций";
  }
};

class Vector {
private:
  std::vector<double> elements;

public:
  Vector(int size, double initial = 0.0);
  Vector(const Vector &other);
  ~Vector();

  void print() const;
  double calculateLength() const;
  int getSize() const;

  Vector &operator=(const Vector &other);
  Vector &operator+=(const Vector &other);
  Vector &operator-=(const Vector &other);
  Vector operator+(const Vector &other) const;
  Vector operator+() const;
  Vector operator-(const Vector &other) const;
  Vector operator-() const;
  Vector operator*(double scalar) const;
  double operator*(const Vector &other) const;
  operator double *();
  double &operator[](int index);

  friend std::ostream &operator<<(std::ostream &os, const Vector &vector);
  friend std::istream &operator>>(std::istream &is, Vector &vector);
};

#endif // VECTOR_H
