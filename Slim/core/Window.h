/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Window.h
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

#ifndef SLIM_WINDOW_H
#define SLIM_WINDOW_H

#include "slimpch.h"

#include "events/Event.h"

#include <GLFW/glfw3.h>

namespace slim
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;
        virtual unsigned int getTitle() const = 0;

        virtual void onUpdate() = 0;
        virtual void onEvent() = 0;

        virtual void terminate() = 0;

        virtual void setVsync(bool value) = 0;
        virtual bool isVsync() const = 0;

        virtual void setEventCallbackFun(const EventCallbackFun& callback) = 0;
    private:
        EventCallbackFun m_eventCallbackFun;
    };
}

#endif