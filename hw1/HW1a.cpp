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
    //bottom row
    glViewport(0, 0, w/3, h/3);
    glViewport(w/3, 0, w/3, h/3);
    glViewport((2*w)/3, 0, w/3, h/3);

    //center row
    glViewport(0, h/3, w/3, h/3);
    glViewport(w/3, h/3, w/3, h/3);
    glViewport((2*w)/3, h/3, w/3, h/3);

    //top row
    glViewport(0, (2*h)/3, w/3, h/3);
    glViewport(w/3, (2*h)/3, w/3, h/3);
    glViewport((2*w)/3, (2*h)/3, w/3, h/3);


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

    //left bottom P
    glBegin(GL_POINTS);
       for(int i=0; i<32; i+=2){
           glVertex2f(Vertices[i]*.325-.875, Vertices[i+1]*.325-.675);
       }
    glEnd();

    //left middle P
    glBegin(GL_LINE_LOOP);
       for(int i=0; i<32; i+=2){
           glVertex2f(Vertices[i]*.325-.875, Vertices[i+1]*.325);
       }
    glEnd();

    //left top P
    glBegin(GL_POLYGON);
       for(int i=0; i<32; i+=2){
           glVertex2f(Vertices[i]*.325-.875, Vertices[i+1]*.325+.675);
       }
    glEnd();

    //center middle P
    glBegin(GL_POLYGON);
       glVertex2f(Vertices[18]*.325, Vertices[19]*.325);
       glVertex2f(Vertices[20]*.325, Vertices[21]*.325);
       glVertex2f(Vertices[22]*.325, Vertices[23]*.325);
    glEnd();

    //center top P
    glBegin(GL_POLYGON);
        glVertex2f(Vertices[8]*.325, Vertices[9]*.325+.675);
        glVertex2f(Vertices[10]*.325, Vertices[11]*.325+.675);
        glVertex2f(Vertices[12]*.325, Vertices[13]*.325+.675);
        glVertex2f(Vertices[14]*.325, Vertices[15]*.325+.675);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(Vertices[16]*.325, Vertices[17]*.325+.675);
        glVertex2f(Vertices[18]*.325, Vertices[19]*.325+.675);
        glVertex2f(Vertices[20]*.325, Vertices[21]*.325+.675);
        glVertex2f(Vertices[22]*.325, Vertices[23]*.325+.675);
    glEnd();

    //center bottom p
    glBegin(GL_LINES);
        for(int i=0; i<32; i+=4){
            glVertex2f(Vertices[i]*.325, Vertices[i+1]*.325-.675);
            glVertex2f(Vertices[i+2]*.325, Vertices[i+3]*.325-.675);
        }
    glEnd();

    //right top P
    glBegin(GL_POLYGON);
       for(int i=0; i<32; i+=2){
           glVertex2f(Vertices[i]*.325+.875, Vertices[i+1]*.325+.675);
       }
    glEnd();

    //right middle P
    glBegin(GL_POLYGON);
        glVertex2f(Vertices[8]*.325+.875, Vertices[9]*.325);
        glVertex2f(Vertices[10]*.325+.875, Vertices[11]*.325);
        glVertex2f(Vertices[12]*.325+.875, Vertices[13]*.325);
     glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(Vertices[10]*.325+.875, Vertices[11]*.325);
        glVertex2f(Vertices[12]*.325+.875, Vertices[13]*.325);
        glVertex2f(Vertices[14]*.325+.875, Vertices[15]*.325);
     glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(Vertices[16]*.325+.875, Vertices[17]*.325);
        glVertex2f(Vertices[18]*.325+.875, Vertices[19]*.325);
        glVertex2f(Vertices[20]*.325+.875, Vertices[21]*.325);
     glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(Vertices[18]*.325+.875, Vertices[19]*.325);
        glVertex2f(Vertices[20]*.325+.875, Vertices[21]*.325);
        glVertex2f(Vertices[22]*.325+.875, Vertices[23]*.325);
     glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(Vertices[20]*.325+.875, Vertices[21]*.325);
        glVertex2f(Vertices[22]*.325+.875, Vertices[23]*.325);
        glVertex2f(Vertices[24]*.325+.875, Vertices[25]*.325);
     glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(Vertices[22]*.325+.875, Vertices[23]*.325);
        glVertex2f(Vertices[24]*.325+.875, Vertices[25]*.325);
        glVertex2f(Vertices[26]*.325+.875, Vertices[27]*.325);
     glEnd();

    //right bottom p
    glBegin(GL_LINE_STRIP);
        for(int i=0; i<32; i+=4){
            glVertex2f(Vertices[i]*.325+.875, Vertices[i+1]*.325-.675);
            glVertex2f(Vertices[i+2]*.325+.875, Vertices[i+3]*.325-.675);
        }
    glEnd();
    glFlush();

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

