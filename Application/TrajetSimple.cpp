/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher()const
{
    cout <<"\r\nTrajet simple de " << villeDepart << " à " << villeArrivee;
	cout << " : " << transport << endl;
}//----- Fin de Afficher

char* TrajetSimple::getDepart()const
{
	return villeDepart;
}//----- Fin de getDepart

char* TrajetSimple::getArrivee()const
{
	return villeArrivee;
}//----- Fin de getArrivee

string TrajetSimple::getType()const
{
	return "S";
}//----- Fin de getType

char* TrajetSimple::getTransport()const
{
	return transport;
}//----- Fin de getTransport

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple :: TrajetSimple (const char* villeD, const char* villeA, const char* moyenTransport )
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    villeDepart=new char [strlen(villeD)+1];
    villeArrivee=new char [strlen(villeA)+1];
    strcpy(villeDepart,villeD);
    strcpy(villeArrivee,villeA);
    transport=new char[(strlen(moyenTransport)+1)];
    strcpy(transport, moyenTransport);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    delete [] villeDepart;
    delete [] villeArrivee;
    delete [] transport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées