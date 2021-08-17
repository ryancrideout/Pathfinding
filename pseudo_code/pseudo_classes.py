# Writing this in Python so that Jacob doesn't have to work to understand a different language. 

# The idea here is to just map out what I think the classes will be for this little pathfinding project.
# I also feel compelled to mention that I could definitely see this all changing - but this is meant
# to be the rough idea.

'''
Overview of the Classes:

Node Class - This represents a single tile on a map. 

Map Class - This is, well, the map. Will have a one-to-many relationship to the Node class.
        
Vehicle Class - This will be our vehicle that lets us perform pathfinding calculations. Will
                try to find the best path from point A to point B.
'''

'''
Objective:

I want to make a function that generates a random map and then places a vehicle on the map.
From there I could give the vehicle a destination and then it would try to find the fastest
way to get to the destination.
'''

class MapTile:
    '''
    MapTile class. 

    Contains X and Y coordinates so that we may assign it to a position on the map, and then has
    a terrain attribute so we can determine if the node is passable terrain or not.

    A Map object will be composed of several of these nodes.

    I have ambitions to add a "visible" attribute (think 'Fog of War') but that can come later.
    '''
    def __init__(self, x_coordinate, y_coordinate, passable):
        '''
        x_coordinate - integer
        y_coordinate - integer
        passable - boolean
        '''
        self.x = x_coordinate
        self.y = y_coordinate
        
        self.passable = passable


class Map:
    '''
    Map class.

    Note that initialization parameters height and width are integers.
    '''

    # This is the variable where we'll store all of our Map nodes.
    tile_map = {}

    def __init__(self, height, width):
        '''
        height - integer
        width - integer
        '''
        self.height = height
        self.width = width

    def generate_map(self):
        # Basically we fill out each coordinate space on the map with a MapTile, which
        # involves us creating a new map tile per 'tile'. As we do this we populate the tile_map
        # so that we can keep track of all the tiles.

        # Design questions -
        #     What happens when we call generate_map twice? Do we delete old nodes?
        for x_cord in range(width):
            tile_map[x_cord] = {}
            for y_cord in range(height):
                # Input some logic here to randomly generate the terrain -
                # terrain should either be 'passable' or 'impassable'... for now.
                tile_map[x_cord][y_cord] = MapTile(x_cord, y_cord, True)

    def display_map(self):
        '''
        This will print out the map to the command line or something. I think what I would do
        is iterate through the node_map dictionary, and if the node is passable terrain then
        display an "-" - otherwise I would display an "X".

        I'll build this out later though.
        '''
        return True


class Vehicle:
    '''
    Vehicle class.

    This will let us do the pathfinding, and I think in the future there are a lot of fun things we can do with this.
    For now though, I'm going to keep it pretty barebones.
    '''
    def __init__(self, x_start, y_start, map):
        '''
        x_start - integer, supposed to represent the starting x coordinate of the vehicle.
        y_start - integer, supposed to represent the starting y coordinate of the vehicle.

        Note that I make a distinction between the position and starting position as the starting_position
        is meant to be a "one and done" type deal (that is, we never intend to update it, but can maybe use
        it to reset the vehicle location), though the position could change.
        '''
        self.position = (x_start, y_start)

    def load_map(self, map):
        '''
        map - Map object. This is the map the vehicle is supposed to be on.

        Here we associate a map to the vehicle we're using. I think this could be a database relation in theory,
        but I'm not too sure.
        '''
        self.map = map

    def find_path(self, destination):
        '''
        destination - tuple of integers.

        This is where the magic happens. I basically try to find the fastest path between the current
        position and the destination. Will fill this out MUCH later as this is the meat and potatoes
        of the pathfinding exercise.
        '''
        return True