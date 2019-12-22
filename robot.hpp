#include <iostream>
#include <string>

class Robot
{
protected:
    std::string _nom;
    int _sante;
    int _degats;

public:
    Robot(std::string n);
    ~Robot();
    virtual void sePresenter();
    void attaquer(Robot *autre);
    void showNom();
    int getVie();
    void modifVie(int difference);
    void showStats();
};

class RobotMedecin : public Robot
{
protected:
    int _soins;

public:
    RobotMedecin(std::string n);
    ~RobotMedecin();
    void showNom();
    void soigner(Robot *autre);
    virtual void sePresenter();
    void showStats();
};

class RobotBerserker : public Robot
{

public:
    RobotBerserker(std::string n);
    ~RobotBerserker();
    void showNom();
    void toutDefoncer(Robot *autre);
    virtual void sePresenter();
    void showStats();
};

class RobotHandicape : public Robot
{
public:
    RobotHandicape(std::string n);
    ~RobotHandicape();
    virtual void sePresenter();
    void utiliserRampeAcces();
    void showStats();
};