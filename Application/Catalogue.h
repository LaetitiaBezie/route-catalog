/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "ListeTrajets.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <typeinfo>
#include <istream>
#include <ostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	virtual void Afficher() const;
    //Mode d'emploi:
    //  Cette méthode montre à l'utilisateur tous les trajets qu'il a ajoutés

	void Rechercher(const char* villeD, const char* villeA) const;
    //Mode d'emploi:
    //  villeD est la ville à partir de laquelle on souhaite partir
    //  villeA est la ville où on souhaite arriver
    //  Cette méthode permet de trouver le ou les trajets correspondants aux points de départ et d'arrrivée spécifiés
    
	void AjouterTrajetSimple(const char* villeD, const char* villeA, const char* transport);
    //Mode d'emploi:
    //  villeD est la ville à partir de laquelle on souhaite partir
    //  villeA est la ville où on souhaite arriver
    //  Cette méthode permet d'ajouter un trajet simple au début de notre catalogue de trajets

	void AjouterTrajetCompose(ListeTrajets* etapes);
    //Mode d'emploi:
    //  villeD est la ville à partir de laquelle on souhaite partir
    //  villeA est la ville où on souhaite arriver
    //  Cette méthode permet d'ajouter un trajet composé au début de notre catalogue de trajets

    void AjouterTrajetSimpleFin(const char* villeD, const char* villeA, const char* transport);
    //Mode d'emploi:
    //  villeD est la ville à partir de laquelle on souhaite partir
    //  villeA est la ville où on souhaite arriver
    //  Cette méthode permet d'ajouter un trajet simple à la fin de notre catalogue de trajets

    void AjouterTrajetComposeFin(ListeTrajets* etapes);
    //Mode d'emploi:
    //  villeD est la ville à partir de laquelle on souhaite partir
    //  villeA est la ville où on souhaite arriver
    //  Cette méthode permet d'ajouter un trajet composé à la fin de notre catalogue de trajets
    
    ListeTrajets* getListeTrajets()const;
    //Mode d'emploi:
    //  Getter qui retourne l'attribut liste de la classe
    
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    Catalogue ();
    //Mode d'emploi:
    //  Le constructeur crée une ListeTrajets, liste chaînée où tous les trajets seront stockés

    virtual ~Catalogue ( );
    //Mode d'emploi:
    //  Le destructeur détruit la ListreTrajets contenant tous les trajets ajoutés lors de l'exécution du programme

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attribut privé
    ListeTrajets* liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
