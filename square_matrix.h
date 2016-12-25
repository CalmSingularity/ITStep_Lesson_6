#ifndef LIB_SQUARE_MATRIX__H__
#define LIB_SQUARE_MATRIX__H__


class SquareMatrix {
private:
  int** data;
  size_t size;
  void allocateMemory();

public:
  size_t getSize();
  int getElement(size_t row, size_t col);
  void setElement(size_t row, size_t col, int value);
  void transpose();

  SquareMatrix();    // constructor by default
  SquareMatrix(size_t s);   // constructor with argument (size)
  SquareMatrix(const SquareMatrix &obj);     // copy constructor
  ~SquareMatrix();     // Destructor:
  
  SquareMatrix operator = (const SquareMatrix &A); // assignment operator =
  SquareMatrix operator + (const SquareMatrix &A); // operator + (add)
  SquareMatrix operator - (const SquareMatrix &A); // operator - (subtract)
  SquareMatrix operator * (const SquareMatrix &A); // operator * (multiply)
};


std::ostream& operator << (std::ostream& out, SquareMatrix& A);
std::istream& operator >> (std::istream& in, SquareMatrix& A);


#endif // LIB_SQUARE_MATRIX__H__