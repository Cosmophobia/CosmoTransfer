#ifndef PORTE_H
#define PORTE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Decors.h"

class Porte : public Decors
{
    public:
        Porte();
        Porte(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);



        virtual ~Porte();
    protected:
    private:

};

#endif // PORTE_H
