#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player.hpp"
#include "base.hpp"

class HUD {
public:
    HUD() 
    : health(100.f),  
      life(0.f),
      ammo(0),
      xp(0.f) 
    {
        // Carregar a fonte
        if (!font.loadFromFile("arial.ttf")) {
            // Lidar com erro de carregamento da fonte
        }

        // Configurar os textos
        lifeText.setFont(font);
        ammoText.setFont(font);
        xpText.setFont(font);
        // ... outras configurações (posição, tamanho, cor, etc.)
    }

    void update(Player& player, Base& base) { 
        life = player.life; 
        ammo = player.ammo;
        xp = player.xp;
        health = base.health;

        // Atualizar o texto dos elementos do HUD
        lifeText.setString("Vida: " + std::to_string(life));
        ammoText.setString("Munição: " + std::to_string(ammo));
        xpText.setString("XP: " + std::to_string(xp)); 
        healthText.setString("Base: " + std::to_string(health)); 
    }

    void draw(sf::RenderWindow& window) {
        window.draw(lifeText);
        window.draw(ammoText);
        window.draw(xpText);
        window.draw(healthText);
        // Desenhar outros elementos do HUD (barras de vida, etc.)
    }

private:
    sf::Font font;
    sf::Text healthText;
    sf::Text lifeText;
    sf::Text ammoText;
    sf::Text xpText;
    float health;
    int life; 
    int ammo;
    float xp;
};

#endif