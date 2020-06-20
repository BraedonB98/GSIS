//
// Created by braedonb98 on 6/13/20.
//

#include <iostream>
#include "ui.h"
#include "Settings.h"


using namespace std;
int main() {
    cout << "Testing Settings" <<endl;
    Settings TestSettings;
    cout<<"Testing Saving Settings"<<endl;
    TestSettings.loadWXFileSettings();
    TestSettings.saveWXFileSettings();
    TestSettings.setWXSCFrequency(11025);
    cout<<"Testing printWXSettings()"<<endl<<endl;
    TestSettings.printWXSettings();
    cout<<"Testing Terminal Command"<<endl;
    TestSettings.getWXTOIMGTerminalString("0907291428noaa-18","test");
    cout << "Tests Complete" << endl;
    return 0;
}
