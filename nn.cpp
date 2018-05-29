#include <iostream>
#include <cmath> // to use round and pow
#include <random>
#include <vector>
#include <exception>
#include <type_traits>
#include "CNumpy.cpp"


template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
struct Tstruct{typedef T (*PTRFN)(T);};


template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T fastsigmoid(T x){
  return (x/(1+abs(x)));
}

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T sigmoid(T x){
  return(1/(1+exp(-x)));
}

class neuralNetwork{
private:
  double inodes;
  double hnodes;
  double onodes;
  double lr;
  NumpyMatrix<double> wih;
  NumpyMatrix<double> who;
public:
  Tstruct<double>::PTRFN activation_function;
  neuralNetwork(double inputnodes, double hiddennodes, double outputnodes, double learningrate);
  void train(std::vector<double>inputs, std::vector<double>targets);
};


neuralNetwork::neuralNetwork(double inputnodes, double hiddennodes, double outputnodes, double learningrate){
  // number of nodes
  this->inodes = inputnodes;
  this->hnodes = hiddennodes;
  this->onodes = outputnodes;
  this->lr = learningrate;
  //this->activation_function = [](double x) {return (x/(1+abs(x)));};
  this->activation_function = &::fastsigmoid<double>;

  // Initalizing weights of inputs with normal distribution
  this->wih = random_normal(0.0, pow(inputnodes, -0.5), hiddennodes, inputnodes);
  this->who = random_normal(0.0, pow(hiddennodes, -0.5), outputnodes, hiddennodes);
}

void neuralNetwork::train(std::vector<double>inputs, std::vector<double>targets){
  // codigo feazo pero funcional :^(
  NumpyMatrix<double> inputsM;
  std::vector<std::vector<double>> tempi;
  tempi[0]=inputs;
  inputsM.init = tempi;
  inputsM = inputsM.Transpose();

  NumpyMatrix<double> targetsM  ;
  std::vector<std::vector<double>> tempt;
  tempt[0]=targets;
  targetsM.init = tempt;
  targetsM = targetsM.Transpose();

  NumpyMatrix<double> hidden_inputs = this->wih * inputsM;
  // *******

  NumpyMatrix<double> hidden_outputs;
  int rows = hidden_inputs.init.size();
  int cols = (hidden_inputs.init)[0].size();
  hidden_outputs.full(rows, cols, 0);

  for(int row=0; row<rows; row++){
    for(int col=0; col<cols; col++){
      hidden_outputs.init[row][col] =(this->activation_function)(hidden_inputs.init[row][col]);
    }
  }
  // ********
  // idea: overloading the operator () -> simplicity
  // python: hidden_outputs = self.activation_function(hidden_inputs)
  NumpyMatrix<double> final_inputs = this->who * hidden_outputs;
  NumpyMatrix<double> final_outputs;
  int rows2 = hidden_inputs.init.size();
  int cols2 = (hidden_inputs.init)[0].size();
  final_outputs.full(rows2, cols2, 0);
  for(int row=0; row<rows; row++){
    for(int col=0; col<cols; col++){
      final_outputs.init[row][col] =(this->activation_function)(final_inputs.init[row][col]);
    }
  }
  NumpyMatrix<double> output_errors = targetsM - final_outputs;

  NumpyMatrix<double> hidden_errors = ((this->who).Transpose())*output_errors;
  (this->who) += dot((output_errors * final_outputs * (NMfull(final_outputs.rows(), final_outputs.cols(), 1.0) - final_outputs)), hidden_outputs.Transpose()) * (this->lr);

}

int main(int argc, char const *argv[]) {
  /*
  NumpyMatrix<int> A(3,3, 1);
  NumpyMatrix<int> B(3,3, 2);
  NumpyMatrix<int> C;
  */
  NumpyMatrix<int> A(3,3, 1);
  NumpyMatrix<int> B(3,3, 2);
  NumpyMatrix<int> C;

  std::cout << A;
  return 0;
}
