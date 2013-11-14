#include "GameMap.h"

GameMap::GameMap()
{
    m_tileSetTexture[0].initTexture(0, "Mur", sf::Vector2i(96,96), sf::Vector2i(6,3), "images/TileSet/tileSet96x96Mur.png");
    m_tileSetTexture[1].initTexture(1, "Sol", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Sol.png");
    m_tileSetTexture[2].initTexture(2, "Special", sf::Vector2i(96,96), sf::Vector2i(5,2), "images/TileSet/tileSet96x96Special.png");
    m_tileSetTexture[3].initTexture(3, "Monstre", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Monstre.png");
    m_tileSetTexture[4].initTexture(4, "Meta", sf::Vector2i(96,96), sf::Vector2i(2,2), "images/TileSet/tileSet96x96Meta.png");
    m_tileSetTexture[5].initTexture(5, "PersoAnimation", sf::Vector2i (96,96), sf::Vector2i (1,3), "images/TileSet/SpriteSetAstro.png");
}

void GameMap::draw(sf::RenderWindow *fenetre, sf::Time elapseTime)
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
        for(int i = 0; i < m_tabMonstre.size(); i++)
        {
            if(m_tabMonstre[i] != 0)
            {
                fenetre->draw(*m_tabMonstre[i]);
            }

        }
        m_player->draw(fenetre,elapseTime);
    }


}

//SYSTEM
void GameMap::load(std::string nomMap)
{
    std::string monFichier("map/"+nomMap+".map");
    std::ifstream monInFlux(monFichier.c_str());

    if(monInFlux)
    {
      //Mise en place des Variables
      std::string tmpTitre = "pas de titre";
      int tmpMapNbrTileX = 0;
      int tmpMapNbrTileY = 0;
      int tmpTileIDx = 0;
      int tmpTileIDy = 0;
      int tmpTextureID = 0;
      int tmpTilePositionX = 0;
      int tmpTilePositionY = 0;
      float tmpRotation = 0;

      //LOAD - TITRE ET TAILLE
      std::cout<<"In monInFlux"<<std::endl;
      monInFlux >> tmpTitre;
      monInFlux >> tmpMapNbrTileX;
      monInFlux >> tmpMapNbrTileY;
      m_mapNbrTile = sf::Vector2i(tmpMapNbrTileX,tmpMapNbrTileY);
      std::cout<<tmpTitre<<std::endl;
      std::cout<<tmpMapNbrTileX<<"/"<<tmpMapNbrTileY<<std::endl;


      //LOAD - MAP
      for(int i = 0; i < m_mapNbrTile.x ; i++)
      {
            for(int j = 0; j < m_mapNbrTile.y ; j++)
            {
                //Lecture des informations
                monInFlux >> tmpTileIDx;
                monInFlux >> tmpTileIDy;
                monInFlux >> tmpTextureID;
                monInFlux >> tmpRotation;
                //Creation Map
                if(tmpTextureID == 0)//TileSet - MUR
                {
                    m_tabMap[i][j] = new Mur(m_tileSetTexture[tmpTextureID],sf::Vector2i(i,j),sf::Vector2i(tmpTileIDx,tmpTileIDy));
                    m_tabMap[i][j]->setScale(sf::Vector2f(0.5,0.5));
                    m_tabMap[i][j]->setCentreOrigin();
                    m_tabMap[i][j]->setRotation(tmpRotation);
                    m_tabMap[i][j]->setMapPosition(m_position);

                    m_tabMap[i][j]->info();
                }
                if(tmpTextureID == 1)//TileSet - SOL
                {
                    m_tabMap[i][j] = new Sol(m_tileSetTexture[tmpTextureID],sf::Vector2i(i,j),sf::Vector2i(tmpTileIDx,tmpTileIDy));
                    m_tabMap[i][j]->setScale(sf::Vector2f(0.5,0.5));
                    m_tabMap[i][j]->setCentreOrigin();
                    m_tabMap[i][j]->setRotation(tmpRotation);
                    m_tabMap[i][j]->setMapPosition(m_position);

                    m_tabMap[i][j]->info();
                }
                if(tmpTextureID == 2)//TileSet - SPECIALvoid GameScreen::load(std::string nomMap)
                {
                    if(tmpTileIDx == 0 && tmpTileIDy == 0)
                    {
                        m_tabMap[i][j] = new Porte(m_tileSetTexture[tmpTextureID],sf::Vector2i(i,j),sf::Vector2i(tmpTileIDx,tmpTileIDy));
                        m_tabMap[i][j]->setScale(sf::Vector2f(0.5,0.5));
                        m_tabMap[i][j]->setCentreOrigin();
                        m_tabMap[i][j]->setRotation(tmpRotation);
                        m_tabMap[i][j]->setMapPosition(m_position);

                        m_tabMap[i][j]->info();
                    }
                }
            }

      }
      //LOAD MONSTRE
      //Initialisation Nombre de Monstre
      int tmpTabMonstreSize = 0;
      monInFlux >> tmpTabMonstreSize;
      for(int i = 0 ; i < tmpTabMonstreSize ; i++)
      {
          //Lecture des informations
          monInFlux >> tmpTileIDx;
          monInFlux >> tmpTileIDy;
          monInFlux >> tmpTilePositionX;
          monInFlux >> tmpTilePositionY;
          monInFlux >> tmpTextureID;
          monInFlux >> tmpRotation;

          //Creation du monstre
          m_tabMonstre.push_back(new Monstre(m_tileSetTexture[tmpTextureID],sf::Vector2i(tmpTilePositionX,tmpTilePositionY),sf::Vector2i(tmpTileIDx,tmpTileIDy)));

          int tmp = m_tabMonstre.size();
          m_tabMonstre[tmp-1]->setScale(sf::Vector2f(0.5,0.5));
          m_tabMonstre[tmp-1]->setCentreOrigin();
          m_tabMonstre[tmp-1]->setMapPosition(m_position);
          m_tabMonstre[tmp-1]->setRotation(tmpRotation);

          m_tabMonstre[tmp-1]->info();
      }

      //LOAD STARTING POINT

      //Lecture des informations
      monInFlux >> tmpTileIDx;
      monInFlux >> tmpTileIDy;
      monInFlux >> tmpTilePositionX;
      monInFlux >> tmpTilePositionY;
      monInFlux >> tmpTextureID;
      monInFlux >> tmpRotation;

      //Creation PersonnageJoueur
      m_player = new PersonnageJoueur(m_tileSetTexture[5],sf::Vector2i(tmpTilePositionX,tmpTilePositionY),sf::Vector2i(tmpTileIDx,tmpTileIDy));
      m_player->setScale(sf::Vector2f(0.5,0.5));
      m_player->setCentreOrigin();
      m_player->setMapPosition(m_position);

      m_player->setRotation(tmpRotation);

      m_player->info();


    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

//EVENT
void GameMap::KeyboardEvent(sf::Event evenement)
{
    if (evenement.type == sf::Event::KeyPressed)
    {
        switch (evenement.key.code)
        {
            case sf::Keyboard::Z:		m_player->playWalkAnimation();
                                        m_player->setDestination(sf::Vector2i(0,-1));
                                        break;

            case sf::Keyboard::D:       m_player->playWalkAnimation();
                                        m_player->setDestination(sf::Vector2i(1,0));
                                        break;

            case sf::Keyboard::S:       m_player->playWalkAnimation();
                                        m_player->setDestination(sf::Vector2i(0,1));
                                        break;

            case sf::Keyboard::Q:       m_player->playWalkAnimation();
                                        m_player->setDestination(sf::Vector2i(-1,0));
                                        break;
        }
    }
}

//SETTER
void GameMap::setMapPosition(sf::Vector2f mapPosition)
{
    m_position = mapPosition;
    for(int i = 0; i < m_mapNbrTile.x ; i++ )
    {
        for(int j = 0; j < m_mapNbrTile.y ; j++)
        {
            m_tabMap[i][j]->setMapPosition(m_position);
        }
    }
    for(int i = 0; i < m_tabMonstre.size(); i++)
    {
        if(m_tabMonstre[i] != 0)
        {
            m_tabMonstre[i]->setMapPosition(m_position);
        }
    }
    m_player->setMapPosition(m_position);
    m_player->resetDestination();
}

//DESTRUCTEUR
GameMap::~GameMap()
{
    //dtor
}
