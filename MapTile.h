#ifndef MapTile_H
#define MapTile_H

class MapTile {
    public:
        int x_coordinate;
        int y_coordinate;
        bool passable;

        MapTile();
        MapTile(int x_coord, int y_coord, bool pass);
};

#endif