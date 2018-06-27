#include "headers.h"
# include <chrono>
using  ns = std::chrono::nanoseconds;
using get_time = std::chrono::steady_clock ;


template<class T>
using PTRFX = T(*)(T);


template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T fastsigmoid(T x){
  return (x/(1+abs(x)));
}
template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T sum1(T x){
  return (x+1);
}

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T sigmoid(T x){
  return(1/(1+exp(-x)));
}

class neuralNetwork{
private:
  int inodes;
  int hnodes;
  int onodes;
  double lr;
public:
  NumpyMatrix<double> wih;
  NumpyMatrix<double> who;
  activationFX<double> activation_function;
  neuralNetwork(double inputnodes, double hiddennodes, double outputnodes, double learningrate);
  void train(std::vector<double>inputs, std::vector<double>targets_list);
  NumpyMatrix<double> query(std::vector<double>inputs_list);

};

neuralNetwork::neuralNetwork(double inputnodes, double hiddennodes, double outputnodes, double learningrate){
    this->inodes = inputnodes;
    this->hnodes = hiddennodes;
    this->onodes = outputnodes;
    this->lr = learningrate;
    (this->activation_function).setfx(&::sigmoid<double>);
    this->wih = random_normal(0.0, pow(hiddennodes, -0.5), hiddennodes, inputnodes);
    this->who = random_normal(0.0, pow(outputnodes, -0.5), outputnodes, hiddennodes);
}

void neuralNetwork::train(std::vector<double>inputs_list, std::vector<double>targets_list){
    NumpyMatrix<double> inputs(inputs_list);
    NumpyMatrix<double> targets(targets_list);
    NumpyMatrix<double> hidden_inputs = dot(this->wih,inputs);
    NumpyMatrix<double> hidden_outputs = activation_function(hidden_inputs);
    NumpyMatrix<double> final_inputs = dot(this->who, hidden_outputs);
    NumpyMatrix<double> final_outputs = activation_function(final_inputs);
    NumpyMatrix<double> output_errors = targets - final_outputs;
    NumpyMatrix<double> hidden_errors = dot(((this->who).Transpose()),output_errors);
    (this->who) += dot((output_errors * final_outputs * (NMfull(final_outputs.rows(), final_outputs.cols(), 1.0) - final_outputs)), hidden_outputs.Transpose()) * (this->lr);
    (this->wih) += dot(((hidden_errors * hidden_outputs) * (NMfull(hidden_outputs.rows(), hidden_outputs.cols(), 1.0) - hidden_outputs)), inputs.Transpose()) * (this->lr);

}

NumpyMatrix<double> neuralNetwork::query(std::vector<double>inputs_list){
    NumpyMatrix<double> inputs(inputs_list);
    NumpyMatrix<double> hidden_inputs = dot(this->wih,inputs);
    NumpyMatrix<double> hidden_outputs = activation_function(hidden_inputs);
    NumpyMatrix<double> final_inputs = dot(this->who, hidden_outputs);
    NumpyMatrix<double> final_outputs = activation_function(final_inputs);
    return final_outputs;
}
int main(int argc, char const *argv[]) {
  int input_nodes = 784;
  int hidden_nodes = 100;
  int output_nodes = 10;

  double learning_rate = 0.3;

  neuralNetwork NN(input_nodes, hidden_nodes, output_nodes, learning_rate);

  //NN.wih.print();
  //std::vector<std::vector<double>> datatest = parse2DCsvFile("mnist_test.csv");
  // DESCOMPRIMIR mnist_train.csv
  std::vector<std::vector<double>> datatrain = parse2DCsvFile("mnist_train.csv");

  std::vector<double> outputs;
  int rows = datatrain.size();
  int cols = datatrain[0].size();

  for(int row=0; row<rows; row++){
    outputs.push_back(datatrain[row][0]);
  }

  for(int row=0; row<rows; row++){
    std::vector<double> targets(output_nodes, 0.1);

    targets[int(datatrain[row][0])-1] = 0.99;

    std::vector<double> inputs;
    for(int col=1; col<cols; col++){
      inputs.push_back(((double(datatrain[row][col])/255.0)*0.99)+0.01);
    }

    NN.train(inputs, targets);
    inputs = {};
    outputs = {};
    std::cout<<"Iteration "<< row << " complete."<<std::endl;
  }

  std::vector<double> inputs;
  for(int col=1; col<cols; col++){
      inputs.push_back(((double(datatrain[0][col])/255.0)*0.99)+0.01);
  }
  std::cout<<NN.query(inputs)<<std::endl;
  std::cout<<datatrain[0][0]<<std::endl;
  // TODO: Implementar query loop
  return 0;
}
