#include "Card.h"
#include "root_directory.h"


namespace acesengine {

    Card::Card(float x, float y,
            std::string BackTexturePath,
            std::string FrontTexturePath,
            int firstPointAssetXBACK, int firstPointAssetYBACK, int secondPointAssetXBACK, int secondPointAssetYBACK,
            int firstPointAssetXFRONT, int firstPointAssetYFRONT, int secondPointAssetXFRONT, int secondPointAssetYFRONT)
            : Draggable(x, y, FrontTexturePath, firstPointAssetXFRONT, firstPointAssetYFRONT, secondPointAssetXFRONT, secondPointAssetYFRONT)
        {
            if (!this->BackTexture.loadFromFile(BackTexturePath, sf::IntRect(firstPointAssetXBACK, firstPointAssetYBACK, secondPointAssetXBACK, secondPointAssetYBACK)))
            {
                printf("Error loading Back texture");
            }
        }

    void Card::setBackTexture(sf::Texture texture) {
        this->BackTexture = texture;
    }

    sf::Texture Card::getBackTexture() {
        return this->BackTexture;
    }

    void Card::turn() {
        this->sprite.getTexture() == &this->texture ? this->sprite.setTexture(this->BackTexture) : this->sprite.setTexture(this->texture);
    }
    
};