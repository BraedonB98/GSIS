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
    WXSettings.SCFrequency = 11025; //May need to change to default wxtoimg later
    WXSettings.satType = 0;
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
string Settings::getWXTOIMGTerminalString(string inputFile, string outputFile){
    string runCmd;
    runCmd = "cd \n cd GSIS/WAVFilesFromGNURadio \n wxtoimg ";

    //pass direction

    if(WXSettings.passDirection == 0){//north bound pass
        runCmd = runCmd + "-N ";
    }
    else{//south bound pass
        runCmd = runCmd + "-S ";
    }

    //channel image

    if(WXSettings.channelImage == 0){//both
        //dont change runcmd value so it runs both;
    }
    else if (WXSettings.channelImage == 1){//channel a only
        runCmd = runCmd + "-a ";
    }
    else{//channel b only
        runCmd = runCmd + "-b ";
    }

    //enhancement
    if(WXSettings.enhancement == 0){
        //no enhancement
    }
    else if(WXSettings.enhancement == 1){
        runCmd = runCmd + "-e histeq ";
    }
    else if(WXSettings.enhancement == 2){
        runCmd = runCmd + "-e MSA ";
    }
    else if(WXSettings.enhancement == 3){
        runCmd = runCmd + "-e MCIR ";
    }
    else if(WXSettings.enhancement == 4){
        runCmd = runCmd + "-e HVCT ";
    }
    else if(WXSettings.enhancement == 5){
        runCmd = runCmd + "-e sea ";
    }
    else if(WXSettings.enhancement == 6){
        runCmd = runCmd + "-e ZA ";
    }

    //sound card frequency

    stringstream ss;
    ss << WXSettings.SCFrequency;
    runCmd = runCmd + "-f " + ss.str();

    if (WXSettings.satType == 0)
    {
        //do nothing for autodetect
    }
    else if (WXSettings.satType == 1)//if NOAA
    {
        runCmd = runCmd + "-t n ";
    }else if (WXSettings.satType == 2)//if GOES
    {
        runCmd = runCmd + "-t g ";
    }
    else if (WXSettings.satType == 3)//if Meteor2
    {
        runCmd = runCmd + "-t 2 ";
    }
    else if (WXSettings.satType == 4)//if Meteor3
    {
        runCmd = runCmd + "-t m ";
    }
    else if (WXSettings.satType == 5)//if Resurs
    {
        runCmd = runCmd + "-t r ";
    }
    else if (WXSettings.satType == 6)//if SICH1M
    {
        runCmd = runCmd + "-t h ";
    }
    else if (WXSettings.satType == 7)//if Sick
    {
        runCmd = runCmd + "-t s ";
    }
    else if (WXSettings.satType == 8)//if Okean
    {
        runCmd = runCmd + "-t o ";
    }
    else if (WXSettings.satType == 9)//if Meteosat
    {
        runCmd = runCmd + "-t e ";
    }
    else if (WXSettings.satType == 10)//if GMS
    {
        runCmd = runCmd + "-t j ";
    }
    else if (WXSettings.satType == 11)//if MTSAT
    {
        runCmd = runCmd + "-t k ";
    }
    else if (WXSettings.satType == 12)//if other
    {
        runCmd = runCmd + "-t x ";
    }


    runCmd = runCmd + " " + inputFile +".wav " + outputFile +  ".png";
    cout<<runCmd<<endl;
    return(runCmd);
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
