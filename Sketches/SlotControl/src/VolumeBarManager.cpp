//
//  VolumeBarManager.cpp
//  SlotControl
//
//  Created by Nicole Messier on 2/25/18.
//
//

#include "VolumeBarManager.h"

VolumeBarManager::VolumeBarManager(){
    
}

VolumeBarManager::~VolumeBarManager(){
    
}

void VolumeBarManager::setup(ofVec2f _size, ofVec2f _pos){
    
    // --- ATTRIBUTES ---
    setSize(_size.x, _size.y);
    setPosition(_pos.x, _pos.y);
    setPlane(2.0f);
    
    // --- TOUCH EVENTS ---
    ofAddListener(eventTouchDown, this, &VolumeBarManager::onTouchDown);
    ofAddListener(eventTouchUp, this, &VolumeBarManager::onTouchUp);
    ofAddListener(eventTouchMove, this, &VolumeBarManager::onTouchMove);
    
    // --- VOLUME BARS ---
    setupVolumneBars();
}

void VolumeBarManager::setupVolumneBars(){
    //Calculate size of bars
    ofVec2f size;
    size.x = (getSize().x - margin*((float)NUM_BARS - 1))/(float)NUM_BARS;
    size.y = getSize().y - 2*margin;
    
    for(int i=0; i<NUM_BARS; i++){
        VolumeBar *vb = new VolumeBar();
        addChild(vb);
        vb->setup(size, ofVec2f((size.x + margin)*(i), margin));
        vb->setVolumeHeight(size.y*ofRandom(0.1, 1.0));
        volumeBars.push_back(vb);
    }
}

void VolumeBarManager::update(float dt){
    
}

void VolumeBarManager::draw(){
    //ofSetColor(255, 0, 0);
    //ofDrawRectangle(0, 0, getSize().x, getSize().y);
    
    if(beingTouched){
        ofSetColor(0, 255, 255);
        ofDrawCircle(touchAnchor.x, touchAnchor.y, 5);
    }
    
}

#pragma mark TOUCH

void VolumeBarManager::onTouchDown(ofxInterface::TouchEvent& event){
    beingTouched = true;
    touchAnchor = toLocal(event.position);
}

void VolumeBarManager::onTouchMove(ofxInterface::TouchEvent& event){
    beingTouched = true;
}

void VolumeBarManager::onTouchUp(ofxInterface::TouchEvent& event){
    beingTouched = false;
}
