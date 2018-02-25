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
    setPlane(-1.0f);
}

void VolumeBar::update(float dt){
    
}

void VolumeBar::draw(){
    ofSetColor(0, 0, 255);
    ofFill(); 
    //ofVec2f size refers to the node size whereas volumeheight refers to the volume level
    ofDrawRectangle(0, 0, size.x, volumHeight);
    
    ofNoFill();
    ofDrawRectangle(0, 0, size.x, size.y);
}

#pragma mark ATTRIBUTES

void VolumeBar::setVolumeHeight(float _vh){
    volumHeight = _vh;
    
    ofLogNotice("VolumeBar") << "volumHeight: " << volumHeight;
}

#pragma mark TOUCH INTERFACE

void VolumeBar::onTouchDown(ofxInterface::TouchEvent& event){
    
}

void VolumeBar::onTouchMove(ofxInterface::TouchEvent& event){
    
}

void VolumeBar::onTouchUp(ofxInterface::TouchEvent& event){
    
}

