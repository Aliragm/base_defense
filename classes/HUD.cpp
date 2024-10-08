#include "../headers/HUD.hpp"
#include <iostream> // Para lidar com o erro de carregamento da fonte
#include <sstream>
#include <iomanip>

// Construtor da classe HUD
HUD::HUD() 
    : health(0.f),  
      life(0.f),
      ammo(0),
      xp(0.f)
{
    // Carregar a fonte
    if (!font.loadFromFile("gfx/font.ttf")) {
        std::cerr << "Erro ao carregar a fonte gfx/8-BIT WONDER.TTF!" << std::endl; 
        // Você pode querer lançar uma exceção ou fechar o jogo aqui, dependendo do seu design:
        // throw std::runtime_error("Erro ao carregar a fonte gfx/arial.ttf");
        // 
        // std::exit(EXIT_FAILURE);
    }

    // Configurar os textos do HUD (defina posição, tamanho, cor, etc.)
    healthText.setFont(font);
    healthText.setCharacterSize(20); 
    healthText.setFillColor(sf::Color::White);
    healthText.setOutlineColor(sf::Color::Black);
    healthText.setOutlineThickness(1.f);
    healthText.setPosition(10, 10); 

    lifeText.setFont(font);
    lifeText.setCharacterSize(20); 
    lifeText.setFillColor(sf::Color::White);
    lifeText.setOutlineColor(sf::Color::Black);
    lifeText.setOutlineThickness(1.f);
    lifeText.setPosition(10, 40); 

    ammoText.setFont(font);
    ammoText.setCharacterSize(20); 
    ammoText.setFillColor(sf::Color::White);
    ammoText.setOutlineColor(sf::Color::Black);
    ammoText.setOutlineThickness(1.f);
    ammoText.setPosition(10, 70); 

    xpText.setFont(font);
    xpText.setCharacterSize(20); 
    xpText.setFillColor(sf::Color::White);
    xpText.setOutlineColor(sf::Color::Black);
    xpText.setOutlineThickness(1.f);
    xpText.setPosition(10, 100); 

    gameOver.setFont(font);
    gameOver.setCharacterSize(50); 
    gameOver.setFillColor(sf::Color::Yellow);
    gameOver.setOutlineColor(sf::Color::Black);
    gameOver.setOutlineThickness(2.f);
    gameOver.setPosition(400, 300); 
}

// Método para atualizar as informações do HUD
void HUD::update(Player& player, Base& base) { 
    // Atualizar os valores das variáveis do HUD
    life = player.showLife();    
    ammo = player.showAmmo();    
    xp = player.showXp();        
    health = base.showHealth();  

    // Usar ostringstream para formatar os números com duas casas decimais
    std::ostringstream ossLife, ossAmmo, ossXp, ossHealth;

    ossLife << "Life " << std::fixed << std::setprecision(0) << life;
    ossAmmo << "Ammo " << std::fixed << std::setprecision(0) << ammo;
    ossXp << "XP " << std::fixed << std::setprecision(0) << xp;
    ossHealth << "Base " << std::fixed << std::setprecision(0) << health;

    // Atualizar o texto dos elementos do HUD com os valores formatados
    lifeText.setString(ossLife.str());
    ammoText.setString(ossAmmo.str());
    xpText.setString(ossXp.str());
    healthText.setString(ossHealth.str());
}

// Método para desenhar o HUD na janela
void HUD::draw(sf::RenderWindow& window) {
    // Desenhar os textos na janela
    window.draw(healthText);
    window.draw(lifeText);
    window.draw(ammoText);
    window.draw(xpText);
    
    // Se você tiver outros elementos no HUD, desenhe-os aqui
}

void HUD::gameOverScreen(sf::RenderWindow& window)  {
    std::ostringstream ossGameOver;
    ossGameOver << "GAME\n  OVER";
    gameOver.setString(ossGameOver.str());
    sf::FloatRect rc = gameOver.getLocalBounds();
    gameOver.setOrigin(rc.width/2, rc.height/2);
    window.draw(gameOver);
}