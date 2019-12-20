#include <iostream>
#include "robot.hpp"
#include <string>
#include <vector>
using namespace std;

void presenter(Robot &r)
{
    r.sePresenter();
}

void createTeam()
{
    vector<Robot *> monEquipe;
    string nom;
    std::cout << "Combien voulez vous de robot classique dans votre équipe ?" << std::endl;
    int nbRobotClassique;
    cin >> nbRobotClassique;

    for (int i = 1; i <= nbRobotClassique; i++)
    {
        cout << "Entrez le nom de votre robot classique numero " << i << " : ";
        cin >> nom;
        monEquipe.push_back(new Robot(nom));
    }

    //********************************FIN ROBOT CLASSIQUE********************************************

    int nbRobotMedecin;
    cin >> nbRobotMedecin;

    for (int i = 1; i <= nbRobotMedecin; i++)
    {
        cout << "Entrez le nom de votre robot médecin numero " << i << " : ";
        cin >> nom;
        monEquipe.push_back(new RobotMedecin(nom));
    }

    //********************************FIN ROBOT MEDECIN********************************************

    int nbRobotBerserker;
    cin >> nbRobotBerserker;

    for (int i = 1; i <= nbRobotBerserker; i++)
    {
        cout << "Entrez le nom de votre robot Berserker numero " << i << " : ";
        cin >> nom;
        monEquipe.push_back(new RobotBerserker(nom));
    }

    //********************************FIN ROBOT BERSERKER********************************************

    int nbRobotHandicape;
    cin >> nbRobotHandicape;

    for (int i = 1; i <= nbRobotHandicape; i++)
    {
        cout << "Entrez le nom de votre robot Handicapé numero " << i << " : ";
        cin >> nom;
        monEquipe.push_back(new RobotHandicape(nom));
    }

    //********************************FIN ROBOT HANDCAPE********************************************
}

int main()
{
    createTeam();
}
