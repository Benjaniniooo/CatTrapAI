#include "CFramework.hpp"

CFramework::CFramework(){
     m_windowIsAlive = false;

     m_windowWidth = 0;
     m_windowHeight = 0;

     m_isMemberFunction = false;
     m_eventHandler = nullptr;
     m_renderHandler = nullptr;
     m_handlerClass = nullptr;

     m_imGuiIsClass = false;
     m_imguiHandler = nullptr;
     m_imGuiHandlerClass = nullptr;
     m_imGuiExists = false;

     m_openGLIsClass = false;
     m_openGLHandler = nullptr;
     m_openGLHandlerClass = nullptr;
     m_openGLExists = false;
     m_simpleMode = true;
}

void CFramework::init(int windowWidth, int windowHeight, std::string title, t_eventHandler eventHandler, t_renderHandler renderHandler){
     m_windowWidth = windowWidth;
     m_windowHeight = windowHeight;

     m_isMemberFunction = false;
     m_eventHandler = eventHandler;
     m_renderHandler = renderHandler;

     m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), title, sf::Style::Default);

     m_windowIsAlive = true;
}
void CFramework::init(int windowWidth, int windowHeight, std::string title, t_eventHandler eventHandler, t_renderHandler renderHandler, sf::ContextSettings settings){
     m_windowWidth = windowWidth;
     m_windowHeight = windowHeight;

     m_isMemberFunction = false;
     m_eventHandler = eventHandler;
     m_renderHandler = renderHandler;

     m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), title, sf::Style::Default, settings);

     m_windowIsAlive = true;
}

void CFramework::init(int windowWidth, int windowHeight, std::string title, CHandler* handler){
     m_windowWidth = windowWidth;
     m_windowHeight = windowHeight;

     m_isMemberFunction = true;
     m_handlerClass = handler;

     m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), title, sf::Style::Default);

     m_windowIsAlive = true;
}
void CFramework::init(int windowWidth, int windowHeight, std::string title, CHandler* handler, sf::ContextSettings settings){
     m_windowWidth = windowWidth;
     m_windowHeight = windowHeight;

     m_isMemberFunction = true;
     m_handlerClass = handler;

     m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), title, sf::Style::Default, settings);

     m_windowIsAlive = true;
}

void CFramework::initImGui(t_imGuiHandler imGuiHandler){
     ImGui::SFML::Init(m_window);

     m_imguiHandler = imGuiHandler;

     m_imGuiIsClass = false;
     m_imGuiExists = true;
}
void CFramework::initImGui(CHandler* imGuiHandlerClass){
     ImGui::SFML::Init(m_window);

     m_imGuiHandlerClass = imGuiHandlerClass;

     m_imGuiIsClass = true;
     m_imGuiExists = true;
}

void CFramework::initOpenGL(t_openGLInit openGLInit, t_openGLHandler openGLHandler, bool simpleMode){
     openGLInit();

     m_openGLHandler = openGLHandler;

     m_openGLExists = true;
     m_openGLIsClass = false;

     m_simpleMode = simpleMode;
}
void CFramework::initOpenGL(CHandler* openGLHandlerClass, bool simpleMode){
     openGLHandlerClass->openGLInit();

     m_openGLHandlerClass = openGLHandlerClass;

     m_openGLExists = true;
     m_openGLIsClass = true;

     m_simpleMode = simpleMode;
}

void CFramework::handleEvents(){
     while(m_window.pollEvent(m_event)){
          if(m_imGuiExists){
               ImGui::SFML::ProcessEvent(m_event);
          }

          if(!m_isMemberFunction){
               m_eventHandler(&m_event, &m_window);
          }else{
               m_handlerClass->eventHandler(&m_event, &m_window);
          }

          if(m_event.type == sf::Event::Closed){
               close();
          }
     }
}

void CFramework::close(){
     m_window.close();

     m_windowIsAlive = false;

     if(m_imGuiExists){
          m_imGuiExists = false;

          ImGui::SFML::Shutdown();
     }
}

void CFramework::render(){
     m_window.setActive(true);

     m_window.clear();

     if(m_openGLExists){
          if(!m_openGLIsClass){
               m_openGLHandler();
          }else{
               m_openGLHandlerClass->openGLHandler();
          }

          if(m_simpleMode){
               m_window.pushGLStates();
               //m_window.resetGLStates();
          }
     }

     if(!m_isMemberFunction){
          m_renderHandler(&m_window);
     }else{
          m_handlerClass->renderHandler(&m_window);
     }

     if(m_imGuiExists){
          ImGui::SFML::Update(m_window, m_deltaClock.restart());

          if(!m_imGuiIsClass){
               m_imguiHandler();
          }else{
               m_imGuiHandlerClass->imGuiHandler();
          }

          ImGui::SFML::Render(m_window);
     }

     m_window.display();

     if(m_openGLExists){
          if(m_simpleMode){
               m_window.popGLStates();
          }
     }

}
