#ifndef SUPERMAP_H
#define SUPERMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"
#include "SuperTile.h"

class SuperMap
{
    public:
        //Constructeur
        SuperMap();

        //! \brief Constructeur Basic
        //!
        //! \param sf::Vector2i : Taille en Tile
        //! \param sf::Vector2f : Position
        SuperMap(sf::Vector2i mapNbrTile,sf::Vector2f position);

        //INITIALISATION
        //! \brief Construit la map
        //!
        //! \param sf::Vector2i : Taille en Tile
        //! \param sf::Vector2f : Position
        void build(sf::Vector2i mapNbrTile, sf::Vector2f positionMap);
        //! \brief Efface toute la map
        //!
        void deleteMap();

        //Action
        void draw(sf::RenderWindow *fenetre);

        //System
        void save(std::string nomMap);
        void load(std::string nomMap);

        //Event
        void scrollMap(std::string direction,float step);
        void scaleMap(std::string zoom, float step);

        //Getter
        sf::Vector2i getMouseTilePosition(sf::Vector2i mouseLocalPosition);

        //Setter
        void setGridPosition(sf::Vector2f positionMap);
        void setTile(sf::Vector2i tilePosition, SuperTile tile, sf::Vector2i mouseLocalPosition);

        //Destructeur
        virtual ~SuperMap();

    protected:

    private:
        //Texture
        int m_nbrTexture;
        TileSetTexture m_tileSetTexture[5];

        //Map Init
        sf::Vector2i m_mapNbrTile;
        sf::Vector2f m_position;
        bool m_isMapBuild;
        bool m_startPointBuild;

        //Map Obj
        SuperTile *m_tabMap[100][100];
        SuperTile *m_startPlayerPoint;
        std::vector<SuperTile*> m_tabMonstre;

        //Fonction
        void triTableauDyn();

};

#endif // SUPERMAP_H
