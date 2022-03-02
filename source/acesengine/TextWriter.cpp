#include "TextWriter.h"
#include "root_directory.h"

namespace acesengine {

    TextWriter::TextWriter() {
            sf::Font* font;
            if (!font->loadFromFile(getPath("assets/fonts/Akronim-Regular.ttf").string()))
            {
                printf("Error loading font");
            }
            this->text->setFont(*font);
            this->text->setCharacterSize(24);
            this->text->setFillColor(sf::Color::Black);
            this->text->setString("Placeholder string");
            this->text->setPosition(300, 300);
        }

    TextWriter::TextWriter(std::string fontPath) {
            sf::Font* font;
            if (!font->loadFromFile(fontPath))
            {
                printf("Error loading font");
            }
            this->text->setFont(*font);
            this->text->setCharacterSize(24);
            this->text->setFillColor(sf::Color::Black);
            this->text->setString("Placeholder string");
        }

    void TextWriter::setString(std::string text) {
        this->text->setString(text);
    }

    void TextWriter::setSize(int valueInPixels) {
        this->text->setCharacterSize(valueInPixels);
    }

    void TextWriter::boldText() {
        this->text->setStyle(this->text->getStyle() | sf::Text::Bold);
    }

    void TextWriter::underlineText() {
        this->text->setStyle(this->text->getStyle() | sf::Text::Underlined);
    }

    void TextWriter::setPosition(float x, float y) {
        this->text->setPosition(sf::Vector2f(x, y));
    }

    void TextWriter::draw(AcesWindow& acesWindow) {
        acesWindow.getWindow().draw(*this->text);
    }
};
