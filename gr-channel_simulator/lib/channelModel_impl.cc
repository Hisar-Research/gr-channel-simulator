/* -*- c++ -*- */
/*
 * Copyright 2024 Omer Lutfu Karakelle.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "channelModel_impl.h"
#include <fstream>
#include <gnuradio/filter/fir_filter.h>
#include <cstdlib>
#include <chrono>

namespace gr {
  namespace channel_simulator {

    using input_type = gr_complex;
    using output_type = gr_complex;
    channelModel::sptr
    channelModel::make(int decimation, std::vector<float> taps)
    {
      return gnuradio::make_block_sptr<channelModel_impl>(
        decimation, taps);
    }


    /*
     * The private constructor
     */
    channelModel_impl::channelModel_impl(int decimation, std::vector<float> taps)
      : gr::sync_decimator("channelModel",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)), decimation),
              infile("/home/user/Masaüstü/taps.txt")
    {
      std::locale::global(std::locale("en_US.UTF-8"));
      std::vector<float> d_taps = get_next_taps(infile);
      old_time = get_time_ms();

      d_fir_ccf = new filter::kernel::fir_filter<gr_complex, gr_complex, float>(d_taps);
      taps = d_taps;
      d_updated = false;

    	this->set_history(d_fir_ccf->ntaps());

      const int d_pad = volk_get_alignment() / sizeof(float);
      set_alignment(std::max(1, d_pad));

    }

    /*
     * Our virtual destructor.
     */
    channelModel_impl::~channelModel_impl()
    {
    }

    int64_t channelModel_impl::get_time_ms()
    {
      auto now = std::chrono::high_resolution_clock::now();
      int64_t ms = std::chrono::duration_cast<std::chrono::milliseconds> (now.time_since_epoch()).count();
      return ms;
    }

    std::vector<float> channelModel_impl::get_next_taps(std::ifstream &infile)
    {
      std::string line;
      std::string tap;
      std::getline(infile, line);
      std::stringstream ss(line);
      std::vector<float> vec;

      while (std::getline(ss, tap, ','))
      {
        vec.push_back(std::stof(tap));
      }
      std::cout << "Current Taps: ";
      for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
      std::cout << std::endl;
      
      return vec;
    }

    void channelModel_impl::set_taps(std::vector<float> taps)
    {
      //gr::thread::scoped_lock l(this->d_setlock);
      d_fir_ccf->set_taps(taps);
      d_updated = true;
    }
    
    int64_t channelModel_impl::get_old_time(){
      return old_time;
    }

    int64_t channelModel_impl::get_current_time(){
      return current_time;
    }

    std::vector<float> channelModel_impl::taps() const
    {
      return d_fir_ccf->taps();
    }

    int
    channelModel_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      gr::thread::scoped_lock l(this->d_setlock);

      const gr_complex *in = static_cast<const input_type*>(input_items[0]);
      gr_complex *out = static_cast<output_type*>(output_items[0]);

      avail += noutput_items;
      if (avail >= 100000)
      {
        avail = 0;
        current_time = get_time_ms();
        if (current_time - old_time >= 10000)
        {
          this->set_taps(get_next_taps(this->infile));
          old_time = current_time;
        }
      }

      if (d_updated) {
        this->set_history(d_fir_ccf->ntaps());
        d_updated = false;
        return 0;
      }
    

      if (this->decimation() == 1)
        d_fir_ccf->filterN(out, in, noutput_items);
      else
        d_fir_ccf->filterNdec(out, in, noutput_items, this->decimation()); 

      // Tell runtime system how many output items we produced.
      std::cout << noutput_items << std::endl;
      return noutput_items;
    }

  } /* namespace channel_simulator */
} /* namespace gr */
