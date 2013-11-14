#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Passable.h"

class Personnage : public Passable
{
    public:
        Personnage();
        Personnage(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);

        virtual void info();

        std::string getName();
        void setName(std::string name);

        virtual ~Personnage();
    protected:
    private:
        std::string m_name;
};

#endif // PERSONNAGE_H
