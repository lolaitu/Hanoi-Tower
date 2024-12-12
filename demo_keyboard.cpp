#include <iostream>

#include "keyboard.hpp"

int main(int argc, char** argv) {
  enableNonBlockingMode();
  while (true) {
    int f, s;
    char key;

    cout << " ";

    while (true){
    if(keyIsPressed(key)){
        if (key == 127){
          cout << key << '\n';
        }
      }
    }
  }
  disableNonBlockingMode();

  return 0;
}