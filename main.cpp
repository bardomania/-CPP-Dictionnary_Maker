//Class includes
#include "Grid.hpp"

//Local graphic includes
#include "graphic.hpp"

//Generic includes
#include <list>
#include <string.h>

/* Priority */
enum priority
{
    NORTH_WEST = 1,
    WEST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EST,
    EST,
    NORTH_EST,
    NORTH,
};


// What the Array should look like :
/*
0 1 2 3
4 5 6 7
8 9 A B
C D E F
*/

int main(int argc, char const *argv[])
{
    Dictionary::Grid grid;

    //print panel to know how it looks like
    //grid.PrintPanel();

    //No graphical display
    if (argc != 2) {
        std::cout << "No Graphical Display" << std::endl;
        grid.BreakDictionary();
        return 0;
    } else if (strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--graphic") == 0) {
        std::cout << "Graphical Display" << std::endl;
    } else {
        std::cout << "Error while choosing arguments" << std::endl;
        return 1;
    }

    /* SFML render */
    sf::RenderWindow window(sf::VideoMode(800, 800), "Panel!");

    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        //draw panel and combinations
        draw(window);
        window.display();
    }

    //default return
    return 0;
}
