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

#ifndef MODULE_CONFIGURABLE_HPP
#define MODULE_CONFIGURABLE_HPP

#include <tuple>

#include <boost/config.hpp>

namespace nil {
    namespace module {
        template<typename... OptionsTypes>
        struct optionable;

        template<typename ThisType, typename... RemainingTypes>
        struct optionable<ThisType, RemainingTypes...> : optionable<RemainingTypes...> {

            virtual void set_options(ThisType &cfg) const = 0;
        };

        template<typename ThisType>
        struct optionable<ThisType> {

            virtual void set_options(ThisType &cfg) const = 0;
        };

        template<typename ConfigurationType, typename... OptionsTypes>
        struct BOOST_SYMBOL_VISIBLE configurable : public optionable<configurable<OptionsTypes...>, OptionsTypes...> {
            typedef std::tuple<OptionsTypes...> options_types;
            typedef ConfigurationType configuration_type;

            virtual void initialize(configuration_type &options) = 0;
        };
    }    // namespace module
}    // namespace nil

#endif    // DBMS_CONFIGURABLE_HPP
