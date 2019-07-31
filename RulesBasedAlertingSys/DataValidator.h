//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============================================================================ 

#pragma once
#include<iostream>
#include<string>
#include <Parser.h>
#include <PatientData.h>
#include <Constants.h>
#include<BufferQueue.h>

namespace alertingsystem
{
    //----------------------------------------------------------------------------
    //: Class:             DataValidator
    //: 
    //:   This class is taking parsed JSON string from Buffer.
    //:   It will perform check operation for vital signs range.
    //:
    //---------------------------------------------------------------------------- 
    class DataValidator
    {
    
    public:
        //this function checks for the validity of the data.
        void validateData();
        void ProcessPatientDataQueue();
        __declspec(dllexport) static bool checkItem(ItemType itemType, double itemValue);
    };
}

