#include "Core.h"

namespace EventSample
{
    CoreClass::CoreClass()
    {
    }

    CoreClass::~CoreClass()
    {
    }

    void CoreClass::AddEvent(action_t callback)
    {
        m_callbacks.push_back(callback);
    }

    void CoreClass::RemoveEvent(action_t callback)
    {
        auto it = std::remove(m_callbacks.begin(), m_callbacks.end(), callback);
        m_callbacks.erase(it, m_callbacks.end());
    }

    void CoreClass::CallEvents()
    {
        for(action_t callback : m_callbacks) callback();
    }
}