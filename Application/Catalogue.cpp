/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajetSimple(const char* villeD, const char* villeA, const char* transport)
{
    TrajetSimple* aAjouter = new TrajetSimple(villeD,villeA,transport);
    liste->AjouterTrajetDebut(aAjouter);
    //delete aAjouter;
}//----- Fin de AjouterTrajetSimple

void Catalogue::AjouterTrajetCompose(ListeTrajets* etapes)
{
    TrajetCompose* aAjouter = new TrajetCompose(etapes);
    liste->AjouterTrajetDebut(aAjouter);
    //delete aAjouter;
}//----- Fin de AjouterTrajetCompose

void Catalogue::AjouterTrajetSimpleFin(const char* villeD, const char* villeA, const char* transport)
{
    TrajetSimple* aAjouter = new TrajetSimple(villeD,villeA,transport);
    liste->AjouterTrajetFin(aAjouter,true);
    //delete aAjouter;
}//----- Fin de AjouterTrajetSimpleFin

void Catalogue::AjouterTrajetComposeFin(ListeTrajets* etapes)
{
    TrajetCompose* aAjouter = new TrajetCompose(etapes);
    liste->AjouterTrajetFin(aAjouter,true);
    //delete aAjouter;
}//----- Fin de AjouterTrajetComposeFin

void Catalogue::Afficher() const
{
    cout<<"*********************************************************************"<<endl;
    string pluriel;
    int nbTrajets=liste->getNbTrajets();
    (nbTrajets>1) ? (pluriel="s ") : (pluriel=" ");
    
    cout<<"Il y a "<<nbTrajets<<" trajet"<<pluriel<<"stocké"<<pluriel<<"dans le catalogue : "<<endl;
    liste->Afficher();
    cout<<"*********************************************************************"<<endl<<endl;
}//----- Fin de Afficher

void Catalogue::Rechercher(const char* villeD, const char* villeA) const
{
    cout<<"*********************************************************************"<<endl;
    int nbOccurrence=0;
    string pluriel=" ";
    if(liste->getNbTrajets()!=0){
        Trajet* courant=liste->getPremierElement()->getTrajet();
        Element* curseur=liste->getPremierElement();
        while(curseur!=nullptr){
            if(strcmp(villeD,courant->getDepart())==0 && strcmp(villeA,courant->getArrivee())==0){
                courant->Afficher();
                nbOccurrence++;
            }
            curseur=curseur->getNext();
            if(curseur!=nullptr){
            courant=curseur->getTrajet();
            }
        }
        if(nbOccurrence>1){
            pluriel="s ";
        }
    }
    cout<<endl<<"Il y a "<<nbOccurrence<<" trajet"<<pluriel<<"possible"<<pluriel<<endl;
    cout<<"*********************************************************************"<<endl<<endl;
}//----- Fin de Rechercher

ListeTrajets* Catalogue::getListeTrajets()const
{
	return liste;
}//----- Fin de getListeTrajets

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif
    liste = new ListeTrajets();
}//----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    #endif
    delete liste;
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
