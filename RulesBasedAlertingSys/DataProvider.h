#pragma once
#include<iostream>
#include <list> 
#include <string>
#include <PatientData.h>

using namespace std;

namespace alertingsystem
{
	class DataProvider {
	private:
		Buffer *m_buffer;
		list <string> m_jsonDataList{ "{patient id: NTRJIW432, SPO2 : 96, pulse rate : 75, temperature : 98.6 }", 
			"{patient id: ATRJIW433, SPO2 : 96, pulse rate : 75, temperature : 198.6 }",
			"{patient id: ATRJIW433, SPO2 : 196, pulse rate : 75, temperature : 98.6 }" ,
			"{patient id: NTRJIW433, SPO2 : 96, pulse rate : 75, temperature : 98.6 }" ,
			"{patient id: ATRJIW433, SPO2 : 96, pulse rate : 175, temperature : 98.6 }" ,
			"{patient id: NTRJIW433, SPO2 : 96, pulse rate : 75, temperature : 98.6 }" };
		string generateData();
		void pushDataToBuffer(PatientData patientData);
	public :
		DataProvider(Buffer *buffer)
		{
			m_buffer = buffer;
		}		
		void printData(string strData);		
		void startOperation();
	};

}
