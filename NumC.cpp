#include "NumC.h"
#include <iostream>
#include <cmath> // to use round and pow
#include <random>
#include <vector>
#include <exception>
#include <type_traits>
// Defining Error class

class MatrixRangeError: public std::exception{
  virtual const char* what()const throw(){
    return "Error: check compatibility between rows and columns of both matrices";
  }
}mre;

// ***************************** CONSTRUCTORS **********************************
template<typename T>
NCMatrix<T>::NCMatrix(){}

template<typename T>
NCMatrix<T>::NCMatrix(std::vector<std::vector<T>> vector){
  this->init = vector;
}

template<typename T>
NCMatrix<T>::NCMatrix(int rows, int cols){
  std::vector<std::vector<T>> temp(rows, std::vector<T>(cols));
  this->init = temp;
}

template<typename T>
NCMatrix<T>::NCMatrix(int rows, int cols, T number){
  std::vector<std::vector<T>> temp(rows, std::vector<T>(cols, number));
  this->init = temp;
}
// ************************ OPERATOR OVERLOADING ******************************

// SCALAR MULTIPLICATION
template<typename T>
NCMatrix<T> NCMatrix<T>::operator*(const T& scalar) const{
  int Mrows = this->rows();
  int Mcolumns = this->cols();
  NCMatrix<T> Result(Mrows, Mcolumns);

  for(int row = 0; row < Mrows; row++){
    for(int col = 0; col < Mcolumns; col++){
      (Result.init)[row][col] = (this->init)[row][col]*scalar;
    }
  }

  return Result;
}

template<typename T>
NCMatrix<T> NCMatrix<T>::operator*=(const T& scalar){
  int Mrows = this->rows();
  int Mcolumns = this->cols();

  for(int row = 0; row < Mrows; row++){
    for(int col = 0; col < Mcolumns; col++){
      (this->init)[row][col] *= (this->init)[row][col]*scalar;
    }
  }

  return *this;
}

// MATRIX DOT PRODUCT MULTIPLICATION
template<typename T>
NCMatrix<T> NCMatrix<T>::operator*(NCMatrix const &M2) const{
  int M1rows = this->rows();
  int M1columns = this->cols();

  int M2rows = M2.rows();
  int M2columns = M2.cols();

  // creates empty result matrix with m1rows as n rows and m2columns as n columns
  NCMatrix<T> Result(M1rows, M2columns);
  // Handles error if m1cols and m2rows don't match
  // I don't know much about errors and exceptions, fix it if it needs to
  try{
    if(M1columns == M2rows){
      int inner = M1columns;
      for(int row = 0; row < M1rows; row++){
        for(int col = 0; col < M2columns; col++){
          for(int i = 0; i < inner; i++){
            (Result.init)[row][col] += (this->init)[row][i] * (M2.init)[i][col];
          }
        }
      }
      return Result;
    }
    else{
      throw mre;
    }
  }
  catch(std::exception& e){
    std::cout << e.what() << std::endl;
  }
}

// MATRIX ADDITION AND SUBTRACTION

template<typename T>
NCMatrix<T> NCMatrix<T>::operator+(const NCMatrix& M2) const{
  int M1rows = this->rows();
  int M1columns = this->cols();

  int M2rows = M2.rows();
  int M2columns = M2.cols();

  NCMatrix<T> Result(M1rows, M2columns);

  try{
    if(M1rows == M2rows && M1columns == M2columns){
      for(int row = 0; row < M1rows; row++){
        for(int col = 0; col < M2columns; col++){
          Result.init[row][col] = (this->init)[row][col] + M2.init[row][col];
        }
      }
      return Result;
    }
    else{
      throw mre;
    }
  }
  catch(std::exception& e){
    std::cout << e.what() << std::endl;
  }
}

template<typename T>
NCMatrix<T> NCMatrix<T>::operator-(const NCMatrix& M2) const{
  int M1rows = this->rows();
  int M1columns = this->cols();

  int M2rows = M2.rows();
  int M2columns = M2.cols();

  NCMatrix<T> Result(M1rows, M2columns);

  try{
    if(M1rows == M2rows && M1columns == M2columns){
      for(int row = 0; row < M1rows; row++){
        for(int col = 0; col < M2columns; col++){
          Result.init[row][col] = (this->init)[row][col] - M2.init[row][col];
        }
      }
      return Result;
    }
    else{
      throw mre;
    }
  }
  catch(std::exception& e){
    std::cout << e.what() << std::endl;
  }
}

// MATRIX COMPOUND ASSIGNMENT
template<typename T>
NCMatrix<T>& NCMatrix<T>::operator+=(const NCMatrix<T>& M2){
  int Mrows = this->rows();
  int Mcols = this->cols();
  for(int row = 0; row < Mrows; row++){
      for(int col = 0; col < Mcols; col++){
          (this->init)[row][col] += M2.init[row][col];
      }
  }
  return *this;

}
template<typename T>
NCMatrix<T>& NCMatrix<T>::operator-=(const NCMatrix<T>& M2){
  int Mrows = this->rows();
  int Mcols = this->cols();
  for(int row = 0; row < Mrows; row++){
      for(int col = 0; col < Mcols; col++){
          (this->init)[row][col] -= M2.init[row][col];
      }
  }
  return *this;

}

// ************************ OTHER FUNCTIONS ******************************
template<typename T>
void NCMatrix<T>::print(){
  int mrows = this->rows();
  int mcols = this->cols();
  for(int row = 0; row < mrows; row++){
    for(int col = 0; col < mcols; col++){
      std::cout<<(this->init)[row][col] << " ";
    }
    std::cout<<"\n";
  }
}

// Fills current NCMatrix with given number

template<typename T>
void NCMatrix<T>::full(int rows, int cols, T number){
  std::vector<std::vector<T>> temp(rows, std::vector<T>(cols, number));
  this->init = temp;
}
// Returns number of rows of current matrix
template<typename T>
int NCMatrix<T>::rows() const{
  return((this->init).size());
}
// Returns number of columns of current matrix
template<typename T>
int NCMatrix<T>::cols() const{
  return((this->init)[0].size());
}

// Transposes current NCMatrix
template<typename T>
NCMatrix<T> NCMatrix<T>::Transpose(){
  int Mrows = this->rows();
  int Mcolumns = this->cols();
  NCMatrix<T> Result(Mcolumns, Mrows);

  for(int row = 0; row < Mrows; row++){
    for(int col = 0; col < Mcolumns; col++){
      (Result.init)[row][col] = (this->init)[col][row];
    }
  }
  return Result;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const NCMatrix<T>& NM){
  int mrows = NM.rows();
  int mcols = NM.cols();
  for(int row = 0; row < mrows; row++){
    for(int col = 0; col < mcols; col++){
      os<<(NM.init)[row][col] << " ";
    }
    os<<"\n";
  }
  return os;
}

template<typename T>
NCMatrix<T> operator*(T scalar, const NCMatrix<T>& NM){
  int Mrows = NM.rows();
  int Mcolumns = NM.cols();
  NCMatrix<T> Result(Mrows, Mcolumns);

  for(int row = 0; row < Mrows; row++){
    for(int col = 0; col < Mcolumns; col++){
      (Result.init)[row][col] = (NM.init)[row][col]*scalar;
    }
  }

  return Result;
}


namespace NumC{
  // outside function to deal with matrix multiplication
  template<typename T>
  NCMatrix<T> dot(const NCMatrix<T>& M1, const NCMatrix<T>& M2){
    int M1rows = M1.rows();
    int M1columns = M1.cols();

    int M2rows = M2.rows();
    int M2columns = M2.cols();

    // creates empty result matrix with m1rows as n rows and m2columns as n columns
    NCMatrix<T> Result(M1rows, M2columns);
    // Handles error if m1cols and m2rows don't match
    // I don't know much about errors and exceptions, fix it if it needs to
    try{
      if(M1columns == M2rows){
        int inner = M1columns;
        for(int row = 0; row < M1rows; row++){
          for(int col = 0; col < M2columns; col++){
            for(int i = 0; i < inner; i++){
              (Result.init)[row][col] += (M1.init)[row][i] * (M2.init)[i][col];
            }
          }
        }
        return Result;
      }
      else{
        throw mre;
      }
    }
    catch(std::exception& e){
      std::cout << e.what() << std::endl;
    }
  }
  // Overloads operator <<, simplifies matrix printing

  // Outside function that returns NCMatrix containing normal distribution random values
  // given mean, double, rows and cols
  template<typename T>
  NCMatrix<T> random_normal(T mean, T stdev, int rows, int cols){
  std::random_device rd{};
  std::mt19937 gen{rd()};
  NCMatrix<T> result;
  // Defining normal_distribution template with mean=0 and standard deviation=nodes^-0.5
  std::normal_distribution<> normal{mean, stdev};
  std::vector<std::vector<T>> temp(rows, std::vector<T>(cols));

  for(int row  = 0; row < rows; row++){
    for (int col = 0; col < cols; col++) {
        temp[row][col]=normal(gen);
    }
  }
  result.init=temp;
  return result;

  }
  // Outside function that returns filled NCMatrix given rows, cols and number
  template<typename T>
  NCMatrix<T> NMfull(int rows, int cols, T number){
    NCMatrix<T> Result(rows, cols, number);
    return Result;
  }

}
