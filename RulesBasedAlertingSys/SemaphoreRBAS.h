#pragma once
#include <mutex>
#include <pthread.h>
namespace alertingsystem
{
    class SemaphoreRBAS {

    private:
        static pthread_mutex_t m_mutexInstance;

    public:
        static void SemaphoreRBAS::initialize()
        {
            pthread_mutex_init(&(SemaphoreRBAS::getMutex()), 0);
        }
        static pthread_mutex_t& getMutex();
    };
}