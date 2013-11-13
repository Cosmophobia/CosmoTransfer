#ifndef TILESETTEXTURE_H
#define TILESETTEXTURE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class TileSetTexture : public sf::Texture
{
    public:
        TileSetTexture();
        TileSetTexture(int id, std::string name, sf::Vector2i tileSize, sf::Vector2i tileNumber, std::string fileAdress);
        void initTexture(int id, std::string name, sf::Vector2i tileSize, sf::Vector2i tileNumber, std::string fileAdress);

        int getId();
        std::string getName();
        sf::Vector2i getTileSize();
        sf::Vector2i getTileNumber();

        virtual ~TileSetTexture();
    protected:
    private:
    int m_id;
    std::string m_name;
    sf::Vector2i m_tileSize;
    sf::Vector2i m_tileNumber;
};

#endif // TILESETTEXTURE_H
