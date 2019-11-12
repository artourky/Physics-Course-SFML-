#include "Collider.h"

Collider::Collider()
{
}

Collider::Collider(Vector2f *pos, float r)
{
	position = pos;
	radius = r;
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider other) {
	Vector2f distance = (*other.position) - *position;
	float distanceMag = sqrt(distance.x * distance.x + distance.y * distance.y);

	if (distanceMag <= ((other.radius) + radius))
	{
		//cout << "Collision happend!" << endl;
	}

	return distanceMag <= ((other.radius) + radius);
}