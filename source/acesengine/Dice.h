#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "root_directory.h"
#include "Animation.h"
#include "Drawable.h"

// Uses Inputable to extend

namespace acesengine {

    /// Defines the things a player can do, input keys must be specified (remapInput method in this case)
    /**
    *   The players accept a maximum of 2 players locally for now, with plans to expand to 4. The defined
    *   controls are "WASD" and the arrows.
    *
    *   Has an inputable component
    */
    class Dice : public Animation, public Drawable {

    public:
        /// Constructor with default values
        /**
        * @param x float 0.0f by default, defines position
        * @param y float 0.0f by default, defines position
        * @param texturePath string path to define the texture of the player, precharged red by default
        * @param firstPointAssetX int Defines the first x coordinate of the asset in case of using a tileset
        * @param firstPointAssetY int Defines the first y coordinate of the asset in case of using a tileset
        * @param secondPointAssetX int Defines the second x coordinate of the asset in case of using a tileset
        * @param secondPointAssetY int Defines the second y coordinate of the asset in case of using a tileset
        */
        Dice(float x = 100.0f, float y = 100.0f,
            std::string texturePath = getPath("assets/imgs/dice and pieces/die rolled 1.png").string(),
            int firstPointAssetX = 0, int firstPointAssetY = 0, int secondPointAssetX = 0, int secondPointAssetY = 0);

    public:
        /// Method to roll the dice, making the animation of roll
        /**
        * 
        */
        void roll();
    };

};