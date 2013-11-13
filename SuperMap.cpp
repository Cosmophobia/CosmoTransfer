#include "SuperMap.h"

SuperMap::SuperMap():
    m_nbrTexture(5),
    m_mapNbrTile(sf::Vector2i(0,0)),
    m_position(sf::Vector2f(0,0)),
    m_isMapBuild(false),
    m_startPointBuild(false)
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
    m_position(position),
    m_isMapBuild(false),
    m_startPointBuild(false)
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
            m_tabMap[i][j]->setScale(sf::Vector2f(0.5,0.5));
            m_tabMap[i][j]->setOrigin(sf::Vector2f(m_tabMap[i][j]->getOrigin().x+(m_tileSetTexture[m_tabMap[i][j]->getTileSetTextureID()].getTileSize().x/2),
                                                   m_tabMap[i][j]->getOrigin().y+(m_tileSetTexture[m_tabMap[i][j]->getTileSetTextureID()].getTileSize().y/2)));
            m_tabMap[i][j]->setMapPosition(m_position);
            m_isMapBuild = true;


        }
    }

}

void SuperMap::deleteMap()
{
    for(int i = 0; i < m_mapNbrTile.x ; i++ )
    {
        for(int j = 0; j < m_mapNbrTile.y ; j++)
        {
            delete m_tabMap[i][j];
            m_tabMap[i][j] = 0 ;
        }
    }
    for(int i = 0; i < m_tabMonstre.size(); i++)
    {
            delete m_tabMonstre[i];
            m_tabMonstre[i] = 0 ;
    }
    if(m_startPointBuild == true)
    {
        delete m_startPlayerPoint;
        m_startPlayerPoint = 0 ;
        m_startPointBuild = false;
    }
}

void SuperMap::draw(sf::RenderWindow *fenetre)
{

    if(m_isMapBuild = true)
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
        //DRAW -> Perso
        if(m_startPointBuild == true)
        {
            fenetre->draw(*m_startPlayerPoint);
        }
    }


}
void SuperMap::save(std::string nomMap)
{
    std::cout << "IN: SAVE" << std::endl;
    std::string nomFichier("map/"+nomMap+".map");
    std::ofstream monFlux(nomFichier.c_str());

    if(monFlux)
    {
        std::cout << "IN: FLUX" << std::endl;
        monFlux <<nomMap<<std::endl;
        monFlux <<m_mapNbrTile.x<<" "<<m_mapNbrTile.y<<std::endl;

        //Save TabMap
        for(int i = 0; i < m_mapNbrTile.x ; i++)
        {
            for(int j = 0; j < m_mapNbrTile.y ; j++)
            {
                int tmpX = m_tabMap[i][j]->getId().x;
                int tmpY = m_tabMap[i][j]->getId().y;
                int tmpTextureID = m_tabMap[i][j]->getTileSetTextureID();

                monFlux <<tmpX<<" "<<tmpY<<" "<<tmpTextureID<<" "<<m_tabMap[i][j]->getRotation()<<" ";
            }
            monFlux << std::endl;
        }
        std::cout << "IN: FLUX MAP OK" << std::endl;
        //Save Enemie
        int tmpNombreMonstre = m_tabMonstre.size();
        monFlux <<tmpNombreMonstre<<std::endl;
        for(int i = 0 ; i < tmpNombreMonstre ; i++)
        {
            int tmpX = m_tabMonstre[i]->getId().x;
            int tmpY = m_tabMonstre[i]->getId().y;
            int tmpPosX = m_tabMonstre[i]->getTilePosition().x;
            int tmpPosY = m_tabMonstre[i]->getTilePosition().y;
            int tmpTextureID = m_tabMonstre[i]->getTileSetTextureID();

            monFlux <<tmpX<<" "<<tmpY<<" "<<tmpPosX<<" "<<tmpPosY<<" "<<tmpTextureID<<" "<<m_tabMonstre[i]->getRotation()<<" ";
        }
        monFlux << std::endl;
        std::cout << "IN: FLUX MONSTRE OK" << std::endl;
        //Save Perso
        int tmpX = m_startPlayerPoint->getId().x;
        int tmpY = m_startPlayerPoint->getId().y;
        int tmpPosX = m_startPlayerPoint->getTilePosition().x;
        int tmpPosY = m_startPlayerPoint->getTilePosition().y;
        int tmpTextureID = m_startPlayerPoint->getTileSetTextureID();

        monFlux <<tmpX<<" "<<tmpY<<" "<<tmpPosX<<" "<<tmpPosY<<" "<<tmpTextureID<<" "<<m_startPlayerPoint->getRotation()<<" ";
        std::cout << "IN: FLUX PERSO OK" << std::endl;
        //SAVE FIN
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
void SuperMap::load(std::string nomMap)
{
    std::string monFichier("map/"+nomMap+".map");
    std::ifstream monInFlux(monFichier.c_str());

    if(monInFlux)
    {
      //L'ouverture s'est bien passee, on peut donc lire

      std::string tmpTitre = "pas de titre";
      int tmpMapNbrTileX = 0;
      int tmpMapNbrTileY = 0;
      int tmpTileIDx = 0;
      int tmpTileIDy = 0;
      int tmpTextureID = 0;
      int tmpTilePositionX = 0;
      int tmpTilePositionY = 0;
      float tmpRotation = 0;

      std::cout<<"In monInFlux"<<std::endl;
      monInFlux >> tmpTitre;
      monInFlux >> tmpMapNbrTileX;
      monInFlux >> tmpMapNbrTileY;
      m_mapNbrTile = sf::Vector2i(tmpMapNbrTileX,tmpMapNbrTileY);

      std::cout<<tmpTitre<<std::endl;
      std::cout<<tmpMapNbrTileX<<"/"<<tmpMapNbrTileY<<std::endl;
      //LOAD MAP
      for(int i = 0; i < m_mapNbrTile.x ; i++)
      {
            for(int j = 0; j < m_mapNbrTile.y ; j++)
            {
                monInFlux >> tmpTileIDx;
                monInFlux >> tmpTileIDy;
                monInFlux >> tmpTextureID;
                monInFlux >> tmpRotation;
                std::cout<<"TileMap["<<i<<"]["<<j<<"] ID : ["<<tmpTileIDx<<","<<tmpTileIDy<<" / texture : "<<tmpTextureID<<" / rotation : "<<tmpRotation<<std::endl;

                m_tabMap[i][j] = new SuperTile(m_tileSetTexture[tmpTextureID],sf::Vector2i(i,j),sf::Vector2i(tmpTileIDx,tmpTileIDy));
                m_tabMap[i][j]->setScale(sf::Vector2f(0.5,0.5));
                m_tabMap[i][j]->setOrigin(sf::Vector2f(m_tabMap[i][j]->getOrigin().x+(m_tileSetTexture[m_tabMap[i][j]->getTileSetTextureID()].getTileSize().x/2),
                                                       m_tabMap[i][j]->getOrigin().y+(m_tileSetTexture[m_tabMap[i][j]->getTileSetTextureID()].getTileSize().y/2)));
                m_tabMap[i][j]->setRotation(tmpRotation);
                m_tabMap[i][j]->setMapPosition(m_position);
            }

      }
      //LOAD MONSTRE
      int tmpTabMonstreSize = 0;
      monInFlux >> tmpTabMonstreSize;
      for(int i = 0 ; i < tmpTabMonstreSize ; i++)
      {
          monInFlux >> tmpTileIDx;
          monInFlux >> tmpTileIDy;
          monInFlux >> tmpTilePositionX;
          monInFlux >> tmpTilePositionY;
          monInFlux >> tmpTextureID;
          monInFlux >> tmpRotation;
          m_tabMonstre.push_back(new SuperTile(m_tileSetTexture[tmpTextureID],sf::Vector2i(tmpTilePositionX,tmpTilePositionY),sf::Vector2i(tmpTileIDx,tmpTileIDy)));
          int tmp = m_tabMonstre.size();
          m_tabMonstre[tmp-1]->setScale(sf::Vector2f(0.5,0.5));
          m_tabMonstre[tmp-1]->setOrigin(sf::Vector2f(m_tabMonstre[tmp-1]->getOrigin().x+(m_tileSetTexture[m_tabMonstre[tmp-1]->getTileSetTextureID()].getTileSize().x/2),
                                                      m_tabMonstre[tmp-1]->getOrigin().y+(m_tileSetTexture[m_tabMonstre[tmp-1]->getTileSetTextureID()].getTileSize().y/2)));
          m_tabMonstre[tmp-1]->setMapPosition(m_position);
          m_tabMonstre[tmp-1]->setRotation(tmpRotation);
      }
      //LOAD STARTING POINT
      monInFlux >> tmpTileIDx;
      monInFlux >> tmpTileIDy;
      monInFlux >> tmpTilePositionX;
      monInFlux >> tmpTilePositionY;
      monInFlux >> tmpTextureID;
      monInFlux >> tmpRotation;
      m_startPlayerPoint = new SuperTile(m_tileSetTexture[tmpTextureID],sf::Vector2i(tmpTilePositionX,tmpTilePositionY),sf::Vector2i(tmpTileIDx,tmpTileIDy));
      m_startPlayerPoint->setScale(sf::Vector2f(0.5,0.5));
      m_startPlayerPoint->setOrigin(sf::Vector2f(m_startPlayerPoint->getOrigin().x+(m_tileSetTexture[m_startPlayerPoint->getTileSetTextureID()].getTileSize().x/2),
                                               m_startPlayerPoint->getOrigin().y+(m_tileSetTexture[m_startPlayerPoint->getTileSetTextureID()].getTileSize().y/2)));
      m_startPlayerPoint->setMapPosition(m_position);
      m_startPlayerPoint->setRotation(tmpRotation);
      m_startPointBuild = true;

    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
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

void SuperMap::setTile(sf::Vector2i tilePosition, SuperTile tile, sf::Vector2i mouseLocalPosition)
{
    int tmpTextureID = tile.getTileSetTextureID();
    //sur map
    if(tmpTextureID == 0 || tmpTextureID == 1 || tmpTextureID == 2)
    {
        m_tabMap[tilePosition.x][tilePosition.y]->setTileSetTexture(m_tileSetTexture[tmpTextureID]);
        m_tabMap[tilePosition.x][tilePosition.y]->setId(tile.getId());
        m_tabMap[tilePosition.x][tilePosition.y]->setRotation(tile.getRotation());
    }
    //sur Monstre
    if(tmpTextureID == 3)
    {
        int tmpTabMonstreSize = m_tabMonstre.size();
        bool monstreDelete = false;
        for(int i = 0; i < tmpTabMonstreSize; i++)
        {
            if(m_tabMonstre[i]->getGlobalBounds().contains(mouseLocalPosition.x,mouseLocalPosition.y))
            {
                std::cout<<"Delete Monstre"<<std::endl;
                delete m_tabMonstre[i];
                m_tabMonstre[i] = 0;
                triTableauDyn();
                monstreDelete = true;

            }
        }
        if(monstreDelete == false)
        {
            std::cout<<"Create Monstre"<<std::endl;
            m_tabMonstre.push_back(new SuperTile(m_tileSetTexture[tmpTextureID],tilePosition,tile.getId()));
            tmpTabMonstreSize = m_tabMonstre.size();
            m_tabMonstre[tmpTabMonstreSize-1]->setScale(sf::Vector2f(0.5,0.5));
            m_tabMonstre[tmpTabMonstreSize-1]->setOrigin(sf::Vector2f(m_tabMonstre[tmpTabMonstreSize-1]->getOrigin().x+(m_tileSetTexture[m_tabMonstre[tmpTabMonstreSize-1]->getTileSetTextureID()].getTileSize().x/2),
                                                                      m_tabMonstre[tmpTabMonstreSize-1]->getOrigin().y+(m_tileSetTexture[m_tabMonstre[tmpTabMonstreSize-1]->getTileSetTextureID()].getTileSize().y/2)));
            m_tabMonstre[tmpTabMonstreSize-1]->setMapPosition(m_position);
        }

    }
    //Sur Perso
    if(tmpTextureID == 4)
    {
        bool persoDelete = false;

        if(m_startPointBuild == true)
        {
            std::cout<<"Delete Starting Point"<<std::endl;
            delete m_startPlayerPoint;
            m_startPlayerPoint = 0;
            persoDelete = true;
            m_startPointBuild = false;
        }

        if(persoDelete == false)
        {
            std::cout<<"Create Starting Point"<<std::endl;
            m_startPlayerPoint = new SuperTile(m_tileSetTexture[tmpTextureID],tilePosition,tile.getId());

            m_startPlayerPoint->setScale(sf::Vector2f(0.5,0.5));
            m_startPlayerPoint->setOrigin(sf::Vector2f(m_startPlayerPoint->getOrigin().x+(m_tileSetTexture[m_startPlayerPoint->getTileSetTextureID()].getTileSize().x/2),
                                                       m_startPlayerPoint->getOrigin().y+(m_tileSetTexture[m_startPlayerPoint->getTileSetTextureID()].getTileSize().y/2)));
            m_startPlayerPoint->setMapPosition(m_position);
            m_startPointBuild = true;
        }

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
    for(int i = 0; i < m_tabMonstre.size(); i++)
    {
            delete m_tabMonstre[i];
            m_tabMonstre[i] = 0 ;
    }
    if(m_startPointBuild == true)
    {
        delete m_startPlayerPoint;
        m_startPlayerPoint = 0 ;
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
