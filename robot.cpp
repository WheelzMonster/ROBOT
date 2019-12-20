#include <iostream>
#include "robot.hpp"
#include <string>
using namespace std;

Robot::Robot(string n)
{
    _nom = n;
    _sante = 100;
}

void Robot::sePresenter()
{
    cout << "Bonjour, je suis un robot et je m'appelle " << _nom << ". Je suis un robot classique mais je sais me battre s'il le faut. Je fais 20 points de dégâts et j'ai actuellement " << _sante << " points de santé." << endl;
}

int Robot::getVie()
{
    return _sante;
}

void Robot::modifVie(int difference)
{
    _sante += difference;
}

void Robot::attaquer(Robot &autre)
{
    autre.modifVie(-20);
}

Robot::~Robot() {}

//***************************FIN IMPLEMENTATION ROBOT*******************************************************

RobotMedecin::RobotMedecin(string n) : Robot(n)
{
    _sante = 100;
}

void RobotMedecin::soigner(Robot &autre)
{
    autre.modifVie(50);
}

void RobotMedecin::sePresenter()
{
    cout << "Bonjour, je suis un robot et je m'appelle " << _nom << ". Je suis un robot médecin. Je soignerai les blessures de mes compagnons. Je restaure 50 points de santé et j'ai actuellement " << _sante << " points de santé." << endl;
}

RobotMedecin::~RobotMedecin() {}

//***************************************FIN IMPLEMENTATION MEDECIN********************************************

RobotBerserker::RobotBerserker(string n) : Robot(n)
{
    _sante = 150;
}

void RobotBerserker::sePresenter()
{
    cout << "HAA, je suis " << _nom << " le Berserker ! Je vais casser du Robot et ma santé actuelle est de " << _sante << " points" << endl;
}

void RobotBerserker::toutDefoncer(Robot &autre)
{
    autre.modifVie(-75);
}

RobotBerserker::~RobotBerserker() {}

//***********************************FIN IMPLEMENTATION BERSERKER**********************************************

RobotHandicape::RobotHandicape(string n) : Robot(n)
{
    _sante = 5;
}

void RobotHandicape::sePresenter()
{
    cout << "Bonjour, je ne suis qu'un amas de pièce détachées, je suis " << _nom << " le Robot handicapé ! Je ne fais rien de spécial, à part coûter de l'argent au contribuable et à la corporation Xerca. Personne ne me choisit, mais je coute de l'argent, c'est benef pour moi! D'ailleurs je n'ai que " << _sante << " points de santé et je ne peux pas être soigné." << endl;
}

RobotHandicape::~RobotHandicape() {}

//********************************** FIN IMPLEMENTATION LEGUME***************************************************
