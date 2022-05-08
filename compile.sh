#!/bin/sh
clear
echo "\n  $(tput setaf 3)$(tput smso)Compiling CFramework with standard main function...$(tput rmso)$(tput setaf 7)\n"
if \
g++ \
-std=c++2a \
-O0 \
-Wall \
\
-o main.exe \
\
Framework/ImGui/imconfig.h \
Framework/ImGui/imgui.h \
Framework/ImGui/imgui.cpp \
Framework/ImGui/imgui_demo.cpp \
Framework/ImGui/imgui_draw.cpp \
Framework/ImGui/imgui-SFML.h \
Framework/ImGui/imgui-SFML.cpp \
Framework/ImGui/imgui_tables.cpp \
Framework/ImGui/imgui_widgets.cpp \
Framework/ImGui/imstb_rectpack.h \
Framework/ImGui/imstb_textedit.h \
Framework/ImGui/imstb_truetype.h \
\
Framework/CFramework.hpp \
Framework/CFramework.cpp \
Framework/CHandler.hpp \
Framework/CHandler.cpp \
\
Framework/Singleton.cpp \
\
Framework/include.hpp \
\
main.cpp \
\
-lsfml-audio \
-lsfml-network \
-lsfml-graphics \
-lsfml-window \
-lsfml-system \
\
-lGL \
-lpthread
then
     echo "\n  $(tput setaf 2)$(tput smso)Compiling successful!$(tput rmso)$(tput setaf 7)"
     ./main.exe
     echo "  $(tput setaf 6)$(tput smso)Execution done!$(tput rmso)$(tput setaf 7)\n"
else
     echo "\n  $(tput setaf 1)$(tput smso)Error during compilation!$(tput rmso)$(tput setaf 7)\n"
fi
