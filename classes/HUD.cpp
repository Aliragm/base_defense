#include "../headers/HUD.hpp"
#include <iostream> // Para lidar com o erro de carregamento da fonte

// Construtor da classe HUD
HUD::HUD() 
: health(100.f),  
  life(0.f),
  ammo(0),
  xp(0.f) 
{
    // Carregar a fonte
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erro ao carregar a fonte!" << std::endl; 
        // TODO: Lidar com o erro de forma adequada ao seu jogo (ex: exibir uma mensagem de erro e fechar o jogo)
    }

    // Configurar os textos (defina posição, tamanho, cor, etc. aqui)
    // TODO: Ajuste as configurações de posição, tamanho e cor dos textos de acordo com o seu layout desejado.
    healthText.setFont(font);
    healthText.setCharacterSize(20); 
    healthText.setFillColor(sf::Color::White);
    healthText.setPosition(10, 10); 

    lifeText.setFont(font);
    lifeText.setCharacterSize(20); 
    lifeText.setFillColor(sf::Color::White);
    lifeText.setPosition(10, 40); 

    ammoText.setFont(font);
    ammoText.setCharacterSize(20); 
    ammoText.setFillColor(sf::Color::White);
    ammoText.setPosition(10, 70); 

    xpText.setFont(font);
    xpText.setCharacterSize(20); 
    xpText.setFillColor(sf::Color::White);
    xpText.setPosition(10, 100); 
}

// Método para atualizar as informações do HUD
void HUD::update(Player& player, Base& base) { 
    life = player.life; 
    ammo = player.ammo;
    xp = player.xp;
    health = base.health; // Obter a vida da base

    // Atualizar o texto dos elementos do HUD
    lifeText.setString("Vida: " + std::to_string(life));
    ammoText.setString("Munição: " + std::to_string(ammo));
    xpText.setString("XP: " + std::to_string(xp)); 
    healthText.setString("Base: " + std::to_string(health)); 
}

// Método para desenhar o HUD na janela
void HUD::draw(sf::RenderWindow& window) {
    window.draw(healthText);
    window.draw(lifeText);
    window.draw(ammoText);
    window.draw(xpText);
    // Desenhar outros elementos do HUD (barras de vida, etc.)
}