#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "SuperTile.h"
#include "Passable.h"
#include "Decors.h"
#include "Personnage.h"
#include "PersonnageJoueur.h"
#include "Monstre.h"
#include "Mur.h"
#include "Sol.h"
#include "Porte.h"

class GameMap
{
    public:
        GameMap();

        void draw(sf::RenderWindow *fenetre, sf::Time elapseTime);

        void load(std::string nomMap);

        void setMapPosition(sf::Vector2f mapPosition);

        //EVENT
        void KeyboardEvent(sf::Event evenement);

        virtual ~GameMap();
    protected:
    private:
        TileSetTexture m_tileSetTexture[7];

        sf::Vector2i m_mapNbrTile;
        sf::Vector2f m_position;
        bool m_isMapBuild;

        Decors *m_tabMap[100][100];
        std::vector<Personnage*> m_tabMonstre;
        PersonnageJoueur *m_player;


};

#endif // GAMEMAP_H
