#include "functions.h"
int main() {
  string choice;
  string input;
  int line;
  bool f;
  int curtime = time(NULL);
  string filename;
  cout << "Enter the name of the file you would like to write to below:"
       << endl;
  cin >> filename;
  send output(filename);
  // file is now open for all read/write operations
  cout << "Would you like to write, or read from this file? Type WRITE for "
          "write, CLEAR to delete a file,and READ for read."
       << endl;
  cin >> choice;
  if (!cin.fail()) {
    if (output.lowercase(choice) == "write") {
      cout << "Begin typing below. Type NEW to type on a new line, or EXIT to "
              "quit."
           << endl;
      cin.ignore();
      while (getline(cin, input)) {
        if (input != "EXIT") {
          f = output.print(input);
        } else {
          break;
        }
      };
      // splitstring here to check for new line
      //  getline automatically starts newline
      if (f == true) {
        cout << "Text succesfully written." << endl;
      } else {
        cout << "ERROR: Text failed to write." << endl;
        return main();
      }
    } else if (output.lowercase(choice) == "read") {
      output.readfile();
      cout << "Would you like to edit this file? y/n" << endl;
      cin >> choice;
      if (choice == "y" || choice == "Y") {
        cout << "Enter the number of the line that you wish to edit." << endl;
        cin >> line;
        if (!cin.fail()) {
          output.edit(line);
          // here is where the editing happens, will return a value based on
          // edit success
        } else {
          cout << "ERROR" << endl;
        }
      }
    } else if (output.lowercase(choice) == "clear") {
      output.deletefile();
    }

  } else {
    cout << "Please enter the phrase write or read for your choice. No spaces "
            "allowed."
         << endl;
    return main();
  }
  output.closefile();
}