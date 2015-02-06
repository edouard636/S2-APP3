/**
    \file  menu.cpp
    \author Equipe professorale S2
    \date 2012-01-12
    \version 01.00a

    Implementation de la classe Menu pour menufact01<br>
   
    Historique de revision   (menufact01)<br>
    V01.00a  12 janv 2012 Equipe professorale S2  Validation iteration No 1 <br>

  -----------------------------------------------------------------------------<br>
  Copyright 2012<br>
  Departement de genie electrique et de genie informatique Universite de Sherbrooke<br>
*/

#include "menu.h"

/**
   \brief Constructeur Menu
   \return void
*/
Menu::Menu ()
{
   int i;
   if (TRACE_Menu)
      cout << "Menu::Constructeur,  aucun parametre" << endl;
   description = "Menu MENUFACT01 - MENUFACT02";                  ///< Pour usage futur
   for ( i = 0; i < NBRE_PLATS_MAX; i++ )
      plat[i]  = NULL;
   courant = 0;
}

Menu::~Menu ()
{
   int i;
   if (TRACE_Menu)
   {
      cout << "Menu::Destructeur" << endl;
      cout << "courant : " << courant << endl;
   }
   for ( i = 0; i < NBRE_PLATS_MAX; i++ ) 
       if (plat[i] != NULL)
       {
          if (TRACE_Menu)
           cout  << "Menu::Destructeur Plat No " << i <<" sera efface " << endl;
          delete plat[i];
       }
       else
       {
          if (TRACE_Menu)
           cout  << "Menu::Destructeur Plat No " << i <<" non defini " << endl;
       }

}

/**
   \brief Afficher Menu
   \param  os Determine le flot de sortie de generation du graphique
   \return void
*/
void Menu::afficher (ostream & os) const               ///< Afficher
{
   int i;
   if (TRACE_Menu)
      os << "Menu::afficher" << endl;
   os << "\nMenu ----------------------------------------------\n";
   os << description << endl;
   for ( i = 0; i < NBRE_PLATS_MAX; i++ ) 
   {
       if (plat[i] != NULL)
       {
           if (i==courant) 
				os << "Plat No " << i <<" (*) : ";
           else
				os << "Plat No " << i <<"     : "; 
           plat[i]->afficher(os);
       }
       else
       {
          if (TRACE_Menu)
				os << "Plat No " << i <<" non defini " << endl;
       }
   }
   return;
}

void Menu::afficher_courant (ostream & os) const               ///< Afficher
{
   if (TRACE_Menu)
   {
      os << "Menu::afficher_courant" << ",  ";
      os << "Menu, courant: ";
   }
   if (plat[courant]!=NULL)
      plat[courant]->afficher(os);
    return;
}

/**
   \brief Ajoute Menu
   \param  le_plat 
   \return void
*/
void Menu::ajoute(int code, string desc, double prix)              ///< Ajoute un plat au Menu
{
    if (TRACE_Menu) cout << "Menu::ajoute, courant = " << courant << endl;

    int i = 0;
    bool place = false;
	
	while ((i < NBRE_PLATS_MAX) && (!place))
    {
        if (plat[i]== NULL)
        {
            plat[i] =  new PlatAuMenu(code, desc, prix);
            courant = i;
            place = true;
        }
        i++;
    }
    if (!place)
        cout << "Menu::ajoute - erreur debordement " << endl;
   return;
}

void Menu::efface_courant()
{
    if (TRACE_Menu)
   {
      cout << "Menu::efface_courant " << endl;
      cout << "courant : " << courant << endl;
   }

    if ((0 <= courant) && (courant < NBRE_PLATS_MAX))
    {
        if (plat[courant] !=  NULL )
        {
            delete plat[courant];
            plat[courant]= NULL;
        }
        else
        {
            //rien on laisse courant designer un espace vide
        }
    }
    else
    {
       //rien a faire, indice courant hors limite (ne devrait jamais arriver)
        if (TRACE_Menu)
         cout << "efface_courant indice courant hors limite " << courant << endl;
    }
   return;
}

bool Menu::positionne_code(int code_a_trouver)      ///< positionne le courant au code
{

   bool trouve = false;
   int i;
   if (TRACE_Menu)
      cout << "Menu::positionne_code" << endl;
   // positionne ‡ la premiere occurence du code
   i = 0;
   trouve = false;
   while ((!trouve) && (i < NBRE_PLATS_MAX))
   {
      if (plat[i] != NULL)
          trouve = (plat[i]->get_code()== code_a_trouver);
      if (trouve)
         courant = i;
      else i++;
    }
  if (!trouve) 
  {
     cout << "Menu::positionne_code  erreur code " << code_a_trouver <<" non existant dans le menu" << endl;
  }
  return trouve;
}

PlatAuMenu * Menu::get_courant ()              ///< Obtenir une rÈfÈrence au plat courant
{
   if (TRACE_Menu)
      cout << "Menu::get_courant " << endl;
   return plat[courant];
}

/**
   \fn string ladate()
   \brief Fonction utilitaire pour produire une chaine de caractere contenant la date systeme
*/
string ladate()
{
   char tmp[0x100];
   struct tm * timeinfo;

   string s;
   time_t t;                    // strutures requises a la lecture
                                 // de la date et de l'heure systeme
   time(&t);
   timeinfo = localtime ( &t );
   strftime (tmp,0x100,"%Y-%m-%d %H:%M:%S",timeinfo);
   s.assign(tmp);
   return s;
}


