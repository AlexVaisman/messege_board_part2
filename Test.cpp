#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
#include <string>
#include <algorithm>

using namespace ariel;


TEST_CASE("Checking good input horizontal"){
    Board board;

    for(unsigned int i = 0 ; i<1000;i++){
        for(unsigned int j = 0 ; j<1000;j++){
            //posting messege
        CHECK_NOTHROW(board.post(i , j , Direction::Horizontal, "messege_"+std::to_string(i)));
            //reading messege
        CHECK_NOTHROW(board.read(i, j, Direction::Horizontal, 30));
        }
    }
    //checking that board shows
    CHECK_NOTHROW(board.show());
}

TEST_CASE("Checking good input vertical"){
    Board board2;

    for(unsigned int i = 0 ; i<1000;i++){
        for(unsigned int j = 0 ; j<1000;j++){
            //posting messege
        CHECK_NOTHROW(board2.post(i , j , Direction::Vertical, "messege_"+std::to_string(i)));
            //reading messege
        CHECK_NOTHROW(board2.read(i, j, Direction::Vertical, 30));
        }
    }
    //checking that board shows
    CHECK_NOTHROW(board2.show());
}

TEST_CASE("Checking input equales to output horizontal"){
    Board board3;

    for(unsigned int i = 0 ; i<100;i++){
        for(unsigned int j = 0 ; j<100;j++){
            //posting messege
        CHECK_NOTHROW(board3.post(i , j , Direction::Horizontal, "messege_"+std::to_string(i)));
            //reading messege
        CHECK(board3.read(i, j, Direction::Horizontal, 30) == ("messege_"+std::to_string(i)));
        }
    }
}

TEST_CASE("Checking input equales to output vertical"){
    Board board3;

    for(unsigned int i = 0 ; i<100;i++){
        for(unsigned int j = 0 ; j<100;j++){
            //posting messege
        CHECK_NOTHROW(board3.post(i , j , Direction::Vertical, "messege_"+std::to_string(i)));
            //reading messege
        CHECK(board3.read(i, j, Direction::Vertical, 30) == ("messege_"+std::to_string(i)));
        }
    }
}