#include "Direction.hpp"
#include "Board.hpp"
#include <string>
#include <map>
#include <iostream>

using namespace ariel;
namespace ariel{
    
    Board::Board(){
    }

    void Board::set_min_max(unsigned int x ,unsigned int y){
        if(x>MAX_X){
            MAX_X = x;
        }
        if(y>MAX_Y){
            MAX_Y = y;
        }
        if(x<MIN_X){
            MIN_X = x;
        }
        if(y<MIN_Y){
            MIN_Y = y;
        }
    }


    // this function post a string on the board, first it checks the direction then it puts into map the row and coloum as key
    // and the messege as the value.
    void Board::post(unsigned int row,unsigned int column, Direction direction , const std::string& messege){
        if(direction ==Direction::Horizontal){
            for(unsigned int i = column ; i<column+messege.length();i++){
                set_min_max(i,row);
                map[std::to_string(row)+","+std::to_string(i)] = messege[i-column];  
            }
        }
        else if(direction ==Direction::Vertical){
            for(unsigned int i = row ; i<row+messege.length();i++){
                set_min_max(column,i);
                map[std::to_string(i)+","+std::to_string(column)] = messege[i-row];
            }
        }
    }

    // this function reads from the map the messege posted depending on direction and length
    std::string Board::read(unsigned int row,unsigned int column, Direction direction , unsigned int length){
        std::string post ;


        if(direction ==Direction::Horizontal){

            for(unsigned int i = column ; i<column+length;i++){
                if(map[std::to_string(row)+","+std::to_string(i)].empty()){
                    post += "_";
                    map.erase(std::to_string(row)+","+std::to_string(i));
                }
                else{
                    post += map[std::to_string(row)+","+std::to_string(i)];
                }
                
            }
        }else if(direction ==Direction::Vertical){

            for(unsigned int i = row ; i<row+length ; i++){
                if(map[std::to_string(i)+","+std::to_string(column)].empty()){
                     post += + "_";
                     map.erase(std::to_string(i)+","+std::to_string(column));
                }
                else{
                    post +=  map[std::to_string(i)+","+std::to_string(column)];
                }
                
            }
        }
        return post;
    }

    void Board::show(){
    std::string space;

        //checking if board is empty , and printing empty board.
        if(map.empty()){
            for(unsigned int row = 0 ;row <= DEF_Y ; row++){
                for(unsigned int column = 0 ; column <= DEF_X ; column++){

                        std::cout<<"_";

                }
                std::cout<<std::endl;
            }
            return;
        }

        //printing board.
        for(unsigned int row = MIN_Y ;row <= MAX_Y ; row++){
            //printing row number with spaces
            space = std::to_string(row);
            if(space.length()<DEF_SPACE){
                while(space.length()!= DEF_SPACE){
                    space+=" ";
                }
            }
        std::cout<<space;

            //printing letters
            for(unsigned int column = MIN_X ; column <= MAX_X ; column++){
                if(map[std::to_string(row)+","+std::to_string(column)].empty()){
                    map.erase(std::to_string(row)+","+std::to_string(column));
                    std::cout<<"_";
                }
                else{
                    std::cout<<map[std::to_string(row)+","+std::to_string(column)];
                }
            }
            std::cout<<std::endl;
        }
        
    }
    Board::~Board(){ 
    };
}