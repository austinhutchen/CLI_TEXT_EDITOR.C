#ifndef functions_h
#define functions_h
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <limits>
// add settings functions for displaying line numbers, page numbers, etc
// implement multithreading for run efficiency
// add maps that map together an integer with num characters in the line and the line number
class send {
public:
  send(std::string &filename) {
    fout.open(filename, std::ios::app);
    fin.open(filename);
    // this places the file pointer at the end
  }
  // function writes to external txt file

  bool print(std::string &text) {
    fout << text << std::endl;
    return true;
  }
  std::string lowercase(std::string &input) {
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

  int split(std::string &inputstring, char &seperator, std::string arr[], int &size) {
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
    std::string line;
    std::cout << "-----FILE TEXT BEGINNING-----" << std::endl;
    while (getline(fin, line) && line.length() != 0) {
      std::cout << line << "(" << count << ")" << std::endl;
      count++;
    }
    std::cout << "-----FILE TEXT END-----" << std::endl;
    return 0;
  }
  void changefilename(std::string &_filename) { filename = _filename; }

  void closefile() {
    fout.close();
    fin.close();
  }
  // fix below function, file wont delete. pointer needs to be reset
  int deletefile() {
    std::string choice;
    std::cout << "Are you sure you want to delete this file? Y/N" << std::endl;
    std::cin >> choice;
    if (!std::cin.fail()&&choice == "y" || "Y" || "yes" || "YES") {
      closefile();
      fout.open("test.txt", std::ofstream::out | std::ofstream::trunc);
      std::cout << "File deleted." << std::endl;
      return 0;
    } else {
      std::cout << "Error. Enter yes or no." << std::endl;
      return 1;
    }
  }
  int edit(int &num) {
    int count = 1;
    std::string line;
    std::string edit;
    fin.clear();
    fin.seekg(0, std::ios::beg);
    while (getline(fin, line) && line.length() != 0) {
      if (count == num) {
        std::cout << "----YOU ARE EDITING LINE NUMBER: " << count << "----" << std::endl;
        std::cout << "LINE CONTENT: " << line << std::endl;
        std::cout << "ENTER YOUR NEW AND EDITED LINE BELOW, TYPE EXITNULL TO QUIT, OR TYPE NOTHING FOR LINE DELETION"<< std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin,edit);
        if (edit == "EXITNULL") {
          std::cout << "Safely exited." << std::endl;
          return 1;
        } else if (edit == "") {
          closefile();
          fout.open(filename);
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
          std::cout << "File change saved locally." << std::endl;
          //NOW ENTIRE FILE WITH LINE EDIT IS STORED IN CLASS VECTOR
          }
          }
          // here use the file system library to delete previous file, and use use fstream to open a new blank one
          // output contents of vector on new blank file with same title
          // OR write to end of file
          // map characters to line number starting here 
          closefile();
          fout.open(filename);
          for(int i=0;i<file.size();i++){
          fout << file[i]<< std::endl;
          }
          fout.close();
          }
          return 0;
        }
      else{count++;}       
      } 
          std::cout << "Line not found in file." << std::endl;
    // if function reaches this point, the write has failed. return 0 inside
    return 1;
    }
    // lambda function to quickly add a linde pair with number of characters and line number

private:
  std::string filename;
  std::ofstream fout;
  std::ifstream fin;
  std::vector<std::string>file;

};
#endif

