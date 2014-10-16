// Copyright Steinwurf ApS 2011-2013.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include "factory_interface.hpp"

namespace kodo
{
    class decoder_factory : public factory_interface
    {
    public:
        decoder_factory(kodo::algorithm algorithm,
                             kodo::fieldtype field_type,
                             uint32_t max_symbols,
                             uint32_t max_symbol_size,
                             bool trace_enabled)
        {
            if(algorithm == kodo_full_rlnc)
            {
                if(!trace_enabled)
                {
                    if(field_type == kodo::field_type.binary)
                    {
                        m_decoder_factory =
                            new kodo::full_rlnc_decoder<
                                fifi::binary>decoder_factory_wrapper();

                    }
                    else if(field_type == kodo::field_type.binary8)
                    {
                        m_decoder_factory =
                            new kodo::full_rlnc_decoder<
                                fifi::binar8y>decoder_factory_wrapper();
                    }
                    else if(field_type == kodo::field_type.binary16)
                    {
                        m_decoder_factory =
                            new kodo::full_rlnc_decoder<
                                fifi::binary16>decoder_factory_wrapper();
                    }
                }
                else{
                    if(field_type == kodo::field_type.binary)
                    {
                        m_decoder_factory =
                            new kodo::full_rlnc_decoder<
                                fifi::binary, kodo::enable_trace>
                            decoder_factory_wrapper();

                    }
                    else if(field_type == kodo::field_type.binary8)
                    {
                        m_decoder_factory =
                            new kodo::full_rlnc_decoder<
                                fifi::binar8y, kodo::enable_trace>
                            decoder_factory_wrapper();
                    }
                    else if(field_type == kodo::field_type.binary16)
                    {
                        m_decoder_factory =
                            new kodo::full_rlnc_decoder<
                                fifi::binary16, kodo::enable_trace>
                            decoder_factory_wrapper();
                    }
                }
            }
            else if(algorithm == kodo_on_the_fly)
            {
                if(!trace_enabled)
                {
                    if(field_type == kodo::field_type.binary)
                    {
                        m_decoder_factory =
                            new kodo::on_the_fly_decoder<
                                fifi::binary>decoder_factory_wrapper();

                    }
                    else if(field_type == kodo::field_type.binary8)
                    {
                        m_decoder_factory =
                            new kodo::on_the_fly_decoder<
                                fifi::binar8y>decoder_factory_wrapper();
                    }
                    else if(field_type == kodo::field_type.binary16)
                    {
                        m_decoder_factory =
                            new kodo::on_the_fly_decoder<
                                fifi::binary16>decoder_factory_wrapper();
                    }
                }
                else{
                    if(field_type == kodo::field_type.binary)
                    {
                        m_decoder_factory =
                            new kodo::on_the_fly_decoder<
                                fifi::binary, kodo::enable_trace>
                            decoder_factory_wrapper();

                    }
                    else if(field_type == kodo::field_type.binary8)
                    {
                        m_decoder_factory =
                            new kodo::on_the_fly_decoder<
                                fifi::binar8y, kodo::enable_trace>
                            decoder_factory_wrapper();
                    }
                    else if(field_type == kodo::field_type.binary16)
                    {
                        m_decoder_factory =
                            new kodo::on_the_fly_decoder<
                                fifi::binary16, kodo::enable_trace>
                            decoder_factory_wrapper();
                    }
                }
            }
            else if(algorithm == kodo_sliding_window)
            {
                if(!trace_enabled)
                {
                    if(field_type == kodo::field_type.binary)
                    {
                        m_decoder_factory =
                            new kodo::sliding_window_decoder<
                                fifi::binary>decoder_factory_wrapper();

                    }
                    else if(field_type == kodo::field_type.binary8)
                    {
                        m_decoder_factory =
                            new kodo::sliding_window_decoder<
                                fifi::binar8y>decoder_factory_wrapper();
                    }
                    else if(field_type == kodo::field_type.binary16)
                    {
                        m_decoder_factory =
                            new kodo::sliding_window_decoder<
                                fifi::binary16>decoder_factory_wrapper();
                    }
                }
                else{
                    if(field_type == kodo::field_type.binary)
                    {
                        m_decoder_factory =
                            new kodo::sliding_window_decoder<
                                fifi::binary, kodo::enable_trace>
                            decoder_factory_wrapper();

                    }
                    else if(field_type == kodo::field_type.binary8)
                    {
                        m_decoder_factory =
                            new kodo::sliding_window_decoder<
                                fifi::binar8y, kodo::enable_trace>
                            decoder_factory_wrapper();
                    }
                    else if(field_type == kodo::field_type.binary16)
                    {
                        m_decoder_factory =
                            new kodo::sliding_window_decoder<
                                fifi::binary16, kodo::enable_trace>
                            decoder_factory_wrapper();
                    }
                }
            }
            assert(m_encoder_factory);
        }

        decoder_factory* decoder_factory()
        {
            return m_decoder_factory
        }

        decoder build()
        {
            return decoder(new decoder_wrapper(m_decoder_factory).build());
        }


        void set_symbols(uint32_t symbols)
        {
            m_factory_wrapper.set_symbols(symbols)
        }

        void set_symbol_size(uint32_t symbol_size)
        {
            m_factory_wrapper.set_symbol_size(symbol_size)
        }

        uint32_t max_symbols() const
        {
            return m_factory_wrapper.max_symbols();
        }

        uint32_t max_symbol_size() const
        {
            return m_factory_wrapper.max_symbol_size();
        }

        uint32_t max_block_size() const
        {
            return m_factory_wrapper.max_block_size();
        }

        uint32_t max_payload_size() const
        {
            return m_factory_wrapper.max_payload_size();
        }

    private:
        decoder_factory* m_decoder_factory;
    }

}