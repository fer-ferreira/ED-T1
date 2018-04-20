#include "Game.hpp"

#include "MusicManager.hpp"
#include "SoundManager.hpp"
#include "TextureManager.hpp"

#include "TelaMenu.hpp"

Game::Game( const std::string titulo,
            const int altura,
            const int largura,
            const int limiteDeFrames )
    : window( sf::VideoMode( altura, largura ), titulo, sf::Style::Close ) {
    window.setFramerateLimit( limiteDeFrames );

    isAudioOn    = true;
    estadoJanela = MENU;

    loadTextures();
    loadSounds();

    running = false;
}

void Game::run() {
    running = true;

    TelaMenu menu( &window, &isAudioOn );

    while( running ) {
        switch( estadoJanela ) {
            case MENU:
                estadoJanela = menu.run();
                break;
            case JOGAR:
                break;
            case CREDITOS:
                break;
            case GANHOU:
                break;
            case PERDEU:
                break;
            case FECHAR:
                running = false;
                break;
        }
    }
}

void Game::loadTextures() const {
    TextureManager::add( "audioOn", "audio_on.png" );
    TextureManager::add( "audioOff", "audio_off.png" );

    TextureManager::add( "botaoCreditos", "credits.png" );
    TextureManager::add( "botaoPlay", "play.png" );

    TextureManager::add( "fundoCreditos", "credit.jpg" );
    TextureManager::add( "fundoMenu", "menu.jpg" );
    TextureManager::add( "fundoPerdeu", "gameover.png" );
    TextureManager::add( "fundoGanhou", "gamewin.png" );
}

void Game::loadSounds() const {
    SoundManager::add( "choice", "choice.ogg" );
    SoundManager::add( "empilhar", "empilhar.ogg" );
    SoundManager::add( "levelPass", "level_pass.ogg" );
}
