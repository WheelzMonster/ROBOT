#include <iostream>
#include "robot.hpp"
#include <string>
#include <vector>
using namespace std;

void presenter(Robot &r)
{
    r.sePresenter();
}

int main()
{
    Robot r("Bob");
    RobotBerserker i("Ivar");
    presenter(r);
    presenter(i);
}
