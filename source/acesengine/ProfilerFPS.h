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

	/// Base class to a profiler that displays fps
	/*
	* This class is independent from any other class, displays the fps on console and will be adapted for screen display
	* Taken and adapted from https://gist.github.com/kenpower/7233967
	*/
	class ProfilerFPS
	{
	public:
		/// Constructor
		ProfilerFPS();

		/// Get the current FPS count.
		/*
		* @returns unsigned int fps representing the fps count
		*/
		const unsigned int getFPS();

	private:

		/// <summary>
		/// Used to coount frames in a second
		/// </summary>
		unsigned int mFrame;

		/// <summary>
		/// Used to display the calculated FPS
		/// </summary>
		unsigned int mFps;

		/// <summary>
		/// SFML tool to measure time
		/// </summary>
		sf::Clock mClock;

	public:
		/// <summary>
		/// Main function, usde to calculate the FPS value. Updated the mFPS value
		/// </summary>
		void update();

		/// Function used to display FPS on screen and not console
		/*
		* @param &renderWindow receives a reference to the window to draw 
		*/
		void draw(AcesWindow& acesWindow);
	};
}