// This is just a test file to get me started on C++ - it's been forever since I've worked in C++.

#include <iostream>
// Need these two for random number generation - see here:
// https://stackoverflow.com/questions/9459035/why-does-rand-yield-the-same-sequence-of-numbers-on-every-run
#include <cstdlib>
#include <ctime>
using namespace std; // This allows us to use "cout" instead of "std::cout"!

// Create a simple class object so I can remember how to do so. This will be a Map, which will start
// to outline how we're going to do random map generation.
class Map {
    // Good tutorial about private access - think about this later.
    // https://www.tutorialspoint.com/cplusplus/cpp_class_access_modifiers.htm
    // private:
    //     int max_width;
    //     int min_width;
    //     int max_height;
    //     int min_height;

    public:
        int width;
        int height;
        Map(int min_width, int max_width, int min_height, int max_height){
            // We need srand in order to get truly random numbers.
            srand((unsigned int)time(NULL));

            // Declare the Width and Height
            width = min_width + (rand() % static_cast<int>(max_width - min_width + 1));
            height = min_height + (rand() % static_cast<int>(max_height - min_height + 1));
        };

    // Probably don't need to worry about deconstructors yet, but it's good to know that they exist.
};

int main() {

    Map map_one(4, 7, 6, 10);

    cout << "This is the width of our map object: " << map_one.width << "\n";
    cout << "This is the height of our map object: " << map_one.height << "\n";

    Map map_two(8, 14, 12, 20);

    cout << "This is the width of our map object: " << map_two.width << "\n";
    cout << "This is the height of our map object: " << map_two.height << "\n";

    return 0;
}