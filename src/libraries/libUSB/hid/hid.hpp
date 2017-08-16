//
// Created by Sandesh Ghimire on 8/16/17.
//

#ifndef HARDWAREVERIFICATION_HID_HPP
#define HARDWAREVERIFICATION_HID_HPP

#include <iostream>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <hidapi/hidapi.h>

class HostInterfaceDevice {
 public:
  HostInterfaceDevice();
  virtual ~HostInterfaceDevice();
 protected:
  void init();
  void exit();
  int enumerate();
  int freeEnumerate();
  int open();
  int close();
  int getManufacturerString();
  int getProductString();
  int getSerialNumberString();
  int getIndexedString();
  int setNonBlocking();
  int setBlocking();
  int read();
  int write();
  int sendFeatureReport();
  int getFeatureReport();

 private:
  hid_device_info *_devices;
  hid_device_info *_currentDevice;
  int _hidInitFlag;
  static const int kEnumerationValue {0x0};
};

#endif //HARDWAREVERIFICATION_HID_HPP
