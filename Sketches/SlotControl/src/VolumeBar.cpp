//
//  VolumeBar.cpp
//  SlotControl
//
//  Created by Nicole Messier on 2/25/18.
//
//

#include "VolumeBar.h"


VolumeBar::VolumeBar(){
    
}

VolumeBar::~VolumeBar(){
    
}

void VolumeBar::setup(ofVec2f _size, ofVec2f _pos){
    // --- Attributes ---
    setSize(_size.x, _size.y);
    setPosition(_pos);
    
}

void VolumeBar::update(float dt){
    
}

void VolumeBar::draw(){
    ofSetColor(0, 255, 0);
    ofDrawRectangle(0, 0, size.x, size.y); 
}

#pragma mark TOUCH INTERFACE

void VolumeBar::onTouchDown(ofxInterface::TouchEvent& event){
    
}

void VolumeBar::onTouchMove(ofxInterface::TouchEvent& event){
    
}

void VolumeBar::onTouchUp(ofxInterface::TouchEvent& event){
    
}

