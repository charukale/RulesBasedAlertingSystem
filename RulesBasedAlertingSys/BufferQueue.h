#pragma once
#include<queue>
#include<PatientData.h>
using namespace alertingsystem;

namespace bufferqueue
{
    class BufferQueue 
    {
    public:
      static queue<PatientData> patientDataQueue;
    };
   
}


