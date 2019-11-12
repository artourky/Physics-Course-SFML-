#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class AABBCollider
{
public:
	Vector2f *position;
	float size;

	AABBCollider();
	AABBCollider(Vector2f *, float);
	~AABBCollider();
	bool CheckCollision(AABBCollider);
};