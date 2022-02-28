#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "AcesWindow.h"

// This class uses AcesWindow

// Si no funciona, agregarle Sprite y que sea una clase independiente de todo

class AcesWindow;

namespace acesengine {

    /// Base class to add textures to a class attributes
    /**
    *   Every object that extends this class may ahve more than one texture, in order to use them, object must me drawable, draggable or inputable.
    */
    class Animation {
    protected:
        /// <summary>
        /// Sets a texture to put on the sprite
        /// </summary>
        std::map<std::string, std::vector<sf::Texture*>> animations; // If the white square remains, the vector can be of paths instead of textures.

    public:
        /// Constructor
        Animation();

    public:
        /// Function to add an animation to the map
        /**
        * @param key std::string sets the key to add to the map
        * @param textures std::vector<sf::Texture*> Vector of the assets that will make the animation
        */
        void addAnimation(std::string key, std::vector<sf::Texture*> textures);

        /// Function to make a texture object (to use in the add Animation)
        /**
        * @param texturePath std::string defines the path of the asset
        * @param firstPointAssetX an int argument, represent the first coordinate x of the front asset (if a tileset)
        * @param firstPointAssetY an int argument, represent the first coordinate y of the front asset (if a tileset)
        * @param secondPointAssetX an int argument, represent the second coordinate x of the front asset (if a tileset)
        * @param secondPointAssetY an int argument, represent the second coordinate y of the front asset (if a tileset)
        */
        sf::Texture* makeTexture(std::string texturePath, int firstPointAssetX = 0, int firstPointAssetY = 0, int secondPointAssetX = 0, int secondPointAssetY = 0);

        /// Getter to an animation, returns a vector of textures
        /**
        * @param key std::string and string argument that represents the key to the map of animations
        */
        std::vector<sf::Texture*> getAnimation(std::string key);
    };
};