/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h"
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual void Afficher() const;
    //Mode d'emploi:
    //  Cette méthode permet d'afficher ce qu'est un TrajetComposé

	virtual char* getDepart()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le départ d'un TrajetComposé

	virtual char* getArrivee()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir l'arrivée d'un TrajetComposé
    
	virtual std::string getType()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le typr de trajet ; donc retourne 'C' lorsqu'elle est appelée car c'est un trajet composé
	
	ListeTrajets* getListeEtapes()const;
     //Mode d'emploi:
    //  Cette méthode est un getter, elle retourne les étapes que composent un trajet composé

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose (ListeTrajets* et);
    //Mode d'emploi:
    //  et est une ListeTrajets qui contient toutes les étapes composant le TrajetCompose
    //  Le constructeur permet d'associer toutes les étapes du TrajetCompose, et, à l'attribut etapes.

    virtual ~TrajetCompose ( );
    //Mode d'emploi:
    //  Le destrcucteur ne supprime rien
 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ListeTrajets* etapes;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H