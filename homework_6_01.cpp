#include <iostream>

struct SquareMatrix {
  int** data;
  size_t size;

  // Constructor by default:
  SquareMatrix() {
    size = 2;
    data = new int*[size];
    for (size_t i = 0; i < size; ++i) {
      data[i] = new int[size];
    }
  }

  // Constructor with argument (size):
  SquareMatrix(size_t size) {
    this->size = size;
    
    // allocate memory:
    data = new int*[size];
    for (size_t i = 0; i < size; ++i) {
      data[i] = new int[size];
    }
  }

  // Copy constructor:
  SquareMatrix(const SquareMatrix &obj) {
    this->size = obj.size;
        
    // allocate memory:
    this->data = new int*[size];
    for (size_t i = 0; i < size; ++i) {
      this->data[i] = new int[size];
    }

    // deep copy:
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        this->data[row][col] = obj.data[row][col];
      }
    }
  }

  // Destructor:
  ~SquareMatrix() {
    for (size_t i = 0; i < size; ++i) {
      delete [] this->data[i];
    }
    delete [] this->data;
  }


  // Assignment operator =:
  SquareMatrix& operator = (SquareMatrix &A) {
    this->size = A.size;

    // deep copy:
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        this->data[row][col] = A.data[row][col];
      }
    }

    return *this;
  }

  // Operator +:
  SquareMatrix operator + (SquareMatrix &A) {
    SquareMatrix R(size);
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        R.data[row][col] = data[row][col] + A.data[row][col];
      }
    }    
    return R;
  }

  // Operator - 
  SquareMatrix operator - (SquareMatrix &A) {
    SquareMatrix R(size);
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        R.data[row][col] = data[row][col] - A.data[row][col];
      }
    }    
    return R;
  }

  // Operator * (multiply):
  SquareMatrix operator * (SquareMatrix &A) {
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

  SquareMatrix transpose() {
    SquareMatrix transposed(size);
    for (size_t row = 0; row < size; ++row) {
      for (size_t col = 0; col < size; ++col) {
        transposed.data[row][col] = this->data[col][row];
      }
    } 
    return transposed; 
  }

};


// Output operator <<
std::ostream& operator << (std::ostream& out, SquareMatrix& A) {
  for (size_t row = 0; row < A.size; ++row) {
    for (size_t col = 0; col < A.size; ++col) {
      out << A.data[row][col] << " ";
    }
    out << "\n";
  }
  // out << "\n";
  return out;
}

// Input operator >>
std::istream& operator >> (std::istream& in, SquareMatrix& A) {
  for (size_t row = 0; row < A.size; ++row) {
    for (size_t col = 0; col < A.size; ++col) {
      std::cin >> A.data[row][col];
    }
  }
  return in;
}


int main(int argc, char** argv) {
  
  size_t size;
  std::cout << "Enter the size of matrix: ";
  std::cin >> size;

  SquareMatrix A(size);
  std::cout << "Enter matrix A of size " << A.size << ":\n";
  std::cin >> A;

  SquareMatrix B(size);
  std::cout << "Enter matrix B of size " << B.size << ":\n";
  std::cin >> B;

  SquareMatrix X = A + B;
  std::cout << "\nA + B =\n" << X;

  SquareMatrix Y = A - B;
  std::cout << "\nA - B =\n" << Y;

  SquareMatrix Z = A * B;
  std::cout << "\nA * B =\n" << Z;

  SquareMatrix T = A.transpose();
  std::cout << "\nA transposed:\n" << T;

  return 0;
}