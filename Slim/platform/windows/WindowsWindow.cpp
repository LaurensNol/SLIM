/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  WindowsWindow.cpp
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

#include "slimpch.h"

#include "WindowsWindow.h"

slim::WindowsWindow::WindowsWindow(const WindowConfig& config)
{
    m_data.title = config.title;
    m_data.width = config.width;
    m_data.height = config.height;

    glfwSetErrorCallback(GLFWErrorCallback);

    int success = glfwInit();
    SLIM_CORE_ASSERT(success, "Failed to initialize GLFW.");

    // Antialising
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_SAMPLES, 16);

    #if defined(_SLIM_DEBUG)
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
    #endif

    m_nativeWindow = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
    SLIM_CORE_ASSERT(m_nativeWindow, "Failed to create GLFW window.");

    glfwMakeContextCurrent(m_nativeWindow);
    glfwSetWindowUserPointer(m_nativeWindow, &m_data);
    setVsync(true);

    // GLFW Callbacks
    glfwSetWindowSizeCallback(m_nativeWindow, [](GLFWwindow* window, int width, int height)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

        WindowResizeEvent e(width, height);
        data.eventCallback(e);
    });
    
    glfwSetWindowCloseCallback(m_nativeWindow, [](GLFWwindow* window)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

        WindowCloseEvent e = WindowCloseEvent();
        data.eventCallback(e);
    });

    glfwSetWindowFocusCallback(m_nativeWindow, [](GLFWwindow* window, int focused)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

        WindowFocusEvent e(focused);
        data.eventCallback(e);
    });
    
    glfwSetKeyCallback(m_nativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        
        switch (action)
        {
            case GLFW_PRESS:
            {
                KeyPressEvent e(key);
                data.eventCallback(e);
                break;
            }
            
            case GLFW_RELEASE:
            {
                KeyReleaseEvent e(key);
                data.eventCallback(e);
                break;
            }
            
            case GLFW_REPEAT:
            {
                KeyHoldEvent e(key);
                data.eventCallback(e);
                break;
            }
        }
    });
    
    glfwSetCharCallback(m_nativeWindow, [](GLFWwindow* window, unsigned int keycode)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        
        KeyTypeEvent e(keycode);
        data.eventCallback(e);
    });
    
    glfwSetMouseButtonCallback(m_nativeWindow, [](GLFWwindow* window, int button, int action, int mods)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

        switch (action)
        {
            case GLFW_PRESS:
            {
                MouseButtonPressEvent e(button);
                data.eventCallback(e);
                break;
            }
            
            case GLFW_RELEASE:
            {
                MouseButtonReleaseEvent e(button);
                data.eventCallback(e);
                break;
            }

            case GLFW_REPEAT:
            {
                MouseButtonHoldEvent e(button);
                data.eventCallback(e);
                break;
            }
        }
    });
    
    glfwSetScrollCallback(m_nativeWindow, [](GLFWwindow* window, double xOff, double yOff)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

        MouseScrollEvent e((float)xOff, (float)yOff);
        data.eventCallback(e);
    });

    glfwSetCursorPosCallback(m_nativeWindow, [](GLFWwindow* window, double xPos, double yPos)
    {
        WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

        MouseMoveEvent e((float)xPos, (float)yPos);
        data.eventCallback(e);
    });
}

slim::WindowsWindow::~WindowsWindow()
{
    terminate();
}

void slim::WindowsWindow::setTitle(const std::string& title)
{
    glfwSetWindowTitle(m_nativeWindow, title.c_str());
    m_data.title = title;
}

void slim::WindowsWindow::setWidth(unsigned int width)
{
    glfwSetWindowSize(m_nativeWindow, width, m_data.height);
    m_data.width = width;
}

void slim::WindowsWindow::setHeight(unsigned int height)
{
    glfwSetWindowSize(m_nativeWindow, m_data.width, height);
    m_data.height = height;
}

void slim::WindowsWindow::setVsync(bool vsync)
{
    glfwSwapInterval(vsync);
    m_data.vsync = vsync;
}

void slim::WindowsWindow::update()
{
    glfwPollEvents();
}

void slim::WindowsWindow::terminate()
{
    glfwDestroyWindow(m_nativeWindow);
    glfwTerminate();
}

void slim::WindowsWindow::setEventCallback(const EventCallbackFun& callback)
{
    m_data.eventCallback = callback;
}

void slim::WindowsWindow::GLFWErrorCallback(int error, const char* description)
{
    SLIM_CORE_ERROR("GLFW Error {0}: {1}", error, description);
}
