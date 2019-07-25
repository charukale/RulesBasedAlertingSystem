#pragma once

#include<iostream>
#include<string>
#include <chrono>
#include <thread>
#include <DataValidator.h>
#include <ConsoleColor.h>

using namespace std;

namespace alertingsystem
{
	void DataValidator::validateData()
	{
		std::chrono::seconds interval(INTERVAL); // 10 seconds
		while (true)
		{
			PatientData patientData = m_buffer->m_patientData;

			string id = patientData.m_patientId;
			//normal range spo2 = 95 - 100;
			double spo2 = patientData.m_SPO2;
			//normal range temp 97 - 99
			double temperature = patientData.m_temperature;
			//normal range PR 60 - 100
			double pulseRate = patientData.m_pulseRate;

			bool isSPO2InRange = checkSPO2(spo2);
			bool isTemperatureInRange = checkTemperature(temperature);
			bool isPulseRateInRange = checkPulseRate(pulseRate);

			if (!isSPO2InRange)
			{
				cout << red  << "Alert!!! SPO2 not in range. SPO2:" << spo2 << " for patient " << id;
				cout << endl;
			}
			if (!isTemperatureInRange)
			{
				cout << red << "Alert!!! Temparature not in range. Temparature:" << temperature << " for patient " << id;
				cout << endl;
			}
			if (!isPulseRateInRange)
			{
				cout << red << "Alert!!! Pulse Rate not in range. Pulse Rate:" << pulseRate << " for patient " << id;
				cout << endl;
			}

			if (!isSPO2InRange || !isTemperatureInRange || !isPulseRateInRange)
			{
				cout << red << "Emergency situation, alerting nurse!!!";// In Red
				cout << endl;
			}

			std::this_thread::sleep_for(interval);
		}		
	}

	bool DataValidator::checkSPO2(double spo2)
	{
		if (spo2 > MIN_SPO2 && spo2 < MAX_SPO2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DataValidator::checkTemperature(double temp)
	{
		if (temp > MIN_TEMPERATURE && temp < MAX_TEMPERATURE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DataValidator::checkPulseRate(double pulseRate)
	{
		if (pulseRate > MIN_PULSE_RATE && pulseRate < MAX_PULSE_RATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

	
