#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::Window window(sf::VideoMode(800, 600), "My window", sf::Style:Close | sf::Style:Resize);
    sf::RectangleShape card(sf::Vector2f(50.0f, 80.0f));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                Case sf::Event::Closed:
                    window.close();
                    break;
                Case sf::Event::Resized:
                    printf("The window has been resized, width: %i, heigth: %i", event.size.width, event.size.heigth);
                    break;
                Case sf::Event::TextEntered:
                    if (event.text.unicode < 128) {
                        printf("%c", event.text.unicode);
                    }
            }
                
        }


        window.draw(card);
    }

    return 0;
    }



}