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


## - Open the solution in VS and build the engine/shape_maker solution -
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
And on the same directory you can found the Snakes And Ladders game. In this game, you can:
```
1 - 4: Music Volume and Pitch
M: Stop and resume music
R: Roll Dice
C: 'Go' voice
WASD and Arrows: Players input
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
There were some functions that were not taken into account by Doxygen, so here they are:
```
/// Enables the drag and drop of objects in the array and draw them
/**
* @param drag_vector std::vector<Draggable*> used to define which objects are movables, accept every object that uses the Draggable class
* @param acesWindow AcesWindow& reference to the window in which the cards will be drawn
*/

void enableDraggables(std::vector<Draggable*> drag_vector, AcesWindow& acesWindow) {...}


/// Enable the input of objects in the array and draw them
/**
* @param inputable_vector std::vector<Inputable*> Used to draw and enable input of every Inputable object in the array
* @param acesWindow AcesWindow& reference to the window in which the cards will be drawn
*/

void enableInputables(std::vector<Inputable*> inputable_vector, AcesWindow& acesWindow) {...}
}
```

---
Use Example (shape_maker.cpp):
```
int main() {
    namespace ae = acesengine;

    std::vector<ae::Draggable*> draggable_array;
    std::vector<ae::Inputable*> inputable_array;

    ae::AcesWindow AcesWindow(800, 600, "Ventana");
    sf::RenderWindow& window = AcesWindow.getWindow();

    // Testing Card class
    ae::Card card_test;
    draggable_array.push_back(&card_test); // TODO: Automatizar (si se puede de forma facil y sin restringir todo a solo cartas y dados)

    // Testing Player class
    ae::Player player1;
    ae::Player player2(0.0f, 0.0f, ae::getPath("assets/imgs/dice and pieces/piece1.png").string(), 0, 0, 0, 0, 2);

    // Change this to draggable_array
    inputable_array.push_back(&player1);
    inputable_array.push_back(&player2);

    // Testing SoundPlayer class
    ae::SoundPlayer acesSoundPlayer;
    acesSoundPlayer.loadAudio("congratulations", ae::getPath("assets/audios/VoiceOverPack/Male/congratulations.ogg").string());
    acesSoundPlayer.playAudio("congratulations");

    acesSoundPlayer.loadAudio("correct", ae::getPath("assets/audios/VoiceOverPack/Female/correct.ogg").string());

    // run the program as long as the window is open
    // TODO: abstract while loop to use AcesWindow instead of window
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
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Key::R && false) { // TODO: Fix recording, fails due to memory error
                    printf("began recording\n");
                    if (acesSoundPlayer.getRecordingState()) {
                        std::string recording_name = "Grabacion_test";
                        acesSoundPlayer.stopRecordingSound(recording_name);
                        acesSoundPlayer.playAudio(recording_name);
                    }
                    else {
                        acesSoundPlayer.startRecordingSound();
                    }
                    
                }
                else if (event.key.code == sf::Keyboard::Key::C) {
                    acesSoundPlayer.playAudio("correct");
                }
            }
        }

        AcesWindow.update();
        ae::enableDraggables(draggable_array, AcesWindow);
        ae::enableInputables(inputable_array, AcesWindow);
        AcesWindow.display();

    }
    return 0;
}
```


