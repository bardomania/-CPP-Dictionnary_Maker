/*
** PERSONAL PROJECT, 2022
** (CPP)Dictionnary_Maker
** File description:
** draw_panel
*/

//SFML includes
#include <SFML/Graphics.hpp>

//Generic includes
#include <fstream>
#include <iostream>

//save all conbinations in the file
void saveCombination(const std::string & combination, const std::string file = "./dictionary.txt")
{
    std::ofstream myfile;
    myfile.open(file);
    myfile << combination << std::endl;
    myfile.close();
}

void draw(sf::RenderWindow & window)
{
    sf::RectangleShape shape(sf::Vector2f(128.0f,128.0f));
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setPosition(0, 0);

    // set a 10-pixel wide orange outline
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color(250, 150, 100));
    window.draw(shape);
    
}