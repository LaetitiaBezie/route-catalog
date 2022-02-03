/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTETRAJETS_H )
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Element.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class ListeTrajets 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual void Afficher() const;
    //Mode d'emploi:
    //  Cette méthode permet de parcourir tous les trajets de la ListeTrajets pour les afficher

	int getNbTrajets() const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le nombre de trajet(s) contenu dans la ListeTrajets

	void AjouterTrajetFin(Trajet* aAjouter, bool inCatalogue);
    //Mode d'emploi:
    //  aAjouter est le trajet qu'il faut ajouter dans la ListeTrajets
    //  inCatalogue permet tenir le bon compte de nombreTrajet. Si false, on appelle cette méthode pour la création des étapes d'un trajet composé (donc on n'augmente pas le nombreTrajet)
    //  Si true, on appelle cette méthode pour lors du chargement d'un fichier texte (pour garder les trajets dans le bon ordre), donc on incrémente nombreTrajet
    //  Cette méthode permet d'ajouter un trajet en dernière position dans la ListeTrajets

    void AjouterTrajetDebut(Trajet* aAjouter);
    //Mode d'emploi:
    //  aAjouter est le trajet qu'il faut ajouter dans la ListeTrajets
    //  Cette méthode permet d'ajouter un trajet en première position dans la ListeTrajets

    Element* getPremierElement() const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le premier Element contenu dans la ListeTrajets

    Element* getDernierElement() const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le dernier Element contenu dans la ListeTrajets


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    ListeTrajets ();
    //Mode d'emploi:
    //  Le constructeur initialise les attributs à un pointeur null pour les pointeurs et à zéro pour le nombre de trajet

    virtual ~ListeTrajets ( );
    //Mode d'emploi:
    //  Le destructeur détruit le premierElement

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs privés
    Element* premierElement;
    Element* dernierElement;
    int nombreTrajet;
};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // ListeTrajets_H