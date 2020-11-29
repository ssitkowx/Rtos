#pragma once

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// MACROS/DEFINITIONS ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define SET_RTOS_INST(INSTANCE) Rtos::SetInstance (INSTANCE);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class Rtos
{
    private:
        static inline Rtos * instance = nullptr;

    public:
        typedef void * TaskHandle;
        typedef void (* TaskFunctionType)(void *);

        static void      SetInstance          (Rtos * v_instance) { instance = v_instance; }
        static Rtos *    GetInstance          (void) { return instance; }

        Rtos () = default;
        virtual ~Rtos () = default;

        virtual void     DelayInMs            (const uint32_t v_ms)                = 0;
        virtual bool     GiveSemaphoreFromISR (const std::string & v_name)         = 0;
        virtual bool     TakeSemaphore        (const std::string & v_name)         = 0;
        virtual uint32_t GetCurrentHeapSize   (void)                               = 0;
        virtual uint32_t GetCurrentStackSize  (const std::string & v_name)         = 0;
        virtual uint32_t TaskCreate           (TaskFunctionType    v_taskFuncion,
                                               const std::string & v_taskName,
                                               const uint32_t     v_stackDepth,
                                               const uint32_t     v_priority,
                                               TaskHandle         v_taskHandle)    = 0;
};
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
