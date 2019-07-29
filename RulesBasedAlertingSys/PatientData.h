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
using namespace std;

namespace alertingsystem
{
    //class PatientData has patient_id, SP02, pulse rate, temperature and it initializes the member variables.
    class PatientData {
    public:
        //declaring the member variables of the class PatientData.
        string m_patientId;
        double m_SPO2;
        double m_pulseRate;
        double m_temperature;

        // default constructor of class PatientData
        PatientData() {};

        //parameterized constructor of PatientData class to initialize the member variables.
        PatientData(string patientId, double SPO2, double pulseRate, double temperature)
        {
            m_patientId = patientId;
            m_SPO2 = SPO2;
            m_pulseRate = pulseRate;
            m_temperature = temperature;
        }

    };

    //Buffer class to store the parsed data. 
    class Buffer
    {
    public:
        //default constructor of Buffer class
        Buffer() {};
        //creating the object of PatientData class.
        PatientData m_patientData;
    };

}
