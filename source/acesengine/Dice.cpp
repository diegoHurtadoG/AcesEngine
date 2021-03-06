#include "Dice.h"
#include "root_directory.h"

namespace acesengine {

    Dice::Dice(float x, float y,
        std::string texturePath,
        int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
        : Animation(), Drawable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)
    {
        
        this->addAnimation("1", { this->makeTexture(getPath("assets/imgs/dice and pieces/die rolled 1.png").string(), 7, 7, 23, 22) });
        this->addAnimation("2", { this->makeTexture(getPath("assets/imgs/dice and pieces/die rolled 2.png").string(), 7, 7, 23, 22) });
        this->addAnimation("3", { this->makeTexture(getPath("assets/imgs/dice and pieces/die rolled 3.png").string(), 7, 7, 23, 22) });
        this->addAnimation("4", { this->makeTexture(getPath("assets/imgs/dice and pieces/die rolled 4.png").string(), 7, 7, 23, 22) });
        this->addAnimation("5", { this->makeTexture(getPath("assets/imgs/dice and pieces/die rolled 5.png").string(), 7, 7, 23, 22) });
        this->addAnimation("6", { this->makeTexture(getPath("assets/imgs/dice and pieces/die rolled 6.png").string(), 7, 7, 23, 22) });
    }

    int Dice::roll(int time)
    {
        int actualValue = rand() % 6 + 1;
        sf::Texture* texture = new sf::Texture();
        this->sprite.setTexture(*this->getAnimation(std::to_string(actualValue))[0]);
        std::this_thread::sleep_for(std::chrono::milliseconds(7000 / time));

        return actualValue;
    }

};