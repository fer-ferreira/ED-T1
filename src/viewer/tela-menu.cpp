#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


void counter(int tempo){
    int g=0;
    for(int i=0; i<=tempo; i++){
        g++;
    }
}

int main()
{
    int sound_status = 1;

    sf::RenderWindow window(sf::VideoMode(750, 550), "Snack Stack", sf::Style::Close | sf::Style::Titlebar);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("menu.wav"))
        window.close();

    sf::Texture menu_screen;
    if(!menu_screen.loadFromFile("menu.jpg"))
            window.close();

    sf::Texture play_btn;
    if(!play_btn.loadFromFile("play.png"))
            window.close();

    sf::Texture credits_btn;
    if(!credits_btn.loadFromFile("credits.png"))
            window.close();

    sf::Texture audio_on_btn;
    if(!audio_on_btn.loadFromFile("audio_on.png"))
            window.close();

    sf::Texture audio_off_btn;
    if(!audio_off_btn.loadFromFile("audio_off.png"))
            window.close();

//    sf::Texture credit_screen;
//    if(!credit_screen.loadFromFile("credit.jpg"))
//            window.close();

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);

    sf::Sprite sprite1(menu_screen);
    sf::Sprite sprite2(play_btn);
    sf::Sprite sprite3(credits_btn);
    sf::Sprite sprite4(audio_on_btn);
    sprite4.setScale(sf::Vector2f(0.25, 0.25));

    sprite2.setPosition(475.0f,250.0f);
    sprite3.setPosition(475.0f,325.0f);
    sprite4.setPosition(700.0f,500.0f);
    sound.play();
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if(sprite2.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))){
                //abrir tela do jogo
                //tirar botões
            }
            if(sprite3.getGlobalBounds().contains(window.mapPixelToCoords(mousePos))){
                //abrir tela de creditos
            }
            if(sprite4.getGlobalBounds().contains(window.mapPixelToCoords(mousePos)) && sound_status==1){
                sound.pause();
                counter(100000000);
                sprite4.setTexture(audio_off_btn);
                sound_status = 0;
            }
            else{
                sound.play();
                counter(100000000);
                sprite4.setTexture(audio_on_btn);
                sound_status = 1;
            }

        }
//        //Movimenta "player" pelas setas do teclado
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
//            player.move(-0.1f,0.0f);
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
//            player.move(0.1f,0.0f);
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
//            player.move(0.0f,-0.1f);
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
//            player.move(0.0f,0.1f);

        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);
        window.display();
        window.clear();
    }
    return 0;
}
