//
// Created by Sandesh Ghimire on 8/14/17.
//

#include "crs_8675.hpp"

CRS8675::CRS8675()
{
  _CSR8675NormalModeInit();

}
CRS8675::~CRS8675()
{
  _CSR8675NormalModeCleanUp();

}
int CRS8675::_CSR8675NormalModeInit()
{
  if (_initialized == 0) {
    if (-1 == _Init()) {
      std::cout << " HID init failed " << std::endl;
      //TODO:: log device already initialized
    } else {
      if (-1 == _Open()) {
        std::cout << " Fail to open HID device  " << std::endl;
        //TODO:: log device already initialized
      }
    }
    _Enumerate(0x00, 0x00);
    _FreeEnumerate();
  } else {
    //TODO:: log device already initialized
  }
  return 0;
}
int CRS8675::_CSR8675NormalModeCleanUp()
{
  if (_initialized == 1) {
    _Close();
    _Exit();
    _initialized = 0;
  }
  return 0;
}
