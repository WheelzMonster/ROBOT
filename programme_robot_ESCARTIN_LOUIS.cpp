#include <iostream>
#include "robot.hpp"
#include <string>
#include <vector>
using namespace std;

vector<Robot *> monEquipeClassique;
vector<RobotBerserker *> monEquipeBerserker;
vector<RobotMedecin *> monEquipeMedecin;
vector<RobotHandicape *> monEquipeHandicape;
vector<Robot *> equipeEnnemieClassique;
vector<RobotBerserker *> equipeEnnemieBerserker;
bool game = true;

void presenter(Robot &r)
{
    r.sePresenter();
}

void createTeam()
{
    string nom;
    int nbUnites = 12;

    std::cout << "Combien voulez vous de robot classique dans votre equipe ?" << std::endl;
    int nbRobotClassique;
    cin >> nbRobotClassique;
    nbUnites -= nbRobotClassique;

    if (nbUnites >= 0)
    {
        for (int i = 1; i <= nbRobotClassique; i++)
        {
            cout << "Entrez le nom de votre robot classique numero " << i << " : ";
            cin >> nom;
            monEquipeClassique.push_back(new Robot(nom));
        }
        std::cout << "il te reste: " << nbUnites << " unites" << std::endl;
    }

    else
    {
        cout << "Tu n'as pas assez d'unites! Et tes credits republicains ne font toujours pas l'affaire!\n Tu te moques de moi je ne te vendrai plus rien. Pars a l'aventure maintenant! Bonne chance, tu en auras besoin.\n\n";
        return;
    }

    //********************************FIN ROBOT CLASSIQUE********************************************
    std::cout << "combien voulez-vous de medecin?" << std::endl;
    int nbRobotMedecin;
    cin >> nbRobotMedecin;
    nbUnites -= (nbRobotMedecin * 4);

    if (nbUnites >= 0)
    {
        for (int i = 1; i <= nbRobotMedecin; i++)
        {
            cout << "Entrez le nom de votre robot medecin numero " << i << " : ";
            cin >> nom;
            monEquipeMedecin.push_back(new RobotMedecin(nom));
        }
        std::cout << "il te reste: " << nbUnites << " unites" << std::endl;
    }

    else
    {
        cout << "Tu n'as pas assez d'unites! Et tes credits republicains ne font toujours pas l'affaire! \n Tu te moques de moi je ne te vendrai plus rien. Pars a l'aventure maintenant! Bonne chance, tu en auras besoin.\n\n";
        return;
    }
    //********************************FIN ROBOT MEDECIN********************************************

    std::cout << "combien voulez-vous de robot Berserker?" << std::endl;
    int nbRobotBerserker;
    cin >> nbRobotBerserker;
    nbUnites -= (nbRobotBerserker * 6);

    if (nbUnites >= 0)
    {

        for (int i = 1; i <= nbRobotBerserker; i++)
        {
            cout << "Entrez le nom de votre robot Berserker numero " << i << " : ";
            cin >> nom;
            monEquipeBerserker.push_back(new RobotBerserker(nom));
        }
        std::cout << "il te reste: " << nbUnites << " unites" << std::endl;
    }

    else
    {
        cout << "Tu n'as pas assez d'unites! Et tes credits republicains ne font toujours pas l'affaire! \n Tu te moques de moi je ne te vendrai plus rien. Pars a l'aventure maintenant! Bonne chance, tu en auras besoin.\n\n";
        return;
    }

    //********************************FIN ROBOT BERSERKER********************************************

    std::cout << "combien voulez-vous de robot handicape ?" << std::endl;
    int nbRobotHandicape;
    cin >> nbRobotHandicape;
    nbUnites -= (nbRobotHandicape * 11);

    if (nbUnites >= 0)
    {
        for (int i = 1; i <= nbRobotHandicape; i++)
        {
            cout << "Entrez le nom de votre robot Handicape numero " << i << " : ";
            cin >> nom;
            monEquipeHandicape.push_back(new RobotHandicape(nom));
        }
    }

    else
    {
        cout << "Tu n'as pas assez d'unites! Et tes credits republicains ne font toujours pas l'affaire! \n Tu te moques de moi je ne te vendrai plus rien. Pars a l'aventure maintenant! Bonne chance, tu en auras besoin.\n\n";
        return;
    }

    //********************************FIN ROBOT HANDCAPE********************************************
}

void showTeam()
{
    for (unsigned int i = 0; i < monEquipeClassique.size(); i++)
    {
        monEquipeClassique[i]->sePresenter();
        std::cout << "\n\n";
    }

    for (unsigned int i = 0; i < monEquipeMedecin.size(); i++)
    {
        monEquipeMedecin[i]->sePresenter();
        std::cout << "\n\n";
    }

    for (unsigned int i = 0; i < monEquipeBerserker.size(); i++)
    {
        monEquipeBerserker[i]->sePresenter();
        std::cout << "\n\n";
    }

    for (unsigned int i = 0; i < monEquipeHandicape.size(); i++)
    {
        monEquipeHandicape[i]->sePresenter();
        std::cout << "\n\n";
    }
}

void showTeamstats()
{
    cout << "voici les statistiques de votre equipe : \n\n";

    for (unsigned int i = 0; i < monEquipeClassique.size(); i++)
    {
        monEquipeClassique[i]->showStats();
        std::cout << "\n\n";
    }

    for (unsigned int i = 0; i < monEquipeMedecin.size(); i++)
    {
        monEquipeMedecin[i]->showStats();
        std::cout << "\n\n";
    }

    for (unsigned int i = 0; i < monEquipeBerserker.size(); i++)
    {
        monEquipeBerserker[i]->showStats();
        std::cout << "\n\n";
    }

    for (unsigned int i = 0; i < monEquipeHandicape.size(); i++)
    {
        monEquipeHandicape[i]->showStats();
        std::cout << "\n\n";
    }
}

void killRobot() // cette fonction servira si à la suite d'un mauvais choix, je decide qu'un robot meurt à coup sur.
{
    if (!monEquipeClassique.empty())
    {
        monEquipeClassique.pop_back();
        cout << "Un de vos robots classique est mort :(" << endl;
    }
    else if (!monEquipeMedecin.empty())
    {
        monEquipeMedecin.pop_back();
        cout << "Un de vos robots medecin est mort :(" << endl;
    }
    else if (!monEquipeBerserker.empty())
    {
        monEquipeBerserker.pop_back();
        cout << "Un de vos robots Berserker est mort :(" << endl;
    }
}

void allRobotsAreDead()
{
    if (monEquipeClassique.empty() && monEquipeBerserker.empty())
    {
        cout << "Vous n'avez plus, ou n'avez jamais eu de robot capable de se battre. \n s'il vous restait une equipe de medecin, ils se sont deja fait detruire par le monde cruel d'algorea. Votre aventure est finie." << endl;
        game = false;
    }
}

int main()
{
    cout << "Ah! Salut Thierry! Euh... voyageur ! Salut voyageur ! \n\n Je suppose que tu es la pour le tresor ? Mais quel tresor me diras-tu ? \n\n Celui d'Algorea bienr! La planete des maths et de l'algorithmie ! Cette planete qui existe depuis bien longtemps dans une galaxie lointaine, tres lointaine! \n\n Mais tu ne peux y aller seul, pauvre fou! Ce tresor est garde par le grand dragon tueur ancestral (oui c'est long comme nom mais ça claque) Clairus Perrotus \n\n Si tu decides d'y aller seul elle ne fera qu'une bouchee de toi ! \n\n Par chance, j'ai plusieurs pieces qui pourraient t'interesser ! Comme un generateur hyperdrive D-14, je suis le seul a en avoir un comme ça dans le coin! \n\n Non ? Bon d'accord ! et pourquoi pas ça ? \n\n cette gamme de robot de type HK- ! J'ai plusieurs modeles, regardent ces 4 modeles de presentation et j'irai en chercher dans mon stock: \n\n  " << endl;

    Robot archi("archi");
    RobotMedecin igor("Igor");
    RobotBerserker Nestor("Nestor");
    RobotHandicape Harry("Harry");

    presenter(archi);
    presenter(igor);
    presenter(Nestor);
    presenter(Harry);

    // cout << "Je ne prends pas les credits republicains ! Tu n'as que 12 unites alogeennes ? Choisis bien dans ce cas! \n Parce que je repete : les credits republicains NE FERONT PAS L'AFFAIRE! \n Tu te prends pour un jedi ou quoi ? A faire des passes avec les mains comme ca ? Choisis !\n\n"
    //      << endl;
    // cout << " Voix off : Attention, ce marchand est tres capricieux! Si tu lui demande quelque chose et que tu ne peux pas payer, il s'enervera et ne te vendra rien. \n\n regardes bien le prix de chaque robot et ton nombre d'unite avant de faire une offre pour etre sur qu'elle soit valable, sinon tu pourrai te retrouver sans robot.\n\n Il est egalement conseiller de prendre au moins un robot classique ou un berserker car ils savent se battre. \n\n Si vous ne prenez que des robots medecin ou handicapes, vous serez incapable de vous defendre.\n\n"
    //      << endl;
    //createTeam();
    //showTeam(); en cas ou je voudrai que les robots achetés se présentent, mais c'est répétitif
    //showTeamstats();

    while (game)
    {
        cout << "Voix off: Vous vous trouvez desormais a bord de l'endar spire, le vaisseau de transport qui vous enmenera sur Algorea, vous debordez d'impatience a l'approche de cette grande aventure!\n\n En arrivant, vous etes recu par l'officier de terrain : Herbert Moon. \n Il n'arrete pas d'hurler : 'vous ne pouvez pas me tuer! Je suis HERBERT MOOOOOOOOOOOOOOOOOOOOOOOOOON' Il a visiblement un serieux probleme... \n\n Son visage etait tout defonce, il a surement du se faire tabasser apres une partie de poker. Il s'approche de vous et dit: \n"
             << endl;

        if (!monEquipeHandicape.empty())
        {
            monEquipeHandicape[0]->utiliserRampeAcces();
            game = false;
        }
        else
        {
            int herbertMoonEncounter;
            cout << "*avec un accent de plouc* qu'ez'fet la vous ? on aime pas ti les etrangers par ici! et pi c'est quoi ces robots la ? je les veux moi" << endl;
            cout << "3 choix s'offrent à vous: \n\n 1: faire une passe avec la main et dire 'ce ne sont pas ces robots que vous recherchez, nous pouvons circuler'\n\n 2: lui eclater la gueule \n\n 3: Baah.. Lui eclater la gueule ?\n\n"
                 << endl;
            cout << "choisissez votre choix en entrant le chiffre du choix: \n\n";

            cin >> herbertMoonEncounter;

            if (herbertMoonEncounter == 1)
            {
                cout << "Tout en faisant un geste avec la main, Herbert dit 'Ce ne sont pas les robots que je recherche. \n Circulez! allons, circulez! \n"
                     << endl;
            }
            else
            {
                cout << "En essayant de lui casser la gueule, il s'enerve et tue un de vos robots. Vous pensiez faire le poids ? vous n'etes pas M. Marston!" << endl;
                killRobot();
            }
        }
        allRobotsAreDead();
        cout << "Après cette rencontre avec Herbert Moon, vous decidez de continuer votre chemin. \n Cependant, avant de partir, vous decidez de jeter un coup d'oeil sur votre equipe \n"
             << endl;
        showTeamstats();
        //*****************************************************************FIN DE LA PREMIERE RENCONTRE****************************************************************************
    }
}
