//
// Created by rathi on 11/13/2023.
//

#include "input_parser.h"
#include <iostream>
#include <string>
#include <utility>
#include "playerdata.h"

using namespace std;

int c_x,c_y;
int msize;

bool go_up()
{
    c_x-=1;
    return c_x>=0 && (maze[c_x][c_y] == '.');
}

bool go_down()
{
    c_x+=1;
    return c_x<msize && (maze[c_x][c_y] == '.');
}

bool go_right()
{
    c_y+=1;
    return c_y<msize && (maze[c_x][c_y] == '.');
}

bool go_left()
{
    c_y-=1;
    return c_y>=0&& (maze[c_x][c_y] == '.');
}

bool cases(const char s)
{
    switch (s)
    {
        case 'u':
            return go_up();
        case 'd':
            return go_down();
        case 'r':
            return go_right();
        case 'l':
            return go_left();

        default:
            return false;
    }
}
pair<int,int> parser(string s)
{
    c_x = x, c_y = y;
    msize = maze_size;
    while(!s.empty())
    {
        if(s[0]>=48 && s[0]<=57)
        {
            for(size_t i = 48;i<s[0];i++)
            {
                if(!cases(s[1]))return{-1,-1};
            }
            s.erase(0,2);
            continue;
        }

        if(!cases(s[0]))
        {
            return{-1,-1};
        }
        s.erase(0,1);
    }
    return {c_x,c_y};
}