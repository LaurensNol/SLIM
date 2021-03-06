/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Application.cpp
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

#include "slimpch.h"

#include "Application.h"

namespace slim
{
    Application* Application::s_instance = nullptr;

    Application::Application()
    {
        SLIM_CORE_ASSERT(!s_instance, "Application already exists.");

        s_instance = this;
        m_window = Window::Create();
        m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
    }

    void Application::onEvent(Event& e)
    {
        return;
    }

    void Application::run()
    {
        while (m_running)
        {
            m_window->update();
        }
    }
}