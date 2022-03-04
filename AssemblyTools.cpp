#include "AssemblyTools.h"
#include <sstream>

/** Adds two hex string numbers together
    @param hex1 The first hex number stored as a string
    @param hex2 The second hex number stored as a string
    @return a string that depicts the resulting hex number
*/
std::string AssemblyTools::Add(std::string hex1, std::string hex2)
{
   unsigned int addval = ConvertStringHexToUnsignedInt(hex1) + ConvertStringHexToUnsignedInt(hex2);
   return ConvertUnsignedIntToStringHex(addval);
}

std::string AssemblyTools::And(std::string hex1, std::string hex2)
{
   unsigned int andval = ConvertStringHexToUnsignedInt(hex1) & ConvertStringHexToUnsignedInt(hex2);
   return ConvertUnsignedIntToStringHex(andval);
}

std::string AssemblyTools::Orr(std::string hex1, std::string hex2)
{
   unsigned int orval = ConvertStringHexToUnsignedInt(hex1) | ConvertStringHexToUnsignedInt(hex2);
   return ConvertUnsignedIntToStringHex(orval);
}

std::string AssemblyTools::Asr(std::string hex1)
{
   unsigned int asrval = ConvertStringHexToUnsignedInt(hex1) >> 1;
   std::string result = ConvertUnsignedIntToStringHex(asrval);
   result.at(0) = hex1.at(0);
   return result;
}

std::string AssemblyTools::Lsr(std::string hex1)
{
   unsigned int lsrval = ConvertStringHexToUnsignedInt(hex1) >> 1;
   return ConvertUnsignedIntToStringHex(lsrval);
}

std::string AssemblyTools::Lsl(std::string hex1)
{
   unsigned int lslval = ConvertStringHexToUnsignedInt(hex1) << 1;
   return ConvertUnsignedIntToStringHex(lslval);
}

std::string AssemblyTools::Not(std::string hex1)
{
   unsigned int notval = ~ConvertStringHexToUnsignedInt(hex1);
   return ConvertUnsignedIntToStringHex(notval);
}

std::string AssemblyTools::Sub(std::string hex1, std::string hex2)
{
   unsigned int subval = ConvertStringHexToUnsignedInt(hex1) - ConvertStringHexToUnsignedInt(hex2);
   return ConvertUnsignedIntToStringHex(subval);
}

std::string AssemblyTools::Xor(std::string hex1, std::string hex2)
{
   unsigned int xorval = ConvertStringHexToUnsignedInt(hex1) ^ ConvertStringHexToUnsignedInt(hex2);
   return ConvertUnsignedIntToStringHex(xorval);
}



/** Private helper function that converts string hex to unsigned int 
   to perform math on.
   @param hex a string representation of a hex number to be converted
   @return unsigned int a workable version of the hex number
*/
unsigned int AssemblyTools::ConvertStringHexToUnsignedInt(std::string hex)
{
   unsigned int val = std::stoul(hex, nullptr, 16);
   return val;
}

/** Private helper function that converts unsigned int types back to
    hex in the form of a string for printing
    @param val unsigned int to be converted back to hex string
    @return string representation of a hex number
*/
std::string AssemblyTools::ConvertUnsignedIntToStringHex(unsigned int val)
{
   std::stringstream s;
   s << std::hex << val;
   std::string result = "0x" + s.str();
   return result;
}