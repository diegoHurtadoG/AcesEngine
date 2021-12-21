#include "Drawable.h"

class AcesWindow;

namespace acesengine {

    Drawable::Drawable(float x, float y,
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

    void Drawable::setTexture(sf::Texture texture) {
        this->texture = texture;
    }

    sf::Texture Drawable::getTexture() {
        return this->texture;
    }

    void Drawable::draw(AcesWindow& acesWindow) {
        acesWindow.getWindow().draw(this->sprite);
    }

    void Drawable::setPosition(float x, float y) {
        this->sprite.setPosition(sf::Vector2f(x, y));
    }

    sf::Vector2f Drawable::getPosition() {
        return this->sprite.getPosition();
    }

    void Drawable::setSprite(sf::Sprite sprite) {
        this->sprite = sprite;
    }

    sf::Sprite Drawable::getSprite() {
        return this->sprite;
    }
};