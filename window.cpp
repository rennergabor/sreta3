#include "window.hpp"
using namespace genv;

void Window::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev ) {

        if (ev.type == ev_key && ev.keycode == key_f12) {
            saveToFile();
            continue;
        }

        if (ev.type == ev_key && ev.keycode == key_tab) {
            if(focus!=-1) {
                widgets[focus]->unfocus();
            }
            do {
                focus++;
                if (focus>=widgets.size()) focus =0;
            } while (!widgets[focus]->focusable()); //TODO:vegtelenciklus!
            widgets[focus]->focus();
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            if(focus!=-1 && widgets[focus]->is_selected(ev.pos_x, ev.pos_y)){
                // ne valts fokuszt, ha a fokuszban levore kattint
            }
            else {
                for (size_t i=0;i<widgets.size();i++) {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && widgets[i]->focusable()) {
                            if (focus!=-1) widgets[focus]->unfocus();
                            focus = i;
                            widgets[focus]->focus();
                    }
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }

        // kirajzolas
        torles();
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        // fokuszban levot rajzoljuk legfelulre!
        if (focus!=-1) {
            widgets[focus]->draw();
        }
        gout << refresh;
    }
}

Window::Window(int sx, int sy){
    _sx = sx;
    _sy = sy;
    gout.open(_sx, _sy);
}

void Window::torles(){
    gout << move_to(0, 0) << color(0,0,0) << box(_sx, _sy);
}

void Window::saveToFile(){
}
