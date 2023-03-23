#include "ofMain.h"
#include "testApp.h"



//#include <string>
using namespace std;

//========================================================================
int main() {
 
    ofSetupOpenGL(550,550, OF_WINDOW);            // <-------- setup the GL context

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp( new testApp());
   
  
    return 0; 
}


