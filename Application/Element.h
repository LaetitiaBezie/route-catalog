/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) ----------------
#if ! defined ( ELEMENT_H )
#define ELEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Element 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet* getTrajet()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le trajet que contient l'Element

    Element* getNext()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le pointeur d'Element qui pointe vers l'Element suivant

    void setTrajet(Trajet* aAjouter);
    //Mode d'emploi:
    //  aAjouter est le trajet que Element doit maintenant contenir
    //  Cette méthode est un setter, elle permet de modifier le trajet que contient l'Element

    void setNext(Element* suivant);
    //Mode d'emploi:
    //  suivant est l'Element que notre Element doit maintenant pointer
    //  Cette méthode est un setter, elle permet de modifier l'Element suivant pointé par l'Element

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Element (Trajet* t);
    //Mode d'emploi:
    //  t est le trajet que doit contenir Element
    //  Le constructeur permet d'associer t à l'attribut trajet et d'initialiser next à un pointeur null

    virtual ~Element ( );
    //Mode d'emploi:
    //  Le destructeur ne supprime rien (aucune allocation de mémoire)

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs privés
    Trajet *trajet;
    Element *next;
};

//-------------------------------- Autres définitions dépendantes de <Element>

#endif // ELEMENT_H