#include "hid.hpp"

HostInterfaceDevice::HostInterfaceDevice()
{

}
HostInterfaceDevice::~HostInterfaceDevice()
{
}

int HostInterfaceDevice::_init()
{
  return( hid_init());
}

void HostInterfaceDevice::_exit()
{
  hid_exit();
}

int HostInterfaceDevice::_enumerate(unsigned int vendorId, unsigned int productId)
{
  _devices = hid_enumerate(vendorId, productId);
}

void HostInterfaceDevice::_freeEnumerate()
{
  hid_free_enumeration(_devices);
}

int HostInterfaceDevice::_open()
{
  _handle = hid_open(_vendorID, _productID, NULL);
  return 0;

}

void HostInterfaceDevice::_close()
{
  hid_close(_handle);
}

int HostInterfaceDevice::_getManufacturerString()
{
  return (hid_get_manufacturer_string(_handle, (wchar_t *) _manufacturerName.c_str(), 255));
}

int HostInterfaceDevice::_getProductString()
{
  return (hid_get_product_string(_handle, (wchar_t *) _productName.c_str(), 255));
}

int HostInterfaceDevice::_getSerialNumberString()
{
  return (hid_get_serial_number_string(_handle, (wchar_t *) _serialNumber.c_str(), 255));
}

int HostInterfaceDevice::_getIndexedString()
{
  return (hid_get_indexed_string(_handle, 1, (wchar_t *) _indexed.c_str(), 255));
}

void HostInterfaceDevice::_setNonBlocking()
{
  hid_set_nonblocking(_handle, 1);
}

int HostInterfaceDevice::_setBlocking()
{
  hid_set_nonblocking(_handle, 0);
}

int HostInterfaceDevice::read(std::string data, unsigned int length)
{
  data.clear();
  return (hid_read(_handle, (unsigned char *) data.c_str(), length));
}

int HostInterfaceDevice::write(std::string data, unsigned int length)
{

  data.clear();
  return (hid_read(_handle, (unsigned char *) data.c_str(), length));
}

int HostInterfaceDevice::_sendFeatureReport(std::string data)
{
  return (hid_get_feature_report(_handle, (unsigned char *) data.c_str(), data.length()));
}

int HostInterfaceDevice::read(std::string data)
{
  data.clear();
  return (hid_read(_handle, (unsigned char *) data.c_str(), data.length()));
}

int HostInterfaceDevice::write(std::string data)
{
  return (hid_write(_handle, (unsigned char *) data.c_str(), data.length()));
}
unsigned int HostInterfaceDevice::_get_vendorID() const
{
  return _vendorID;
}
void HostInterfaceDevice::_setVendorID(unsigned int _vendorID)
{
  HostInterfaceDevice::_vendorID = _vendorID;
}
unsigned int HostInterfaceDevice::_get_productID() const
{
  return _productID;
}
void HostInterfaceDevice::_setProductID(unsigned int _productID)
{
  HostInterfaceDevice::_productID = _productID;
}
int HostInterfaceDevice::_openPath(std::string path)
{
  _handle = hid_open_path((const char *) path.c_str());
}
int HostInterfaceDevice::readTimeout(std::string data, unsigned int timeout)
{
  hid_read_timeout(_handle, (unsigned char *) data.c_str(), data.length(), timeout);
}
int HostInterfaceDevice::_getFeatureReport(std::string data)
{
  return (hid_get_feature_report(_handle, (unsigned char *) data.c_str(), data.length()));
}

