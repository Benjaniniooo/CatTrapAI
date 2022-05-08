#include "CHandler.hpp"

CHandler::CHandler(){}

void CHandler::eventHandler(sf::Event* event, sf::RenderWindow* window){}

void CHandler::renderHandler(sf::RenderWindow* window){}

void CHandler::imGuiHandler(void){}

void CHandler::openGLInit(void){}
void CHandler::openGLHandler(void){
     glClear(GL_COLOR_BUFFER_BIT);

// Drawing is done by specifying a sequence of vertices.  The way these
// vertices are connected (or not connected) depends on the argument to
// glBegin.  GL_POLYGON constructs a filled polygon.
glBegin(GL_POLYGON);
  glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
  glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
  glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
glEnd();

// Flush drawing command buffer to make drawing happen as soon as possible.
glFlush();

}
