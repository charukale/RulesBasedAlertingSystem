#include <SemaphoreRBAS.h>
#include <mutex>
#include <pthread.h>


namespace alertingsystem
{
    pthread_mutex_t SemaphoreRBAS::m_mutexInstance;
    pthread_mutex_t& SemaphoreRBAS::getMutex()
    {
        return m_mutexInstance;
    }
}