#include <iostream>
#include <string>

class Robot
{
protected:
    std::string _nom;
    int _sante;

public:
    Robot(std::string n);
    ~Robot();
    virtual void sePresenter();
    void attaquer(Robot &autre);
    int getVie();
    void modifVie(int difference);
};

class RobotMedecin : public Robot
{
protected:
    int _soins;

public:
    RobotMedecin(std::string n);
    ~RobotMedecin();
    void soigner(Robot &autre);
    virtual void sePresenter();
};

class RobotBerserker : public Robot
{
protected:
    int _degats;

public:
    RobotBerserker(std::string n);
    ~RobotBerserker();
    void toutDefoncer(Robot &autre);
    virtual void sePresenter();
};

class RobotHandicape : public Robot
{
public:
    RobotHandicape(std::string n);
    ~RobotHandicape();
    virtual void sePresenter();
    void utiliserRampeAcces();
};