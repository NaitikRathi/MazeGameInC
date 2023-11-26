#include <iostream>
#include <windows.h>

#include "playerdata.h"
#include "input_parser.h"
#include "MazeGenerator.h"
#include "MazeSolver.h"

using namespace std;

void print() {
    for(size_t i = 0;i<maze_size;i++) {
        for(size_t j = 0;j<maze_size;j++) {
            if(i == x && j == y){cout<<"\033[94;1mp";}
            else if(maze[i][j] == '#'){cout<<"\033[91m"<<maze[i][j];}
            else{cout<<"\033[32m"<<maze[i][j];}
        }
        cout<<endl;
    }
}

void create_maze() {
    x = 0; y = 0;
    bool visited[20][20];

    for(auto & i : visited) {
        for(bool & j : i) {
            j = false;
        }
    }
    backtracker({0, 0}, visited);
}

void maze_opener() {
    fillmaze();
    create_maze();
    while(!isSolveable()) {
        fillmaze();
        create_maze();
    }
    print();
    cout<<"\033[97;1m";
}

void start_state() {
    cout<<"\033[33;1m_____________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"#\\ \\      / / | ____| | |  / ___|  / _ \\  |  \\/  | | ____|   |_   _|  / _ \\    |  \\/  |    / \\    |__ / | ____|    / ___|    / \\   |  \\/  | | ____| #"<<endl;
    cout<<"# \\ \\ /\\ / /  |  _|   | | | |     | | | | | |\\/| | |  _|       | |   | | | |   | |\\/| |   / _ \\    / /  |  _|     | |  _    / _ \\  | |\\/| | |  _|   #"<<endl;
    cout<<"#  \\ V  V /   | |___  | | | |___  | |_| | | |  | | | |___      | |   | |_| |   | |  | |  / ___ \\  / /_  | |___    | |_| |  / ___ \\ | |  | | | |___  #"<<endl;
    cout<<"#   \\_/\\_/    |_____| |_|  \\____|  \\___/  |_|  |_| |_____|     |_|    \\___/    |_|  |_| /_/   \\_\\/____| |_____|     ____| /_/   \\_\\|_|  |_| |_____| #"<<endl;
    cout<<"_____________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"Your Goal: Reach the rightmost corner of the maze."<<endl;
    cout<<"Controls: Move right: 'r', Move left: 'l', Move Up: 'u', Move Down: 'd'"<<endl;
    cout<<"You can remake the puzzle with 'rm' and you can exit the game with 'x'"<<endl;
    cout<<"You can pair the controls for ex- ldrru for left, down, 2 times right and up"<<endl;
    cout<<"You can even use numbers for ex- 2l for 2 times left"<<endl;
    cout<<"You may start the game."<<endl;
}

void end_state() {
    cout<<"You Reached the end"<<endl;
    cout<<"enter x: to exit"<<endl;
    cout<<"enter rm: to replay"<<endl;
}

void loop(string s) {
    while(s != "x")
    {
        if(s == "rm") {
            maze_opener();
            cout<<"\033[97;1m";
            cin>>s;
            continue;
        }
        pair<int,int> curr_moveset = parser(s);
        if(curr_moveset.first != -1 && curr_moveset.second != -1) {
            x = curr_moveset.first;
            y = curr_moveset.second;
            print();
            if(x == 19 && y == 19) {
                end_state();
            }
        }
        else{cout<<"\033[94m"<<"Invalid Input"<<endl;}
        cout<<"\033[97;1m";
        cin>>s;
    }
}

int main()
{
    start_state();
    maze_opener();
    string s;cin>>s;
    loop(s);

    return 0;
}
