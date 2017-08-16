#ifndef _LIBUSB_HPP_
#define _LIBUSB_HPP_

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <hidapi/hidapi.h>
#include "../hid/hid.hpp"

class USB : public HostInterfaceDevice
{
 public:
    USB();
    virtual ~USB();
 private:

};

#endif //_LIBUSB_HPP_
