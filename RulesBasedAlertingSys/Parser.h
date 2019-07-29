//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============================================================================ 

#pragma once
#include<iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <PatientData.h>

namespace alertingsystem
{
    //this class has 2 static functions called splitinfo() which splits the json string
   //and parseJsonData function parses the json string. 

   //----------------------------------------------------------------------------
   //: Class:             Parser
   //: 
   //:   This class has a JSONparser function it will parsed the JSON string
   //:
   //---------------------------------------------------------------------------- 
    class Parser {
    private:
        //splitinfo() function splits the json string
        static void splitInfo();
    public:
        //parseJsonData function parses the json string.
        __declspec(dllexport) static PatientData parseJsonData(string strJsonData);
    };
}


