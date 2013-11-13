#ifndef SUPERTILE_H
#define SUPERTILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "TileSetTexture.h"

class SuperTile : public sf::Sprite
{
    public:
        SuperTile();
        SuperTile(TileSetTexture &tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i id = sf::Vector2i(0,0) , sf::Vector2f mapOrigin = sf::Vector2f(0,0));

        //Position
        //! \brief Cette fonction permet de ranger les SuperTiles en grille selon leur ID
        //!
        //! \param sf::Vector2f : Position de l'origin de la map
        void setIdGridPosition(sf::Vector2f positionMap);

        //! \brief Cette fonction permet de ranger les SuperTiles en grille selon leur Position
        //!
        //! \param sf::Vector2f : Position de l'origin de la map
        void setMapPosition(sf::Vector2f positionMap);

        //! \brief Permet de scale un groupe de SuperTile en X
        //!
        //! \param float : la taille a atteindre
        //! \param int : nombre de SuperTile
        void setAutoScaleX(float width, int textureNbrTileX);

        //Setter
        //! \brief Change automatiquement le TextureRect en fontion de l'ID
        //!
        void autoSetTileTextureRect();
        void setTileSetTexture(TileSetTexture &tileSetTexture);
        void setTilePosition(sf::Vector2i tilePosition);
        //! \brief Change l'ID puis change automatiquement le TextureRect
        //!
        void setId(sf::Vector2i id);
        void setMapOrigin(sf::Vector2f mapOrigin);

        //Getter
        int getTileSetTextureID();
        sf::Vector2i getTilePositon();
        sf::Vector2i getId();
        sf::Vector2f getMapOrigin();

        virtual ~SuperTile();
    protected:
    private:
        TileSetTexture *m_tileSetTexture;
        sf::Vector2i m_tilePosition;
        sf::Vector2i m_id;
        sf::Vector2f m_mapOrigin;
};

#endif // SUPERTILE_H
