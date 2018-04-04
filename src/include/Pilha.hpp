#ifndef PILHA_HPP

#define PILHA_HPP

#include <exception>

class ExcecaoPilha : public std::exception {
  public:
    ExcecaoPilha( const char *message );
    virtual const char *what() const throw();

  private:
    const char *msg;
    void setMessage( const char *message );
};

template < class T >
class Pilha {
  public:
    Pilha( const int tamanho ) throw( ExcecaoPilha );
    ~Pilha();

    bool isVazia() const;
    bool isCheia() const;
    int getTamanho() const;

    void empilhar( const T elemento ) throw( ExcecaoPilha );
    T desempilhar() throw( ExcecaoPilha );

  private:
    int tamanho;
    int topo;

    T *vetor;
};

#include "../model/Pilha.cpp"

#endif
