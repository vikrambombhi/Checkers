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
        bool writeToFile(int wins, int losses, int turnsCount);
        float kdRatio(int index);
        void selectNode();
        bool mind();

        float BLOCK = 75;
        float KILL_PIECE = 500;
        float OUT_OF_BOUND = -99999999;
    protected:

    private:
        struct node{
            double block;
            double kill_piece;
            int wins;
            int losses;
            int turnsCount;
        };

        std::vector<node> nodes;
};

#endif // NEURALNETWORK_H
