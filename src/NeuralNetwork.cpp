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
    srand (static_cast<unsigned int>(time(NULL)));
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
    return true;
}

bool NeuralNetwork::readFile(){
    ifstream data("data.txt"); //load file named data.txt
    {
        string first_line;
        getline(data, first_line); // waste the first line ("BLOCK KILL_PIECE wins turnsCount")
    }

    while( data.good() )
    {
        node temp;
        data >> temp.block >> temp.kill_piece >> temp.wins >> temp.losses >> temp.turnsCount;
        nodes.push_back(temp);
    }

    //this is for testing purposes
    for (int i = 0; i < nodes.size()-1; ++i){
        cout<<"node:    "<<i<<endl;
        cout << "block points: " << nodes[i].block << " type: " << typeid(nodes[i].block).name() << endl;
        cout << "kill points: " << nodes[i].kill_piece << " type: " << typeid(nodes[i].kill_piece).name() << endl;
        cout << "number of wins: " << nodes[i].wins << " type: " << typeid(nodes[i].wins).name() << endl;
        cout << "number of losses: " << nodes[i].losses << " type: " << typeid(nodes[i].losses).name() << endl;
        cout << "turns Count: " << nodes[i].turnsCount << " type: " << typeid(nodes[i].turnsCount).name() << endl;
    }
    return true;
}

bool NeuralNetwork::writeToFile(int wins,int losses, int turnsCount){
    //write to file
    ofstream myfile ("data.txt", ios::app);
    if (myfile.is_open()){

        myfile <<BLOCK<<" "<<KILL_PIECE<<" "<<wins<<" "<<losses<<" "<<turnsCount<<endl;
        myfile.close();
        return true;
    }
    else cout << "Unable to open file";
    return false;
}

float NeuralNetwork::kdRatio(int index){
    if(nodes[index].losses == 0){
        return nodes[index].wins;
    }
    else{
        return (nodes[index].wins/nodes[index].losses);
    }
}

void NeuralNetwork::selectNode(){
    int bestNode = 0;
    for(int i=0; i<nodes.size()-1;i++){
        if(kdRatio(i)>kdRatio(bestNode)){
            bestNode = i;
        }
    }
    cout << nodes[bestNode].losses << endl;
}

bool NeuralNetwork::mind(){
    int wins = 2;
    int losses = 3;
    int turnsCount = 11;
    createNode();
<<<<<<< HEAD
    writeToFile(wins, losses, turnsCount);
    readFile();
    selectNode();
=======
    
    
    // temporary return to ensure build isnt broken
    return true;
>>>>>>> d5f228876c72697be961cc24e01a81dc8d21fcc7
}
