/*
** PERSONAL PROJECT, 2022
** (CPP)Dictionnary_Maker
** File description:
** Grid
*/

#pragma once

//Generic includes
#include <array>
#include <iostream>

//Class includes
#include "Block.hpp"

#define SIZE_X 4
#define SIZE_Y 4

namespace Dictionary {

class Grid {
    public:
        Grid();
        ~Grid();

        const void PrintPanel() const;
        const void BreakDictionary() const;

    protected:
    private:
        std::array<std::array<Block, SIZE_X>, SIZE_Y> _grid;
};

}