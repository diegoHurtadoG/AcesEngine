#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Drawable.h"
#include "AcesWindow.h"

class Drawable;
class AcesWindow;

namespace acesengine {
    /// Base class to an object that has input, keys must be defined in specific class
    /**
    *   This class already expands the drawable class, overrides the draw() method to enable input
    */
    class Inputable : public Drawable {

    protected:
        /// <summary>
        /// Defines the key to the left movement
        /// </summary>
        sf::Keyboard::Key left;

        /// <summary>
        /// Defines the key to the right movement
        /// </summary>
        sf::Keyboard::Key right;

        /// <summary>
        /// Defines the key to the up movement
        /// </summary>
        sf::Keyboard::Key up;

        /// <summary>
        /// Defines the key to the down movement
        /// </summary>
        sf::Keyboard::Key down;

        /// <summary>
        /// Movement log
        /// </summary>
        std::vector<int> movements; //0 if left, 1 if right, reset if up or down, check state by even or odd size.

    public:
        /// Constructor
        /** Default constructor for every draggable item, just calls the drawable constructor, sets WASD as default input in case they dont override
        * @param x a float argument
        * @param y a float argument
        * @param texturePath a string argument
        * @param firstPointAssetX an int argument, represent the first coordinate x of the front asset (if a tileset)
        * @param firstPointAssetY an int argument, represent the first coordinate y of the front asset (if a tileset)
        * @param secondPointAssetX an int argument, represent the second coordinate x of the front asset (if a tileset)
        * @param secondPointAssetY an int argument, represent the second coordinate y of the front asset (if a tileset)
        */
        Inputable(float x, float y,
            std::string texturePath,
            int firstPointAssetX, int firstPointAssetY, int secondPointAssetX, int secondPointAssetY);

    public:
        /// Input receiver and movement maker, define sequences and chords
        /**
        * Enables input in players
        */
        void receiveInput();

        /// Defines if the player can move or not and draw it in the window, overrides the base class function because of the receiveInput method
        /**
        * @param &renderWindow sf::RenderWindow reference to the window to draw
        * @param move bool set if the player can move or not
        */
        void draw(AcesWindow& acesWindow, bool move = true);
    };

}