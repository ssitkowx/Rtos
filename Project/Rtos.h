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

        static void           SetInst (DERIVED_TYPE * const vInstance) { inst = vInstance; }
        static DERIVED_TYPE * GetInst (void              )             { return inst;      }

        void                  Init       (void)                        { derivedType.Init       ();    }
        void                  DeInit     (void)                        { derivedType.DeInit     ();    }
        void                  TaskDelete (void)                        { derivedType.TaskDelete ();    }
        void                  DelayInMs  (const uint32_t vMs)          { derivedType.DelayInMs  (vMs); }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
