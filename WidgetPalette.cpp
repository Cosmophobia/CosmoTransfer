#include "WidgetPalette.h"

WidgetPalette::WidgetPalette(sf::Vector2f position):
    m_position(position),
    m_nbrTexture(5)
{
    //Load Texture Fond
    m_texture = new sf::Texture;
    if(!m_texture->loadFromFile("images/Gui/GuiPalette.png"))
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
    std::cout<<"In Ctor ---- FONT OK"<<std::endl;

    //Load Texture palette
    m_tileSetTexture[0].initTexture(0, "Mur", sf::Vector2i(96,96), sf::Vector2i(6,3), "images/TileSet/tileSet96x96Mur.png");
    m_tileSetTexture[1].initTexture(1, "Sol", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Sol.png");
    m_tileSetTexture[2].initTexture(2, "Special", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Special.png");
    m_tileSetTexture[3].initTexture(3, "Monstre", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Monstre.png");
    m_tileSetTexture[4].initTexture(4, "Meta", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Meta.png");

    m_upddateTime = sf::seconds(0);
    setWidget();
}

void WidgetPalette::draw(sf::RenderWindow *f)
{
    f->draw(m_fond);
    f->draw(m_texte[0]);
    for(int i = 0; i < 2; i++)
        {


            f->draw(m_bouton[i]);
        }
    for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
    {
        for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
        {
            //Draw Palette
            f->draw(*m_tilePalette[i][j]);
        }
    }
    f->draw(m_selectionTile);
}


void WidgetPalette::update(sf::Vector2i mouseLocalPosition, sf::Time elapseTime)
{
    for(int n = 0; n < 2; n++)
    {
        if(m_bouton[n].getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
        {
            //highLIGHT
            if(elapseTime > m_upddateTime+sf::milliseconds(300))
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if(n==0)
                    {
                        //Si bouton up est appuyé
                        m_bouton[n].setTextureRect(sf::IntRect(0,48+15*2,20,15));
                        //Détruire l'ancienne palette
                        for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
                        {
                            for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
                            {
                                delete m_tilePalette[i][j];
                                m_tilePalette[i][j] = 0;

                            }
                        }
                        std::cout<<"Delete Old OK"<<std::endl;
                        //Incrementer la palette selectionné
                        m_selectedTexture -= 1;
                        if(m_selectedTexture == -1)
                        {
                            m_selectedTexture = m_nbrTexture-1;
                        }
                        std::cout<<"New m_select OK : "<<m_selectedTexture<<std::endl;
                        //Construire la nouvelle palette
                        m_texte[0].setString(m_tileSetTexture[m_selectedTexture].getName());

                        for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
                        {
                            for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
                            {
                                m_tilePalette[i][j] = new SuperTile(m_tileSetTexture[m_selectedTexture], sf::Vector2i(i,j), sf::Vector2i(i,j));
                                m_tilePalette[i][j]->setAutoScaleX(288.f,m_tileSetTexture[m_selectedTexture].getTileNumber().x);
                                m_tilePalette[i][j]->setIdGridPosition(sf::Vector2f(m_position.x,m_position.y+48));
                                std::cout<<" OK New Palette : "<<i<<" "<<j<<std::endl;
                            }
                        }

                    }
                    if(n==1)
                    {
                       m_bouton[n].setTextureRect(sf::IntRect(20,48+15*2,20,15));

                        //Détruire l'ancienne palette
                        for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
                        {
                            for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
                            {
                                delete m_tilePalette[i][j];
                                m_tilePalette[i][j] = 0;

                            }
                        }
                        std::cout<<"Delete Old OK"<<std::endl;
                        //Incrementer la palette selectionné
                        m_selectedTexture += 1;
                        if(m_selectedTexture == m_nbrTexture)
                        {
                            m_selectedTexture = 0;
                        }
                        std::cout<<"New m_select OK : "<<m_selectedTexture<<std::endl;
                        //Construire la nouvelle palette
                        m_texte[0].setString(m_tileSetTexture[m_selectedTexture].getName());

                        for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
                        {
                            for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
                            {
                                m_tilePalette[i][j] = new SuperTile(m_tileSetTexture[m_selectedTexture], sf::Vector2i(i,j), sf::Vector2i(i,j));
                                m_tilePalette[i][j]->setAutoScaleX(288.f,m_tileSetTexture[m_selectedTexture].getTileNumber().x);
                                m_tilePalette[i][j]->setIdGridPosition(sf::Vector2f(m_position.x,m_position.y+48));
                                std::cout<<" OK New Palette : "<<i<<" "<<j<<std::endl;
                            }
                        }
                    }
                    m_upddateTime = elapseTime;

                }
                //OVER
                else
                {
                    if(n==0)
                    {
                       m_bouton[n].setTextureRect(sf::IntRect(0,48+15*1,20,15));
                    }
                    if(n==1)
                    {
                       m_bouton[n].setTextureRect(sf::IntRect(20,48+15*1,20,15));
                    }
                }
            }

        }
        //Normal
        else
        {
            if(n==0)
            {
               m_bouton[n].setTextureRect(sf::IntRect(0,48,20,15));
            }
            if(n==1)
            {
               m_bouton[n].setTextureRect(sf::IntRect(20,48,20,15));
            }
        }
    }
    if(elapseTime > m_upddateTime+sf::milliseconds(300))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(sf::FloatRect(m_position.x,m_position.y,72,48).contains(mouseLocalPosition.x,mouseLocalPosition.y))
            {
                std::cout<<"CreateMove"<<std::endl;
                setWidgetPosition(sf::Vector2f(mouseLocalPosition.x-24,mouseLocalPosition.y-24));
            }

            for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++)
            {
                for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++)
                {
                    if(m_tilePalette[i][j]->getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
                    {
                        std::cout<<"Tile :"<<i<<","<<j<<std::endl;
                        m_selectionTile.setTileSetTexture(m_tileSetTexture[m_selectedTexture]);
                        m_selectionTile.setId(sf::Vector2i(m_tilePalette[i][j]->getId().x,m_tilePalette[i][j]->getId().y));
                    }
                }
            }
            m_upddateTime = elapseTime;
        }
    }


    if(elapseTime > m_upddateTime+sf::milliseconds(300))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            m_selectionTile.rotate(90.f);
            m_upddateTime = elapseTime;
        }
    }

}



void WidgetPalette::setWidgetPosition(sf::Vector2f position)
{
    m_position = position;
    m_fond.setPosition(sf::Vector2f (m_position.x,m_position.y));


    m_texte[0].setPosition(sf::Vector2f(m_position.x + 192,m_position.y+10));

    m_bouton[1].setPosition(sf::Vector2f(m_position.x + 159,m_position.y+8));
    m_bouton[0].setPosition(sf::Vector2f(m_position.x + 159,m_position.y+25));

    for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
    {
        for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
        {
            m_tilePalette[i][j]->setAutoScaleX(288.f,m_tileSetTexture[m_selectedTexture].getTileNumber().x);
            m_tilePalette[i][j]->setIdGridPosition(sf::Vector2f(m_position.x,m_position.y+48));

        }
    }
    m_selectionTile.setScale(sf::Vector2f(0.4,0.4));
    m_selectionTile.setPosition(sf::Vector2f(m_position.x+130,m_position.y+24));
}

SuperTile WidgetPalette::getSelectTile()
{
    return m_selectionTile;
}


WidgetPalette::~WidgetPalette()
{
    delete m_font;
    m_font = 0;
    delete m_texture;
    m_texture = 0;
    for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
    {
        for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
        {
            delete m_tilePalette[i][j];
            m_tilePalette[i][j] = 0;

        }
    }
}

void WidgetPalette::setWidget()
{
    //texture selectionné par default
    m_selectedTexture = 0;
    std::cout<<"In Set Widget"<<std::endl;
    for(int i = 0; i < 2; i++)
    {
        m_bouton[i].setSize(sf::Vector2f(20,15));
        m_bouton[i].setTexture(m_texture);
    }
    m_bouton[0].setTextureRect(sf::IntRect(0,0,24,24));
    m_bouton[1].setTextureRect(sf::IntRect(24,0,24,24));
    std::cout<<"Bouton set OK"<<std::endl;

    m_fond.setSize(sf::Vector2f(288,48));
    m_fond.setTexture(m_texture);
    m_fond.setTextureRect(sf::IntRect(0,0,288,48));
    std::cout<<"Fond set"<<std::endl;

    m_texte[0].setFont(*m_font);
    m_texte[0].setString(m_tileSetTexture[m_selectedTexture].getName());
    m_texte[0].setCharacterSize(20u);
    m_texte[0].setColor(sf::Color::Green);
    std::cout<<"Texte Set"<<std::endl;

    for(int i = 0 ; i < m_tileSetTexture[m_selectedTexture].getTileNumber().x ; i++ )
    {
        for(int j = 0 ; j < m_tileSetTexture[m_selectedTexture].getTileNumber().y ; j++ )
        {
            std::cout<<"set Palette : "<<std::endl;
            m_tilePalette[i][j] = new SuperTile(m_tileSetTexture[m_selectedTexture], sf::Vector2i(i,j), sf::Vector2i(i,j));

            std::cout<<" OK Set Palette : "<<i<<" "<<j<<std::endl;
        }
    }
    std::cout<<"set selection tile : "<<std::endl;
    m_selectionTile.setTileSetTexture(m_tileSetTexture[m_selectedTexture]);

    std::cout<<"set selection tile : "<<std::endl;
    m_selectionTile.setTilePosition(sf::Vector2i (0,0));
    std::cout<<"set selection tile : "<<std::endl;
    m_selectionTile.setId(sf::Vector2i (1,0));
    m_selectionTile.setOrigin(sf::Vector2f(m_selectionTile.getOrigin().x+(m_tileSetTexture[m_selectionTile.getTileSetTextureID()].getTileSize().x/2),
                                                   m_selectionTile.getOrigin().y+(m_tileSetTexture[m_selectionTile.getTileSetTextureID()].getTileSize().y/2)));
    std::cout<<"OK set selection tile ! "<<std::endl;


    setWidgetPosition(m_position);
}
