#include <SFML/Audio.hpp>
#include <grafica/root_directory.h>

/// Example works, its included in the ex_sfml_window
int main()
{
    sf::Sound sound;
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(Grafica::getPath("assets/audios/VoiceOverPack/congratulations.ogg").string())) {
        printf("Error loading audio");
        return -1;
    }
    printf("Beggining audio play");
    sound.setBuffer(buffer);
    sound.setVolume(50);
    sound.play();
    return 0;
}