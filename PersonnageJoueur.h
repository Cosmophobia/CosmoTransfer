#ifndef PERSONNAGEJOUEUR_H
#define PERSONNAGEJOUEUR_H

#include <SFML/Graphics.hpp>
#include <THOR/Animation.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "Personnage.h"

class PersonnageJoueur : public Personnage
{
    public:
        PersonnageJoueur();
        PersonnageJoueur(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID);

        //SYSTEM
        void draw(sf::RenderWindow *fenetre, sf::Time timeOfDraw);

        //ANIMATION
        void playWalkAnimation();

        //EVENT
        void deplacementPerso(sf::Time tempTime);

        //SETTER
        void setDestination(sf::Vector2i destination);
        void resetDestination();

        virtual ~PersonnageJoueur();
    protected:
    private:
        sf::Vector2f m_destination;
        sf::Sprite m_playerSprite;
        sf::Time m_lastDraw;
        TileSetTexture m_spriteTexture;
        thor::FrameAnimation m_walking;
        thor::Animator<sf::Sprite, std::string> pjAnimator;
};

#endif // PERSONNAGEJOUEUR_H
