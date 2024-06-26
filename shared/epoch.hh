// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2024, QFort Contributors
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
#ifndef CORE_EPOCH_HH
#define CORE_EPOCH_HH
#include <stdint.h>

namespace epoch
{
uint64_t microseconds(void);
uint64_t milliseconds(void);
uint64_t seconds(void);
} // namespace epoch

#endif /* CORE_EPOCH_HH */
