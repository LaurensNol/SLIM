/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Log.h
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

#ifndef SLIM_LOG_H
#define SLIM_LOG_H

#include <memory>

#include <spdlog/spdlog.h>

namespace slim
{
    class Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& Core() { return s_coreLogger; };
        static std::shared_ptr<spdlog::logger>& App() { return s_appLogger; };

    private:
        static std::shared_ptr<spdlog::logger> s_coreLogger;

        // To be used in client side
        static std::shared_ptr<spdlog::logger> s_appLogger;
    };
}

#define SLIM_CORE_TRACE(...)    ::slim::Log::Core()->trace(__VA_ARGS__)
#define SLIM_CORE_INFO(...)     ::slim::Log::Core()->info(__VA_ARGS__)
#define SLIM_CORE_ERROR(...)    ::slim::Log::Core()->error(__VA_ARGS__)
#define SLIM_CORE_CRITICAL(...) ::slim::Log::Core()->critical(__VA_ARGS__)

#define SLIM_TRACE(...)    ::slim::Log::App()->trace(__VA_ARGS__)
#define SLIM_INFO(...)     ::slim::Log::App()->info(__VA_ARGS__)
#define SLIM_ERROR(...)    ::slim::Log::App()->error(__VA_ARGS__)
#define SLIM_CRITICAL(...) ::slim::Log::App()->critical(__VA_ARGS__)

#endif