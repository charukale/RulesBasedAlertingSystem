#pragma once
#include<iostream>
#include<string>
#include"Parser.h"
#include <PatientData.h>
#include <Constants.h>

namespace alertingsystem
{
	class DataValidator
	{
	private:
		Buffer *m_buffer;
		bool checkTemperature(double temp);
		bool checkSPO2(double spo2);
		bool checkPulseRate(double pulseRate);
	public:
		DataValidator(Buffer *buffer)
		{
			m_buffer = buffer;
		}
		void validateData();
	};

}

