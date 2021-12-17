#include "Draggable.h"
#include "Drawable.h"

class Drawable;

namespace acesengine {

    Draggable::Draggable(float x, float y,
        std::string texturePath,
        int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
        : Drawable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY)
    {}

    void Draggable::enableDrag(AcesWindow& acesWindow) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            auto mouse_pos = sf::Mouse::getPosition(acesWindow.getWindow()); // Mouse position relative to the window
            if ((*this).getSprite().getGlobalBounds().contains((float)mouse_pos.x, (float)mouse_pos.y)) {
                (*this).setPosition((float)mouse_pos.x, (float)mouse_pos.y);
            }
        }
    }

}