#include "PersonnageJoueur.h"

PersonnageJoueur::PersonnageJoueur()
{
    //ctor
}

PersonnageJoueur::PersonnageJoueur(TileSetTexture& tileSetTexture, sf::Vector2i tilePosition, sf::Vector2i tileID):
    Personnage(tileSetTexture,tilePosition,tileID)
{
    setName("PERSONNAGEJOUEUR");
    setIfPassable(false);

    m_walking.addFrame(1.f, sf::IntRect(96, 0, 96, 96));
    m_walking.addFrame(1.f, sf::IntRect(192, 0, 96, 96));
    m_walking.addFrame(1.f, sf::IntRect(96, 0, 96, 96));
    m_walking.addFrame(1.f, sf::IntRect(192, 0, 96, 96));

	m_pjAnimator.addAnimation("walking", m_walking, sf::seconds(1.f));
}

//SYSTEM
void PersonnageJoueur::draw(sf::RenderWindow *fenetre, sf::Time timeOfDraw)
{
    sf::Time tempTime = timeOfDraw - m_lastDraw;
    deplacementPerso(tempTime);
    fenetre->draw(*this);
    m_lastDraw = timeOfDraw;
}

//ANIMATION
void PersonnageJoueur::playWalkAnimation()
{
    m_pjAnimator.playAnimation("walking",true);
}

//EVENT
void PersonnageJoueur::deplacementPerso(sf::Time tempTime)
{

    if(getPosition().x < m_destination.x)
    {
        move(sf::Vector2f(3,0));
        m_pjAnimator.update(tempTime);
        m_pjAnimator.animate(*this);
    }
    if(getPosition().y < m_destination.y)
    {
        move(sf::Vector2f(0,3));
        m_pjAnimator.update(tempTime);
        m_pjAnimator.animate(*this);
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

//GETTER
sf::Vector2i PersonnageJoueur::getNextMove(sf::Vector2i mouvement)
{
    sf::Vector2i tmp = getTilePosition() + mouvement;
    return tmp;
}

//SETTER
void PersonnageJoueur::setDestination(sf::Vector2i destination)
{
    if(getPosition() == m_destination)
    {
        setTilePosition(getTilePosition()+destination);
        m_destination = sf::Vector2f( getMapOrigin().x + getTilePosition().x * getGlobalBounds().width,
                                      getMapOrigin().y + getTilePosition().y * getGlobalBounds().height );
        std::cout<<"PJ tp:"<<getTilePosition().x<<"/"<<getTilePosition().y<<
                      " p:"<<getPosition().x<<"/"<<getPosition().y<<
                      " d:"<<m_destination.x<<"/"<<m_destination.y<<std::endl;
    }
}
void PersonnageJoueur::resetDestination()
{
    m_destination = getPosition();
}


PersonnageJoueur::~PersonnageJoueur()
{
    //dtor
}
