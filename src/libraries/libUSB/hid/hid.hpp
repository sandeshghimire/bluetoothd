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

class HostInterfaceDevice
{
 public:
  HostInterfaceDevice();
  virtual ~HostInterfaceDevice();
  int read(std::string data);
  int write(std::string data);
  int read(std::string data, unsigned int length);
  int write(unsigned int length);
  int readTimeout(std::string data, unsigned int timeout);
  void setVendorID(unsigned int _vendorID);
  void setProductID(unsigned int _productID);

 protected:
  int _open();
  void _init();
  void _exit();
  void _close();
  int _setBlocking();
  void _freeEnumerate();
  void _setNonBlocking();
  int _getProductString();
  int _getIndexedString();
  int _getManufacturerString();
  int _getSerialNumberString();
  int _openPath(std::string path);
  unsigned int _get_vendorID() const;
  unsigned int _get_productID() const;
  int _getFeatureReport(std::string data);
  int _sendFeatureReport(std::string data);
  int _enumerate(unsigned int vendorId, unsigned int productId);

 protected:
  unsigned int _initialized = 0;

 private:
  hid_device *_handle;
  hid_device_info *_devices;
  std::string _manufacturerString;
  std::string _productString;
  std::string _serialNumberString;
  std::string _indexedString;
  std::string _readBuffer;
  std::string _writeBuffer;
  unsigned int _vendorID;
  unsigned int _productID;

};

#endif //_HID_HPP_
