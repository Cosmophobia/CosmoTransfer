#include "WidgetMenu.h"

WidgetMenu::WidgetMenu(sf::Vector2f position, sf::Vector2f taille):
    m_position(position),
    m_isActive(false),
    m_btMenu(taille),
    m_widgetSystem(0)
{
    std::cout<<"In Ctor - WidgetMenu"<<std::endl;
    m_texture = new sf::Texture;
    if(!m_texture->loadFromFile("images/Gui/GuiMenu.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    std::cout<<"In Ctor ---- Texture OK"<<std::endl;
    m_updateTime = sf::seconds(0);
    setBtMenu();
    std::cout<<"In Ctor ---- btMenu OK"<<std::endl;

    std::cout<<"Out Ctor - WidgetMenu"<<std::endl;
}

void WidgetMenu::build(sf::Vector2f position)
{

}

void WidgetMenu::draw(sf::RenderWindow *f)
{
    f->draw(m_btMenu);
    m_widgetSystem->draw(f);
}

void WidgetMenu::update(sf::Vector2i mouseLocalPosition, sf::Time elapseTime)
{
        if(m_btMenu.getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
        {
            //HIGHLIGHT
            if(elapseTime > m_updateTime+sf::milliseconds(300))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    std::cout<<"left press"<<std::endl;
                    m_btMenu.setTextureRect(sf::IntRect(0,72*2,72,72));
                    m_isActive = !m_isActive;
                    std::cout<<"menu Active "<<m_isActive<<std::endl;
                    m_updateTime = elapseTime;
                }
                //OVER
                else
                {
                    m_btMenu.setTextureRect(sf::IntRect(0,72*1,72,72));
                    m_btMenu.rotate(2);
                }
            }
        }
        //Normal
        else
        {
            m_btMenu.setTextureRect(sf::IntRect(0,72*0,72,72));
        }
    if(m_isActive == true && m_widgetSystem->getPosition().y < 4)
    {
        m_widgetSystem->deplacement(sf::Vector2f (0,6));
    }

    if(m_isActive == false && m_widgetSystem->getPosition().y > -150 )
    {
        m_widgetSystem->deplacement(sf::Vector2f (0,-6));
    }
    m_widgetSystem->update(mouseLocalPosition, elapseTime);

}

void WidgetMenu::setChildWidget(WidgetSystem &widgetSystem)
{
    m_widgetSystem = &widgetSystem;
}


WidgetMenu::~WidgetMenu()
{
    delete m_texture;
    m_texture = 0;
}



void WidgetMenu::setBtMenu()
{
    m_btMenu.setOrigin(sf::Vector2f(m_btMenu.getOrigin().x+(72/2),
                                    m_btMenu.getOrigin().y+(72/2)));
    m_btMenu.setScale(sf::Vector2f (1,1));
    m_btMenu.setPosition(sf::Vector2f(m_position.x,m_position.y));
    m_btMenu.setTexture(m_texture);
    m_btMenu.setTextureRect(sf::IntRect(0,0,72,72));
}
