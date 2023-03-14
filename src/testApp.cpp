#include "testApp.h"

testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
}

//--------------------------------------------------------------
void testApp::setup() {


	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	font.load("NewYork PERSONAL USE.otf", 25);//要先在bin文件夹里加入字体
	text = "Run Away";

	ofBackground(0, 10, 20);

	// set up the boids
	for (int i = 0; i < 8; i++)
		boids.push_back(new Boid());
	for (int i = 0; i < 8; i++)
		boids1.push_back(new Boid());
	for (int i = 0; i < 8; i++)
		boids2.push_back(new Boid());
	for (int i = 0; i < 8; i++)
		boids3.push_back(new Boid());

}


//--------------------------------------------------------------
void testApp::update() {

	ofVec3f min(0, 0);
	ofVec3f max(mouseX, mouseY);
	
	ofVec3f min1(mouseX, mouseY);
	ofVec3f max1(ofGetWidth(), ofGetHeight());

	ofVec3f min2(mouseX,0);
	ofVec3f max2(ofGetWidth() - 0, mouseY);

	ofVec3f min3(0, mouseY);
	ofVec3f max3(mouseX, ofGetHeight() - 0);

	for (int i = 0; i < traces.size(); i++) 
	{
		traces[i]->update();
		if (traces[i]->getLifetime() <= 0)
		{
			traces.erase(std::remove(traces.begin(), traces.end(), traces[i]), traces.end());
		}
	}
	

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);
		traces.push_back(new BoidLife(*boids[i]));
	}
	for (int i = 0; i < boids1.size(); i++)
	{
		boids1[i]->update(boids1, min1, max1);
		traces.push_back(new BoidLife(*boids1[i]));
	}
	for (int i = 0; i < boids2.size(); i++)
	{
		boids2[i]->update(boids2, min2, max2);
		traces.push_back(new BoidLife(*boids2[i]));
	}
	for (int i = 0; i < boids3.size(); i++)
	{
		boids3[i]->update(boids3, min3, max3);
		traces.push_back(new BoidLife(*boids3[i]));
	}
}

//--------------------------------------------------------------
void testApp::draw() {

	ofSetColor(100, 110, 170);
	font.drawString(text, ofGetWidth()/2 - font.stringWidth(text) / 2, ofGetHeight()/2 - font.stringHeight(text) / 2);

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}

	for (int i = 0; i < boids1.size(); i++)
	{
		boids1[i]->draw1();
	}
	for (int i = 0; i < boids2.size(); i++)
	{
		boids2[i]->draw2();
	}

	for (int i = 0; i < boids3.size(); i++)
	{
		boids3[i]->draw3();
	}

	for (int i = 0; i < traces.size(); i++) 
	{
		// std::cout << i << endl;
		traces[i]->draw();
	}
	for (int i = 0; i < traces.size(); i++)
	{
		// std::cout << i << endl;
		traces[i]->draw1();
	}

	for (int j = 0; j <10 ; j++)
	{
		ofDrawCircle(mouseX,mouseY,ofRandom(20,35));
		ofSetColor(255,150,160);
	}
	//-------------------------------------------------------
	

	
}


//--------------------------------------------------------------
void testApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {
	mouseX = x;
	mouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	if (button == 0) {
		a = mouseX;
		b = mouseY;
	}
	else {

	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}