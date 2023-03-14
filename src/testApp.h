#ifndef _TEST_APP
#define _TEST_APP


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

    int a, b,c,d;
    int mouseX;
    int mouseY;

    ofTrueTypeFont font;
    string text;

};

#endif	
