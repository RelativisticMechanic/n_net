#include "neuron.h"
#include "sigmoid.h"

NeuralNetwork::NeuralNetwork(unsigned int n_i, unsigned int n_h, unsigned int l_h, unsigned int n_o) {
	this->inputs.neurons = calloc(n_i, sizeof(Neuron));
	this->inputs.n = n_i;
	
	this->hidden_layers = calloc(n_h, sizeof(NeuralLayer));
	for(int i = 0; i < n_h; i++) {
		this->hidden_layers[i].neurons = calloc(l_h, sizeof(Neuron));
		this->hidden_layers[i].n = l_h;
	}
	this->output = calloc(n_o, sizeof(Neuron));
	
	// Allocate weights to the neurons
	// The first hidden layer shall have weights for the input layer
	for(int i = 0; i < l_h; i++) {
		this->hidden_layers[0].neurons[i].weights = calloc(n_i, sizeof(double));
		this->hidden_layers[i].neurons[j].n = n_i;
	}
	// Now the rest of the hidden layers will have l_h number of weights
	for(int i = 1; i < n_h; i++) {
		for(int j = 0; j < l_h; j++) {
			this->hidden_layers[i].neurons[j].weights = calloc(l_h, sizeof(double));
			this->hidden_layers[i].neurons[j].n = l_h;
		}
	}
	// And the output layer will also have the same weights as the hidden layers
	for(int i = 0; i < n_o; i++) {
		this->output.neurons[i].weights = calloc(l_h, sizeof(double));
		this->output.neurons[i].n = l_h;
	}
	this->n = n_h; // Number of hidden layers
	this->l_h = l_h;
	this->n_inputs = n_i;
	this->n_outputs = n_o;
}
void NeuralNetwork::Randomize(void) {
	// Randomize the network for training
	for(int i = 0; i < this->n; i++) {
		for(int j = 0; j < this->l_h; i++) {
			int n_weights = l_h;
			if(i == 0)
				// This is the layer that receives input
				n_weights = this->n_inputs;
			for(int k = 0; k < n_weights; k++) {
				this->hidden_layers[i].neurons[j].weights[k] = frand();
			}
		}
	}
	for(int i = 0; i < this->n_outputs; i++)
		for(int j = 0; j < this-> l_h; j++)
			this->output.neurons[i].weights[j] = frand();
}

void NeuralNetwork::NetworkSetProcess(NN_PROCESS process_func) {
	this->process_func = process_func;
}

void NeuralNetwork::NetworkProcess(double* inputs) {
	for(int i = 0; i < this->n_inputs; i++) {
		this->inputs[i] = inputs[i];
	}
	this->process_func(this);
}

void NeuralNetwork::NetworkBufferOutput(double* output) {
	for(int i = 0; i < this->n_outputs; i++) {
		output[i] = this->output.neurons[i].value;
	}
}
