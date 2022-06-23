/*
** PERSONAL PROJECT, 2022
** (CPP)Dictionnary_Maker
** File description:
** Grid
*/

#include "Grid.hpp"

using namespace Dictionary;

const void Grid::BreakDictionary() const
{
    return;
}

// What the Array should look like :
/*
0 1 2 3
4 5 6 7
8 9 A B
C D E F
*/

const void Grid::PrintPanel() const
{
    for (auto & i : _grid) {
        for (auto & j : i) {
            std::cout << j.GetLetter() << " ";
        }
        std::cout << std::endl;
    }
}

Grid::Grid()
{
    int k = 0;
    //letters on the panel
    char letters_available[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (auto & i : _grid) {
        for (auto & j : i) {
            j.SetLetter(letters_available[k]);
            ++k;
        }
    }
}

Grid::~Grid()
{
}
