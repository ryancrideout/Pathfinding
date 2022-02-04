#ifndef Vehicle_H
#define Vehicle_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "Map.h"
#include "MapTile.h"
using namespace std;

class Vehicle {
    public:
        Map map;
        pair<int, int> position;
        Vehicle(int x, int y);

        // This function ties a map to a vehicle. 
        void load_map(Map m);

        // This is a method to find the most optimal path, if given coordinates.
        string find_path(int x, int y);

        // This is a function to, well, display the map.
        void display_map();

    private:
        void find_new_starting_position(Map m);
};

#endif