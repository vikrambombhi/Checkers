#include <iostream>
#include <vector>

using namespace std;

struct pos_t{
    int x;
    int y;
};

struct prob_counter{
    int left;
    int right;
}lvl_zero,lvl_one, lvl_two;

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

void threat_check(int lvl){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            //Check left
            if ((bteam[i].x + lvl == rteam[j].x + 1) && (bteam[i].y + lvl == rteam[j].y - 1)) {
                cout << "left";
                cout << endl;
                cout << "original x,y coordinates:" << bteam[i].x << bteam[i].y;
                cout << endl;
                cout << "leveled x,y coordinates:" << bteam[i].x + lvl << bteam[i].y + lvl;
                cout << endl;
                if(lvl == 0){
                    lvl_zero.left += 1;
                }
                if(lvl == 1){
                    lvl_one.left += 1;
                }
                if(lvl == 2){
                    lvl_two.left += 1;
                }
            }
            //Check right
            if ((bteam[i].x + lvl == rteam[j].x - 1) && (bteam[i].y + lvl == rteam[j].y - 1)) {
                cout << "right";
                cout << endl;
                cout << "original x,y coordinates:" << bteam[i].x << bteam[i].y;
                cout << endl;
                cout << "leveled x,y coordinates:" << bteam[i].x + lvl << bteam[i].y + lvl;
                cout << endl;
                if(lvl == 0){
                    lvl_zero.right += 1;
                }
                if(lvl == 1){
                    lvl_one.right += 1;
                }
                if(lvl == 2){
                    lvl_two.right += 1;
                }
            }
        }
    }
}

int main() {
    init_assignment();
    for(int lvl=0;lvl<2;lvl++) {
        threat_check(lvl);
    }
}