/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Event.h
 *  29.04.2020
 *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Part of 'Slim Engine'
 *      https://github.com/laurensnol/slim
 *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Copyright 2020 Laurens Nolting

 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#ifndef SLIM_EVENT_H
#define SLIM_EVENT_H

#include "slimpch.h"

namespace slim
{
    enum EVENT_TYPE
    {
        // Window Events
        WINDOW_MOVE, WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS,

        // Mouse Events
        MOUSE_MOVE, MOUSE_SCROLL, MOUSE_KEY_PRESS, MOUSE_KEY_RELEASE, MOUSE_KEY_HOLD,

        // Key Events
        KEY_PRESS, KEY_RELEASE, KEY_HOLD,

        // Controller Events (preliminary)
        CONTROLLER_KEY_PRESS, CONTROLLER_KEY_RELEASE, CONTROLLER_KEY_HOLD
    };

    class Event
    {
    public:
        Event(EVENT_TYPE type, std::any message)
            : m_type(type), m_message(message) {}

        virtual ~Event() = default;

        virtual std::any getMessage() = 0;
        virtual EVENT_TYPE getType() = 0;

        virtual const std::string toString()
        {
            std::stringstream ss;
            ss << "Event of Type: " << m_type;

            return ss.str();
        }

    private:
        std::any m_message;
        EVENT_TYPE m_type;
    };

    // Event Callback Function
    typedef std::function<void(Event&)> EventCallbackFun;
}

#endif