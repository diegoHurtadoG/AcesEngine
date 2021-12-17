#include "AcesWindow.h"
#include "root_directory.h"


namespace acesengine {

    AcesWindow::AcesWindow(int heigth, int width, std::string title,
            std::string backgroundPath) {
            this->width = width;
            this->heigth = heigth;
            this->title = title;
            this->backgroundPath = backgroundPath;
            this->window.create(sf::VideoMode(heigth, width), title, sf::Style::Close | sf::Style::Resize); // TODO: Estudiar esto, hay un posible 4to parametro
            try {
                if (!this->backgroundTexture.loadFromFile(this->backgroundPath))
                {
                    throw("Error loading texture");
                }
                backgroundRectangle.setSize(sf::Vector2f((float)heigth, (float)width));
                backgroundRectangle.setTexture(&(this->backgroundTexture));
            }
            catch (std::string msg) {
                std::cout << msg << "\n";;
            }
        }

    sf::RenderWindow& AcesWindow::getWindow() {
        return this->window;
    }

    void AcesWindow::setSize(int heigth, int width) {
        this->window.setSize(sf::Vector2u(heigth, width));
    }

    sf::Vector2u AcesWindow::getSize() {
        return this->window.getSize();
    }

    void AcesWindow::setTexture(std::string newPath) {
        try {
            if (!this->backgroundTexture.loadFromFile(newPath))
            {
                throw("Error loading texture");
            }
            // Test this to see if texture really changes (not urgent)
        }
        catch (std::string msg) {
            std::cout << msg;
        }
    }

    void AcesWindow::update() {
        this->window.clear();
        this->window.draw(backgroundRectangle);
    }

    void AcesWindow::display() {
        this->window.display();
    }

    void AcesWindow::enableDraggables(std::vector<Draggable*> drag_vector) {
        for (auto i = drag_vector.begin(); i != drag_vector.end(); i++) {
            (**i).draw(*this);
            (**i).enableDrag(*this);
        }
    }

    void AcesWindow::enableInputables(std::vector<Inputable*> inputable_vector) {
        for (auto i = inputable_vector.begin(); i != inputable_vector.end(); i++) {
            (**i).draw(*this);
        }
    }
    
};
