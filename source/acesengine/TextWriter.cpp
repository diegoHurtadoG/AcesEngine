#include "TextWriter.h"

namespace acesengine {

    class TextWriter {
        sf::Text text;

    public:
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

        void setString(std::string text) {
            this->text.setString(text);
        }

        void setSize(int valueInPixels) {
            this->text.setCharacterSize(valueInPixels);
        }

        void boldText() {
            this->text.setStyle(this->text.getStyle() | sf::Text::Bold);
        }

        void underlineText() {
            this->text.setStyle(this->text.getStyle() | sf::Text::Underlined);
        }

        void setPosition(float x, float y) {
            this->text.setPosition(sf::Vector2f(x, y));
        }

        void draw(AcesWindow& acesWindow) {
            acesWindow.getWindow().draw(this->text);
        }
    };
};
