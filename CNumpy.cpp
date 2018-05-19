#include <iostream>
#include <cmath> // to use round and pow
#include <random>
#include <vector>
#include <exception>
#include <type_traits>


class MatrixRangeError: public std::exception{
  virtual const char* what()const throw(){
    return "Error: check compatibility between rows and columns of both matrices";
  }
}mre;


template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class NumpyMatrix{
public:
  std::vector<std::vector<T>> init;
  void print(){
    int mrows = (this->init).size();
    int mcols = (this->init)[0].size();
    for(int row = 0; row < mrows; row++){
      for(int col = 0; col < mcols; col++){
        std::cout<<(this->init)[row][col] << " ";
      }
      std::cout<<"\n";
    }
  }
  void full(int rows, int cols, T number){
    std::vector<std::vector<T>> temp(rows, std::vector<T>(cols, number));
    this->init = temp;
  }
  T rows(){
    return((this->init).size());
  }
  T cols(){
    return((this->init)[0].size());
  }
  NumpyMatrix operator*(const NumpyMatrix& M2){
    int M1rows = (this->init).size();
    int M1columns = (this->init)[0].size();

    int M2rows = (M2.init).size();
    int M2columns = (M2.init)[0].size();

    std::vector<std::vector<T>> temp(M1rows, std::vector<T>(M2columns));
    NumpyMatrix<T> Result;
    Result.init = temp;

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
  NumpyMatrix operator-(const NumpyMatrix& M2){
    int M1rows = (this->init).size();
    int M1columns = (this->init)[0].size();

    int M2rows = (M2.init).size();
    int M2columns = (M2.init)[0].size();

    std::vector<std::vector<T>> temp(M1rows, std::vector<T>(M2columns));
    NumpyMatrix<T> Result;
    Result.init = temp;

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
  NumpyMatrix operator*(T scalar){
    int Mrows = (this->init).size();
    int Mcolumns = (this->init)[0].size();
    std::vector<std::vector<T>> temp(Mrows, std::vector<T>(Mcolumns));
    NumpyMatrix<T> Result;
    Result.init = temp;

    for(int row = 0; row < Mrows; row++){
      for(int col = 0; col < Mcolumns; col++){
        (Result.init)[row][col] = (this->init)[row][col]*scalar;
      }
    }

    return Result;
  }
  /*
  NumpyMatrix operator+=(NumpyMatrix M2){
  }
*/
  NumpyMatrix dot(const NumpyMatrix& M1, const NumpyMatrix& M2){
    int M1rows = (M1.init).size();
    int M1columns = (M1.init)[0].size();

    int M2rows = (M2.init).size();
    int M2columns = (M2.init)[0].size();

    std::vector<std::vector<T>> temp(M1rows, std::vector<T>(M2columns));
    NumpyMatrix<T> Result;
    Result.init = temp;

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
  NumpyMatrix Transpose(){
    int Mrows = (this->init).size();
    int Mcolumns = (this->init)[0].size();
    std::vector<std::vector<T>> temp(Mcolumns, std::vector<T>(Mrows));
    NumpyMatrix<T> Result;
    Result.init = temp;

    for(int row = 0; row < Mrows; row++){
      for(int col = 0; col < Mcolumns; col++){
        (Result.init)[row][col] = (this->init)[col][row];
      }
    }
    return Result;
  }
};
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NumpyMatrix<T> dot(const NumpyMatrix<T>& M1, const NumpyMatrix<T>& M2){
  int M1rows = (M1.init).size();
  int M1columns = (M1.init)[0].size();

  int M2rows = (M2.init).size();
  int M2columns = (M2.init)[0].size();

  std::vector<std::vector<T>> temp(M1rows, std::vector<T>(M2columns));
  NumpyMatrix<T> Result;
  Result.init = temp;

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
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
std::ostream& operator<<(std::ostream& os, const NumpyMatrix<T>& NM){
  int mrows = (NM.init).size();
  int mcols = (NM.init)[0].size();
  for(int row = 0; row < mrows; row++){
    for(int col = 0; col < mcols; col++){
      os<<(NM.init)[row][col] << " ";
    }
    os<<"\n";
  }
  return os;
}

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NumpyMatrix<T> random_normal(T mean, double stdev, int rows, int cols){
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

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
NumpyMatrix<T> NMfull(T rows, T cols, T number){
  std::vector<std::vector<T>> temp(rows, std::vector<T>(cols, number));
  NumpyMatrix<T> Result;
  Result.init = temp;
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
