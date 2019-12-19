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
    cout << "Bonjour, je suis un robot et je m'appelle " << _nom << ". Je suis un robot classique mais je sais me battre s'il le faut.";
}

int Robot::getVie()
{
    return _sante;
}

void Robot::modifVie(int difference)
{
    _sante += difference;
}

//***************************FIN IMPLEMENTATION ROBOT*******************************************************

RobotMedecin::RobotMedecin(string n) : Robot(n)
{
    _sante = 125;
}

void RobotMedecin::soigner(Robot &autre)
{
    autre.modifVie(50);
}

void RobotMedecin::sePresenter()
{
    cout << "Bonjour, je suis un robot et je m'appelle " << _nom << ". Je suis un robot médecin. Je soignerai les blessures de mes compagnons.";
}

//***************************************FIN IMPLEMENTATION MEDECIN********************************************

RobotBerserker::RobotBerserker(string n) : Robot(n)
{
    _sante = 125;
}

void RobotBerserker::sePresenter()
{
    cout << "HAA, je suis " << _nom << " le Berserker ! Je vais casser du Robot!";
}

//***********************************FIN IMPLEMENTATION BERSERKER**********************************************

RobotHandicape::RobotHandicape(string n) : Robot(n)
{
    _sante = 5;
}

void RobotHandicape::sePresenter()
{
    cout << "Bonjour, je ne suis qu'un amas de pièce détachées, je suis" << _nom << " le Robot handicapé ! Je ne fais rien de spécial, à part coûter de l'argent au contribuable et à la corporation Xerca, il faudrai être fou pour me choisir! Mais qui est le plus fou des deux ? Le fou ou celui qui l'écoute ?";
}

//********************************** FIN IMPLEMENTATION LEGUME***************************************************
