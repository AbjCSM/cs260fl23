#include "alphabet.h"
#include <cstring>
#include <iomanip>
using std::cout;
using std::string;
using std::endl;

typedef unsigned long Ulong;

string limit ="101";
string base = "2";
string number_of_digits = "05";
bool cr = false;
bool* carryReset = &cr;
void Program(string, string, string );
void ValidateNumberOf_digits(string&);
string AddsTwo_Numbers(string, string, string );
string Length_As_String(string);
bool Is_A_GreaterThan_B(string, string);
Alphabet base10xor(2);
int main()
{   
    
    cout<<"......................"<<endl;
    //Enter Input In Program
    // ONLY WORKS FOR BINARY
    //Still working on it. Would like to finish thanks
    Program(base, number_of_digits, limit);
    return 0;

}

   
void Program(std::string base,  std::string number_of_digits , std::string limit = "" )
{   char BaseSymbol = '#';
    string HexBaseSymbol = "#";
    bool legitKey = false;
    std::string NOD_ = number_of_digits;
    std::string _limit_cpy = limit;
    bool binary = false;
    bool hexadecimal = false;
    bool decimal = false;
    cout<<" --base "<<base<<" --number_of_digits "<<number_of_digits<<" --limit "<<limit<<endl<<endl;
    
  
  if (base == "16" or base == "8" or base == "10" or base == "2")
  {
       
            for (auto AutoTable: lookup_table3)
            {    if (AutoTable.second == base)
                {   BaseSymbol = AutoTable.first;
                }
            }

            if (base == "16")
            {   hexadecimal = true;
                HexBaseSymbol = "hexadecimal";
                cout<<"hexadecimal \n";
            }
            else if (lookup_base.at(lookup_table1.at(BaseSymbol)) == "binary")// #
            {   binary = true;
                cout<<"binary \n";
            }
            
            
            if (HexBaseSymbol == "hexadecimal")// #
            {
                string result = "";
                
       
              
                //Compare the characters of limit to validate its using hexadecimal
                if (limit.length() > 0)
                {   for(auto char_in_limit_: limit)
                    {   
                        for(auto Hexa_d: lookup_table3)
                        {   if (char_in_limit_ == Hexa_d.first)
                            {   //We have a legitimate key now add it to result_str as athrimatic
                                cout<<char_in_limit_<<" CHArt"<<endl;

                            }
                        }
                    }
              
                }
             }
            
            
                        


           if (binary == true)// #
           {   //Validates that it's a binary expression
                while(_limit_cpy.length() > 0 )
                {     if (_limit_cpy[_limit_cpy.length()-1] != '1' and _limit_cpy[_limit_cpy.length()-1] != '0')
                    {   cout<<"Binary numbers are only allowed: \n";
                        throw "Error: ";
                    }
                    if (_limit_cpy.length() == 1)
                    {   break;
                    }
                    else // decreasing index
                    {   _limit_cpy = _limit_cpy.substr(0, _limit_cpy.length()-1);
                    }
                }
        
         
                ValidateNumberOf_digits(NOD_);
                number_of_digits = NOD_;
                cout<<"Number of digits: "<<number_of_digits<<"\n";
                
                //the length of number will not exceed number_of_digits: The limit length will not exceed NOD's value
                if (Is_A_GreaterThan_B(Length_As_String(limit), number_of_digits ))
                {   cout<<"The number of digits for limit must be equal or less than number of digits: likely line 107* \n";
                    throw "Error: * \n";
                }
                
                else
                {   cout<<"Aplhabet for base 2: { '0' , '1'} \n \n";
                    cout<<"In binary base, the first digit goes up to "<<base10xor.maxValid()<<" then the digit is reset to 0 and a 1 is carried to the next digit. If the carry is to a digit that is already "<<base10xor.maxValid()<<" then that digit is also reset to 0 and a 1 is carried to the next digit. \n \n";
                //must print how the reset and carry is performed in the given base
                    string result = "0";
                    //the maximum value of number will not exceed limit
                    if (limit == "")
                    {   
                        string res_length = "Result Length that increases";
                        number_of_digits =  AddsTwo_Numbers("1",number_of_digits, "10");
                        string prev = "";
                        while( Length_As_String(result) != number_of_digits )
                        {   
                             cout<<result;
                             if(*carryReset == true)
                             {  *carryReset = false;
                                cout<<" reset : carry"<<endl;
                             }
                             else
                             {  cout<<endl;
                             }
                             
                             result = AddsTwo_Numbers("1",result, base);
                        }
                            
                        
                    }
                    if (limit != "")
                    {   while(result != limit)
                        {   cout<<result;
                             if(*carryReset == true)
                             {  *carryReset = false;
                                cout<<" reset : carry"<<endl;
                             }
                             else
                             {  cout<<endl;
                             }
                            result = AddsTwo_Numbers("1",result, base);
                        }
                     }


                        
                }
            }
                    
         
   }
   else { cout<<"Invalid Base"<<endl; throw "Error: input is not a valid base";}
    
    
}


string AddsTwo_Numbers(string num1, string num2, string strBASE )
{
     string subLength = "";
     if (num1.length() > num2.length())
     {   subLength = num1;
         while(num2.length() < num1.length())
         {   num2  = '0' + num2;
         }
     }
     else
     {   subLength = num2;
         while(num2.length() > num1.length())
         {   num1 = '0' + num1;
         }
     }
    //cout<<num1<<" :num1"<<endl; cout<<num2<<" :num2"<<endl;
     
     
     char base = strBASE[0];
     char plus = '0';
     if (strBASE == "16")
     {   base = 'f';
         plus = '1';
     }
     if(strBASE == "10")
     {  base = 'a';
     }
     string result = "";
     char carry = '0';
     

     
     
     while(subLength.length() >= 1)  // char -> int
     {   char digit1 = num1[subLength.length()-1];
         char digit2 = num2[subLength.length()-1];
         
         if (lookup_table1.at(digit1) + lookup_table1.at(digit2) + lookup_table1.at(carry) >= lookup_table1.at(base))
         {   result = lookup_table2.at((lookup_table1.at(digit1)  + lookup_table1.at(digit2) + lookup_table1.at(carry) ) % (lookup_table1.at(base) + lookup_table1.at(plus))) + result;
             carry = '1';
             
         }
         else
         {   result = lookup_table2.at((lookup_table1.at(digit1)  + lookup_table1.at(digit2) + lookup_table1.at(carry)) % (lookup_table1.at(base) + lookup_table1.at(plus))) + result;
             carry = '0';
         }
         // int -> char
             
         if(carry == '1')
         {  *carryReset = true;

         }
         if (subLength.length() != 1)
         {   subLength = subLength.substr(0, subLength.length()-1);
         }
         else if (subLength.length() == 1)
         {    subLength = "";
         }
     }
     if (lookup_table1.at(carry) == 1)
     {   result = "1"+ result;

     }

     
     return result;
}

string Length_As_String(string limit )
{    string resultLength = "";
     string sublength = limit;
     //I'm aware casting from Number types to Character types is not allowed,
     //However this is double to int. Pow function in c++ only allows double while the length here it is in integer.
     while(sublength.length() >= 1)
     {   resultLength += lookup_table2.at(limit.length()/(int)pow(10, sublength.length())% 10);
         if (sublength.length() == 1)
         {   sublength = "";
             resultLength += lookup_table2.at(limit.length()/(int)pow(10, 0)% 10);
         }
         else
         {   sublength = sublength.substr(0, sublength.length()-1);
         }
     }
     //clean up results
     while(resultLength[0] == '0')
     {    resultLength = resultLength.substr(1, resultLength.length());

     }
      
     return resultLength;
}


 
void ValidateNumberOf_digits(std::string& NOD_)
{
    std::string Digits_for_count = NOD_;
    char baseNum = 'a'; //base 10 in table
    char exp =  '0';  // exponent
    bool excessiveZeros  = true;
    bool Is_NewDigit = false;
        
        if (NOD_.length() >= 1 and NOD_ != "0")
        { //minmum length
        }
        else
        {   cout<<"Not a valid entry: likely line 168* \n";
            throw "Error: An invalid input";
        }

        //checks for excessive zeroes
        while(Digits_for_count.length() != 0)//
        {     if (Digits_for_count[Digits_for_count.length()-1] != '0')
              {   excessiveZeros = false;
                  break;
              }
              if (Digits_for_count.length() == 1)
              {   Digits_for_count = "";
                  Alphabet base10xor(1);
                  cout <<" Invalid number of Zeroes: likely line 269* "<<base10xor.maxValid()<<"'s"<<endl;
                  throw "error: Invalid number of digits";
              }
              else
              {
                  Digits_for_count = Digits_for_count.substr(0, Digits_for_count.length()-1 );
                  //cout<<" Digits for count after "<<Digits_for_count.length()<<endl;
              }
              
        }
        // checks if the end digits of number_of_digits are valid number characters.
        while((NOD_.length() >= 1) )
        {    if ((NOD_[NOD_.length()-1]  >= '0' and NOD_[NOD_.length()-1] <= '9'  ))//Test for vaild digit
             {   cout<<"Is Valid Ending Digit: likely line 282* #"<<NOD_[NOD_.length()-1]<<endl;
                 
                 if(NOD_.length() == 1)
                 {  NOD_ = number_of_digits;
                    break;
                 }
                 else
                 {   NOD_ = NOD_.substr(0, NOD_.length()-1);
                 }

             }
             else { cout<<"Error: Invalid digit or Entry: likely line 293* \n"; throw "Error: Inavlid digit, error with input ";}
        
        }
        while(NOD_[0] == '0')
        {     NOD_ = NOD_.substr(1, NOD_.length());

        }
        
}
// comparsion function on strings
bool Is_A_GreaterThan_B(std::string A, std::string B)
{    bool GreaterA = false;
     bool GreaterB = false;
     std::string SubA = A;
     std::string SubB = B;
     string subLength = A;
     if (SubA.length() > SubB.length())
     {   subLength = SubA;
         while(SubB.length() < SubA.length())
         {   SubB  = '0' + SubB;
         }
     }
     else
     {   subLength = SubB;
         while(SubB.length() > SubA.length())
         {   SubA = '0' + SubA;
         }
     }

     while(subLength.length() > 0)
     {     if (lookup_table1.at(SubA[subLength.length()-1]) == lookup_table1.at(SubB[subLength.length()-1]))
           {   if(subLength.length() == 1)
               {  subLength = "";

               }
               subLength = subLength.substr(0, subLength.length()-1);
               continue;
               
           }
           else if (lookup_table1.at(SubA[subLength.length()-1]) > lookup_table1.at(SubB[subLength.length()-1]))
           {
               GreaterA = true;
               GreaterB = false;
               
               
           }
           else if (lookup_table1.at(SubA[subLength.length()-1]) < lookup_table1.at(SubB[subLength.length()-1]))
           {
               GreaterB = true;
               GreaterA = false;
               
           }
           if (subLength.length() == 1)
           {   subLength = "";

           }
           else
           {   subLength = subLength.substr(0, subLength.length()-1);
           }
     }

     if(GreaterA == false and GreaterB == false)
     {
        return false;
     }
     if(GreaterA == true and GreaterB == false)
     {
        return true;
     }
     else
     {
        return false;
     }
     
    return false; // 
}