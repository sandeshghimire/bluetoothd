
#ifndef _BLUETOOTH_MAIN_HPP_
#define _BLUETOOTH_MAIN_HPP_

#include "bluetooth.hpp"
#include "bluetooth_controller_service_delegate.hpp"

class BluetoothManager;

class BluetoothManager
{
 public:
    BluetoothManager();
    virtual ~BluetoothManager();
 private:
    unsigned char _state;


};

#endif //_BLUETOOTH_MAIN_HPP_
