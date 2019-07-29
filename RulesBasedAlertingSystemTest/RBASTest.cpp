#include "stdafx.h"
#include "CppUnitTest.h" 
#include<string>
#include <PatientData.h>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RulesBasedAlertingSystemTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string jsonData = "patient id \" TRJIW432\"." ", " "SPO2\" 96\"."","
				"pulse rate \" 75\".""," "temperature \"98.6\".";

			PatientData p_data;

		}

	};
}