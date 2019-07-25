#pragma once

namespace alertingsystem
{
	const char COMMA_DELIMETER = ',';
	const char COLON_DELIMETER = ':';
	const double MIN_TEMPERATURE = 97;
	const double MAX_TEMPERATURE = 99;
	const double MIN_PULSE_RATE = 60;
	const double MAX_PULSE_RATE = 100;
	const double MIN_SPO2 = 95;
	const double MAX_SPO2 = 100;
	const int INTERVAL = 5;

	static double randomizeDouble(double nMin, double nMax)
	{
		return nMin + (double)((double)rand() / (RAND_MAX + 1) * (nMax - nMin + 1));
	}
}
