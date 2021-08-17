#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
using namespace std;

class MapTile {
    public:
        int x_coordinate;
        int y_coordinate;
        bool passable;

        MapTile(){
            x_coordinate = 0;
            y_coordinate = 0;
            passable = true;
        };

        MapTile(int x_coord, int y_coord, bool pass){
            x_coordinate = x_coord;
            y_coordinate = y_coord;
            passable = pass;
        };
};


class Map {
    public:
        map<int, map<int, MapTile>> map_tile;
        int height;
        int width;

        // Default Constructor
        Map(){
            height = 10;
            width = 10;
            generate_map();
        }

        Map(int h, int w){
            height = h;
            width = w;
            generate_map();
        };

        void generate_map(){
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

        void display_map(){
            for(int y_coord = 0; y_coord < height; y_coord++) {
                for(int x_coord = 0; x_coord < width; x_coord++){
                    MapTile maptile = map_tile[x_coord][y_coord];
                    if (maptile.passable == true){
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
      
};


class Vehicle {
    public:
        Map map;
        pair<int, int> position;
        Vehicle(int x, int y){
            position.first = x;
            position.second = y;
        };

        void load_map(Map m){
            map = m;
        };

        string find_path(int x, int y){
            return "Ah ha, yes! I figured it out.";
        };
};


// This is the main function.
int main(){

    Map first_map(10, 20);
    Vehicle first_vehicle(1, 1);

    first_vehicle.load_map(first_map);
    // cout << first_vehicle.find_path(3, 3) << "\n";
    first_map.display_map();

    return 0;
};