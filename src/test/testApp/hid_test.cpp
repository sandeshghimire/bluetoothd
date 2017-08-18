#include <iostream>
#include <zconf.h>
#include "../../libraries/lib_usb/hid/crs_8675.hpp"

int main(int argc, char **argv)
{
  std::string input;
  std::string output;

  CRS8675 *crs8675 = new CRS8675();

  std::cout << "Vendor ID  " << crs8675->_GetVendorID() << std::endl;
  std::cout << "Product ID  " << crs8675->_GetProductID() << std::endl;

  while(1)
  {
    std::cin >> input;
    crs8675->Write(input);
    crs8675->Read(output);

    for(int i = 0; i < output.length(); i++)
    {
      printf("%X ", output.c_str()[i]);
    }

  }

  delete(crs8675);

  return 0;
}