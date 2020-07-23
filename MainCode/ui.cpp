//
// Created by Braedon Bellamy on 6/6/2020.
//

#include "ui.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "Settings.h"
#include <sstream>



using namespace std;
ui::ui()
{
    cout<<"Launching Program"<<endl;
    settings.loadWXFileSettings();
}
ui::~ui()
{

}
int ui::mainMenuDisplay()
{
    cout<<endl;
    cout<<"Main Menu"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1.Run Program"<<endl;
    cout<<"2.WXTOIMG Settings"<<endl;
    cout<<"3.SDR Interface Settings"<<endl;
    cout<<"4.Satellite Tracking Settings"<<endl;
    cout<<"5.Quit Program"<<endl;

}
int ui::mainMenu()
{
    string userInput="";
    while(userInput!= "5")
    {
        mainMenuDisplay();
        getline(cin,userInput);
        if(userInput=="1"||userInput == "Run Program" || userInput == "1.Run Program")
        {
            cout<<"Running Main Program"<<endl;
            system("gpredict &");//Launch Gpredict
            system("cd \n cd /home/braedonb98/GSIS/GNURadioCode \n python ./GSISFMTEST.py & ");//launch sdr code
            system("xwxtoimg");//remove from code when I finish code for switching satellites

        }
        else if(userInput=="2"||userInput == "Run WXTOIMG" || userInput == "2.Run WXTOIMG")
        {
            wxToImgMenu();
        }
        else if(userInput=="3"||userInput == "Run SDR Interface" || userInput == "3.Run SDR Interface")
        {
            SDRMenu();
        }
        else if(userInput=="4"||userInput == "Run Satellite Tracking" || userInput == "4.Run Satellite Tracking")
        {
            cout<<"Running Satellite Tracking"<<endl;
            satTrackingMenu();
            //launch and run predict program here
            //use the port for radio to get info about when to start tracking satellite with sdr.
            //find a way to get data from port on local computer in c++
        }
        else if(userInput=="5"||userInput == "Quit" || userInput == "5.Quit Program")
        {
            cout<<"Shutting Down Program"<<endl;
            return(1);
        }
        else{
            cout<<"Not a valid input. Try again"<<endl;
        }

    }
}

int ui::wxToImgMenuDisplay()
{
    cout<<endl;
    cout<<"WXTOIMG Menu"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1.Run WXTOIMG Decode"<<endl;
    cout<<"2.Edit WXTOIMG Settings"<<endl;
    cout<<"3.Save WXTOIMG Settings"<<endl;
    cout<<"4.Load WXTOIMG Settings"<<endl;
    cout<<"5.Display Current Settings"<<endl;
    cout<<"6.Return To Main Menu"<<endl;
}

int ui::wxToImgMenu()
{
    string userInput="";

    while(userInput!= "6")
    {
        wxToImgMenuDisplay();
        getline(cin,userInput);
        if(userInput=="1"||userInput == "Run WXTOIMG Decode" || userInput == "1.Run WXTOIMG Decode")
        {
            char command[200] = "";// allows for file names up to 55 char long
            cout<<"Running WXTOIMG"<<endl;
            cout<<"Enter Input File Name"<<endl;
            getline(cin,userInput);
            string inputFile = userInput;
            cout<<"Enter Output File Name"<<endl;
            getline(cin,userInput);
            string outputFile = userInput;
            string terminalCmd = settings.getWXTOIMGTerminalString(inputFile,outputFile);
            int n = terminalCmd.length();
            char tC[n + 1];
            strcpy(tC, terminalCmd.c_str());
            sprintf(command, "%s" ,tC);// 88 char size before file name added
            cout<<command<<endl;
            system(command);
        }
        else if(userInput=="2"||userInput == "Edit WWXTOIMG Settings" || userInput == "2.Edit WXTOIMG Settings")
        {
            cout<<"Change Settings Here"<<endl;
            settings.printWXSettings();
            wxToImgSettingsMenu();
        }
        else if(userInput=="3"||userInput == "Save WXTOIMG Settings" || userInput == "3.Save WXTOIMG Settings")
        {
            cout<<"Saving WXTOIMG Settings"<<endl;
            settings.saveWXFileSettings();
            //write settings to file
        }
        else if(userInput=="4"||userInput == "Load WXTOIMG Settings" || userInput == "4.Load WXTOIMG Settings")
        {
            cout<<"Loading WXTOIMG Settings"<<endl;
            settings.loadWXFileSettings();
            //load settings from file
        }
        else if(userInput=="5"||userInput == "Display Current Settings" || userInput == "5.Display Current Settings")
        {
            settings.printWXSettings();
        }
        else if(userInput=="6"||userInput == "Return To Main Menu" || userInput == "6.Return To Main Menu")
        {
            cout<<"Returning To Main Menu"<<endl;
            break;
        }
        else{
            cout<<"Not a valid input. Try again"<<endl;
        }

    }
}
int ui::SDRMenuDisplay()
{
    cout<<endl;
    cout<<"SDR Menu"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1.Run SDR FM Test"<<endl;
    cout<<"2.Run SDR Satellite Test"<<endl;
    cout<<"3.Edit SDR Settings"<<endl;
    cout<<"4.Save SDR Settings"<<endl;
    cout<<"5.Load SDR Settings"<<endl;
    cout<<"6.Return To Main Menu"<<endl;
}
int ui::SDRMenu()
{
    string userInput="";
    while(userInput!= "6")
    {
        SDRMenuDisplay();
        getline(cin,userInput);
        if(userInput=="1"||userInput == "Run SDR FM Test" || userInput == "1.Run SDR FM Test")
        {
            cout << "Running SDR Test, A new window should pop up with FM Test" << endl;
            system("cd \n cd /home/braedonb98/GSIS/GNURadioCode \n python ./GSISFMTEST.py &");
        }
        else if(userInput=="2"||userInput == "Run SDR Satellite Test" || userInput == "2.Run SDR Satellite Test")
        {
            cout<<"Running SDR Test, A new window should pop up with Sat Test"<<endl;
            system("cd \n cd /home/braedonb98/GSIS/GNURadioCode \n python ./GSISSatTest.py &");
        }
        else if(userInput=="3"||userInput == "Edit SDR Settings" || userInput == "3.Edit SDR Settings")
        {
            cout<<"SDR Settings"<<endl;
        }
        else if(userInput=="4"||userInput == "Save SDR Settings" || userInput == "4.Save SDR Settings")
        {
            cout<<"Saving SDR Settings"<<endl;
        }
        else if(userInput=="5"||userInput == "Load SDR Settings" || userInput == "5.Load SDR Settings")
        {
            cout<<"Loading SDR Settings"<<endl;
        }
        else if(userInput=="6"||userInput == "Return To Main Menu" || userInput == "6.Return To Main Menu") {
            cout << "Returning To Main Menu" << endl;
            break;
        }
        else{
            cout<<"Not a valid input. Try again"<<endl;
        }
    }
}

int ui::satTrackingMenuDisplay()
{
    cout<<endl;
    cout<<"Tracking Software Menu"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1.Run GPredict"<<endl;
    cout<<"2.Edit SatTracking Settings"<<endl;
    cout<<"3.Save SatTracking Settings"<<endl;
    cout<<"4.Load SatTracking Settings"<<endl;
    cout<<"5.Return To Main Menu"<<endl;
}
int ui::satTrackingMenu()
{
    string userInput="";
    while(userInput!= "5")
    {
        satTrackingMenuDisplay();
        getline(cin,userInput);
        if(userInput=="1"||userInput == "Run SDR FM Test" || userInput == "1.Run SDR FM Test")
        {
            cout << "Launching Gpredict" << endl;
            system("gpredict &");
        }
        else if(userInput=="2"||userInput == "Edit SatTracking Settings" || userInput == "2.Edit SatTracking Settings")
        {
            cout<<"SatTracking Settings"<<endl;
        }
        else if(userInput=="3"||userInput == "Save SatTracking Settings" || userInput == "3.Save SatTracking Settings")
        {
            cout<<"Saving SatTracking Settings"<<endl;
        }
        else if(userInput=="4"||userInput == "Load SatTracking Settings" || userInput == "4.Load SatTracking Settings")
        {
            cout<<"Loading SDR Settings"<<endl;
        }
        else if(userInput=="5"||userInput == "Return To Main Menu" || userInput == "5.Return To Main Menu") {
            cout << "Returning To Main Menu" << endl;
            break;
        }
        else{
            cout<<"Not a valid input. Try again"<<endl;
        }
    }
}

int ui::wxToImgSettingsMenuDisplay()
{
    cout<<endl;
    cout<<"WXTOIMG Menu"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1.Edit Pass Direction"<<endl;
    cout<<"2.Edit Channel Image"<<endl;
    cout<<"3.Edit Enhancement"<<endl;
    cout<<"4.Edit SoundCard Frequency"<<endl;
    cout<<"5.Edit Satellite"<<endl;
    cout<<"6.Return To WXTOIMG Menu"<<endl;
}

int ui::wxToImgSettingsMenu()
{
    string userInput="";

    while(userInput!= "6")
    {
        wxToImgSettingsMenuDisplay();
        getline(cin,userInput);
        if(userInput=="1"|| userInput == "Edit Pass Direction" || userInput == "1.Edit Pass Direction")
        {
            cout<<"Editing Pass Direction"<<endl;
            cout<<"     * 0 = northbound pass\n"
                  "     * 1 = south bound pass"<<endl;
            getline(cin,userInput);
            stringstream ss(userInput);
            int x;
            ss>>x;
            settings.setWXPassDirection(x);
        }
        else if(userInput=="2"||userInput == "Edit Channel Image" || userInput == "2.Edit Channel Image")
        {
            cout<<"Editing Channel Image"<<endl;
            cout<<"     * 0 = Both\n"
                  "     * 1 = Channel A image only\n"
                  "     * 2 = B image only"<<endl;
            getline(cin,userInput);
            stringstream ss(userInput);
            int x;
            ss>>x;
            settings.setWXChannelImage(x);
        }
        else if(userInput=="3"||userInput == "Edit Enhancement" || userInput == "3.Edit Enhancement")
        {
            cout<<"Editing Enhancement"<<endl;
            cout<<"     * 0 = None\n"
                  "     * 1 = histeq\n"
                  "     * 2 = MSA\n"
                  "     * 3 = MCIR\n"
                  "     * 4 = HVCT\n"
                  "     * 5 = sea\n"
                  "     * 6 = ZA"<<endl;
            getline(cin,userInput);
            stringstream ss(userInput);
            int x;
            ss>>x;
            settings.setWXEnhancement(x);
        }
        else if(userInput=="4"||userInput == "Edit SoundCard Frequency" || userInput == "4.Edit SoundCard Frequency")
        {
            cout<<"Editing SoundCard Frequency"<<endl;
            cout<<"Type in Frequency in Hz"<<endl;
            getline(cin,userInput);
            stringstream ss(userInput);
            int x;
            ss>>x;
            settings.setWXSCFrequency(x);
        }
        else if(userInput=="5"||userInput == "Edit Satellite" || userInput == "5.Edit Satellite")
        {
            cout<<"Editing Satellite"<<endl;
            cout<<"     * 0 = Autodetect\n"
                  "     * 1 = NOAA (n)\n"
                  "     * 2 = GOES (g)\n"
                  "     * 3 = Meteor2 (2)\n"
                  "     * 4 = Meteor3 (m)\n"
                  "     * 5 = Resurs (r)\n"
                  "     * 6 = SICH1M (h)\n"
                  "     * 7 = SICH(s)\n"
                  "     * 8 = Okean(o)\n"
                  "     * 9 = Meteosat(e)\n"
                  "     * 10 = GMS(j)\n"
                  "     * 11 = MTSAT(k)\n"
                  "     * 12 = other(x)"<<endl;
            getline(cin,userInput);
            stringstream ss(userInput);
            int x;
            ss>>x;
            settings.setWXSatType(x);
        }

        else if(userInput=="6"||userInput == "Return To WXTOIMG Menu" || userInput == "6.Return To WXTOIMG Menu")
        {
            cout << "Returning To WXTOIMG Menu" << endl;
            break;
        }
        else{
            cout<<"Not a valid input. Try again"<<endl;
        }

    }
}