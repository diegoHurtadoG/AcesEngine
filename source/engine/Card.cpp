#include "Card.h"


namespace AcesEngine {

    class Card : public Draggable {
        sf::Texture BackTexture;

    public:
        Card(float x = 16.0f, float y = 22.0f,
            std::string BackTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
            std::string FrontTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
            int firstPointAssetXBACK = 1, int firstPointAssetYBACK = 1, int secondPointAssetXBACK = 32, int secondPointAssetYBACK = 44,
            int firstPointAssetXFRONT = 36, int firstPointAssetYFRONT = 1, int secondPointAssetXFRONT = 32, int secondPointAssetYFRONT = 44)
            : Draggable(x, y, FrontTexturePath, firstPointAssetXFRONT, firstPointAssetYFRONT, secondPointAssetXFRONT, secondPointAssetYFRONT)
        {
            if (!this->BackTexture.loadFromFile(BackTexturePath, sf::IntRect(firstPointAssetXBACK, firstPointAssetYBACK, secondPointAssetXBACK, secondPointAssetYBACK)))
            {
                printf("Error loading Back texture");
            }
        }

    protected:
        void setBackTexture(sf::Texture texture) {
            this->BackTexture = texture;
        }

        sf::Texture getBackTexture() {
            return this->BackTexture;
        }

    public:

        void turn() {
            this->sprite.getTexture() == &this->texture ? this->sprite.setTexture(this->BackTexture) : this->sprite.setTexture(this->texture);
        }
    };
};