#include "crs_8675.hpp"

HostInterfaceDevice::HostInterfaceDevice()
{
}
HostInterfaceDevice::~HostInterfaceDevice()
{
}

int HostInterfaceDevice::_Init()
{
  return (hid_init());
}

void HostInterfaceDevice::_Exit()
{
  hid_exit();
}

int HostInterfaceDevice::_Enumerate(unsigned int vendorId, unsigned int productId)
{
  _devices = hid_enumerate(vendorId, productId);
}

void HostInterfaceDevice::_FreeEnumerate()
{
  hid_free_enumeration(_devices);
}

int HostInterfaceDevice::_Open()
{
  _handle = hid_open(_vendorID, _productID, NULL);
  return 0;

}

void HostInterfaceDevice::_Close()
{
  hid_close(_handle);
}

int HostInterfaceDevice::_GetManufacturerString()
{
  return (hid_get_manufacturer_string(_handle, (wchar_t *) _manufacturerName.c_str(), 255));
}

int HostInterfaceDevice::_GetProductString()
{
  return (hid_get_product_string(_handle, (wchar_t *) _productName.c_str(), 255));
}

int HostInterfaceDevice::_GetSerialNumberString()
{
  return (hid_get_serial_number_string(_handle, (wchar_t *) _serialNumber.c_str(), 255));
}

int HostInterfaceDevice::_GetIndexedString()
{
  return (hid_get_indexed_string(_handle, 1, (wchar_t *) _indexed.c_str(), 255));
}

void HostInterfaceDevice::_SetNonBlocking()
{
  hid_set_nonblocking(_handle, 1);
}

int HostInterfaceDevice::_SetBlocking()
{
  hid_set_nonblocking(_handle, 0);
}

int HostInterfaceDevice::_SendFeatureReport(std::string data)
{
  return (hid_get_feature_report(_handle, (unsigned char *) data.c_str(), data.length()));
}

int HostInterfaceDevice::Read(std::string data)
{
  int rc = 0;
  data.clear();
  memset(_readBuffer, 0, sizeof(_readBuffer));
  pthread_mutex_lock(&_hidMutex);
  rc = (hid_read(_handle, _readBuffer, sizeof(_readBuffer)));
  pthread_mutex_unlock(&_hidMutex);
  return rc;
}

int HostInterfaceDevice::Write(std::string data)
{
  unsigned int writeBufferCounter = 0;
  for (int i = 0; i < data.length(); i += 2) {
    _writeBuffer[writeBufferCounter++] = (((_HexChar(data.c_str()[i])) & 0x0F) << 4) | (_HexChar(data.c_str()[i + 1]));
  }
  std::cout << "input string  " << data << std::endl;

  pthread_mutex_lock(&_hidMutex);
  int rc = hid_write(_handle, _writeBuffer, writeBufferCounter);
  pthread_mutex_unlock(&_hidMutex);
  return rc;
}
unsigned int HostInterfaceDevice::_GetVendorID() const
{
  return _vendorID;
}
void HostInterfaceDevice::_SetVendorID(unsigned int _vendorID)
{
  HostInterfaceDevice::_vendorID = _vendorID;
}
unsigned int HostInterfaceDevice::_GetProductID() const
{
  return _productID;
}
void HostInterfaceDevice::_SetProductID(unsigned int _productID)
{
  HostInterfaceDevice::_productID = _productID;
}
int HostInterfaceDevice::_OpenPath(std::string path)
{
  _handle = hid_open_path((const char *) path.c_str());
}
int HostInterfaceDevice::ReadTimeout(std::string data, unsigned int timeout)
{
  hid_read_timeout(_handle, (unsigned char *) data.c_str(), data.length(), timeout);
}
int HostInterfaceDevice::_GetFeatureReport(std::string data)
{
  return (hid_get_feature_report(_handle, (unsigned char *) data.c_str(), data.length()));
}

unsigned char HostInterfaceDevice::_HexChar(char input)
{
  if ('0' <= input && input <= '9') return (unsigned char) (input - '0');
  if ('A' <= input && input <= 'F') return (unsigned char) (input - 'A' + 10);
  if ('a' <= input && input <= 'f') return (unsigned char) (input - 'a' + 10);
  return 0xFF;
}