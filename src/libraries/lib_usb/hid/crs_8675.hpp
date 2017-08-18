#ifndef _BT8675_HPP_
#define _BT8675_HPP_

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>

#include "hid.hpp"

class CRS8675 : public HostInterfaceDevice
{
 public:
  CRS8675();
  virtual ~CRS8675();

 private:
  int _CSR8675NormalModeInit();
  int _CSR8675NormalModeCleanUp();

 private:
  unsigned int kVendorId{0x05};
  unsigned int kProductId{0x03};

};

#endif //_BT8675_HPP_
