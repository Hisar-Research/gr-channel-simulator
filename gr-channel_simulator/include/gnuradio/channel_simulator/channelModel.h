/* -*- c++ -*- */
/*
 * Copyright 2024 Omer Lutfu Karakelle.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CHANNEL_SIMULATOR_CHANNELMODEL_H
#define INCLUDED_CHANNEL_SIMULATOR_CHANNELMODEL_H

#include <gnuradio/channel_simulator/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace channel_simulator {

    /*!
     * \brief <+description of block+>
     * \ingroup channel_simulator
     *
     */
    class CHANNEL_SIMULATOR_API channelModel : virtual public gr::sync_decimator
    {
     public:
      typedef std::shared_ptr<channelModel> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of channel_simulator::channelModel.
       *
       * To avoid accidental use of raw pointers, channel_simulator::channelModel's
       * constructor is in a private implementation
       * class. channel_simulator::channelModel::make is the public interface for
       * creating new instances.
       */
      static sptr make(int decimation=4, std::vector<float> taps={1.0});
      virtual void set_taps(std::vector<float> taps) = 0;
      virtual std::vector<float> taps() const = 0;
    };

  } // namespace channel_simulator
} // namespace gr

#endif /* INCLUDED_CHANNEL_SIMULATOR_CHANNELMODEL_H */
