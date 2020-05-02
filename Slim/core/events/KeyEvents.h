/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  KeyEvents.h
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

#ifndef SLIM_KEYEVENTS_H
#define SLIM_KEYEVENTS_H

#include "slimpch.h"

#include "Event.h"

namespace slim
{
    class KeyEvent : public Event
    {
    public:
        int getKeyCode() const { return m_keyCode; }

    protected:
        KeyEvent(int keyCode)
            : m_keyCode(keyCode) { }

        int m_keyCode;
    };

    class KeyPressEvent : public KeyEvent
    {
    public:
        KeyPressEvent(int keyCode)
            : KeyEvent(keyCode) { }

        EventType getType() const override { return EventType::KeyPress; }

        virtual inline const std::string& toString() 
        {
            std::stringstream ss;
            ss << "KeyPressEvent " << getKeyCode();

            return ss.str();
        }
    };

    class KeyReleaseEvent : public KeyEvent
    {
    public:
        KeyReleaseEvent(int keyCode)
            : KeyEvent(keyCode) { }

        EventType getType() const override { return EventType::KeyRelease; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "KeyReleaseEvent " << getKeyCode();

            return ss.str();
        }
    };

    class KeyHoldEvent : public KeyEvent
    {
    public:
        KeyHoldEvent(int keyCode)
            : KeyEvent(keyCode) { }

        EventType getType() const override { return EventType::KeyHold; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "KeyHoldEvent " << getKeyCode();

            return ss.str();
        }
    };

    class KeyTypeEvent : public KeyEvent
    {
    public:
        KeyTypeEvent(int keyCode)
            : KeyEvent(keyCode) { }

        EventType getType() const override { return EventType::KeyType; }

        virtual inline const std::string& toString()
        {
            std::stringstream ss;
            ss << "KeyTypeEvent " << getKeyCode();

            return ss.str();
        }
    };
}

#endif