#include <iostream>

class Vector {
private:
  unsigned int size; // Размер вектора
  double *elements;  // Указатель на массив элементов

public:
  // Конструктор с параметрами
  Vector(unsigned int size, double initial = 0.0);

  // Копирующий конструктор
  Vector(const Vector &other);

  // Деструктор
  ~Vector();

  // Методы доступа к данным
  unsigned int get_size() const;
  double get_element(unsigned int index) const;
  void set_element(unsigned int index, double value);

  // Оператор присваивания
  Vector &operator=(const Vector &other);

  // Оператор +=
  Vector &operator+=(const Vector &other);

  // Оператор -=
  Vector &operator-=(const Vector &other);

  // Бинарный оператор сложения
  Vector operator+(const Vector &other) const;

  // Унарный оператор сложения
  Vector operator+() const;

  // Бинарный оператор вычитания
  Vector operator-(const Vector &other) const;

  // Унарный оператор вычитания
  Vector operator-() const;

  // Оператор умножения вектора на число
  Vector operator*(double scalar) const;

  // Оператор умножения вектора на вектор (скалярное произведение)
  double operator*(const Vector &other) const;

  // Оператор умножения вектора на матрицу (необходимо определить отдельно класс
  // Matrix)

  // Оператор умножения числа на вектор
  friend Vector operator*(double scalar, const Vector &vec);

  // Оператор доступа к элементам по индексу
  double &operator[](unsigned index);
  // Чтение по индексу
  double operator[](unsigned index) const;

  // Оператор вывода вектора в поток
  friend std::ostream &operator<<(std::ostream &os, const Vector &vec);

  // Оператор ввода вектора из потока
  friend std::istream &operator>>(std::istream &is, Vector &vec);

  // Оператор приведения типа к указателю на double
  explicit operator double *() { return elements; }

  // Метод вычисления длины вектора
  double length() const;

  // Метод, возвращающий размерность вектора
  unsigned int dimension() const;
};

// Реализация методов и операторов класса Vector

// Реализация конструктора с параметрами
Vector::Vector(unsigned int size, double initial) : size(size) {
  elements = new double[size];
  for (unsigned int i = 0; i < size; ++i) {
    elements[i] = initial;
  }
}

// Реализация копирующего конструктора
Vector::Vector(const Vector &other) : size(other.size) {
  elements = new double[size];
  for (unsigned int i = 0; i < size; ++i) {
    elements[i] = other.elements[i];
  }
}

// Реализация деструктора
Vector::~Vector() { delete[] elements; }

// Метод получения размера вектора
unsigned int Vector::get_size() const { return size; }

// Метод получения элемента по индексу
double Vector::get_element(unsigned int index) const {
  if (index < size) {
    return elements[index];
  } else {
    // Обработка ошибки, например, выброс исключения
    return 0.0;
  }
}

// Метод установки значения элемента по индексу
void Vector::set_element(unsigned int index, double value) {
  if (index < size) {
    elements[index] = value;
  } else {
    // Обработка ошибки, например, выброс исключения
  }
}
