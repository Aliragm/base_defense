#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>

class Base : public sf::RectangleShape  {
    private:
        float health;
        sf::RectangleShape structure;

    public:
        Base();
        ~Base();
        sf::RectangleShape show();
           float getHealth() const { return health; }
};



#endif
