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
    enum class CursorMode
    {
        Normal,
        Hidden,
        Disabled
    };

    struct WindowConfig
    {
        std::string title;
        unsigned int width;
        unsigned int height;

        WindowConfig(const std::string& title = "Slim Engine", unsigned int width = 1024, unsigned int height = 720)
            : title(title), width(width), height(height) { }
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void* getNativeWindow() const = 0;

        virtual const std::string& getTitle() = 0;
        virtual unsigned int getWidth() = 0;
        virtual unsigned int getHeight() = 0;
        virtual bool getVsync() = 0;

        virtual void setTitle(const std::string& title) = 0;
        virtual void setWidth(unsigned int width) = 0;
        virtual void setHeight(unsigned int width) = 0;
        virtual void setVsync(bool vsync) = 0;

        virtual void update() = 0;
        virtual void terminate() = 0;

        virtual void setEventCallback(const EventCallbackFun& callback) = 0;

        static std::unique_ptr<Window> Create(const WindowConfig& config = WindowConfig());
    };
}

#endif