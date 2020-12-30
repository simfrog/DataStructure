#include "Location2D.h"
#include <iostream>
#include <queue>
using namespace std;

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '0', '0'},
    {'1', '0', '1', '0', '1', 'x'},
    {'1', '1', '1', '1', '1', '1'}
};

bool isValidLoc(int r, int c) {
    if(r<0 || c<0 || r>=MAZE_SIZE || c>=MAZE_SIZE) { return false; }
    else { return map[r][c] == '0' || map[r][c] == 'x'; }
}

int main()
{
    queue<Location2D> locQueue;
    Location2D entry(1,0);
    locQueue.push(entry);

    while(locQueue.empty() == false) {
        Location2D here = locQueue.front();
        locQueue.pop();

        int r = here.row;
        int c = here.col;
        cout << "(" << r << "," << c << ") ";
        if(map[r][c] == 'x') {
            cout << "탈출에 성공했습니다.\n";
            return 0;
        } else {
            map[r][c] = '.';
            if(isValidLoc(r-1, c)) locQueue.push(Location2D(r-1,c));
            if(isValidLoc(r+1, c)) locQueue.push(Location2D(r+1,c));
            if(isValidLoc(r, c-1)) locQueue.push(Location2D(r,c-1));
            if(isValidLoc(r, c+1)) locQueue.push(Location2D(r,c+1));
        }
    }
    cout << "탈출에 실패했습니다.\n";
    return 0;
}