#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    
    // ---  REMOTE UI ---
    RUI_SETUP();
    RUI_SHARE_PARAM(index, 0, 10);
    RUI_LOAD_FROM_XML();
    
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
    
    if(debugIndex){
        //INDEX TEXT
        vbMan->setIndex(index);
    }
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
    ofxInterface::TouchManager::one().touchMove(button, ofVec2f(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofxInterface::TouchManager::one().touchDown(button, ofVec2f(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofxInterface::TouchManager::one().touchUp(button, ofVec2f(x,y));
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
