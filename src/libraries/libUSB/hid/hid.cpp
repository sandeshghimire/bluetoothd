//
// Created by Sandesh Ghimire on 8/16/17.
//

#include "hid.hpp"

HostInterfaceDevice::HostInterfaceDevice()
    : _devices(nullptr), _currentDevice(nullptr), _hidInitFlag(-1) {}
HostInterfaceDevice::~HostInterfaceDevice() {
}

void HostInterfaceDevice::init() {
  if (!_hidInitFlag) {
    _hidInitFlag = hid_init();
  } else {
    std::cout << "HID already initilized" << std::endl;
  }
}
void HostInterfaceDevice::exit() {

}
int HostInterfaceDevice::enumerate() {
  _devices = hid_enumerate(kEnumerationValue, kEnumerationValue);
  if (!_devices) {
    std::cout << "Failed to enumerate" << std::endl;
  }
}
int HostInterfaceDevice::freeEnumerate() {
  return 0;
}
int HostInterfaceDevice::open() {
  return 0;
}
int HostInterfaceDevice::close() {
  return 0;
}
int HostInterfaceDevice::getManufacturerString() {
  return 0;
}
int HostInterfaceDevice::getProductString() {
  return 0;
}
int HostInterfaceDevice::getSerialNumberString() {
  return 0;
}
int HostInterfaceDevice::getIndexedString() {
  return 0;
}
int HostInterfaceDevice::setNonBlocking() {
  return 0;
}
int HostInterfaceDevice::setBlocking() {
  return 0;
}
int HostInterfaceDevice::read() {
  return 0;
}
int HostInterfaceDevice::write() {
  return 0;
}
int HostInterfaceDevice::sendFeatureReport() {
  return 0;
}
int HostInterfaceDevice::getFeatureReport() {
  return 0;
}

