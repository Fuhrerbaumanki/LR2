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
  // Конструктор, принимающий размер вектора и начальное значение элементов
  Vector(int size, double initial = 0.0) : elements(size, initial) {}

  // Копирующий конструктор
  Vector(const Vector &other) : elements(other.elements) {}

  // Деструктор
  ~Vector() { std::cout << "Деструктор вызван" << std::endl; }

  void print() const {
    for (const auto &element : elements) {
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }

  double calculateLength() const {
    double sumOfSquares = 0.0;
    for (const auto &element : elements) {
      sumOfSquares += element * element;
    }
    return std::sqrt(sumOfSquares);
  }

  int getSize() const { return elements.size(); }

  // Оператор присваивания
  Vector &operator=(const Vector &other) {
    elements = other.elements;
    return *this;
  }

  // Оператор +=
  Vector &operator+=(const Vector &other) {
    for (size_t i = 0; i < elements.size(); ++i) {
      elements[i] += other.elements[i];
    }
    return *this;
  }

  // Оператор -=
  Vector &operator-=(const Vector &other) {
    for (size_t i = 0; i < elements.size(); ++i) {
      elements[i] -= other.elements[i];
    }
    return *this;
  }

  // Бинарный оператор сложения
  Vector operator+(const Vector &other) const {
    Vector result(*this);
    result += other;
    return result;
  }

  // Унарный оператор сложения
  Vector operator+() const { return *this; }

  // Бинарный оператор вычитания
  Vector operator-(const Vector &other) const {
    Vector result(*this);
    result -= other;
    return result;
  }
  // Унарный оператор вычитания
  Vector operator-() const {
    Vector result(*this);
    for (double &element : result.elements) {
      element = -element;
    }
    return result;
  }

  // Оператор умножения вектора на число
  Vector operator*(double scalar) const {
    Vector result(*this);
    for (double &element : result.elements) {
      element *= scalar;
    }
    return result;
  }
  // Оператор скалярного произведения векторов
  double operator*(const Vector &other) const {
    double dotProduct = 0.0;
    for (size_t i = 0; i < elements.size(); ++i) {
      dotProduct += elements[i] * other.elements[i];
    }
    return dotProduct;
  }

  // Оператор приведения типа к указателю на double
  operator double *() { return elements.data(); }

  // Оператор индексации []
  double &operator[](int index) { return elements[index]; }

  // Оператор вывода <<
  friend std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    for (const auto &element : vector.elements) {
      os << element << " ";
    }
    return os;
  }
  // Оператор ввода >>
  friend std::istream &operator>>(std::istream &is, Vector &vector) {
    for (auto &element : vector.elements) {
      is >> element;
    }
    return is;
  }
};
