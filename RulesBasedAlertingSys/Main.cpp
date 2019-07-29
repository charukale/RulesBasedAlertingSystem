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
#include <thread>
#include <PatientData.h>
#include <DataProvider.h>
#include <DataValidator.h>
#include <RBASSemaphore.h>
#include <SemaphoreRBAS.h>

using namespace std;

using namespace pthreadMutex;
using namespace alertingsystem;

//this thread calls the startOperation() function.
typedef void * (*THREADFUNCPTR)(void *);
void startDPThread(DataProvider *dataProvider)
{
    dataProvider->startOperation();
}

//this thread calls the validateData() function.
void startDVThread(DataValidator *dataValidator)
{
    dataValidator->validateData();
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

    //pthread_mutex_init(&myMutex , 0);
    //std::thread dataProviderThread(startDPThread, dataProvider);
    //pthread_mutex_t myMutex;
    pthread_t thread1;
    pthread_t thread2;

    /*pthread_mutex_init(&myMutex , 0);*/

    SemaphoreRBAS::initialize();

    //dataProvider.setMutex(&SemaphoreRBAS::getMutex());
    //dataValidator.setMutex(&SemaphoreRBAS::getMutex());

    //pthread_create(&thread1 , 0, (THREADFUNCPTR)&dataProvider.startOperation, NULL);
    
    pthread_create(&thread1, NULL, (THREADFUNCPTR)startDPThread, &dataProvider);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pthread_create(&thread2, NULL, (THREADFUNCPTR)startDVThread, &dataValidator);
    

    //std::this_thread::sleep_for(std::chrono::seconds(2)); 

    

    
    pthread_join(thread2, 0);
    pthread_join(thread1, 0);

    pthread_mutex_destroy(&SemaphoreRBAS::getMutex());

    //
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    //std::thread dataValidatorThread(startDVThread, dataValidator);

    // synchronize threads:
    /*dataProviderThread.join();
    dataValidatorThread.join();*/
    //pthread_mutex_destroy(&myMutex);


    return 0;
}

