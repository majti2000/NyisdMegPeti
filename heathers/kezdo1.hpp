#ifndef KEZDO1_HPP_INCLUDED
#define KEZDO1_HPP_INCLUDE

#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;


#include <string>

class Kezdo1:public Widget{
protected: 
    bool _checked;
    std::string szoveg;
public: 
    Kezdo1(int x, int y, int sx, int sy, std :: string szoveg);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual bool is_checked() ;
};

#endif