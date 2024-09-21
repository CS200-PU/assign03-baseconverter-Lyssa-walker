//******************************************************************************
// File name:   main.cpp
// Author:      Nilyssa Walker
// Date:        09/13/2024
// Class:       CS200-01
// Assignment:  Base Converter
// Purpose:     a C++ program in Codespaces that automatically converts a number 
//              in a specified base to equivalent numbers in the other two bases
// Hours:       
//******************************************************************************

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

/****************************************************************************
  Function: hexCharToInt
  Description: converts a hexidecimal character or number and turns it into a 
               decimal number
  Parameters: hexDigit - the hexidecimal being passed in
  
  Returned: int
****************************************************************************/
  int hexCharToInt (char hexDigit){
    int decimalValue = 0;
   
    if (hexDigit >= '0' && hexDigit <= '9') {
            decimalValue = hexDigit - '0';  
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            decimalValue = hexDigit - 'A' + 10;  
        }

    return decimalValue;
  }

  /****************************************************************************
  Function: getBase
  Description: determinse whether the base is a decimal, hexadecimal or binary
  Parameters: strNumber - the base being passed in
  
  Returned: char
****************************************************************************/
char getBase (const string& strNumber){
  

  if (strNumber.substr(0, 2) == "0x" || strNumber.substr(0, 2) == "0X") {
        return 'H';  
    }
    
    
    if (strNumber.substr(0, 2) == "0b" || strNumber.substr(0, 2) == "0B") {
        return 'B';  
    }

    
    return 'D';  

  
}

/****************************************************************************
  Function: getNumber
  Description: 
  Parameters: prompt - the prompt to print to the screen
  
  Returned: String
****************************************************************************/
string getNumber (const string& prompt){
  string userNum;

    cout << prompt;
    cin >> userNum;

    return userNum; 
}

/****************************************************************************
  Function: printTitle 
  Description: takes in a title and prints to the screen
  Parameters: myTitle - the title given in main
  
  Returned: none
****************************************************************************/
void printTitle(const string& myTitle){
  cout << myTitle;
}

/****************************************************************************
  Function: binaryToDecimal
  Description: converts a binary number to a decimal
  Parameters: strNumber - string representing a binary number
  
  Returned: String
****************************************************************************/
string binaryToDecimal (const string& strNumber){
  int decimalValue = 0;
  string binaryNumber = strNumber;

   binaryNumber = binaryNumber.substr(2);

   for (size_t i = 0; i < binaryNumber.length(); ++i) {
        char bit = binaryNumber[i];
        decimalValue = decimalValue * 2 + (bit - '0');
    }

    
    return to_string(decimalValue); 

}

/****************************************************************************
  Function: decimalToBinary
  Description: turning a decimal number into a binary
  Parameters: strNumber - string representing a decimal
  
  Returned: String
****************************************************************************/
string decimalToBinary (const string& strNumber){
  int decimalNumber;
  std::stringstream(strNumber) >> decimalNumber;
  string binaryResult = "";
    
    // Special case for decimal 0
    if (decimalNumber == 0) {
        return "0";
    }    

    // Convert decimal number to binary
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;  // Get the remainder when divided by 2
        binaryResult = std::to_string(remainder) + binaryResult;  // Build the binary string from the right
        decimalNumber /= 2;  // Divide the decimal number by 2
    }

    return binaryResult;
}

/****************************************************************************
  Function: decimalToHex
  Description: turning a decimal number into a hexidecimal
  Parameters: strNumber - string representing a decimal
  
  Returned: String
****************************************************************************/
string decimalToHex(const string& strNumber){
 string hexValue;



  return hexValue;
}

int main () {




  
  return EXIT_SUCCESS;
}