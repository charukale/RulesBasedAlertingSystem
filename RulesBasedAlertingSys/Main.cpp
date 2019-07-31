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
#include<BufferQueue.h>

using namespace std;

using namespace pthreadMutex;
using namespace alertingsystem;
using namespace bufferqueue;

//this thread calls the startOperation() function.
typedef void * (*THREADFUNCPTR)(void *);

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
    pthread_t producerThread;
    pthread_t consumerThread;

    SemaphoreRBAS::initialize();
    
    //this thread calls the startDPThread function and dataProvider
    pthread_create(&producerThread, NULL, (THREADFUNCPTR)startDPThread, NULL);
    pthread_create(&consumerThread, NULL, (THREADFUNCPTR)startDVThread, NULL);

    pthread_join(consumerThread, 0);
    pthread_join(producerThread, 0);

    return 0;
}

