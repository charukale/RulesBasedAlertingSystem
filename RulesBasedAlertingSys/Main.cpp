//============================================================================
//
// COPYRIGHT KONINKLIJKE PHILIPS ELECTRONICS N.V. 2019
// All rights are reserved. Reproduction in whole or in part is
// prohibited without the written consent of the copyright owner.
//
//============================================================================ 
#include<iostream>
#include<string>
#include <thread>
#include <PatientData.h>
#include <DataProvider.h>
#include <DataValidator.h>


using namespace std;
using namespace alertingsystem;

//this thread calls the startOperation() function.
void startDPThread(DataProvider dataProvider)
{
	dataProvider.startOperation();
}

//this thread calls the validateData() function.
void startDVThread(DataValidator dataValidator)
{
	dataValidator.validateData();
}

int main()
{
	//creating the the object of buffer class.
	Buffer buffer;

	//buffer object is passed as parameter to the dataProvider
	DataProvider dataProvider(&buffer);

	////buffer object is passed as parameter to the dataProvider
	DataValidator dataValidator(&buffer);

	//this thread calls the startDPThread function and dataProvider
	std::thread dataProviderThread(startDPThread, dataProvider);
	//
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::thread dataValidatorThread(startDVThread, dataValidator);

	// synchronize threads:
	dataProviderThread.join();
	dataValidatorThread.join();

	return 0;
}

