#include <iostream>
#include <zconf.h>
#include "../../libraries/libUSB/hid/crs_8675.hpp"

int main(int argc, char **argv)
{
  std::string input;
  std::string output;

  CRS8675 *crs8675 = new CRS8675();

  while(1)
  {
    std::cin >> input;
    crs8675->Write(input);
    std::cout << "Input value is " << input << std::endl;
    crs8675->Read(output);
    std::cout << "Return value is " << output << std::endl;
  }

  delete(crs8675);

  return 0;
}