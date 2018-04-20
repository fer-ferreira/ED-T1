#include "TelaMenu.hpp"

#include "MusicManager.hpp"
#include "SoundManager.hpp"
#include "TextureManager.hpp"

TelaMenu::TelaMenu( sf::RenderWindow* window, bool* isAudioOn ) {
    this->window    = window;
    this->isAudioOn = isAudioOn;

    loadSprites();
    loadSounds();
}

void TelaMenu::loadSprites() {
    background.setTexture( TextureManager::get( "fundoMenu" ) );
    botaoJogar.setTexture( TextureManager::get( "botaoPlay" ) );
    botaoCreditos.setTexture( TextureManager::get( "botaoCreditos" ) );
    botaoAudio.setTexture( TextureManager::get( "audioOn" ) );
}
void TelaMenu::loadSounds() {
    musica = &MusicManager::add( "menu", "menu.ogg" );
    musica->setLoop( true );

    somClick = SoundManager::get( "choice" );
}

WINDOW_RETURN TelaMenu::run() {
    sf::Time delayTime = sf::milliseconds( 200 );
    sf::Event event;

    isRunnig = true;

    botaoAudio.setScale( sf::Vector2f( 0.25, 0.25 ) );

    botaoJogar.setPosition( 475.0f, 250.0f );
    botaoCreditos.setPosition( 475.0f, 325.0f );
    botaoAudio.setPosition( 700.0f, 500.0f );

    musica->play();

    while( isRunnig ) {
        while( window->pollEvent( event ) ) {
            if( event.type == sf::Event::Closed ) {
                window->close();
                return FECHAR;
            }
        }

        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition( *window );
            if( botaoJogar.getGlobalBounds().contains(
                    window->mapPixelToCoords( mousePosition ) ) ) {
                return CLICK_JOGAR;
            }
            if( botaoCreditos.getGlobalBounds().contains(
                    window->mapPixelToCoords( mousePosition ) ) ) {
                return CLICK_CREDITOS;
            }
            if( botaoAudio.getGlobalBounds().contains(
                    window->mapPixelToCoords( mousePosition ) ) ) {
                if( *isAudioOn ) {
                    musica->pause();
                    sf::sleep( delayTime );
                    botaoAudio.setTexture( TextureManager::get( "audioOff" ) );
                    *isAudioOn = false;
                } else {
                    musica->play();
                    sf::sleep( delayTime );
                    botaoAudio.setTexture( TextureManager::get( "audioOn" ) );
                    *isAudioOn = true;
                }
            }
        }

        window->draw( background );
        window->draw( botaoAudio );
        window->draw( botaoJogar );
        window->draw( botaoCreditos );

        window->display();
        window->clear();
    }
    return FECHAR;
}
