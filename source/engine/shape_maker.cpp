#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

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
    sf::Vector2f position;
    sf::Texture FrontTexture;
    sf::Texture BackTexture;
    sf::Sprite sprite;

    // Constructor
    public:
        Card(float x = 16.0f, float y = 22.0f, 
            std::string BackTexturePath = "C:/Users/diego/OneDrive/Desktop/Ramos/2021-2/Arquitectura de Motores de Videojuegos/Proyecto/AcesEngine/assets/imgs/8BitDeckAssets.png", 
            std::string FrontTexturePath = "C:/Users/diego/OneDrive/Desktop/Ramos/2021-2/Arquitectura de Motores de Videojuegos/Proyecto/AcesEngine/assets/imgs/8BitDeckAssets.png",
            int firstPointAssetXBACK = 1, int firstPointAssetYBACK = 1, int secondPointAssetXBACK = 32, int secondPointAssetYBACK = 44,
            int firstPointAssetXFRONT = 36, int firstPointAssetYFRONT = 1, int secondPointAssetXFRONT = 32, int secondPointAssetYFRONT = 44)
        {
            this->position = sf::Vector2f(x, y);
            if (!this->BackTexture.loadFromFile(BackTexturePath, sf::IntRect(firstPointAssetXBACK, firstPointAssetYBACK, secondPointAssetXBACK, secondPointAssetYBACK)))
            {
                printf("Error loading Back texture");
            }
            if (!this->FrontTexture.loadFromFile(FrontTexturePath, sf::IntRect(firstPointAssetXFRONT, firstPointAssetYFRONT, secondPointAssetXFRONT, secondPointAssetYFRONT)))
            {
                printf("Error loading Front texture");
            }
            this->sprite.setTexture(this->FrontTexture);
            this->sprite.setPosition(this->position);
            this->sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2, this->sprite.getTexture()->getSize().y / 2);
        }

    public:
        void setPosition(sf::Vector2f pos) {
            this->position = pos;
            this->sprite.setPosition(this->position);
        }
        sf::Vector2f getPosition() {
            return this->position;
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
            std::string backgroundPath = "C:/Users/diego/OneDrive/Desktop/Ramos/2021-2/Arquitectura de Motores de Videojuegos/Proyecto/AcesEngine/assets/imgs/backgrounds/0.jpg") {
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
                printf("%s\n", msg);
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



// This function is to test the art i will be doing in the functions

int main() {
    std::vector<Card*> card_array;

    AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();

    // Testing card class
    Card card_test;
    card_array.push_back(&card_test);

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
        card_test.draw(window);
        AcesWindow.display();

    }
    return 0;
}