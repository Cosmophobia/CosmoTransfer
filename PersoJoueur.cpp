#include "PersoJoueur.h"

PersoJoueur::PersoJoueur()
{
    m_spriteTexture.initTexture(9, "CosmoTexture", sf::Vector2i (96,96), sf::Vector2i (1,3), "images/SpriteSetAstro2.png");
    setTileSetTexture(m_spriteTexture);
    setId(sf::Vector2i(0,0));
    setCentreOrigin();
    setMapPosition(sf::Vector2f(75,75));
    m_destination = getPosition();
    std::cout << "destination" << m_destination.x << m_destination.y << " position " << getPosition().x << getPosition().y << std::endl;
    m_walking.addFrame(1.f, sf::IntRect(96, 0, 96, 96));
    m_walking.addFrame(1.f, sf::IntRect(192, 0, 96, 96));
    m_walking.addFrame(1.f, sf::IntRect(96, 0, 96, 96));
    m_walking.addFrame(1.f, sf::IntRect(192, 0, 96, 96));

	pjAnimator.addAnimation("walking", m_walking, sf::seconds(1.f));
}


void PersoJoueur::playWalkAnimation()
{
    pjAnimator.playAnimation("walking",true);
}
void PersoJoueur::draw(sf::RenderWindow *fenetre, sf::Time timeOfDraw)
{
    sf::Time tempTime = timeOfDraw - m_lastDraw;
    deplacementPerso(tempTime);
    fenetre->draw(*this);
    m_lastDraw = timeOfDraw;
}

void PersoJoueur::deplacementPerso(sf::Time tempTime)
{
    std::cout << "destination" << m_destination.x << m_destination.y << " position " << getPosition().x << getPosition().y << std::endl;

    if(getPosition().x < m_destination.x)
    {
        move(sf::Vector2f(3,0));
        pjAnimator.update(tempTime);
        pjAnimator.animate(*this);
    }
    if(getPosition().y < m_destination.y)
    {
        move(sf::Vector2f(0,3));
        pjAnimator.update(tempTime);
        pjAnimator.animate(*this);
    }
    if(getPosition().x > m_destination.x)
    {
        move(sf::Vector2f(-3,0));
    }
    if(getPosition().y > m_destination.y)
    {
        move(sf::Vector2f(0,-3));
    }

}

void PersoJoueur::setDestination(sf::Vector2f destination)
{
    if(getPosition() == m_destination)
    {
    m_destination = sf::Vector2f(getPosition().x + destination.x * 96 , getPosition().y + destination.y * 96 );
    std::cout <<"setDestination x = " << m_destination.x << "setDestination y = " << m_destination.y <<std::endl;
    }
}


PersoJoueur::~PersoJoueur()
{
    //dtor
}
