#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxHttpUtils.h"
#include "ofxWiringPi.h"


class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
  
    ofxJSONElement json;
    
    ofxHttpUtils httpUtils;
    int counter;
    string responseStr;
    string requestStr;
    string action_url;
    float value;

    
		
};
