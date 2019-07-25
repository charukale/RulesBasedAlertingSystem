#include<iostream>
#include<string>
#include <thread>
#include <PatientData.h>
#include <DataProvider.h>
#include <DataValidator.h>


using namespace std;
using namespace alertingsystem;

void startDPThread(DataProvider dataProvider)
{
	dataProvider.startOperation();
}

void startDVThread(DataValidator dataValidator)
{
	dataValidator.validateData();
}

int main()
{
	Buffer buffer;

	DataProvider dataProvider(&buffer);
	//dataProvider.startOperation();

	DataValidator dataValidator(&buffer);
	//dataValidator.validateData();


	std::thread dataProviderThread(startDPThread, dataProvider);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::thread dataValidatorThread(startDVThread, dataValidator);

	// synchronize threads:
	dataProviderThread.join();
	dataValidatorThread.join();

	return 0;
}

