#include <iostream>
#include "square_matrix.h"


int main(int argc, char** argv) {
  
  size_t size;
  std::cout << "Enter the size of matrix: ";
  std::cin >> size;

  SquareMatrix A(size);
  std::cout << "Enter matrix A of size " << A.getSize() << ":\n";
  std::cin >> A;

  SquareMatrix B(size);
  std::cout << "Enter matrix B of size " << B.getSize() << ":\n";
  std::cin >> B;


  SquareMatrix X = A + B;
  std::cout << "\nA + B =\n" << X;

  SquareMatrix Y = A - B;
  std::cout << "\nA - B =\n" << Y;

  SquareMatrix Z = A * B;
  std::cout << "\nA * B =\n" << Z;

  A.transpose();
  std::cout << "\nA transposed:\n" << A;

  return 0;
}