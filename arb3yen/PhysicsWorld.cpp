#include "PhysicsWorld.h"

PhysicsWorld::PhysicsWorld()
{
}

PhysicsWorld::~PhysicsWorld()
{
}

void PhysicsWorld::addBody(Particle *p) {
	bodies.push_back(p);
}

void PhysicsWorld::Update(float dt) {
	for (int i = 0; i < bodies.size(); i++)
	{
		(*bodies[i]).Update(dt);
		//cout << i << ": " << (*bodies[i]).position.x << ", " << (*bodies[i]).position.y << endl;
	}

	for (int i = 0; i < bodies.size(); i++)
	{
		for (int j = i + 1; j < bodies.size(); j++)
		{
			if (bodies[i]->collider.CheckCollision(bodies[j]->collider)) {
				bodies[i]->callBack();
				cout << bodies[i]->name << " collided with " << bodies[j]->name << endl;
			}
		}
	}
}