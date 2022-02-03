/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	//Mode d'emploi de TOUTES les méthodes:
    //  Toutes les méthodes de trajets ne font rien, elles servent seulement à faire le pivot entre TrajetSimple et TrajetComposé

    virtual void Afficher()const=0;
	virtual char*getDepart()const=0;
	virtual char*getArrivee()const=0;
	virtual std::string getType()const=0;
	virtual char* getTransport()const;
	

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    virtual ~Trajet ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    //Le constructeur est en protégé car Trajet est une classe abstraite
    Trajet ();

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H