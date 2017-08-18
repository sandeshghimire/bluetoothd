//
// Created by Sandesh Ghimire on 8/14/17.
//

#include "bt_8675.hpp"

BT8675::BT8675()
{
  if (!_initialized )
  {
    if(!_init())
    {
      _devices =  _enumerate(kVendorId, kProductId);
      handle = hid_open(kVendorId, kProductId, NULL);
      if(!handle)
      {
        // TODOD log hid open fail
      }

    }
    else
    {
      // TODO log init failed
    }
    _initialized = 1;

  }
  else
  {
    // TODO log already initialized
  }


}
BT8675::~BT8675()
{
  _freeEnumerate(_devices);
  _initialized = 0;
}
