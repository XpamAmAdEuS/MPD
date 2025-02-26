/*
 * Copyright 2003-2022 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "ParseName.hxx"
#include "util/ASCII.hxx"
#include "util/StringCompare.hxx"

#include <cassert>

#include <string.h>

TagType
tag_name_parse(std::string_view name) noexcept
{
	for (unsigned i = 0; i < TAG_NUM_OF_ITEM_TYPES; ++i) {
		assert(tag_item_names[i] != nullptr);

		if (name == tag_item_names[i])
			return (TagType)i;
	}

	return TAG_NUM_OF_ITEM_TYPES;
}

TagType
tag_name_parse_i(const char *name) noexcept
{
	assert(name != nullptr);

	for (unsigned i = 0; i < TAG_NUM_OF_ITEM_TYPES; ++i) {
		assert(tag_item_names[i] != nullptr);

		if (StringEqualsCaseASCII(name, tag_item_names[i]))
			return (TagType)i;
	}

	return TAG_NUM_OF_ITEM_TYPES;
}

TagType
tag_name_parse_i(std::string_view name) noexcept
{
	for (unsigned i = 0; i < TAG_NUM_OF_ITEM_TYPES; ++i) {
		assert(tag_item_names[i] != nullptr);

		if (StringIsEqualIgnoreCase(name, tag_item_names[i]))
			return (TagType)i;
	}

	return TAG_NUM_OF_ITEM_TYPES;
}
