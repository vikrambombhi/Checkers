#include <iostream>
#include <vector>

using namespace std;

struct pos_t{
    int x;
    int y;
    int prob;
};

vector<pos_t> bteam;
vector<pos_t> rteam;

void init_assignment(){
    //----------------------------BLUE TEAM----------------------------\\
    //Push back new chip created with default constructor.
    bteam.push_back(pos_t());
    //Vector now has 1 element @ index 0
    bteam[0].x = 1;
    bteam[0].y = 0;

    //Push back new chip created with default constructor.
    bteam.push_back(pos_t());
    //Vector now has 1 element @ index 1
    bteam[1].x = 3;
    bteam[1].y = 0;

    //Push back new chip created with default constructor.
    bteam.push_back(pos_t());
    //Vector now has 1 element @ index 2
    bteam[2].x = 2;
    bteam[2].y = 1;

    //Push back new chip created with default constructor.
    bteam.push_back(pos_t());
    //Vector now has 1 element @ index 3
    bteam[3].x = 1;
    bteam[3].y = 2;

    //-----------------------------RED TEAM----------------------------\\
    //Push back new chip created with default constructor.
    rteam.push_back(pos_t());
    //Vector now has 1 element @ index 0
    rteam[0].x = 0;
    rteam[0].y = 4;

    //Push back new chip created with default constructor.
    rteam.push_back(pos_t());
    //Vector now has 1 element @ index 1
    rteam[1].x = 2;
    rteam[1].y = 4;

    //Push back new chip created with default constructor.
    rteam.push_back(pos_t());
    //Vector now has 1 element @ index 2
    rteam[2].x = 2;
    rteam[2].y = 3;

    //Push back new chip created with default constructor.
    rteam.push_back(pos_t());
    //Vector now has 1 element @ index 3
    rteam[3].x = 3;
    rteam[3].y = 3;
}

void threat_check(int b){
        for (int j = 0; j < 4; j++) {
            //Check bottom left
            if ((bteam[b].x == rteam[j].x + 1) && (bteam[b].y == rteam[j].y - 1)) {
                cout << "left";
                cout << endl;
                cout << "original x,y coordinates:" << bteam[b].x << bteam[b].y;
                cout << endl;
            }
            //Check bottom right
            if ((bteam[b].x == rteam[j].x - 1) && (bteam[b].y == rteam[j].y - 1)) {
                cout << "right";
                cout << endl;
                cout << "original x,y coordinates:" << bteam[b].x << bteam[b].y;
                cout << endl;
            }
        }
    }

void move_check(){
    for(int b=0;b<4;b++){
        threat_check(b);
    }
}

int main() {
    init_assignment();
    move_check();
}