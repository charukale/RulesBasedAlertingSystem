//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============================================================================ 

#pragma once

//this header file contains all the constant member variables which are being declared and initialized.
namespace alertingsystem
{
    const char COMMA_DELIMETER = ',';
    const char COLON_DELIMETER = ':';
    const double MIN_TEMPERATURE = 97;
    const double MAX_TEMPERATURE = 99;
    const double MIN_PULSE_RATE = 60;
    const double MAX_PULSE_RATE = 100;
    const double MIN_SPO2 = 95;
    const double MAX_SPO2 = 100;
    const int INTERVAL = 10;
   

    //this function randomly generates patient's information in json format.
    static double randomizeDouble(double nMin, double nMax)
    {
        //return nMin + (double)((double)rand() / (RAND_MAX + 1) * (nMax - nMin + 1));
        double range = (nMax - nMin) + 1;
        return (int)(nMin + double(range*rand() / (RAND_MAX + 1.0)));
    }

    // Type of data
    enum ItemType
    {
        SPO2,
        PulseRate,
        Temperature
    };
}


