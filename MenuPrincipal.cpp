#include <SFML/Graphics.hpp>
#include <iostream>
#include "./Automata 1/Automata 1.cpp"
#include "./Automata 3/Automata3.cpp"
#include "./Automata 2/Automata2.cpp"
#include <random>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Menu");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("Assets/Font/Roughnation.ttf")) { // Make sure you have a .ttf font file
        std::cout << "Error loading font\n";
        return -1;
    }

    sf::Text programa1Aleatorio("Programa 1 Aleatorio", font, 20);
    programa1Aleatorio.setFillColor(sf::Color::White);
    programa1Aleatorio.setPosition(100, 100); // Position it according to your needs
    sf::Text programa1Manual("Programa 1 Manual", font, 20);
    programa1Manual.setFillColor(sf::Color::White);
    programa1Manual.setPosition(400, 100); // Position it according to your needs
    sf::Text programa2Aleatorio("Programa 2 Aleatorio", font, 20);
    programa2Aleatorio.setFillColor(sf::Color::White);
    programa2Aleatorio.setPosition(100, 200); // Position it according to your needs
    sf::Text programa2Manual("Programa 2 Manual", font, 20);
    programa2Manual.setFillColor(sf::Color::White);
    programa2Manual.setPosition(400, 200); // Position it according to your needs
    sf::Text programa3Text("Programa 3", font, 20);
    programa3Text.setFillColor(sf::Color::White);
    programa3Text.setPosition(100, 300); // Position it according to your needs

    sf::Text exitText("Exit", font, 50);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(300, 400); // Position it accordingly
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (programa1Aleatorio.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        std::cout << "¡Empezando programa 1 Aleatoriamente!" << std::endl;
                        automata1(rand()%5);
                    }else if(programa1Manual.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
                        std::cout <<"Empezando programa 1 Manualmente!" << std::endl << "Escriba la potencia n" << std::endl;
                        int n;
                        cin>> n;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        automata1(n);
                    }else if (programa2Aleatorio.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
                        std:: cout<< "Empezadno programa 2 Aleatoriamente! " << std::endl;
                        Automata2(1);
                    }else if(programa2Manual.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
                        std:: cout<< "Empezando programa 2 Manualmente! " << std::endl;
                        Automata2(2);
                    }else if(programa3Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))){
                        std:: cout<<"Empezando el progrma 3!" << std::endl;
                        Automata3();
                    }
                     else if (exitText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        std::cout << "Exit was clicked!" << std::endl;
                        window.close(); // Exit the program
                    }
                }
            }
        }

        window.clear();
        window.draw(programa1Aleatorio);
        window.draw(programa1Manual);
        window.draw(programa2Aleatorio);
        window.draw(programa2Manual);
        window.draw(programa3Text);
        window.draw(exitText);
        window.display();
    }

    return 0;
}