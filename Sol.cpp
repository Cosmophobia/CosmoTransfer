#include "Sol.h"

Sol::Sol()
{
    //ctor
}

Sol::Sol(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Decors(tileSetTexture,tilePosition,tileID)
{
    setName("SOL");
    setIfPassable(true);
}

Sol::~Sol()
{
    //dtor
}
