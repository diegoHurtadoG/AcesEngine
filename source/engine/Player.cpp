#include "Player.h"

namespace AcesEngine {

    class Player : public Inputable {
        int playerNumber;

    public:
        Player(float x = 0.0f, float y = 0.0f,
            std::string texturePath = Grafica::getPath("assets/imgs/dice and pieces/piece0.png").string(),
            int firstPointAssetX = 0, int firstPointAssetY = 0, int secondPointAssetX = 0, int secondPointAssetY = 0,
            int playerNumber = 1) : Inputable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)
        {
            this->playerNumber = playerNumber;
            this->remapInput(this->playerNumber);
        }

    public:
        void setPlayerNumber(int playerNumber) {
            this->playerNumber = playerNumber % 2;
            this->remapInput(playerNumber);
        }

        int getPlayerNumber() {
            return this->playerNumber;
        }

        void remapInput(int playerNumber) {
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

};