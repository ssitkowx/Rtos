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

        Rtos () = default;
        virtual ~Rtos () = default;

        static void      SetInstance              (Rtos * v_instance) { instance = v_instance; }
        static Rtos *    GetInstance              (void             ) { return instance;       }

        virtual void     DelayInMs                (const uint32_t v_ms)           = 0;
        virtual bool     TakeSemaphore            (std::string_view v_name)       = 0;
        virtual bool     GiveSemaphoreFromISR     (std::string_view v_name)       = 0;
        virtual uint32_t GetCurrentHeapSize       (void)                          = 0;
        virtual uint32_t GetCurrentStackSize      (std::string_view v_name)       = 0;
        virtual uint32_t TaskCreate               (TaskFunctionType v_taskFuncion,
                                                   std::string_view v_taskName,
                                                   const uint32_t   v_stackDepth,
                                                   const uint32_t   v_priority,
                                                   TaskHandle       v_taskHandle) = 0;
};
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
