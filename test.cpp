#include <iostream>
#include "activationfx.h"

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T sum1(T x){
    return x+1;
}

int main(int argc, char const *argv[]) {
    NumpyMatrix<double> M1(2,2,1);
    activationFX<double> af(&::sum1<double>);
    std::cout << "Original Matrix: "<<std::endl<< M1;
    std::cout << "f(x) applied: "<< std::endl << af(M1);
    return 0;
}
