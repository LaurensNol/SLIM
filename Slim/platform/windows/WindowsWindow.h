/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  WindowsWindow.h
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

#ifndef SLIM_WINWINDOW_H
#define SLIM_WINWINDOW_H

#include "slimpch.h"

#include "../../core/Window.h"
#include "../../core/events/Event.h"
#include "../../core/events/WindowEvents.h"
#include "../../core/events/MouseEvents.h"
#include "../../core/events/KeyEvents.h"
#include "../../core/Core.h"

#include <GLFW/glfw3.h>

namespace slim
{
    // Handler for GLFW Window Data
    struct WindowData
    {
        std::string title;
        unsigned int width;
        unsigned int height;
        bool vsync;

        EventCallbackFun eventCallback;
    };

    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowConfig& config);
        virtual ~WindowsWindow();

        inline void* getNativeWindow() const override { return m_nativeWindow; }

        inline const std::string& getTitle() override { return m_data.title; }
        inline unsigned int getWidth() override { return m_data.width; }
        inline unsigned int getHeight() override { return m_data.height; }
        inline bool getVsync() override { return m_data.vsync; }

        void setTitle(const std::string& title) override;
        void setWidth(unsigned int width) override;
        void setHeight(unsigned int height) override;
        void setVsync(bool vsync) override;
        
        void update() override;
        void terminate() override;

        void setEventCallback(const EventCallbackFun& callback) override;

    private:
        GLFWwindow* m_nativeWindow;
        WindowData m_data;

        static void GLFWErrorCallback(int error, const char* description);
    };
}

#endif