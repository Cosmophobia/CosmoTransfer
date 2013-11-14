#include "WidgetWindowNewMap.h"

WidgetWindowNewMap::WidgetWindowNewMap(sf::Vector2f position):
    m_position(position),
    m_nbrX(10),
    m_nbrY(10)

{
    std::cout<<"In Ctor - WidgetMenu"<<std::endl;


    //Texture
    m_texture = new sf::Texture;
    if(!m_texture->loadFromFile("images/Gui/GuiNew.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    std::cout<<"In Ctor ---- Texture OK"<<std::endl;


    //Font
    m_font = new sf::Font;
    if(!m_font->loadFromFile("images/Font/BAUHS93.TTF"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    std::cout<<"In Ctor ---- Font OK"<<std::endl;

    setWidget();

    std::cout<<"Out Ctor - WidgetMenu"<<std::endl;
}

void WidgetWindowNewMap::draw(sf::RenderWindow *f)
{
        for(int i = 0; i < 4; i++)
        {
            f->draw(m_bouton[i]);
            if(i<4)
            {
                f->draw(m_texte[i]);
            }
        }
}

void WidgetWindowNewMap::update(sf::Vector2i mouseLocalPosition)
{
    for(int i = 0; i < 5; i++)
    {
        if(m_bouton[i].getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
        {
            //highLIGHT
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(i==0)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(0,24*2,24,24));
                   if(m_nbrX > 10)
                   {
                       m_nbrX -= 1;
                       m_texte[1].setString(int2string(m_nbrX));
                   }

                }
                if(i==2)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(0,24*2,24,24));
                   if(m_nbrX > 10)
                   {
                       m_nbrY -= 1;
                       m_texte[2].setString(int2string(m_nbrY));
                   }
                }
                if(i==1)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(24,24*2,24,24));
                   if(m_nbrX < 100)
                   {
                       m_nbrX += 1;
                       m_texte[1].setString(int2string(m_nbrX));
                   }
                }
                if(i==3)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(24,24*2,24,24));
                   if(m_nbrX < 100)
                   {
                       m_nbrY += 1;
                       m_texte[2].setString(int2string(m_nbrY));
                   }
                }


            }
            //OVER
            else
            {
                if(i==0)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(0,24*1,24,24));
                }
                if(i==2)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(0,24*1,24,24));
                }
                if(i==1)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(24,24*1,24,24));
                }
                if(i==3)
                {
                   m_bouton[i].setTextureRect(sf::IntRect(24,24*1,24,24));
                }
            }
        }
        //Normal
        else
        {
            if(i==0)
            {
               m_bouton[i].setTextureRect(sf::IntRect(0,24*0,24,24));
            }
            if(i==2)
            {
               m_bouton[i].setTextureRect(sf::IntRect(0,24*0,24,24));
            }
            if(i==1)
            {
               m_bouton[i].setTextureRect(sf::IntRect(24,24*0,24,24));
            }
            if(i==3)
            {
               m_bouton[i].setTextureRect(sf::IntRect(24,24*0,24,24));
            }

        }
    }
    if(m_texte[0].getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout<<"CreateMove"<<std::endl;
            setWidgetPosition(sf::Vector2f(mouseLocalPosition.x-10,mouseLocalPosition.y-10));
        }

    }

    if(m_texte[3].getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
    {
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
         {
            std::cout<<"NEW MAP !!"<<std::endl;
         }
    }


}

void WidgetWindowNewMap::setWidgetPosition(sf::Vector2f position)
{
    m_position = position;

    m_texte[0].setPosition(sf::Vector2f(m_position.x,m_position.y));

    m_texte[1].setPosition(sf::Vector2f( m_position.x + 10 ,m_position.y + m_texte[0].getGlobalBounds().height+20 ));

    m_bouton[0].setPosition(sf::Vector2f(m_position.x+5 + m_texte[1].getGlobalBounds().width+10,m_position.y+m_texte[0].getGlobalBounds().height+20));
    m_bouton[1].setPosition(sf::Vector2f(m_position.x+5+m_texte[1].getGlobalBounds().width+10+m_bouton[0].getGlobalBounds().width+5,m_position.y+m_texte[0].getGlobalBounds().height+20));

    m_texte[2].setPosition(sf::Vector2f(m_position.x + 10 , m_position.y + m_texte[0].getGlobalBounds().height + m_texte[1].getGlobalBounds().height +20+20));

    m_bouton[2].setPosition(sf::Vector2f(m_position.x +5 + m_texte[2].getGlobalBounds().width + 10 , m_position.y + m_texte[1].getGlobalBounds().height+m_texte[0].getGlobalBounds().height+20+20));
    m_bouton[3].setPosition(sf::Vector2f(m_position.x +5 + m_texte[2].getGlobalBounds().width + 10 + m_bouton[2].getGlobalBounds().width + 5,m_position.y+m_texte[1].getGlobalBounds().height+m_texte[0].getGlobalBounds().height+20+20));

    m_texte[3].setPosition(sf::Vector2f( m_position.x + 5 , m_position.y + m_texte[2].getGlobalBounds().height + m_texte[1].getGlobalBounds().height + m_texte[0].getGlobalBounds().height + 60));

}

int WidgetWindowNewMap::getButtonOnMouseLocation(sf::Vector2i mouseLocalPosition)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if(m_texte[i].getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
        {
            return i;
        }
    }
    return -1;
}
sf::Vector2i WidgetWindowNewMap::getSelectedMapSize()
{
    return sf::Vector2i(m_nbrX,m_nbrY);
}


WidgetWindowNewMap::~WidgetWindowNewMap()
{
    delete m_font;
    m_font = 0;
    delete m_texture;
    m_texture = 0;
}

void WidgetWindowNewMap::setWidget()
{
    for(int i = 0; i < 4; i++)
    {
        m_bouton[i].setSize(sf::Vector2f(24,24));
        m_bouton[i].setTexture(m_texture);
    }

    m_texte[0].setFont(*m_font);
    m_texte[0].setString("New Map");
    m_texte[0].setCharacterSize(20u);
    m_texte[0].setColor(sf::Color::Cyan);

    m_texte[1].setFont(*m_font);
    m_texte[1].setString(int2string(m_nbrX));
    m_texte[1].setCharacterSize(17u);
    m_texte[1].setColor(sf::Color::Cyan);

    m_bouton[0].setTextureRect(sf::IntRect(0,0,24,24));
    m_bouton[1].setTextureRect(sf::IntRect(24,0,24,24));


    m_texte[2].setFont(*m_font);
    m_texte[2].setString(int2string(m_nbrY));
    m_texte[2].setCharacterSize(17u);
    m_texte[2].setColor(sf::Color::Cyan);


    m_bouton[2].setTextureRect(sf::IntRect(0,0,24,24));
    m_bouton[2].setPosition(sf::Vector2f(m_position.x +5 + m_texte[2].getGlobalBounds().width + 10 , m_position.y + m_texte[1].getGlobalBounds().height+m_texte[0].getGlobalBounds().height+20+20));
    m_bouton[3].setTextureRect(sf::IntRect(24,0,24,24));



    m_texte[3].setFont(*m_font);
    m_texte[3].setString("OK");
    m_texte[3].setCharacterSize(20u);
    m_texte[3].setColor(sf::Color::Cyan);

    setWidgetPosition(m_position);
}




std::string WidgetWindowNewMap::int2string(int i)
{
  std::ostringstream os;
  os << i;
  return os.str();
}
