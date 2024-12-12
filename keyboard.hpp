#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

// Fonction pour désactiver le buffering du terminal
void enableNonBlockingMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;  // Désactive le mode canonique
    term.c_lflag &= ~ECHO;    // Désactive l'écho
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Fonction pour restaurer le mode normal du terminal
void disableNonBlockingMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;   // Réactive le mode canonique
    term.c_lflag |= ECHO;     // Réactive l'écho
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Fonction pour vérifier si une touche est pressée et lire la touche
bool keyIsPressed(char &key) {
    // Configure STDIN en mode non-bloquant
    int oldFlags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, oldFlags | O_NONBLOCK);

    int bytesRead = read(STDIN_FILENO, &key, 1);

    // Rétablir le mode de blocage
    fcntl(STDIN_FILENO, F_SETFL, oldFlags);

    return bytesRead == 1;
}