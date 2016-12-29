#include <iostream>
#include "vector.h"


int main(int argc, char** argv) {
  
  Vector A;
  Vector B(5);
  std::cout << "Enter a vector of 5 elements: ";
  std::cin >> B;
  Vector C = B;
  std::cout << "The copied vector is: " << C;
  std::cout << "Length is: " << C.length() << "\n";
  std::cout << "Size is: " << C.size() << "\n";

  return 0;
}