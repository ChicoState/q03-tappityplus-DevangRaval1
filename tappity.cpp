#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  ref = reference;
  inp = "";
  
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  inp = input;
  return;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  if(inp.length() > ref.length()){
    return (inp.length()-ref.length());
  }
  else if(inp.length() < ref.length()){
    return (ref.length() - inp.length());
  }
  else
    return 0;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  double difference = 0; 
  if(inp.length() > ref.length()){
    for(int i = 0; i<ref.length(); i++){
      if(inp[i] != ref[i]){
        difference++;
      }
    }
    difference = difference + inp.length() - ref.length();
    return ((inp.length()-difference)/inp.length())*100;
  }
  else if(inp.length() < ref.length()){
    for(int i = 0; i<inp.length(); i++){
      if(inp[i] != ref[i]){
        difference++;
      }
    }
    difference = difference + ref.length() - inp.length();
    return ((ref.length()-difference)/ref.length())*100;
  }
  else{
    for(int i = 0; i<inp.length(); i++){
      if(inp[i] != ref[i]){
        difference++;
      }
    }
    return ((inp.length()-difference)/inp.length())*100;
  }
}
