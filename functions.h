#ifndef functions_h
#define functions_h
#include <fstream>
#include <iostream>
#include <thread>
#include <time.h>
#include <vector>
using namespace std;
// add settings functions for displaying line numbers, page numbers, etc
// implement multithreading for run efficiency
class send {
public:
  send(string _filename) {
    filename = _filename;
    fout.open(filename, std::ios::app);
    fin.open(filename);
    // this places the file pointer at the end
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

  // displays output of what is currently stored in the text file
  int readfile() {
    int count = 1;
    string line;
    cout << "-----FILE TEXT BEGINNING-----" << endl;
    while (getline(fin, line) && line.length() != 0) {
      cout << line << "(" << count << ")" << endl;
      count++;
    }
    cout << "-----FILE TEXT END-----" << endl;
    return 0;
  }
  void changefilename(string _filename) { filename = _filename; }

  void closefile() {
    fout.close();
    fin.close();
  }
  // fix below function, file wont delete. pointer needs to be reset
  int deletefile() {
    string choice;
    cout << "Are you sure you want to delete this file? Y/N" << endl;
    cin >> choice;
    if (choice == "y" || "Y" || "yes" || "YES") {
      fout.open("test.txt", std::ofstream::out | std::ofstream::trunc);
      cout << "File deleted." << endl;
      return 0;
    } else {
      return 1;
    }
  }
  int edit(int num) {
    int count = 1;
    string line;
    string edit;
    fin.clear();
    fin.seekg(0, std::ios::beg);
    while (getline(fin, line) && line.length() != 0) {
      if (count == num) {
        cout << "----YOU ARE EDITING LINE NUMBER: " << count << "----" << endl;
        cout << "LINE CONTENT: " << line << endl;
        cout << "ENTER YOUR NEW AND EDITED LINE BELOW, TYPE EXITNULL TO QUIT, "
                "OR TYPE NOTHING FOR LINE DELETION"<<endl;
        cin >> edit;
        if (edit == "EXITNULL") {
          cout << "Safely exited." << endl;
          return 1;
        } else if (edit == "") {

          // delete line
        } else {
          fin.clear();
          fin.seekg(0, std::ios::beg);
          // the only way to do this is to store every line of the file in a
          // vector, find the line number that needs to be changed, change it,
          // and output to the file again. DANGER VECTORS ARE ZERO INDEXED, LINES ARE 1 INDEXED
          while (getline(fin, line) && line.length() != 0) {
          file.push_back(line);
          }
          for(int i=0;i<file.size();i++){
          if(i==count-1){
          file[i]=edit;
          cout << "File change saved locally." << endl;
          //NOW ENTIRE FILE WITH LINE EDIT IS STORED IN CLASS VECTOR
          }
          }
          /* NEED TO CLEAR FILE BEFORE HERE FOR FILE TO NOT DUPLICATE
          for(int i=0;i<file.size();i++){
          fout << file[i]<<endl;
          }*/

          }
          return 0;
        }
      else{count++;}       
      } 
          cout << "Line not found in file." << endl;
    // if function reaches this point, the write has failed. return 0 inside
    return 1;
    }

private:
  string filename;
  ofstream fout;
  ifstream fin;
  vector<string>file;
};
#endif

