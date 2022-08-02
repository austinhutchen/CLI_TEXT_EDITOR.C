#ifndef functions_h
#define functions_h
#include <ctime>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

class send {
public:
  send() { active = false; };
  // function writes to external txt file
  void on(){
    active=true;
  }
  void off(){
    active=false;
  }
  bool print(string filename, string text) {

    ofstream fout;
    fout.open(filename);
    if (fout.fail()) {
      cout << "Invalid filename. Cannot open file." << endl;
      return false;
    } else {
      fout << text << endl;
      ;
      fout.close();
      return true;
    }
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






return 0;
 }
// displays output of what is currently stored in the text file
int readfile(){











return 0;
}
private:
  bool active;
};
#endif