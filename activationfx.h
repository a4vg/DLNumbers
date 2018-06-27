#include <iostream>
#include "CNumpy.cpp"

template<class T>
using PTRFX = T(*)(T);

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class activationFX
{
public:
  activationFX(PTRFX<T> afx) : activation_function(afx){}
  activationFX() : activation_function(){}
  NumpyMatrix<T> operator()(NumpyMatrix<T> M){
    int *rows = new int(M.rows());
    int *cols = new int(M.cols());
    NumpyMatrix<T> R(*rows, *cols);
    for(int row = 0; row<*rows; ++row){
      for(int col = 0; col<*cols; ++col){
        R.init[row][col] = activation_function(M.init[row][col]);
      }
    }
    delete rows;
    delete cols;
    return R;
  }
  activationFX& operator=(const activationFX& other){
      activation_function = other.activation_function;
      return *this;
  }
  void setfx(PTRFX<T> afx){
      this->activation_function = afx;
  }
private:
  PTRFX<T> activation_function;
};




/* BIBLIOGRAPHY
1. https://stackoverflow.com/questions/29265451/how-to-typedef-a-function-pointer-with-template-arguments
2. https://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html
3. http://www.learncpp.com/cpp-tutorial/9-14-overloading-the-assignment-operator/
*/
