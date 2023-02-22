#include  <SFML\Graphics.hpp>
#include <iostream>

#define SCREEN_HIGHT 960
#define SCREEN_WIDTH 1600

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), "title");
    window.setFramerateLimit(60);

    sf::Event event;


    float sigma = 10.0, rho = 28.0, beta = 8.0 / 3.0, x = 0.1, y = 0.0, z = 0.0;
    float scale = 10;
    float dt = 0.01;

    float dx, dy, dz;
    sf::CircleShape circle(50);
    circle.setRadius(2);
    circle.setFillColor(sf::Color::Green);
    sf::CircleShape circle1(50);
    circle1.setRadius(2);
    circle1.setFillColor(sf::Color::White);
    sf::CircleShape circle2(50);
    circle2.setRadius(2);
    circle2.setFillColor(sf::Color::Magenta);

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

        dx = (sigma * (y - x)) * dt;
        dy = ((x * (rho - z)) - y) * dt;
        dz = (x * y - beta * z) * dt;
        x = x + dx;
        y = y + dy;
        z = z + dz;

        circle.setPosition(int(x * scale) + SCREEN_WIDTH / 6, int(y * scale) + SCREEN_HIGHT / 2);
        circle1.setPosition(int(y * scale) + SCREEN_WIDTH / 2, int(z * scale) + SCREEN_HIGHT / 3.5);
        circle2.setPosition(int(x * scale) + SCREEN_WIDTH / 1.2, int(z * scale) + SCREEN_HIGHT / 3.5);
        //std::cout << x << y << std::endl;
        //render
        window.clear();//clear old frames
        //draw
        window.draw(circle);
        window.draw(circle1);
        window.draw(circle2);

        window.display();


    }

    return 0;
}