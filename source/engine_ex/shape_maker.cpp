#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
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

/*
    This file will be defining common art used in board games
        such as cards and a dice for example
*/

/*
 EXTRA MILESTONE 1 TODO: Pegarse a la pauta y ver puntajes
      - Para el remapeo de controles solo se puede la opcion del switch/case gigante
      - El text writer podria tener un vector de strings a dibujar y que todos tengan la misma fuente y cosas, ver si conviene
*/

/*
 TODO MILESTONE 2: TERMINAR TEXT RENDERER Y EN VOLA EL RECORDER -> GANAR BONUS DE AVANCES MILESTONE 1
 
 MILESTONE 2 TODO: Classes for cards and dice, Usando Component Model
      Cards: - Position (Drag and Drop?)
             - Assets
             - OnClick -> show reverse
      Dice:  - Position (dinamic?)
             - Asset
             - OnClick -> Roll
*/

// This function is to test the art I will be doing in the functions
int main() {
    namespace ae = acesengine;

    std::vector<ae::Draggable*> draggable_array;
    std::vector<ae::Inputable*> inputable_array;

    ae::AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();

    // Testing Card class
    ae::Card card_test;
    draggable_array.push_back(&card_test); // TODO: Automatizar (si se puede de forma facil y sin restringir todo a solo cartas y dados)

    // Testing Player class
    ae::Player player1;
    ae::Player player2(0.0f, 0.0f, ae::getPath("assets/imgs/dice and pieces/piece1.png").string(), 0, 0, 0, 0, 2);

    // Change this to draggable_array
    inputable_array.push_back(&player1);
    inputable_array.push_back(&player2);

    // Testing SoundPlayer class
    ae::SoundPlayer acesSoundPlayer;
    acesSoundPlayer.loadAudio("congratulations", ae::getPath("assets/audios/VoiceOverPack/Male/congratulations.ogg").string());

    acesSoundPlayer.loadAudio("correct", ae::getPath("assets/audios/VoiceOverPack/Female/correct.ogg").string());

    // Testing the Dice class (and the Animation inside it)
    ae::Dice dice;

    // Testing the ProfilerFPS class
    ae::ProfilerFPS profilerfps;

    // Testing the Text Writer class
    ae::TextWriter textWriter;

    // run the program as long as the window is open
    while (AcesWindow.getWindow().isOpen())
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
                if (event.key.code == sf::Keyboard::Key::F && false) { // TODO: Fix recording, fails due to memory error
                    printf("began recording\n");
                    if (acesSoundPlayer.getRecordingState()) {
                        std::string recording_name = "Grabacion_test";
                        acesSoundPlayer.stopRecordingSound(recording_name);
                        acesSoundPlayer.playAudio(recording_name);
                    }
                    else {
                        acesSoundPlayer.startRecordingSound();
                    }
                    
                }
                else if (event.key.code == sf::Keyboard::Key::C) {
                    acesSoundPlayer.playAudio("correct");
                }
                else if (event.key.code == sf::Keyboard::Key::V) {
                    acesSoundPlayer.playAudio("congratulations");
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
            }
        }

        AcesWindow.update();

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
