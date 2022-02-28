#include "Animation.h"

class AcesWindow;

namespace acesengine {

    Animation::Animation()
    {
    }

    void Animation::addAnimation(std::string key, std::vector<sf::Texture*> textures)
    {
        animations.insert({ key, textures });
    }

    sf::Texture* Animation::makeTexture(std::string texturePath, int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
    {
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

        return texture;
    }

    std::vector<sf::Texture*> Animation::getAnimation(std::string key)
    {
        return this->animations.at(key);
    }

    
};