#include <iostream>
#include "robot.hpp"
#include <string>
using namespace std;

Robot::Robot(string n)
{
    _nom = n;
    _sante = 100;
    _degats = 20;
}

void Robot::sePresenter()
{
    cout << "Bonjour, je suis un robot et je m'appelle " << _nom << ". \n Je suis un robot classique mais je sais me battre s'il le faut. Je fais 20 points de degats et j'ai actuellement " << _sante << " points de sante. Je coute 1 UNITE ALGOREENNES\n"
         << endl;
}

int Robot::getVie()
{
    return _sante;
}

void Robot::modifVie(int difference)
{
    _sante += difference;
    if (_sante > 100)
    {
        _sante = 100;
    }

    if (_sante < 0)
    {
        _sante = 0;
    }
}

void Robot::attaquer(Robot *autre)
{
    autre->modifVie(-20);
    cout << _nom << " attaque ";
    autre->showNom();
    cout << " et lui enleve 20 points de vie \n\n";
}

void Robot::showNom()
{
    cout << _nom << endl;
}

void Robot::showStats()
{
    cout << _nom << " ---- " << _sante << " PV"
         << " ---- " << _degats << " points de degats" << endl;
}

Robot::~Robot() {}

//***************************FIN IMPLEMENTATION ROBOT*******************************************************

RobotMedecin::RobotMedecin(string n) : Robot(n)
{
    _sante = 100;
    _soins = 50;
}

void RobotMedecin::soigner(Robot *autre)
{
    autre->modifVie(_soins);
    cout << _nom << " soigne ";
    autre->showNom();
    cout << " et lui rajoute 50 points de vie \n\n";
}

void RobotMedecin::showNom()
{
    cout << _nom << endl;
}

void RobotMedecin::sePresenter()
{
    cout << "Bonjour, je m'appelle " << _nom << ". Je suis un robot medecin. Je soignerai les blessures de mes compagnons. \n Je restaure 50 points de sante et j'ai actuellement " << _sante << " points de sante. Je coute 4 UNITES ALGOREENNES\n"
         << endl;
}

void RobotMedecin::showStats()
{
    cout << _nom << " ---- " << _sante << " PV";
    cout << " ---- " << _soins << " points de soins" << endl;
}

RobotMedecin::~RobotMedecin() {}

//***************************************FIN IMPLEMENTATION MEDECIN********************************************

RobotBerserker::RobotBerserker(string n) : Robot(n)
{
    _sante = 100;
    _degats = 75;
}

void RobotBerserker::sePresenter()
{
    cout << "HAA, je suis " << _nom << " le Berserker ! Je vais casser du Robot et ma sante actuelle est de " << _sante << " points.\n"
         << "Je fais " << _degats << " points de degats et je coute 6 UNITES ALGOREENNES.\n"
         << endl;
}

void RobotBerserker::showNom()
{
    cout << _nom << endl;
}

void RobotBerserker::toutDefoncer(Robot *autre)
{
    autre->modifVie(-75);
    cout << _nom << " defonce ";
    autre->showNom();
    cout << " et lui enleve 75 points de vie \n\n";
}

void RobotBerserker::showStats()
{
    cout << _nom << " ---- " << _sante << " PV"
         << " ---- " << _degats << " points de degats" << endl;
}

RobotBerserker::~RobotBerserker() {}

//***********************************FIN IMPLEMENTATION BERSERKER**********************************************

RobotHandicape::RobotHandicape(string n) : Robot(n)
{
    _sante = 5;
}

void RobotHandicape::sePresenter()
{
    cout << "Bonjour, je ne suis qu'un amas de pièce detachees, je suis " << _nom << " le Robot handicape ! \n Je ne fais rien de special, part couter de l'argent au contribuable et la corporation Xerca. \n Personne ne me choisit, mais je coute de l'argent, c'est benef pour moi! \n D'ailleurs je n'ai que " << _sante << " points de sante et je ne peux pas être soigne. Je coute 11 UNITES ALGOREENNES\n"
         << endl;
}

void RobotHandicape::utiliserRampeAcces()
{
    std::cout << "Oh mais vous avez pris un robot handicape ?!! Quel gaspillage d'unites!! Mais quelle intuition.... \n En effet le robot handicape peut utiliser la super rampe d'accès inter-planetaire et vous mener tout droit jusqu'au tresor! \n Felicitation, une fois que vous utiliserez cette rampe vous serez riche ! Votre aventure est terminee :)" << std::endl;
}

void RobotHandicape::showStats()
{
    cout << _nom << " ---- " << _sante << " PV" << endl;
}

RobotHandicape::~RobotHandicape() {}

//********************************** FIN IMPLEMENTATION LEGUME***************************************************
