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


	float lifespan = 10.0f;//拖尾的生命时长，可以控制拖尾的长度
	float initOpcatiy = 0.2;// 初始的透明度，暂时没有用...
	float initSize = 24.0f;// 初始的大小
	ofVec3f initVelocity; // 拖尾初始的速度，从头部粒子复制而来

	int getLifetime();

	void update();
	void draw() override;

};

#endif