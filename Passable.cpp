#include "Passable.h"

Passable::Passable()
{
   //Constructeur par default
}
Passable::Passable(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID, bool isPassable):
    SuperTile(tileSetTexture, tilePosition, tileID),
    m_passable(isPassable)
{
   //Constructeur Complet
}

//GETTER
bool Passable::getIfPassable()
{
    return m_passable;
}


//SETTER
void Passable::setIfPassable(bool isPassable)
{
    m_passable = isPassable;
}


Passable::~Passable()
{
    //dtor
}
