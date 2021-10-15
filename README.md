# AcesEngine
Game Engine focused on board games with educational purposes. Made under the Universidad de Chile CC5512 class.

## Dependencies:
-	[SFML](https://www.sfml-dev.org/index.php)
-	[OpenGL](https://www.opengl.org//) MUST be installed
-	Some third party of the directory may be necessary too, but i need to clean which not (just make all of them for now)

## To run the project
```
git clone https://github.com/diegoHurtadoG/AcesEngine.git
mkdir build
cd build
cmake ../AcesEngine
```
---

## Open the solution in VS and build the engine/shape_maker solution.
It is important that the build **MUST** be made in **RELEASE** mode. Before opening the example.exe, there is one thing you need to do

---
###  If x86 architecture
Go to 
```
AcesEngine/third_party/SFML/extlibs/bin/x86/
```
### If x64 architecture
Go to
```

AcesEngine/
```

And copy the file openal32.dll to
```
build/source/engine/Release/
```
---
Done that, you can build the solution in the Build directory. 
The example can be found in
```
build/source/engine/Release/shape_maker.exe
```
---
### Ignore the file content and go down until you find the last while lopp
There you can see how the example was made. The events are still written in SFML library language.

To Make your own game, make a new file in the same engine/ directory and import the shape_maker.cpp file so the classes and functions are available to use.

---
# Documentation
The official documentation is made in [Doxygen](https://www.doxygen.nl/index.html) and can be found in the docs/ directory, to open it correctly open
```
docs/index.html
```
with your favorite browser and then you can navigate.

---
There is one function that was not taken into account by Doxygen, so here it is:
```
/// Enables the drag and drop in cards of the array
/**
* @param card_vector std::vector<Card*> used to define which cards are movable
* @param &window sf::RenderWindow reference to the window in which the cards will be drawn
*/
void dragAndDropCards(std::vector<Card*> card_vector, AcesWindow &acesWindow)
```

---
###**TODO**:
-	Clean unused third party libraries

---
Use Example:
```
int main() {
    std::vector<Card*> card_array;

    AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();
	
	// Using default card Constructor
    Card card_test;
    card_array.push_back(&card_test); 
	
	// Using both player constructors
    Player player1;
    Player player2(0.0f, 0.0f, Grafica::getPath("assets/imgs/dice and pieces/piece1.png").string(), 0, 0, 0, 0, 2);

    // Initializing sound player and loading an audio with
	//		key "congratulations"
    SoundPlayer acesSoundPlayer;
    acesSoundPlayer.loadAudio("congratulations", Grafica::getPath("assets/audios/VoiceOverPack/Male/congratulations.ogg").string());
    acesSoundPlayer.playAudio("congratulations");
	
	// Loading a second audio to the same player
    acesSoundPlayer.loadAudio("correct", Grafica::getPath("assets/audios/VoiceOverPack/Female/correct.ogg").string());
    acesSoundPlayer.playAudio("correct");

    // run the program as long as the window is open
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                printf("The window has been resized, width: %i, height: %i\n", event.size.width, event.size.height);
                break;
            }
		}
		
		// Enable card_array to drag and drop
        dragAndDropCards(card_array, acesWindow);
		
		// Clear the window and update states
        AcesWindow.update();
		
		// Every object has the "draw" method to make this easier
        card_test.draw(acesWindow);
        player1.draw(acesWindow);
        player2.draw(acesWindow);
		
		// Displays the new status of screen
        AcesWindow.display();

    }
    return 0;
}
```


