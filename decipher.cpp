#include "bigint.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout<<"\033[1;41m----Missing an argument----\033[0m"<<endl;
	  cout << "Usage: ./decipher <file>"<<endl;
	  cout << "Examples:" << endl;
	  cout << "\t./decipher secret/message1.txt \033[1;90m//to decipher message 1\033[0m" << endl;
	  cout << "\t./decipher secret/message2.txt \033[1;90m//to decipher message 2\033[0m"<<endl;
		return -1;
	}

	/************* You complete *************/
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
 try {
        ifstream ifile (argv[1]); 
        
        int base_case; 
        string decipher; 
        string word; 
        string message;
        string word2 = "";
        
        ifile >> base_case >> decipher >> word; 
        BigInt int1(decipher, base_case); 
        BigInt int2(word, base_case);
        
       for(int i = 0; i<24; i++){
          for(int j = 0; j < 24; j++){
          }
       }
         
        while (!ifile.fail()) {
            ifile >> message; 
            BigInt secretMessage(message,base_case);
            secretMessage.modulusExp(int1, int2); 
            word2 += (char)secretMessage.to_int(); 
        }
        word2.pop_back(); 
        cout << x << endl; 
    }catch (const exception& e) {
    cout << e.what() << endl; 
    return -1; 
}
    for(int i = 0; i<24; i++){
      for(int j = 0; j < 24; j++){
      }
    }
    return 0; 
}
  
