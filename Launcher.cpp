#include "Launcher.h"

Launcher::Launcher(sf::RenderWindow *fenetre)
{
    m_fenetreMenu = fenetre;
    m_textureFond = new sf::Texture;
    if(!m_textureFond->loadFromFile("images/FondMenu.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    m_textureMenu = new sf::Texture;
    if(!m_textureMenu->loadFromFile("images/tileSetMenu150x50.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    std::cout<<"-> Textures : OK"<<std::endl;

    m_fenetreMenu->create(sf::VideoMode(500,500,32),"Cosmophobia Launcher prototype",sf::Style::Close);
    m_imgFond.setTexture(*m_textureFond);
    m_imgFond.setPosition(0,0);
    m_imgFond.setTextureRect(sf::IntRect(0,0,500,500));

    for(int i = 0; i < 3; i++)
    {
        m_tabBouton[i] = new sf::RectangleShape(sf::Vector2f(150,50));
        m_tabBouton[i]->setPosition(sf::Vector2f(50,250+50*i+10*i));
        m_tabBouton[i]->setTexture(m_textureMenu);
        m_tabBouton[i]->setTextureRect(sf::IntRect(150*i,0,150,50));
    }
}
void Launcher::updateBouton(sf::Vector2i localPosition)
{
    for(int i = 0; i < 3; i++)
    {
        if(m_tabBouton[i]->getGlobalBounds().contains(localPosition.x,localPosition.y))
        {
            m_tabBouton[i]->setTextureRect(sf::IntRect(150*i,50,150,50));
        }
        else
        {
            m_tabBouton[i]->setTextureRect(sf::IntRect(150*i,0,150,50));
        }
    }
}
bool Launcher::pollEvent(sf::Event evenement)
{
    if(m_fenetreMenu->pollEvent(evenement))
    {
       return true;
    }
    return false;
}
int Launcher::ifBoutonIsPress(sf::Vector2i localPosition)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for(int i = 0; i < 3; i++)
        {
            if(m_tabBouton[i]->getGlobalBounds().contains(localPosition.x,localPosition.y))
            {
                return i;
            }
        }

    }
    return -1;
}
void Launcher::draw()
{
    m_fenetreMenu->clear();
    m_fenetreMenu->draw(m_imgFond);
    for(int i = 0; i < 3; i++)
    {
        m_fenetreMenu->draw(*m_tabBouton[i]);
    }
    m_fenetreMenu->display();
}
Launcher::~Launcher()
{
        delete m_textureFond;
        m_textureFond = 0;
        delete m_textureMenu;
        m_textureMenu = 0;
        m_fenetreMenu = 0;
        for(int i; i<3 ; i++)
        {
            delete m_tabBouton[i];
            m_tabBouton[i] = 0;
        }

}
