//
// Created by rathi on 11/15/2023.
//

#pragma once

#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include<stdlib.h>
#include<vector>
#include<iostream>

#include "playerdata.h"

#pragma once

void backtracker(const std::pair<int, int> &source, bool visited[20][20]);


#endif //MAZEGENERATOR_H
