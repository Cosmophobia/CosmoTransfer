#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "GameMap.h"
#include "PersoJoueur.h"


class GameScreen
{
    public:
        GameScreen(sf::RenderWindow *fenetre);

        //SYSTEM
        void load(std::string nomMap);

        //EVENT
        void wheelEvent(sf::Event evenement);
        void eventClavier(sf::Event evenement);
        void draw(sf::Time elapsedTime);

        virtual ~GameScreen();

    protected:
    private:

        sf::RenderWindow *m_fenetreGame;
        sf::Texture m_textureFondGame;
        sf::Sprite m_imgFondGame;
        sf::Vector2f m_gameMapOrigine;
        GameMap m_gameMap;
};

#endif // GAMESCREEN_H
