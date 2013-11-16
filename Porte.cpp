#include "Porte.h"

Porte::Porte()
{
    //ctor
}

Porte::Porte(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Decors(tileSetTexture,tilePosition,tileID)
{
    setName("PORTE");
    setIfPassable(false);

    m_open.addFrame(1.f, sf::IntRect(0, 0, 96, 96));
    m_open.addFrame(1.f, sf::IntRect(96, 0, 96, 96));
    m_open.addFrame(1.f, sf::IntRect(96*2, 0, 96, 96));
    m_open.addFrame(1.f, sf::IntRect(96*3, 0, 96, 96));
	m_doorAnimator.addAnimation("open", m_open, sf::seconds(1.f));

	m_close.addFrame(1.f, sf::IntRect(96*3, 0, 96, 96));
    m_close.addFrame(1.f, sf::IntRect(96*2, 0, 96, 96));
    m_close.addFrame(1.f, sf::IntRect(96, 0, 96, 96));
    m_close.addFrame(1.f, sf::IntRect(0, 0, 96, 96));
    m_doorAnimator.addAnimation("close", m_close, sf::seconds(1.f));

}

void Porte::draw(sf::RenderWindow *fenetre, sf::Time timeOfDraw)
{
    sf::Time tempTime = timeOfDraw - m_lastDraw;
    m_doorAnimator.update(tempTime);
    m_doorAnimator.animate(*this);
    fenetre->draw(*this);
    m_lastDraw = timeOfDraw;
}

void Porte::playAnimation(std::string name)
{
    if(name == "open")
    {
        m_doorAnimator.playAnimation("open");
    }
    if(name == "close")
    {
        m_doorAnimator.playAnimation("close");
    }
}


Porte::~Porte()
{
    //dtor
}
