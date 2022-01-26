#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <string>
#include <vector>
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

        // This is our method that we use to generate a map.
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
      
};


class Vehicle {
    public:
        Map map;
        pair<int, int> position;
        Vehicle(int x, int y){
            position.first = x;
            position.second = y;
        };

        // This function ties a map to a vehicle. 
        void load_map(Map m){
            map = m;

            // Need to check that our starting location isn't on a piece of impassable terrain.
            MapTile map_tile;
            map_tile = map.map_tile[position.first][position.second];
            if (map_tile.passable != true){
                    find_new_starting_position(map);
                };
            };

        // This is a method to find the most optimal path, if given coordinates.
        string find_path(int x, int y){
            // So I don't forget, this is where the pathfinding algorithm should live.
            return "Ah ha, yes! I figured it out.";
        };

        // This is a function to, well, display the map.
        void display_map(){
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

    private:
        void find_new_starting_position(Map m){
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
};


// This is the main function.
int main(){

    // Map first_map(10, 20);
    // Vehicle first_vehicle(1, 1);

    // first_vehicle.load_map(first_map);

    // Not currently being used.
    // cout << first_vehicle.find_path(3, 3) << "\n";

    // first_vehicle.display_map();

    string command = "coordinates";
    string response = "empty";

    string x_coordinate;
    string y_coordinate;

    vector<string> yes_response{"yes", "y", "sure", "ya", "yeah", "Yes", "Y"}; 

    Vehicle main_vehicle(1, 1);
    Map main_map(10, 10);

    cout << "Hi welcome to my INSANE Pathfinding code project." << "\n";
    cout << "Enough small talk, give me some coordinates." << "\n";

    while (command != "terminate") {
        
        // The command to initialize a Map object; This sets the size of our map.
        // This is also the first command we run.
        if (command == "coordinates") {
            cout << "\n";
            cout << "Give me an X coordinate:" << "\n";
            getline(cin, x_coordinate);

            cout << "Now give me a Y coordinate you sultry vixen:" << "\n";
            getline(cin, y_coordinate);

            cout << "Alright is this the size you wanted the map to be?" << "\n";
            cout << "(" << x_coordinate << ", " << y_coordinate << ")" << "\n";
            getline(cin, response);

            // If 'yes', cast the coordinates to ints.
            if (find(yes_response.begin(), yes_response.end(), response) != yes_response.end()) {
                int int_x_cord = stoi(x_coordinate);
                int int_y_cord = stoi(y_coordinate);
                
                // Make our map.
                Map first_map(int_y_cord, int_x_cord);
                main_map = first_map;
                main_vehicle.load_map(main_map);

                cout << "Map made! Now give me a new command." << "\n";
                cout << "(Type 'help' for a list of commands.)" << "\n";
                getline(cin, command);
            }

            // If 'no', redo the whole thing. Remember 'command' is already set to 'coordinates',
            // so we don't need to reassign it.
        };

        if (command == "help") {
            cout << "\n";
            // Gives a list of commands and the like.
            cout << "Here are a list of the following commands and what they do:" << "\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << "\n";
            cout << "coordinates - This creates a map with user defined coordinates." << "\n";
            cout << "vehicle - This creates a vehicle with a user defined starting coordinates." << "\n";
            cout << "display - This displays the map." << "\n";
            cout << "pathfind - Finds a path from point A to point B." << "\n";
            cout << "terminate - Grants you sweet, sweet release." << "\n";
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << "\n";
            cout << "(Type 'help' for a list of commands.)" << "\n";
            getline(cin, command);
        };

        if (command == "vehicle") {
            cout << "\n";
            // Create a vehicle object and set starting coordinates.
            cout << "Give me some starting coordinates for this vehicle:" << "\n";
            cout << "First, an X coordinate:" << "\n";
            getline(cin, x_coordinate);

            cout << "Now, a Y coordinate:" << "\n";
            getline(cin, y_coordinate);

            cout << "Is this the starting location you want for your vehicle?" << "\n";
            cout << "(" << x_coordinate << ", " << y_coordinate << ")" << "\n";
            getline(cin, response);

            // If 'yes', cast the coordinates to ints.
            if (find(yes_response.begin(), yes_response.end(), response) != yes_response.end()) {
                int int_x_cord = stoi(x_coordinate);
                int int_y_cord = stoi(y_coordinate);
                
                // Create a vehicle with the specified coordinates.
                Vehicle first_vehicle(int_y_cord, int_x_cord);
                main_vehicle = first_vehicle;

                // Load up the map
                main_vehicle.load_map(main_map);

                cout << "Vehicle made! Now give me a new command." << "\n";
                cout << "(Type 'help' for a list of commands.)" << "\n";
                getline(cin, command);
            }

            // If 'no', redo the whole thing. Remember 'command' is already set to 'coordinates',
            // so we don't need to reassign it.
        };

        if (command == "display") {
            cout << "\n";
            // Display map function
            main_vehicle.display_map();

            cout << "Map displayed. Give me another command." << "\n";
            cout << "(Type 'help' for a list of commands.)" << "\n";
            getline(cin, command);
        };

        if (command == "pathfind") {
            cout << "\n";

            // Give current vehicle coordinates
            cout << "Here are the current vehicle coordinates:" << "\n";
            cout << "(" << main_vehicle.position.first << ", " << main_vehicle.position.second << ")" << "\n";
            cout << "\n";

            // Ask for destination coordinates
            cout << "Give me a DESTINATION X coordinate:" << "\n";
            getline(cin, x_coordinate);

            cout << "Now give me a DESTINATION Y coordinate:" << "\n";
            getline(cin, y_coordinate);

            // Variable declarations to help make our lives easier.
            float starting_x = main_vehicle.position.first;
            float starting_y = main_vehicle.position.second;
            float current_x = starting_x;
            float current_y = starting_y;
            float destination_x = stoi(x_coordinate);
            float destination_y = stoi(y_coordinate);

            // These might need to be a vector of something else.
            vector<float> open_vector = {};
            vector<float> closed_vector = {};

            // Put current x and y into the open vector, do we need to identify it as the starting point?

            bool at_destination = false;
            while (not at_destination) {

                at_destination = true;
            }

            /*
            Okay so what I realized is that I need to get the distance from:
            The current node and the starting node
            The current node and the ending node
            */
            float starting_x_distance = abs(main_vehicle.position.first - starting_x);
            float starting_y_distance = abs(main_vehicle.position.second - starting_y);
            float starting_x_squared = pow(starting_x_distance, 2);
            float starting_y_squared = pow(starting_y_distance, 2);
            float starting_distance = starting_x_squared + starting_y_squared;

            float destination_x_distance = abs(main_vehicle.position.first - destination_x);
            float destination_y_distance = abs(main_vehicle.position.second - destination_y);
            float destination_x_squared = pow(destination_x_distance, 2);
            float destination_y_squared = pow(destination_y_distance, 2);
            float destination_distance = destination_x_squared + destination_y_squared;

            // Need to make a path now... now how best to do it...

            /*
            I mean where do you even start with this?

            List of stuff:
            1) Get Destination X and Y.
            2) Find Path...
            3) Mark the best path on the Map.
            4) Display Map. Done.

            Alright but how do we find the best path?

            - Well you can count how many "steps" you take, and the path with the least steps is "best"

            - Depending on the obstacles though, you might need to move "away" from the destination to make progress.

            - Will need to calculate several routes. I guess you could brute force it, so with every tile, you go in
              every direction, and then with every direction you make a new path. Paths that lead into obstacles will
              "die" and won't use path calculations.

            - First path to reach destination will be the best path. I think for EACH tile step you update all of the paths.
              So going (for example) from step 4 -> 5 you would update all of the existing paths. Kill any of them that hit
              dead ends.

            - I guess we could try an "intelligent" method first and only consider paths that move "towards" the destination
              but that could be hard to calculate.

            - Worth reading: https://medium.com/@nicholas.w.swift/easy-a-star-pathfinding-7e6689c7f7b2
            */

            cout << "Path found. Give me another command." << "\n";
            cout << "(Type 'help' for a list of commands.)" << "\n";
            getline(cin, command);
        };

    };

    return 0;
};