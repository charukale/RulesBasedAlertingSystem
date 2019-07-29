
#pragma once
#include "stdafx.h"
#include <CppUnitTest.h>
#include <ConsoleColor.h>
#include <DataProvider.h>
#include <DataValidator.h>
#include <Parser.h>
#include <PatientData.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace alertingsystem;

namespace UnitTest2
{
    TEST_CLASS(unittest2)
    {
    public:

        TEST_METHOD(parseJsonString_TestCase1)
        {
            string jsonData = "{patient id: Patient_" + std::to_string(11) + ", SPO2 :" + std::to_string(11) +
                ", pulse rate : " + std::to_string(11) +
                ", temperature : " + std::to_string(11) + " }";
            PatientData p_data = Parser::parseJsonData(jsonData);

            string id = p_data.m_patientId;
            double spo2 = p_data.m_SPO2;
            double temperature = p_data.m_temperature;
            double pulseRate = p_data.m_pulseRate;
            Assert::IsTrue("Patient_11" == id.substr(1, id.length()));
            Assert::AreEqual(11.0, spo2);
            Assert::AreEqual(11.0, pulseRate);
            Assert::AreEqual(11.0, temperature);
        }
        TEST_METHOD(parseJsonString_TestCase2)
        {
            string jsonData = "{patient id: Patient_" + std::to_string(96) + ", SPO2 :" + std::to_string(96) +
                ", pulse rate : " + std::to_string(96) +
                ", temperature : " + std::to_string(96) + " }";
            PatientData p_data = Parser::parseJsonData(jsonData);

            string id = p_data.m_patientId;
            double spo2 = p_data.m_SPO2;
            double temperature = p_data.m_temperature;
            double pulseRate = p_data.m_pulseRate;
            Assert::IsTrue("Patient_96" == id.substr(1, id.length()));
            Assert::AreEqual(96.0, spo2);
            Assert::AreEqual(96.0, pulseRate);
            Assert::AreEqual(96.0, temperature);
        }
        TEST_METHOD(parseJsonString_TestCase3)
        {
            string jsonData = "{patient id: Patient_" + std::to_string(55) + ", SPO2 :" + std::to_string(55) +
                ", pulse rate : " + std::to_string(55) +
                ", temperature : " + std::to_string(55) + " }";
            PatientData p_data = Parser::parseJsonData(jsonData);

            string id = p_data.m_patientId;
            double spo2 = p_data.m_SPO2;
            double temperature = p_data.m_temperature;
            double pulseRate = p_data.m_pulseRate;
            Assert::IsTrue("Patient_55" == id.substr(1, id.length()));
            Assert::AreEqual(55.0, spo2);
            Assert::AreEqual(55.0, pulseRate);
            Assert::AreEqual(55.0, temperature);
        }

        TEST_METHOD(parseJsonStringNull_TestCase4)
        {
            string jsonData = "";
            PatientData p_data = Parser::parseJsonData(jsonData);

            string id = p_data.m_patientId;
            double spo2 = p_data.m_SPO2;
            double temperature = p_data.m_temperature;
            double pulseRate = p_data.m_pulseRate;
            Assert::IsTrue("" == id);
            Assert::AreEqual(-1.0, spo2);
            Assert::AreEqual(-1.0, pulseRate);
            Assert::AreEqual(-1.0, temperature);
        }
        TEST_METHOD(valueInRange_TestCase5)
        {
            Assert::IsTrue(DataValidator::checkItem(ItemType::PulseRate, 75.0));
            Assert::IsTrue(DataValidator::checkItem(ItemType::SPO2, 96.0));
            Assert::IsTrue(DataValidator::checkItem(ItemType::Temperature, 98.0));
        }
        TEST_METHOD(valueInRange_TestCase6)
        {
            Assert::IsTrue(DataValidator::checkItem(ItemType::PulseRate, 85.0));
            Assert::IsTrue(DataValidator::checkItem(ItemType::SPO2, 98.0));
            Assert::IsTrue(DataValidator::checkItem(ItemType::Temperature, 97.0));
        }

        TEST_METHOD(value_outOfRange_TestCase7)
        {
            Assert::IsTrue(DataValidator::checkItem(ItemType::PulseRate, 55.0) == false);
            Assert::IsTrue(DataValidator::checkItem(ItemType::SPO2, 58.0) == false);
            Assert::IsTrue(DataValidator::checkItem(ItemType::Temperature, 100.5) == false);
        }

       TEST_METHOD(value_outOfRange_TestCase8)
        {
            Assert::IsTrue(DataValidator::checkItem(ItemType::PulseRate, 50.0) == false);
            Assert::IsTrue(DataValidator::checkItem(ItemType::SPO2, 100.5) == false);
            Assert::IsTrue(DataValidator::checkItem(ItemType::Temperature, 107.5) == false);
        }
    };
}