#include <vector>

// Структура для хранения ненулевых элементов матрицы в формате CSLR
struct CSLR {
  unsigned int row;  // Номер строки
  double value;      // Значение элемента
  unsigned int next; // Индекс следующего элемента в той же строке
};

class CSLRMatrix {
private:
  unsigned int size;            // Размер матрицы
  std::vector<double> diagonal; // Диагональные элементы
  std::vector<CSLR> rows; // Ненулевые элементы по строкам

public:
  // Конструктор с параметрами
  CSLRMatrix(unsigned int size);

  // Деструктор
  ~CSLRMatrix();

  // Методы доступа к данным
  unsigned int get_size() const;
  double get_element(unsigned int row, unsigned int col) const;
  void set_element(unsigned int row, unsigned int col, double value);

  // Оператор доступа к элементам по индексу
  double &operator()(unsigned int row, unsigned int col);

  // Метод вывода матрицы
  void print() const;
};
