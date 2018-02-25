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
    size.x = getSize().x - margin*((float)NUM_BARS - 1);
    size.y = getSize().y - 2*margin;
    
    for(int i=0; i<NUM_BARS; i++){
        VolumeBar *vb = new VolumeBar();
        vb->setup(size, ofVec2f((size.x + margin)*(i+1), margin));
        volumeBars.push_back(vb);
        addChild(vb); 
    }
}

void VolumeBarManager::update(float dt){
    
}

void VolumeBarManager::draw(){
    ofSetColor(255, 0, 0);
    ofDrawRectangle(0, 0, getSize().x, getSize().y);
    
    if(beingTouched){
        ofSetColor(0, 0, 255);
        ofDrawCircle(touchAnchor.x, touchAnchor.y, 10);
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
