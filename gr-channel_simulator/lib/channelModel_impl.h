/* -*- c++ -*- */
/*
 * Copyright 2024 Omer Lutfu Karakelle.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CHANNEL_SIMULATOR_CHANNELMODEL_IMPL_H
#define INCLUDED_CHANNEL_SIMULATOR_CHANNELMODEL_IMPL_H

#include <gnuradio/channel_simulator/channelModel.h>
#include <gnuradio/filter/fir_filter.h>
#include <fstream>


namespace gr {
  namespace channel_simulator {

    class channelModel_impl : public channelModel
    {
     private:
      // Nothing to declare in this block.
      filter::kernel::fir_filter<gr_complex, gr_complex, float> *d_fir_ccf;
      bool d_updated;
      int64_t old_time;
      int64_t current_time;
      std::ifstream infile;

     public:
      channelModel_impl(int decimation, std::vector<float> taps);
      ~channelModel_impl();
      
      std::vector<float> taps() const override;
      void set_taps(std::vector<float> taps) override;
      std::vector<float> get_next_taps(std::ifstream &infile);
      int64_t get_time_ms();
      int64_t get_old_time();
      int64_t get_current_time();
      int avail;
      

      // Where all the action really happens
      int work(
              int noutput_items,
              gr_vector_const_void_star &input_items,
              gr_vector_void_star &output_items
      );
    };

  } // namespace channel_simulator
} // namespace gr

#endif /* INCLUDED_CHANNEL_SIMULATOR_CHANNELMODEL_IMPL_H */
