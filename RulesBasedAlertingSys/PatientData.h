#pragma once
#include<iostream>
#include<string>
using namespace std;

namespace alertingsystem
{
	class PatientData {
	public:
		string m_patientId;
		double m_SPO2;
		double m_pulseRate;
		double m_temperature;

		PatientData() {};

		PatientData(string patientId, double SPO2, double pulseRate, double temperature)
		{
			m_patientId = patientId;
			m_SPO2 = SPO2;
			m_pulseRate = pulseRate;
			m_temperature = temperature;
		}

	};

	class Buffer
	{
	public:
		Buffer() {};
		PatientData m_patientData;
	};

}
