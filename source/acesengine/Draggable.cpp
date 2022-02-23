#include "Draggable.h"

class Drawable;
class AcesWindow;

namespace acesengine {

    Draggable::Draggable(float x, float y,
        std::string texturePath,
        int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
    {
        if ((firstPointAssetX != secondPointAssetX) && (firstPointAssetY != secondPointAssetY)) {
            if (!this->texture.loadFromFile(texturePath, sf::IntRect(firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)))
            {
                printf("Draggable: Error loading Back texture rectangle\n");
            }
        }
        else {
            if (!this->texture.loadFromFile(texturePath))
            {
                printf("Draggable: Error loading Back texture\n");
            }
        }
        this->sprite.setTexture(this->texture);
        this->sprite.setPosition(sf::Vector2f(x, y));
        this->sprite.setOrigin(this->sprite.getTexture()->getSize().x / 2, this->sprite.getTexture()->getSize().y / 2);
    }

    void Draggable::enableDrag(AcesWindow& acesWindow) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            auto mouse_pos = sf::Mouse::getPosition(acesWindow.getWindow()); // Mouse position relative to the window
            if ((*this).getSprite().getGlobalBounds().contains((float)mouse_pos.x, (float)mouse_pos.y)) {
                (*this).setPosition((float)mouse_pos.x, (float)mouse_pos.y);
            }
        }
    }

    void Draggable::setTexture(sf::Texture texture) {
        this->texture = texture;
    }

    sf::Texture Draggable::getTexture() {
        return this->texture;
    }

    void Draggable::draw(AcesWindow& acesWindow) {
        acesWindow.getWindow().draw(this->sprite);
    }

    void Draggable::setPosition(float x, float y) {
        this->sprite.setPosition(sf::Vector2f(x, y));
    }

    sf::Vector2f Draggable::getPosition() {
        return this->sprite.getPosition();
    }

    void Draggable::setSprite(sf::Sprite sprite) {
        this->sprite = sprite;
    }

    sf::Sprite Draggable::getSprite() {
        return this->sprite;
    }

}