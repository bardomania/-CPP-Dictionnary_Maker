/*
** PERSONAL PROJECT, 2022
** (CPP)Dictionnary_Maker
** File description:
** Block
*/

#include "Block.hpp"

using namespace Dictionary;

const char Block::GetLetter() const
{
    return _letter;
}

void Block::SetLetter(const char letter)
{
    _letter = letter;
}

Block::Block()
{
}

Block::Block(const char letter)
: _letter (letter)
{
}

Block::~Block()
{
}