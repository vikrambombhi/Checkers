#include "NeuralNetwork.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <fstream>
#include <iostream>
#include <typeinfo>

using namespace std;

NeuralNetwork::NeuralNetwork()
{
    //ctor
}

NeuralNetwork::~NeuralNetwork()
{
    //dtor
}

bool NeuralNetwork::createNode(){
    /* initialize random seed: */
    srand (time(NULL));
    float randomNum = rand() % 101;
    int randomSign = rand() % 7;
    int selectChange = rand() % 4;
    if(randomSign%2 == 0){
        randomNum = randomNum*-1;
    }
    if(selectChange == 1 || selectChange == 3){
        BLOCK += randomNum;
    }
    if(selectChange == 2 || selectChange == 3){
        KILL_PIECE += randomNum;
    }
    cout<<BLOCK<<KILL_PIECE<<endl;
    return true;
}

bool NeuralNetwork::readFile(){
    ifstream data("data.txt"); //load file named data.txt
    {
        string first_line;
        getline(data, first_line); // waste the first line ("pointSystem winORlost turnsCount")
    }

    while( data.good() )
    {
        columns temp;
        data >> temp.block >> temp.kill_piece >> temp.winORlost >> temp.turnsCount;
        nodes.push_back(temp);
    }

    //this is for testing purposes
    for (int i = 0; i < nodes.size()-1; ++i){
        cout<<"node:    "<<i<<endl;
        cout << "block points: " << nodes[i].block << " type: " << typeid(nodes[i].block).name() << endl;
        cout << "kill points: " << nodes[i].kill_piece << " type: " << typeid(nodes[i].kill_piece).name() << endl;
        cout << "win or lost: " << nodes[i].winORlost << " type: " << typeid(nodes[i].winORlost).name() << endl;
        cout << "turns Count: " << nodes[i].turnsCount << " type: " << typeid(nodes[i].turnsCount).name() << endl;
    }
    return true;
}

bool NeuralNetwork::writeToFile(int winORlost, int turnsCount){
    //write to file
    ofstream myfile ("data.txt", ios::app);
    if (myfile.is_open()){

        myfile <<BLOCK<<" "<<KILL_PIECE<<" "<<winORlost<<" "<<turnsCount<<endl;
        myfile.close();
        return true;
    }
    else cout << "Unable to open file";
    return false;
}

bool NeuralNetwork::mind(){
    int winORlost = 2;
    int turnsCount = 11;
    //writeToFile(winORlost, turnsCount);
    //readFile();
    createNode();
}
