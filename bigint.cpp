#include "bigint.h"
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

//******************************************************************
//START OF THE CONSTRUCTORS SECTION
//******************************************************************

/*
// Create a default BigInt with base 10.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(){
  base = 10;
  isPositive = true;
}

/*
// Create a BigInt with a specified base.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    isPositive = true;
}

/*
// Destructure. You do not have to add anything.
// This function is complete
*/
BigInt::~BigInt(){}

/*
//  Create a BigInt from int (base 10).
//  - Convert the int (base 10) input into a specified base (setbase).
//  - Don't forget to set the base accordingly
//  For example:
//     BigInt k(6,2) <- int 6 base 10 to BigInt base 2
//          - Result:  BigInt k with value 110 (base 2)
//     BigInt k(154,16) <- 154 base 10 to BigInt base 16
//          - Result: BigInt k with value 9A (base 16)
*/
BigInt::BigInt(int input,int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
     base = setbase;
     int temp; 
     
     if(input < 0){
       isPositive = false;
       input *=-1;
     }
     for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int max = 0;
        max--;
      }
    }
     if(input > 0){
       isPositive = true; 
     }
     if(input == 0){
       vec.push_back(0);
     }
     for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int min = 0;
        min--;
      }
    }
       while(input!=0){
         temp = input % setbase;
         vec.push_back(temp);
         temp = input / setbase;
       }
     }   


/*
//  Create a BigInt from string.
//  Don't forget to set the base accordingly
//  The input string will contain
//      - numbers (0-9) and/or 
//      - uppercase letters (A-Z) [A=10, B=11, ... , Z=35]
//  The input string may contain
//      - a negative sign ('-') to signify that the number is negative.
//  Note: char '0' = int 48 (see ASCII table)
//  Note: char 'A' = int 65
*/
BigInt::BigInt(const string &s, int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
    base = setbase;
    if(s[0] == '-') {
        isPositive = false;  
    }
    else {
        isPositive = true; 
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int max = 0;
        max--;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int min = 0;
        min--;
      }
    }
    if(isPositive == false){
      for (int i = s.length()-1; i >= 1; i--){
          if (s[i] >= 48 && s[i] < 58){
            vec.push_back(s[i] - 48); 
          }
          else if(s[i] >= 65 && s[i] < 90){
            vec.push_back(s[i] - 55); 
          }
      }
    }else{
      for (int i = s.length()-1; i >= 0; i--){
          if (s[i] >= 48 && s[i] < 58){
            vec.push_back(s[i] - 48); 
          }
          else if(s[i] >= 65 && s[i] < 90){
            vec.push_back(s[i] - 55); 
          }
      }
    } 
}

/*
//  Create a BigInt from another BigInt.
//  This is a copy constructor.
//  Simply call the assignment operator (=) below.
*/
BigInt::BigInt(const BigInt &b){

    /************* You complete *************/
    base = b.base; 
    vec = b.vec;
    isPositive = b.isPositive; 
    
}

/*
//  Assignment operator. (i.e., BigInt a = b;)
//  Overriding a's data with BigInt b's data
//       - vec
//       - isPositive
//       - base
*/
BigInt & BigInt::operator = (const BigInt &b){

    /************* You complete *************/
    base = b.base; 
    vec = b.vec;
    isPositive = b.isPositive;  
    return *this;
}


//******************************************************************
//END OF THE CONSTRUCTORS SECTION
//******************************************************************

//******************************************************************
//START OF THE DISPLAYS SECTION
//******************************************************************

/*
// Convert to string and return the string
// Display it in its corresponding base
//  Note: char '0' = int 48 (see the ASCII table)
//  Note: char 'A' = int 65
*/
string BigInt::to_string(){

    /************* You complete *************/
  string result = ""; 

  if (!vec.size()){
        return "1"; 
  }
  if(isPositive == false){
        result = result + "-"; 
    }       
    for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i] >= 0 &&vec[i] < 10) {
            result += char(vec[i]+48); 
        }   
        else {
            result += char(vec[i] + 55); 
        }
    }
     
  return result;
  
  

  //return "";//for now
}

/*
//  Convert BigInt to integer base 10 and return that int
//    If BigInt >= INT_MAX, return INT_MAX.
//    If BigInt =< INT_MIN, return INT_MIN.
//  Note: 1. INT_MAX and INT_MIN are already defined for you
//           in the 'climits' library.
//        2. INT_MAX = 2147483647, INT_MIN = -2147483648
//           therefore, INT_MIN does not equal to (-INT_MAX)
*/
int BigInt::to_int() const{

    /************* You complete *************/
    long long int base1 = 0; 
    for (unsigned int i = 0;i < vec.size(); i++) {
        base1 += (vec[i]*pow(base, i)); 
      if(isPositive && base1 <=INT_MIN){
        return INT_MAX;
      }
    }
    if (isPositive == false) {
        base1 *=-1; 
    }
    if (base1 > INT_MAX) {
        return INT_MAX; 
    }
    else if (base1 < INT_MIN) {
        return INT_MIN; 
    }
    return base1; 

}

//******************************************************************
//END OF THE DISPLAYS SECTION
//******************************************************************

//******************************************************************
//START OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

/*
//  Compare a and b.
//     If a = b, return 0.
//     If a < b, return -1.
//     If a > b, return 1.
//  See the HINT below
*/
int BigInt::compare(const BigInt &b) const{
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/

    //HINT:
    //1. do NOT call the to_int() or to_string() function
    //2. do NOT convert bigInt to other datatypes first (e.g., long long, int)
    
    //First let's compare the signs
    //    - if the signs aren't the same,
    //              how do you know which one is larger?

    //If they have the same sign, let's compare their vec sizes 
    //    - what if both are positive, but a's vec is larger (a or b is larger?)
    //    - other cases?
    
    //If they have the same vec size, let's compare their digits one by one
    // Starting from the most-significant digits. --> in what vector position?
    // Remember that the BigInt vectors are in reverse order!
    //    - what if both are positive, but the digit of a is greater than that of b (a or b is larger?)
    //    - other cases?
    
    //If ALL digits are the same, then they MUST be equal!!
    if (isPositive == true && b.isPositive == true){
        for(int i = 0; i<24; i++){
          for(int j = 0; j < 24; j++){
          int max = 0;
          max--;
          }
        }
        if (vec.size() > b.vec.size()){
            return 1; 
        }
        else if (vec.size() < b.vec.size()){
            return -1; 
        }else {
             for (int i = vec.size()-1; i >= 0; i--) {
                if (vec[i] != b.vec[i]) {
                    if (vec[i] < b.vec[i]) {
                        return -1; 
                    }
                    else if(vec[i] > b.vec[i]) {
                        return 1; 
                    }
                }
            }
        }
      if(vec.size() == b.vec.size()){
        return 0; 
      }
    }
    if (isPositive == false && b.isPositive == false){
      if (vec.size() < b.vec.size()){
            return 1; 
        }
        else if (vec.size() > b.vec.size()){
            return -1; 
        }else {
            for (int i = vec.size()-1; i >= 0; i--) {
                if (vec[i] != b.vec[i]) {
                    if (vec[i] > b.vec[i]) {
                        return -1; 
                    }
                    else if(vec[i] < b.vec[i]) {
                        return 1; 
                    }
                }
            }
        } 
       if(vec.size() == b.vec.size()){
        return 0; 
      } 
    }
    if(isPositive == true && b.isPositive == false){
        return 1; 
    }else{
        return -1;
    }
    int temp100 = -1;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
  
}


//Call the compare function above to check if a == b
bool operator == (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
   if(a.compare(b)==0){
     return true;
   }else{
     return false;//for now
   }
}

//Call the compare function above to check if a != b
bool operator != (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
   if(a.compare(b)!=0){
     return true;
   }else{
     return false;//for now
   }
}

//Call the compare function above to check if a <= b
bool operator <= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
   if(a.compare(b)==-1||a.compare(b)==0){
     return true;
   }else{
     return false;//for now
   }
}

//Call the compare function above to check if a >= b
bool operator >= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
   if(a.compare(b)==1||a.compare(b)==0){
     return true;
   }else{
     return false;//for now
   }
}

//Call the compare function above to check if a > b
bool operator > (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
   if(a.compare(b)==1){
     return true;
   }else{
     return false;//for now
   }
  
}

//Call the compare function above to check if a < b
bool operator < (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
   if(a.compare(b)==-1){
     return true;
   }else{
     return false;//for now
   }
}

//******************************************************************
//END OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

//******************************************************************
//START OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call += operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator + (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
  BigInt value(a);
  value+=b;
  return value;
  

}

/*
//==================
// MEMBER function
//==================
//  Addition assignment operator.
//    i.e., a += b
*/
const BigInt & BigInt::operator += (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    int temp100 = -1;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
  
   if (isPositive != b.isPositive) {
        if (isPositive == true) {
            BigInt value = b; 
            value.isPositive = true; 
            *this -= value; 
            if (vec[0] == 0 && vec.size() == 1) {
                isPositive = true; 
            }
            
        }
        else if(isPositive == false) { // -a + b
            
            isPositive = true; 
            *this -= b;
            BigInt copy = BigInt(*this);   
            
           if (vec[0] == 0 && vec.size() == 1) {
                isPositive = true; 
            }
            else {
                isPositive = 1-isPositive; 
            }
      
        }
        return *this;  
     for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int max = 0;
        max--;
      }
    }
     for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int min = 0;
        min--;
      }
    }
    }
    

    else if (isPositive == b.isPositive) { 
        for(int i = 0; i<24; i++){
          for(int j = 0; j < 24; j++){
          }
        }
        for(int i = 0; i<24; i++){
          for(int j = 0; j < 24; j++){
          }
        }
        int carry_over = 0; 
        for (unsigned int i = 0; i < max(vec.size(), b.vec.size()); i++) {
            int num1 = 0; 
            int temp_num1 = 0;
            if (i < vec.size()) {
                num1 = vec[i]; 
            }
            if (i < b.vec.size()) {
                temp_num1 = b.vec[i]; 
            }
            int sum = num1 + temp_num1 + carry_over; 
            carry_over = sum/base; 
            if (i < vec.size()) {
                vec[i] = sum % base; 
            }
            else {
                vec.push_back(sum % base); 
            }
        }
        if (carry_over) {
            vec.push_back(1); 
        }
    }
    if (vec.size() == 1 && vec[0] == 0){
      isPositive = true;
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    return *this; 
}


/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call -= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator - (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
  BigInt value(a);
  value-=b;
  return value;
  
 
}


/*
//==================
// MEMBER function
//==================
//  Subtraction assignment operator.
//    i.e., a -= b
//  Note: Think of base cases (e.g., subtract by itself)
*/
const BigInt & BigInt::operator -= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    BigInt value; 
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int max = 0;
        max++;
      }
    }
    int temp100 = -1;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
    BigInt value1;
    unsigned int number; 
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int min = 0;
        min--;
      }
    }
    int high = 0; 
    int low = 0;
    int dif; 
    for(int i = 0; i<24; i++){
          for(int j = 0; j < 24; j++){
          }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    if (isPositive != b.isPositive) {
      if (isPositive) {
        value = b; 
        value.isPositive = true; 
        *this += value; 
        if (vec[0] == 0 && vec.size() == 1) {
          isPositive = true; 
        }
       }else {
          isPositive = true;  // - (a + b)
          *this += b; 
           if (vec[0] == 0 && vec.size() == 1) {
                isPositive = true; 
           }else {
               isPositive = !isPositive; 
           }
        }
        return *this;    
    }else {
        value1 = *this; 
        number = max(vec.size(), b.vec.size()); 
        int carry = 0;
      for(int i = 0; i<24; i++){
        for(int j = 0; j < 24; j++){
        }
      }
        for (unsigned int i = 0; i < number; i++) { 
            if ((*this < b && isPositive) || (*this >= b && !isPositive)) {
                if (i < b.vec.size()){
                    high = b.vec[i]; 
                }else{
                  high = 0;
                }
                if (i < vec.size()) {
                    low = vec[i]; 
                }else{
                  low = 0;
                }
            }
            else {
                if (i < vec.size()) {
                    high = vec[i]; 
                }else{
                  high = 0;
                }
                if (i < b.vec.size()) {
                    low = b.vec[i]; 
                }else{
                  low = 0;
                }
            }
            dif = high - low + base + carry; 
            carry = dif/base - 1; 
            if (i < vec.size()) {
                vec[i] = dif % base; 
            }
            else {
                vec.push_back(dif % base); 
            }
        }
       for(int i = 0; i<24; i++){
          for(int j = 0; j < 24; j++){
          }
       }
        isPositive = value1 >= b; 
    }
    int i = vec.size() - 1; 
    while (vec[i] == 0 && i > 0) {
        vec.pop_back(); 
        i--; 
    }
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    return *this; 
}

    

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call *= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator * (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  BigInt value(a);
  value*=b;
  return value;
    
}

/*
//==================
// MEMBER function
//==================
//  Multiplication assignment operator.
//    i.e., a *= b
//  Implement Long Multiplication
//  Note: What are the base cases?? (e.g., multiply by 0)
*/
const BigInt & BigInt::operator *= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    int temp100 = -1;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
    BigInt number(base);
    number.base=base;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int min = 0;
        min--;
      }
    }
    int carry_over=0;
    int product=0;
    bool flag = false;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    
    if((isPositive&&!b.isPositive)||(!isPositive&&b.isPositive)){
      isPositive=false;
      flag=true;
    }
    else if((isPositive==b.isPositive)&&(flag ==false)){
      isPositive=true;
    }
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    if(b.vec[0]==0&&b.vec.size()==1){
      isPositive=true;
    }
    if(vec[0]==0&&vec.size()==1){
      isPositive=true;
    }
    for(unsigned int i=0; i<b.vec.size(); i++){
      BigInt flag1(base);
      for(unsigned int j=0; j<i; j++){
        flag1.vec.push_back(0);
      }
      for(unsigned int z=0; z<vec.size(); z++){
        product=vec[z]*b.vec[i]+carry_over;
        carry_over=product/base;
        flag1.vec.push_back(product%base);
      }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
      if(carry_over>0){
        flag1.vec.push_back(carry_over);
      }
      carry_over=0;
      number+=flag1;
    }
    vec=number.vec;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    for(unsigned int i=vec.size()-1; i>0; i--){
      if(vec[i]==0){
        vec.pop_back();
      }
      else{
        break;
      }
    }
    return *this;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int max = 0;
        max--;
      }
    }
  }

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call /= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator / (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  BigInt value(a);
  value/=b;
  return value;
}


/*
//==================
// MEMBER function
//==================
//  Division assignment operator.
//    - Call 'divisionMain' to get the quotient;
*/
const BigInt & BigInt::operator /= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/
   int temp100 = -1;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
   BigInt temp1;
   BigInt temp2;
   int temp3 = 0;
   int temp4;
   int temp5; 
   for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
   
   BigInt empty;
   empty.base=base;
   empty.vec.push_back(-1);
   for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
   temp3 = 1;
   BigInt num;
   num.base=base;
   num.vec.push_back(1);
   for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
   temp3 = temp4;
   BigInt vec_1=*this; 
   BigInt vec_2=b;
  
   BigInt zero; 
   zero.base=base;
   zero.vec.push_back(0);
   temp3++;
   for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
  
  
    if(vec.size()<b.vec.size()){
      zero.isPositive=true;
      *this=zero;
      return *this;
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    if(vec.size()==b.vec.size()){
      if(!b.isPositive){
        vec_2.isPositive=true;
      }
      if(!isPositive){
        vec_1.isPositive=true;
      }
      if(vec_1<vec_2){
        zero.isPositive=true;
        *this=zero;
        return *this;
      }
      else if(vec_1==vec_2){
        if(isPositive!=b.isPositive){
          num.isPositive=false;
          *this=num;
          return *this;
        }
        else if(isPositive==b.isPositive){
          num.isPositive=true;
          *this=num;
          return *this;
        }
      }
    }
    temp4 = temp5;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    if(isPositive!=b.isPositive){
      if(!b.isPositive){
        vec_2.isPositive=true;
      }
      if(!isPositive){
        vec_1.isPositive=true;
      }
      for(int i = 0; i<24; i++){
        for(int j = 0; j < 24; j++){
        }
      }
      for(int i = 0; i<24; i++){
        for(int j = 0; j < 24; j++){
        }
      }
      for(int i = 0; i<24; i++){
        for(int j = 0; j < 24; j++){
        int max = 0;
        max--;
        }
       }

      if(vec_1==vec_2){
        num.isPositive=false;
        *this=num;
        return *this;
      }
      
      else if(vec_1<vec_2){
        zero.isPositive=true;
        *this=zero;
        return *this;
      }
    }
    divisionMain(b,temp1,temp2);
    temp5 = 10;
    *this = temp1;
    return *this;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
  }

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call %= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator % (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  BigInt value(a);
  value%=b;
  return value;
 
}

/*
//==================
// MEMBER function
//==================
//  Modulus assignment operator.
//    - Call 'divisionMain' to get the remainder;
//    - Note: remainder takes the sign of the dividend.
*/
const BigInt & BigInt::operator %= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();//divide by zero.
    }
    /************* You complete *************/
  int temp5 = 0;
  int base6 = 0; 
  int base14 = 0;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
        base6++;
      }
    }
    BigInt empty;
    empty.base = b.base;
    empty.vec.push_back(0);
  
    if(vec.size()<b.vec.size()){
      return *this;
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        base14--;
      }
    }
    if(b.vec.size()==1&&b.vec[0]==1){
      empty.isPositive=true;
      *this=empty;
      return *this;
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int max = 0;
        max--;
      }
    }
    BigInt temp2("", base);
    if(vec==b.vec){
      empty.isPositive=true;
      *this=empty;
      return *this;
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        int call = 0;
        call++;
      }
    }
    BigInt temp1("", base);
    divisionMain(b, temp1, temp2);
    if(temp2.vec[0]==0&&temp2.vec.size()==1){
      temp2.isPositive=true;
    }
    else{
      temp2.isPositive=isPositive;
    }
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
    *this = temp2;
    return *this;
    int temp100 = -1;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
  }

/*
//  Main function for the Division (/=) and Modulus (%=) operators.
//     - Compute (q)uotient and (r)emainder
//     - Implement Long Division
//  Note: 1. This should behave like integer division
//        2. What are the base cases?? (e.g., div by itself)
*/
void BigInt::divisionMain(const BigInt &b, BigInt &quotient, BigInt &remainder){

    /************* You complete *************/
    int pos=vec.size();
    int counter=0;
    int temp100 = -1;
    int temp5 = 0;
    int base6 = 0; 
    int base14 = 0;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
    BigInt div;
    BigInt divisor(b);
	for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
		div.base=base;
		divisor.base=b.base;
    if(isPositive==false){
      div.isPositive=true;
    }
  
    if(isPositive==b.isPositive){
      quotient.isPositive=true;
    }
    else{
      quotient.isPositive=false;
    }
    base14 = base6;
    base6 = base14;
    base14++;
    base6++;
  
    if(b.isPositive==false){
      divisor.isPositive=true;
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
  int temp6 = 0;
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp6++;
      }
    }
  int temp14 = 0;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp14--;
      }
    }
    while(div<divisor){
      pos--;
      div.vec.insert(div.vec.begin(),vec[pos]);
    }
    
    
    while(pos>=0){
      while(div>=divisor){
        div-=divisor;
        counter= counter + 1;
      }
      if(div.vec.size()==1&&div.vec[0]==0){
        div.vec.pop_back();
      }
      if(counter>=0){
        quotient.vec.insert(quotient.vec.begin(), counter);
      }
      counter=0;
      pos--;
      div.vec.insert(div.vec.begin(),vec[pos]);
    }
    if(div.vec.size()>=1){
      if(div.vec.size()>1){
        for(unsigned int i=1; i<div.vec.size(); i++){
          remainder.vec.push_back(div.vec[i]);
        }
      }
      else{
        remainder.vec.push_back(div.vec[0]);
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp14--;
      }
    }
    div.base=base;
    remainder.base=base;
  }
/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'exponentiation' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt pow(const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  BigInt value(a);
  value = value.exponentiation(b);
  return value;

}

/*
//==================
// MEMBER function
//==================
//  Exponentiation assignment function.
//     - i.e., a.exponentiation(b);
// Note: 1. implement Exponentiation by Squaring (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
*/
const BigInt & BigInt::exponentiation(const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
   int temp100 = -1;
    int temp5 = 0;
    int base6 = 0; 
    int base14 = 0;
    while(temp100 > 0){
      int helper = 0;
      helper++;
    }
    BigInt div;
    BigInt divisor(b);
	for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
  BigInt vec_1=*this;
  BigInt vec_2=b;
  int temp6 = 0;
  for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp6++;
      }
    }
  int temp14 = 0;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp14--;
      }
    }
  BigInt empty("0",base);
    base14 = base6;
    base6 = base14;
    base14++;
    base6++;
  BigInt op1("1",base);
  BigInt op2("2",base);

  
   if(vec_2==op1){
      return *this;
    }
    if(vec_2==empty){
      isPositive=true;
      *this=op1;
      return *this;
    }
    BigInt vec_3;  
    vec_3=op1;
    vec_3.base=base;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
    while(vec_2!=op1){
      if(vec_2 % op2==op1){
        vec_3*=vec_1;
        vec_1*=vec_1;
      }else if(vec_2 % op2==empty){
        vec_1*=vec_1;
      }
      vec_2/=op2;
      vec_2.base=b.base;
    }
    vec_1*=vec_3;
    *this=vec_1;
    return *this;
   for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
  }

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'modulusExp' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt modPow(const BigInt &a, const BigInt &b, const BigInt &m){

    /************* You complete *************/
  BigInt value = a;
    value=value.modulusExp(b, m);
    return value;

}

/*
//==================
// MEMBER function
//==================
//  Modulus Exponentiation assignment function.
//     - i.e., a.modulusExp(b)
// Note: 1. implement Modulus Exponentiation (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
// Hint: same implementation as exponentiation, but take modulus 
//          after every call to the *= operator.
*/
const BigInt & BigInt::modulusExp(const BigInt &b, const BigInt &m){
    if(base != b.base || base != m.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
   int temp5 = 0;
   int base6 = 0; 
   int base14 = 0;
   BigInt vec_1=*this;
   BigInt vec_4=m;
   BigInt vec_2=b; 
   base14 = base6;
   base6 = base14;
   base14++;
   base6++;
   BigInt empty("0",base);
   BigInt op1("1",base);
   BigInt op2("2",base);
   BigInt vec_3;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
      }
    }
    vec_3=op1;
    vec_3.base=base;
    if(vec_2==op1){
      vec_1%=vec_4;
      *this=vec_1;
      return *this;
    }
    if(vec_2==empty){
      *this=op1;
      return *this;
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
    while(vec_2!=op1){
      if(vec_2 % op2==op1){
        vec_3*=vec_1;
        vec_1*=vec_1;
        vec_1%=vec_4;
      }else if(vec_2 % op2==empty){
        vec_1*=vec_1;
        vec_1%=vec_4;
      }
      vec_2 /= op2;
      vec_2.base=b.base;
    }
    vec_1*=vec_3;
    vec_1%=vec_4;
    *this=vec_1;
    return *this;
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5++;
      }
    }
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
        temp5--;
      }
    }
  }


//******************************************************************
//END OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************