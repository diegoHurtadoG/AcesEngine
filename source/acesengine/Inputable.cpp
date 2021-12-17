#include "Inputable.h"
#include "Drawable.h"

class Drawable;

namespace acesengine {

    Inputable::Inputable(float x, float y,
            std::string texturePath,
            int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
            : Drawable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)
        {
            this->left = sf::Keyboard::Key::A;
            this->right = sf::Keyboard::Key::D;
            this->up = sf::Keyboard::Key::W;
            this->down = sf::Keyboard::Key::S;
        }

    void Inputable::receiveInput() {
        if (sf::Keyboard::isKeyPressed(this->left)) {
            this->sprite.move(-0.2f, 0.0f);

            // Beggining sequence conditions
            if (this->movements.empty() && !(sf::Keyboard::isKeyPressed(this->right))) {
                this->movements.push_back(0);
            }
            else if (!(this->movements.empty()) && (this->movements.back() == 1) && !(sf::Keyboard::isKeyPressed(this->right))) {
                this->movements.push_back(0);
            }
            if (!(this->movements.empty()) && this->movements.size() >= 5) {
                printf("Side to side combination executing");
                this->movements.clear();
                this->sprite.move(20.0f, 20.0f);
            }
        }
        if (sf::Keyboard::isKeyPressed(this->right)) {
            this->sprite.move(0.2f, 0.0f);

            // Beggining sequence conditions
            if (!(this->movements.empty()) && !(sf::Keyboard::isKeyPressed(this->left))) {
                if (this->movements.back() == 0) {
                    this->movements.push_back(1);
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(this->up)) {
            this->sprite.move(0.0f, -0.2f);

            // Clearing sequence array
            this->movements.clear();
        }
        if (sf::Keyboard::isKeyPressed(this->down)) {
            this->sprite.move(0.0f, 0.2f);

            // Clearing sequence array
            this->movements.clear();
        }
    }

    void Inputable::draw(AcesWindow& acesWindow, bool move) {
        acesWindow.getWindow().draw(this->sprite);
        if (move) {
            this->receiveInput();
        }
    }
    
};