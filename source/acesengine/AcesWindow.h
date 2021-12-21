#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "root_directory.h"

// This class uses Inputable and Draggable

class Draggable;
class Inputable;

namespace acesengine {

    ///  Defines a render window which allows drawing
    /**
    *   The window allows to personalize background, size, and a title
    */
    class AcesWindow {
        /// <summary>
        /// Allows to have a rendering window
        /// </summary>
        sf::RenderWindow window;

        /// <summary>
        /// Used to set a background for the window
        /// </summary>
        sf::Texture backgroundTexture;

        /// <summary>
        /// Defines the dimensions of the window
        /// </summary>
        int heigth, width;

        /// <summary>
        /// Sets the title of the window and the path to the background texture
        /// </summary>
        std::string title, backgroundPath;

        /// <summary>
        /// Used to contain the background texture
        /// </summary>
        sf::RectangleShape backgroundRectangle;

    public:
        /// Constructor
        /**
        * @param heigth int which defines the height of the window
        * @param width int which defines the width of the window
        * @param title string to name the window, "Default Title" by default
        * @param backgroundPath string to set the background of the window, precharged one as default
        */
        AcesWindow(int heigth, int width, std::string title = "Default Title",
            std::string backgroundPath = getPath("assets/imgs/backgrounds/0.jpg").string());

        /// Window getter
        /**
        * @returns sf::RenderWindow& commonly used to give it to the draw functions
        */
        sf::RenderWindow& getWindow();

        /// Size setter
        /**
        * @param height int new heigth of the window
        * @param width int new width of the window
        */
        void setSize(int heigth, int width);

        /// Size getter
        /**
        * @returns sf::Vector2u which represents the actual size
        */
        sf::Vector2u getSize();

        /// Texture Setter
        /** Sets a new background for the window
        * @param newPath string to reference the new asset
        */
        void setTexture(std::string newPath);

        /// Update
        /**
        * Clears the window and draw the background
        */
        void update();

        /// Display
        /**
        * Display the new window
        */
        void display();
    };
}