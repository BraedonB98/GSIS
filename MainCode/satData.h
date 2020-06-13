//
// Created by braedonb98 on 6/11/20.
//

#ifndef MAINCODE_SATDATA_H
#define MAINCODE_SATDATA_H
#include <iostream>

using namespace std;

class satData {
public:
    satData();
    ~satData();
    int connectGPred(int port);


private:
    bool portOpen(string &address , int port);



};


#endif //MAINCODE_SATDATA_H
