#include "graphics.hpp"
#include "widgets.hpp"
#include "kezdo1.hpp"
#include "szambeallito.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
using namespace genv;

enum statusz{
    elso=0, 
    dolog=6,
    szulinap_e=1,
    szekszipeter=2,
    petifeje=3,
    szeret_e=4, 
    otodik=5,
    hb=7
};

statusz stat=elso;

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    bool katte=false;
    while(gin >> ev && stat==elso) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[0]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                        stat=szulinap_e;
                        break;
                }
                if (widgets[1]->is_selected(ev.pos_x, ev.pos_y)){
                    focus = i;
                    gout << move_to(0,0) << color(0,0,0) << box(400,400) << refresh;
                    stat=dolog;
                    break;
                }
            }
            break;
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
 
    }
}
void read_img(ifstream& f, canvas& c, int width, int height)
{
    f >> width >> ws;
    f >> height >> ws;
    c.open(width, height);

    int x, y, r, g, b;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            f >> r >> ws;
            f >> g >> ws;
            f >> b >> ws;

            c << move_to(x, y)<< color(r, g, b)<< dot;
        }
    }
}


int main()
{
    ifstream f("0.kep");
    ifstream f1("1.kep");
    ifstream f2("2.kep");
    ifstream f3("3.kep");
    ifstream f4("4.kep");
    ifstream f5("szekszipeterek.kep");
    ifstream f6("sz.kep");

    canvas c;
    canvas c1;
    canvas c2;
    canvas c3;
    canvas c4;
    canvas c5;
    canvas c6;

    read_img(f, c, 200, 150);
    read_img(f1, c1, 100, 79);
    read_img(f2, c2, 150, 112);
    read_img(f3, c3, 100, 177);
    read_img(f4, c4, 100, 188);
    read_img(f5, c5, 360, 357);
    read_img(f6, c6, 390, 396);
   
    gout.open(400,400);
    vector<Widget*> w;
    if (stat==elso){ 
    Kezdo1 * k1= new Kezdo1(10, 10, 100, 40, "Meheeeet!");
    Kezdo1 * k2= new Kezdo1(200, 10, 170, 40, "Ma este Dolgom van.");
    w.push_back(k1);
    w.push_back(k2);
    for (Widget * wg : w) {
        wg->draw();
    }
    gout << move_to(70,150) << color(255,255,255) << text("Na, Peti, raersz egy kis progra?");
    gout << refresh;
    event_loop(w);
    }
    event ev1;
    while (gin >> ev1){
    if (stat==dolog){
        gout << move_to(0,0) << color(0,0,0) << box(400,400);
        gout << stamp(c6, 5, 2) << refresh;
    }
    if (stat==szulinap_e){
        gout << move_to(0,0) << color(0,0,0) << box(400,400);
        gout << move_to(15,100) << color (179, 0, 90) << text("Ha ma van a szulinapod, nyomd meg ezt a szamot:") 
       << move_to(50,200) <<  text("(3x^2)'+(x-3)^2-((x^4)/12)''-sqrt(81)") << refresh;
        if (ev1.type==ev_key && ev1.keycode==48)
        {
            stat=szekszipeter;
        }
    }
    if(stat==szekszipeter){
        gout << move_to(0,0) << color(0,0,0) << box(400,400) << refresh;
        gout << move_to(135, 100) << color(108, 255, 220) << text("Mi a valodi neved?")
            << move_to(20, 150) << color(255, 147, 108 ) <<text("a) plungingChode") <<color(255, 221, 108) << move_to(270, 150) << text("b) szeksziPeter")  
            << move_to(60, 250) <<color(108, 255, 220)<< text("Nyomd meg a helyes valasz betujelet!") << refresh;
            if (ev1.type==ev_key && ev1.keycode==97 || ev1.keycode==98)
            {
                stat=petifeje;
            }
    }
    if (stat==petifeje){
        gout << move_to(0,0) << color(0,0,0) << box(400,400)
            << move_to(10,20) << color(108, 255, 147) << text("Nyomd meg az igazi ened szamat! 1), 2) vagy 3)");
        gout << stamp(c5, 22, 33);
        gout << refresh;
         if (ev1.type==ev_key && ev1.keycode==49 || ev1.keycode==50 || ev1.keycode==51)
            {
                stat=szeret_e;
            }
       
    }
    if (stat==szeret_e){
        gout << move_to(0,0) << color(0,0,0) << box(400,400);
        gout << move_to(20,150) << color(255, 108, 143) << text("Ha szereted Klaut es Ritat, nyomd meg az 'a'-t!") <<refresh;
        if (ev1.type==ev_key && ev1.keycode==97)
        {
            stat=otodik;
        }
    }
    if (stat==otodik){
        gout << move_to(0,0) << color(0,0,0) << box(400,400);
                gout << stamp(c, 100, 15);
                gout << stamp(c1, 150, 176);
                gout << stamp(c2, 125, 270);
                gout << stamp(c3, 20, 200);
                gout << stamp(c4, 280, 195);
                gout << refresh;
                if (ev1.type==ev_key && ev1.keycode==key_space)
                {
                    stat=hb;
                }
    }
    if(stat==hb)
    {
        gout << move_to(0,0) << color(0,0,0) << box(400,400) << color(0,191,255)
            <<move_to(135,120) << text("01001000 01100001")
            <<move_to(135,145) << text("01110000 01110000")
            <<move_to(135,170) <<  text("01111001 00100000")
            <<move_to(135,195) <<  text("01000010 01101001")
            <<move_to(135,220) <<  text("01110010 01110100")
            <<move_to(135,245) <<  text("01101000 01100100")
            <<move_to(135,270) <<  text("01100001 01111001")
            << refresh;
        
    }
    
    }
    return 0;
}
