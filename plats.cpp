/**
    \file  plats.cpp
    \author Equipe professorale S2
    \date 2012-01-12
    \version 01.00a 

    Classe PlatAuMenu et associees<br>

    Ce code est a completer pour la realisation de l'iteration menufact02.<br>

    Historique de revision   (menufact01)<br>
    V01.00a  14 janv 2012  Equipe professorale S2  Creation version 2011<br>

    Copyright 2012<br>
    Departement de genie electrique et de genie informatique Universite de Sherbrooke  */

#include "plats.h"

void PlatAuMenu::afficher (ostream & sortie) const        ///< fichier sortie
{
   if (TRACE_Plats)
      sortie << "Liste_plat::afficher" <<  ", ";
   sortie << "code = " << code << ", ";
   sortie << "prix = " << prix << ", ";
   sortie << " (" << desc << " )" << endl;
   return;
}

void PlatAuMenu::afficher_sommaire (ostream & os) const        ///< fichier sortie
{
   if (TRACE_Plats)
      os << "Liste_plat::afficher" <<  ", ";
   os << setiosflags( ios::fixed);
   os << setiosflags( ios::right);
   os << setprecision(2);
   os << " code  = " << code << ", ";
   os << " prix  = " << prix << ", "<< endl;
   return;
}

PlatAuMenu::PlatAuMenu ()
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::Constructeur,  aucun parametre" << endl;
   code = 0;
   desc = "";
   prix = 0.0;
}

PlatAuMenu::PlatAuMenu  (int c, string s, double p)
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::Constructeur,  avec parametre" << endl;
   code = c;
   desc = s;
   prix = p;
}

PlatAuMenu::~PlatAuMenu ()
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::Destructeur " << endl;
}

void PlatAuMenu::set_prix (double p)              ///< prix d un PlatAuMenu
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::set_prix " << endl;
   prix = p;
   return;
}

void PlatAuMenu::set_code (int  c)      ///< Code d un PlatAuMenu
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::set_code " << endl;
   code = c;
   return;
}

void PlatAuMenu::set_desc (string s)              ///< Description d un PlatAuMenu
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::set_desc " << endl;
   desc = s;
   return;
}

double PlatAuMenu::get_prix () const              ///< Obtenir le prix d un PlatAuMenu
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::get_prix " << endl;
   return prix;
}

int PlatAuMenu::get_code ()  const    ///< Obtenir le code d un PlatAuMenu
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::set_code " << endl;
   return code;
}

string PlatAuMenu::get_desc () const             ///< Obtenir la description d un PlatAuMenu
{
   if (TRACE_Plats)
      cout << "PlatAuMenu::set_desc " << endl;
   return desc;
}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
