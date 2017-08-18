//
// Created by Sandesh Ghimire on 8/14/17.
//

#include "crs_8675.hpp"

CRS8675::CRS8675()
{
  if(_initialized == 0) {
    if (-1 == _Init()) {
      std::cout << " HID init failed " << std::endl;
    } else {
      if (-1 == _Open()) {
        std::cout << " Fail to open HID device  " << std::endl;
      }
    }
    _SetBlocking();
  }
  else
  {
    //TODO:: log device already initialized
  }
}
CRS8675::~CRS8675()
{
  if(_initialized == 1)
  {
    _Close();
    _Exit();
    _initialized = 0;
  }
}
