
void print_help() {
	// cout << "This is a CLI version of the Hanoi tower game\nThe goal is to move the entire tower from the left pole to the right pole\n\nYou can move a disk by pressing on your keyboard the letter of the pole where come the disk,\n and secondly the letter of the pole where you want it to go.\nYou can remove a input by pressing Backspace.\n\nA disk cannot go on top of a thinner disk\n\nFinally, if you want more challenge, you can type :\n  $>hanoi 5\nor more to add disk and with it difficulty\n\n";

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
