/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ListeTrajets::Afficher()const
{
	Element * aAfficher = premierElement;

	while(aAfficher!=nullptr){
		aAfficher->getTrajet()->Afficher();
		aAfficher=aAfficher->getNext();	
	}
}//----- Fin de Afficher


int ListeTrajets::getNbTrajets() const
{
	
	return nombreTrajet;
}//----- Fin de getNbTrajets

void ListeTrajets::AjouterTrajetDebut(Trajet* aAjouter)
{
	if (premierElement==nullptr){
		premierElement = new Element(aAjouter);
		dernierElement=premierElement;
	}
	else{
		Element* e=premierElement;
		Element* suivant=new Element(aAjouter);
		suivant->setNext(e);
		premierElement=suivant;
		//delete suivant;
	}
	++nombreTrajet;
}//----- Fin de AjouterTrajetDebut


void ListeTrajets::AjouterTrajetFin(Trajet* aAjouter, bool inCatalogue)
{
	if (premierElement==nullptr){
		premierElement = new Element(aAjouter);
		dernierElement=premierElement;
	}
	else{
		Element* suivant=new Element(aAjouter);
		dernierElement->setNext(suivant);
		dernierElement=suivant;
		//delete suivant;
	}

	if(inCatalogue)
	{
		++nombreTrajet;
	}
}//----- Fin de AjouterTrajetFin


Element* ListeTrajets::getPremierElement() const
{
	return premierElement;
}//----- Fin de getPremierElement

Element* ListeTrajets::getDernierElement() const
{
	return dernierElement;
}//----- Fin de getDernierElement

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
ListeTrajets::ListeTrajets ()
{	
	#ifdef MAP
    	cout << "Appel au constructeur de <ListeTrajets>" << endl;
	#endif
	premierElement=nullptr;
	dernierElement=nullptr;
	nombreTrajet=0;
}//----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ( )
{
	#ifdef MAP
    	cout << "Appel au destructeur de <ListeTrajets>" << endl;
	#endif
	
	Element* temp1 = premierElement;
	Element* temp2=nullptr;

	while(temp1!=nullptr){
		temp2 = temp1->getNext();
		delete temp1;
		temp1=temp2;
	}	
} //----- Fin de ~ListeTrajets

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées