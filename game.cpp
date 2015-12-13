#include "game.h"
#include "constants.h"
#include <iostream>
#include <string>
using namespace std;
const int MAXRADIUS(43);
Game::Game()
{
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Wenyuan's Sample Window!", sf::Style::Titlebar | sf::Style::Close);
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    window.setFramerateLimit(60);
}

void Game::processEvents(){
    sf::Event event;
    int num=0;
    int intersect=0;
    int num1=1;
    int radius(20);
    while (window.waitEvent(event))//or waitEvent
        {
        // check the type of the event...
        //num1++;
            switch (event.type)
            {
                // window closed
                // "close requested" event: we close the window
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    //...
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right){
                        //using arrow key too( up and down)
                        //increase size of the circle.
                        //sf::CircleShape circle(10,30);
                        //circle.setPosition(event.mouseButton.x-circle.getRadius(),event.mouseButton.y-circle.getRadius());
                        std::cout << "the right button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        //sf::RectangleShape rect;
                        //rect.setPosition(event.mouseButton.x,event.mouseButton.y);
                        for(int i=0;i<num;i++){
                            if(holder[i].getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y)==1){
                                //int j=0;
                                //if(i<num){
                                    //j=0;
                                    //int k=i+1;
                                //}
                                for(int j=0;j<num;j++){
                                    if(j==i){
                                        cout<<"nothing happen"<<endl;
                                    }else if(holder[i].getGlobalBounds().intersects(holder[j].getGlobalBounds())){
                                        cout<<"intersects"<<endl;
                                        i=num;
                                        intersect++;
                                    }
                                }
                                if(intersect>0){
                                    cout<<"cant increase size"<<endl;
                                    intersect=0;
                                }else{
                                    cout<<" click on circle"<<endl;
                                    //holder[i].setOrigin(holder[i].getOrigin());
                                    cout<<holder[i].getPosition().x<<endl;
                                    cout<<holder[i].getPosition().y<<endl;
                                    cout<<holder[i].getRadius()<<endl;
                                    if(holder[i].getRadius()<MAXRADIUS){
                                        //cout<<holder[i].getLocalBounds().contains(event.mouseButton.x,event.mouseButton.y)<<endl;
                                        holder[i].setPosition(holder[i].getPosition().x-holder[i].getRadius()*1/10,holder[i].getPosition().y-holder[i].getRadius()*1/10);
                                        holder[i].setRadius(holder[i].getRadius()*1/10+holder[i].getRadius());
                                        //holder[i].setPosition(holder[i].getPosition().x-holder[i].getRadius()*1/10,holder[i].getPosition().y-holder[i].getRadius()*1/10);
                                    }else{
                                        cout<<"cant increase size anymore"<<endl;
                                    }
                                }
                            }
                            //sf::CircleShape copy;
                            //copy.getLocalBounds().contains()
                            //copy.setOrigin();
                            //copy.getOrigin()
                            //copy.getGlobalBounds().contains(x,y)
                            //holder[1].getPosition();
                            //copy = holder[i];
                            //holder[i].setRadius(88);
                            //holder[i].setPosition(holder[i].getPosition().x-88,holder[i].getPosition().y-88);
                            //holder[i]=copy;
                            //copy.setRadius(60);
                            //holder[1]=copy;
                            //cout<<copy.getRadius()<<endl;
                            //if(copy.getGlobalBounds().intersects(rect)){
                                //cout<<"hi"<<endl;
                            //}
                        }
                    }else if(event.mouseButton.button == sf::Mouse::Left){
                        std::cout<<"left button?"<<std::endl;
                        //CREATE the circle
                        //num1++;
                        //cout<<num1 <<" + "<<radius<<endl;
                        //num1++;
                        circle.setRadius(radius);
                        circle.setPointCount(99999);
                        circle.setFillColor(sf::Color::Red);
                        circle.setPosition(event.mouseButton.x-circle.getRadius(),event.mouseButton.y-circle.getRadius());
                        //holder.push_back(circle);
                        if(num>=1&&num<=15){
                            int hit=0;
                            cout<<"fire3"<<endl;
                            for(int i=num-1;i>=0;i--){
                                if(holder[i-1].getGlobalBounds().intersects(circle.getGlobalBounds())){
                                    cout<<"hit"<<endl;
                                    i=0;
                                    hit++;
                                    //holder.push_back(circle);
                                }
                            }
                            if(hit==0){
                                holder.push_back(circle);
                                num++;
                                cout<<num<<endl;
                            }else if(hit>0){
                                cout<<"fire2"<<endl;
                                hit=0;
                            }
                        }else if(num==0){
                            cout<<"fire1"<<endl;
                            holder.push_back(circle);
                            num++;
                        }else{
                            cout<<"cant create anymore planets"<<endl;
                        }
                        //num++;
                        //sf::CircleShape shape;
                        //shape.getGlobalBounds().intersects(circle);
                        //radius[num]=circle.getRadius();
                        //num++;
                        //window.draw(circle);
                        /*
                        circle.setPosition(event.mouseButton.x,event.mouseButton.y);
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        circle.setFillColor(sf::Color::Red);
                        circle.setOutlineColor(sf::Color::White);
                        circle.setOutlineThickness(3);
                        */
                    }
                    break;
            //case sf::Event::mouseMove:

                //case sf::Event::TextEntered:
                //std::cout<<event.text.unicode<<endl;
                //case sf::Event::MouseButtonPressed:

                //case sf::Event::MouseMoved:
                    //std::cout << "mouse x: " << event.mouseMove.x << std::endl;
                    //std::cout << "mouse y: " << event.mouseMove.y << std::endl;
                    default:
                        break;
            }

            for(int i=0;i<num;i++){
                window.draw(holder[i]);
            }
            //window.draw(circle);
            window.display();
        }
}
void Game::update()
{
    for(int i=0;i<5;i++){
    if((holder[i].getPosition().y + holder[i].getPosition().y < SCREEN_HEIGHT)&&(holder[i].getPosition().x + holder[i].getPosition().x < SCREEN_WIDTH))
    {
        holder[i].move(0.5,1);
    }
    else {
        if (holder[i].getPosition().y + holder[i].getPosition().y >= SCREEN_HEIGHT){
            holder[i].setPosition(holder[i].getPosition().x,0);
        }
        else {
            holder[i].setPosition(0,holder[i].getPosition().y);
        }
    }
    }
}
/*
void Game::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    //getCurrentPositition();
    //circle will be in vector.
    window.draw(circle);
}
void Game::render(){
       window.clear();
       Draw();
       window.display();
}
*/
void Game::run(){
    while (window.isOpen())
    {
        processEvents();
        //window.display();
        //window.draw(circle);
        update();
        //render(); //clear/draw/display
    }
}


/*
Game::Game(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Wenyuan's Sample Window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //  of the window: resize, fullscreen etc.

    window.setFramerateLimit(60);

    //mybox.setFillColor(sf::Color::Red);
    //mybox.setSize(sf::Vector2f(20,30));
    //mybox.setPosition(0,0);
}


void Game::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    //getCurrentPositition();
    window.draw(circle);
}


void Game::update()
{
    if((mybox.getPosition().y + mybox.getSize().y < SCREEN_HEIGHT)&&(mybox.getPosition().x + mybox.getSize().x < SCREEN_WIDTH))
    {
        mybox.move(0.5,1);
    }
    else {
        if (mybox.getPosition().y + mybox.getSize().y >= SCREEN_HEIGHT){
            mybox.setPosition(mybox.getPosition().x,0);
        }
        else {
            mybox.setPosition(0,mybox.getPosition().y);
        }
    }
}
void Game::render(){
       window.clear();
       Draw();
       window.display();
}



void Game::processEvents()
{
   sf::Event event;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
               // window closed
               // "close requested" event: we close the window
               case sf::Event::Closed:
                   window.close();
                   break;

               // key pressed
               case sf::Event::KeyPressed:
                   //...
                   break;
               case sf::Event::MouseButtonReleased:
                       if (event.mouseButton.button == sf::Mouse::Right)
                       {
                           std::cout << "the right button was pressed" << std::endl;
                           std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                           std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                       }
                       else
                           std::cout<<"left button?"<<std::endl;
                           mybox.setPosition(event.mouseButton.x,event.mouseButton.y);

                       break;

                   default:
                       break;
           }
       }
}

void Game::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
}
*/




















