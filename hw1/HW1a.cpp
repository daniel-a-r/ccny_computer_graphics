// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2022 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2022
// ===============================================================

#include "HW1a.h"

// init array of 16 vertices for letter 'P'
float Vertices[] = {
	-0.5f , -0.75f,
	-0.5f , -0.5f,
	-0.5f , -0.25f,
	-0.5f ,  0.0f,
	-0.5f ,  0.25f,
	-0.5f ,  0.5f,
	-0.25f,  0.75f,
	 0.0f ,  0.75f,
	 0.25f,  0.75f,
	 0.5f ,  0.75f,
	 0.75f,  0.5f,
	 0.75f,  0.25f,
	 0.5f ,  0.0f,
	 0.25f,  0.0f,
	 0.0f ,  0.0f,
	-0.25f,  0.0f
};

static int DrawModes[] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_QUADS,
	GL_POLYGON
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
	: HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
	// PUT YOUR CODE HERE
    // initialize GL function resolution for current context
    initializeGLFunctions();

    // init state variables
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // set background color
    glColor3f   (1.0F, 1.0f, 1.0f);   // set foreground color
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{
	// PUT YOUR CODE HERE
    // save window dimensions
	m_winW = w;
	m_winH = h;

    // compute aspect ratio
    float xmax, ymax;
    float ar = (float) w / h;
    if(ar > 1.0) {  // wide screen
       xmax = ar;
       ymax = 1.;
    } else {  // tall screen
       xmax = 1.;
       ymax = 1/ar;
    }

    // set viewports
    glViewport(0, 0, w, h);
    

    // init viewing coordinates for orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);

}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
	// PUT YOUR CODE HERE
    // clear canvas with background values
    glClear(GL_COLOR_BUFFER_BIT);

    // viewport dimensions
	int w = m_winW / 3;
	int h = m_winH / 3;

	for(int i=0; i<9; i++){
		glViewport((i%3)*w, (i/3)*h, w, h);
		
        glBegin(DrawModes[i]);
           for(int j=0; j<32; j=j+2){
               glVertex2f(Vertices[j], Vertices[j+1]);
           }
        glEnd();
	} 
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
	// init group box
	QGroupBox *groupBox = new QGroupBox("Homework 1a");
	groupBox->setStyleSheet(GroupBoxStyle);

	return(groupBox);
}
