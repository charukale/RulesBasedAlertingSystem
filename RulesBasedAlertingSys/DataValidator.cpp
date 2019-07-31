//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============

#pragma once

#include <DataValidator.h>
#include <ConsoleColor.h>
#include <mutex>
#include <SemaphoreRBAS.h>
#include <pthread.h>


using namespace std;
using namespace bufferqueue;

namespace alertingsystem
{

    void DataValidator::ProcessPatientDataQueue()
    {
        PatientData patientData = BufferQueue::patientDataQueue.front();

        string id = patientData.m_patientId;
        //normal range spo2 = 95 - 100;
        double spo2 = patientData.m_SPO2;
        //normal range temp 97 - 99
        double temperature = patientData.m_temperature;
        //normal range PR 60 - 100
        double pulseRate = patientData.m_pulseRate;

        bool isSPO2InRange = checkItem(ItemType::SPO2, spo2);
        bool isTemperatureInRange = checkItem(ItemType::Temperature, temperature);
        bool isPulseRateInRange = checkItem(ItemType::PulseRate, pulseRate);

        if (!isSPO2InRange)
        {
            cout << red << "Alert!!! SPO2 not in range. SPO2:" << spo2 << " for patient " << blue << id;
            cout << endl;
        }
        if (!isTemperatureInRange)
        {
            cout << red << "Alert!!! Temparature not in range. Temparature:" << temperature << " for patient " << blue << id;
            cout << endl;
        }
        if (!isPulseRateInRange)
        {
            cout << red << "Alert!!! Pulse Rate not in range. Pulse Rate:" << pulseRate << " for patient " << blue << id;
            cout << endl;
        }

        if (!isSPO2InRange || !isTemperatureInRange || !isPulseRateInRange)
        {
            cout << red << "Emergency situation, alerting nurse!!!";// In Red
            cout << endl;
            Beep(2000, 2000);
        }

        BufferQueue::patientDataQueue.pop();
    }
    // Function to validate the data present in buffer
    // If data is out of range then alert the nurse.
    void DataValidator::validateData()
    {

        std::chrono::seconds interval(INTERVAL); // 10 seconds
        while (true)
        {
            pthread_mutex_lock(&SemaphoreRBAS::getMutex());

            if (!BufferQueue::patientDataQueue.empty())
            {
                ProcessPatientDataQueue();
            }
            pthread_mutex_unlock(&SemaphoreRBAS::getMutex());
            std::this_thread::sleep_for(interval);
        }
    }

    // Check the value for the data type.
    // If value is in raneg, return true else false.
    bool DataValidator::checkItem(ItemType itemType, double itemValue)
    {
        bool isInRange = false;

        switch (itemType)
        {
        case ItemType::SPO2:
        {
            if (itemValue >= MIN_SPO2 && itemValue <= MAX_SPO2)
            {
                isInRange = true;
            }
        }
        break;
        case ItemType::PulseRate:
        {
            if (itemValue >= MIN_PULSE_RATE && itemValue <= MAX_PULSE_RATE)
            {
                isInRange = true;
            }
        }
        break;
        case ItemType::Temperature:
        {
            if (itemValue >= MIN_TEMPERATURE && itemValue <= MAX_TEMPERATURE)
            {
                isInRange = true;
            }
        }
        break;
        default:
            break; {
            }
        }

        return isInRange;
    }
}
