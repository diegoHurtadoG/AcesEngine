#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Inputable.h"
#include "root_directory.h"


namespace acesengine {

    /// Defines the things a player can do, input keys must be specified (remapInput method in this case)
    /**
    *   The players accept a maximum of 2 players locally for now, with plans to expand to 4. The defined
    *   controls are "WASD" and the arrows.
    *
    *   Has an inputable component
    */
    class Player : public Inputable {
        /// <summary>
        /// Asign a number to the player
        /// </summary>
        int playerNumber;

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
        * @param playerNumber int defines the number of the player, 1 by default and 2 if any other int
        */
        Player(float x = 0.0f, float y = 0.0f,
            std::string texturePath = getPath("assets/imgs/dice and pieces/piece0.png").string(),
            int firstPointAssetX = 0, int firstPointAssetY = 0, int secondPointAssetX = 0, int secondPointAssetY = 0,
            int playerNumber = 1) : Inputable(x, y, texturePath, firstPointAssetX, firstPointAssetY, secondPointAssetX, secondPointAssetY);

    public:
        /// Player number setter
        /**
        * @param playerNumber int defines player number with a maximum of 2 (4 in process)
        */
        void setPlayerNumber(int playerNumber);

        /// Player number getter
        /**
        * @returns int representing player number
        */
        int getPlayerNumber();

        /// Input remapper to default values
        /**
        * @param playerNumber int depending on the player number set default controls
        */
        void remapInput(int playerNumber);
    };

};