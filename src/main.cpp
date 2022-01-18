#include <iostream>
#include <fstream>
#include "robot.h"

using namespace std;
using namespace toyrobot;

void run_script(string script)
{
    Robot robot;

    ifstream fs(script);
    if (!fs)
    {
        cout << "Cannot open file: " << script << endl;
        return;
    }

    string command;
    while (getline(fs, command))
    {
        cout << ">" << command << endl;
        robot.run(command);
    }
}

void run_shell()
{
    Robot robot;

    while (1)
    {
        string command;
        cout << ">";
        getline(cin, command);

        if (command == "exit")
            break;

        robot.run(command);
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        run_script(argv[1]);
    }
    else
    {
        run_shell();
    }

    return 0;
}