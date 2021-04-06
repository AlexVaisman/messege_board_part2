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

	//Triangle printer
	unsigned int tri_size = 42; //choose size
	
	
	unsigned int column = tri_size*2 + 1;
	unsigned int row = tri_size+1;
	unsigned int spot;
	unsigned int spot_left;
	unsigned int spot_right;

	spot = (unsigned int)(column/2);
	spot_left = spot;
	spot_right = spot;

	for(unsigned int i = 1 ; i<row;i++){
		if(i==1){
			board.post(/*row=*/0, /*column=*/spot, Direction::Horizontal, "0");
		}
		if(i>0 && i<row-1){
		spot_left -- ;
		spot_right ++ ;
		board.post(/*row=*/i, /*column=*/spot_left, Direction::Horizontal, "0");
		board.post(/*row=*/i, /*column=*/spot_right, Direction::Horizontal, "0");
		}
		if(i==row-1){
			for(unsigned int j = 0 ; j <column ; j++){
				board.post(/*row=*/i, /*column=*/j, Direction::Horizontal, "0");
			}
		}
	}
	board.show();
	return 0;
}
