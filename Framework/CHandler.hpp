#include "include.hpp"

#pragma once

#ifndef CHANDLER_HPP
#define CHANDLER_HPP

class CHandler{
public:
     CHandler();

     virtual void eventHandler(sf::Event* event, sf::RenderWindow* window);
     virtual void renderHandler(sf::RenderWindow* window);

     virtual void imGuiHandler(void);

     virtual void openGLInit(void);
     virtual void openGLHandler(void);
};

#endif
