//
// Created by braedonb98 on 7/14/20.
//

#ifndef MAINCODE_ROTORCONTROL_H
#define MAINCODE_ROTORCONTROL_H

struct Rotator {
    /*Enable or disable auto parking when wind speeds are too high
     *  0 = disabled
     *  1 = enabled with data from gndstation weather station
     *  2 = enabled with data from Weather service
     *  3 = enabled with data from both
     */
    int weatherOverride = 1;

    //Position(asmith) rotor should be set to in degrees.
    int rotorNeededAsm  = 180;

    //Position(elevation) rotor should be set to in degrees
    int rotorNeededElev = 90;

    //Position(asmith) rotor is set to based on last read in degrees
    int rotorActualAsm;

    //Position(elevation) rotor is set to based on last read in degrees
    int rotorActualElev;

    //Position(asmith) that the rotor tracking software is requesting the rotor to be set to in degrees
    int rotorTrackAsm;

    //Position(elev) that the rotor tracking software is requesting the rotor to be set to in degrees
    int rotorTrackElev;

    /*What satellite is currently active
     *  0 = No satellite currently active
    */
    int satellite;
};

class RotorControl {

};


#endif //MAINCODE_ROTORCONTROL_H
