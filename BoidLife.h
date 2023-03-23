#pragma once


#ifndef _BOIDLIFE
#define _BOIDLIFE
#include <vector>

#include <stdio.h>
#include "ofMain.h"
#include "boid.h"

class BoidLife: public Boid
{
private:
	float lifetime;
	float opacity = 1.0f;
	float size;
	ofVec3f colour = ofVec3f(255, 0, 0);

	float calculateOpacity();
	ofVec3f velocityDecay();
	float calculateSize();
	float calculateDecay();
public:
	BoidLife(Boid start);
	// BoidLife(ofVec3f position,ofVec3f velocity, ofVec3f colour);


	float lifespan = 10.0f;//��β������ʱ�������Կ�����β�ĳ���
	float initOpcatiy = 0.2;// ��ʼ��͸���ȣ���ʱû����...
	float initSize = 24.0f;// ��ʼ�Ĵ�С
	ofVec3f initVelocity; // ��β��ʼ���ٶȣ���ͷ�����Ӹ��ƶ���

	int getLifetime();

	void update();
	void draw() override;

};

#endif