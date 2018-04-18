#ifndef COMIDA_HPP
#define COMIDA_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

static std::string comidas_certas[] =
    {"pao superior", "alface", "tomate", "pepino", "bacon", "hamburguer", "queijo", "cebola"};

static std::string comidas_erradas[] = {"frango assado", "donnut", "peixe", "sorvete", "maca"};

class Comida {
  public:
    Comida( const std::string nome, const bool comidaCerta );
    void setPosition( const float x, const float y );

    std::string getNome() const;
    sf::Vector2f getPosition() const;
    sf::Sprite getSprite() const;

  private:
    std::string nome;
    sf::Sprite sprite;
    bool comidaCerta;
};

#endif
