# AcesEngine
Game Engine focused on board games with educational purposes. Made under the Universidad de Chile CC5512 class.

## To run the project
```
git clone https://github.com/diegoHurtadoG/AcesEngine.git
mkdir build
cd build
cmake ../AcesEngine
```
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
Done that, you can build the solution in the Build directory. The build **MUST** be made in **RELEASE** mode.
The example can be found in
```
build/source/engine/Release/shape_maker.exe
```
---
### Ignore the file content and go down until you find the last while lopp
There you can see how the example was made. The events are still written in SFML library language.

To Make your own game, make a new file in the same engine/ directory and import the shape_maker.cpp file so the classes and functions are available to use.

---

Use Example (Documentation below):
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
        dragAndDropCards(card_array, window);
		
		// Clear the window and update states
        AcesWindow.update();
		
		// Every object has the "draw" method to make this easier
        card_test.draw(window);
        player1.draw(window);
        player2.draw(window);
		
		// Displays the new status of screen
        AcesWindow.display();

    }
    return 0;
}
```



---
# Little Documentation
In the source/engine/shape_maker.cpp you will find everythin made for the engine, im sorry for the mess but I used the file for testing purposes and didn't get to reorder the directory. There are some pre-loaded tiles and audios so you can play.

Here you will find:
```
-	CLASS Card:

		// Default constructor
	-	Card(float x = 16.0f, float y = 22.0f, 
            std::string BackTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
            std::string FrontTexturePath = Grafica::getPath("assets/imgs/8BitDeckAssets.png").string(),
            int firstPointAssetXBACK = 1, int firstPointAssetYBACK = 1, int secondPointAssetXBACK = 32, int secondPointAssetYBACK = 44,
            int firstPointAssetXFRONT = 36, int firstPointAssetYFRONT = 1, int secondPointAssetXFRONT = 32, int secondPointAssetYFRONT = 44)
		
		// * Card Methods *
		// Set and get a card position
	-	void setPosition(float x, float y);
	-	sf::Vector2f getPosition();

		// Set and get Back Texture
	-	void setBackTexture(sf::Texture texture)
	-   sf::Texture getBackTexture() 

		// Set and get Front Texture
	-	void setFrontTexture(sf::Texture texture)
	-	sf::Texture getFrontTexture()

		// Set and get Card Sprite
	-	void setSprite(sf::Sprite sprite) 
	-	sf::Sprite getSprite() 

		// Draw card in window
	-	 void draw(sf::RenderWindow &renderWindow)

		// Turn card to show the other face on click (not working)
	-	void turn()
```

---

```
-	Class AcesWindow:

		// Default Constructor
	-	AcesWindow(int heigth, int width, std::string title = "Default Title",
            std::string backgroundPath = Grafica::getPath("assets/imgs/backgrounds/0.jpg").string())
			
		// * AcesWindow Methods *
		// Get window object, used in the loop
	-	sf::RenderWindow& getWindow()
		
		// Set and Get Window Size
	-	void setSize(int heigth, int width) 
	-	sf::Vector2u getSize()
		
		//Change window Background with a texture path
	-	void setTexture(std::string newPath)
		
		// Update the screen objects to show and clear previous
	-	void update()
		
		// Draw the objects in screen
	-	void display()
```

---

```
-	Class Player:

		// Default Constructor
	-	Player(float x = 0.0f, float y = 0.0f,
            std::string texturePath = Grafica::getPath("assets/imgs/dice and pieces/piece0.png").string(),
            int firstPointAssetX = 0, int firstPointAssetY = 0, int secondPointAssetX = 0, int secondPointAssetY = 0,
            int playerNumber = 1)
			void setPosition(sf::Vector2f pos) {
            this->sprite.setPosition(pos);
        }
		
		// * Player Methods *
		// Get player position
	-	sf::Vector2f getPosition()
		
		// Set and Get texture
	-	void setTexture(sf::Texture texture)
	-	sf::Texture getTexture()
		
		// Set and Get Sprite
	-	void setSprite(sf::Sprite sprite)
	-	sf::Sprite getSprite()
		
		// set Player number (1 or other value, 2 is max for now)
	-	void setPlayerNumber(int playerNumber)
	-	int getPlayerNumber()
		
		// Manages input, future remapping
	-	void remapInput(int playerNumber)
		
		// Handles input in the while loop, have sequences and could have Chords
	-	void receiveInput()

		// Draw Player in the window, if wanted can set false to dont let the player move (static drawing)
	-	void draw(sf::RenderWindow& renderWindow, bool move = true)
```

---

```
-	Class SoundPlayer

		// Default Constructor
	-	SoundPlayer()

		// * Important Class methods *
		// Loads audio from path, needs a key
	-	void loadAudio(std::string uniqueName, std::string audioPath)
		
		// Play audio by key
	-	void playAudio(std::string uniqueName)
		
		// Stop audio by key
	-	void stopAudio(std::string uniqueName)
		
		// Set Volume (from 0 to 100) by key
	-	void setVolumeAudio(std::string uniqueName, int vol)
		
		// get Volume by key
	-	float getVolumeAudio(std::string uniqueName)
		
		// Set Pitch by key
	-	void setPitchAudio(std::string uniqueName, float value)
		
		// Get Pitch by key
	-	float getPitchAudio(std::string uniqueName)
		
        // Offset in seconds
	-	float setPlayingOffsetAudio(std::string uniqueName, float offset)

		// Defines if the audio will loop by name
        void loopAudio(std::string uniqueName) 
```

---

```
-	Class TextWriter (not working because of permissions)

		// Constructors
	-	TextWriter()
	-	TextWriter(std::string fontPath)

		// * Text Writer Methods *
		// Set string to write
	-	void setString(std::string text)
	
		// Set font size
	-	void setSize(int valueInPixels)

		// Bold text
	-	void boldText()

		// Underline text
	-	void underlineText()

		// Set Text Position in screen
	-	void setPosition(float x, float y)

		// Draw text in screen
	-	void draw(sf::RenderWindow& renderWindow)
```

---

Extra methods:
```
// Given a card vector, enables the user to drag and drop
//	them on screen
void dragAndDropCards(std::vector<Card*> card_vector, sf::RenderWindow &window)
```