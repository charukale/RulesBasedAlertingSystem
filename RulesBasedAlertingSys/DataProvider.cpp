//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============================================================================ 

#pragma once

#include <DataProvider.h>
#include <RBASSemaphore.h>
#include <mutex>
#include <SemaphoreRBAS.h>
#include <pthread.h>
using namespace std;

using namespace pthreadMutex;

namespace alertingsystem
{

    //this function will generate the json data using randomizeDouble() function for patient id, sp02,pulserate,temperature.
    string DataProvider::generateData()
    {

        if (m_idCounter == 0)
        {
            m_patientId = (int)randomizeDouble(1111, 9999);
        }
        m_idCounter += 1;

        if (m_idCounter == 10)
        {
            m_idCounter = 0;
        }

        double spo2 = randomizeDouble(MIN_SPO2 -1, MAX_SPO2);
        double pulseRate = randomizeDouble(MIN_PULSE_RATE -1, MAX_PULSE_RATE);
        double temperature = randomizeDouble(MIN_TEMPERATURE, MAX_TEMPERATURE);

        return
            "{patient id: Patient_" + std::to_string(m_patientId) + ", SPO2 :" + std::to_string(spo2) +
            ", pulse rate : " + std::to_string(pulseRate) +
            ", temperature : " + std::to_string(temperature) + " }";
    }

    //this function has timer which calls printData() and pushDataToBuffer() every 10 seconds.
    void DataProvider::startOperation()
    {
        std::chrono::seconds interval(INTERVAL); // 10 seconds
        while (true)
        {
            pthread_mutex_lock(&SemaphoreRBAS::getMutex());

            string jsonData = generateData();
            printData(jsonData);


            PatientData patientData = Parser::parseJsonData(jsonData);
            pushDataToBuffer(patientData);

            pthread_mutex_unlock(&SemaphoreRBAS::getMutex());

            std::this_thread::sleep_for(interval);
        }
    }

    //prints the data on the console every 10 seconds.
    void DataProvider::printData(string strData)
    {
        cout << yellow << (strData);
        cout << '\n';
        Beep(1000, 500);
    }

    //this function pushes the data to the buffer.
    void DataProvider::pushDataToBuffer(PatientData patientData)
    {
        m_buffer->m_patientData.m_patientId = patientData.m_patientId;
        m_buffer->m_patientData.m_SPO2 = patientData.m_SPO2;
        m_buffer->m_patientData.m_pulseRate = patientData.m_pulseRate;
        m_buffer->m_patientData.m_temperature = patientData.m_temperature;
    }
}