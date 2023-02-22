#include  <SFML\Graphics.hpp>
#include <iostream>

#define SCREEN_HIGHT 960
#define SCREEN_WIDTH 1600

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), "title");
    window.setFramerateLimit(120);

    sf::Event event;

    int iterator = 0;//(for loop) to display every old frames each time window clears
    
    //animation classes

    sf::CircleShape circle_xy(50);
    circle_xy.setRadius(1);
    circle_xy.setFillColor(sf::Color::Green);

    sf::CircleShape circle_yz(50);
    circle_yz.setRadius(1);
    circle_yz.setFillColor(sf::Color::White);

    sf::CircleShape circle_xz(50);
    circle_xz.setRadius(1);
    circle_xz.setFillColor(sf::Color::Magenta);

    //window loop
    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            switch (event.type) {

            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }

        }

        //for r = 99.96: scale = 2, dt = 0.005

        float sigma = 10.0, rho = 28.0, beta = 8.0 / 3.0, x = 0.1, y = 0.0, z = 0.0;
        float scale = 10.0;
        float dt = 0.01;

        float dx, dy, dz;
        
        ++iterator;
        
        //render
        window.clear();//clear old frames
        for (int i = 0; i <= iterator; i++) {

            dx = (sigma * (y - x)) * dt;
            dy = ((x * (rho - z)) - y) * dt;
            dz = (x * y - beta * z) * dt;
            x = x + dx;
            y = y + dy;
            z = z + dz;

            //if statement that removes old circles
            if (iterator - i >= 1500) {
                continue;
            }

            circle_xy.setPosition(int(x * scale) + SCREEN_WIDTH / 6, int(y * scale) + SCREEN_HIGHT / 2);
            circle_yz.setPosition(int(y * scale) + SCREEN_WIDTH / 2, int(z * scale) + SCREEN_HIGHT / 4.1);
            circle_xz.setPosition(int(x * scale) + SCREEN_WIDTH / 1.2, int(z * scale) + SCREEN_HIGHT / 4.1);

            //draw 
            window.draw(circle_xy);
            window.draw(circle_yz);
            window.draw(circle_xz);
        }

        window.display();


    }

    return 0;
}
