#ifndef _TEST_APP
#define _TEST_APP
#define AMOUNT 13

#include "ofMain.h"
#include <vector>
#include "boid.h"
#include "BoidLife.h"

class testApp : public ofBaseApp{
	
public:
    ~testApp();
	
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);

    std::vector<Boid *> boids;
    std::vector<Boid*> boids1;
    std::vector<Boid*> boids2;
    std::vector<Boid*> boids3;
    std::vector<BoidLife *> traces;
    std::vector<BoidLife*> traces1;

    int a,b,c,d;
    int mouseX;
    int mouseY;

    ofTrueTypeFont font;
    string text;


    int nBytesRead = 0;
    ofSerial serial;
    char bytesReadString1[2];
    char bytesReadString2[10];
    char bytesReadString3[7];

    string sensorValue;
    int byteData;
    int byteData1;
    int byteData2;
    string msg;
    char sendData = 1;

    bool byteDataReceived = false;
    bool Screen = false;
    bool Screen1 = false;
    bool Screen2 = false;

    vector<float> speedx;//ÃûÎªspeedxµÄ
    vector<float> speedy;

};

#endif	
