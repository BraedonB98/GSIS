//
// Created by braedonb98 on 6/13/20.
//

#include "Settings.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>


using namespace std;
Settings::Settings() {
    WXSettings.passDirection = 0;
    WXSettings.channelImage = 0;
    WXSettings.enhancement = 0; //May want to change this later when I find an enhancement that looks nice(probably one with color)
    WXSettings.SCFrequency = 48000; //May need to change to default wxtoimg later
    WXSettings.satType = 0;
    cout<<"Loading Default Settings"<<endl;
}

Settings::~Settings() {}

void Settings::printWXSettings() {
    cout<<endl;
    cout<<"Current Settings"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"Pass Direction = ";
    if(WXSettings.passDirection == 0)
    {
        cout<<"North"<<endl;
    } else{
        cout<< "South"<<endl;
    }
    cout<<"Channel Image = ";
    if(WXSettings.channelImage == 0)
    {
        cout<<"Channel A and B"<<endl;
    }
    else if (WXSettings.channelImage == 1){
        cout<<"Only Channel A"<<endl;
    }
    else{
        cout<<"Only Channel B"<<endl;
    }

    cout<<"Enhancement = ";
    if(WXSettings.enhancement == 0){
        cout<<"None"<<endl;
    }
    else if(WXSettings.enhancement == 1){
        cout<<"Histeq"<<endl;
    }
    else if(WXSettings.enhancement == 2){
        cout<<"MSA"<<endl;
    }
    else if(WXSettings.enhancement == 3){
        cout<<"MCIR"<<endl;
    }
    else if (WXSettings.enhancement == 4){
        cout<<"HVCT"<<endl;
    }
    else if (WXSettings.enhancement == 5)
    {
        cout<<"Sea"<<endl;
    }
    else if (WXSettings.enhancement == 6)
    {
        cout<<"ZA"<<endl;
    }

    cout<<"Sound Card Frequency = "<<WXSettings.SCFrequency<<endl;

    cout<<"Satellite = ";
    if(WXSettings.satType == 0){
        cout<<"Autodetect"<<endl;
    }
    else if(WXSettings.satType == 1){
        cout<<"NOAA"<<endl;
    }
    else if(WXSettings.satType == 2){
        cout<<"GOES"<<endl;
    }
    else if(WXSettings.satType == 3){
        cout<<"Meteor 2"<<endl;
    }
    else if(WXSettings.satType == 4){
        cout<<"Meteor 3"<<endl;
    }
    else if(WXSettings.satType == 5){
        cout<<"Resurs"<<endl;
    }
    else if(WXSettings.satType == 6){
        cout<<"SICH1M"<<endl;
    }
    else if(WXSettings.satType == 7){
        cout<<"SICH"<<endl;
    }
    else if(WXSettings.satType == 8){
        cout<<"Okean"<<endl;
    }
    else if(WXSettings.satType == 9){
        cout<<"Meteosat"<<endl;
    }
    else if(WXSettings.satType == 10){
        cout<<"GMS"<<endl;
    }
    else if(WXSettings.satType == 11){
        cout<<"MTSAT"<<endl;
    }
    else if(WXSettings.satType == 12){
        cout<<"Other"<<endl;
    }
}

WXTOIMGSettings Settings::loadWXFileSettings() {
    ifstream inFile;
    inFile.open("WXTOIMGSettings.txt");
    string data = "";
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (getline(inFile, data)) {
        if (data == "Pass Direction")
        {
            inFile >> WXSettings.passDirection;
        }
        if (data == "Channel Image")
        {
            inFile >> WXSettings.channelImage;
        }
        if (data == "Enhancement")
        {
            inFile >> WXSettings.enhancement;
        }
        if (data == "SoundCard Frequency")
        {
            inFile >> WXSettings.SCFrequency;
        }
        if (data == "Satellite")
        {
            inFile >> WXSettings.satType;
        }
    }

    inFile.close();
}
void Settings::saveWXFileSettings() {
    ofstream WXSettingFile;
    WXSettingFile.open ("WXTOIMGSettings.txt");
    WXSettingFile << "Pass Direction\n"<< (int)WXSettings.passDirection<<endl;
    WXSettingFile << "Channel Image\n"<< (int)WXSettings.channelImage<<endl;
    WXSettingFile << "Enhancement\n"<< (int)WXSettings.enhancement<<endl;
    WXSettingFile << "SoundCard Frequency\n"<< WXSettings.SCFrequency<<endl;
    WXSettingFile << "Satellite\n"<< (int)WXSettings.satType<<endl;
    WXSettingFile.close();
}

//All Getters and Setters Bellow.
WXTOIMGSettings Settings::getWXSetting() {
    return (WXSettings);
}
void Settings::setWXSettings(WXTOIMGSettings newSettings) {
    WXSettings.passDirection = newSettings.passDirection;
    WXSettings.channelImage = newSettings.channelImage;
    WXSettings.enhancement = newSettings.enhancement;
    WXSettings.SCFrequency = newSettings.SCFrequency;
    WXSettings.satType = newSettings.satType;
}
void Settings::setWXPassDirection(int pass){
    if(pass == 0|| pass == 1){
        WXSettings.passDirection = pass;
        return;
    }
    cout<<"Not valid pass direction "<<endl;
}
void Settings::setWXChannelImage(int channel){
    if(channel == 0 ||channel == 1||channel == 2) {
        WXSettings.channelImage = channel;
        return;
    }
    cout<<"Not valid channel image"<<endl;


}
void Settings::setWXEnhancement(int enhance){
    if(enhance >= 0 && enhance <= 6)
    {
        WXSettings.enhancement = enhance;
        return;
    }
    cout<<"Not valid enhancement"<<endl;
}
void Settings::setWXSCFrequency(int freq){
    WXSettings.SCFrequency = freq;
}
void Settings::setWXSatType(int sat){
    if(sat>=0  && sat <= '12') {
        WXSettings.satType = sat;
        return;
    }
    cout<<"Not a valid satellite"<<endl;
}
int Settings::getWXPassDirection(){
    return(WXSettings.passDirection);
}
int Settings::getWXChannelImage(){
    return(WXSettings.channelImage);
}
int Settings::getWXEnhancement(){
    return(WXSettings.enhancement);
}
int Settings::getWXSCFrequency(){
    return(WXSettings.SCFrequency);
}
int Settings::getWXSatType(){
    return(WXSettings.satType);
}
