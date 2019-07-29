#include "pch.h"
#include "CppUnitTest.h"
#include "../RulesBasedAlertingSys/ConsoleColor.h"
#include "../RulesBasedAlertingSys/Constants.h"
#include "../RulesBasedAlertingSys/DataProvider.h"
#include "../RulesBasedAlertingSys/DataValidator.h"
#include "../RulesBasedAlertingSys/Parser.h"
#include "../RulesBasedAlertingSys/PatientData.h"
#include "../RulesBasedAlertingSys/DataProvider.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace alertingsystem;
namespace TestProject1
{
	TEST_CLASS(unittest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			string jsonData = "patient id \" TRJIW432\"." "," "SPO2\" 96\"."","
				"pulse rate \" 75\"." "," "temperature \"98.6\".";
			PatientData p_data;
			p_data = Parser::parseJsonData(jsonData);

			string id = p_data.m_patientId;
			double spo2 = p_data.m_SPO2;
			double temperature = p_data.m_temperature;
			double pulseRate = p_data.m_pulseRate;
			Assert::AreEqual("TRJIW432", "id");
			Assert::AreEqual(96.00, spo2);
			Assert::AreEqual(75.00, pulseRate);
			Assert::AreEqual(98.6, temperature);
		}
		
	};
}
