/**
    \file test_menu_fact.cpp
    \author Equipe professorale S2
    \date 2012-01-12
    \version 1.00a 
  
    Classe Test_menu_fact <br>
 
    Ce code est a completer pour la realisation de l'iteration menufact01.<br>

    Historique de revision   (menufact01)<br>
    V01.00   12 janv 2012  D. Dalle  Creation<br>

  -----------------------------------------------------------------------------<br>
  Copyright 2012<br>
  Departement de genie electrique et de genie informatique Universite de Sherbrooke<br>
*/

#include "test_menu_fact.h"
#include "menu.h"
#include "facture.h"

Test_menu_fact::Test_menu_fact (Menu *le_m, Facture *la_f)
                        ///< Definir et initialiser un Test_menu_fact
{
    le_menu = le_m;
    la_facture = la_f;
}

Test_menu_fact::~Test_menu_fact ()
{
};

void Test_menu_fact::executer_test_1 (ostream& fichier_sortie)           ///< Executer un test 
{      
    fichier_sortie << "\n==========================================================";
    fichier_sortie << "\nExecuter_test_1 Constitution initiale du menu..." << endl;
    //
    //  Tests des fonctions d'initialisations des attributs (un a la fois)
    le_menu->ajoute(10, "Soupe du jour", 2.99); 

    // La methode suivante serait plus concise avec le constructeur approprie
    le_menu->ajoute(20, "Salade du jardin", 4.95 );
    
    // La methode suivante est encore plus concise avec le constructeur approprie
    le_menu->ajoute(30, "Canard sauvage au poivre vert", 3.99);
    le_menu->ajoute(39, "Soupe repas aux fruits de mer", 10.99);
    le_menu->afficher(fichier_sortie);

    fichier_sortie << "\n==========================================================";
    fichier_sortie << "\nOn tente de positionner a un code inexistant" << endl;

    int un_code = 999;
    
	if (le_menu->positionne_code(un_code))
        fichier_sortie << "Code "<< un_code << " localise" << endl;
    else
        fichier_sortie << "Code "<< un_code << " non existant" << endl;
    
	le_menu->afficher(fichier_sortie);

    fichier_sortie << "\n==========================================================";
    fichier_sortie << "\nOn change le prix du plat de code 20 (sera le plat courant)";
    
	if (le_menu->positionne_code(20))
    {
        PlatAuMenu * un_plat = le_menu->get_courant();
        un_plat->set_prix (6.50); 
        le_menu->afficher(fichier_sortie);
    }
    else
        fichier_sortie << "Plat non existant" << endl;

    fichier_sortie << "\n==========================================================";
    fichier_sortie << "\nOn elimine le plat de code 30 (plat courant sera non defini)";
 
    // on supprime un plat du menu
	le_menu->positionne_code(30);
    le_menu->efface_courant();
    le_menu->afficher(fichier_sortie);

    fichier_sortie << "\n==========================================================";
    fichier_sortie << "\nOn ajoute un nouveau plat (sera le plat courant)" << endl;

    // on ajoute un nouveau plat
    le_menu->ajoute(33, "Truite aux amandes", 13.99);
    le_menu->afficher(fichier_sortie);

    fichier_sortie << "\n==========================================================";
    fichier_sortie << "\nFin du test..." << endl;
}
