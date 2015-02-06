//!  Definition de classes
/**
    \file  plats.h
    \author Equipe professorale S2
    \date 2012-01-20
    \version 1.00a 
  
    Classe PlatAuMenu et associees<br>

    Ce code est a completer pour la realisation de l'iteration menufact02.<br>

    Historique de revision   (menufact01)<br>
    V01.00a  14 janv 2012  Equipe professorale S2  Creation version 2011<br>
  -----------------------------------------------------------------------------<br>
  Copyright 2012<br>
  Departement de genie electrique et de genie informatique Universite de Sherbrooke<br>
*/

#ifndef PLATS_H
#define PLATS_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const bool TRACE_Plats = false;          ///< Activer une trace sur cout (deboguage systematique)

/// Determine un  plats pour le menu
/** \class PlatAuMenu
  Determine un plat...
  Permet d'initialiser les plats et de les initialiser
*/

class PlatAuMenu { 
public:
/** Methodes et attributs publiques
  Determine un plat au menu (general)
  Permet d'initialiser les attributs et de les exploiter
*/
   PlatAuMenu ();                         ///< Constructeur de base
   PlatAuMenu  (int code,
                string desc, double prix);         ///< Constructeur avec code, description et prix 
   virtual ~PlatAuMenu();                          ///< Destructeur
   virtual void afficher (ostream & sortie) const; ///< Afficher le plat
   virtual void afficher_sommaire (ostream & sortie) const;  ///< afficher quantite code prix
   void set_prix (double prix);                 ///< Fixer le prix
   void set_code (int code);                 ///< Fixer le code
   void set_desc (string desc);                     ///< Fixer la description
   double get_prix () const;                        ///< Obtenir le prix
   int get_code () const ;                   ///< Obtenir le code
   string get_desc () const;                        ///< Obtenir la description

private:
   int code; 
   string desc; 
   double prix;
};

/// Determine un  plat sante 
/** \class PlatSante
  Determine un plat...
  Permet d'initialiser les plats et de les initialiser
*/

#endif //PLATS_H

