#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
public:
  Vector(const Vector &other);
  Vector(int size);
  ~Vector();
  Vector &operator=(const Vector &other);
  int getSize() const;
  Vector &operator+=(const Vector &other);
  Vector &operator-=(const Vector &other);
  Vector operator+(const Vector &other) const;
  Vector operator+() const;
  Vector operator-(const Vector &other) const;
  Vector operator-() const;
  Vector operator*(double scalar) const;
  double operator*(const Vector &other) const;
  friend Vector operator*(double scalar, const Vector &vec);
  double &operator[](int index);
  friend std::ostream &operator<<(std::ostream &out, const Vector &vec);
  friend std::istream &operator>>(std::istream &in, Vector &vec);
  operator double *() const;

private:
  int size;
  double *array;
};

#endif // VECTOR_H
