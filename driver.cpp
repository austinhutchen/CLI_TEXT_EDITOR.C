#include "functions.h"
int main(int argc, char *argv[]) {
  std::string choice;
  std::string input;
  int line;
  bool f;
  int curtime = time(NULL);
  if(argc<2){
    std::cout << "INVALID execution. Include filename using ./a.out {filename}" << std::endl;
    return 0;
      }
  std::string filename=argv[1];
  send output(filename);
  // file is now open for all read/write operations
  std::cout << "Would you like to write, or read from this file? Type WRITE for write, CLEAR to delete a file,and READ for read. Type LEAVE to exit program."<< std::endl;
  std::cin >> choice;
  if (!std::cin.fail()) {
    if (output.lowercase(choice) == "write") {
      std::cout << "Begin typing below. Type ENTER to type on a new line, or EXIT to quit."<< std::endl;
      std::cin.ignore();
      while (getline(std::cin, input)) {
        if (input != "EXIT") {
          f = output.print(input);
        } else {
          break;
        }
      };
      // splitstring here to check for new line
      //  getline automatically starts newline
      if (f == true) {
        std::cout << "Text succesfully written." << std::endl;
      } else {
        std::cout << "ERROR: Text failed to write." << std::endl;
        return main(argc,argv);
      }
    } else if (output.lowercase(choice) == "read") {
      output.readfile();
      std::cout << "Would you like to edit this file? y/n" << std::endl;
      std::cin >> choice;
      if (choice == "y" || choice == "Y") {
        std::cout << "Enter the number of the line that you wish to edit." << std::endl;
        std::cin >> line;
        if (!std::cin.fail()) {
          output.edit(line);
          // here is where the editing happens, will return a value based on
          // edit success
        } else {
          std::cout << "ERROR" << std::endl;
        }
      }
    } else if (output.lowercase(choice) == "clear") {
      output.deletefile();
    }
    else if (output.lowercase(choice) == "leave") {
      return -1;
    }

  } else {
    std::cout << "Please enter the phrase write or read for your choice. No spaces allowed."<< std::endl;
    return main(argc,argv);
  }
  output.closefile();
}