#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <grafica/root_directory.h>

/*
    This file will be defining common art used in board games
        such as cards and a dice for example
    Ill try to make classes (to make them rollable or diceable), but if I fail they will be
        functions with some random optiona values
*/

// TODO: Pegarse a la pauta y ver puntajes
//      - Hacer modulo audio por ejemplo
//      - Idea: Cada objeto que se hace en pantalla meterlo a un [], para que sea mas facil manejar las posiciones y clicks
//      - Idea: Que las fichas que vienen en la carpeta de fotos sean los jugadores (movimientos con inputs)
//      - Idea: Para luces, si quiero hacer, podria hacer un tipo de memorize oscuro y que el mouse sea una fuente de luz

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
            this->window.create(sf::VideoMode(heigth, width), title, sf::Style::Close | sf::Style::Resize); // Estudiar esto, hay un posible 4to parametro
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
                printf("%s\n", msg);
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

void dragAndDropCards(std::vector<Card*> card_vector, sf::RenderWindow &window) {
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


    public:
        Player(float x = 0.0f, float y = 0.0f,
            std::string texturePath = Grafica::getPath("assets/imgs/dice and pieces/red piece.png").string(),
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
            }
            if (sf::Keyboard::isKeyPressed(this->right)) {
                this->sprite.move(0.2f, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(this->up)) {
                this->sprite.move(0.0f, -0.2f);
            }
            if (sf::Keyboard::isKeyPressed(this->down)) {
                this->sprite.move(0.0f, 0.2f);
            }
        }

        void draw(sf::RenderWindow& renderWindow, bool move = true) {
            renderWindow.draw(this->sprite);
            if (move){
                this->receiveInput();
            }
        }

};



// This function is to test the art i will be doing in the functions

int main() {
    std::vector<Card*> card_array;

    AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();

    // Testing card class
    Card card_test;
    card_array.push_back(&card_test); // TODO: Automatizar (si se puede de forma facil y sin restringir todo a solo cartas y dados)

    // Testing player class
    Player player1;
    Player player2(0.0f, 0.0f, Grafica::getPath("assets/imgs/dice and pieces/green piece.png").string(), 0, 0, 0, 0, 2);

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
                printf("The window has been resized, width: %i, height: %i", event.size.width, event.size.height);
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode < 128) {
                    printf("%c", event.text.unicode);
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