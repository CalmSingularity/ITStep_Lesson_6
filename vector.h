#ifndef _VECTOR__H__
#define _VECTOR__H__


class Vector {
private:
  int* data;
  size_t N_array, N_filled;

public:
  Vector();
  Vector(size_t N);
  Vector(const Vector &obj);
  ~Vector();

  Vector operator = (const Vector &A);

  double length();
  void push_back(int x);
  int size();
  int filled();
  int getElement(size_t pos);
  void setEmpty();
};


std::ostream& operator << (std::ostream& out, Vector& A);
std::istream& operator >> (std::istream& in, Vector& A);


#include "vector.cpp"

#endif // _VECTOR__H__

