#include "BoidLife.h"

float BoidLife::calculateOpacity()
{
	// std::cout << calculateDecay() << endl;
	return calculateDecay();
}

ofVec3f BoidLife::velocityDecay()
{
	return calculateDecay() * initVelocity;
}



float BoidLife::calculateDecay()
// Linear decay function to culculate the decay percentage of opacity & velocity according to lifestime
{
	float percentage = lifetime / lifespan;
	return (percentage);
}

float BoidLife::calculateSize()
{
	return calculateDecay() * initSize;
}

BoidLife::BoidLife(Boid start)
{
	initOpcatiy = 1;
	initVelocity = start.getVelocity();
	position = start.getPosition();
	velocity = initVelocity;
	lifetime = lifespan;
	size = initSize;
}

int BoidLife::getLifetime()
{
	return lifetime;
}

void BoidLife::update()
{
	
	lifetime -= 0.6f;
	velocity = velocityDecay();
	opacity = calculateOpacity();
	size = calculateSize();
	position += velocity;
	// std::cout << opacity << endl;
}

void BoidLife::draw()
{
	// std::cout << "opt" << endl;
	ofSetColor(ofRandom(110,190), 25, 0);
	ofCircle(position.x, position.y, size);
}
