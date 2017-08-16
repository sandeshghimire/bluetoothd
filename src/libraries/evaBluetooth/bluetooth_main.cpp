#include "bluetooth_main.hpp"

BluetoothMain::BluetoothMain()
{

}
BluetoothMain::~BluetoothMain()
{

}
unsigned char BluetoothMain::get_state() const
{
    return _state;
}
void BluetoothMain::set_state(unsigned char _state)
{
    BluetoothMain::_state = _state;
}
int BluetoothMain::run()
{
    return 0;
}
int BluetoothMain::stop()
{
    return 0;
}
