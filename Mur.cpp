#include "Mur.h"

Mur::Mur()
{

}

Mur::Mur(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Decors(tileSetTexture,tilePosition,tileID)
{
    setName("MUR");
    setIfPassable(false);
}


Mur::~Mur()
{
    //dtor
}
