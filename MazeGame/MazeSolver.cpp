//
// Created by rathi on 11/16/2023.
//

#include "MazeSolver.h"
#include "playerdata.h"

#include <iostream>

using namespace std;

bool isSolveable()
{
    return maze[maze_size-1][maze_size-1] == '.';
}