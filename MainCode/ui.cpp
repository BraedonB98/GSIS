//
// Created by Braedon Bellamy on 6/6/2020.
//

#include "ui.h"
#include <iostream>
using namespace std;
ui::ui()
{
    cout<<"creating new ui"<<endl;
}
ui::~ui()
{

}
int ui::mainMenuDisplay()
{
    cout<<"Main Menu"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1.Run Program"<<endl;
    cout<<"2.Run WXTOIMG"<<endl;
    cout<<"3.Run SDR Interface"<<endl;
    cout<<"4.Run Satellite Tracking"<<endl;
    cout<<"5.Quit Program"<<endl;
}
int ui::mainMenu()
{
    string userInput="";
    mainMenuDisplay();
    while(userInput!= "5")
    {
        getline(cin,userInput);
        if(userInput=="1"||userInput == "Run Program" || userInput == "1.Run Program")
        {
            cout<<"Running Main Program"<<endl;
            return(1);
        }
        else if(userInput=="2"||userInput == "Run WXTOIMG" || userInput == "2.Run WXTOIMG")
        {
            cout<<"Running WXTOIMG"<<endl;
            return(2);
        }
        else if(userInput=="3"||userInput == "Run SDR Interface" || userInput == "3.Run SDR Interface")
        {
            cout<<"Running SDR Interface"<<endl;
            return(3);
        }
        else if(userInput=="4"||userInput == "Run Satellite Tracking" || userInput == "4.Run Satellite Tracking")
        {
            cout<<"Running Satellite Tracking"<<endl;
            return(4);
        } else{
            cout<<"Not a vailid input. Try again"<<endl;
        }

    }
}