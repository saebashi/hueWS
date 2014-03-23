#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define NUM_MSG_STRINGS 20

#define HOST_MUS "192.168.2.7"
#define HOST_HUE "192.168.1.243"

#define PORT 7400
#define HUE_SIZE 6
class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofSoundPlayer music;
    ofxOscReceiver receiver;
    ofxOscSender senderMusic;
    ofxOscSender senderHue;
    int mode;
    bool flash[HUE_SIZE];
    
    int bri[HUE_SIZE];
    int hue[HUE_SIZE];
    int tra[HUE_SIZE];
    int sat[HUE_SIZE];
    
    string msg_strings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];

};
