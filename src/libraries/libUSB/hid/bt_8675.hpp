#ifndef _BT8675_HPP_
#define _BT8675_HPP_

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>

#include "hid.hpp"

class BT8675 : public HostInterfaceDevice
{
 public:
    BT8675();
    virtual ~BT8675();
 private:

};

#endif //_BT8675_HPP_
