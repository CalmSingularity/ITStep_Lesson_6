#include <iostream>
#include <cmath>


// Constructor by default:
Vector::Vector()
: N_array(16) {
  data = new int[N_array];
}

// Constructor with argument (size):
Vector::Vector(size_t s)
: N_array(s) {
  data = new int[N_array];
}

// Copy constructor:
Vector::Vector(const Vector &obj)
: N_array(obj.N_array), N_filled(obj.N_filled) {
  data = new int[N_array];
  // deep copy:
  for (size_t i = 0; i < N_filled; ++i) {
    this->data[i] = obj.data[i];
  }
}

// Assignment operator =:
Vector Vector::operator = (const Vector &A) {
  this->N_array = A.N_array;
  this->N_filled = A.N_filled;

  // deep copy:
  for (size_t i = 0; i < N_filled; ++i) {
    this->data[i] = A.data[i];
  }

  return *this;
}


// Destructor:
Vector::~Vector() {
  delete [] this->data;
}


int Vector::getElement(size_t pos) {
  return data[pos];
}

void Vector::setEmpty() {  // to empty the array before using operator >>
  N_filled = 0;
}

int Vector::size() {
  return N_filled;
}

int Vector::filled() {
  return N_array;
}

void Vector::push_back(int x) {
  if (N_filled < N_array) {
    data[N_filled] = x;
    ++N_filled;
  } else {
    std::cout << "Error: Vector overflow!";
  }
}

double Vector::length() {
  double sum = 0;
  for (size_t i = 0; i < N_filled; ++i) {
    sum += data[i] * data[i];
  }
  return sqrt(sum);
}


// Output operator <<
std::ostream& operator << (std::ostream& out, Vector& A) {
  for (size_t i = 0; i < A.size(); ++i) {
    out << A.getElement(i) << " ";
  }
  out << "\n";
  return out;
}

// Input operator >>
std::istream& operator >> (std::istream& in, Vector& A) {
  A.setEmpty();
  int value;
  for (size_t i = 0; i < A.filled(); ++i) {
    std::cin >> value;
    A.push_back(value);
  }
  return in;
}