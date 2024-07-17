#pragma once
#include <vector>
#include <random>

namespace NN {
	class NeuralNetwork
	{
	public:
		NeuralNetwork();
		~NeuralNetwork();

	private:
		struct Neuron
		{
			float value = 0.0f;
			float bias = 0.0f;

			Neuron();
			Neuron(float value);
		};
		struct Layer
		{
			std::vector<Neuron> inputs;
			std::vector<Neuron> neurons;
			std::vector<float> weights;

			Layer(Layer& layer, int neuron_amount);
			Layer(const std::vector<float>& inputs, int neuron_amount);
			~Layer();
			void PrintInputs();
			void PrintNeurons();
			void PrintWeights();
			void GenerateRandomWeights(int size = 0);
			void operator>>(Layer& layer);
			void calculate();
		};
	};
}