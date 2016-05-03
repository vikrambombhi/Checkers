#ifndef AI_H
#define AI_H

#include "../include/Player.h"
#include "../include/CheckersBoard.h"

class AI : public Player
{
public:
    AI(bool, CheckersBoard*, Button*);
    ~AI();
    bool makeMove(SDL_Event *);
private:
    // New AI Stuff
    int findMax(int,int);
    int findMin(int,int);
    int maxValue(CheckersBoard tempBoard, vector<Piece> teamCopy, vector<Piece> enemyTeamCopy, int depth, Directions direction, int value);
    int minValue(CheckersBoard tempBoard, vector<Piece> teamCopy, vector<Piece> enemyTeamCopy, int depth, Directions direction, int value);
    int minMove(CheckersBoard tempBoard, vector<Piece> teamCopy, vector<Piece> enemyTeamCopy, int depth, Directions direction, int value);
    bool checkNode(CheckersBoard& tempBoard, vector<Piece>& teamCopy, vector<Piece>& enemyTeamCopy, Directions direction, bool enemy);
    int valueCalculator(vector<Piece>& teamCopy, vector<Piece>&);
    
    void updateTeam(CheckersBoard& tempBoard, vector<Piece>& teamCopy, bool enemy);
    
    void updateKings(CheckersBoard& tempBoard, vector<Piece>& teamCopy, bool enemy);
    
    // Old AI stuff
    void getEnemyTeam();
    bool changeWithDirection(int*,int*,Directions, bool);
    bool killCheckArea(int,int,Directions, bool);
    int bestPiece(vector<Piece>);
    
    const int OUT_OF_BOUND = -99999999;
    // Temp max depth value:
    const int MAX_DEPTH = 3;

    // Used for finding min values
    vector<Piece> enemyTeam;
    int enemyCurrentIndex;
};

#endif // AI_H
