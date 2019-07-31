#pragma once
#include <mutex>
#include <pthread.h>
namespace alertingsystem
{
    class SemaphoreRBAS {

        static pthread_mutex_t m_mutexInstance;
        // Getting the mutex 

    public:
        static void SemaphoreRBAS::initialize()
        {
            pthread_mutex_init(&(SemaphoreRBAS::getMutex()), 0);
        }
        __declspec(dllexport) static pthread_mutex_t& getMutex();
    };
}