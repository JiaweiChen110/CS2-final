#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>


class Game{
public:
    Game();
    void createCircle();
    void processEvents();
    void render();
    void Draw();
    void run();
    void update();
    sf::CircleShape circle;

private:
    sf::RenderWindow window;
    std::vector <sf::CircleShape> holder;
    //int radius[999];
    //vector to hold circle.
};


#endif // GAME_H
