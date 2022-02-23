#include "Animation.h"

class AcesWindow;

namespace acesengine {

    Animation::Animation()
    {
    }

    void Animation::addAnimation(std::string key, std::vector<sf::Texture> textures)
    {
        animations.insert({ key, textures });
    }

    sf::Texture Animation::makeTexture(std::string texturePath, int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
    {
        sf::Texture texture;
        if ((firstPointAssetX != secondPointAssetX) && (firstPointAssetY != secondPointAssetY)) {
            if (texture.loadFromFile(texturePath, sf::IntRect(firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)))
            {
                printf("Error loading Back texture");
            }
        }
        else {
            if (texture.loadFromFile(texturePath))
            {
                printf("Error loading Back texture");
            }
        }
        return texture;
    }

    
};