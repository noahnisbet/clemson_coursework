/*
Noah Nisbet
Project 3 Cipher Code
November 11, 2022
CPSC 1070

This file is the driver that I use for testing the classes.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"
#include "Cipher.h"
#include "CipherAdvanced.h"
#include <vector>

using namespace std;

int main(){
  // Defining variables used for testing.
  CipherAdvanced cipheradvanced;
  char char_input = 'A';
  Queue queue;
  srand(time(NULL));
  /*
    Print out tests if the input is not Q
  */
  do{
    string input;
    cout<<endl;
    cout<<"Enter E to encode, D to get possible decodings, or Q to quit: ";
    cin>>input;
    char_input = toupper(input[0]);
    
    switch (char_input){
      case 'E':{
        Cipher cipher;
        string message;

        cout<<endl;
        cout<<"Enter message to encode (no spaces): ";
        cin>>message;
        cout<<endl;

        int key_length = rand() % message.size() + 1;
        int *array = new int(key_length);
        cout<<"Your key is: ";
        for(int i=0; i<key_length; i++)
        {
          array[i] = (rand()+2) % 26 ;
          if (i == 0)
          {
            cout<<array[i];
          }
          else
          {
            cout<<", "<<array[i];
          }
        }
        cout<<endl;
        
        cipher.setCipher(key_length, array);
        string encoded_message = cipher.encodeMessage(message);
        cout<<encoded_message<<endl;
        break;
      }
      case 'D': {
        string encoded;
        cout<<"Enter encoded message: ";
        cin>>encoded;
        cipheradvanced.unknownScramble(encoded);
        break;
      }
    }
    
  }
  while(char_input != 'Q');

  return 0;
}
