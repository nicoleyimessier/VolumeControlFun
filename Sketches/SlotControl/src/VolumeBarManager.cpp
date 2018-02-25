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
    updateIndex();
    
    if(!beingTouched){
        
        
        index -= currentVel;
        
        //Dampen velocity
        currentVel *= velFriction;
        
        float tempIndex = index;
        targetIndex = round(tempIndex);
        loopIndex();
        
        if(fabs(currentVel) < swipeVelRange ){
            
            index = ofLerp(index, targetIndex, indexLerpAmt);

        }
    
    } else {
    
    }
}

void VolumeBarManager::draw(){
    //ofSetColor(255, 0, 0);
    //ofDrawRectangle(0, 0, getSize().x, getSize().y);
    
    if(beingTouched){
        ofSetColor(0, 255, 255);
        ofDrawCircle(touchAnchor.x, touchAnchor.y, 5);
    }
    
}

#pragma mark SLOT MACHINE
void VolumeBarManager::updateIndex(){
    if(!volumeBars.size()) return;
    
    for(int i=0; i < volumeBars.size(); i++){
        ofVec2f pos;
        float step =  getSize().x/(float)NUM_BARS;
        pos.x = step*(i) + step*index;
        
        if(pos.x > getSize().x){
            pos.x -= getSize().x;
        }
        
        pos.y = volumeBars[i]->getPosition().y;
        volumeBars[i]->setPosition((ofVec3f)pos);
    }
}

void VolumeBarManager::loopIndex(){
    if(!(volumeBars.size() - 1)) return;
    
    //SET BOUNDARIES
    float minRange = -1.0f;
    float maxRange = volumeBars.size() - 1;
    float fullRange = volumeBars.size();
    
    //LOOP POSITIVE
    while(index < minRange){
        index +=fullRange;
    }
    
    //LOOP MINUS
    while(index > maxRange){
        index -= fullRange;
    }
}


void VolumeBarManager::setIndex(float _index){
    index = _index;
}

#pragma mark TOUCH

void VolumeBarManager::onTouchDown(ofxInterface::TouchEvent& event){
    beingTouched = true;
    touchAnchor = toLocal(event.position);
    
    // --- SLOT MACHINE ---
    lastTouch = touchAnchor.x;
    startTime = ofGetElapsedTimef();
}

void VolumeBarManager::onTouchMove(ofxInterface::TouchEvent& event){
    beingTouched = true;
    ofVec2f local = toLocal(event.position);
    
    // --- SLOT MACHINE ---
    float offset = (local.x - lastTouch);
    index += -offset;
    lastTouch = local.x;
    loopIndex();
    endTime = ofGetElapsedTimef();
}

void VolumeBarManager::onTouchUp(ofxInterface::TouchEvent& event){
    beingTouched = false;
    
    currentVel = fabs(touchAnchor.x - lastTouch)/endTime - startTime;
}
