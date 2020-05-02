/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Log.cpp
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

#include "slimpch.h"

#include "Log.h"

namespace slim
{
    std::shared_ptr<spdlog::logger> Log::s_coreLogger;
    std::shared_ptr<spdlog::logger> Log::s_appLogger;

    void Log::Init()
    {
        s_coreLogger = std::make_shared<spdlog::logger>("SLIM");
        spdlog::register_logger(s_coreLogger);
        s_coreLogger->set_level(spdlog::level::trace);
        s_coreLogger->flush_on(spdlog::level::trace);

        s_appLogger = std::make_shared<spdlog::logger>("APP");
        spdlog::register_logger(s_appLogger);
        s_appLogger->set_level(spdlog::level::trace);
        s_appLogger->flush_on(spdlog::level::trace);
    }
}