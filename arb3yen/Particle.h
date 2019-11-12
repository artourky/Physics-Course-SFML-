#pragma once
#include <SFML/Graphics.hpp>
#include "AABBCollider.h"

using namespace sf;
using namespace std;

class Particle
{
public:
	string name;
	AABBCollider collider;

	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;
	float mass;
	float dragCoefficient;

	bool useGravity;

	int x;
	int *s;
	void (*doing)();
	void(*callBack)();

	Vector2f forces;

	Particle();
	Particle(Vector2f, float, Vector2f);
	
	~Particle();

	Vector2f Update(float);

	void addForce(Vector2f);
};