#pragma once
#include "Direction.hpp"
#include <string>
#include <vector>
#include <map>

namespace ariel{

    class Board{

        public:
        Board();
        ~Board();
        void post(unsigned int row,unsigned int column, Direction direction , const std::string& messege);
        std::string read(unsigned int row,unsigned int column, Direction direction , unsigned int length);
        void show();

        private:
        std::map<std::string ,std::string > map;
        void set_min_max(unsigned int x ,unsigned int y);

        unsigned int MIN_X = UINT32_MAX;
        unsigned int MIN_Y = UINT32_MAX;
        unsigned int MAX_X = 0;
        unsigned int MAX_Y = 0;
        unsigned int DEF_X = 5;
        unsigned int DEF_Y = 5;
        unsigned int DEF_SPACE = 6;

    };

}