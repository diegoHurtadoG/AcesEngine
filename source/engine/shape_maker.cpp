#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <grafica/root_directory.h>
#include <stdlib.h>

/*
    This file will be defining common art used in board games
        such as cards and a dice for example
*/

// TODO: Pegarse a la pauta y ver puntajes
//      - Idea: Para luces, si quiero hacer, podria hacer un tipo de memorize oscuro y que el mouse sea una fuente de luz
//      - Para el remapeo de controles solo se puede la opcion del switch/case gigante


// TODO: Classes for cards and dice
//      Cards: - Position (Drag and Drop?)
//             - Assets
//             - OnClick -> show reverse
//      Dice:  - Position (dinamic?)
//             - Asset
//             - OnClick -> Roll

class Card {
    sf::Texture FrontTexture;
    sf::Texture BackTexture;
    sf::Sprite sprite;

    // Constructor
    public:
        Card(float x = 16.0f, float y = 22.0f, 
            std::string BackTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
            std::string FrontTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
            int firstPointAssetXBACK = 1, int firstPointAssetYBACK = 1, int secondPointAssetXBACK = 32, int secondPointAssetYBACK = 44,
            int firstPointAssetXFRONT = 36, int firstPointAssetYFRONT = 1, int secondPointAssetXFRONT = 32, int secondPointAssetYFRONT = 44)
        {
            if (!this->BackTexture.loadFromFile(BackTexturePath, sf::IntRect(firstPointAssetXBACK, firstPointAssetYBACK, secondPointAssetXBACK, secondPointAssetYBACK)))
            {
                printf("Error loading Back texture");
            }
            if (!this->FrontTexture.loadFromFile(FrontTexturePath, sf::IntRect(firstPointAssetXFRONT, firstPointAssetYFRONT, secondPointAssetXFRONT, secondPointAssetYFRONT)))
            {
                printf("Error loading Front texture");
            }
            this->sprite.setTexture(this->FrontTexture);
            this->sprite.setPosition(sf::Vector2f(x, y));
            this->sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2, this->sprite.getTexture()->getSize().y / 2);
        }

    public:
        void setPosition(sf::Vector2f pos) {
            this->sprite.setPosition(pos);
        }
        sf::Vector2f getPosition() {
            return this->sprite.getPosition();
        }
        void setBackTexture(sf::Texture texture) {
            this->BackTexture = texture;
        }
        sf::Texture getBackTexture() {
            return this->BackTexture;
        }
        void setFrontTexture(sf::Texture texture) {
            this->FrontTexture = texture;
        }
        sf::Texture getFrontTexture() {
            return this->FrontTexture;
        }
        void setSprite(sf::Sprite sprite) {
            this->sprite = sprite;
        }
        sf::Sprite getSprite() {
            return this->sprite;
        }

        void draw(sf::RenderWindow &renderWindow) {
            renderWindow.draw(this->sprite);
        }

        void turn() {
            this->sprite.getTexture() == &this->FrontTexture ? this->sprite.setTexture(this->BackTexture) : this->sprite.setTexture(this->FrontTexture);
        }
};

class AcesWindow {
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    int heigth, width;
    std::string title, backgroundPath;
    sf::RectangleShape backgroundRectangle;

    public:
        AcesWindow(int heigth, int width, std::string title = "Default Title",
            std::string backgroundPath = Grafica::getPath("assets/imgs/backgrounds/0.jpg").string()) {
            this->width = width;
            this->heigth = heigth;
            this->title = title;
            this->backgroundPath = backgroundPath;
            this->window.create(sf::VideoMode(heigth, width), title, sf::Style::Close | sf::Style::Resize); // TODO: Estudiar esto, hay un posible 4to parametro
            try {
                if (!this->backgroundTexture.loadFromFile(this->backgroundPath))
                {
                    throw("Error loading texture");
                }
                backgroundRectangle.setSize(sf::Vector2f((float) heigth,(float) width));
                backgroundRectangle.setTexture(&(this->backgroundTexture));
            }
            catch (std::string msg) {
                std::cout << msg << "\n";;
            }
        }

    public:
        sf::RenderWindow& getWindow() {
            return this->window;
        }
        void setSize(int heigth, int width) {
            this->window.setSize(sf::Vector2u(heigth, width));
        }
        sf::Vector2u getSize() {
            return this->window.getSize();
        }
        void setTexture(std::string newPath) {
            try {
                if (!this->backgroundTexture.loadFromFile(newPath))
                {
                    throw("Error loading texture");
                }
                // Test this to see if texture really changes (not urgent)
            }
            catch (std::string msg) {
                std::cout << msg;
            }
        }
        void update() {
            this->window.clear();
            this->window.draw(backgroundRectangle);
        }
        void display() {
            this->window.display();
        }

};

void dragAndDropCards(std::vector<Card*> card_vector, sf::RenderWindow &window) { // Se rompe con el resize
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        for (auto i = card_vector.begin(); i != card_vector.end(); i++) {
            if ((**i).getSprite().getGlobalBounds().contains((float)mouse_pos.x, (float)mouse_pos.y)) {
                (**i).setPosition(sf::Vector2f((float)mouse_pos.x, (float)mouse_pos.y));
            }
        }
    }
}

class Player {
    sf::Texture texture;
    sf::Sprite sprite;
    int playerNumber;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    std::vector<int> movements; //0 if left, 1 if right, reset if up or down, check state by even or odd size.

    public:
        Player(float x = 0.0f, float y = 0.0f,
            std::string texturePath = Grafica::getPath("assets/imgs/dice and pieces/piece0.png").string(),
            int firstPointAssetX = 0, int firstPointAssetY = 0, int secondPointAssetX = 0, int secondPointAssetY = 0,
            int playerNumber = 1)
        {
            if ((firstPointAssetX != secondPointAssetX) && (firstPointAssetY != secondPointAssetY)) {
                if (!this->texture.loadFromFile(texturePath, sf::IntRect(firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)))
                {
                    printf("Error loading Back texture");
                }
            }
            else {
                if (!this->texture.loadFromFile(texturePath))
                {
                    printf("Error loading Back texture");
                }
            }
            this->sprite.setTexture(this->texture);
            this->sprite.setPosition(sf::Vector2f(x, y));
            this->sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2, this->sprite.getTexture()->getSize().y / 2);
            this->playerNumber = playerNumber;
            this->remapInput(this->playerNumber);
           
        }

    public:
        void setPosition(sf::Vector2f pos) {
            this->sprite.setPosition(pos);
        }
        sf::Vector2f getPosition() {
            return this->sprite.getPosition();
        }
        void setTexture(sf::Texture texture) {
            this->texture = texture;
        }
        sf::Texture getTexture() {
            return this->texture;
        }
        void setSprite(sf::Sprite sprite) {
            this->sprite = sprite;
        }
        sf::Sprite getSprite() {
            return this->sprite;
        }
        void setPlayerNumber(int playerNumber) {
            this->playerNumber = playerNumber;
            this->remapInput(playerNumber);
        }
        int getPlayerNumber() {
            return this->playerNumber;
        }

        void remapInput(int playerNumber) {
            if (playerNumber == 1) {
                this->left = sf::Keyboard::Key::A;
                this->right = sf::Keyboard::Key::D;
                this->up = sf::Keyboard::Key::W;
                this->down = sf::Keyboard::Key::S;
            }
            else if (playerNumber != 1) {
                this->left = sf::Keyboard::Key::Left;
                this->right = sf::Keyboard::Key::Right;
                this->up = sf::Keyboard::Key::Up;
                this->down = sf::Keyboard::Key::Down;
            }
        }

        void receiveInput() {
            if (sf::Keyboard::isKeyPressed(this->left)) {
                this->sprite.move(-0.2f, 0.0f);

                // Beggining sequence conditions
                if (this->movements.empty() && !(sf::Keyboard::isKeyPressed(this->right))) {
                    this->movements.push_back(0);
                }
                else if ( !(this->movements.empty()) && (this->movements.back() == 1) && !(sf::Keyboard::isKeyPressed(this->right))) {
                    this->movements.push_back(0);
                }
                if ( !(this->movements.empty())&& this->movements.size() >= 5) { //Lo que pase cuando se cumpla la combinacion, pense en cambiar sprites, pero no funciono (creo que por algo de memoria)
                    printf("Side to side combination executing");
                    this->movements.clear();
                    this->sprite.move(20.0f, 20.0f);
                }
            }
            if (sf::Keyboard::isKeyPressed(this->right)) {
                this->sprite.move(0.2f, 0.0f);

                // Beggining sequence conditions
                if (!(this->movements.empty()) && !(sf::Keyboard::isKeyPressed(this->left))) {
                    if (this->movements.back() == 0) {
                        this->movements.push_back(1);
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(this->up)) {
                this->sprite.move(0.0f, -0.2f);

                // Clearing sequence array
                this->movements.clear();
            }
            if (sf::Keyboard::isKeyPressed(this->down)) {
                this->sprite.move(0.0f, 0.2f);

                // Clearing sequence array
                this->movements.clear();
            }
        }

        void draw(sf::RenderWindow& renderWindow, bool move = true) {
            renderWindow.draw(this->sprite);
            if (move){
                this->receiveInput();
            }
        }

};

class SoundPlayer {
    std::map<std::string, sf::Sound> sounds;
    std::map<std::string, sf::SoundBuffer> buffers;
    std::map<std::string, sf::Music> musics;
    sf::SoundBufferRecorder recorder;
    bool recording = false;

    public:
        SoundPlayer() {};

    public:
        // Audio Methods

        void loadAudio(std::string uniqueName, std::string audioPath) {
            sf::Sound sound;
            sf::SoundBuffer buff;
            if (!buff.loadFromFile(audioPath)) {
                printf("Error loading audio");
            }
            this->buffers.emplace(uniqueName, buff);
            this->sounds.emplace(uniqueName, sound);
        }

        void playAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).setBuffer(this->buffers.at(uniqueName));
            this->sounds.at(uniqueName).play();
        }

        void stopAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).stop();
        }

        void setVolumeAudio(std::string uniqueName, int vol) {
            this->sounds.at(uniqueName).setVolume((float) vol);
        }

        float getVolumeAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).getVolume();
        }

        void setPitchAudio(std::string uniqueName, float value) {
            this->sounds.at(uniqueName).setPitch(value);
        }

        float getPitchAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).getPitch();
        }

        // Offset in seconds
        float setPlayingOffsetAudio(std::string uniqueName, float offset) {
            this->sounds.at(uniqueName).setPlayingOffset(sf::seconds(offset));
        }

        void loopAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).setLoop(!this->sounds.at(uniqueName).getLoop());
        }

        // Music methods

        // This one throwing error with assimp (?)
        /*
        void loadMusic(std::string uniqueName, std::string musicPath) {
            sf::Music music;
            if (!music.openFromFile(musicPath)) {
                printf("Error loading music");
            }
            this->musics.emplace(uniqueName, music);
        }
        */

        void playMusic(std::string uniqueName) {
            this->musics.at(uniqueName).play();
        }

        void stopMusic(std::string uniqueName) {
            this->musics.at(uniqueName).stop();
        }

        void setVolumeMusic(std::string uniqueName, int vol) {
            this->musics.at(uniqueName).setVolume((float)vol);
        }

        float getVolumeMusic(std::string uniqueName) {
            this->musics.at(uniqueName).getVolume();
        }

        void setPitchMusic(std::string uniqueName, float value) {
            this->musics.at(uniqueName).setPitch(value);
        }

        float getPitchMusic(std::string uniqueName) {
            this->musics.at(uniqueName).getPitch();
        }

        // Offset in seconds
        float setPlayingOffsetMusic(std::string uniqueName, float offset) {
            this->musics.at(uniqueName).setPlayingOffset(sf::seconds(offset));
        }

        void loopMusic(std::string uniqueName) {
            this->musics.at(uniqueName).setLoop(!this->musics.at(uniqueName).getLoop());
        }
        
        void startRecordingSound() {
            if (!sf::SoundBufferRecorder::isAvailable())
            {
                printf("Audio capture not available in system");
            }
            this->recorder.start();
            this->recording = true;
        }

        void pauseRecordingSound() {
            this->recorder.stop();
            this->recording = false;
        }

        void resumeRecordingSound() {
            if (!sf::SoundBufferRecorder::isAvailable())
            {
                printf("Audio capture not available in system");
            }
            this->recorder.start();
            this->recording = true;
        }

        void stopRecordingSound(std::string uniqueName) {
            this->recorder.stop();
            this->recording = false;
            const sf::SoundBuffer& buffer = recorder.getBuffer();
            this->sounds.emplace(uniqueName, buffer);
        }

        void changeRecordingState() {
            this->recording = !this->recording;
        }

        bool getRecordingState() {
            return this->recording;
        }

};



// This function is to test the art i will be doing in the functions

int main() {
    std::vector<Card*> card_array;

    AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();

    // Testing Card class
    Card card_test;
    card_array.push_back(&card_test); // TODO: Automatizar (si se puede de forma facil y sin restringir todo a solo cartas y dados)

    // Testing Player class
    Player player1;
    Player player2(0.0f, 0.0f, Grafica::getPath("assets/imgs/dice and pieces/piece1.png").string(), 0, 0, 0, 0, 2);

    // Testing SoundPlayer class
    
    SoundPlayer acesSoundPlayer;
    acesSoundPlayer.loadAudio("congratulations", Grafica::getPath("assets/audios/VoiceOverPack/Male/congratulations.ogg").string());
    acesSoundPlayer.playAudio("congratulations");

    acesSoundPlayer.loadAudio("correct", Grafica::getPath("assets/audios/VoiceOverPack/Female/correct.ogg").string());
    acesSoundPlayer.playAudio("correct");
    

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
                if (event.key.code == sf::Keyboard::Key::R && false) { // TODO: Fix recording, fails due to memory error
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
            }


        }

        dragAndDropCards(card_array, window);
        AcesWindow.update();
        card_test.draw(window); // Podria poner un for en card_array y dibujar todas
        player1.draw(window);
        player2.draw(window);
        AcesWindow.display();

    }
    return 0;
}