#pragma once
#include<iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <PatientData.h>

namespace alertingsystem
{
	class Parser {
	private :
		static void splitInfo();
	public:
		static PatientData parseJsonData(string strJsonData);
	};
}


