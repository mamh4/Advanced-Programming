#include "Gameboard.h"
#include <SFML/Graphics.hpp>
#include "Predator.h"
#include "Prey.h"
#include "Flora.h"
#include <iostream>
#include <string>
#include "OrganicMaths.h"
#include <chrono>
#include <ctime>

#include <random>
#include <thread>

int numberOfPredators = 0;
int numberOfPrey = 0;
int numberOfFlora = 0;


//TODO: Decide on intialisation in main class of two vectors Fauna and Flora and then we loop through all Faunas, then all Floras? I think so
//TODO: Implement update for Prey and Flora

int main()
{
/*
    sf::RenderWindow window(sf::VideoMode(400, 300), "Input Box Example");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return -1;
    }

    //Number of predators input box
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setString("Enter number of predators:");

    sf::RectangleShape inputBox(sf::Vector2f(50.f, 20.f));
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineThickness(2.f);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setPosition(260.f, 3.f);

    std::string inputString;
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(20);
    inputText.setFillColor(sf::Color::Black);
    inputText.setString("");
    inputText.setPosition(262.f, 2.f);
    
    //Number of prey
    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::Black);
    text2.setString("Enter number of prey:");

    sf::RectangleShape inputBox2(sf::Vector2f(50.f, 30.f));
    inputBox2.setFillColor(sf::Color::White);
    inputBox2.setOutlineThickness(2.f);
    inputBox2.setOutlineColor(sf::Color::Black);
    inputBox2.setPosition(260.f, 3.f);

    std::string inputString2;
    sf::Text inputText2;
    inputText2.setFont(font);
    inputText2.setCharacterSize(20);
    inputText2.setFillColor(sf::Color::Black);
    inputText2.setString("");
    inputText2.setPosition(262.f, 2.f);


    std::string inputTextString = "0";
    std::string inputTextString2 = "0";
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(1);
            }
            else if (event.type == sf::Event::TextEntered) {
                //predator
                if (event.text.unicode == '\b' && inputString.size() > 0) {
                    // Backspace was pressed
                    inputString.pop_back();
                    inputText.setString(inputString);
                }
                //prey
                if (event.text.unicode == '\b' && inputString2.size() > 0) {
                    // Backspace was pressed
                    inputString2.pop_back();
                    inputText2.setString(inputString2);
                }

                else if (event.text.unicode == '\r') {
                    // predator
                    if (!inputString.empty()) {
                        inputTextString = inputText.getString();
                    }
                    //prey
                    if (!inputString2.empty()) {
                        inputTextString2 = inputText2.getString();
                    }
                    window.close();
                }
                else if (inputString.size() < 3 && event.text.unicode >= '0' && event.text.unicode <= '9') {
                    // Input character is a digit and input string is less than 3 characters
                    inputString += static_cast<char>(event.text.unicode);
                    inputText.setString(inputString);
                }
                else if (inputString2.size() < 3 && event.text.unicode >= '0' && event.text.unicode <= '9') {
					// Input character is a digit and input string is less than 3 characters
					inputString2 += static_cast<char>(event.text.unicode);
					inputText2.setString(inputString2);
                }
            }
        }

        window.clear(sf::Color::White);
        //Predator
        window.draw(text);
        window.draw(inputBox);
        window.draw(inputText);
        //prey
        window.draw(text2);
        window.draw(inputBox2);
        window.draw(inputText2);

        window.display();
    }

   

    numberOfPredators = std::stoi(inputTextString);
    numberOfPrey = std::stoi(inputTextString2);
    std::cout << "Number of predators: " << numberOfPredators << std::endl;
    std::cout << "Number of prey: " << numberOfPrey << std::endl;
    */

    
    std::time_t seed = std::time(nullptr);

    srand(seed);
    //test age of predator any prey make sure they inherit it and the value is 0
    float geneticTest=0.0 ;
    geneticTest= geneticEngine("Prey", "Speed", 2.0 , 3.0) ;


    std::vector<Organism*> organismVector;


    //Predator* myPredator = new Predator(500, 500, 5, 750, true, 1, 10, 1, 50, 400);
    //organismVector.push_back(myPredator);
    //Predator* myPredator2 = new Predator(475, 596, 5, 750, false, 1, 10, 1, 50, 800);
    //organismVector.push_back(myPredator2);

    //Predator* myPredator3 = new Predator(500, 290, 5, 750, true, 1, 10, 1, 50, 800);
    //organismVector.push_back(myPredator3);

    Prey* myPrey = new Prey(400, 460, 7, 200, true, 2, 10, 0.1, 50, 900, 1);
    organismVector.push_back(myPrey);

    Prey* myPrey2 = new Prey(100, 400, 7, 200, false, 2, 10, 0.1, 50, 900, 1);
    organismVector.push_back(myPrey2);

    Flora* myFlora = new Flora(500, 190, 10, 1000, 10);
    organismVector.push_back(myFlora);

    //Flora* myFlora2 = new Flora(900, 900, 10, 1000, 2);
    //organismVector.push_back(myFlora2);
    

    /*
    //std::cout << organismVector.at(0)->getType() << std::endl;
    for (int i = 0; i < numberOfPredators; i++) {
        bool validRespawnPlace = false;
        float posX = 500;
        float posY = 500;
        float radius = 3;
        while (not validRespawnPlace){
            posX = rand() % windowWidth;
            posY = rand() % windowHeight;
            radius = static_cast<float>(rand() % 10 + 5);
            for (int j = 0; j <= i; j++) {
                float distanceSquare = pow(posX - organismVector.at(i)->getPosX(), 2) + pow(posY - organismVector.at(i)->getPosY(), 2);
                if (distanceSquare > pow(organismVector.at(i)->getRadius() + radius, 2)) {
                    validRespawnPlace = true;
                }
            }
        }
        float energy = rand() % 100 + 1;
        bool sex = rand() % 2 == 0 ? true : false;
        int speed = rand() % 3 +1;
        int hungerLevel = rand() % 100 + 1;
        float metabolicRate = static_cast<float>(rand() % 10 + 1) / 10.0f;
        int lustLevel = rand() % 100 + 1;
        int visionRange = rand() % 100 + 1;
        Predator* myPredator = new Predator(posX, posY, radius, energy, sex, speed, hungerLevel, metabolicRate, lustLevel, visionRange);
        organismVector.push_back(myPredator);
    }

    for (int i = 0; i < numberOfPrey; i++) {
        bool validRespawnPlace = false;
        float posX = 500;
        float posY = 500;
        float radius = 3;
        while (not validRespawnPlace) {
            posX = rand() % windowWidth;
            posY = rand() % windowHeight;
            radius = static_cast<float>(rand() % 10 + 5);
            for (int j = 0; j <= i; j++) {
                float distanceSquare = pow(posX - organismVector.at(i)->getPosX(), 2) + pow(posY - organismVector.at(i)->getPosY(), 2);
                if (distanceSquare > pow(organismVector.at(i)->getRadius() + radius, 2)) {
                    validRespawnPlace = true;
                }
            }
        }
        float energy = rand() % 100 + 1;
        bool sex = rand() % 2 == 0 ? true : false;
        int speed = rand() % 10 + 1;
        int hungerLevel = rand() % 100 + 1;
        float metabolicRate = static_cast<float>(rand() % 10 + 1) / 10.0f;
        int lustLevel = rand() % 100 + 1;
        int visionRange = rand() % 100 + 1;
        float predatorAversion = static_cast<float>(rand() * 100);
        Prey* myPrey = new Prey(posX, posY, radius, energy, sex, speed, hungerLevel, metabolicRate, lustLevel, visionRange, predatorAversion);
        organismVector.push_back(myPrey);
    }

    for (int i = 0; i < numberOfFlora; i++) {
        bool validRespawnPlace = false;
        float posX = 500;
        float posY = 500;
        float radius = 3;
        while (not validRespawnPlace) {
            posX = rand() % windowWidth;
            posY = rand() % windowHeight;
            radius = static_cast<float>(rand() % 10 + 5);
            for (int j = 0; j <= i; j++) {
                float distanceSquare = pow(posX - organismVector.at(i)->getPosX(), 2) + pow(posY - organismVector.at(i)->getPosY(), 2);
                if (distanceSquare > pow(organismVector.at(i)->getRadius() + radius, 2)) {
                    validRespawnPlace = true;
                }
            }
        }
        float energy = rand() % 100 + 1;
        float growthRate = static_cast<float>(rand() * 100);
        Flora* myFlora = new Flora(posX, posY, radius, energy, growthRate);
        organismVector.push_back(myFlora);
    }
    */

    
    // Create a window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Prey vs Predator");

    //Predator myPredator(500, 500, 20, 100, true, 10, 5, 80, 1.5f, 50, 100);

    // Set the frame rate
    window.setFramerateLimit(60);

    // Set the movement speed of the pixel
    float moveSpeed = 1.0f;

    // start the game loop
    while (window.isOpen()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        for (int i = 0; i < organismVector.size(); i++) {

            organismVector.at(i)->update(organismVector);
        }


        // Print statistics at the top left corner
        sf::Text text;
        sf::Font font;
        font.loadFromFile("arial.ttf");
        if (!font.loadFromFile("arial.ttf")) {
           
        }
        text.setFont(font);
        text.setString("Population size: " + std::to_string(organismVector.size()) + "\n" +
            "Predators: " + std::to_string(numberOfPredators) + "\n" +
            "Prey: " + std::to_string(numberOfPrey) + "\n" +
            "Flora: " + std::to_string(numberOfFlora));
        // +std::to_string(organismVector.size()));
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::Black);


        // clear the window
        window.clear(sf::Color::White);

        // draw the organisms and the text
        for (Organism* organism : organismVector) {
            window.draw(organism->getShape());
            window.draw(text);
        }

        window.display();
    }
    




    return 0;
}