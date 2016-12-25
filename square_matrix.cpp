#include <iostream>
#include "square_matrix.h"
 
  void SquareMatrix::allocateMemory() {
    data = new int*[size];
    for (size_t i = 0; i < size; ++i) {
      data[i] = new int[size];
    }
  }


  size_t SquareMatrix::getSize() {
    return(size);
  }

  int SquareMatrix::getElement(size_t row, size_t col) {
    return data[row][col];
  }

  void SquareMatrix::setElement(size_t row, size_t col, int value) {
    data[row][col] = value;
  }


  // Constructor by default:
  SquareMatrix::SquareMatrix()
  : size(2) {
    this->allocateMemory();
  }

  // Constructor with argument (size):
  SquareMatrix::SquareMatrix(size_t s)
  : size(s) {
    this->allocateMemory();
  }

  // Copy constructor:
  SquareMatrix::SquareMatrix(const SquareMatrix &obj):
  size(obj.size) {

    this->allocateMemory();

    // deep copy:
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        this->data[row][col] = obj.data[row][col];
      }
    }
  }

  // Destructor:
  SquareMatrix::~SquareMatrix() {
    for (size_t i = 0; i < size; ++i) {
      delete [] this->data[i];
    }
    delete [] this->data;
  }


  // Assignment operator =:
  SquareMatrix SquareMatrix::operator = (const SquareMatrix &A) {
    this->size = A.size;

    // deep copy:
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        this->data[row][col] = A.data[row][col];
      }
    }

    return *this;
  }

  // Operator + (add):
  SquareMatrix SquareMatrix::operator + (const SquareMatrix &A) {
    SquareMatrix R(size);
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        R.data[row][col] = data[row][col] + A.data[row][col];
      }
    }    
    return R;
  }

  // Operator - (subtract):
  SquareMatrix SquareMatrix::operator - (const SquareMatrix &A) {
    SquareMatrix R(size);
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        R.data[row][col] = data[row][col] - A.data[row][col];
      }
    }    
    return R;
  }

  // Operator * (multiply):
  SquareMatrix SquareMatrix::operator * (const SquareMatrix &A) {
    SquareMatrix R(size);
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        R.data[row][col] = 0;
        for (size_t k = 0; k < size; ++k) {
          R.data[row][col] += data[row][k] * A.data[k][col];
        }
      }
    }    
    return R;
  }


  void SquareMatrix::transpose() {
    int temp;
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = row + 1; col < size; ++col) {
        
        // swap date[row][col] and data[col][row]:
        temp = data[row][col];
        data[row][col] = data[col][row];
        data[col][row] = temp;
      }
    } 
  }
  



// Output operator <<
std::ostream& operator << (std::ostream& out, SquareMatrix& A) {
  for (size_t row = 0; row < A.getSize(); ++row) {
    for (size_t col = 0; col < A.getSize(); ++col) {
      out << A.getElement(row, col) << " ";
    }
    out << "\n";
  }
  // out << "\n";
  return out;
}

// Input operator >>
std::istream& operator >> (std::istream& in, SquareMatrix& A) {
  for (size_t row = 0; row < A.getSize(); ++row) {
    for (size_t col = 0; col < A.getSize(); ++col) {
      int value;
      std::cin >> value;
      A.setElement(row, col, value);
    }
  }
  return in;
}
