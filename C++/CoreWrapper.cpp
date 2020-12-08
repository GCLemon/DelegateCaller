// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//   CBGに似せたやつ
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <stdint.h>
#include <stdio.h>

#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#include <Windows.h>
#endif

#ifndef CBGEXPORT
#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#define CBGEXPORT __declspec(dllexport)
#else
#define CBGEXPORT
#endif
#endif

#ifndef CBGSTDCALL
#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#define CBGSTDCALL __stdcall
#else
#define CBGSTDCALL
#endif
#endif

#include "Core.h"

extern "C" {

    CBGEXPORT void* CBGSTDCALL cbg_CoreClass_Constructor_0() {
        return new EventSample::CoreClass();
    }
    
    CBGEXPORT void CBGSTDCALL cbg_CoreClass_CallEvents(void* cbg_self) {
        auto cbg_self_ = (EventSample::CoreClass*)(cbg_self);
        cbg_self_->CallEvents();
    }
    
    CBGEXPORT void CBGSTDCALL cbg_CoreClass_AddEvent(void* cbg_self, void(*callback)()) {
        auto cbg_self_ = (EventSample::CoreClass*)(cbg_self);
        cbg_self_->AddEvent(callback);
    }
    
    CBGEXPORT void CBGSTDCALL cbg_CoreClass_RemoveEvent(void* cbg_self, void(*callback)()) {
        auto cbg_self_ = (EventSample::CoreClass*)(cbg_self);
        cbg_self_->RemoveEvent(callback);
    }
    
    CBGEXPORT void CBGSTDCALL cbg_CoreClass_AddRef(void* cbg_self) {
        auto cbg_self_ = (EventSample::CoreClass*)(cbg_self);
        cbg_self_->AddRef();
    }
    
    CBGEXPORT void CBGSTDCALL cbg_CoreClass_Release(void* cbg_self) {
        auto cbg_self_ = (EventSample::CoreClass*)(cbg_self);
        cbg_self_->Release();
    }
}