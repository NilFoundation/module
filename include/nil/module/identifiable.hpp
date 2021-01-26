//----------------------------------------------------------------------------
// Copyright (C) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Server Side Public License, version 1,
// as published by the author.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Server Side Public License for more details.
//
// You should have received a copy of the Server Side Public License
// along with this program. If not, see
// <https://github.com/NilFoundation/plugin/blob/master/LICENSE_1_0.txt>.
//----------------------------------------------------------------------------

#ifndef MODULE_IDENTIFIABLE_HPP
#define MODULE_IDENTIFIABLE_HPP

#include <cstdint>

namespace nil {
    namespace module {
        template<typename IdentifierType = uint32_t>
        struct identifiable {
            typedef IdentifierType id_type;

            virtual id_type id() const = 0;
        };
    }    // namespace module
}    // namespace nil

#endif    // DBMS_PLUGIN_HPP
