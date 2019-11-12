#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Collider
{
public:
	Vector2f *position;
	float radius;

	Collider();
	Collider(Vector2f *, float);
	~Collider();
	bool CheckCollision(Collider);
};

