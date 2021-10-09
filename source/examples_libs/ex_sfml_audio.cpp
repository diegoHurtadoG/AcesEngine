#include <SFML/Audio.hpp>

// Example works, its included in the ex_sfml_window
int main()
{
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
    return 0;
}