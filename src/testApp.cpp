#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    music.loadSound("miii.mp3");
    senderMusic.setup(HOST_MUS, PORT);
    receiver.setup(PORT);
    senderHue.setup(HOST_HUE, PORT);
    
    mode=0;
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofxOscMessage m;

    //OSC
    ofSetWindowTitle(ofToString(round(ofGetFrameRate())));
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
		if(timers[i] < ofGetElapsedTimef()){
			msg_strings[i] = "";
		}
	}
    while(receiver.hasWaitingMessages()){
        receiver.getNextMessage(&m);
        if(m.getAddress() == "/music/bars/tick"){
            //stateMachine.getSharedData().ram=true;
            mode=m.getArgAsInt32(0);
            cout<<mode<<endl;
		}
    }
    m.clear();
    
    
    
    //HUE
    string addres[HUE_SIZE] = {"1","2","3","4","5","6"};
    
    if (mode==4) {
        for (int i=0; i<HUE_SIZE; i++) {
            flash[i]=!flash[i];
        }
        //cout<<flash[1]<<endl;
        for (int i=0; i<HUE_SIZE; i++) {
            bri[i]=50+205*flash[i];
        }
        for (int i=0; i<HUE_SIZE; i++) {
            sat[i]=ofRandom(255);
        }
        for (int i=0; i<3; i++) {
            hue[i]=ofRandom(255)*255;
        }
        for (int i=0; i<3; i++) {
            tra[i]=0;
        }
        
    }else if(mode==3){
        for (int i=0; i<HUE_SIZE; i++) {
            flash[i]=!flash[i];
        }
        for (int i=0; i<HUE_SIZE; i++) {
            bri[i]=50+205*flash[i];
        }
        for (int i=0; i<HUE_SIZE; i++) {
            sat[i]=255;
        }
        for (int i=0; i<HUE_SIZE; i++) {
            hue[i]=ofRandom(50)*255;
        }
        for (int i=0; i<3; i++) {
            tra[i]=0;
        }
        
    }else if(mode==2){
        for (int i=0; i<HUE_SIZE; i++) {
            flash[i]=!flash[i];
        }
        for (int i=0; i<HUE_SIZE; i++) {
            bri[i]=255;
        }
        for (int i=0; i<HUE_SIZE; i++) {
            sat[i]=255*flash[i];
        }
        for (int i=0; i<HUE_SIZE; i++) {
            hue[i]=(ofGetFrameNum()%255)*255;
        }
        for (int i=0; i<3; i++) {
            tra[i]=5;
        }
        
    }else if(mode==1){
        for (int i=0; i<HUE_SIZE; i++) {
            if (bri[i]!=255) {
                bri[i]=155;
            }
        }
        for (int i=0; i<HUE_SIZE; i++) {
            sat[i]=255;
        }
        for (int i=0; i<HUE_SIZE; i++) {
            hue[i]=(ofGetFrameNum()%255)*255;
        }
        for (int i=0; i<3; i++) {
            tra[i]=10;
        }
        
    }else if(mode==0){
        for (int i=0; i<HUE_SIZE; i++) {
            bri[i]=ofGetFrameNum()%155;
        }
        for (int i=0; i<HUE_SIZE; i++) {
            sat[i]=255;
        }
        for (int i=0; i<HUE_SIZE; i++) {
            hue[i]=157*255;
        }
        for (int i=0; i<3; i++) {
            tra[i]=10;
        }
    }
    
    for (int i=0; i<HUE_SIZE; i++) {
        
        if (ofGetFrameNum()%45==8*i) {//65535
            
            m.clear();
            m.setAddress("/"+ addres[i] +"/bri");
            m.addIntArg(bri[i]);
            senderHue.sendMessage(m);
            
            m.clear();
            m.setAddress("/"+ addres[i] +"/hue");
            m.addIntArg(hue[i]);
            senderHue.sendMessage(m);
            
            m.clear();
            m.setAddress("/"+ addres[i] +"/sat");
            m.addIntArg(sat[i]);
            senderHue.sendMessage(m);
            
            m.clear();
            m.setAddress("/"+ addres[i] +"/transitiontime");
            m.addIntArg(tra[i]);
            senderHue.sendMessage(m);
            
            
        }
    }
}
//--------------------------------------------------------------
void testApp::draw(){
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 's' || key == 'S'){
		ofxOscMessage m;
		m.setAddress("/music/start");
		senderMusic.sendMessage(m);
        music.play();
	}
    if(key == 'a' || key == 'a'){
		if (mode<4) {
            mode++;
        }else{
            mode=0;
        }
        cout<<"mode:"<<mode<<endl;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}