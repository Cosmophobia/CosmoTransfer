#ifndef WIDGETMENU_H
#define WIDGETMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "WidgetSystem.h"
#include "WidgetWindowNewMap.h"


class WidgetMenu
{
    public:
        //! \brief Constructeur
        //!
        //! \param sf::Vector2f : position du widget
        //! \param sf::Vector2f : taille (default = 72,72)
        WidgetMenu(sf::Vector2f position, sf::Vector2f taille = sf::Vector2f(72,72));

        void build(sf::Vector2f position);

        //! \brief Dessine le Widget
        //!
        //! \param sf::RenderWindow : fenetre de rendu
        void draw(sf::RenderWindow *f);

        //! \brief Update le Widget
        //!
        //! \param sf::Vector2i : Position de la souris
        void update(sf::Vector2i mouseLocalPosition, sf::Time elapseTime);

        //! \brief Permet de choisir le Widget que ce bouton va faire apparaitre
        //!
        //! \param
        //! \param
        void setChildWidget(WidgetSystem &widgetSystem);

        virtual ~WidgetMenu();
    protected:
    private:
        sf::Texture *m_texture;
        sf::Vector2f m_position;
        bool m_isActive;
        sf::Time m_updateTime;

        sf::RectangleShape m_btMenu;
        void setBtMenu();

        WidgetSystem *m_widgetSystem;



        sf::RectangleShape *m_bouton[1];
        int m_menuOutState;

};

#endif // WIDGETMENU_H
