/*
 *  boid.cpp
 *  boids
 *
 *  Created by Marco Gillies on 05/10/2010.
 *  Copyright 2010 Goldsmiths, University of London. All rights reserved.
 *
 */

#include "boid.h"
#include "ofMain.h"

Boid::Boid()
{
	separationWeight = 0.6f;//分隔
	cohesionWeight = 0.25f;//凝聚力
	alignmentWeight = 0.3f;


	separationThreshold = 20; //分开的起始点，弹射
	neighbourhoodSize = 140;

	position = ofVec3f(ofRandom(0, 200), ofRandom(0, 20));
	velocity = ofVec3f(ofRandom(0, 10), ofRandom(-20, 0));
}

Boid::Boid(ofVec3f& pos, ofVec3f& vel)
{
	separationWeight = 0.4f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;

	separationThreshold = 40;
	neighbourhoodSize = 100;

	position = pos;
	velocity = vel;
}

Boid::~Boid()
{

}

float Boid::getSeparationWeight()
{
	return separationWeight;
}
float Boid::getCohesionWeight()
{
	return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
	return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
	return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
	separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
	return position;
}

ofVec3f Boid::getVelocity()
{
	return velocity;
}

ofVec3f Boid::separation(std::vector<Boid*>& otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position - otherBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}

ofVec3f Boid::cohesion(std::vector<Boid*>& otherBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - position;
	v.normalize();
	return v;
}

ofVec3f Boid::alignment(std::vector<Boid*>& otherBoids)
{
	ofVec3f average(0, 0, 0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v = average - velocity;
	v.normalize();
	return v;
}

void Boid::update(std::vector<Boid*>& otherBoids, ofVec3f& min, ofVec3f& max)
{
	velocity += separationWeight * separation(otherBoids);
	velocity += cohesionWeight * cohesion(otherBoids);
	velocity += alignmentWeight * alignment(otherBoids);

	walls(min, max);
	position += velocity;
}

void Boid::walls(ofVec3f& min, ofVec3f& max)
{
	if (position.x < min.x) {
		position.x = min.x;
		velocity.x *= -1;
	}
	else if (position.x > max.x) {
		position.x = max.x;
		velocity.x *= ofRandom(-1, abs(-1));
	}

	if (position.y < min.y) {
		position.y = min.y;
		velocity.y *= -1;
	}
	else if (position.y > max.y) {
		position.y = max.y;
		velocity.y *= ofRandom(-1, abs(-1));
	}


}

void Boid::draw()
{
	ofSetColor(ofRandom(10, 30), ofRandom(180, 225), ofRandom(10, 255), ofRandom(150, 185));
	ofCircle(position.x, position.y, 7);
	ofNoFill();
	ofSetLineWidth(ofRandom(0.1, 0.2));
}

void Boid::draw1()
{
	ofSetColor(ofRandom(110, 130), ofRandom(30, 185), ofRandom(180, 255), ofRandom(150, 185));
	ofCircle(position.x, position.y, 7);
	ofNoFill();
	ofSetLineWidth(ofRandom(0.1,0.2));
}
void Boid::draw2()
{
	ofSetColor(ofRandom(110, 130), ofRandom(10, 225), ofRandom(10, 255), ofRandom(150, 185));
	ofCircle(position.x, position.y, 7);
	ofNoFill();
	ofSetLineWidth(ofRandom(0.1, 0.2));
}

void Boid::draw3()
{
	ofSetColor(ofRandom(110, 130), ofRandom(10, 225), ofRandom(10, 255), ofRandom(150, 185));
	ofCircle(position.x, position.y, 7);
	ofNoFill();
	ofSetLineWidth(ofRandom(0.1, 0.2));
}