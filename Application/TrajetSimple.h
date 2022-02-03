/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined (TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual void Afficher() const;
    //Mode d'emploi:
    //  Cette méthode permet d'afficher ce qu'est un TrajetSimple

	virtual char* getDepart()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le départ d'un TrajetSimple

	virtual char* getArrivee()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir l'arrivée d'un TrajetSimple

	virtual std::string getType()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le typr de trajet ; donc retourne 'S' lorsqu'elle est appelée car c'est un trajet simple

    virtual char* getTransport()const;
    //Mode d'emploi:
    //  Cette méthode est un getter, elle permet d'obtenir le moyen de transport utilisé pendant le trajet simple

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const char* villeD, const char* villeA, const char* transport);
    //Mode d'emploi:
    //  villeD correspond à la ville de départ du TrajetSimple
    //  villeA correspond à la ville d'arrivée du TrajetSimple
    //  transport correspond au moyen de locomotion lors TrajetSimple
    //  Le constructeur fait initialise chaque attribut au paramètre qui lui correspond

    virtual ~TrajetSimple ( );
    //Mode d'emploi:
    //  Le destructeur supprime tous les attributs de TrajetSimple

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char* villeDepart;
char* villeArrivee;
char* transport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H