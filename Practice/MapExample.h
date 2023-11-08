#pragma once

#include<iostream>
#include<string>
#include<map>

struct Vector2
{
	int x = 0;
	int y = 0;

	Vector2(int _x, int _y);
	Vector2();

    // general overload examples
	Vector2 operator+(Vector2& const) const; 
	Vector2 operator-(Vector2& const) const;
};

static Vector2 UP    = Vector2(-1, 0);
static Vector2 DOWN  = Vector2(1, 0);
static Vector2 LEFT  = Vector2(0, -1);
static Vector2 RIGHT = Vector2(0, 1);

static int grid[10][10] = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  1,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};

// Kinda unnessarcy, needs to follow proper princples 
// constants for mapping the level / grid
const int PLAYER = 1, WALL = -1, EMPTY = 0;     
const int CPLAYER = 'P', CWALL = '#', CEMPTY = '.';

class MapExample
{
public:

    void displayLevel();
    bool isPlaying();
    MapExample();

private:
    std::map<char, Vector2*> movementDirections; // mapping movement directions
    
    char level[10][10];  // probably should just be an int array
    void generateBoard();
    
    void doMove(Vector2); 
    Vector2& getInput();

    bool playing = true;
    Vector2 currentPosition = Vector2(0,0);
};