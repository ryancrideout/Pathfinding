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
            vector<vector<float>> open_vector;
            vector<vector<float>> closed_vector;

            // Put current x and y into the open vector, do we need to identify it as the starting point?
            // I think we need to add the "F" as well. Initial F is to be zero.
            // Maybe add G and H as well?
            vector<float> start_node = {starting_x, starting_y, 0};

            // Add this to the open_vector
            open_vector.push_back(start_node);

            bool at_destination = false;
            while (!at_destination) {

                // Look for the lowest 'F' cost square on the open list. This is the current square.

                // Take the current square, and then put it into the closed list.

                // Then, for each of the 8 squares adjacent to the current square:
                /*
                - If it is not walkable or if it is on the closed list, ignore it. Otherwise

                - If it isn't on the open list, add it to the open list. Make the current square
                  the parent of that square. Record the F, G and H costs of the square.

                - If it IS on the open list already, check to see if this path to that square is better,
                  using G cost as the measure. A lower G cost means that this is a better path. If so,
                  change the parent of the square to the current square, and recalculate the G and F
                  scores of the square.
                */

               // Stop when you:
               /*
               - Add the target square to the closed list, in which case the path has been found, or

               - Fail to find the target square, and the open list is empty. In this case, there is no path.
               */

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