#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Launcher
{
    public:
        Launcher(sf::RenderWindow *fenetre);
        //ACTION
        void updateBouton(sf::Vector2i localPosition);
        //EVENEMENT
        bool pollEvent(sf::Event evenement);
        int ifBoutonIsPress(sf::Vector2i localPosition);
        //DRAW
        void draw();
        //GETTER
        sf::RenderWindow getFenetre();
        virtual ~Launcher();
    protected:
    private:
        sf::Texture *m_textureFond;
        sf::Texture *m_textureMenu;
        sf::RenderWindow *m_fenetreMenu;
        sf::Sprite m_imgFond;
        sf::RectangleShape *m_tabBouton[3];
};

#endif // LAUNCHER_H
