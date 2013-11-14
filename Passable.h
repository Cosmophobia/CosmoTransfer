#ifndef PASSABLE_H
#define PASSABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "SuperTile.h"


class Passable : public SuperTile
{
    public:
        Passable();
        Passable(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID, bool isPassable);

        //GETTER
        bool getIfPassable();

        //SETTER
        void setIfPassable(bool isPassable);

        virtual ~Passable();
    protected:
    private:
        bool m_passable;
};

#endif // PASSABLE_H
