#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <string>

using namespace std;

namespace toyrobot
{

#define DEFAULT_MAX_WIDTH 5
#define DEFAULT_MAX_HEIGHT 5

    //Direction difinition
    typedef enum
    {
        EAST,
        SOUTH,
        WEST,
        NORTH,
        INVALID
    } DIRECTION;

    class Robot
    {
    public:
        Robot();
        Robot(int table_width, int table_height);       //Can define a different table
        ~Robot();

        //Parse and run command
        void run(const string &command);

    private:
        bool _place(int x, int y, DIRECTION f);
        bool _move();
        bool _left();
        bool _right();
        bool _report();

        bool _on_table();
        int _check_place_x(string param);
        int _check_place_y(string param);
        DIRECTION _check_place_f(string param);
        int _string_to_int(string param);               //Convert string parameter to int, return negative value if invalid

    private:
        int _max_width{DEFAULT_MAX_WIDTH};
        int _max_height{DEFAULT_MAX_HEIGHT};

        int _x{-1};
        int _y{-1};
        DIRECTION _f{INVALID};
    };

}
#endif