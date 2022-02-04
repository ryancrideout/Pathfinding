#ifndef Map_H
#define Map_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "MapTile.h"
using namespace std;

class Map {
    public:
        map<int, map<int, MapTile>> map_tile;
        int height;
        int width;

        // Default Constructor
        Map();
        Map(int h, int w);

        // This is our method that we use to generate a map.
        void generate_map();
      
};

#endif