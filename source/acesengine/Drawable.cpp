#include "Drawable.h"

namespace acesengine {
    class Drawable {
    protected:
        sf::Sprite sprite;
        sf::Texture texture;

    public:
        Drawable(float x, float y,
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

    protected:
        void setTexture(sf::Texture texture) {
            this->texture = texture;
        }

        sf::Texture getTexture() {
            return this->texture;
        }

    public:

        void draw(AcesWindow& acesWindow) {
            acesWindow.getWindow().draw(this->sprite);
        }

        void setPosition(float x, float y) {
            this->sprite.setPosition(sf::Vector2f(x, y));
        }

        sf::Vector2f getPosition() {
            return this->sprite.getPosition();
        }

        void setSprite(sf::Sprite sprite) {
            this->sprite = sprite;
        }

        sf::Sprite getSprite() {
            return this->sprite;
        }
    };
};