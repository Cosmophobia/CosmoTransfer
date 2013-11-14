#include "TileSetTexture.h"

TileSetTexture::TileSetTexture()
{

}
TileSetTexture::TileSetTexture(int id, std::string name, sf::Vector2i tileSize, sf::Vector2i tileNumber, std::string fileAdress)
{
    m_id = id;
    m_name = name;
    m_tileSize = tileSize;
    m_tileNumber = tileNumber;
    loadFromFile(fileAdress);
}

void TileSetTexture::initTexture(int id, std::string name, sf::Vector2i tileSize, sf::Vector2i tileNumber, std::string fileAdress)
{
    m_id = id;
    m_name = name;
    m_tileSize = tileSize;
    m_tileNumber = tileNumber;
    loadFromFile(fileAdress);
}


int TileSetTexture::getId()
{
    return m_id;
}
std::string TileSetTexture::getName()
{
    return m_name;
}
sf::Vector2i TileSetTexture::getTileSize()
{
    return m_tileSize;
}
sf::Vector2i TileSetTexture::getTileNumber()
{
    return m_tileNumber;
}


TileSetTexture::~TileSetTexture()
{
    //dtor
}
