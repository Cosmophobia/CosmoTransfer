#ifndef PORTE_H
#define PORTE_H

#include <SFML/Graphics.hpp>
#include <THOR/Animation.hpp>

#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Decors.h"

class Porte : public Decors
{
    public:
        Porte();
        Porte(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);

        void draw(sf::RenderWindow *fenetre, sf::Time timeOfDraw);

        void playAnimation(std::string name);

        virtual ~Porte();
    protected:
    private:
        sf::Time m_lastDraw;

        thor::FrameAnimation m_open;
        thor::FrameAnimation m_close;
        thor::Animator<sf::Sprite, std::string> m_doorAnimator;

};

#endif // PORTE_H
