/*
** PERSONAL PROJECT, 2022
** (CPP)Dictionnary_Maker
** File description:
** Block
*/

#pragma once

namespace Dictionary {

class Block {
    public:
        Block();
        Block(const char letter);
        ~Block();

        void SetLetter(const char letter);
        const char GetLetter() const; 
    protected:
    private:
        char _letter;
};

}