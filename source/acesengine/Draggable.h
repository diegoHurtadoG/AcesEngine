#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Drawable.h"
#include "AcesWindow.h"


namespace acesengine {
    /// Base class to an object that can be dragged in the screen
    /**
    *   This class already expands the drawable class (an object can not be dragged but not drawn)
    */
    class Draggable : public Drawable {

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
            int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY)
            : Drawable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY);

    public:
        /// Enables the drag and drop of the current object
        /**
        * @param &window sf::RenderWindow reference to the window in which the cards will be drawn
        */
        void enableDrag(AcesWindow& acesWindow);
    };
};