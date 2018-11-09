#include <iostream>
#include <SFML/Graphics.hpp>

int main(int, char**) {
    sf::RenderWindow win;
    win.create(sf::VideoMode(600,400), "hello", sf::Style::Close);
    sf::Event e;
    while(win.isOpen())
    {
        while(win.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            win.close();
        }
        win.clear();
        win.display();
    }
}
