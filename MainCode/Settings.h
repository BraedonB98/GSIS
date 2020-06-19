//
// Created by braedonb98 on 6/13/20.
//

#ifndef MAINCODE_SETTINGS_H
#define MAINCODE_SETTINGS_H

#include <iostream>

using namespace std;

struct WXTOIMGSettings{
    /* What direction is the satellite passing?
     * 0 = northbound pass
     * 1 = south bound pass
     */
    int passDirection;
    /* Which channel image would you prefer to see. Select both if you dont know.
     * 0 = Both
     * 1 = Channel A image only
     * 2 = B image only
     */
    int channelImage;
    /* Stores which enhancement will run on the wxtoimg files
     * 0 = None
     * 1 = histeq
     * 2 = MSA
     * 3 = MCIR
     * 4 = HVCT
     * 5 = sea
     * 6 = ZA
     */
    int enhancement;
    //Stores what frequency your sound card runs at. Default wxtoimg setting is 11025 and gnu radio code default is 48000
    int SCFrequency;
    /* Stores which satellite you are decoding
     * 0 = Autodetect
     * 1 = NOAA (n)
     * 2 = GOES (g)
     * 3 = Meteor2 (2)
     * 4 = Meteor3 (m)
     * 5 = Resurs (r)
     * 6 = SICH1M (h)
     * 7 = SICH(s)
     * 8 = Okean(o)
     * 9 = Meteosat(e)
     * 10 = GMS(j)
     * 11 = MTSAT(k)
     * 12 = other(x)
     */
    int satType;

};
struct SDRSettings{
    //put future SDR Settings here
};
struct trackingSettings{
    //What port the tracking software thinks a radio is on
    int vRadioPort;
    //What port the tracking software thinks a rotor is on
    int vRotorPort;
    //Contains location of host. Default to local host if the gpredict software is running on same computer as Main code(this code)
    string hostLocation = "localhost";
    //Contains location information for usb port the rotor is connected to
    string rotorLocation;
    //Contains baud rate of rotor
    int rotorBaud;

};

class Settings {
public:
    Settings();
    ~Settings();
    void printWXSettings();
    WXTOIMGSettings loadWXFileSettings();
    void saveWXFileSettings();

    //getters and setters are at the bottom of Settings.cpp
    WXTOIMGSettings getWXSetting();
    void setWXSettings(WXTOIMGSettings newSettings);
    void setWXPassDirection(int pass);
    void setWXChannelImage(int channel);
    void setWXEnhancement(int enhance);
    void setWXSCFrequency(int freq);
    void setWXSatType(int sat);
    int getWXPassDirection();
    int getWXChannelImage();
    int getWXEnhancement();
    int getWXSCFrequency();
    int getWXSatType();

private:
    WXTOIMGSettings WXSettings;
};


#endif //MAINCODE_SETTINGS_H
