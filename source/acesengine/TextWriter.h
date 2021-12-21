#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "AcesWindow.h"

// Uses AcesWindow to draw

namespace acesengine {

    /// Defines a text writer to render text on screen (broken)
    /**
    * The text writer is simple to use and is used to display text on the screen, comes with preloaded
    * fonts and options, has methods to customize the text
    */
    class TextWriter {
        /// <summary>
        /// Defines the text that will be displayed
        /// </summary>
        sf::Text text;

    public:
        /// Constructor, preloads the available options to fast and easy use
        TextWriter();

        /// Constructor, uses an alternative font
        /**
        * @param fontPath string loads a font from a given directory
        */
        TextWriter(std::string fontPath);


    public:
        /// Sets a string to draw
        /**
        * @param text string defines the string to display
        */
        void setString(std::string text);

        /// Sets a size to the text
        /**
        * @param valueInPixels int the size of the text measured in pixels
        */
        void setSize(int valueInPixels);

        /// Bolds the given text
        void boldText();

        /// Underlines the given text
        void underlineText();

        /// Sets the position of the text
        /**
        * @param float x sets the x coordinate
        * @param float y sets the y coordinate
        */
        void setPosition(float x, float y);

        /// Draws the text in the given window
        /**
        * @param &renderWindow the window in which to display the text
        */
        void draw(AcesWindow& acesWindow);

    };
};
