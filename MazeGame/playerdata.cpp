//
// Created by rathi on 11/13/2023.
//

#include "playerdata.h"

int x = 0,y = 0;
const int maze_size = 20; // or whatever size you need
char maze[20][maze_size];

void fillmaze() {
    for(int i = 0;i<20;i++)
    {
        for(int j = 0;j<20;j++)
        {
            maze[i][j] = '#';
        }
    }
}