#include "AABBCollider.h"

AABBCollider::AABBCollider()
{
}

AABBCollider::AABBCollider(Vector2f *pos, float s)
{
	position = pos;
	size = s;
}

AABBCollider::~AABBCollider()
{
}

bool AABBCollider::CheckCollision(AABBCollider otherCollider) {
	Vector2f Amin = Vector2f((*position).x - (size / 2), (*position).y - (size / 2));
	Vector2f Amax = Vector2f((*position).x + (size / 2), (*position).y + (size / 2));

	Vector2f Bmin = sf::Vector2f(otherCollider.position->x - (otherCollider.size / 2),
		otherCollider.position->y - (otherCollider.size / 2));
	Vector2f Bmax = sf::Vector2f(otherCollider.position->x + (otherCollider.size / 2),
		otherCollider.position->y + (otherCollider.size / 2));

	if (Amin.x > Bmax.x)
		return false;
	if (Bmin.x > Amax.x)
		return false;
	if (Amin.y > Bmax.y)
		return false;
	if (Bmin.y > Amax.y)
		return false;

	return true;
}