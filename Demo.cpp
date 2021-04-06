/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	ariel::Board board;
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "ismore");

	//cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/5) << endl;  
		// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	//cout << board.read(/*row=*/1002, /*column=*/2002, Direction::Horizontal, /*length=*/5) << endl;  
	board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "less");

	//cout << board.read(/*row=*/99, /*column=*/202, Direction::Vertical, /*length=*/6) << endl;  

	board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________
		return 0;
}

