#include<SFML/Graphics.hpp>
#include<iostream>
#include<iomanip>
#include<cmath>

static constexpr auto pi = 3.14159265;



static constexpr float to_degree(const float radian)
{
	return radian * (180.f / pi);
}


using namespace std;
using namespace sf;






int main()
{
    RenderWindow windows(VideoMode(1200, 1060), "game", Style::Default);

    CircleShape boy(30.f,3);

    CircleShape dot(5.f);
    dot.setPosition(1000,300);
    
    boy.setPosition(1200/2,1060/2);
     const float speed = 10.f;

    Clock clocl;

    boy.setOrigin((boy.getGlobalBounds().width/2), (boy.getGlobalBounds().height/2));

    

    while(windows.isOpen())
    {

        Time dt = clocl.restart();
       Event evnt;
       
           while(windows.pollEvent(evnt))
           {
               switch(evnt.type)
               {

                   case Event::Closed:
                   windows.close();

                   case Event::MouseMoved:

                   auto mouse_position = windows.mapPixelToCoords({evnt.mouseMove.x,evnt.mouseMove.y});
                   float X =  mouse_position.x - boy.getPosition().x;
                        float Y =  mouse_position.y - boy.getPosition().y;
                        auto rotation = to_degree(atan2(Y,X))+90.f;
                        boy.setRotation(rotation);
                        break;
               }

           } 

          

           
            
         if(Keyboard::isKeyPressed(Keyboard::W))
         {
             boy.move(0.f,-speed*dt.asSeconds()*60.f);
            
            
         } 
         else
         {
             if(Keyboard::isKeyPressed(Keyboard::S))
             {
                 boy.move(0.f,+speed*dt.asSeconds()*60.f);
                 
             }
         }

         if(Keyboard::isKeyPressed(Keyboard::A))
         {
             boy.move(-speed*dt.asSeconds() * 60.f , 0.f);
             
         } 
         else
         {
             if(Keyboard::isKeyPressed(Keyboard::D))
             {
                 boy.move(+speed*dt.asSeconds()*60.f, 0.f);
                 
             }
         }

         cout<<Mouse::getPosition().x<<setw(4)<<Mouse::getPosition().y<<endl;

     windows.clear();
     windows.draw(boy);
     windows.draw(dot);
     windows.display();

         

     
    }
}
