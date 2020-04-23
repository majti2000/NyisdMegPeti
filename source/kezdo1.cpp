#include "kezdo1.hpp"
#include "graphics.hpp"

using namespace genv;

Kezdo1::Kezdo1(int x, int y, int sx, int sy, std::string szoveg) 
        : Widget(x,y,sx,sy), szoveg(szoveg)
{
    _checked=false;
}

void Kezdo1::draw()
{
    gout << color(133, 162, 255);
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4) << color(255,255,255)
            << move_to(_x+5, _size_y-5) << text(szoveg);
    if (_checked) {
        gout << color(255, 133, 162);
        gout << move_to(_x+100, _y+100) << color(0,0,0) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4) << color(0,0,0)
        << move_to(_x+5, _size_y-5) << text(szoveg);
    
    }

}

void Kezdo1::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
    
}


bool Kezdo1::is_checked() 
{
    return _checked;
}
