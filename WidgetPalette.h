#ifndef WIDGETPALETTE_H
#define WIDGETPALETTE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "SuperTile.h"
#include "TileSetTexture.h"

class WidgetPalette
{
    public:
        WidgetPalette(sf::Vector2f position);

        void draw(sf::RenderWindow *f);
        void update(sf::Vector2i mouseLocalPosition,  sf::Time elapseTime);

        void setWidgetPosition(sf::Vector2f position = sf::Vector2f (0,0));

        SuperTile getSelectTile();

        virtual ~WidgetPalette();
    protected:
    private:

        sf::Texture *m_texture;
        sf::Font *m_font;
        TileSetTexture m_tileSetTexture[5];

        sf::Vector2f m_position;
        bool m_isActive;


        sf::Time m_upddateTime;

        sf::RectangleShape m_fond;
        sf::RectangleShape m_bouton[2];
        sf::Text m_texte[1];
        void setWidget();

        int m_selectedTexture;
        int m_nbrTexture;

        SuperTile *m_tilePalette[100][100];
        SuperTile m_selectionTile;

};

#endif // WIDGETPALETTE_H
