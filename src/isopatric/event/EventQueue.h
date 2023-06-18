#ifndef ISOPATRIC_EVENT_EVENTQUEUE_H
#define ISOPATRIC_EVENT_EVENTQUEUE_H

#include "Event.h"
#include <isopatric/core/Base.h>

namespace isopatric::event
{

    class EventQueue
    {
    public:
        virtual ~EventQueue() = default;

        virtual Scope<Event> poll() = 0;

        static Scope<EventQueue> create();
    };

}

#endif // ISOPATRIC_EVENT_EVENTQUEUE_H
