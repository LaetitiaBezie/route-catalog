/*************************************************************************
                           Element  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Element> (fichier Element.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Element.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Trajet* Element::getTrajet()const
{
    return trajet;
}//----- Fin de getTrajet

Element* Element::getNext()const
{
    return next;
}//----- Fin de getNext

void Element::setTrajet(Trajet* aAjouter)
{
    trajet=aAjouter;
}//----- Fin de setTrajet

void Element::setNext(Element* suivant)
{
    next=suivant;
}//----- Fin de setNext

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Element :: Element (Trajet* t)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Element>" << endl;
    #endif
    trajet=t;
    next=nullptr;
}//----- Fin de Element


Element :: ~Element ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Element>" << endl;
    #endif
    delete trajet;
}//----- Fin de ~Element

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées