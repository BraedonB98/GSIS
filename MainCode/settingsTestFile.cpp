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
    cout<<"Testing printWXSettings()"<<endl;
    TestSettings.printWXSettings();
    cout << "Tests Complete" << endl;
    return 0;
}
