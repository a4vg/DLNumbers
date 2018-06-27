#ifndef NUMC_H
#define NUMC_H

#include <iostream>
#include <cmath> // to use round and pow
#include <random>
#include <vector>
#include <exception>
#include <type_traits>

// Defining Error class
/*
class MatrixRangeError: public std::exception{
  virtual const char* what()const throw(){
    return "Error: check compatibility between rows and columns of both matrices";
  }
}mre;
*/

// Template allows only arithmetic types (float, double, int, etc) for typename T

/*
NCMatrix is simply a class containing a 2d vector which aim is
to simplify matrix operations.
*/

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class NCMatrix;

template<typename T>
class NCMatrix<T>{
public:
  std::vector<std::vector<T>> init;

  NCMatrix();
  NCMatrix(std::vector<std::vector<T>> vector);
  NCMatrix(const NCMatrix<T>&);
  NCMatrix(int rows, int cols);
  NCMatrix(int rows, int cols, T number);


  NCMatrix<T> operator*(const T& scalar) const;
  NCMatrix<T> operator*=(const T& scalar);


  NCMatrix<T> operator*(const NCMatrix<T>& M2) const;
  //NCMatrix<T>& operator*=(const NCMatrix<T>& M2);


  NCMatrix<T> operator+(const NCMatrix<T>& M2) const;
  NCMatrix<T> operator-(const NCMatrix<T>& M2) const;

  NCMatrix<T>& operator+=(const NCMatrix<T>& M2);
  NCMatrix<T>& operator-=(const NCMatrix<T>& M2);
  //friend std::istream & operator >> (istream&, NCMatrix&);
  friend std::ostream & operator << (std::ostream&, const NCMatrix& NM);

  void print();
  void full(int rows, int cols, T number);
  int rows() const;
  int cols() const;
  NCMatrix<T> Transpose();
};

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NCMatrix<T> operator*(T scalar, const NCMatrix<T>& NM);

// Overloads operator <<, simplifies matrix printing
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
std::ostream& operator<<(std::ostream& os, const NCMatrix<T>& M);

namespace NumC{

  // outside function to deal with matrix multiplication
  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  NCMatrix<T> dot(const NCMatrix<T>& M1, const NCMatrix<T>& M2);

  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  NCMatrix<T> NMfull(int rows, int cols, T number);

  // Outside function that returns NCMatrix containing normal distribution random values
  // given mean, double, rows and cols
  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  NCMatrix<T> random_normal(T mean, T stdev, int rows, int cols);

  template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  NCMatrix<T> operator*(T scalar, const NCMatrix<T>& NM);

}
#endif
