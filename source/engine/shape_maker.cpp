#include <SFML/Graphics.hpp>

/*
    This file will be defining common art used in board games
        such as cards and a dice for example
    Ill try to make classes (to make them rollable or diceable), but if I fail they will be
        functions with some random optiona values
*/



// This function is to test the art i will be doing in the functions

int main() {

    // Initialize a Render Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Close | sf::Style::Resize);

    // Make a rectangle to put on background
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("C:/Users/diego/OneDrive/Desktop/Ramos/2021-2/Arquitectura de Motores de Videojuegos/Proyecto/AcesEngine/assets/imgs/backgrounds/background_circles.jpg"))
    {
        printf("Error loading background texture");
        return -1;
    }
    sf::RectangleShape rectangle_test(sf::Vector2f(800.0f, 600.0f));
    rectangle_test.setTexture(&background_texture);


    // Initialize a texture of a card
    sf::Texture texture_test;
    // Ath (1, 1) of the .png, loads a 32x44 image
    if (!texture_test.loadFromFile("C:/Users/diego/OneDrive/Desktop/Ramos/2021-2/Arquitectura de Motores de Videojuegos/Proyecto/AcesEngine/assets/imgs/8BitDeckAssets.png", sf::IntRect(1, 1, 32, 44)))
    {
        printf("Error loading texture");
        return -1;
    }
    texture_test.setSmooth(true);


    // Initialize a Sprite to stick the texture in
    sf::Sprite sprite_test;
    sprite_test.setTexture(texture_test);
    sprite_test.setPosition(sf::Vector2f(33.0f, 0.0f));


    // run the program as long as the window is open
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

        window.draw(rectangle_test);
        window.draw(sprite_test);
        window.display();

    }
    return 0;
}