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

// Template allows only arithmetic types (float, double, int, etc) for typename T
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
/*
NumpyMatrix is simply a class containing a 2d vector which aim is
to simplify matrix operations.
*/
class NumpyMatrix{
public:
  // True Matrix
  std::vector<std::vector<T>> init;

  NumpyMatrix(){}
  NumpyMatrix(std::vector<std::vector<T>> vector){
    this->init = vector;
  }
  NumpyMatrix(T rows, T cols){
    std::vector<std::vector<T>> temp(rows, std::vector<T>(cols));
    this->init = temp;
  }
  NumpyMatrix(T rows, T cols, T number){
    std::vector<std::vector<T>> temp(rows, std::vector<T>(cols, number));
    this->init = temp;
  }
  // Just a print function obj.print()
  void print(){
    int mrows = this->rows();
    int mcols = this->cols();
    for(int row = 0; row < mrows; row++){
      for(int col = 0; col < mcols; col++){
        std::cout<<(this->init)[row][col] << " ";
      }
      std::cout<<"\n";
    }
  }
  // Fills current NumpyMatrix with given number
  void full(int rows, int cols, T number){
    std::vector<std::vector<T>> temp(rows, std::vector<T>(cols, number));
    this->init = temp;
  }
  // Returns number of rows of current matrix
  T rows(){
    return((this->init).size());
  }
  // Returns number of columns of current matrix
  T cols(){
    return((this->init)[0].size());
  }
  // Overloads operator* to simplify matrix multiplication
  NumpyMatrix operator*(const NumpyMatrix& M2){
    int M1rows = this->rows();
    int M1columns = this->cols();

    int M2rows = M2.rows();
    int M2columns = M2.cols();

    // creates empty result matrix with m1rows as n rows and m2columns as n columns
    NumpyMatrix<T> Result(M1rows, M2columns);
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

  // Overloads operator-
  NumpyMatrix operator-(const NumpyMatrix& M2){
    int M1rows = this->rows();
    int M1columns = this->cols();

    int M2rows = M2.rows();
    int M2columns = M2.cols();

    NumpyMatrix<T> Result(M1rows, M2columns);

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
  // Defines multiplication between Matrix and scalar
  NumpyMatrix operator*(T scalar){
    int Mrows = this->rows();
    int Mcolumns = this->cols();
    NumpyMatrix<T> Result(Mrows, Mcolumns);

    for(int row = 0; row < Mrows; row++){
      for(int col = 0; col < Mcolumns; col++){
        (Result.init)[row][col] = (this->init)[row][col]*scalar;
      }
    }

    return Result;
  }
  // Needs to be done
  /*
  NumpyMatrix operator+=(NumpyMatrix M2){
  }
*/
// Transposes current NumpyMatrix
  NumpyMatrix Transpose(){
    int Mrows = this->rows();
    int Mcolumns = this->cols();
    NumpyMatrix<T> Result(Mcolumns, Mrows);

    for(int row = 0; row < Mrows; row++){
      for(int col = 0; col < Mcolumns; col++){
        (Result.init)[row][col] = (this->init)[col][row];
      }
    }
    return Result;
  }
};
// outside function to deal with matrix multiplication
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NumpyMatrix<T> dot(const NumpyMatrix<T>& M1, const NumpyMatrix<T>& M2){
  int M1rows = M1.rows();
  int M1columns = M1.cols();

  int M2rows = M2.rows();
  int M2columns = M2.cols();

  // creates empty result matrix with m1rows as n rows and m2columns as n columns
  NumpyMatrix<T> Result(M1rows, M2columns);
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
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
std::ostream& operator<<(std::ostream& os, const NumpyMatrix<T>& NM){
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
// Outside function that returns NumpyMatrix containing normal distribution random values
// given mean, double, rows and cols
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NumpyMatrix<T> random_normal(T mean, T stdev, int rows, int cols){
  std::random_device rd{};
  std::mt19937 gen{rd()};
  NumpyMatrix<T> result;
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
// Outside function that returns filled NumpyMatrix given rows, cols and number
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NumpyMatrix<T> NMfull(T rows, T cols, T number){
  NumpyMatrix<T> Result(rows, cols, number);
  return Result;
}
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NumpyMatrix<T> operator*(T scalar, const NumpyMatrix<T>& NM){
  int Mrows = NM.rows();
  int Mcolumns = NM.cols();
  NumpyMatrix<T> Result(Mrows, Mcolumns);

  for(int row = 0; row < Mrows; row++){
    for(int col = 0; col < Mcolumns; col++){
      (Result.init)[row][col] = (NM.init)[row][col]*scalar;
    }
  }

  return Result;
}
/*
int main(int argc, char const *argv[]) {
  NumpyMatrix<int> M1;
  1<int> M2;
  NumpyMatrix<int> M3;
  M1.init={{1,1,1},{2,2,2}};
  M2.init={{1,1},{2,2},{3,3}};
  M3.init={{1,1},{2,2}};
  int inodes = 2;
  int hnodes = 2;

  std::cout<<random_normal(0.0, pow(inodes, -0.5), hnodes, inodes);

  std::cout << M1*M2*2;


  std::vector<std::vector<int>> Matrix1;
  std::vector<std::vector<int>> Matrix2;

  return 0;
}
*/
