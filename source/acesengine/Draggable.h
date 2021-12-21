#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "AcesWindow.h"

class AcesWindow;

namespace acesengine {
    /// Base class to an object that can be dragged in the screen
    /**
    *   Includes a draw method and already includes the sprite and texture
    */
    class Draggable {
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
        /** Default constructor for every draggable item, just calls the drawable constructor
        * @param x a float argument
        * @param y a float argument
        * @param texturePath a string argument
        * @param firstPointAssetX an int argument, represent the first coordinate x of the front asset (if a tileset)
        * @param firstPointAssetY an int argument, represent the first coordinate y of the front asset (if a tileset)
        * @param secondPointAssetX an int argument, represent the second coordinate x of the front asset (if a tileset)
        * @param secondPointAssetY an int argument, represent the second coordinate y of the front asset (if a tileset)
        */
        Draggable(float x, float y,
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

        /// Enables the drag and drop of the current object
        /**
        * @param &window sf::RenderWindow reference to the window in which the cards will be drawn
        */
        void enableDrag(AcesWindow& acesWindow);
    };
}