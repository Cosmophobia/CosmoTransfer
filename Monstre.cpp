#include "Monstre.h"

Monstre::Monstre()
{
    //ctor
}
Monstre::Monstre(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Personnage(tileSetTexture,tilePosition,tileID)
{
    setName("MONSTRE");
    setIfPassable(false);
}

Monstre::~Monstre()
{
    //dtor
}
