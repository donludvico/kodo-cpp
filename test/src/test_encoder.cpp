// Copyright Steinwurf ApS 2014.
// Distributed under the "STEINWURF EVALUATION LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include <kodocpp/encoder.hpp>

#include <cstdint>

#include <gtest/gtest.h>

#include "test_helper.hpp"

namespace kodocpp
{
static void test_encoder(uint32_t max_symbols, uint32_t max_symbol_size,
                         codec code, field field)
{
    encoder_factory encoder_factory(
        code,
        field,
        max_symbols,
        max_symbol_size);

    encoder encoder = encoder_factory.build();
    test_coder(encoder, max_symbols, max_symbol_size, code);

    // Encoder methods
    EXPECT_TRUE(encoder.has_write_payload());

    if (encoder.has_systematic_interface())
    {
        EXPECT_TRUE(encoder.is_systematic_on());
        encoder.set_systematic_off();
        EXPECT_FALSE(encoder.is_systematic_on());
        encoder.set_systematic_on();
        EXPECT_TRUE(encoder.is_systematic_on());
    }
}
}

TEST(test_encoder, invoke_api)
{
    using namespace kodocpp;

    uint32_t max_symbols = rand_symbols();
    uint32_t max_symbol_size = rand_symbol_size();

    test_combinations(test_encoder, max_symbols, max_symbol_size);
}
