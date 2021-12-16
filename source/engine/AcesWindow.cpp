#include "AcesWindow.h"


namespace AcesEngine {

    class AcesWindow {
        sf::RenderWindow window;
        sf::Texture backgroundTexture;
        int heigth, width;
        std::string title, backgroundPath;
        sf::RectangleShape backgroundRectangle;

    public:
        AcesWindow(int heigth, int width, std::string title = "Default Title",
            std::string backgroundPath = Grafica::getPath("assets/imgs/backgrounds/0.jpg").string()) {
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

        sf::RenderWindow& getWindow() {
            return this->window;
        }

        void setSize(int heigth, int width) {
            this->window.setSize(sf::Vector2u(heigth, width));
        }

        sf::Vector2u getSize() {
            return this->window.getSize();
        }

        void setTexture(std::string newPath) {
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

        void update() {
            this->window.clear();
            this->window.draw(backgroundRectangle);
        }

        void display() {
            this->window.display();
        }

        void enableDraggables(std::vector<Draggable*> drag_vector) {
            for (auto i = drag_vector.begin(); i != drag_vector.end(); i++) {
                (**i).draw(*this);
                (**i).enableDrag(*this);
            }
        }

        void enableInputables(std::vector<Inputable*> inputable_vector) {
            for (auto i = inputable_vector.begin(); i != inputable_vector.end(); i++) {
                (**i).draw(*this);
            }
        }
    };
};
