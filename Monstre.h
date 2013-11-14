#ifndef MONSTRE_H
#define MONSTRE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Personnage.h"

class Monstre : public Personnage
{
    public:
        Monstre();
        Monstre(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);
        virtual ~Monstre();
    protected:
    private:
};

#endif // MONSTRE_H
