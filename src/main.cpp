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
  cout << "*******************************\n" 
       << "*****" << myTitle << "*****\n"
       << "*******************************\n";
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
    
   
    if (decimalNumber == 0) {
        return "0";
    }    

   
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;  
        binaryResult = std::to_string(remainder) + binaryResult;  
        decimalNumber /= 2;  
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
    int decimalNumber;
    std::stringstream(strNumber) >> decimalNumber;
    std::stringstream hexValue;

    hexValue << "0x" << std::hex << std::uppercase << decimalNumber;

    return hexValue.str();
}

/****************************************************************************
  Function: hexToDecimal 
  Description: turning a hexadecimal number into a decimal
  Parameters: strNumber - string representing a hexadecimal being passed in
  
  Returned: String
****************************************************************************/
string hexToDecimal (const string& strNumber){
    int decimalVal;
    string hexNumber = strNumber;

    if (hexNumber.substr(0, 2) == "0x" || hexNumber.substr(0, 2) == "0X") {
        hexNumber = hexNumber.substr(2); 
    }

    
    std::stringstream hexVal;
    hexVal << std::hex << hexNumber; 
    hexVal >> decimalVal;         

    return to_string(decimalVal);  
}

/****************************************************************************
  Function: hexToBinary
  Description: turning a hexadecimal number into a binary number
  Parameters: strNumber - string representing a hexadecimal being passed in
  
  Returned: String
****************************************************************************/
string hexToBinary (const string& strNumber){
  string decimalNum;
  string binaryNum;


 decimalNum = hexToDecimal(strNumber);

 binaryNum = decimalToBinary(decimalNum);

 return binaryNum;
}


/****************************************************************************
  Function: binaryToHex 
  Description: turning a binary number into a hexidecimal
  Parameters: strNumber - string representing a binary number being passed in
  
  Returned: String
****************************************************************************/
string binaryToHex(const string& strNumber){
  string decimalNum;
std::stringstream hexNum;
  decimalNum = binaryToDecimal(strNumber);
  hexNum << decimalToHex(strNumber);

  return hexNum.str();
}



int main () {
  string userAnswer;
  bool proceed = true;
  char hexChar = 'H';
  char binaryChar = 'B';
  char decimalChar = 'D';
  char quit = 'q';
  

 printTitle("HEX-DECIMAL CONVERTER");

 while(proceed){

  cout << "Enter your string to convert (q to quit): ";
  cin >> userAnswer;

  if (userAnswer.at(0) == quit){
      proceed = false;
  }
  else if (getBase(userAnswer) == hexChar){
    cout << "The decimal conversion is: " << hexToDecimal(userAnswer) << "\n"; 
    cout << "The binary conversion is: " << "0b" << hexToBinary(userAnswer) << "\n\n";   
  }
  else if (getBase(userAnswer) == decimalChar){
    cout << "The binary conversion is: " << "0b" << decimalToBinary(userAnswer) << "\n";
    cout << "The hexadecimal conversion is: " << decimalToHex(userAnswer) << "\n\n";
  }
  else if (getBase(userAnswer) == binaryChar){
    cout << "The decimal conversion is: " << binaryToDecimal(userAnswer) << "\n";
    cout << "The hexadecimal is: " << binaryToHex(userAnswer) << "\n\n";
  }
 }


  
  return EXIT_SUCCESS;
}