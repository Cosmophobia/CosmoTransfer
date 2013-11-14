#include "Decors.h"

Decors::Decors()
{
    //ctor
}

Decors::Decors(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Passable(tileSetTexture,tilePosition,tileID,true)
{
    //ctor
}

void Decors::info()
{
    std::cout<<"texture:"<<getTileSetTextureID()<<" tp:"<<getTilePosition().x<<"/"<<getTilePosition().y<<" tId:"<<getId().x<<"/"<<getId().y<<"t:"<<m_name<<" p:"<<getIfPassable()<<std::endl;
}

std::string Decors::getName()
{
        return m_name;
}
void Decors::setName(std::string name)
{
    m_name = name;
}

Decors::~Decors()
{
    //dtor
}
