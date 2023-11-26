//
// Created by rathi on 11/15/2023.
//

#include "MazeGenerator.h"
#include "RandomNumberGenerator.h"

using namespace std;
vector<pair<int,int>> moveset = {{-1,0},{1,0},{0,1},{0,-1}};

bool IsValid(const pair<int,int> &coor) {
    return coor.first >= 0 && coor.second < maze_size && coor.first < maze_size && coor.second >= 0;
}

void backtracker(const pair<int,int> &source, bool visited[20][20])
{
    RandomIndex random_chance(0,3);
    const int x=source.first,y=source.second;
    visited[x][y] = true;
    for(auto i : moveset) {
        int n_x = x + i.first;int n_y = y+i.second;
        if ((IsValid({n_x, n_y}) && !visited[n_x][n_y])) {
            visited[n_x][n_y] = true;
            if (random_chance() != 3) {
                maze[n_x][n_y] = '.';
                backtracker({n_x, n_y}, visited);
            }
        }
    }
}