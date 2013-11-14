#ifndef SOL_H
#define SOL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Decors.h"


class Sol : public Decors
{
    public:
        Sol();
        Sol(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);



        virtual ~Sol();
    protected:
    private:


};

#endif // SOL_H
