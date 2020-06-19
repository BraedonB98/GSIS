//
// Created by braedonb98 on 6/15/20.
//

#include <iostream>
#include "ui.h"
#include "satData.h"


using namespace std;
int main() {
    cout << "Running SatTest Code"<<endl;
    satData satCom;
    satCom.connectGPred(1000);
    //ui display;
    //display.mainMenu();
    cout << "Program Complete" << std::endl;
    return 0;
}
