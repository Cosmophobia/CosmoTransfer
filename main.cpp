#include <SFML/Graphics.hpp>
#include <iostream>
#include "Launcher.h"
#include "Editeur.h"
#include "GameScreen.h"


int main()
{
    //Déclaration VARIABLES
    sf::Clock clock;
    std::string gameState("LAUNCHER");
    bool appOn = true;

    Editeur *editeur;
    Launcher *launcher;
    GameScreen *gameScreen;
    sf::Event evenement;

    //initialisation fenetre
    sf::RenderWindow *fenetre = new sf::RenderWindow(sf::VideoMode(500,500,32),"Launcher Cosmophobia Concept",sf::Style::Close);
    fenetre->setFramerateLimit(60);

    // BOUCLE PRINCIPALE
    std::cout<<"Lancement boucle principale -->"<<std::endl;
    while(appOn)
    {

        //LAUNCHER
        if(gameState == "LAUNCHER")
        {
            launcher = new Launcher(fenetre);

        while (gameState == "LAUNCHER")
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(*fenetre);
            launcher->updateBouton(localPosition);
            while (fenetre->pollEvent(evenement))
            {
                    switch(launcher->ifBoutonIsPress(localPosition))
                      {
                      case 0:
                              std::cout<<"Launch game"<<std::endl;
                              gameState = "GAME";
                              std::cout<<"State set to GAME"<<std::endl;
                              break;
                      case 1:
                              std::cout<<"Editor"<<std::endl;
                              gameState = "EDITOR";
                              break;
                      case 2:
                              std::cout<<"Exit"<<std::endl;
                              gameState = "EXIT";
                              appOn = false;
                      }
            }
        launcher->draw();
        }
        delete launcher;
        launcher = 0;
        std::cout<<"Launcher Delete"<<std::endl;
        }




        //EDITOR
        if(gameState == "EDITOR")
        {

            //Mise En Place
            editeur = new Editeur(fenetre);
            sf::Time mouseEventTime(clock.getElapsedTime());

            //editor = new Editor(fenetre);
            //editor->mnNewAndLoadMap();
            //editor->mnPalette();
            //editor->mapConstruction(sf::Vector2i(10,10));
            std::cout<<"-----> Boucle EDITEUR"<<std::endl;
                //Depart BOUCLE EDITOR
                while (gameState == "EDITOR")
                {
                    //update
                    editeur->update(evenement,clock.getElapsedTime());
                    //editor->update(evenement);

                    while (fenetre->pollEvent(evenement))
                    {
                        //evenement CLOSE
                        if (evenement.type == sf::Event::Closed)
                        {
                            std::cout<<"Close to launcher"<<std::endl;
                            gameState = "LAUNCHER";
                        }
                        editeur->keyboardAndMouseEvent(evenement,clock.getElapsedTime());
                            //editor->eventMouse(evenement, clock.getElapsedTime());
                            //editor->eventClavier(evenement, clock.getElapsedTime());

                        //evenement SOURIS
                        //evenement CLAVIER

                    }

                    //Dessiner l'éditeur
                    editeur->draw();
                    //editor->draw(clock);
                }

            //DESTRUCTION EDITEUR
            std::cout<<"Editor Exit"<<std::endl;
            //delete editor;
            //editor = 0;
            std::cout<<"Editor Delete"<<std::endl;
        }




                    //GAME
        if(gameState == "GAME")
        {
            //Mise En Place
            gameScreen = new GameScreen(fenetre);


                //Depart BOUCLE GAME
                while (gameState == "GAME")
                {
                  //update
                    //gameScreen->update(evenement);

                    while (fenetre->pollEvent(evenement))
                    {
                        //evenement CLOSE
                        if (evenement.type == sf::Event::Closed)
                        {
                            std::cout<<"Close to launcher"<<std::endl;
                            gameState = "LAUNCHER";
                        }
                        gameScreen->wheelEvent(evenement);
                        //evenement SOURIS

                        //evenement CLAVIER
                        gameScreen->eventClavier(evenement);
                    }

                    //Dessiner l'éditeur
                    gameScreen->draw(clock.getElapsedTime());
                }

            //DESTRUCTION EDITEUR
            std::cout<<"GameScreen Exit"<<std::endl;
            delete gameScreen;
            gameScreen = 0;
            std::cout<<"GameScreen Delete"<<std::endl;
        }


    }

    delete fenetre;
    fenetre = 0;
    return EXIT_SUCCESS;
}
