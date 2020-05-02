/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  WindowEvents.h
 *  01.05.2020
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

#ifndef SLIM_WINDOWEVENTS_H
#define SLIM_WINDOWEVENTS_H

#include "slimpch.h"

#include "Event.h"
#include "../Window.h"

namespace slim
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        EventType getType() const override { return EventType::WindowClose; }

        virtual inline const std::string& toString() { return "WindowCloseEvent"; }
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_width(width), m_height(height) { }

        EventType getType() const override { return EventType::WindowResize; }

        virtual inline const std::string& toString() { return "WindowResizeEvent"; }

        inline unsigned int getWidth() const { return m_width; }
        inline unsigned int getHeight() const { return m_height; }
            
    private:
        unsigned int m_width;
        unsigned int m_height;
    };

    class WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent(bool focused)
            : m_focused(focused) { }

        EventType getType() const override { return EventType::WindowFocus; }

        virtual inline const std::string& toString() { return "WindowFocusEvent"; }

    private:
        bool m_focused;
    };
}

#endif