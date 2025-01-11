
void print_help() {
	cout << "Welcome to the CLI version of the Tower of Hanoi game!\n\n"
		 << "The objective of the game is to move the entire tower from the left pole to the right pole,\n"
	     << "following the rules of the Tower of Hanoi.\n\n"
	     << "How to play:\n"
	     << " - To move a disk, press the letter of the pole where the disk is currently located,\n"
	     << "   followed by the letter of the pole where you want to move it.\n"
	     << " - You can erase an input by pressing the Backspace key.\n\n"
	     << "Rules:\n"
	     << " - A larger disk cannot be placed on top of a smaller disk.\n\n"
	     << "Want more of a challenge?\n"
	     << " - By default, the game starts with 3 disks. You can increase the number of disks by typing:\n"
	     << "     $> hanoi 5\n"
	     << "   Replace '5' with any number to adjust the difficulty.\n\n";
}
