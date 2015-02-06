 /**
    \file menufact01.cpp
    \author Equipe professorale S2
    \date 2012-01-10
    \version 01.00a

    Ce code est a developper (en menufact02.cpp)<br>
      pour la realisation de l'iteration menufact02.<br>

    Programme menufact01<br>
    Fonctionnalite:<br>
      Interprete des commandes pour ........<br>
    Precondition:<br>
      Invocation sur ligne de commande<br>
      argv[1] (optionnel) nom du fichier de sortie (texte)<br>
      voir le document Specmenufact02.doc<br>
    Postcondition<br>
      creation du fichier texte<br>
  
    Note:<br>
      Ce programme fonctionne avec un mode "trace", c'est a dire que de <br>
      nombreux messages peuvent Ítre affiches sur la console pour rapporter<br>
      le deroulement des operation internes.<br>
    References:<br>
      Documents  APP #3 S2<br>
      Document   ......<br>
  
    Historique de revision   (menufact01)<br>
    V01.00a  12 janv 2012 D. Dalle  Validation hiver 2012 et modification pour package liste_s.h, .cpp <br>
                                    modification de nom pour menufact01<br>

  -----------------------------------------------------------------------------<br>
    Copyright 2006-2012<br>
    Departement de genie electrique et de genie informatique Universite de Sherbrooke  <br>
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const string menufact_VERSION = "V01.00a";
const bool TRACE_M = false;

#include "facture.h"
#include "menu.h"
#include "test_menu_fact.h"

enum mode {console, fichier} le_mode = console;

/** \fn int affiche_commandes ()
    \brief Afficher les commandes possibles a la console
           Cette fonction affiche le format des commandes comme aide 
           memoire a l'utilisateur
*/
void affiche_commandes() 
{                 ///< Information de type "Aide"
    cout << "Commandes du programme menufact01, version \n" << menufact_VERSION << endl;
    cout << " format general d'une commande\n";
    cout << " menufact01 [nom_de_fichier_de_sortie]\n";
    cout << " menufact01 ?\n";
    cout << "           affichage d'informations sur le programme\n";
    cout << " menufact01\n";
    cout << "           execution et toutes les sorties sur la console\n";
    cout << " menufact01  [nom_de_fichier_de_sortie]\n";
    cout << "           execution et sortie dans un fichier, messages sur la console\n";
    return;
}


int main( int argc, char **argv, char **envp )
{
   ofstream  fichier_sortie;             // fichier de sortie 
   Facture  la_facture;                  // Facture
   Menu le_menu;                         // Menu (unique)

   //========================================================================
   // interpretation de la ligne de commande
   // Affichage d'informations diverses
   // et initialisation du fichier de sortie

   string sladate = ladate();

   cout << "menufact01, version " << menufact_VERSION << endl;
   cout << "Date et heure: " << sladate << endl; 
   if (TRACE_M)
   {
      cout << "TRACE_M: environnement   = " << *envp << endl;
      cout << "TRACE_M: argc   = " << argc << endl;
      if (argc >= 2)
        cout << "TRACE_M: argv[1]  =  " << argv[1] << endl;
   }

   if (argc > 2)	// Analyse et validation de la ligne de commande
   {
      cout << "Ligne de commande comprenant trop de parametres \n";
      affiche_commandes();   // Affiche la liste des commandes
      return 1;
   }
   else if (argc == 1)	// Analyse et validation de la ligne de commande
   {
      cout << "Mode de sorties sur la console \n";
      le_mode = console;
   }
   else
   {
      string argv1 = argv[1];
      if ((argv1.compare(0,2,"-h") == 0) |
         (argv1.compare("?") == 0))
      {
         affiche_commandes();	// Affiche la liste des commandes
         return 0;
      }
      else
      {
          cout << "fichier_sortie  =  " << argv[1] << endl;
          le_mode = fichier;
          fichier_sortie.open(argv[1]);
          if(fichier_sortie.fail() || fichier_sortie.eof()!=0)
          {
              cout << "Le fichier de sortie ne peut etre cree" << endl;
              return 1;
          }
          cout   << "Fichier de sortie ouvert !" << endl;
          fichier_sortie << "Fichier  " << argv[1] << endl;
          fichier_sortie << "menufact01, version " << menufact_VERSION << endl;
          fichier_sortie << "Date et heure: " << sladate << endl; 
      }
   }
 

   //========================================================================
   // initialisation des donnees

   Test_menu_fact le_test (&le_menu, &la_facture);    // un objet statique Test_menu_fact,

   if (le_mode == fichier)
      le_test.executer_test_1 (fichier_sortie);
   else
      le_test.executer_test_1 (cout);
   
   //========================================================================
   // fin des operations et sortie 

   if (le_mode == fichier)
      fichier_sortie.close();    
   
   cout << "Fin ... " << endl;
   
   return 0;
}


