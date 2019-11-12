#include "Particle.h"

void PrintSomething();

Particle::Particle()
{
	position = Vector2f(0, 0);
	velocity = Vector2f(0, 0);
	mass = 1.f;
	forces = Vector2f(0, 0);
}

Particle::Particle(Vector2f pos, float size, Vector2f v = Vector2f(0,0))
{
	position.x = pos.x - (size / 2);
	position.y = pos.y - (size / 2);

	velocity = v;
	mass = 1.f;
	dragCoefficient = 0.1f;
	forces = Vector2f(0, 0);
	useGravity = false;

	collider = AABBCollider(&position, size);
	callBack = PrintSomething;
}

Particle::~Particle()
{
}

Vector2f Particle::Update(float dt) {
	// a = F / m
	if (velocity.x != 0 && velocity.y != 0)
	{
		float velocityMag = 
			sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

		Vector2f velocityNormalized =
			Vector2f(velocity.x / velocityMag, velocity.y / velocityMag);
		
		float dragMag = velocityMag * velocityMag * dragCoefficient;
		
		Vector2f drag = velocityNormalized * -dragMag;
		forces += drag;
	}
	acceleration = forces * (1.f / mass);

	if (useGravity)
	{
		acceleration += Vector2f(0, 9.81);
	}

	// v = a * t
	velocity += (acceleration * dt);
	// x = v * t;
	position += (velocity * dt);
	// Force Impulse
	forces *= 0.f;
	
	return position;
}

void Particle::addForce(Vector2f f) {
	forces += f;
}


void PrintSomething() {
	cout << "Ahmed Gado\n";
}