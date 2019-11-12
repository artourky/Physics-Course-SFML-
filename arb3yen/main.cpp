#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"
#include "PhysicsWorld.h"

using namespace std;
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::CircleShape circle1(10.f);
	sf::RectangleShape rect2(Vector2f(20.f,20.f));
	sf::CircleShape circle3(10.f);
	sf::RectangleShape rect4(Vector2f(20.f, 20.f));

	sf::CircleShape player(25.f);

	circle1.setFillColor(sf::Color::Green);
	rect2.setFillColor(sf::Color::Red);
	circle3.setFillColor(sf::Color::Blue);
	rect4.setFillColor(sf::Color::Magenta);

	player.setFillColor(Color::White);

	Particle particle1(Vector2f(0, 0), 10, Vector2f(3.f, 6.f));
	particle1.name = "particle1";
	Particle particle2(Vector2f(400, 0), 20, Vector2f(0.f, 0.f));
	particle2.name = "particle2";
	Particle particle3(Vector2f(0, 200), 10, Vector2f(8.f, 6.f));
	particle3.name = "particle3";
	Particle particle4(Vector2f(400, 400), 20, Vector2f(0.f, 0.f));
	particle4.name = "particle4";

	Particle playerParticle(Vector2f(0, 0), 25, Vector2f(0, 0));

	particle2.useGravity = true;

	circle1.setPosition(particle1.position);
	rect2.setPosition(particle2.position);
	circle3.setPosition(particle3.position);
	rect4.setPosition(particle4.position);

	player.setPosition(playerParticle.position);

	particle2.acceleration = Vector2f(0, 10.f);
	//particle4.acceleration = Vector2f(0, 10.f);

	PhysicsWorld world;

	//world.addBody(&particle1);
	world.addBody(&particle2);
	world.addBody(&particle3);
	world.addBody(&particle4);
	world.addBody(&playerParticle);

	Clock clock;

	//window.setFramerateLimit(20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			switch (event.type) {
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space)
					{
						//world.Update(10.f);
						/*
						circle1.setPosition(particle1.position);
						circle2.setPosition(particle2.position);
						circle3.setPosition(particle3.position);*/

						//shape.setPosition(Vector2f(0,0));
					}
					else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
					{
						playerParticle.addForce(Vector2f(-300.f, 0));
					}
					else if (event.key.code == sf::Keyboard::Right)
					{
						playerParticle.addForce(Vector2f(300.f, 0.0));
					}
					else if (event.key.code == sf::Keyboard::Up)
					{
						playerParticle.addForce(Vector2f(0.f, -300.0));
					}
					else if (event.key.code == sf::Keyboard::Down)
					{
						playerParticle.addForce(Vector2f(0.f, 300.0));
					}
			}
		}

		Time time = clock.getElapsedTime();

		// UPDATE
		if (time.asMilliseconds() >= 20.f)
		{
			world.Update(1.f / time.asMilliseconds());
			clock.restart();
		}

		circle1.setPosition(particle1.position);
		rect2.setPosition(particle2.position);
		circle3.setPosition(particle3.position);
		rect4.setPosition(particle4.position);

		player.setPosition(playerParticle.position);

		window.clear();
		window.draw(circle1);
		window.draw(rect2);
		window.draw(circle3);
		window.draw(rect4);
		window.draw(player);

		window.display();
	}

	return 0;
}