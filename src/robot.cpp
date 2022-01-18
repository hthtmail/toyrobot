#include "robot.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

namespace toyrobot
{

    vector<string> direction_str = {"EAST", "SOUTH", "WEST", "NORTH"};

    Robot::Robot()
    {
    }

    Robot::Robot(int table_width, int table_height)
        : _max_width(table_width), _max_height(table_height)
    {
    }

    Robot::~Robot()
    {
    }

    void Robot::run(const string &command)
    {
        vector<string> command_strings;
        stringstream input(command);
        string temp;

        while (getline(input, temp, ' '))
        {
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);   //Convert command to lower case
            command_strings.push_back(temp);
        }

        if (command_strings.empty())
        {
            return;
        }

        if (command_strings[0] == "place")
        {
            if (command_strings.size() < 4)
            {
                return;
            }
            // Check parameters
            int x = _check_place_x(command_strings[1]);
            int y = _check_place_y(command_strings[2]);
            DIRECTION f = _check_place_f(command_strings[3]);
            _place(x, y, f);
        }
        else if (command_strings[0] == "move")
        {
            _move();
        }
        else if (command_strings[0] == "left")
        {
            _left();
        }
        else if (command_strings[0] == "right")
        {
            _right();
        }
        else if (command_strings[0] == "report")
        {
            _report();
        }
        else
        {
            cout << "ERROR: Invalid command: " << command << endl;
        }
    }

    bool Robot::_place(int x, int y, DIRECTION f)
    {
        if ((0 <= x && x < _max_width) && (0 <= y && y < _max_height) && (EAST <= f && f < INVALID))
        {
            _x = x;
            _y = y;
            _f = f;
            return true;
        }

        cout << "ERROR: Invalid parameters for PLACE" << endl;

        return false;
    }

    bool Robot::_move()
    {
        if (!_on_table())
        {
            cout << "IGNORE: Robot is not on the table" << endl;
            return false;
        }

        switch (_f)
        {
        case EAST:
            if (_x < _max_width - 1)
            {
                _x++;
                return true;
            }
            break;
        case WEST:
            if (0 < _x)
            {
                _x--;
                return true;
            }
            break;
        case NORTH:
            if (_y < _max_height - 1)
            {
                _y++;
                return true;
            }
            break;
        case SOUTH:
            if (0 < _y)
            {
                _y--;
                return true;
            }
            break;
        }

        cout << "DANGER: Robot cannot move forward" << endl;

        return false;
    }

    bool Robot::_left()
    {
        if (!_on_table())
        {
            cout << "IGNORE: Robot is not on the table" << endl;
            return false;
        }

        _f = static_cast<DIRECTION>((_f + 3) % 4);

        return true;
    }

    bool Robot::_right()
    {
        if (!_on_table())
        {
            cout << "IGNORE: Robot is not on the table" << endl;
            return false;
        }

        _f = static_cast<DIRECTION>((_f + 1) % 4);

        return true;
    }

    bool Robot::_report()
    {
        if (!_on_table())
        {
            cout << "IGNORE: Robot is not on the table" << endl;
            return false;
        }

        cout << "Current Position: [" << _x << ", " << _y << "], Face To " << direction_str[static_cast<int>(_f)] << endl;

        return true;
    }

    bool Robot::_on_table()
    {
        return (0 <= _x && _x < _max_width) && (0 <= _y && _y < _max_height) && (EAST <= _f && _f < INVALID);
    }

    int Robot::_check_place_x(string param)
    {
        return _string_to_int(param);
    }

    int Robot::_check_place_y(string param)
    {
        return _string_to_int(param);
    }

    DIRECTION Robot::_check_place_f(string param)
    {
        if (param == "east" || param == "e")
        {
            return EAST;
        }
        else if (param == "west" || param == "w")
        {
            return WEST;
        }
        else if (param == "south" || param == "s")
        {
            return SOUTH;
        }
        else if (param == "north" || param == "n")
        {
            return NORTH;
        }
        return INVALID;
    }

    int Robot::_string_to_int(string param)
    {
        int n;

        try
        {
            n = stoi(param);
        }
        catch (...)
        {
            n = -999999;
        }
        return n;
    }

}