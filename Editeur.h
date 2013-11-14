#ifndef EDITEUR_H
#define EDITEUR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "WidgetMenu.h"
#include "WidgetSystem.h"
#include "WidgetWindowNewMap.h"
#include "WidgetPalette.h"
#include "SuperMap.h"

class Editeur
{
    public:
        Editeur(sf::RenderWindow *fenetre);

        void draw();

        void update(sf::Event evenement, sf::Time elapseTime);
        void keyboardAndMouseEvent(sf::Event evenement, sf::Time elapseTime);

        virtual ~Editeur();
    protected:
    private:
        sf::RenderWindow *m_fenetre;
        sf::Texture *m_textureFond;
        sf::Sprite m_imgFond;

        sf::Time m_updateTime;

        WidgetMenu m_widgetMenu;
        WidgetSystem m_widgetSystem;
        WidgetWindowNewMap m_widgetNewMap;
        WidgetPalette m_widgetPalette;
        SuperMap m_map;

};

#endif // EDITEUR_H
