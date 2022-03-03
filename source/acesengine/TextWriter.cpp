#include "TextWriter.h"
#include "root_directory.h"

namespace acesengine {

    TextWriter::TextWriter() {
        this->text = new sf::Text();
        sf::Font* font = new sf::Font();
        if (!font->loadFromFile(getPath("assets/fonts/Akronim-Regular.ttf").string()))
        {
            printf("Error loading font\n");
        }
        this->text->setFont(*font);
        this->text->setCharacterSize(24);
        this->text->setFillColor(sf::Color::White);
        this->text->setString("Placeholder string");
        this->text->setPosition(620, 25);
        }

    TextWriter::TextWriter(std::string fontPath) {
        this->text = new sf::Text();
        sf::Font* font = new sf::Font();
        if (!font->loadFromFile(fontPath))
        {
            printf("Error loading font\n");
        }
        this->text->setFont(*font);
        this->text->setCharacterSize(24);
        this->text->setFillColor(sf::Color::White);
        this->text->setString("Placeholder string");
        this->text->setPosition(620, 25);
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
