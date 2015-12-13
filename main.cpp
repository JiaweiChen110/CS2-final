#include <iostream>
#include "game.h"
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    Game testing;
    testing.run();
    return 0;
    /*
    //sf::RenderWindow window(sf::VideoMode(480, 180), "Animation");
    //window.setFramerateLimit(60);

    //sf::String buffer;

    /*sf::CircleShape circleShape(50);
    circleShape.setFillColor(sf::Color::Red);
    circleShape.setOutlineColor(sf::Color::White);
    circleShape.setOutlineThickness(3);*/

    /*sf::RectangleShape rectShape(sf::Vector2f(50, 50));
    rectShape.setFillColor(sf::Color::Red);
    rectShape.setPosition(sf::Vector2f(50, 50));
    //rectShape.setRotation(30);
    rectShape.setOrigin(sf::Vector2f(25, 25));
    //rectShape.setScale(sf::Vector2f(2, 1));*/


    /*sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(100, 0));
    triangle.setPoint(1, sf::Vector2f(100, 100));
    triangle.setPoint(2, sf::Vector2f(0, 100));
    triangle.setFillColor(sf::Color::Blue);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){

                rectShape.rotate(1.5f);
                rectShape.move(sf::Vector2f(1, 0));

            }

            switch(event.type){

            case sf::Event::EventType::Closed:
                window.close();
                break;

            case sf::Event::EventType::TextEntered:
                buffer += event.text.unicode;
                break;

            case sf::Event::EventType::KeyReleased:
                if(event.key.code == sf::Keyboard::Key::Return)
                {
                    window.setTitle(buffer);
                    buffer.clear();
                }
                break;

            default:
                break;

            }

            //update frame
            //rectShape.rotate(1.5f);
            //rectShape.move(sf::Vector2f(1, 0));

            //render frame
            window.clear(sf::Color::Black);

            //window.draw(triangle);
            window.draw(rectShape);

            window.display();


       }
    }
    return 0;
    */
}

