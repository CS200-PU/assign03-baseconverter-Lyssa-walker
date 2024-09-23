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
#include <algorithm>
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
  int power = binaryNumber.length() - 1;


   
      

    for (char digit : binaryNumber){

      if (digit == '1'){
        decimalValue += 1 * pow(2,power);
        
      }
      power -= 1;
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
  decimalNumber = std::stoi(strNumber);
  string binaryResult = "";
  int remainder;
  
    
    if (decimalNumber == 0){
      return "0";
    }
    
   while (decimalNumber != 0){

    remainder = decimalNumber % 2;
    decimalNumber = decimalNumber / 2;      

    binaryResult += to_string(remainder);

   }
     std ::reverse(binaryResult.begin(), binaryResult.end());
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
    string hexResult;
     decimalNumber = std::stoi(strNumber);
     int remainder;
     string hexDigits = "0123456789ABCDEF";

      if (decimalNumber == 0){
        return "0";
      }
      else if (decimalNumber > 9 && decimalNumber < 16){
        if (decimalNumber == 10){
          return "A";
        }
        else if (decimalNumber == 11){
          return "B";
        }
        else if (decimalNumber == 12){
          return "C";
        }
         else if (decimalNumber == 13){
          return "D";
        }
         else if (decimalNumber == 14){
          return "E";
        }
         else if (decimalNumber == 15){
          return "F";
        }
        
      }
      else{
        while(decimalNumber > 0){
        remainder = decimalNumber % 16;
        hexResult = hexDigits[remainder] + hexResult;
        decimalNumber = decimalNumber / 16;
        }
      }
      

    return hexResult;
}

/****************************************************************************
  Function: hexToDecimal 
  Description: turning a hexadecimal number into a decimal
  Parameters: strNumber - string representing a hexadecimal being passed in
  
  Returned: String
****************************************************************************/
string hexToDecimal (const string& strNumber){
    int decimalVal = 0;
    string hexNumber = strNumber;
    hexNumber = hexNumber.substr(2);
    int power = hexNumber.length() - 1;

  if (hexNumber.length() == 1){
    for (char digit : hexNumber){
      if (digit == '0'){
        decimalVal = 0;

        return  to_string(decimalVal);    
      }
      else if (digit == '1'){
        decimalVal = 1;

        return  to_string(decimalVal);    
      }
      else if (digit == '2'){
        decimalVal = 2;

        return  to_string(decimalVal);    
      }
      else if (digit == '3'){
        decimalVal = 3;

        return  to_string(decimalVal);    
      }
      else if (digit == '4'){
        decimalVal = 4;

        return  to_string(decimalVal);    
      }
      else if (digit == '5'){
        decimalVal = 5;

        return  to_string(decimalVal);    
      }
      else if (digit == '6'){
        decimalVal = 6;

        return  to_string(decimalVal);    
      }
      else if (digit == '7'){
        decimalVal = 7;

        return  to_string(decimalVal);    
      }
      else if (digit == '8'){
        decimalVal = 8;

        return  to_string(decimalVal);    
      }
      else if (digit == '9'){
        decimalVal = 9;

        return  to_string(decimalVal);    
      }
    }
  }
       

     
        for (char digit : hexNumber){
            
          decimalVal += hexCharToInt(digit) * pow(16,power);
            
          power -= 1;
        }
      
    
         

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
 string hexNum;
  decimalNum = binaryToDecimal(strNumber);
  hexNum = decimalToHex(decimalNum);

  return hexNum;
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

  userAnswer = getNumber("Enter your string to convert (q to quit): ");

  if (userAnswer.at(0) == quit){
      proceed = false;
  }
  else if (getBase(userAnswer) == hexChar){
    cout << "The decimal conversion is: " << hexToDecimal(userAnswer) << "\n"; 
    cout << "The binary conversion is: " << "0b" << hexToBinary(userAnswer) << "\n\n";   
  }
  else if (getBase(userAnswer) == decimalChar){
    cout << "The binary conversion is: " << "0b" << decimalToBinary(userAnswer) << "\n";
    cout << "The hexadecimal conversion is: 0x" << decimalToHex(userAnswer) << "\n\n";
  }
  else if (getBase(userAnswer) == binaryChar){
    cout << "The decimal conversion is: " << binaryToDecimal(userAnswer) << "\n";
    cout << "The hexadecimal is: 0x" << binaryToHex(userAnswer) << "\n\n";
  }
 }


  
  return EXIT_SUCCESS;
}