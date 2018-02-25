//
//  VolumeBar.hpp
//  SlotControl
//
//  Created by Nicole Messier on 2/25/18.
//
//

#pragma once
#include "ofMain.h"
#include "ofxInterface.h"

class VolumeBar : public ofxInterface::Node{
public:
    VolumeBar();
    ~VolumeBar();
    
    void setup(ofVec2f _size, ofVec2f _pos);
    void update(float dt);
    void draw();
    
    // --- TOUCH INTERFACE ---
    void onTouchDown(ofxInterface::TouchEvent& event);
    void onTouchMove(ofxInterface::TouchEvent& event);
    void onTouchUp(ofxInterface::TouchEvent& event);
    
private:
    

    
};