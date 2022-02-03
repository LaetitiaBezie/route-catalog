/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const
{
	cout<<"\nTrajet Composé : ";
    etapes->Afficher();
    cout<<"Fin du trajet composé."<<endl;
}//----- Fin de Afficher

char* TrajetCompose::getDepart()const
{
	return etapes->getPremierElement()->getTrajet()->getDepart();
}//----- Fin de getDepart

char* TrajetCompose::getArrivee()const
{
	return etapes->getDernierElement()->getTrajet()->getArrivee();
}//----- Fin de getArrivee

string TrajetCompose::getType()const
{
	return "C";
}//----- Fin de getType

ListeTrajets* TrajetCompose::getListeEtapes()const
{
	return etapes;
}//----- Fin de getListeEtapes

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (ListeTrajets* et)
{
    //Le this permet de lever l'ambiguïté des noms
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    this->etapes=et;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées