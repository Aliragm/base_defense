#ifndef HUD_HPP
#define HUD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "player.hpp"
#include "base.hpp"

class HUD 
public:
    HUD() 
    : health(100.f),  // Inicializando com algum valor padrão, ajuste conforme necessário
      life(0.f),
      ammo(0),
      xp(0.f) 
    {
public:
    HUD() {
        // Carregar a fonte
        if (!font.loadFromFile("arial.ttf")) {
            // Lidar com erro de carregamento da fonte
        }

        // Configurar os textos
        healthText.setFont(font);
        lifeText.setFont(font);
        ammoText.setFont(font);
        xpText.setFont(font);
        // ... outras configurações (posição, tamanho, cor, etc.)
    }

  void HUD::update(Player& player, Base& base) { 
    life = player.life; 
    ammo = player.ammo;
    xp = player.xp;
    health = base.health; // Obter a vida da base
  
 }

 

    void draw(sf::RenderWindow& window) {
        window.draw(healthText);
        window.draw(lifeText);
        window.draw(ammoText);
        window.draw(xpText);
        // Desenhar outros elementos do HUD (barras de vida, etc.)
    }

private:
    sf::Font font;
    sf::Text healthText;
    sf::Text lifeText;
    sf::Text ammoText;
    sf::Text xpText;
    float health;
    float life;
    int ammo;
    float xp;
};



  
