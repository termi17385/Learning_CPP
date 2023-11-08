#include "MapExample.h"

Vector2::Vector2(int _x, int _y)
{
	x = _x;
	y = _y;
}

Vector2::Vector2() {}

Vector2 Vector2::operator+(Vector2& const _other) const
{
	return Vector2(x + _other.x, y + _other.y);
}
Vector2 Vector2::operator-(Vector2& const _other) const
{
	return Vector2(x - _other.x, y - _other.y);
}

void MapExample::displayLevel()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            std::cout << level[i][j];
        }

        std::cout << std::endl;
    }
}

bool MapExample::isPlaying()
{
    doMove(getInput());
    return playing;
}

MapExample::MapExample()
{
    generateBoard();

    // generating for each case
    
    // maps allow you to store key value pairs
    // meaning you can use a key such as a char
    // to store and retrieve a value

    movementDirections['W'] = &UP;
    movementDirections['w'] = &UP;
    movementDirections['S'] = &DOWN;
    movementDirections['s'] = &DOWN;
    movementDirections['A'] = &LEFT;
    movementDirections['a'] = &LEFT;
    movementDirections['D'] = &RIGHT;
    movementDirections['d'] = &RIGHT;
}

void MapExample::generateBoard()
{
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            switch (grid[i][j]) 
            {
                case PLAYER:
                level[i][j] = 'P';
                currentPosition = Vector2(i,j);
                break;

                case WALL:
                level[i][j] = '#';
                break;

                case EMPTY:
                level[i][j] = '.';
                break;

                default:
                level[i][j] = '?';  // Just in case there's an unknown value
            }
        }
    }
}

void MapExample::doMove(Vector2 _input)
{
    Vector2 nextPosition = currentPosition + _input;
    
    char nextTile = level[nextPosition.x][nextPosition.y];
    
    char playerTile = level[currentPosition.x][currentPosition.y];


    // Can only move if the next tile is empty
    if (nextTile == CEMPTY)
    {
        level[nextPosition.x][nextPosition.y] = playerTile;
        level[currentPosition.x][currentPosition.y] = CEMPTY;
        currentPosition = nextPosition;
    }
}

Vector2& MapExample::getInput()
{
    char ans = ' ';
    std::cout << std::endl;
    std::cout << "Enter Key (W,A,S,D) or Exit (E): ";
    std::cin >> ans;
    std::cout << std::endl;

    if (ans == 'e' || ans == 'E')
    {
        playing = false;
        auto pos = Vector2(0, 0);
        return pos;
    }

    // reason for the pointers is to return a reference, so we actually have the value returned?
    // idk C++ is weird sometimes.
    // decent usecase for a map

    // No need to write a switch or if statements, can get movement directly from map
    // this can be quite useful and I think it is faster?
    // only issue is it is not the most readable sometimes.
    return *movementDirections[ans]; 
}