#ifndef PERSOJOUEUR_H
#define PERSOJOUEUR_H

#include <SFML/Graphics.hpp>
#include <THOR/Animation.hpp>
#include <iostream>
#include <string>
#include "TileSetTexture.h"
#include "SuperTile.h"


class PersoJoueur : public SuperTile
{
    public:
        PersoJoueur();
        void draw(sf::RenderWindow *fenetre,sf::Time timeOfDraw);
        void playWalkAnimation();
        void deplacementPerso(sf::Time tempTime);

        //SETTER
        void setDestination(sf::Vector2f destination);

        virtual ~PersoJoueur();
    protected:
    private:
        sf::Vector2f m_playerPosition;
        sf::Vector2f m_destination;
        sf::Sprite m_playerSprite;
        sf::Time m_lastDraw;
        TileSetTexture m_spriteTexture;
        thor::FrameAnimation m_walking;
        thor::Animator<sf::Sprite, std::string> pjAnimator;
};

#endif // PERSOJOUEUR_H
