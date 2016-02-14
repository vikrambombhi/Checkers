#include <iostream>
#include <vector>

using namespace std;

struct pos {
    int x;
    int y;
    int prob;
};

vector<pos> blueTeam;
vector<pos> redTeam;

void init_assignment(){
    //----------------------------BLUE TEAM----------------------------\\
    //Push back new chip created with default constructor.
    blueTeam.push_back(pos());
    //Vector now has 1 element @ index 0
    blueTeam[0].x = 1;
    blueTeam[0].y = 0;

    //Push back new chip created with default constructor.
    blueTeam.push_back(pos());
    //Vector now has 1 element @ index 1
    blueTeam[1].x = 3;
    blueTeam[1].y = 0;

    //Push back new chip created with default constructor.
    blueTeam.push_back(pos());
    //Vector now has 1 element @ index 2
    blueTeam[2].x = 2;
    blueTeam[2].y = 1;

    //Push back new chip created with default constructor.
    blueTeam.push_back(pos());
    //Vector now has 1 element @ index 3
    blueTeam[3].x = 1;
    blueTeam[3].y = 2;

    //-----------------------------RED TEAM----------------------------\\
    //Push back new chip created with default constructor.
    redTeam.push_back(pos());
    //Vector now has 1 element @ index 0
    redTeam[0].x = 0;
    redTeam[0].y = 4;

    //Push back new chip created with default constructor.
    redTeam.push_back(pos());
    //Vector now has 1 element @ index 1
    redTeam[1].x = 2;
    redTeam[1].y = 4;

    //Push back new chip created with default constructor.
    redTeam.push_back(pos());
    //Vector now has 1 element @ index 2
    redTeam[2].x = 2;
    redTeam[2].y = 3;

    //Push back new chip created with default constructor.
    redTeam.push_back(pos());
    //Vector now has 1 element @ index 3
    redTeam[3].x = 3;
    redTeam[3].y = 3;
}

void threat_check(int b){
    for (int j = 0; j < 4; j++) {
        //Check bottom left
        if ((blueTeam[b].x == redTeam[j].x + 1) && (blueTeam[b].y == redTeam[j].y - 1)) {
            cout << "left";
            cout << endl;
            cout << "original x,y coordinates:" << blueTeam[b].x << blueTeam[b].y;
            cout << endl;
        }
        //Check bottom right
        if ((blueTeam[b].x == redTeam[j].x - 1) && (blueTeam[b].y == redTeam[j].y - 1)) {
            cout << "right";
            cout << endl;
            cout << "original x,y coordinates:" << blueTeam[b].x << blueTeam[b].y;
            cout << endl;
        }
    }
}

int func(int x, int y, int val){
    if(virtualBoard[x,y] == 2){
        func(x+1, y+1, val+1);
        func(x-1, y+1, val+1);
    }
    if(virtualBoard[x,y] == 1){
        func(x+1, y+1, val+1);
        func(x-1, y+1, val+1);
    }
    if(virtualBoard[x,y] == 0){
        if((virtualBoard[x+1,y+1]) == 1 || (virtualBoard[x-1,y+1])){
            val -= 1;
        }
    }
    if((x>8) || (y>8)){
        return val+10;
    }
}


void move_check(){
    for(int b=0;b<4;b++){
        blueTeam[b].prob = 0;
        func(blueTeam[b].x, blueTeam[b].y, blueTeam[b].prob);
    }
}

int main(){
    init_assignment();
    move_check();
}