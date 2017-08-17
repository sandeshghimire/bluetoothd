//
// Created by Sandesh Ghimire on 8/14/17.
//

#include "bt_8675.hpp"

BT8675::BT8675()
{
  if(!_initialized)
  {
    _initialized = 1;
  }
  else
  {

  }

}
BT8675::~BT8675()
{
  _initialized = 0;
}

