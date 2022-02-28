#include "Animation.h"

class AcesWindow;

namespace acesengine {

    Animation::Animation()
    {
    }

    void Animation::addAnimation(std::string key, std::vector<sf::Texture*> textures)
    {
        // Error here, the insert copies the value into the vector, and textures can not be copied
        // https://en.sfml-dev.org/forums/index.php?topic=11627.0
        // Pointers may be neccesary
        animations.insert({ key, textures });
    }

    sf::Texture* Animation::makeTexture(std::string texturePath, int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
    {
        //sf::Texture *texture;
        sf::Texture* texture = new sf::Texture();
        if ((firstPointAssetX != secondPointAssetX) && (firstPointAssetY != secondPointAssetY)) {
            if (!texture->loadFromFile(texturePath, sf::IntRect(firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)))
            {
                printf("Animation: Error loading Back texture rectangle\n");
            }
        }
        else {
            if (!texture->loadFromFile(texturePath))
            {
                printf("Animation: Error loading Back texture\n");
            }
        }

        // Error here, the return must be avoided:
        // https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php
        return texture;
    }

    std::vector<sf::Texture*> Animation::getAnimation(std::string key)
    {
        return this->animations.at(key);
    }

    
};