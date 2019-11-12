#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Particle.h"

using namespace sf;
using namespace std;

class PhysicsWorld
{
public:
	vector<Particle *> bodies;

	PhysicsWorld();
	~PhysicsWorld();

	void addBody(Particle *);

	void Update(float);
};

