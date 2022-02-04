#include "MapTile.h"

MapTile::MapTile(){
    x_coordinate = 0;
    y_coordinate = 0;
    passable = true;
}

MapTile::MapTile(int x_coord, int y_coord, bool pass){
    x_coordinate = x_coord;
    y_coordinate = y_coord;
    passable = pass;
}
