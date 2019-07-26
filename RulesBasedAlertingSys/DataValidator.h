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
#include <Parser.h>
#include <PatientData.h>
#include <Constants.h>

namespace alertingsystem
{
	class DataValidator
	{
	private:
		Buffer *m_buffer;
		
		bool DataValidator::checkItem(ItemType itemType, double itemValue);
	public:
		//parameterized constructor.
		DataValidator(Buffer *buffer)
		{
			m_buffer = buffer;
		}
		//this function checks for the validity of the data.
		void validateData();
	};

}

