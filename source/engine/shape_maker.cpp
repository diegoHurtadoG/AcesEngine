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


///  Defines a render window which allows drawing
/**
*   The window allows to personalize background, size, and a title
*/
class AcesWindow {
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    int heigth, width;
    std::string title, backgroundPath;
    sf::RectangleShape backgroundRectangle;

    public:
        /// Constructor
        /**
        * @param heigth int which defines the height of the window
        * @param width int which defines the width of the window
        * @param title string to name the window, "Default Title" by default
        * @param backgroundPath string to set the background of the window, precharged one as default
        */
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
        /// Window getter
        /**
        * @returns sf::RenderWindow& commonly used to give it to the draw functions
        */
        sf::RenderWindow& getWindow() {
            return this->window;
        }
        /// Size setter
        /**
        * @param height int new heigth of the window
        * @param width int new width of the window
        */
        void setSize(int heigth, int width) {
            this->window.setSize(sf::Vector2u(heigth, width));
        }
        /// Size getter
        /**
        * @returns sf::Vector2u which represents the actual size
        */
        sf::Vector2u getSize() {
            return this->window.getSize();
        }
        /// Texture Setter
        /** Sets a new background for the window
        * @param newPath string to reference the new asset
        */
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
        /// Update
        /**
        * Clears the window and draw the background
        */
        void update() {
            this->window.clear();
            this->window.draw(backgroundRectangle);
        }
        /// Display
        /**
        * Display the new window
        */
        void display() {
            this->window.display();
        }

};

/// Base class to an object with a draw() method
/**
*   Every drawable object will inherit from this class. This will have a sprite, and a texture, the sprite contains the position
*/
class Drawable {
protected:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    /// Constructor
    /** Default constructor for every drawable item
    * @param x a float argument
    * @param y a float argument
    * @param texturePath a string argument
    * @param firstPointAssetX an int argument, represent the first coordinate x of the front asset (if a tileset)
    * @param firstPointAssetY an int argument, represent the first coordinate y of the front asset (if a tileset)
    * @param secondPointAssetX an int argument, represent the second coordinate x of the front asset (if a tileset)
    * @param secondPointAssetY an int argument, represent the second coordinate y of the front asset (if a tileset)
    */
    Drawable(float x, float y,
        std::string texturePath,
        int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
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
    }

protected:
    /// Texture setter
    /**
    * @param texture sf::Texture defines texture of player
    */
    void setTexture(sf::Texture texture) {
        this->texture = texture;
    }
    /// Texture getter
    /**
    * @returns sf::Texture obtains current texture
    */
    sf::Texture getTexture() {
        return this->texture;
    }

public:
    /// Draw function
    /**
    * @param &renderWindow receives a reference to the window to draw
    */
    void draw(AcesWindow& acesWindow) {
        acesWindow.getWindow().draw(this->sprite);
    }
    /// Position setter
    /**
    * @param x float defines x coordinate
    * @param y float defines y coordinate
    */
    void setPosition(float x, float y) {
        this->sprite.setPosition(sf::Vector2f(x, y));
    }
    /// Position getter
    /**
    * @returns sf::Vector2f defines position
    */
    sf::Vector2f getPosition() {
        return this->sprite.getPosition();
    }
    /// Sprite setter
    /**
    * @param sprite sf::Sprite defines player Sprite
    */
    void setSprite(sf::Sprite sprite) {
        this->sprite = sprite;
    }
    /// Sprite getter
    /**
    * @returns sf::Sprite actual player sprite
    */
    sf::Sprite getSprite() {
        return this->sprite;
    }
};

/// Base class to an object that can be dragged in the screen
/**
*   This class already expands the drawable class (an object can not be dragged but not drawn)
*/
class Draggable : public Drawable {

public:
    /// Constructor
    /** Default constructor for every draggable item, just calls the drawable constructor
    * @param x a float argument
    * @param y a float argument
    * @param texturePath a string argument
    * @param firstPointAssetX an int argument, represent the first coordinate x of the front asset (if a tileset)
    * @param firstPointAssetY an int argument, represent the first coordinate y of the front asset (if a tileset)
    * @param secondPointAssetX an int argument, represent the second coordinate x of the front asset (if a tileset)
    * @param secondPointAssetY an int argument, represent the second coordinate y of the front asset (if a tileset)
    */
    Draggable(float x, float y,
        std::string texturePath,
        int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
        : Drawable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)
    {}

public:
    /// Enables the drag and drop of the current object
    /**
    * @param &window sf::RenderWindow reference to the window in which the cards will be drawn
    */
    void enableDrag(AcesWindow& acesWindow) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            auto mouse_pos = sf::Mouse::getPosition(acesWindow.getWindow()); // Mouse position relative to the window
            if ((*this).getSprite().getGlobalBounds().contains((float)mouse_pos.x, (float)mouse_pos.y)) {
                (*this).setPosition((float)mouse_pos.x, (float)mouse_pos.y);
            }
        }
    }
};

/// Defines a fast way to make a card, ideal to board games
/**
*   The cards in this class can have different assets, in the assets directory there is a pre loaded card tileset, the setters and getters
*   are public and it has the draw method, the turn over method is in process. The drag and drop is another method outside the class
* 
*   Has a Drawable component
*/
class Card : public Draggable {
    sf::Texture BackTexture;

public:
    /// Constructor
    /** Default constructor for the Card class
    * @param x a float argument, 16.0f by default
    * @param y a float argument, 22.0f by default
    * @param BackTexturePath a string argument, precharged asset by default
    * @param FrontTexturePath a string argument, precharged asset by default
    * @param firstPointAssetXBACK an int argument, represent the first coordinate x of the back asset (if a tileset), default value to fit the precharged tileset
    * @param firstPointAssetYBACK an int argument, represent the first coordinate y of the back asset (if a tileset), default value to fit the precharged tileset
    * @param secondPointAssetXBACK an int argument, represent the second coordinate x of the back asset (if a tileset), default value to fit the precharged tileset
    * @param secondPointAssetYBACK an int argument, represent the second coordinate y of the back asset (if a tileset), default value to fit the precharged tileset
    * @param firstPointAssetXFRONT an int argument, represent the first coordinate x of the front asset (if a tileset), default value to fit the precharged tileset
    * @param firstPointAssetYFRONT an int argument, represent the first coordinate y of the front asset (if a tileset), default value to fit the precharged tileset
    * @param secondPointAssetXFRONT an int argument, represent the second coordinate x of the front asset (if a tileset), default value to fit the precharged tileset
    * @param secondPointAssetYFRONT an int argument, represent the second coordinate y of the front asset (if a tileset), default value to fit the precharged tileset
    */
    Card(float x = 16.0f, float y = 22.0f,
        std::string BackTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
        std::string FrontTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
        int firstPointAssetXBACK = 1, int firstPointAssetYBACK = 1, int secondPointAssetXBACK = 32, int secondPointAssetYBACK = 44,
        int firstPointAssetXFRONT = 36, int firstPointAssetYFRONT = 1, int secondPointAssetXFRONT = 32, int secondPointAssetYFRONT = 44)
        : Draggable(x, y, FrontTexturePath, firstPointAssetXFRONT, firstPointAssetYFRONT, secondPointAssetXFRONT, secondPointAssetYFRONT)
    {
        if (!this->BackTexture.loadFromFile(BackTexturePath, sf::IntRect(firstPointAssetXBACK, firstPointAssetYBACK, secondPointAssetXBACK, secondPointAssetYBACK)))
        {
            printf("Error loading Back texture");
        }
    }

protected:
    /// Back Texture setter
    /**
    * @param texture sf::Texture, sets a texture for the BACK of the card
    */
    void setBackTexture(sf::Texture texture) {
        this->BackTexture = texture;
    }
    /// Back Texture Getter
    /**
    * @returns sf::Texture
    */
    sf::Texture getBackTexture() {
        return this->BackTexture;
    }

public:
    /// Turn card function (in progress)
    /**
    * Set the texture of the card to the inverse, simulating a turn over
    */
    void turn() {
        this->sprite.getTexture() == &this->texture ? this->sprite.setTexture(this->BackTexture) : this->sprite.setTexture(this->texture);
    }
};

/// Defines the things a player can do, contains input and draw propeties (remap in progress)
/**
*   The players accept a maximum of 2 players locally for now, with plans to expand to 4. The defined
*   controls are "WASD" and the arrows.
* 
*   Has a drawable component
*/      
class Player : public Drawable{
    int playerNumber;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    std::vector<int> movements; //0 if left, 1 if right, reset if up or down, check state by even or odd size.

    public:
        /// Constructor with default values
        /**
        * @param x float 0.0f by default, defines position
        * @param y float 0.0f by default, defines position
        * @param texturePath string path to define the texture of the player, precharged red by default
        * @param firstPointAssetX int Defines the first x coordinate of the asset in case of using a tileset
        * @param firstPointAssetY int Defines the first y coordinate of the asset in case of using a tileset
        * @param secondPointAssetX int Defines the second x coordinate of the asset in case of using a tileset
        * @param secondPointAssetY int Defines the second y coordinate of the asset in case of using a tileset
        * @param playerNumber int defines the number of the player, 1 by default and 2 if any other int
        */
        Player(float x = 0.0f, float y = 0.0f,
            std::string texturePath = Grafica::getPath("assets/imgs/dice and pieces/piece0.png").string(),
            int firstPointAssetX = 0, int firstPointAssetY = 0, int secondPointAssetX = 0, int secondPointAssetY = 0,
            int playerNumber = 1) : Drawable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)
        {
            this->playerNumber = playerNumber;
            this->remapInput(this->playerNumber);
        }

    public:
        /// Player number setter
        /**
        * @param playerNumber int defines player number with a maximum of 2 (4 in process)
        */
        void setPlayerNumber(int playerNumber) {
            this->playerNumber = playerNumber % 2;
            this->remapInput(playerNumber);
        }
        /// Player number getter
        /**
        * @returns int representing player number
        */
        int getPlayerNumber() {
            return this->playerNumber;
        }
        /// Input remapper to default values
        /**
        * @param playerNumber int depending on the player number set default controls
        */
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
        /// Input receiver and movement maker, define sequences and chords
        /**
        * Enables input in players
        */
        void receiveInput() { // Idea: Para hacer que con la secuencia cambien de color, puedo cargar las 4 texturas altiro a la clase y ir rotando en ese vector
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
        /// Defines if the player can move or not and draw it in the window, overrides the base class function because of the receiveInput method
        /**
        * @param &renderWindow sf::RenderWindow reference to the window to draw
        * @param move bool set if the player can move or not
        */
        void draw(AcesWindow& acesWindow, bool move = true) {
            acesWindow.getWindow().draw(this->sprite);
            if (move){
                this->receiveInput();
            }
        }

};

/// Defines a sound player to well... play sounds
/**
* One sound player can contain multiple sounds and store them with a string unique key
* If the unique key is repeated, the first one will be played, recorder is broken
*/
class SoundPlayer {
    std::map<std::string, sf::Sound> sounds;
    std::map<std::string, sf::SoundBuffer> buffers;
    std::map<std::string, sf::Music> musics;
    sf::SoundBufferRecorder recorder;
    bool recording = false;

    public:
        /// Default constructor
        /**
        *   Doesnt need to initialize anything
        */
        SoundPlayer() {};

    public:
        // Audio Methods
        /// Loads an audio to a buffer
        /**
        * @param uniqueName string defines the key of a sound
        * @param audioPath string tell where is the audio downloaded
        */
        void loadAudio(std::string uniqueName, std::string audioPath) {
            sf::Sound sound;
            sf::SoundBuffer buff;
            if (!buff.loadFromFile(audioPath)) {
                printf("Error loading audio");
            }
            this->buffers.emplace(uniqueName, buff);
            this->sounds.emplace(uniqueName, sound);
        }
        /// Plays an audio buffer
        /**
        * @param uniqueName string to identify the audio
        */
        void playAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).setBuffer(this->buffers.at(uniqueName));
            this->sounds.at(uniqueName).play();
        }
        /// Stops an audio buffer
        /**
        * @param uniqueName string to identify the audio
        */
        void stopAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).stop();
        }
        /// Set the volume of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @param vol int from 0 to 100, where 100 is the original volume
        */
        void setVolumeAudio(std::string uniqueName, int vol) {
            this->sounds.at(uniqueName).setVolume((float) vol);
        }
        /// Gets volume of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @returns float representing the actual volume
        */
        float getVolumeAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).getVolume();
        }
        /// Set the pitch of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @param value float representing the pitch, 1 is the default
        */
        void setPitchAudio(std::string uniqueName, float value) {
            this->sounds.at(uniqueName).setPitch(value);
        }
        /// Gets pitch of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @returns float representing the actual pitch
        */
        float getPitchAudio(std::string uniqueName) {
            this->sounds.at(uniqueName).getPitch();
        }
        /// Set the offset of an audio buffer
        /**
        * @param uniqueName string to identify the audio
        * @param value float representing the offset measured in seconds
        */
        void setPlayingOffsetAudio(std::string uniqueName, float offset) {
            this->sounds.at(uniqueName).setPlayingOffset(sf::seconds(offset));
        }
        /// Set if the audio buffer is meant to loop
        /**
        * @param uniqueName string to identify the audio
        */
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
        /// Plays a music buffer
        /**
        * @param uniqueName string to identify the music
        */
        void playMusic(std::string uniqueName) {
            this->musics.at(uniqueName).play();
        }
        /// Stops a music buffer
        /**
        * @param uniqueName string to identify the music
        */
        void stopMusic(std::string uniqueName) {
            this->musics.at(uniqueName).stop();
        }
        /// Set the volume of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @param vol int from 0 to 100, where 100 is the original volume
        */
        void setVolumeMusic(std::string uniqueName, int vol) {
            this->musics.at(uniqueName).setVolume((float)vol);
        }
        /// Gets volume of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @returns float representing the actual volume
        */
        float getVolumeMusic(std::string uniqueName) {
            this->musics.at(uniqueName).getVolume();
        }
        /// Set the pitch of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @param value float representing the pitch, 1 is the default
        */
        void setPitchMusic(std::string uniqueName, float value) {
            this->musics.at(uniqueName).setPitch(value);
        }
        /// Gets pitch of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @returns float representing the actual pitch
        */
        float getPitchMusic(std::string uniqueName) {
            this->musics.at(uniqueName).getPitch();
        }
        /// Set the offset of a music buffer
        /**
        * @param uniqueName string to identify the music
        * @param value float representing the offset measured in seconds
        */
        float setPlayingOffsetMusic(std::string uniqueName, float offset) {
            this->musics.at(uniqueName).setPlayingOffset(sf::seconds(offset));
        }
        /// Set if the music buffer is meant to loop
        /**
        * @param uniqueName string to identify the music
        */
        void loopMusic(std::string uniqueName) {
            this->musics.at(uniqueName).setLoop(!this->musics.at(uniqueName).getLoop());
        }
        /// Starts the recording
        void startRecordingSound() {
            if (!sf::SoundBufferRecorder::isAvailable())
            {
                printf("Audio capture not available in system");
            }
            this->recorder.start();
            this->recording = true;
        }
        /// Pauses the recording, can resume
        void pauseRecordingSound() {
            this->recorder.stop();
            this->recording = false;
        }
        /// Resumes the paused recording
        void resumeRecordingSound() {
            if (!sf::SoundBufferRecorder::isAvailable())
            {
                printf("Audio capture not available in system");
            }
            this->recorder.start();
            this->recording = true;
        }
        /// Finishes the recording
        /**
        * @param uniqueName string defines the name under the record will be saved in a buffer to play
        */
        void stopRecordingSound(std::string uniqueName) {
            this->recorder.stop();
            this->recording = false;
            const sf::SoundBuffer& buffer = recorder.getBuffer();
            this->sounds.emplace(uniqueName, buffer);
        }
        /// Switches the inner state of the recorder
        void changeRecordingState() {
            this->recording = !this->recording;
        }
        /// Get the inner recording state
        /**
        * @returns bool representing if the recorder is active or not
        */
        bool getRecordingState() {
            return this->recording;
        }

};

/// Defines a text writer to render text on screen (broken)
/**
* The text writer is simple to use and is used to display text on the screen, comes with preloaded 
* fonts and options, has methods to customize the text
*/
class TextWriter {
    sf::Text text;

    public:
        /// Constructor, preloads the available options to fast and easy use
        TextWriter() {
            sf::Font font;
            if (!font.loadFromFile(Grafica::getPath("assets/fonts/Akronim-Regular.ttf").string()))
            {
                printf("Error loading font");
            }
            this->text.setFont(font);
            this->text.setCharacterSize(24);
            this->text.setFillColor(sf::Color::Black);
            this->text.setString("Placeholder string");
        }
        /// Constructor, uses an alternative font
        /** 
        * @param fontPath string loads a font from a given directory
        */
        TextWriter(std::string fontPath) {
            sf::Font font;
            if (!font.loadFromFile(fontPath))
            {
                printf("Error loading font");
            }
            this->text.setFont(font);
            this->text.setCharacterSize(24);
            this->text.setFillColor(sf::Color::Black);
            this->text.setString("Placeholder string");
        }

    public:
        /// Sets a string to draw
        /**
        * @param text string defines the string to display
        */
        void setString(std::string text) {
            this->text.setString(text);
        }
        /// Sets a size to the text
        /**
        * @param valueInPixels int the size of the text measured in pixels
        */
        void setSize(int valueInPixels) {
            this->text.setCharacterSize(valueInPixels);
        }
        /// Bolds the given text
        void boldText() {
            this->text.setStyle(this->text.getStyle() | sf::Text::Bold);
        }
        /// Underlines the given text
        void underlineText() {
            this->text.setStyle(this->text.getStyle() | sf::Text::Underlined);
        }
        /// Sets the position of the text
        /**
        * @param float x sets the x coordinate
        * @param float y sets the y coordinate
        */
        void setPosition(float x, float y) {
            this->text.setPosition(sf::Vector2f(x, y));
        }
        /// Draws the text in the given window
        /**
        * @param &renderWindow the window in which to display the text
        */
        void draw(AcesWindow& acesWindow) {
            acesWindow.getWindow().draw(this->text);
        }
};

/// Enables the drag and drop of objects in the array
/**
* @param drag_vector std::vector<Draggable*> used to define which objects are movables, accept every object that uses the Draggable class
* @param acesWindow AcesWindow& reference to the window in which the cards will be drawn
*/
void enableDraggables(std::vector<Draggable*> drag_vector, AcesWindow& acesWindow) {
    for (auto i = drag_vector.begin(); i != drag_vector.end(); i++) {
        (**i).enableDrag(acesWindow);
    }
}

// This function is to test the art I will be doing in the functions

int main() {
    std::vector<Draggable*> draggable_array;

    AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();

    // Testing Card class
    Card card_test;
    draggable_array.push_back(&card_test); // TODO: Automatizar (si se puede de forma facil y sin restringir todo a solo cartas y dados)

    // Testing Player class
    Player player1;
    Player player2(0.0f, 0.0f, Grafica::getPath("assets/imgs/dice and pieces/piece1.png").string(), 0, 0, 0, 0, 2);

    // Testing SoundPlayer class
    
    SoundPlayer acesSoundPlayer;
    acesSoundPlayer.loadAudio("congratulations", Grafica::getPath("assets/audios/VoiceOverPack/Male/congratulations.ogg").string());
    acesSoundPlayer.playAudio("congratulations");

    acesSoundPlayer.loadAudio("correct", Grafica::getPath("assets/audios/VoiceOverPack/Female/correct.ogg").string());

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
                else if (event.key.code == sf::Keyboard::Key::C) {
                    acesSoundPlayer.playAudio("correct");
                }
            }
        }

        enableDraggables(draggable_array, AcesWindow);
        AcesWindow.update();
        card_test.draw(AcesWindow); // Podria poner un for en card_array y dibujar todas
        player1.draw(AcesWindow);
        player2.draw(AcesWindow);
        AcesWindow.display();

    }
    return 0;
}
