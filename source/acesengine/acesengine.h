#pragma once

#include "AcesWindow.h"

class Draggable;
class AcesWindow;
class Inputable;

namespace acesengine {

    /// Enables the drag and drop of objects in the array and draw them
    /**
    * @param drag_vector std::vector<Draggable*> used to define which objects are movables, accept every object that uses the Draggable class
    * @param acesWindow AcesWindow& reference to the window in which the cards will be drawn
    */
    void enableDraggables(std::vector<Draggable*> drag_vector, AcesWindow& acesWindow) {
        for (auto i = drag_vector.begin(); i != drag_vector.end(); i++) {
            (**i).draw(acesWindow);
            (**i).enableDrag(acesWindow);
        }
    }

    /// Enable the input of objects in the array and draw them
    /**
    * @param inputable_vector std::vector<Inputable*> Used to draw and enable input of every Inputable object in the array
    * @param acesWindow AcesWindow& reference to the window in which the cards will be drawn
    */
    void enableInputables(std::vector<Inputable*> inputable_vector, AcesWindow& acesWindow) {
        for (auto i = inputable_vector.begin(); i != inputable_vector.end(); i++) {
            (**i).draw(acesWindow);
        }
    }

}