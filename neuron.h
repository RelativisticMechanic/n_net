/// The basic structure of a neuron
#ifndef NEURON_H
#define NEURON_H

typedef void (*)(NeuralNetwork*) NN_PROCESS;

typedef struct {
	double value;
	double* weights; // Weight given to the neurons coming from the previous layer
	unsigned int n;
	double bias;
} Neuron;

class NeuralLayer {
public:
	// Defines a layer of neurons
	Neuron* neurons; // Neurons in this layer
	unsigned int n; // Number of neurons
};

class NeuralNetwork {
public:
	// Arguments
	// Number of inputs, number of hidden layers, length of each hidden layer
	// number of outputs
	NeuralNetwork(unsigned int n_i, unsigned int n_h, unsigned int l_h, unsigned int n_o);
	
	NeuralLayer inputs;
	NeuralLayer* hidden_layers;
	NeuralLayer output;
	
	unsigned int n; // Number of layers
	unsigned int l_h; // Length of hidden layer
	unsigned int n_inputs;
	unsigned int n_outputs;
	
	void NetworkSetProcess(NN_PROCESS process_function);
	// Process the inputs from a NeuralLayer
	void NetworkProcess(double* inputs);
	// Get output from network
	void NetworkBufferOutput(double* output);
private:
	NN_PROCESS process_func;
};
#endif
