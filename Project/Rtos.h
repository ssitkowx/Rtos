#pragma once

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <class DERIVED_TYPE>
class Rtos
{
    friend DERIVED_TYPE;
    DERIVED_TYPE & derivedType = static_cast <DERIVED_TYPE &>(*this);

    private:
        static inline DERIVED_TYPE * inst = nullptr;

    public:
        Rtos            ()                           = default;
        Rtos            (const DERIVED_TYPE & vRtos) = delete;
        Rtos & operator=(const DERIVED_TYPE & vRtos) = delete;
        Rtos & operator=(DERIVED_TYPE && vRtos)      = delete;
        virtual ~Rtos   ()                           = default;

        static void           SetInst              (DERIVED_TYPE * const vInstance) { inst = vInstance; }
        static DERIVED_TYPE * GetInst              (void                          ) { return inst;      }

        void                  Init                 (void)                           { derivedType.Init       ();                       }
        void                  DeInit               (void)                           { derivedType.DeInit     ();                       }
        void                  TaskDelete           (void)                           { derivedType.TaskDelete ();                       }
        uint16_t              GetFreeHeapSize      (void)                           { return derivedType.GetFreeHeapSize ();           }
        void                  DelayInMs            (const uint32_t vMs)             { derivedType.DelayInMs (vMs);                     }
        bool                  TakeSemaphore        (std::string_view vName)         { return derivedType.TakeSemaphore (vName);        }
        uint16_t              GetFreeStackSize     (std::string_view vTaskName)     { return derivedType.GetFreeStackSize (vTaskName); }
        bool                  GiveSemaphoreFromISR (std::string_view vName)         { return derivedType.GiveSemaphoreFromISR (vName); }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////