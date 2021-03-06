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

//Local includes
#include "graphic.hpp"

/*
//number of letters available
int number_letters = sizeof(letters_available) / sizeof(char);
std::cout << number_letters << std::endl;
*/

//save all conbinations in the file
void saveCombination(const std::string & combination, const std::string file = "./dictionary.txt")
{
    std::ofstream myfile;
    myfile.open(file);
    myfile << combination << std::endl;
    myfile.close();
}

void fill_grid(sf::RenderWindow & window)
{
    //letters on the panel
    char letters_available[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int k = 0;

    //define font
    sf::Font font;
    if (!font.loadFromFile("./code_ressources/Roboto-Regular.ttf"))
    {
        // #TODO return error
        std::cout << "erreur de path" << std::endl;
    }

    for (int i = 0; i < NUMBER_OF_LINE; ++i) {
        for (int j = 0; j < NUMBER_LETTERS_PER_LINE; ++j) {
            /* DRAW RECTANGLE */
            sf::RectangleShape shape(sf::Vector2f(PANEL_SIZE_X / NUMBER_LETTERS_PER_LINE, PANEL_SIZE_Y / NUMBER_OF_LINE));
            //Set color to see the different grid's block #TODO maybe change that outline
            shape.setFillColor(sf::Color(255 - (10 * j) - (10 * i), 255 - (10 * j) - (10 * i), 255 - (10 * j) - (10 * i)));
            //Set position of each blocks
            shape.setPosition(((WINDOW_SIZE_X - PANEL_SIZE_X) / 2) + ((PANEL_SIZE_X / NUMBER_LETTERS_PER_LINE) * j), 
                ((WINDOW_SIZE_Y - PANEL_SIZE_Y) / 2) + ((PANEL_SIZE_Y / NUMBER_OF_LINE) * i));
            window.draw(shape);

            /* DRAW TEXT */
            sf::Text text;
            //set default text
            text.setFont(font);
            text.setString(letters_available[k]);
            text.setCharacterSize(TEXT_SIZE);
            text.setFillColor(sf::Color::Black);
            //set text position
            text.setPosition(
                //X
                ((WINDOW_SIZE_X - PANEL_SIZE_X) / 2) + ((PANEL_SIZE_X / NUMBER_LETTERS_PER_LINE) * j) + ((PANEL_SIZE_X / NUMBER_LETTERS_PER_LINE) / 2 - (TEXT_SIZE / NUMBER_LETTERS_PER_LINE)), 
                //Y
                ((WINDOW_SIZE_Y - PANEL_SIZE_Y) / 2) + ((PANEL_SIZE_Y / NUMBER_OF_LINE) * i) + TEXT_SIZE / 2);
            window.draw(text);

            ++k;
        }
    }
}

void draw(sf::RenderWindow & window)
{
    //setting up grid 
    sf::RectangleShape shape(sf::Vector2f(PANEL_SIZE_X, PANEL_SIZE_Y));
    shape.setFillColor(sf::Color(170, 170, 170));
    shape.setPosition((WINDOW_SIZE_X - PANEL_SIZE_X) / 2, (WINDOW_SIZE_Y - PANEL_SIZE_Y) / 2);

    //set a 10-pixel wide outline
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color(90, 90, 90));
    window.draw(shape);

    fill_grid(window);
}