#pragma once 

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "Rtos.h"
#include "gmock/gmock.h"

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class RtosHw final : public Rtos
{
    public:
        RtosHw () = default;
        ~RtosHw () = default;

        MOCK_METHOD1 (DelayInMs           , void (const uint32_t));
        MOCK_METHOD1 (TakeSemaphore       , bool (std::string_view v_name));
        MOCK_METHOD1 (GiveSemaphoreFromISR, bool (std::string_view v_name));
        MOCK_METHOD0 (GetCurrentHeapSize  , uint32_t (void));
        MOCK_METHOD1 (GetCurrentStackSize , uint32_t (std::string_view v_name));
        MOCK_METHOD5 (TaskCreate          , uint32_t (TaskFunctionType v_taskFuncion,
                                                      std::string_view v_taskName,
                                                      const uint32_t   v_stackDepth,
                                                      const uint32_t   v_priority,
                                                      TaskHandle       v_taskHandle));
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////