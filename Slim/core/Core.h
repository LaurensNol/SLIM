/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
 *  Core.h
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

#ifndef SLIM_CORE_H
#define SLIM_CORE_H

#include <assert.h>

#include <spdlog/spdlog.h>

#define SLIM_CORE_ASSERT(cond, msg) { if(!(cond)) { coreAssert(#cond, __FILE__, __LINE__, msg); } }

inline void coreAssert(const char* expr_str, const char* file, int line, const char* msg)
{
    spdlog::error("Assertion Failed: {0}\n\t{1}\n\tin: {2}, line {3}", msg, expr_str, file, line);

    abort();
}

#endif