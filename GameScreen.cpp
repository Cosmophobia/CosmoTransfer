#include "GameScreen.h"

GameScreen::GameScreen(sf::RenderWindow *fenetre)
{
    // CREER FENETRE AVEC FOND
    std::cout<<"IN : GameScreen"<<std::endl;
    m_fenetreGame = fenetre;

    if(!m_textureFondGame.loadFromFile("images/FondGame.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }

    m_fenetreGame->create(sf::VideoMode(1440,900,32),"Cosmophobia Game",sf::Style::Close);
    m_imgFondGame.setTexture(m_textureFondGame);
    m_imgFondGame.setPosition(0,0);
    m_imgFondGame.setTextureRect(sf::IntRect(0,0,1440,900));

    std::cout<<"texture done"<<std::endl;

    // CREER MAP
    m_gameMapOrigine = sf::Vector2f(75.f,75.f);

    m_gameMap.load("testMap");
    m_gameMap.setMapPosition(sf::Vector2f (150,150));
}



//evenement
void GameScreen::wheelEvent(sf::Event evenement)
{
    if (evenement.type == sf::Event::MouseWheelMoved)
    {
       int tmpDelta = evenement.mouseWheel.delta;
       std::cout<<"tmp delta ="<<tmpDelta<<std::endl;
       if(tmpDelta > 0)
       {
          //  m_gameMap.scaleMap("ZOOM+",0.5f);
       }
       if(tmpDelta < 0)
       {
         //  m_gameMap.scaleMap("ZOOM-",0.5f);
       }
    }
}

void GameScreen::eventClavier(sf::Event evenement)
{
   m_gameMap.KeyboardEvent(evenement);
}

void GameScreen::draw(sf::Time elapsedTime)
{
    m_fenetreGame->resetGLStates();
    m_fenetreGame->clear();
    m_fenetreGame->draw(m_imgFondGame);
    m_gameMap.draw(m_fenetreGame, elapsedTime);
    //m_cosmonaute.draw(m_fenetreGame, elapsedTime);
    m_fenetreGame->display();
}


GameScreen::~GameScreen()
{
    m_fenetreGame = 0;
}
