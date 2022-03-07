#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <acesengine/root_directory.h>
#include <acesengine/AcesWindow.h>
#include <acesengine/Drawable.h>
#include <acesengine/Draggable.h>
#include <acesengine/Inputable.h>
#include <acesengine/Player.h>
#include <acesengine/Card.h>
#include <acesengine/SoundPlayer.h>
#include <acesengine/TextWriter.h>
#include <acesengine/root_directory.h>
#include <acesengine/acesengine.h>
#include <acesengine/Dice.h>
#include <acesengine/ProfilerFPS.h>

// This function is to test the art I will be doing in the functions
int main() {
    srand(time(NULL));
    namespace ae = acesengine;

    std::vector<ae::Draggable*> draggable_array;
    std::vector<ae::Inputable*> inputable_array;

    ae::AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();

    // Testing Player class
    ae::Player player1(200.0f, 495.0f, ae::getPath("assets/imgs/dice and pieces/piece3.png").string(), 0, 0, 0, 0, 1);
    ae::Player player2(185.0f, 515.0f, ae::getPath("assets/imgs/dice and pieces/piece2.png").string(), 0, 0, 0, 0, 2);

    // Change this to draggable_array
    inputable_array.push_back(&player1);
    inputable_array.push_back(&player2);

    // Testing SoundPlayer class
    ae::SoundPlayer acesSoundPlayer;
    acesSoundPlayer.loadAudio("go", ae::getPath("assets/audios/VoiceOverPack/Female/go.ogg").string());

    // Background Music
    acesSoundPlayer.loadAudio("music", ae::getPath("assets/audios/BackgroundMusic/POL-fragments-short.wav").string());
    acesSoundPlayer.loopAudio("music");


    // Making the board for the game
    ae::Drawable board((float)AcesWindow.getSize().x / 2, (float)AcesWindow.getSize().y / 2,
        ae::getPath("assets/imgs/snakes_and_ladders_board.png").string(), 0, 0, 492, 492);

    // Credits:
    printf("Music: 'Fragments', from PlayOnLoop.com\nLicensed under Creative Commons by Attribution 4.0\n");
    acesSoundPlayer.playAudio("music");
    acesSoundPlayer.setVolumeAudio("music", 50);
    bool playing = true;


    // Testing the Dice class (and the Animation inside it)
    ae::Dice dice;

    // Testing the ProfilerFPS class
    ae::ProfilerFPS profilerfps;

    // Testing the Text Writer class
    ae::TextWriter textWriter;

    // run the program as long as the window is open
    // TODO: abstract while loop to use AcesWindow instead of window
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                printf("The window has been resized, width: %i, height: %i\n", event.size.width, event.size.height);
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Key::C) {
                    acesSoundPlayer.playAudio("go");
                }
                else if (event.key.code == sf::Keyboard::Key::R) {
                    printf("The rolled number is: %i\n", rand() % 6 + 1);
                }
                else if (event.key.code == sf::Keyboard::Key::M) {
                    if (playing){
                        acesSoundPlayer.stopAudio("music");
                        playing = !playing;
                    }
                    else {
                        acesSoundPlayer.playAudio("music");
                        playing = !playing;
                    }
                }
                else if (event.key.code == sf::Keyboard::Key::R) {
                    int value;
                    int time = (rand() % 200 + 100);
                    do {
                        value = dice.roll(time);
                        //printf("Rolling.\n");
                        dice.draw(AcesWindow);
                        AcesWindow.display();
                        time = time - 20;
                    } while (time > 50);
                    printf("Dice has been rolled, value: %i\n", value);
                }
                else if (event.key.code == sf::Keyboard::Key::Num1) {
                    acesSoundPlayer.setVolumeAudio("music", acesSoundPlayer.getVolumeAudio("music") - 10);;
                }
                else if (event.key.code == sf::Keyboard::Key::Num2) {
                    acesSoundPlayer.setVolumeAudio("music", acesSoundPlayer.getVolumeAudio("music") + 10);
                }
                else if (event.key.code == sf::Keyboard::Key::Num3) {
                    acesSoundPlayer.setPitchAudio("music", acesSoundPlayer.getPitchAudio("music") + 0.1f);
                }
                else if (event.key.code == sf::Keyboard::Key::Num4) {
                    acesSoundPlayer.setPitchAudio("music", acesSoundPlayer.getPitchAudio("music") - 0.1f);
                }
            }
        }

        AcesWindow.update();
        board.draw(AcesWindow);

        dice.draw(AcesWindow);
        ae::enableDraggables(draggable_array, AcesWindow);
        ae::enableInputables(inputable_array, AcesWindow);

        profilerfps.update();
        textWriter.setString("FPS: " + std::to_string(profilerfps.getFPS()));
        textWriter.draw(AcesWindow);

        AcesWindow.display();
    }

    return 0;
}
