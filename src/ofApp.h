#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxHttpUtils.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void getData();
  
    ofxJSONElement json;
    
    ofxHttpUtils httpUtils;
    int counter;
    string responseStr;
    string requestStr;
    string action_url;
    float value;


		
};
