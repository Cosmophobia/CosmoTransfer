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

        //GETTER
        sf::Vector2i getNextMove(sf::Vector2i mouvement);

        //SETTER
        void setDestination(sf::Vector2i destination);
        void resetDestination();

        virtual ~PersonnageJoueur();
    protected:
    private:
        sf::Vector2f m_destination;

        sf::Time m_lastDraw;

        thor::FrameAnimation m_walking;
        thor::Animator<sf::Sprite, std::string> m_pjAnimator;
};

#endif // PERSONNAGEJOUEUR_H
