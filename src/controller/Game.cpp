#include "Game.hpp"

#include "MusicManager.hpp"
#include "SoundManager.hpp"
#include "TelaMenu.hpp"
#include "TextureManager.hpp"

#include <iostream>

Game::Game( const std::string titulo,
            const int altura,
            const int largura,
            const int limiteDeFrames )
    : window( sf::VideoMode( altura, largura ), titulo, sf::Style::Close ) {
    window.setFramerateLimit( limiteDeFrames );

    isAudioOn = true;

    loadTextures();
    loadSounds();

    running = false;
}

void Game::run() {
    running = true;

    TelaMenu menu( &window, &isAudioOn );
    menu.run();
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
