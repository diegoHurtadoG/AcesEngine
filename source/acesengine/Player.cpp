#include "Player.h"
#include "root_directory.h"

namespace acesengine {

    Player::Player(float x, float y,
            std::string texturePath,
            int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY,
            int playerNumber) : Inputable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)
        {
            this->playerNumber = playerNumber;
            this->remapInput(this->playerNumber);
        }

    void Player::setPlayerNumber(int playerNumber) {
        this->playerNumber = playerNumber % 2;
        this->remapInput(playerNumber);
    }

    int Player::getPlayerNumber() {
        return this->playerNumber;
    }

    void Player::remapInput(int playerNumber) {
        if (playerNumber == 1) {
            this->left = sf::Keyboard::Key::A;
            this->right = sf::Keyboard::Key::D;
            this->up = sf::Keyboard::Key::W;
            this->down = sf::Keyboard::Key::S;
        }
        else if (playerNumber != 1) {
            this->left = sf::Keyboard::Key::Left;
            this->right = sf::Keyboard::Key::Right;
            this->up = sf::Keyboard::Key::Up;
            this->down = sf::Keyboard::Key::Down;
        }
    }

};