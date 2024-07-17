#include "NeuralNetwork.h"
#include <iostream>

NN::NeuralNetwork::NeuralNetwork()
{
	std::cout << "NeuralNetwork created" << std::endl;
	std::vector<float> inputs = {0.5f, 0.1f, 1.0f};
	Layer layer = Layer(inputs, 3);
	layer.calculate();
	Layer layer2 = Layer(layer, 2);
	layer2.calculate();

	layer.PrintInputs();
	layer.PrintWeights();
	layer.PrintNeurons();
	layer2.PrintInputs();
	layer2.PrintWeights();
	layer2.PrintNeurons();
}

NN::NeuralNetwork::~NeuralNetwork()
{
	std::cout << "NeuralNetwork destroyed" << std::endl;
}

NN::NeuralNetwork::Layer::Layer(Layer& layer, int neurons_amount) 
{
	inputs = layer.neurons;

	neurons.reserve(neurons_amount);
	for (int i = 0; i < neurons_amount; i++)
		neurons.emplace_back(Neuron());

	GenerateRandomWeights(layer.inputs.size() * neurons_amount);
}

NN::NeuralNetwork::Layer::Layer(const std::vector<float>& _inputs, int neuron_amount)
{
	inputs.reserve(_inputs.size());
	for (Neuron neuron : _inputs)
		inputs.emplace_back(neuron);

	neurons.reserve(neuron_amount);
	for (int i = 0; i < neuron_amount; i++)
		neurons.emplace_back(Neuron());

	GenerateRandomWeights(inputs.size() * neurons.size());
}

NN::NeuralNetwork::Layer::~Layer()
{
	inputs.clear();
	neurons.clear();
	weights.clear();
}

void NN::NeuralNetwork::Layer::PrintInputs()
{
	std::cout << "[";
	bool first = true;
	for (Neuron neuron : inputs)
	{
		if(!first) std::cout << ", ";
		first = false;
		std::cout << neuron.value;
	}
	std::cout << "]\n";
}

void NN::NeuralNetwork::Layer::PrintNeurons()
{
	std::cout << "[";
	bool first = true;
	for (Neuron neuron : neurons)
	{
		if (!first) std::cout << ", ";
		first = false;
		std::cout << neuron.value;
	}
	std::cout << "]\n";
}

void NN::NeuralNetwork::Layer::PrintWeights() {
	std::cout << "[";
	bool first = true;
	for (float weight : weights)
	{
		if (!first) std::cout << ", ";
		first = false;
		std::cout << weight;
	}
	std::cout << "]\n";
}

void NN::NeuralNetwork::Layer::GenerateRandomWeights(int size)
{
	weights.reserve(size);
	std::random_device device;
	std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
	for (int i = 0; i < size; i++)
		weights.emplace_back(round(distribution(device) * 100) / 100);
}

void NN::NeuralNetwork::Layer::calculate()
{
	for (int neuron_index = 0; neuron_index < neurons.size(); neuron_index++)
	{
		float sum = neurons[neuron_index].bias;
		for (int input_index = 0; input_index < inputs.size(); input_index++)
			sum += inputs[input_index].value * weights[input_index + neuron_index * inputs.size()];
		neurons[neuron_index].value = sum;
	}
}

NN::NeuralNetwork::Neuron::Neuron()
{
	std::random_device device;
	std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
	this->value = round(distribution(device) * 100) / 100;
	this->bias = 0.0f;
}

NN::NeuralNetwork::Neuron::Neuron(float value)
{
	this->value = value;
	this->bias = 0.0f;
}