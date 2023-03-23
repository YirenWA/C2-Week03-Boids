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

	// 串行通信開始
	serial.setup("COM8 Arduino Uno", 9600);

	
	speedx.resize(AMOUNT);
	speedy.resize(AMOUNT);
	for (int i = 0; i < AMOUNT; i++) {
		speedx[i] = ofRandom(0.001, 0.04);
		speedy[i] = ofRandom(0.001, 0.02);
	}

	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	font.load("NewYork PERSONAL USE.otf", 55);//要先在bin文件夹里加入字体

	ofBackground(20,20,20);

	// set up the boids
	for (int i = 0; i < 30; i++)
		boids.push_back(new Boid());
	for (int i = 0; i < 30; i++)
		boids1.push_back(new Boid());
	for (int i = 0; i < 30; i++)
		boids2.push_back(new Boid());
	for (int i = 0; i < 30; i++)
		boids3.push_back(new Boid());

}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
void testApp::update() {
	// Check if there is any serial data available
	if (serial.available() > 0) {
		byteData = serial.readByte();// Read the byte data from the serial connection

		cout << "Received byte data: " << byteData << endl;
	}
	else {
		byteData = 0;// Set the `byteData` to a default value (for example, 0)
	}

	// Check if the Button1 is pressed
	if (!Screen || byteData == 49 || byteData == 10 || byteData == 13) {
		// Set the `Screen` variable to `true`
		Screen = true;

		cout << "Button1 pressed, Screen set to true" << endl;
	}

	// Check if the Button2 is pressed
	if (!Screen || byteData1 == 50 || byteData1 == 10 || byteData1 == 13) {
		// Set the `Screen1` variable to `true`
		Screen1 = true;

		cout << "Button2 pressed, Screen set to true" << endl;
	}

	// Check if the Button3 is pressed
	if (!Screen || byteData1 == 50 || byteData1 == 10 || byteData1 == 13) {
		// Set the `Screen1` variable to `true`
		Screen2 = true;

		cout << "Button3 pressed, Screen set to true" << endl;
	}

	// Check if the `byteData` is equal to 10,13,49
	if (byteData == 49 || byteData == 10 || byteData == 13) {
		// Set the `Screen` variable to `false`
		Screen = false;

		cout << "byteData is 10,13,49, Screen set to false" << endl;
	}

	// Check if the `byteData` is equal to 10,13,50
	if (byteData1 == 50 || byteData1 == 10 || byteData1 == 13) {
		// Set the `Screen1` variable to `false`
		Screen1 = false;

		cout << "byteData is 10,13,50, Screen1 set to false" << endl;
	}




	ofVec3f min(ofGetWidth() / 2 - 100, ofGetHeight() / 2 - 100);
	ofVec3f max(ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 100);
	
	ofVec3f min1(ofGetWidth() / 2 - 100, ofGetHeight() / 2 - 100);
	ofVec3f max1(ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 100);

	ofVec3f min2(ofGetWidth() / 2 - 100, ofGetHeight() / 2 - 100);
	ofVec3f max2(ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 100);

	ofVec3f min3(ofGetWidth() / 2 - 100, ofGetHeight() / 2 - 100);
	ofVec3f max3(ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 100);

	ofVec3f min0(0, 0);
	ofVec3f max0(ofGetWidth(), ofGetHeight());

	
    
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
               boids1[i]->update(boids1, min, max);
               traces.push_back(new BoidLife(*boids1[i]));
           
       } 
       
       for (int i = 0; i < boids2.size(); i++)
       {
               boids2[i]->update(boids2, min, max);
               traces.push_back(new BoidLife(*boids2[i]));
               
       }
       
       for (int i = 0; i < boids3.size(); i++)
       {
               boids3[i]->update(boids3, min, max);
               traces.push_back(new BoidLife(*boids3[i]));
       }
       
}

//--------------------------------------------------------------
void testApp::draw() {
	
	//器皿
	//----------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------
	ofSetCircleResolution(70);
	ofNoFill();
	ofSetLineWidth(1.2);
    ofSetColor(160, 185, 255, 140);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 195);
	
	ofSetLineWidth(4.8);
	ofSetColor(180, 195, 205,50);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2 ,150);
	
	ofSetLineWidth(2.0);
	ofSetColor(200, 235, 205, 170);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 184);
	

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
		traces[i]->draw2();
    }

    if (!Screen1 || byteData == 50 || byteData == 13) {

        Screen1 = true;
        for (int i = 0; i < traces.size(); i++)
        {
            // std::cout << i << endl;
            traces[i]->draw1();
			traces[i]->setDraw2Size(traces[i]->getDraw2Size() -0.5);
        }
    }
    
    if (!Screen || byteData == 49  ) {

        Screen = true;
        for (int i = 0; i < traces.size(); i++)
        {
            // std::cout << i << endl;
			
            traces[i]->draw2();
			traces[i]->setDraw2Size(traces[i]->getDraw2Size() + 0.99 );
			
        }
    }

	if (!Screen2 || byteData == 10) {

		Screen2 = true;
		for (int i = 0; i < traces.size(); i++)
		{
			// std::cout << i << endl;

			traces[i]->draw3();
			traces[i]->setDraw2Size(traces[i]->getDraw2Size() + 3.0);

		}
	}
	
	//-------------------------------------------------------
	//-------------------------------------------------------

    //文本
    msg = "Variation\n";
    ofSetColor(110, 110, 140, 255);
    font.drawString(msg, ofGetWidth() / 2 - font.stringWidth(msg) / 2, ofGetHeight() - 15);
    //----------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------

	
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}