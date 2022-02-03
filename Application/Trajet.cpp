/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Afficher()const
{
}//----- Fin de Afficher

char*Trajet::getDepart()const
{
	return nullptr;
}//----- Fin de getDepart

char*Trajet::getArrivee()const
{	
	return nullptr;
}//----- Fin de getArrivee

string Trajet::getType()const
{
	return "none";
}//----- Fin de getType

char*Trajet::getTransport()const
{
	return nullptr;
}//----- Fin de getTransport

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Trajet::~Trajet ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Trajet::Trajet ()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
} //----- Fin de Trajet