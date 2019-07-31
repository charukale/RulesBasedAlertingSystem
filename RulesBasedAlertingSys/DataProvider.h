//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============================================================================ 

#pragma once
#include<iostream>
#include <list> 
#include <string>
#include <PatientData.h>
#include <iostream> 
#include <iterator> 
#include <string>
#include <chrono>
#include <thread>
#include <list>
#include <Parser.h>
#include <ConsoleColor.h>
#include <Constants.h>
#include <BufferQueue.h>


using namespace std;

namespace alertingsystem
{
//----------------------------------------------------------------------------
//: Class:             DataProvider
//: 
//:   This class is generating dynamic JSON formatted string.
//:   It will print the generated JSON string on the console.
//:   It pushes the parsed JSON string to Buffer.
//:
//---------------------------------------------------------------------------- 
    class DataProvider {
    private:

        int m_idCounter = 0;
        int m_patientId = 0;

        //calling the generateData() funcion to generate the data
        string generateData();

    public:
        //constructor to initialize the member variable m_buffer.
        
        //calling printData to print the json string on the console.
        __declspec(dllexport) void printData(string strData);
        //calling startOperation() to start the application.
        __declspec(dllexport) void startOperation();
    };

}
