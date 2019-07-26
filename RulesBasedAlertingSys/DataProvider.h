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

using namespace std;

namespace alertingsystem
{
	class DataProvider {
	private:
		Buffer *m_buffer;
		int m_idCounter = 0;
		int m_patientId = 0;

		//calling the generateData() funcion to generate the data
		string generateData();

		//calling pushDataToBuffer() function to push data to the buffer.
		void pushDataToBuffer(PatientData patientData);

	public :
        //constructor to initialize the member variable m_buffer.
		DataProvider(Buffer *buffer)
		{
			m_buffer = buffer;
		}		
		//calling printData to print the json string on the console.
		void printData(string strData);	
		//calling startOperation() to start the application.
		void startOperation();
	};

}
