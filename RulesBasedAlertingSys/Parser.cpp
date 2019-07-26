//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============================================================================ 

#include<iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cstring>
#include <Parser.h>
#include <Constants.h>

using namespace std;

namespace alertingsystem
{
	//vector to store the patient information which has been split by comma
	static std::vector<std::string> splitByComma;
	//vector to store the patient information which has been split by colon
	static std::vector<std::string> splitByColon;

	//Function to parse json string of below format
	//"{patient id: ATRJIW433, SPO2 : 96, pulse rate : 75, temperature : 198.6 }"
	PatientData Parser::parseJsonData(string json)
	{
		splitByComma.clear();
		splitByColon.clear();

		string withoutParenthesis = json.substr(1, strlen(json.c_str()) - 2);
		size_t start;
		size_t end = 0;

		while ((start = withoutParenthesis.find_first_not_of(COMMA_DELIMETER, end)) != std::string::npos)
		{
			end = withoutParenthesis.find(COMMA_DELIMETER, start);
			splitByComma.push_back(withoutParenthesis.substr(start, end - start));

		}

		splitInfo();

		PatientData p_data(splitByColon[0], stod(splitByColon[1]), stod(splitByColon[2]), stod(splitByColon[3]));
		return p_data;
	}

	void Parser::splitInfo()
	{
		int size = splitByComma.size();
		for (int i = 0; i < size; i++)
		{
			string temp = splitByComma[i];
			std::string token = splitByComma[i].substr(splitByComma[i].find(COLON_DELIMETER) + 1, splitByComma[i].size());
			splitByColon.push_back(token);
		}
	}
}

	
	


