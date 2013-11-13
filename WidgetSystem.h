#ifndef WIDGETSYSTEM_H
#define WIDGETSYSTEM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "WidgetWindowNewMap.h"
#include "WidgetPalette.h"

class WidgetSystem
{
    public:
        WidgetSystem(sf::Vector2f position, sf::Vector2f taille = sf::Vector2f(96,96));

        void build(sf::Vector2f position);
        void draw(sf::RenderWindow *f);
        void update(sf::Vector2i mouseLocalPosition, sf::Time elapseTime);
        void setNewMapWidget(WidgetWindowNewMap &widgetNewMap);
        void setPaletteWidget(WidgetPalette &widgetPalette);


        void deplacement(sf::Vector2f d);

        sf::Vector2f getPosition();
        void setPosition(sf::Vector2f p);

        virtual ~WidgetSystem();
    protected:
    private:
        sf::Vector2f m_position;
        bool m_isActive;
        sf::Texture *m_texture;
        sf::Time m_updateTime;

        sf::RectangleShape m_bouton[4];
        void setBouton();

        WidgetWindowNewMap *m_widgetNewMap;
        bool m_isWidgetNewMapActive;

        WidgetPalette *m_widgetPalette;
        bool m_isWidgetPaletteActive;
};

#endif // WIDGETSYSTEM_H
