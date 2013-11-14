#include "GameScreen.h"

GameScreen::GameScreen(sf::RenderWindow *fenetre)

{
    // CREER FENETRE AVEC FOND
    std::cout<<"In GAME"<<std::endl;
    m_fenetreGame = fenetre;

    if(!m_textureFondGame.loadFromFile("images/FondGame.png"))
    {
        std::cout<<"Erreur lors du chargement de l'image"<<std::endl;
    }
    m_fenetreGame->create(sf::VideoMode(1024,768,32),"Cosmophobia Game",sf::Style::Close);
    m_imgFondGame.setTexture(m_textureFondGame);
    m_imgFondGame.setPosition(0,0);
    m_imgFondGame.setTextureRect(sf::IntRect(0,0,1024,768));
    std::cout<<"texture done"<<std::endl;

    // CREER MAP
    m_gameMapOrigine = sf::Vector2f(75.f,75.f);
    m_gameMap.build(sf::Vector2i(10,10), m_gameMapOrigine);

    //COSMONAUTE
  //  m_cosmonaute.setCentreOrigin();
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
			if (evenement.type == sf::Event::KeyPressed)
			{
				switch (evenement.key.code)
				{
					case sf::Keyboard::Z:		m_cosmonaute.playWalkAnimation();
                                                m_cosmonaute.setDestination(sf::Vector2f(0.f,-1.f)); break;
                    case sf::Keyboard::D:       m_cosmonaute.playWalkAnimation();
                                                m_cosmonaute.setDestination(sf::Vector2f(1.f,0.f)); break;
                    case sf::Keyboard::S:       m_cosmonaute.playWalkAnimation();
                                                m_cosmonaute.setDestination(sf::Vector2f(0.f,1.f)); break;
                    case sf::Keyboard::Q:       m_cosmonaute.playWalkAnimation();
                                                m_cosmonaute.setDestination(sf::Vector2f(-1.f,0.f)); break;
				}
			}

}

void GameScreen::draw(sf::Time elapsedTime)
{
    m_fenetreGame->resetGLStates();
    m_fenetreGame->clear();
    m_fenetreGame->draw(m_imgFondGame);
    m_gameMap.draw(m_fenetreGame);
    m_cosmonaute.draw(m_fenetreGame, elapsedTime);
    m_fenetreGame->display();
}


GameScreen::~GameScreen()
{
    m_fenetreGame = 0;
}
