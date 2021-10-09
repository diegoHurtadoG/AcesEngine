#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main()
{
    /*
        Here we test the Audio library
    */
    sf::Sound sound;
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("C:/Users/diego/OneDrive/Desktop/Ramos/2021-2/Arquitectura de Motores de Videojuegos/Proyecto/AcesEngine/assets/audios/VoiceOverPack/Male/congratulations.ogg")) {
        printf("Error loading audio");
        return -1;
    }
    printf("Beggining audio play");
    sound.setBuffer(buffer);
    sound.setVolume(50);
    sound.play();


    /*
        Here we test the Window library
    */
    sf::Window window(sf::VideoMode(800, 600), "My window");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    
    return 0;
}