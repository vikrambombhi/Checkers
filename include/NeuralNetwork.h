#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include <vector>

class NeuralNetwork
{
    public:
        NeuralNetwork();
        ~NeuralNetwork();
        bool createNode();
        bool readFile();
        bool writeToFile(int winORlost, int turnsCount);
        bool mind();

        float BLOCK = 75;
        float KILL_PIECE = 500;
        float OUT_OF_BOUND = -99999999;
    protected:

    private:
        struct columns{
            float block;
            float kill_piece;
            int winORlost;
            int turnsCount;
        };

        std::vector<columns> nodes;
};

#endif // NEURALNETWORK_H
