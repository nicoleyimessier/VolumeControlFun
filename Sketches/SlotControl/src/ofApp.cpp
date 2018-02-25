#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    
    // ---  SCENEGRAPH ---
    //set up the scene with width + height
    scene = new ofxInterface::Node();
    scene->setSize(ofGetWidth(), ofGetHeight());
    scene->setName("Scene");
    
    //pass the scene to the touch manager
    ofxInterface::TouchManager::one().setup(scene);
    
    // ---  VOLUME BAR MANAGER ---
    vbMan = new VolumeBarManager();
    ofVec2f vbSize = ofVec2f(ofGetWidth() - margin*2, ofGetHeight() - 2*margin);
    vbMan->setup(vbSize, ofVec2f(margin, margin));
    scene->addChild(vbMan);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // ---  SCENEGRAPH ---
    
    //update touch manager
    ofxInterface::TouchManager::one().update();
    scene->updateSubtree(dt, true);
}

//--------------------------------------------------------------
void ofApp::draw(){
    // ---  SCENEGRAPH ---
    scene->render();
    
    if(showDebug){
        scene->renderDebug(); 
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'd': showDebug = !showDebug; break;
        default: break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
