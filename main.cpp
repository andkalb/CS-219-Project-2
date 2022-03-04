/**
* Main driver for the ALU - project 2 CS 219
* @file main.cpp
* @author Andrew Kalb
* @version 1.0 1/28/2022
*/


#include <iostream>
#include <fstream>
#include <string>
#include "AssemblyTools.h"

int main()
{
   std::ifstream f("commands.txt");
   if (f)
   {
      std::string line = "";
      while (std::getline(f, line))
      {
         std::string op = "";
         std::vector<std::string> params;
         bool operatorFound = false;

         std::string word = "";
         // NOTE: capture following loop in a function
         for (int i = 0; i < line.length(); i++)
         {
            if (line.at(i) != ' ')
            {
               word += line.at(i);
            }
            else if (!word.empty())
            {
               if (operatorFound)
               {
                  params.push_back(word);
               }
               else
               {
                  op = word;
                  operatorFound = true;
               }
               word = "";
            }
         }   
         if (!word.empty())
         {
            params.push_back(word);
         }

         if (op == "ADD")
         {
            if(params.size() > 1)
            {
               std::cout << "ADDing ";
               for(int i = 0; i < 2; i++)
               {
                  std::cout << params.at(i) << " ";
               }
               std::cout << "= " << AssemblyTools::Add(*(params.begin()), *(params.begin() + 1)) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for ADD." << std::endl;
            }
         }
         else if(op == "AND")
         {
            if(params.size() > 1)
            {
               std::cout << "Bitwise ANDing ";
               for(int i = 0; i < 2; i++)
               {
                  std::cout << params.at(i) << " ";
               }
               std::cout << "= " << AssemblyTools::And(*(params.begin()), *(params.begin() + 1)) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for AND." << std::endl;
            }
         }
         else if(op == "ASR")
         {
            if(params.size() > 0)
            {
               std::cout << "ASRing ";
               std::cout << params.at(0) << " ";
               std::cout << "= " << AssemblyTools::Asr(*(params.begin())) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for ASR." << std::endl;
            }         
         }
         else if(op == "LSR")
         {
            if(params.size() > 0)
            {
               std::cout << "LSRing ";
               std::cout << params.at(0) << " ";
               std::cout << "= " << AssemblyTools::Lsr(*(params.begin())) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for LSR." << std::endl;
            }         }
         else if(op == "LSL")
         {
            if(params.size() > 0)
            {
               std::cout << "LSLing ";
               std::cout << params.at(0) << " ";
               std::cout << "= " << AssemblyTools::Lsl(*(params.begin())) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for LSL." << std::endl;
            }         }
         else if(op == "NOT")
         {
            if(params.size() > 0)
            {
               std::cout << "Bitwise NOTing ";
               std::cout << params.at(0) << " ";
               std::cout << "= " << AssemblyTools::Not(*(params.begin())) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for NOT." << std::endl;
            }
         }
         else if(op == "ORR")
         {
            if(params.size() > 1)
            {
               std::cout << "Bitwise ORRing ";
               unsigned int count = 0;
               for(std::vector<std::string>::iterator it = params.begin(); count < 2 && it != params.end(); it++)
               {
                  std::cout << *it << " ";
                  count++;
               }
               std::cout << "= " << AssemblyTools::Orr(*(params.begin()), *(params.begin() + 1)) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for ORR." << std::endl;
            }
         }
         else if(op == "SUB")
         {
            if(params.size() > 1)
            {
               std::cout << "SUBing ";
               for(int i = 0; i < 2; i++)
               {
                  std::cout << params.at(i) << " ";
               }
               std::cout << "= " << AssemblyTools::Sub(*(params.begin()), *(params.begin() + 1)) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for SUB." << std::endl;
            }
         }
         else if(op == "XOR")
         {
            if(params.size() > 1)
            {
               std::cout << "Bitwise XORing ";
               for(int i = 0; i < 2; i++)
               {
                  std::cout << params.at(i) << " ";
               }
               std::cout << "= " << AssemblyTools::Xor(*(params.begin()), *(params.begin() + 1)) << std::endl;
            }
            else
            {
               std::cout << "Not enough arguments for XOR." << std::endl;
            }
         }
         else 
         {
            std::cout << "OPCODE not understood." << std::endl;
         }
      }
   }
   else
   {
      std::cout << "File not found" << std::endl;
   }
}