#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "Map.h"
#include "MapTile.h"
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(int x, int y){
    position.first = x;
    position.second = y;
};

// This function ties a map to a vehicle. 
void Vehicle::load_map(Map m){
    map = m;

    // Need to check that our starting location isn't on a piece of impassable terrain.
    MapTile map_tile;
    map_tile = map.map_tile[position.first][position.second];
    if (map_tile.passable != true){
            find_new_starting_position(map);
        };
    };

// This is a method to find the most optimal path, if given coordinates.
string Vehicle::find_path(int x, int y){
    // So I don't forget, this is where the pathfinding algorithm should live.
    return "Ah ha, yes! I figured it out.";
};

// This is a function to, well, display the map.
void Vehicle::display_map(){
    for(int y_coord = 0; y_coord < map.height; y_coord++) {
        for(int x_coord = 0; x_coord < map.width; x_coord++){
            MapTile maptile = map.map_tile[x_coord][y_coord];
            if (x_coord == position.first && y_coord == position.second) {
                cout << 'V';
            }
            else if (maptile.passable == true){
                cout << '-';
            }
            else{
                cout << 'X';
            }
        };
        // This marks the next row of the map.
        cout << "\n";
    };  
};

void Vehicle::find_new_starting_position(Map m){
    Map map;
    map = m;

    // Map Tile isn't passable, find a new tile to be our starting position.
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            MapTile new_map_tile;
            new_map_tile = map.map_tile[position.first + i][position.second + j];

            // New Map Tile is passable, set the position of the vehicle to be the coordinates of the 
            // new map tile.
            if (new_map_tile.passable == true){
                position.first = new_map_tile.x_coordinate;
                position.second = new_map_tile.y_coordinate;

                // We have our vehicle on passable terrain, we're done here. Use a goto to break out of
                // these loops.
                return;
                };
            };
        }
    };