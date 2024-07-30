#include <SFML/Graphics.hpp>
#include <iostream>
#include "Base.hpp"
#include "Player.hpp"

// clang++ prototipo.cpp -o protipo -I/usr/local/Cellar/sfml/2.6.1/include -L/usr/local/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system



int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "BaseDefense");
    sf::RectangleShape Background(sf::Vector2f(800.f, 600.f));
    Background.setFillColor(sf::Color::White);
    Base Base;
    Player Player;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                Player.processEvents(event.key.code, true);
            }
            if(event.type == sf::Event::KeyReleased){
                Player.processEvents(event.key.code, false);
            }
        }

        window.clear();
        window.draw(Background);
        window.draw(Base.show());
        Player.updateVelocity();
        Player.checkColissions();
        window.draw(Player.show());
        window.display();
    }

    return 0;
}
