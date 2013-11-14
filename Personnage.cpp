#include "Personnage.h"

Personnage::Personnage()
{
    //ctor
}
Personnage::Personnage(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Passable(tileSetTexture,tilePosition,tileID,false)
{
    m_name = "PERSONNAGE";
}

void Personnage::info()
{
    std::cout<<"texture:"<<getTileSetTextureID()<<" tp:"<<getTilePosition().x<<"/"<<getTilePosition().y<<" tId:"<<getId().x<<"/"<<getId().y<<"t:"<<m_name<<" p:"<<getIfPassable()<<std::endl;
}

std::string Personnage::getName()
{
        return m_name;
}
void Personnage::setName(std::string name)
{
    m_name = name;
}


Personnage::~Personnage()
{
    //dtor
}
