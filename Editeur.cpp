#include "Editeur.h"

Editeur::Editeur(sf::RenderWindow *fenetre):
    m_widgetMenu(sf::Vector2f (0,0)),
    m_widgetSystem(sf::Vector2f (100,-96)),
    m_widgetNewMap(sf::Vector2f (50,200)),
    m_widgetPalette(sf::Vector2f (300,300))
{
    std::cout<<"In Ctor - EDITEUR"<<std::endl;
    m_fenetre = fenetre;
    m_textureFond = new sf::Texture;
    if(!m_textureFond->loadFromFile("images/FondEditor.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    std::cout<<"In Ctor ---- Texture OK"<<std::endl;

    m_fenetre->create(sf::VideoMode(1360,768,32),"Cosmophobia Editeur",sf::Style::Close);
    std::cout<<"In Ctor ---- Set RenderWindow OK"<<std::endl;

    m_imgFond.setTexture(*m_textureFond);
    m_imgFond.setPosition(0,0);
    m_imgFond.setTextureRect(sf::IntRect(0,0,1024,768));
    std::cout<<"In Ctor ---- ImgFond OK"<<std::endl;

    m_widgetMenu.setChildWidget(m_widgetSystem);
    m_widgetSystem.setNewMapWidget(m_widgetNewMap);
    m_widgetSystem.setPaletteWidget(m_widgetPalette);

    m_map.build(sf::Vector2i(10,10),sf::Vector2f(200,200));
    m_updateTime = sf::seconds(0);

    std::cout<<"Out Ctor - EDITEUR"<<std::endl;
}

void Editeur::draw()
{
    m_fenetre->clear();
    m_fenetre->draw(m_imgFond);
    m_map.draw(m_fenetre);
    m_widgetMenu.draw(m_fenetre);

    m_fenetre->display();

}

void Editeur::update(sf::Event evenement, sf::Time elapseTime)
{
    m_widgetMenu.update(sf::Mouse::getPosition(*m_fenetre), elapseTime);
    if (elapseTime > m_updateTime+sf::milliseconds(100))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (m_map.getMouseTilePosition(sf::Mouse::getPosition(*m_fenetre)).x != -1)
            {
               m_map.setTile(m_map.getMouseTilePosition(sf::Mouse::getPosition(*m_fenetre)),m_widgetPalette.getSelectTile(),sf::Mouse::getPosition(*m_fenetre));
               m_updateTime = elapseTime;
            }
            if (m_widgetNewMap.getButtonOnMouseLocation(sf::Mouse::getPosition(*m_fenetre)) != -1)
            {
                if(m_widgetNewMap.getButtonOnMouseLocation(sf::Mouse::getPosition(*m_fenetre)) == 3)
                {
                    m_map.deleteMap();
                    m_map.build(m_widgetNewMap.getSelectedMapSize(),sf::Vector2f (200,200));
                    m_updateTime = elapseTime;
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_map.save("testMap");
            m_updateTime = elapseTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            m_map.deleteMap();
            m_map.load("testMap");
            m_updateTime = elapseTime;
        }
    }

}

void Editeur::keyboardAndMouseEvent(sf::Event evenement, sf::Time elapseTime)
{
    if(elapseTime > m_updateTime+sf::milliseconds(300))
    {
        if (evenement.type == sf::Event::MouseWheelMoved)
        {
           int tmpDelta = evenement.mouseWheel.delta;
           std::cout<<"tmp delta ="<<tmpDelta<<std::endl;
           if(tmpDelta > 0)
           {
                m_map.scaleMap("ZOOM+",0.5f);
           }
           if(tmpDelta < 0)
           {
                m_map.scaleMap("ZOOM-",0.5f);
           }
           m_updateTime = elapseTime;
        }
        float tmpStep = 50;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            m_map.scrollMap("HAUT",tmpStep);
            m_updateTime = elapseTime;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_map.scrollMap("BAS",tmpStep);
            m_updateTime = elapseTime;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            m_map.scrollMap("GAUCHE",tmpStep);
            m_updateTime = elapseTime;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_map.scrollMap("DROITE",tmpStep);
            m_updateTime = elapseTime;
        }
    }


}

Editeur::~Editeur()
{
    //dtor
}
