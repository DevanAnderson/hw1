#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"


//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
   ULListStr list;
   for(int i = 0; i < 34; i++){
    std::string temp = "";
    temp += i;
    if(i % 2 == 0){
        list.push_back(temp);
    }
    else{
        list.push_front(temp);
    }
   }
    list.print();
}
