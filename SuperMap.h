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
        SuperMap();

        //! \brief Constructeur Basic
        //!
        //! \param sf::Vector2i : Taille en Tile
        //! \param sf::Vector2f : Position
        SuperMap(sf::Vector2i mapNbrTile,sf::Vector2f position);

        //! \brief Construit la map
        //!
        //! \param sf::Vector2i : Taille en Tile
        //! \param sf::Vector2f : Position
        void build(sf::Vector2i mapNbrTile, sf::Vector2f positionMap);
        void deleteMap();

        void draw(sf::RenderWindow *fenetre);

        void save(std::string nomMap);
        void load(std::string nomMap);

        sf::Vector2i getMouseTilePosition(sf::Vector2i mouseLocalPosition);

        void setGridPosition(sf::Vector2f positionMap);

        void setTile(sf::Vector2i tilePosition, SuperTile tile, sf::Vector2i mouseLocalPosition);


        virtual ~SuperMap();
    protected:

    private:

        int m_nbrTexture;
        sf::Vector2i m_mapNbrTile;
        sf::Vector2f m_position;
        TileSetTexture m_tileSetTexture[5];

        bool m_isMapBuild;

        SuperTile *m_tabMap[100][100];
        bool m_startPointBuild;
        SuperTile *m_startPlayerPoint;
        std::vector<SuperTile*> m_tabMonstre;

        void triTableauDyn();

};

#endif // SUPERMAP_H
