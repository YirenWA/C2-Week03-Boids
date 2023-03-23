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
	separationWeight = 1.0f;//分隔
	cohesionWeight = 0.10f;//凝聚力
	alignmentWeight = 0.1f;


	separationThreshold = 8; //分开的起始点，弹射
	neighbourhoodSize = 60;

	position = ofVec3f(ofGetWidth() / 2, ofGetHeight() / 2);
	int init_vel = 2; //起始速度
	velocity = ofVec3f(ofRandom(-init_vel/2, init_vel/2), ofRandom(-init_vel / 2, init_vel / 2));
}

Boid::Boid(ofVec3f& pos, ofVec3f& vel)
{
	separationWeight = 0.4f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;

	separationThreshold = 4;
	neighbourhoodSize = 25;

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

int Boid::getDraw2Size()
{
	return size2;
}

void Boid::setDraw2Size(int s)
{
	size2 = s;
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

	ofVec2f center = ofVec2f(ofGetWidth() / 4, ofGetHeight() / 4);
	float radius = 500.0;
	if (position.distance(center) > radius) {
		ofVec2f direction = (center - position).normalize();
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

	ofVec2f center = ofVec2f(ofGetWidth() / 4, ofGetHeight() / 4);
	float radius = 500.0;
	if (position.distance(center) > radius) {
		ofVec2f direction = (center - position).normalize();
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

	ofVec2f center = ofVec2f(ofGetWidth() / 4, ofGetHeight() / 4);
	float radius = 500.0;
	if (position.distance(center) > radius) {
		ofVec2f direction = (center - position).normalize();
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

	// walls(min, max);
	updateWithinCircle(150);
	position += velocity;

}

void Boid::updateWithinCircle(int radius)
{
	float pythagorean = (position.x - ofGetWidth() / 2) * (position.x - ofGetWidth() / 2)
		+ (position.y - ofGetHeight() / 2) * (position.y - ofGetHeight() / 2);
	if (pythagorean >= radius * radius)
	{
		velocity.x *= -1;
		velocity.y *= -1;
		ofVec3f center = ofVec3f(ofGetWidth(), ofGetHeight(), 0);
		velocity += (position - center).getNormalized();
	}

	int count = 0;
	while (pythagorean >= radius * radius && count < 1000)
	{
		// velocity.x += ofRandom(-1, abs(-1));
		// velocity.y += ofRandom(-1, abs(-1));
		position += velocity * 10;
		pythagorean = (position.x - ofGetWidth() / 2) * (position.x - ofGetWidth() / 2)
			+ (position.y - ofGetHeight() / 2) * (position.y - ofGetHeight() / 2);
		count += 1;
	}
	//cout << count << endl;
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
	ofSetColor(180, 250, 140, 55);
	ofCircle(position.x, position.y, 30);
	//ofNoFill();
	ofSetLineWidth(ofRandom(0.1, 0.2));
	
}

void Boid::draw1()
{
	ofSetColor(ofRandom(100,120), ofRandom(150, 180), 170, 255);
	ofCircle(position.x, position.y, 14);
	//ofNoFill();
	ofSetLineWidth(ofRandom(0.1,0.2));
}
void Boid::draw2()
{
	ofSetColor(ofRandom(125,160), 45, ofRandom(20, 45), ofRandom(90, 150));
	ofCircle(position.x, position.y, size2);
	
	//ofNoFill();
	ofSetLineWidth(ofRandom(0.1, 0.2));
}

void Boid::draw3()
{
	ofSetColor(ofRandom(80, 100), ofRandom(50, 100), 80, 205);
	ofCircle(position.x, position.y, 30);
	//ofNoFill();
	ofSetLineWidth(ofRandom(2.5, 2.8));
}