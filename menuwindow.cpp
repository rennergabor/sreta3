#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "clickButton.hpp"
#include "statictext.hpp"
#include "amobaapplication.hpp"
#include "menuwindow.hpp"

#include <vector>
#include <iostream>

using namespace std;

MenuWindow::MenuWindow(AmobaApplication &app, int x, int y) : Window (x, y), _app(app) {
    StaticText *text = new StaticText(150, 30, 100,30, "Men�");
    widgets.push_back(text);

    ClickButton *kilepesGomb = new ClickButton([&]() { kilepesClicked(); }, 10, 150, 30, 30);
    widgets.push_back(kilepesGomb);

    ClickButton *jatekGomb = new ClickButton([&]() { jatekClicked(); }, 290, 150, 30, 30);
    widgets.push_back(jatekGomb);
}

void MenuWindow::kilepesClicked() {
    cout << "exit clicked!" << endl;
    exit_event_loop();
    _app.changeState(KILEPES);
}
void MenuWindow::jatekClicked() {
    cout << "play clicked!" << endl;
    exit_event_loop();
    _app.changeState(JATEK);
}
