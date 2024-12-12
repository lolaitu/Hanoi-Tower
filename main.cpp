#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

#include "keyboard.hpp"

using namespace std;

void gobackNline(int n){
  printf("%c[%dA",0x1B,n);
}

void _show_part(int nb, int size){
  if (nb == 0){
    for (int i = 0; i < (size); i++){ cout << " "; }
    cout << "|";
    for (int i = 0; i < (size); i++){ cout << " "; }
  } else {
    for (int i = 0; i < (size - nb); i++){ cout << " "; }
    cout << "\033[" << 31 + nb % 7 << "m";
    cout << "[";
    for (int i = 0; i < ((nb - 1) * 2 +1); i++){ cout << "#"; }
    cout << "]";
    cout << "\033[" << 97 << "m";
    for (int i = 0; i < (size - nb); i++){ cout << " "; }
  }
  
}

void show_hanoi(const vector<vector<int>> tab, int const size){
  cout << endl;
  for (int j = size-1; j >= 0; j--){
    for (int i = 0; i < 3; i++){
      cout << ' ';
      _show_part(tab[i][j], size);
    }
    cout << endl;
  }
  char keybind[3] = {'j', 'k', 'l'};
  for (int key = 0; key < 3; key++){
    cout << ' ';
    for (int i = 0; i < (size); i++){ cout << "_"; }
    cout << keybind[key];
    for (int i = 0; i < (size); i++){ cout << "_"; }
  }
  cout << endl << endl;
}

void debug_show_hanoi(const vector<vector<int>> tab, int const size){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < size; j++){
      cout << tab[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int key_2_int(char const key){
  switch (key) {
    case 'j':
      return 0;
    case 'k':
      return 1;
    case 'l':
      return 2;
    case 127:
      return 9;
    default :
      return -1;
  }
}

pair<int, int> ask_colum(){
  int f, s;
  char key;

  while (1){
    while (true){
      if(keyIsPressed(key)){
        int value = key_2_int(key);
        if (value != -1 and value != 9){
          f = value;
          break;
        }
      }
    }
    cout << '\r' << "      " << '\r';
    fflush(stdout);
    cout << ' ' << key << ' ';
    fflush(stdout);
    while (true){
      if(keyIsPressed(key)){
        int value = key_2_int(key);
        if (value != -1){
          if (value == 9){
            cout << '\r' << "      " << '\r';
            fflush(stdout);
            break; // pass (go to the begining)
          } else if (value != f) {
            s = value;
            cout << "| " << key << ' ';
            return {f, s};
            break;
          }
        }
      }
    }
  }
}

int _index_top(const vector<int> colum, int const size){
  for (int i = size-1; i >= 0; i--){
    if (colum[i] != 0){
      return i;
    }
  }
  return -1;
}

bool move_disc(vector<vector<int>>& tab, int const size,
               const pair<int, int> paircol){
  if (tab[paircol.second][_index_top(tab[paircol.second], size)] < 
      tab[paircol.first][_index_top(tab[paircol.first], size)]
      && tab[paircol.second][_index_top(tab[paircol.second], size)] != 0){
    return false;
  }
  tab[paircol.second][_index_top(tab[paircol.second], size) + 1] = 
    tab[paircol.first][_index_top(tab[paircol.first], size)];
  tab[paircol.first][_index_top(tab[paircol.first], size)] = 0;
  return true;
}

bool not_finished(const vector<vector<int>> tab, int const size){
  for (int i = 0; i < size; i++){
    if (tab[2][i] != size - i){
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]){
  int difficulty = 4;
  
  if (argc >= 2){
    if (strcmp(argv[1], "--help") == 0){
      cout << "figure it out yourself moron !!!" << endl;
      return 0;
    } else {
      try {
        difficulty = stoi(argv[1]);
      } catch ( ... ) { difficulty = -1; }
    }
  }

  if ( difficulty < 1 || 16 < difficulty ){
    cout << "Please set in parameter a raisonable and strictly positive number" << endl;
    return 1;
  }
  if ( difficulty > 6 ){
    cout << "You will burp blood. Are you sure ? (y/n) : ";
    char validation;
    cin >> validation;
    if (validation != 'y'){
      cout << "Abording the mission" << endl;
      return 1;
    }
    gobackNline(1);
  }

  // Main code ###############################################################
  vector<vector<int>> tab(3, vector<int>(difficulty, 0));
  for (int i = 0; i < difficulty; i++){
    tab[0][i] = difficulty - i;
  }

  bool done = true;
  enableNonBlockingMode();

  show_hanoi(tab, difficulty);
  while (not_finished(tab, difficulty)){
    
    auto colum_to_change = ask_colum();

    done = move_disc(tab, difficulty, colum_to_change);
    
    if (done){
      gobackNline(difficulty + 3);
      show_hanoi(tab, difficulty);
    }
  }

    
  disableNonBlockingMode();

  return 0;
}