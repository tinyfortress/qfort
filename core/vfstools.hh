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
#ifndef CORE_VFSTOOLS_HH
#define CORE_VFSTOOLS_HH
#include <physfs.h>
#include <stdint.h>
#include <string>
#include <vector>

namespace vfstools
{
const char *last_error(void);
bool read_file(const std::string &path, std::string &out);
bool read_file(const std::string &path, std::vector<uint8_t> &out);
bool write_file(const std::string &path, const std::string &data);
bool write_file(const std::string &path, const std::vector<uint8_t> &data);
} // namespace vfstools

#endif /* CORE_VFSTOOLS_HH */
