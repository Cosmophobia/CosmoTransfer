#ifndef MUR_H
#define MUR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Decors.h"

class Mur : public Decors
{
    public:
        Mur();
        Mur(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);

        virtual ~Mur();
    protected:
    private:
};

#endif // MUR_H
