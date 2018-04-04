#include "Pilha.hpp"
#include <iostream>

int main( int argc, char const *argv[] ) {
    Pilha< int > pilha( 10 );
    pilha.empilhar( 1 );
    pilha.empilhar( 2 );
    std::cout << pilha.desempilhar() << '\n';
    std::cout << pilha.desempilhar() << '\n';
    return 0;
}
