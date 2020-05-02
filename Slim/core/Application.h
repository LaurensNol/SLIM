/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Application.h
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

#ifndef SLIM_APPLICATION_H
#define SLIM_APPLICATION_H

#include "core/events/Event.h"
#include "core/Window.h"
#include "core/Core.h"

// Forward declare main function from SlimEntry.h
int main(int argc, char** argv);

namespace slim
{
    class Application
    {
    public:
        Application();
        virtual ~Application() = default;

        void onEvent(Event& e);

        Window& getWindow() { return *m_window; }

        static Application& Get() { return *s_instance; }

    private:
        void run();

        std::unique_ptr<Window> m_window;
        bool m_running;
        static Application* s_instance;
        friend int ::main(int argc, char** argv);
    };

    Application* CreateApplication();
}

#endif