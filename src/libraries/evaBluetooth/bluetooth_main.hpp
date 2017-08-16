
#ifndef _BLUETOOTH_MAIN_HPP_
#define _BLUETOOTH_MAIN_HPP_

#include "eva_bluetooth.hpp"
#include "bluetooth_controller_service_delegate.hpp"

class BluetoothMain;

class BluetoothMain : public EvaBluetooth, public BluetoothControllerServiceDelegate
{
 public:
    BluetoothMain();
    virtual ~BluetoothMain();
    unsigned char get_state() const;
    void set_state(unsigned char _state);
    int run();
    int stop();

 private:
    unsigned char _state;


};

#endif //_BLUETOOTH_MAIN_HPP_
