#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    action_url = "https://128.2.109.159/piwebapi/streams/A0EDrCQspyh10qS-uAmnJ8eXAL0kemPll5BGfhGhbNZgNbw8T76JDZWhlUE9yV5tbOekwMTI4LjIuMTA5LjE1OVxDQU1QVVMgU1VCTUVURVJJTkdcTUFJTiBDQU1QVVNcR0FURVN8UE9XRVIgSU5URU5TSVRZ/value";

    httpUtils.setBasicAuthentication("CMU_Students","Energy1?");
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //every two minutes, request an update
    int timeMillis = (ofGetElapsedTimeMillis() % (120 * 1000));
    
    if( timeMillis > 0 && timeMillis < 10){
        getData();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::getData(){
    ofLog() << "retreiving data at " << ofGetTimestampString();
        
    //get the response and the status of the GET request
    ofxHttpResponse response = httpUtils.getUrl(action_url);
    int status = response.status;
    
    //let us know what the status and reason is
    ofLog() << "status: " << status;
    ofLog() << "reason: " << response.reasonForStatus;
    
    //if success status:
    if(status == 200)
    {
        //see if we can parse the data
        bool success = json.parse(response.responseBody);
        
        //if we can parse, print it out
        if(success)
        {
            ofLog() << json.getRawString();
        } else
        {
            ofLog() << "could not parse";
        }
       
        //get the "value" parameter and read it as a float
        value = json["Value"].asFloat();
        
        //tell us what it is
        ofLog() << "value: " << value;
    }

}

