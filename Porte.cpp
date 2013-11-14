#include "Porte.h"

Porte::Porte()
{
    //ctor
}

Porte::Porte(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Decors(tileSetTexture,tilePosition,tileID)
{
    setName("PORTE");
    setIfPassable(false);
}

Porte::~Porte()
{
    //dtor
}
