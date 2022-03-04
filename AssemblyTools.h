#ifndef ASSEMBLY_TOOLS_H
#define ASSEMBLY_TOOLS_H

#include <iostream>
#include <vector>

class AssemblyTools
{
public:
   static std::string Add(std::string hex1, std::string hex2);
   static std::string And(std::string hex1, std::string hex2);
   static std::string Orr(std::string hex1, std::string hex2);
   static std::string Asr(std::string hex1);
   static std::string Lsr(std::string hex1);
   static std::string Lsl(std::string hex1);
   static std::string Not(std::string hex1);
   static std::string Sub(std::string hex1, std::string hex2);
   static std::string Xor(std::string hex1, std::string hex2);

private:
   static unsigned int ConvertStringHexToUnsignedInt(std::string hex);
   static std::string ConvertUnsignedIntToStringHex(unsigned int val);
};

#endif