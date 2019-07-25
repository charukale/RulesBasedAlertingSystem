#pragma once

#include <iostream> 
#include <iterator> 
#include<string>
#include <chrono>
#include <thread>
#include<list>
#include <DataProvider.h>
#include <Parser.h>
#include <ConsoleColor.h>
#include <Constants.h>


namespace alertingsystem
{
	int index = 0;
	string DataProvider::generateData()
	{
		int id = (int)randomizeDouble(1111, 9999);
		double spo2 = randomizeDouble(MIN_SPO2, MAX_SPO2 + 0.5);
		double pulseRate = randomizeDouble(MIN_PULSE_RATE, MAX_PULSE_RATE + 0.5);
		double temperature = randomizeDouble(MIN_TEMPERATURE, MAX_TEMPERATURE + 0.5);
		//list<std::string>::iterator it = m_jsonDataList.begin();

		//// Advance the iterator by index positions,
		//std::advance(it, index);

		//index = index + 1;

		//if (index == m_jsonDataList.size())
		//{
		//	index = 0;
		//}

		//return *it;
		return 
			"{patient id: Patient_" + std::to_string(id) + ", SPO2 :" + std::to_string(spo2) +
			", pulse rate : " + std::to_string(pulseRate) + 
			", temperature : " + std::to_string(temperature) + " }";
	}

	void DataProvider::startOperation()
	{
		std::chrono::seconds interval(INTERVAL); // 10 seconds
		while(true)
		{
			string jsonData = generateData();
			printData(jsonData);

			PatientData patientData = Parser::parseJsonData(jsonData);
			pushDataToBuffer(patientData);

			std::this_thread::sleep_for(interval);
		}
	}

	void DataProvider::printData(string strData)
	{
		cout <<  yellow<< (strData);
		cout << '\n';
	}

	void DataProvider::pushDataToBuffer(PatientData patientData)
	{
		//PatientData tempPatientData(patientData.m_patientId, patientData.m_SPO2, patientData.m_pulseRate, patientData.m_temperature);
		m_buffer->m_patientData.m_patientId = patientData.m_patientId;
		m_buffer->m_patientData.m_SPO2 = patientData.m_SPO2;
		m_buffer->m_patientData.m_pulseRate = patientData.m_pulseRate;
		m_buffer->m_patientData.m_temperature = patientData.m_temperature;
	}

}