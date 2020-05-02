/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  MouseEvents.h
 *  02.05.2020
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

#ifndef SLIM_MOUSEEVENTS_H
#define SLIM_MOUSEEVENTS_H

#include "slimpch.h"

#include "Event.h"

namespace slim
{
    class MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float x, float y)
            : m_x(x), m_y(y) { }

        EventType getType() const override { return EventType::MouseMove; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "MouseMoveEvent " << m_x << ", " << m_y;

            return ss.str();
        }

        inline float getX() { return m_x; }
        inline float getY() { return m_y; }

    private:
        float m_x;
        float m_y;
    };

    class MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(float xOff, float yOff)
            : m_xOff(xOff), m_yOff(yOff) { }

        EventType getType() const override { return EventType::MouseScroll; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "MouseScrollEvent " << m_xOff << ", " << m_yOff;

            return ss.str();
        }

        inline float getX() { return m_xOff; }
        inline float getY() { return m_yOff; }

    private:
        float m_xOff;
        float m_yOff;
    };

    class MouseButtonEvent : public Event
    {
    public:
        int getButton() const { return m_button; }

    protected:
        MouseButtonEvent(int button)
            : m_button(button) { }

        int m_button;
    };

    class MouseButtonPressEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressEvent(int button)
            : MouseButtonEvent(button) { }

        EventType getType() const override { return EventType::MouseButtonPress; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "MouseButtonPressEvent: " << getButton();

            return ss.str();
        }
    };

    class MouseButtonReleaseEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleaseEvent(int button)
            : MouseButtonEvent(button) { }

        EventType getType() const override { return EventType::MouseButtonRelease; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "MouseButtonReleaseEvent: " << getButton();

            return ss.str();
        }
    };

    class MouseButtonHoldEvent : public MouseButtonEvent
    {
    public:
        MouseButtonHoldEvent(int button)
            : MouseButtonEvent(button) { }

        EventType getType() const override { return EventType::MouseButtonHold; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "MouseButtonHoldEvent: " << getButton();

            return ss.str();
        }
    };
}

#endif