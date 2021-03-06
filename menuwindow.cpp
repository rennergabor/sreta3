#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "clickButton.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "amobaapplication.hpp"
#include "menuwindow.hpp"
#include "texteditor.hpp"

#include <vector>
#include <iostream>

using namespace std;

MenuWindow::MenuWindow(AmobaApplication &app, int x, int y) : Window (x, y), _app(app) {
    StaticText *text = new StaticText(170, 50, 100,30, "Am�ba");
    widgets.push_back(text);

    ClickButton *kilepesGomb = new ClickButton([&]() { kilepesClicked(); }, 40, 320, 100, 35);
    widgets.push_back(kilepesGomb);

    StaticText *exit = new StaticText(70, 330, 40, 20, "EXIT");
    widgets.push_back(exit);

    ClickButton *jatekGomb = new ClickButton([&]() { jatekClicked(); }, 260, 320, 100, 35);
    widgets.push_back(jatekGomb);

    StaticText *kek = new StaticText(40, 180, 100, 35, "K�k j�t�kos:");
    widgets.push_back(kek);

    TextEditor *ed = new TextEditor(40, 200, 100, 35, _app.players[0]);
    ed->addValueChangeListener([&](ValueChangedEvent event) { textEditorChanged(event); });
    widgets.push_back(ed);

    StaticText *play = new StaticText(290, 330, 40, 20, "PLAY");
    widgets.push_back(play);

    StaticText *piros = new StaticText(260, 180, 100, 35, "Piros j�t�kos:");
    widgets.push_back(piros);

    TextEditor *ed2 = new TextEditor(260, 200, 100, 35, _app.players[1]);
    ed2->addValueChangeListener([&](ValueChangedEvent event) { textEditorChanged2(event); });
    widgets.push_back(ed2);

}

void MenuWindow::textEditorChanged(ValueChangedEvent event){
    if(event.eventType == ev_type_text){
        _app.players[0]=event.newValueString;
    }
}

void MenuWindow::textEditorChanged2(ValueChangedEvent event){
    if(event.eventType == ev_type_text){
        _app.players[1]=event.newValueString;
    }
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

