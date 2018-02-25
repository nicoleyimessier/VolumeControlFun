#pragma once

#include "ofMain.h"
#include "VolumeBarManager.h"
#include "ofxInterface.h"
#include "ofxRemoteUIServer.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    // ---  SCENEGRAPH ---
    ofxInterface::Node* scene;
    
    // ---  VOLUME BAR MANAGER ---
    VolumeBarManager *vbMan;
    float margin = 100.0f;
    
    // --- MIS ---
    float dt = 1/60.0f;
    bool showDebug = false;
    
    // --- DEBUG INDEX ---
    float index = 0.0f;
    bool debugIndex = false; 
};
