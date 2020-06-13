//
// Created by Braedon Bellamy on 6/6/2020.
//

#ifndef GNDSTATIONCODE_UI_H
#define GNDSTATIONCODE_UI_H

#include "Settings.h"


class ui {
private:
Settings settings;
public:
    ui();
    ~ui();
    int mainMenuDisplay();
    int mainMenu();
    int wxToImgMenu();
    int wxToImgMenuDisplay();
    int SDRMenu();
    int SDRMenuDisplay();
    int satTrackingMenu();
    int satTrackingMenuDisplay();
    int wxToImgSettingsMenuDisplay();
    int wxToImgSettingsMenu();

};


#endif //GNDSTATIONCODE_UI_H
