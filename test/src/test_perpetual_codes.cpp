// Copyright Steinwurf ApS 2015.
// Distributed under the "STEINWURF EVALUATION LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include <kodocpp/kodocpp.hpp>

#include <gtest/gtest.h>

#include "test_helper.hpp"

TEST(test_perpetual_codes, basic_api)
{
    using namespace kodocpp;

    if (has_codec(codec::perpetual) == false)
        return;

    uint32_t max_symbols = rand_symbols();
    uint32_t max_symbol_size = rand_symbol_size();

    test_basic_api(codec::perpetual, max_symbols, max_symbol_size);
}
