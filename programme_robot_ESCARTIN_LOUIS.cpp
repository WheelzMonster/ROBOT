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

void presenter(Robot &r) //presente les modeles de bases du marchand
{
    r.sePresenter();
}

void createTeam() // creer une equipe de robot en fonction des choix du user
{
    string nom;
    int nbUnites = 12;

    std::cout << "Combien voulez vous de robot classique dans votre equipe ?" << std::endl;
    int nbRobotClassique;
    std::cin >> nbRobotClassique;
    nbUnites -= nbRobotClassique;

    if (nbUnites >= 0)
    {
        for (int i = 1; i <= nbRobotClassique; i++)
        {
            cout << "Entrez le nom de votre robot classique numero " << i << " : ";
            std::cin >> nom;
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
    std::cin >> nbRobotMedecin;
    nbUnites -= (nbRobotMedecin * 4);

    if (nbUnites >= 0)
    {
        for (int i = 1; i <= nbRobotMedecin; i++)
        {
            cout << "Entrez le nom de votre robot medecin numero " << i << " : ";
            std::cin >> nom;
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
    std::cin >> nbRobotBerserker;
    nbUnites -= (nbRobotBerserker * 6);

    if (nbUnites >= 0)
    {

        for (int i = 1; i <= nbRobotBerserker; i++)
        {
            cout << "Entrez le nom de votre robot Berserker numero " << i << " : ";
            std::cin >> nom;
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
    std::cin >> nbRobotHandicape;
    nbUnites -= (nbRobotHandicape * 11);

    if (nbUnites >= 0)
    {
        for (int i = 1; i <= nbRobotHandicape; i++)
        {
            cout << "Entrez le nom de votre robot Handicape numero " << i << " : ";
            std::cin >> nom;
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

void showTeam() // j'ai creer ceci au cas ou je decide de presenter l'equipe du user
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

void showTeamstats() // montre les stats de l'equipe du joueur
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
    else if (!monEquipeBerserker.empty())
    {
        monEquipeBerserker.pop_back();
        cout << "Un de vos robots Berserker est mort :(" << endl;
    }
    else if (!monEquipeMedecin.empty())
    {
        monEquipeMedecin.pop_back();
        cout << "Un de vos robots medecin est mort :(" << endl;
    }
}

void allRobotsAreDead() // fonction appelée à la fin de chaque evenement pour verifier si l'utilisateur rassemble les conditions pour continuer à jouer
{
    if (monEquipeClassique.empty() && monEquipeBerserker.empty())
    {
        cout << "Vous n'avez plus, ou n'avez jamais eu de robot capable de se battre. \n s'il vous restait une equipe de medecin, ils se sont deja fait detruire par le monde cruel d'algorea. Votre aventure est finie." << endl;
        exit(0);
    }
}

void allMyteamattackk(Robot *autre) //tout les robots dispo qui peuvent se battre attaquent une cible
{
    int enemyHealth = 100;
    while (enemyHealth > 0)
    {
        if (!monEquipeClassique.empty())
        {
            for (unsigned int i = 0; i < monEquipeClassique.size(); i++)
            {
                if (enemyHealth <= 0)
                {
                    break;
                }

                monEquipeClassique[i]->attaquer(autre);
                enemyHealth -= 20;
                std::cout << "\n\n";
            }
        }

        if (!monEquipeBerserker.empty())
        {
            for (unsigned int i = 0; i < monEquipeBerserker.size(); i++)
            {
                if (enemyHealth <= 0)
                {
                    break;
                }

                monEquipeBerserker[i]->toutDefoncer(autre);
                enemyHealth -= 75;
                std::cout << "\n\n";
            }
        }
    }
    autre->showNom();
    std::cout << " est mort \n"
              << endl;
}

void healAllteam() // aidera un medecin a soigner toute mon equipe
{
    if (!monEquipeClassique.empty())
    {
        for (unsigned int i = 0; i < monEquipeClassique.size(); i++)
        {
            monEquipeMedecin[0]->soigner(monEquipeClassique[i]);
            std::cout << "\n\n";
        }
    }

    if (!monEquipeBerserker.empty())
    {
        for (unsigned int i = 0; i < monEquipeBerserker.size(); i++)
        {
            monEquipeMedecin[0]->soigner(monEquipeBerserker[i]);
            std::cout << "\n\n";
        }
    }
}

void enemyAttack() // fonction qui fera attaquer les enemies classique ou berserker sur les robots classiques ou berserker du joueur
{
    if (!equipeEnnemieClassique.empty() && !monEquipeClassique.empty())
    {
        equipeEnnemieClassique[0]->attaquer(monEquipeClassique[0]);
    }

    if (!equipeEnnemieClassique.empty() && !monEquipeBerserker.empty())
    {
        equipeEnnemieClassique[0]->attaquer(monEquipeBerserker[0]);
    }

    if (!equipeEnnemieBerserker.empty() && !monEquipeClassique.empty())
    {
        equipeEnnemieBerserker[0]->toutDefoncer(monEquipeClassique[0]);
    }

    if (!equipeEnnemieBerserker.empty() && !monEquipeBerserker.empty())
    {
        equipeEnnemieBerserker[0]->toutDefoncer(monEquipeBerserker[0]);
    }
}

int addition(int a, int b)
{
    int result = a + b;
    std::cout << result << std::endl;
    return result;
}

double addition(double a, double b)
{
    double result = a + b;
    std::cout << result << std::endl;
    return result;
}

void deleteAll()
{
    for (int i = 0; i < monEquipeClassique.size(); ++i)
    {
        delete monEquipeClassique[i]; //On libère la i-ème case mémoire allouée
        monEquipeClassique[i] = 0;    //On met le pointeur à 0 pour éviter les soucis
    }

    for (int i = 0; i < monEquipeMedecin.size(); ++i)
    {
        delete monEquipeMedecin[i]; //On libère la i-ème case mémoire allouée
        monEquipeMedecin[i] = 0;    //On met le pointeur à 0 pour éviter les soucis
    }

    for (int i = 0; i < monEquipeBerserker.size(); ++i)
    {
        delete monEquipeBerserker[i]; //On libère la i-ème case mémoire allouée
        monEquipeBerserker[i] = 0;    //On met le pointeur à 0 pour éviter les soucis
    }

    for (int i = 0; i < monEquipeHandicape.size(); ++i)
    {
        delete monEquipeHandicape[i]; //On libère la i-ème case mémoire allouée
        monEquipeHandicape[i] = 0;    //On met le pointeur à 0 pour éviter les soucis
    }

    for (int i = 0; i < equipeEnnemieClassique.size(); ++i)
    {
        delete equipeEnnemieClassique[i]; //On libère la i-ème case mémoire allouée
        equipeEnnemieClassique[i] = 0;    //On met le pointeur à 0 pour éviter les soucis
    }

    for (int i = 0; i < equipeEnnemieBerserker.size(); ++i)
    {
        delete equipeEnnemieBerserker[i]; //On libère la i-ème case mémoire allouée
        equipeEnnemieBerserker[i] = 0;    //On met le pointeur à 0 pour éviter les soucis
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

    cout << "Je ne prends pas les credits republicains ! Tu n'as que 12 unites alogeennes ? Choisis bien dans ce cas! \n Parce que je repete : les credits republicains NE FERONT PAS L'AFFAIRE! \n Tu te prends pour un jedi ou quoi ? A faire des passes avec les mains comme ca ? Choisis !\n\n"
         << endl;
    cout << " Voix off : Attention, ce marchand est tres capricieux! Si tu lui demande quelque chose et que tu ne peux pas payer, il s'enervera et ne te vendra rien. \n\n regardes bien le prix de chaque robot et ton nombre d'unite avant de faire une offre pour etre sur qu'elle soit valable, sinon tu pourrai te retrouver sans robot.\n\n Il est egalement conseiller de prendre au moins un robot classique ou un berserker car ils savent se battre. \n\n Si vous ne prenez que des robots medecin ou handicapes, vous serez incapable de vous defendre.\n\n"
         << endl;
    createTeam();
    // showTeam(); en cas ou je voudrai que les robots achetés se présentent, mais c'est répétitif
    showTeamstats();

    std::cout << "Voix off: Vous vous trouvez desormais a bord de l'endar spire, le vaisseau de transport qui vous enmenera sur Algorea, vous debordez d'impatience a l'approche de cette grande aventure!\n"
              << endl;
    std::cout << "Lorsque vous descendez du vaisseau, vous vous dirigez vers la capital de la planete." << endl;
    allRobotsAreDead();
    std::cout << "En arrivant, vous etes recu par l'officier de terrain : Herbert Moon. \n Il n'arrete pas d'hurler : 'vous ne pouvez pas me tuer! Je suis HERBERT MOOOOOOOOOOOOOOOOOOOOOOOOOON' Il a visiblement un serieux probleme... \n\n Son visage etait tout defonce, il a surement du se faire tabasser apres une partie de poker. Il s'approche de vous et dit: \n"
              << endl;

    if (!monEquipeHandicape.empty())
    {
        monEquipeHandicape[0]->utiliserRampeAcces();
        exit(0);
    }
    else
    {
        int herbertMoonEncounter;
        std::cout << "*avec un accent de plouc* qu'ez'fet la vous ? on aime pas ti les etrangers par ici! et pi c'est quoi ces robots la ? je les veux moi" << endl;
        std::cout << "3 choix s'offrent à vous: \n\n 1: faire une passe avec la main et dire 'ce ne sont pas ces robots que vous recherchez, nous pouvons circuler'\n\n 2: lui eclater la gueule \n\n 3: Baah.. Lui eclater la gueule ?\n\n"
                  << endl;
        std::cout << "choisissez votre choix en entrant le chiffre du choix: \n\n";

        cin >> herbertMoonEncounter;

        if (herbertMoonEncounter == 1)
        {
            std::cout << "Tout en faisant un geste avec la main, Herbert dit 'Ce ne sont pas les robots que je recherche. \n Circulez! allons, circulez! \n"
                      << endl;
        }
        else
        {
            std::cout << "En essayant de lui casser la gueule, il s'enerve et tue un de vos robots. Vous pensiez faire le poids ? vous n'etes pas M. Marston!" << endl;
            killRobot();
        }
    }
    allRobotsAreDead();
    std::cout << "Après cette rencontre avec Herbert Moon, vous decidez de continuer votre chemin. \n Cependant, avant de partir, vous decidez de jeter un coup d'oeil sur votre equipe \n"
              << endl;
    showTeamstats();
    //*****************************************************************FIN DE LA PREMIERE RENCONTRE****************************************************************************

    std::cout << "Toujours determine a trouver le fabuleux tresor, vous vous enfoncez de plus en plus profondement dans les montagnes exp(x) = e^x d'algorea." << endl;

    int doorEncounter;

    std::cout << "Vous finissez par arriver sur un chemin menant a 2 grandes portes. \n L'une est bleu et lumineuse, l'autre est rouge et sombre. Laquelle choisissez-vous? \n\n 1: La porte lumineuse \n\n 2: la porte sombre" << endl;
    std::cout << "choisissez votre choix en entrant le chiffre du choix: \n\n";

    cin >> doorEncounter;

    if (doorEncounter == 2)
    {
        std::cout << "Vous arrivez devant la porte. Il est ecrit 'Lorsque vous appuyerez sur cette pierre, le grand maitre citera les precepts ancestraux \n montrez-vous digne de son enseignement en completant ces precepts, et a la toute puissance vous accederez.' \n\n"
                  << endl;
        std::cout << "La Paix est un mensonge, il n'y a que la passion, \n Par la passion, j'ai la puissance, \n Par la puissance j'ai le pouvoir, \n Par le pouvoir j'ai la victoire, \n Par la victoire, je brise mes chaines. \n"
                  << endl;
        std::cout << "completez: \n\n 1: Et sans limite mon pouvoir deviendra  \n\n 2: Et pour toujours j'echapperai a l'au dela \n\n 3: Et la Force me liberera" << endl;
        std::cout << "choisissez votre choix en entrant le chiffre du choix: \n\n";
        int choiceRedDoor;
        cin >> choiceRedDoor;

        if (choiceRedDoor == 3)
        {
            cout << "\n\n Vous êtes digne, entrez donc... a vos risques et perils. " << endl;
        }

        else
        {
            std::cout << "Vous n'etes pas digne, partez ! *le plafond de la caverne s'ecroule mais vous parvenez a franchir la porte \n cependant vous perdez un de vos robots*. " << endl;
            killRobot();
        }
    }

    else if (doorEncounter == 1)
    {
        std::cout << "Vous arrivez devant la porte. Il est ecrit 'Lorsque vous appuyerez sur cette pierre, le grand maitre citera les precepts ancestraux \n montrez-vous digne de son enseignement en completant ces precepts, et a la toute sagesse vous accederez.' \n\n"
                  << endl;
        std::cout << "Il n'y a pas d'emotion, il n'y que la paix, \n Il n'y a pas d'ignorance, il n'y a que la conaissance \n Il n'y a pas de passion, il n'y a que la serenite, \n Il n'y a pas de chaos, il y a l'harmonie."
                  << endl;
        std::cout << "completez: \n\n 1: Il n'y a pas de colere, car au cote obscur elle te menera  \n\n 2: Il n'y a pas de mort, il n'y a que la Force \n\n 3: Il n'y a pas de rencoeur, il n'y a que le pardon" << endl;
        std::cout << "choisissez votre choix en entrant le chiffre du choix: \n\n";
        int choiceBlueDoor;
        cin >> choiceBlueDoor;

        if (choiceBlueDoor == 2)
        {
            cout << "\n\n Vous êtes pur, entrez donc... et que la Force soit avec vous. " << endl;
        }

        else
        {
            std::cout << "Vous etes impur, partez ! *le plafond de la caverne s'ecroule mais vous parvenez a franchir la porte \n cependant vous perdez un de vos robots*. " << endl;
            killRobot();
        }
    }

    allRobotsAreDead();

    std::cout << "Une fois a l'interieur, vous realisez que les deux portes menent au meme endroit \n deux entrees etaient utilisees a l'epoque ou les Sith'aari vivaient sur Algorea \n vous decidez donc de jeter un coup d'oeil sur votre equipe: \n"
              << endl;
    showTeamstats();

    //****************************************************************FIN DEUXIEME RENCONTRE*************************************************************

    std::cout << "Vous avancez dans des couloirs sombres, toujours plus proche du trésor, lorsque soudain, une silouhette malefique se profil a l'horizon...\n\n"
              << endl;

    equipeEnnemieClassique.push_back(new Robot("Kree'vus"));

    std::cout << "*Le docteur se presente* Bonjour voyageur *rires* Tu viens aussi pour le tresor ?\n\n tu pensais que ca serai facile ? C'etait sans compter sur le docteur Kree'vus! Tu vas mourir" << endl;
    equipeEnnemieClassique[0]->showStats();
    enemyAttack();
    showTeamstats();
    allMyteamattackk(equipeEnnemieClassique[0]);
    equipeEnnemieClassique.pop_back();

    std::cout << "Vous m'avez peut etre eu moi, mais vous ne l'aurez pas lui... \n\n Tremblez devant MON POTE CHARNAGUS!!" << endl;
    std::cout << "*Le docteur Charnagus sort de l'ombre et s'avance.....*\n\n"
              << endl;
    equipeEnnemieBerserker.push_back(new RobotBerserker("Charnagus"));
    equipeEnnemieBerserker[0]->showStats();
    enemyAttack();
    showTeamstats();
    allMyteamattackk(equipeEnnemieBerserker[0]);
    equipeEnnemieBerserker.pop_back();

    std::cout << "Apres ce combat quasi fatal, votre equipe est mal en point. Il faudrait qu'ils puissent se soigner\n\n"
              << endl;

    if (!monEquipeMedecin.empty())
    {
        std::cout << "Heureusement, vous avez achete un robot medecin au marchand, il peut soigner toute votre equipe !" << endl;
        healAllteam();
        showTeamstats();
        std::cout << "Ah! Voila qui est mieux!" << endl;
    }
    else
    {
        std::cout << "Dommage! Vous n'avez pas achete de robot medecin chez le marchand...\n Vous commencez a perdre espoir quand soudain, un robot a l'allure etrange et l'accent bizarre apparait ...\n"
                  << endl;
        std::cout << "'Hey Salut Chef ! ils ont l'air mal en point tes robots ! T'inquiete ! Je suis michmich Escart !\n I am zi best doctor in ze world ! Je vais joindre ton equipe pour la suite!'" << endl;
        monEquipeMedecin.push_back(new RobotMedecin("michmich"));
        healAllteam();
        showTeamstats();
        std::cout << "Ah! Voila qui est mieux!" << endl;
    }
    //*****************************************************************FIN TROISIEME RNCONTRE*******************************************************************************************************

    std::cout << "Maintenant qu'ils sont en bien meilleur sante, vos robots et vous vous dirigez vers la grande porte final qui abrite le tresor et le dragon ancestral.\n\n"
              << endl;
    std::cout << "Il est ecrit 'pour ouvrir cette porte tapez le code suivant 11 21 1211 111221 .... mais les 6 derniers chiffre manquent. \n\n Trouvez les, vous n'avez qu'un seul essai." << endl;
    int guesscode;
    cin >> guesscode;

    if (guesscode == 312211)
    {
        std::cout << "Vous etes fort... vous entrez sans probleme." << endl;
    }
    else
    {
        std::cout << "M. Rouxel, heuu.. Voyageur, vous etes mauvais. Vous etes oblige d'utiliser l'autodestruction de l'un de vos robot pour entrer" << endl;
        killRobot();
    }
    allRobotsAreDead();

    std::cout << "Une fois a l'interieur, vous apercevez le tresor garde par le grand dragon Clairus Perrotos!\n\n 2 choix s'offre à vous : \n\n 1: La tuer et recuperer le tresor \n\n 2: La distraire et recuperer le tresor" << endl;
    std::cout << "choisissez votre choix en entrant le chiffre du choix: \n\n";
    int choiceDragon;
    cin >> choiceDragon;

    if (choiceDragon == 1)
    {
        std::cout << "Tout au fond de vous, vous connaissez cette technique ancestral...\n Qu'est-ce qui peut un dragon fan de Math ? Mais oui bien sûr!\n\n Vous et votre equipe courrez vers le dragon en criant 'J'INVOQUE LA DIVISION PAR 0!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n Le dragon etant prit au depourvu par cette aberation mathematique, vous avez le temps de lui infliger un coup fatal derriere l'oreil droite!\n\n' Felicitation, le tresor est a vous. Votre aventure est terminee " << endl;
    }
    else if (choiceDragon == 2)
    {
        std::cout << "Vous voyez une bibliotheque avec plein de livre! Voila la cle de votre distraction!\n\n Mais que choisir ? \n\n 1: Un bouquin sur le dessin \n\n 2: Un bouquin sur HTML/CSS \n\n 3: Un bouquin qui s'intitule 'Graphes planaires : dessins non-alignés, domination de puissance et énumération d'orientations Eulériennes'" << endl;
        std::cout << "choisissez votre choix en entrant le chiffre du choix: \n\n";
        int choiceDistraction;
        cin >> choiceDistraction;

        if (choiceDistraction == 3)
        {
            cout << "Bien vu! Elle parait completement fascine par se livre, au point qu'elle ne vous a pas vu prendre le tresor! \n Vous etes riche et votre aventure est terminee\n\n"
                 << endl;
        }
        else
        {
            cout << "Malheureux ! il etait evident que ce bouquin n'allait pas l'interesser !\n elle vous a vu et elle a aneantie toute votre equipe! vous lui servez de repas." << endl;
            allRobotsAreDead();
        }
    }

    std::cout << "***********************BONUS****************************************" << endl;
    std::cout << "choisissez deux nombre entier a additionner" << std::endl;
    int nbrEntier1;
    int nbrEntier2;
    cin >> nbrEntier1;
    cin >> nbrEntier2;

    addition(nbrEntier1, nbrEntier2);

    std::cout << "choisissez deux nombre a virgule a additionner (utiliser le . pour la virgule)" << std::endl;
    int nbrDecimal1;
    int nbrDecimal2;
    cin >> nbrDecimal1;
    cin >> nbrDecimal2;

    addition(nbrDecimal1, nbrDecimal2);

    cout << "voila! Vous venez d'utiliser une surcharge de fonction, je ne savais pas ou l'utiliser, donc je le fait ici.\n C'est pour avoir des points.\n Excelsior!" << endl;
    deleteAll(); // J'ai lu que c'est une bonne pratique de liberer l'espace memoire alors je le fais
}
