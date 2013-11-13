#include "SuperTile.h"

SuperTile::SuperTile():
    m_tilePosition(sf::Vector2i(0,0)),
    m_id(sf::Vector2i(0,0)),
    m_mapOrigin(sf::Vector2f(0,0))
{
    //ctor
}
SuperTile::SuperTile(TileSetTexture &tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i id, sf::Vector2f mapOrigin):
    m_tilePosition(tilePosition),
    m_id(id),
    m_mapOrigin(mapOrigin)
{
    m_tileSetTexture = &tileSetTexture;
    setTexture(tileSetTexture);
    autoSetTileTextureRect();
}

//Position
void SuperTile::setIdGridPosition(sf::Vector2f positionMap)
{
    m_mapOrigin = positionMap;
    setPosition(sf::Vector2f( m_mapOrigin.x + m_id.x * getGlobalBounds().width  ,  m_mapOrigin.y + m_id.y * getGlobalBounds().height ));
}
void SuperTile::setMapPosition(sf::Vector2f positionMap)
{
    m_mapOrigin = positionMap;
    setPosition(sf::Vector2f(  positionMap.x + m_tilePosition.x * getGlobalBounds().width  ,  positionMap.y + m_tilePosition.y * getGlobalBounds().height  ));
}
void SuperTile::setAutoScaleX(float width, int textureNbrTileX)
{
    float tmpScale = getScale().x;
    while(textureNbrTileX*getGlobalBounds().width*tmpScale > width)
    {
        tmpScale -= 0.001;
    }
    setScale(sf::Vector2f(tmpScale,tmpScale));
}

//Setter
void SuperTile::autoSetTileTextureRect()
{
    int i = m_id.x, j = m_id.y;
    setTextureRect( sf::IntRect ( i * m_tileSetTexture->getTileSize().x , j * m_tileSetTexture->getTileSize().y , m_tileSetTexture->getTileSize().x , m_tileSetTexture->getTileSize().y ));
}
void SuperTile::setTileSetTexture(TileSetTexture &tileSetTexture)
{
    std::cout<<" IN   Tile set texture : "<<&tileSetTexture<<std::endl;
    m_tileSetTexture = &tileSetTexture;
    std::cout<<" IN   Tile set texture : "<<&tileSetTexture<<std::endl;
    std::cout<<" texture set"<<std::endl;
    setTexture(tileSetTexture);
    std::cout<<" set texture OK"<<std::endl;
}
void SuperTile::setTilePosition(sf::Vector2i tilePosition)
{
    m_tilePosition = tilePosition;
}
void SuperTile::setId(sf::Vector2i id)
{
    m_id = id;
    autoSetTileTextureRect();
}
void SuperTile::setMapOrigin(sf::Vector2f mapOrigin)
{
    m_mapOrigin = mapOrigin;
}

//Getter
int SuperTile::getTileSetTextureID()
{
    return m_tileSetTexture->getId();
}
sf::Vector2i SuperTile::getTilePosition()
{
    return m_tilePosition;
}
sf::Vector2i SuperTile::getId()
{
    return m_id;
}
sf::Vector2f SuperTile::getMapOrigin()
{
    return m_mapOrigin;
}

SuperTile::~SuperTile()
{
    //dtor
}
