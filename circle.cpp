#include "circle.h"
#include "game.h"

Circle::Circle()
{
    circle.setRadius(radius);
    circle.setPointCount(100);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(event.mouseButton.x-circle.getRadius(),event.mouseButton.y-circle.getRadius());
    //holder.push_back(circle);
}

