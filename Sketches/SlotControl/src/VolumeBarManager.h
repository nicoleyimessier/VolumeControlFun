//
//  VolumeBarManager.hpp
//  SlotControl
//
//  Created by Nicole Messier on 2/25/18.
//
//

#pragma once
#include "ofMain.h"
#include "ofxInterface.h"
#include "VolumeBar.h"

#define NUM_BARS 10

class VolumeBarManager : public ofxInterface::Node{
    
public:
    VolumeBarManager();
    ~VolumeBarManager();
    
    void setup(ofVec2f _size, ofVec2f _pos);
    void update(float dt);
    void draw();
    
    // --- TOUCH INTERFACE ---
    void onTouchDown(ofxInterface::TouchEvent& event);
    void onTouchMove(ofxInterface::TouchEvent& event);
    void onTouchUp(ofxInterface::TouchEvent& event);
    
    // --- SLOT MACHINE ---
    void setIndex(float _index);
    
private:
    // --- VOLUME BARS ---
    vector<VolumeBar*> volumeBars;
    void setupVolumneBars();
    float margin = 10;
    
    // --- TOUCH INTERFACE ---
    ofVec2f touchAnchor;
    bool beingTouched = false;
    
    // --- SLOT MACHINE ---
    void updateIndex();
    void loopIndex();
    
    float index = 0.0f;
    float targetIndex = 0.0f;
    float currentVel = 0.0f;
    float velFriction = 0.01f;
    float scrollGain = 0.8f;
    float swipeVelRange = 0.1f;
    float indexLerpAmt = 0.1f;
    
    float startTime;
    float endTime; 
    float lastTouch;
};