//
// Created by Sandesh Ghimire on 8/16/17.
//

#ifndef _HID_HPP_
#define _HID_HPP_

#include <iostream>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <hidapi/hidapi.h>
#include <pthread.h>

class HostInterfaceDevice
{
 public:
  HostInterfaceDevice();
  virtual ~HostInterfaceDevice();
  int Read(std::string data);
  int Write(std::string data);
  unsigned int _GetVendorID() const;
  unsigned int _GetProductID() const;
  int ReadTimeout(std::string data, unsigned int timeout);

 protected:
  int _Open();
  int _Init();
  void _Exit();
  void _Close();
  int _SetBlocking();
  void _FreeEnumerate();
  void _SetNonBlocking();
  int _GetProductString();
  int _GetIndexedString();
  int _GetManufacturerString();
  int _GetSerialNumberString();
  int _OpenPath(std::string path);
  int _GetFeatureReport(std::string data);
  int _SendFeatureReport(std::string data);
  int _Enumerate(unsigned int vendorId, unsigned int productId);
  void _SetVendorID(unsigned int _vendorID);
  void _SetProductID(unsigned int _productID);
  unsigned char _HexChar(char input);
 protected:
  unsigned int _initialized = {0};

 private:
  pthread_mutex_t _hidMutex;
  hid_device *_handle;
  hid_device_info *_devices;
  std::string _manufacturerName;
  std::string _productName;
  std::string _serialNumber;
  std::string _indexed;
  unsigned int _vendorID{0x0A12};
  unsigned int _productID{0x1004};
  unsigned char _readBuffer[255];
  unsigned char _writeBuffer[255];

};

#endif //_HID_HPP_
