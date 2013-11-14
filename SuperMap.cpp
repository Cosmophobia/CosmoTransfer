#include "SuperMap.h"

SuperMap::SuperMap():
    m_nbrTexture(5),
    m_mapNbrTile(sf::Vector2i(0,0)),
    m_position(sf::Vector2f(0,0))
{
    std::cout<<"IN Ctor SUPER MAP"<<std::endl;
    m_tileSetTexture[0].initTexture(0, "Mur", sf::Vector2i(96,96), sf::Vector2i(6,3), "images/TileSet/tileSet96x96Mur.png");
    m_tileSetTexture[1].initTexture(1, "Sol", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Sol.png");
    m_tileSetTexture[2].initTexture(2, "Special", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Special.png");
    m_tileSetTexture[3].initTexture(3, "Monstre", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Monstre.png");
    m_tileSetTexture[4].initTexture(4, "Meta", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Meta.png");
}
SuperMap::SuperMap(sf::Vector2i mapNbrTile,sf::Vector2f position):
    m_nbrTexture(5),
    m_mapNbrTile(mapNbrTile),
    m_position(position)
{
    std::cout<<"IN Ctor SUPER MAP"<<std::endl;
    m_tileSetTexture[0].initTexture(0, "Mur", sf::Vector2i(96,96), sf::Vector2i(6,3), "images/TileSet/tileSet96x96Mur.png");
    m_tileSetTexture[1].initTexture(1, "Sol", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Sol.png");
    m_tileSetTexture[2].initTexture(2, "Special", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Special.png");
    m_tileSetTexture[3].initTexture(3, "Monstre", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Monstre.png");
    m_tileSetTexture[4].initTexture(4, "Meta", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Meta.png");
}



void SuperMap::build(sf::Vector2i mapNbrTile, sf::Vector2f position)
{
    std::cout<<"IN BUILD SUPER MAP"<<std::endl;
    m_mapNbrTile = mapNbrTile;
    m_position = position;
    for(int i = 0; i < m_mapNbrTile.x ; i++)
    {
        for(int j = 0; j < m_mapNbrTile.y ; j++)
        {
            //Map Tableau
            std::cout<<"IN BUILD TabMap "<<i<<" "<<j<<std::endl;
            m_tabMap[i][j] = new SuperTile(m_tileSetTexture[0],sf::Vector2i(i,j),sf::Vector2i(1,0));
            m_tabMap[i][j]->setScale(sf::Vector2f(1,1));
            m_tabMap[i][j]->setCentreOrigin();
            m_tabMap[i][j]->setMapPosition(m_position);


        }
    }

}

void SuperMap::draw(sf::RenderWindow *fenetre)
{
    //DRAW -> tabMap
    for(int i = 0; i < m_mapNbrTile.x ; i++ )
    {
        for(int j = 0; j < m_mapNbrTile.y ; j++)
        {
            fenetre->draw(*m_tabMap[i][j]);

        }
    }
    //DRAW -> tabMonstre
    for(int i = 0; i < m_tabMonstre.size(); i++)
    {
        if(m_tabMonstre[i] != 0)
        {
            fenetre->draw(*m_tabMonstre[i]);
        }

    }

}

sf::Vector2i SuperMap::getMouseTilePosition(sf::Vector2i mouseLocalPosition)
{
    for(int i = 0; i < m_mapNbrTile.x ; i++)
    {
        for(int j = 0; j < m_mapNbrTile.y ; j++)
        {
            if(m_tabMap[i][j]->getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
            {
                return sf::Vector2i(i,j);
            }
        }
    }
    return sf::Vector2i(-1,-1);
}

void SuperMap::setGridPosition(sf::Vector2f positionMap)
{
    for(int i = 0; i < m_mapNbrTile.x ; i++)
    {
        for(int j = 0; j < m_mapNbrTile.y ; j++)
        {
            m_tabMap[i][j]->setMapPosition(positionMap);
        }
    }
}

void SuperMap::setTile(sf::Vector2i tilePosition, SuperTile tile)
{
    int tmpTextureID = tile.getTileSetTextureID();
    //sur map
    if(tmpTextureID == 0 || tmpTextureID == 1 || tmpTextureID == 2)
    {
        m_tabMap[tilePosition.x][tilePosition.y]->setTileSetTexture(m_tileSetTexture[tmpTextureID]);
        m_tabMap[tilePosition.x][tilePosition.y]->setId(tile.getId());
        m_tabMap[tilePosition.x][tilePosition.y]->setRotation(tile.getRotation());
    }
    //sur Perso
    if(tmpTextureID == 3)
    {
        m_tabMonstre.push_back(new SuperTile(m_tileSetTexture[tmpTextureID],tilePosition,tile.getId()));
        m_tabMonstre[m_tabMonstre.size()-1]->setScale(sf::Vector2f(0.5,0.5));
        m_tabMonstre[m_tabMonstre.size()-1]->setOrigin(sf::Vector2f(m_tabMonstre[m_tabMonstre.size()-1]->getOrigin().x+(m_tileSetTexture[m_tabMonstre[m_tabMonstre.size()-1]->getTileSetTextureID()].getTileSize().x/2),
                                                                    m_tabMonstre[m_tabMonstre.size()-1]->getOrigin().y+(m_tileSetTexture[m_tabMonstre[m_tabMonstre.size()-1]->getTileSetTextureID()].getTileSize().y/2)));
        m_tabMonstre[m_tabMonstre.size()-1]->setMapPosition(m_position);
    }


}

SuperMap::~SuperMap()
{
    for(int i = 0; i < m_mapNbrTile.x ; i++ )
    {
        for(int j = 0; j < m_mapNbrTile.y ; j++)
        {
            delete m_tabMap[i][j];
            m_tabMap[i][j] = 0 ;
        }
    }
}

void SuperMap::triTableauDyn()
{
    std::cout<<"Enter triTab"<<std::endl;
    int tmpTailleMonstre = 0;
    SuperTile *tmpMonstrePointeur = 0;
    bool modif = false;
    do
    {
        modif = false;
        tmpMonstrePointeur = 0;
        tmpTailleMonstre = m_tabMonstre.size()-1;
        for(int i=tmpTailleMonstre; i >= 0 ; i--)
        {
            if(i == tmpTailleMonstre && m_tabMonstre[i] == 0)
            {
                m_tabMonstre.pop_back();
            }
            if(m_tabMonstre[i]!=0 && tmpMonstrePointeur == 0)
            {
            tmpMonstrePointeur = m_tabMonstre[i];
            }

            if(m_tabMonstre[i] == 0 && i < tmpTailleMonstre)
            {
                m_tabMonstre[i] = tmpMonstrePointeur;
                tmpMonstrePointeur = 0;
                m_tabMonstre.pop_back();
                modif = true;
            }
        }
    }while(modif);
    std::cout<<"Exit triTab : OK"<<std::endl;


}
