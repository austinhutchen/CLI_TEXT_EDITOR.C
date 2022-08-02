#include "functions.h"
int main() {
  send output = send();
  string filename("");
  string choice;
  string input;
  cout << "Enter the name of the file you would like to write to below:" << endl;
  cin >> filename;
  cout << "Would you like to write, or read from this file? Type WRITE for write, and READ for read." << endl;
  cin >> choice;
  if (!cin.fail()) {
    if (output.lowercase(choice) == "write") {
      cout << "Begin typing below. Type NEW to type on a new line." << endl;
      cin.ignore();
      getline(cin, input);
      //splitstring here to check for new line
      // getline automatically starts newline
      bool f = output.print(filename, input);
      if (f == true) {
        cout << "Text succesfully written." << endl;
      } 
      else {
        return main();
      }
    }
    else if (output.lowercase(choice) == "read") {

    }

  } 
  else {
    cout << "Please enter the phrase write or read for your choice. No spaces allowed."<< endl;
    return main();
  }
}