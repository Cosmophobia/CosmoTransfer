#include "WidgetSystem.h"

WidgetSystem::WidgetSystem(sf::Vector2f position, sf::Vector2f taille):
    m_position(position),
    m_isActive(false),
    m_isWidgetNewMapActive(false),
    m_isWidgetPaletteActive(false)
{
    std::cout<<"In Ctor - WidgetSystem"<<std::endl;
    m_texture = new sf::Texture;
    if(!m_texture->loadFromFile("images/Gui/GuiEditor.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    std::cout<<"In Ctor ---- Texture OK"<<std::endl;
    m_updateTime = sf::seconds(0);
    setBouton();
    std::cout<<"In Ctor ---- Bouton OK"<<std::endl;

    std::cout<<"Out Ctor - WidgetSystem"<<std::endl;
}

//Create
void WidgetSystem::build(sf::Vector2f position)
{
    std::cout<<"In Build - WidgetSystem"<<std::endl;


    std::cout<<"In Build ---- Bouton OK"<<std::endl;


    std::cout<<"Out Build - WidgetSystem"<<std::endl;
}


//Draw
void WidgetSystem::draw(sf::RenderWindow *f)
{
    for(int i = 0; i < 4; i++)
    {
        f->draw(m_bouton[i]);
    }
    if(m_isWidgetNewMapActive)
    {
        m_widgetNewMap->draw(f);
    }
    if(m_isWidgetPaletteActive)
    {
        m_widgetPalette->draw(f);
    }

}

//Update
void WidgetSystem::update(sf::Vector2i mouseLocalPosition, sf::Time elapseTime)
{
    for(int i = 0; i < 4; i++)
    {

        if(m_bouton[i].getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
        {
            //HIGHLIGHT
            if(elapseTime > m_updateTime+sf::milliseconds(300))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    m_bouton[i].setTextureRect(sf::IntRect(96*i,96*2,96,96));
                    std::cout<<"button press"<<std::endl;
                    if(i==2)
                    {
                        if(m_isWidgetNewMapActive)
                        {
                            m_isWidgetNewMapActive = false;
                        }
                        else
                        {
                            m_isWidgetNewMapActive = true;
                        }

                    }
                    if(i==3)
                    {
                        if(m_isWidgetPaletteActive)
                        {
                            m_isWidgetPaletteActive = false;
                        }
                        else
                        {
                            m_isWidgetPaletteActive = true;
                        }

                    }
                    m_updateTime = elapseTime;
                }
                //OVER
                else
                {
                    m_bouton[i].setTextureRect(sf::IntRect(96*i,96*1,96,96));
                }
            }

        }
        //NORMAL
        else
        {
            m_bouton[i].setTextureRect(sf::IntRect(96*i,96*0,96,96));
        }
    }
    if(m_isWidgetNewMapActive)
    {
        m_widgetNewMap->update(mouseLocalPosition);
    }
    if(m_isWidgetPaletteActive)
    {
        m_widgetPalette->update(mouseLocalPosition, elapseTime);
    }

}


void WidgetSystem::setNewMapWidget(WidgetWindowNewMap &widgetNewMap)
{
    m_widgetNewMap = &widgetNewMap;
}
void WidgetSystem::setPaletteWidget(WidgetPalette &widgetPalette)
{
    m_widgetPalette = &widgetPalette;
}

void WidgetSystem::deplacement(sf::Vector2f d)
{
    for(int i = 0; i < 4; i++)
    {
        m_bouton[i].move(d);
    }
    m_position = m_bouton[0].getPosition();
}


sf::Vector2f WidgetSystem::getPosition()
{
    return m_position;
}
void WidgetSystem::setPosition(sf::Vector2f p)
{
    m_position = p;
    for(int i = 0; i< 4 ; i++)
    {
        m_bouton[i].setPosition(sf::Vector2f(p.x+m_bouton[i].getGlobalBounds().width*i+10*i,p.y));
    }

}


WidgetSystem::~WidgetSystem()
{
    delete m_texture;
    m_texture = 0;
}


void WidgetSystem::setBouton()
{
    for(int i = 0; i < 4; i++)
    {
        m_bouton[i].setSize(sf::Vector2f (96,96));
        m_bouton[i].setScale(sf::Vector2f (1,1));
        m_bouton[i].setPosition(sf::Vector2f(m_position.x+m_bouton[i].getGlobalBounds().width*i+10*i,m_position.y));
        m_bouton[i].setTexture(m_texture);
        m_bouton[i].setTextureRect(sf::IntRect(96*i,0,96,96));
    }
}
