#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "Map.h"
#include "MapTile.h"

// Default Constructor
Map::Map(){
    height = 10;
    width = 10;
    generate_map();
}

Map::Map(int h, int w){
    height = h;
    width = w;
    generate_map();
};

// This is our method that we use to generate a map.
void Map::generate_map(){
    // We need srand in order to get truly random numbers.
    srand((unsigned int)time(NULL));
    bool passable;
    int bool_value;
    for(int x_coord = 0; x_coord < width; x_coord++) {
        for(int y_coord = 0; y_coord < height; y_coord++){
            // Randomly determine if the MapTile is passable or not.
            bool_value = (rand() % 10);
            if (bool_value > 1){
                passable = true;
            }
            else {
                passable = false;
            }

            // Declare a MapTile and then put it into the dictionary.
            MapTile maptile(x_coord, y_coord, passable);
            map_tile[x_coord][y_coord] = maptile;
        };
    };   
};

