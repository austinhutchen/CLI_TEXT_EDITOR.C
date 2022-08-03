#ifndef functions_h
#define functions_h
#include <cstddef>
#include <time.h>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class send {
public:
  send(string _filename){
    filename=_filename;
    fout.open(filename,std::ios::app);
    fin.open(filename);
  //this places the file pointer at the end
  }
  // function writes to external txt file

  bool print(string text) {
      fout << text << endl;
      return true;
  }
  string lowercase(string input) {
    for (int x = 0; x < input.size(); x++) {
      if (input[x] >= 65 && input[x] <= 90) {
        int e = input[x] + 32;
        input[x] = e;
      } else {
        continue;
      }
    }
    // end of loop
    return input;
  }

  int split(string inputstring, char seperator, string arr[], int size) {
    // number of split strings stored in count
    int count = 0;
    int i = 0;
    int start = 0;
    int end = 0;
    // input validation
    if (inputstring.empty()) {
      return 0;
    }

    while (end < inputstring.size()) {
      if (inputstring[end] == seperator) {
        int length = end - start;
        // if length is 0, use -1 (error is here)
        if (i == length) {
          return -1;
        }
        arr[i++] = inputstring.substr(start, length);
        // move up 1 to avoid delimiter
        end++;
        start = end;
      } else {
        end++;
      }
    }
    int length = end - start;
    // error checking for array size greater than the required
    if (i >= size) {
      return -1;
    }
    arr[i++] = inputstring.substr(start, length);
    return i;
  }
 int edit_text(){
// first, read the file. Then, make a menu asking user for the line they want to edit, before searching and replacing that word.
// most likley, file will need to be rewritten, as ifstream automatically deletes the previous .txt file




return 0;
 }
// displays output of what is currently stored in the text file
int readfile(){
string line;
cout << "-----FILE TEXT BEGINNING-----" << endl;
while(getline(fin,line)&&line.length()!=0){
cout << line << endl;
}
cout << "-----FILE TEXT END-----" << endl;
return 0;}
void changefilename(string _filename){
  filename=_filename;
}

void closefile(){
  fout.close();
  fin.close();
}
// fix below function, file wont delete. pointer needs to be reset
int deletefile(){
  string choice;
  cout << "Are you sure you want to delete this file? Y/N" << endl;
  cin >> choice;
  if(choice=="y"||"Y"||"yes"||"YES"){
    fout.open("test.txt", std::ofstream::out | std::ofstream::trunc);
    cout << "File deleted." << endl;
    return 0;
  }
  else{return 1;}
}
private:
  string filename;
  ofstream fout;
  ifstream fin;
};
#endif