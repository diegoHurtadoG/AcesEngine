#include <SFML/Graphics.hpp>

/// Example of the graphics library, opens a renderWindow
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape card(sf::Vector2f(50.0f, 80.0f));
    card.setFillColor(sf::Color::Red);
    
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

        window.draw(card);
        window.display();

    }
    return 0;
}