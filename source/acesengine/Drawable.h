#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "AcesWindow.h"

// This class uses AcesWindow

class AcesWindow;

namespace acesengine {

    /// Base class to an object with a draw() method
    /**
    *   Every drawable object will inherit from this class. This will have a sprite, and a texture, the sprite contains the position
    */
    class Drawable {
    protected:
        /// <summary>
        /// Sets the sprite to draw
        /// </summary>
        sf::Sprite sprite;

        /// <summary>
        /// Sets a texture to put on the sprite
        /// </summary>
        sf::Texture texture;

    public:
        /// Constructor
        /** Default constructor for every drawable item
        * @param x a float argument
        * @param y a float argument
        * @param texturePath a string argument
        * @param firstPointAssetX an int argument, represent the first coordinate x of the front asset (if a tileset)
        * @param firstPointAssetY an int argument, represent the first coordinate y of the front asset (if a tileset)
        * @param secondPointAssetX an int argument, represent the second coordinate x of the front asset (if a tileset)
        * @param secondPointAssetY an int argument, represent the second coordinate y of the front asset (if a tileset)
        */
        Drawable(float x, float y,
            std::string texturePath,
            int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY);

    protected:
        /// Texture setter
        /**
        * @param texture sf::Texture defines texture of player
        */
        void setTexture(sf::Texture texture);

        /// Texture getter
        /**
        * @returns sf::Texture obtains current texture
        */
        sf::Texture getTexture();

    public:
        /// Draw function
        /**
        * @param &renderWindow receives a reference to the window to draw
        */
        void draw(AcesWindow& acesWindow);

        /// Position setter
        /**
        * @param x float defines x coordinate
        * @param y float defines y coordinate
        */
        void setPosition(float x, float y);

        /// Position getter
        /**
        * @returns sf::Vector2f defines position
        */
        sf::Vector2f getPosition();

        /// Sprite setter
        /**
        * @param sprite sf::Sprite defines player Sprite
        */
        void setSprite(sf::Sprite sprite);

        /// Sprite getter
        /**
        * @returns sf::Sprite actual player sprite
        */
        sf::Sprite getSprite();

    };
};