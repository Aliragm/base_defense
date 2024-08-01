#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "Base.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

// clang++ prototipo.cpp -o protipo -I/usr/local/Cellar/sfml/2.6.1/include -L/usr/local/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

int main(){
    std::srand(time(NULL));
    // Variáveis
    sf::RenderWindow window(sf::VideoMode(800, 600), "BaseDefense");
    sf::RectangleShape Background(sf::Vector2f(800.f, 600.f));
    Background.setFillColor(sf::Color::White);
    Base Base;
    Player Player;
    Enemy Enemies;
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    // Loop do jogo
    while (window.isOpen())
    {
        // Atualização
        Player.updateVelocity();
        Player.checkCollisions();
        Player.updateBullets(Enemies.showVector());

        playerCenter = Player.show().getPosition();
        mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
        aimDir = mousePosWindow - playerCenter;
        float length = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
        aimDirNorm = aimDir / length;

        // Eventos
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
            if(event.type == sf::Event::MouseButtonPressed){
                Player.shootBullet(aimDirNorm);
            }
        }

        // Desenho
        window.clear();
        window.draw(Background);

        window.draw(Base.show());
        Enemies.Spawner(); // Chama o Spawner para criar os inimigos
        Enemies.DrawEnemies(window); // Desenha os inimigos na janela
        Player.drawBullets(window);
        window.draw(Player.show());
        window.display();
    }

    return 0;
}
