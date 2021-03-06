#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "root_directory.h"
#include "Draggable.h"

// Uses Draggable to extend


namespace acesengine {

    /// Defines a fast way to make a card, ideal to board games
    /**
    *   The cards in this class can have different assets, in the assets directory there is a pre loaded card tileset, the setters and getters
    *   are public and it has the draw method, the turn over method is in process. The drag and drop is another method outside the class
    *
    *   Has a Drawable component
    */
    class Card : public Draggable {
        sf::Texture BackTexture;

    public:
        /// Constructor
        /** Default constructor for the Card class
        * @param x a float argument, 16.0f by default
        * @param y a float argument, 22.0f by default
        * @param BackTexturePath a string argument, precharged asset by default
        * @param FrontTexturePath a string argument, precharged asset by default
        * @param firstPointAssetXBACK an int argument, represent the first coordinate x of the back asset (if a tileset), default value to fit the precharged tileset
        * @param firstPointAssetYBACK an int argument, represent the first coordinate y of the back asset (if a tileset), default value to fit the precharged tileset
        * @param secondPointAssetXBACK an int argument, represent the second coordinate x of the back asset (if a tileset), default value to fit the precharged tileset
        * @param secondPointAssetYBACK an int argument, represent the second coordinate y of the back asset (if a tileset), default value to fit the precharged tileset
        * @param firstPointAssetXFRONT an int argument, represent the first coordinate x of the front asset (if a tileset), default value to fit the precharged tileset
        * @param firstPointAssetYFRONT an int argument, represent the first coordinate y of the front asset (if a tileset), default value to fit the precharged tileset
        * @param secondPointAssetXFRONT an int argument, represent the second coordinate x of the front asset (if a tileset), default value to fit the precharged tileset
        * @param secondPointAssetYFRONT an int argument, represent the second coordinate y of the front asset (if a tileset), default value to fit the precharged tileset
        */
        Card(float x = 16.0f, float y = 22.0f,
            std::string BackTexturePath = getPath("assets/imgs/8BitDeckAssets.png").string(),
            std::string FrontTexturePath = getPath("assets/imgs/8BitDeckAssets.png").string(),
            int firstPointAssetXBACK = 1, int firstPointAssetYBACK = 1, int secondPointAssetXBACK = 32, int secondPointAssetYBACK = 44,
            int firstPointAssetXFRONT = 36, int firstPointAssetYFRONT = 1, int secondPointAssetXFRONT = 32, int secondPointAssetYFRONT = 44);

    protected:
        /// Back Texture setter
        /**
        * @param texture sf::Texture, sets a texture for the BACK of the card
        */
        void setBackTexture(sf::Texture texture);

        /// Back Texture Getter
        /**
        * @returns sf::Texture
        */
        sf::Texture getBackTexture();

    public:
        /// Turn card function (in progress)
        /**
        * Set the texture of the card to the inverse, simulating a turn over
        */
        void turn();
    };
}