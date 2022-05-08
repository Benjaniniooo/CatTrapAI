#include "include.hpp"

#include "CHandler.hpp"

#pragma once

#ifndef CFRAMEWORK_HPP
#define CFRAMEWORK_HPP

#define Framework CFramework::get()

typedef void (*t_eventHandler)(sf::Event*, sf::RenderWindow*);
typedef void (*t_renderHandler)(sf::RenderWindow*);

typedef void (*t_imGuiHandler)(void);

typedef void (*t_openGLInit)(void);
typedef void (*t_openGLHandler)(void);


class CFramework : public Singleton<CFramework>{
public:
     CFramework(void);

     void init(int windowWidth, int windowHeight, std::string title, t_eventHandler eventHandler, t_renderHandler renderHandler);
     void init(int windowWidth, int windowHeight, std::string title, t_eventHandler eventHandler, t_renderHandler renderHandler, sf::ContextSettings settings);

     void init(int windowWidth, int windowHeight, std::string title, CHandler* handler);
     void init(int windowWidth, int windowHeight, std::string title, CHandler* handler, sf::ContextSettings settings);

     void initImGui(t_imGuiHandler imGuiHandler);
     void initImGui(CHandler* imGuiHandlerClass);

     void initOpenGL(t_openGLInit openGLInit, t_openGLHandler openGLHandler, bool simpleMode);
     void initOpenGL(CHandler* openGLHandlerClass, bool simpleMode);

     void close(void);

     void handleEvents(void);

     void render(void);

     bool m_windowIsAlive;

private:
     t_eventHandler m_eventHandler;
     t_renderHandler m_renderHandler;
     bool m_isMemberFunction;
     CHandler* m_handlerClass;

     bool m_imGuiIsClass;
     bool m_imGuiExists;
     t_imGuiHandler m_imguiHandler;
     CHandler* m_imGuiHandlerClass;

     bool m_openGLIsClass;
     bool m_openGLExists;
     t_openGLHandler m_openGLHandler;
     CHandler* m_openGLHandlerClass;
     bool m_simpleMode;

     int m_windowWidth, m_windowHeight;

     sf::Event m_event;
     sf::RenderWindow m_window;

     sf::Clock m_deltaClock;
};

#endif
