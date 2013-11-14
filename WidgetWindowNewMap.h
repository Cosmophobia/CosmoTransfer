#ifndef WIDGETWINDOWNEWMAP_H
#define WIDGETWINDOWNEWMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class WidgetWindowNewMap
{
    public:
        WidgetWindowNewMap(sf::Vector2f position);

        void build(sf::Vector2f position);
        void draw(sf::RenderWindow *f);
        void update(sf::Vector2i mouseLocalPosition);

        void setWidgetPosition(sf::Vector2f step = sf::Vector2f (0,0));

        int getButtonOnMouseLocation(sf::Vector2i mouseLocalPosition);
        sf::Vector2i getSelectedMapSize();

        virtual ~WidgetWindowNewMap();
    protected:
    private:
        sf::Texture *m_texture;
        sf::Font *m_font;

        sf::Vector2f m_position;
        bool m_isActive;

        sf::RectangleShape m_bouton[4];
        sf::Text m_texte[4];
        void setWidget();

        int m_nbrX;
        int m_nbrY;

        std::string int2string(int i);
};

#endif // WIDGETWINDOWNEWMAP_H
