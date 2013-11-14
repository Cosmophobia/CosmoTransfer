#ifndef DECORS_H
#define DECORS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Passable.h"

class Decors : public Passable
{
    public:
        Decors();
        Decors(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);

        virtual void info();

        std::string getName();
        void setName(std::string name);

        virtual ~Decors();
    protected:
    private:
        std::string m_name;
};

#endif // DECORS_H
