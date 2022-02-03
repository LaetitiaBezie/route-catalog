/*************************************************************************
                           sejours  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Laetitia Bézie et Nathan Nowakowski
    e-mail               : laetitia.bezie@insa-lyon.fr nathan.nowakowski@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <sejours> (fichier sejours.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <typeinfo>
#include <istream>
#include <ostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------- Méthodes
void SauvegardeTrajetS(ofstream &, Element*); //Sauvegarde les trajets simples du catalogue dans un fichier texte
void SauvegardeTrajetC(ofstream &, Element*); //Sauvegarde les trajets composés du catalogue dans un fichier texte
void ChargementTrajetS(ifstream &, Catalogue*); //Charge les trajets simples d'un fichier texte dans le catalogue
void ChargementTrajetC(ifstream &, Catalogue*); //Charge les trajets composés d'un fichier texte dans le catalogue
void RembobinerFlux(ifstream &); //Permet de replacer le curseur du stream au début de la ligne

//------------------------------------------------------------- Variable globale
ListeTrajets* etapes; //Car utilisée dans différentes méthodes

///////////////////////////////////////////////////////////////////main
int main()
{
    Catalogue* c = new Catalogue();
    TrajetSimple* trajetS;
    int lecture;
    int n,m; //bornes de l'intervalle de recherche/sauvegarde
    char villeD[200];
    char villeA[200];
    char transport[200];
    int index=0;
    string nomFichier;
    ofstream fSauvegarde;
    ifstream fChargement;
    Element* aSauvegarde;
	char lettre;
	char ligne[610];
    char id[2]; //Si c'est un trajet S ou trajet C dans le fichier
	char findVille[200];
	bool deleteE=false;
	bool case6=false;
	bool case5=false;

    cout<<"\t\t\t\t\t\tBienvenue dans votre catalogue de trajets"<<endl;
    cout<<"\t\tIci vous pouvez constituer ou charger des itnéraires pour après les consulter, les rechercher et même les sauvegarder\n"<<endl;

    for( ; ; ) //D'après le guide de style (T-22)
    {
        cout<<"Menu :"<<endl;
        cout<<"\t1:Afficher le catalogue"<<endl;
        cout<<"\t2:Ajouter un trajet simple"<<endl;
        cout<<"\t3:Ajouter un trajet composé"<<endl;
        cout<<"\t4:Rechercher un trajet"<<endl;
        cout<<"\t5:Sauvegarder le catalogue"<<endl;
        cout<<"\t6:Charger un fichier dans le catalogue"<<endl;
        cout<<"\t0:Quitter"<<endl;
        cin>>lecture;
		case6=false;
		case5=false;

        switch(lecture)
        {   
            case 0:
		   		cout<<"Bon voyage !"<<endl;
				break;

			
			
			case 1:
                c->Afficher();
                break;
        
            case 2:
                cout<<"Ville de départ : ";
                cin>>villeD;
                cout<<"Ville d'arrivée : ";
                cin>>villeA;
                cout<<"Transport : ";
                cin>>transport;
                c->AjouterTrajetSimple(villeD,villeA,transport);
                break;
            
            case 3:
				deleteE=true;
                etapes=new ListeTrajets();
                cout<<"Tapez 'fin' dans Ville de départ lorsque vous voulez arrêter de rentrer des étapes"<<endl;

                for( ; ; )
                {
                    cout<<"Ville de départ : ";
                    cin>>villeD;
                    if(strcmp(villeD,"fin")==0 || strcmp(villeD,"FIN")==0){
                        break;
                    }
                    if(index==0){
                        ++index;
                    }
                    cout<<"Ville d'arrivée : ";
                    cin>>villeA;
                    cout<<"Transport : ";
                    cin>>transport;

                    trajetS = new TrajetSimple(villeD,villeA,transport);
                    etapes->AjouterTrajetFin(trajetS,false);
                }
                if(index!=0){
                    c->AjouterTrajetCompose(etapes);
                    index=0;
                }
                break;
                
            case 4:
                cout<<"Point de départ : ";
                cin>>villeD;
                cout<<"Point d'arrivée : ";
                cin>>villeA;
                c->Rechercher(villeD,villeA);
                break;
            
            //  SAUVEGARDE DU CATALOGUE
			case 5: 
				for( ; ; )
				{
					cout<<"Critères de sauvegarde :"<<endl;
					cout<<"\t1:Sans critère de sélection"<<endl;
					cout<<"\t2:Selon le type des trajets"<<endl;
					cout<<"\t3:Selon la ville de départ"<<endl;
					cout<<"\t4:Selon la ville d'arrivée"<<endl;
					cout<<"\t5:Selon une sélection de trajets"<<endl;
					cout<<"\t0:Retour au menu"<<endl;
					cin>>lecture;
					case5=true;
					
					switch (lecture)
					{
						case 0:
							cout<<"Retour menu principal"<<endl;
							break;

						case 1: 
					
							cout<<"Nom du fichier de sauvegarde : ";
							cin>>nomFichier;
							fSauvegarde.open(nomFichier, ios::app);
							aSauvegarde=c->getListeTrajets()->getPremierElement();
							if(fSauvegarde)
							{	
								while (aSauvegarde!=nullptr)
								{
									if(aSauvegarde->getTrajet()->getType()=="S"){
										SauvegardeTrajetS(fSauvegarde, aSauvegarde);
									}
									else
									{
										SauvegardeTrajetC(fSauvegarde, aSauvegarde);
									}
									
									aSauvegarde=aSauvegarde->getNext();
								}
							}
							else
							{
								cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
							}
							fSauvegarde.close();
							break;
							
						case 2:
							cout<<"Tapez 'S' pour sauvegarder les trajets simples, 'C' pour sauvegarder les trajets composés."<<endl;
							cout<<"Type de trajet : ";
							cin>>lettre;
							if (lettre=='S')
							{
								cout<<"Nom du fichier de sauvegarde : ";
								cin>>nomFichier;
								fSauvegarde.open(nomFichier, ios::app);
								aSauvegarde=c->getListeTrajets()->getPremierElement();
								if(fSauvegarde)
								{
										
									while (aSauvegarde!=nullptr)
									{
										if(aSauvegarde->getTrajet()->getType()=="S"){
											SauvegardeTrajetS(fSauvegarde, aSauvegarde);
										}
										aSauvegarde=aSauvegarde->getNext();
									}
								}
								else
								{
									cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
								}
								fSauvegarde.close();
								
							}
							else if(lettre=='C')
							{
								cout<<"Nom du fichier de sauvegarde : ";
								cin>>nomFichier;
								fSauvegarde.open(nomFichier, ios::app);
								aSauvegarde=c->getListeTrajets()->getPremierElement();
								if(fSauvegarde)
								{	
									while (aSauvegarde!=nullptr)
									{
										if(aSauvegarde->getTrajet()->getType()=="C")
										{
											SauvegardeTrajetC(fSauvegarde, aSauvegarde);
										}
										aSauvegarde=aSauvegarde->getNext();
									}
								}
								else
								{
									cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
								}	
								fSauvegarde.close();	
							}
							else
							{
								cout<<"Mauvais choix"<<endl;
							}
							break;
							
						case 3:
						
							cout<<"Point de départ : ";
							cin>>villeD;
							cout<<"Nom du fichier de sauvegarde : ";
							cin>>nomFichier;
							fSauvegarde.open(nomFichier, ios::app);
							aSauvegarde=c->getListeTrajets()->getPremierElement();
							if(fSauvegarde)
							{
									while (aSauvegarde!=nullptr)
									{
										if(strcmp(aSauvegarde->getTrajet()->getDepart(),villeD)==0)
										{
											if(aSauvegarde->getTrajet()->getType()=="C")
											{
												SauvegardeTrajetC(fSauvegarde, aSauvegarde);
											}
											else
											{
												SauvegardeTrajetS(fSauvegarde, aSauvegarde);
											}
										}
										aSauvegarde=aSauvegarde->getNext();
									}
							}
							else
							{
								cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
							}	
							fSauvegarde.close();
							break;
							
							
						case 4:
							cout<<"Point d'arrivée : ";
							cin>>villeA;
							
							cout<<"Nom du fichier de sauvegarde : ";
							cin>>nomFichier;
							fSauvegarde.open(nomFichier, ios::app);
							aSauvegarde=c->getListeTrajets()->getPremierElement();
							if(fSauvegarde)
							{	
						
									while (aSauvegarde!=nullptr)
									{
										if(strcmp(aSauvegarde->getTrajet()->getArrivee(),villeA)==0){
											if(aSauvegarde->getTrajet()->getType()=="C"){
												SauvegardeTrajetC(fSauvegarde, aSauvegarde);
											}
											else
											{
												SauvegardeTrajetS(fSauvegarde, aSauvegarde);
											}
										}
										aSauvegarde=aSauvegarde->getNext();
									}
							}
							else
							{
								cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
							}	
							fSauvegarde.close();
							break;
							
						case 5:
							cout<< "Tapez les deux bornes de l'intervalle de trajets que vous souhaitez sauvegarder"<<endl;
							cout<< "Début de l'intervalle: ";
							cin>>n;
							cout<< "Fin de l'intervalle: ";
							cin>>m;
							cout<<"Nom du fichier de sauvegarde : ";
							cin>>nomFichier;
							
							fSauvegarde.open(nomFichier, ios::app);
							aSauvegarde=c->getListeTrajets()->getPremierElement();
							if(fSauvegarde)
							{	
								index=1;
									while (index<n)
									{
										++index;
										aSauvegarde=aSauvegarde->getNext();
									}//arriver à l'élément n du catalogue
									
									while (index<=m && aSauvegarde!=nullptr)
									{
							
									if(aSauvegarde->getTrajet()->getType()=="S"){
							
										SauvegardeTrajetS(fSauvegarde, aSauvegarde);
									}
									else
									{
										SauvegardeTrajetC(fSauvegarde, aSauvegarde);
									}
									++index;
									aSauvegarde=aSauvegarde->getNext();
								}
							}
							else
							{
								cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
							}
							fSauvegarde.close();
							break;
					default:
						cout<<"Mauvais choix"<<endl;
						break;
					}
					
					if(lecture==0){
						break;
					}
				}

			//  CHARGEMENT DU CATALOGUE
			case 6:

				//Ainsi on ne rentre pas dans le case 6 si on on provient du case 5 (car on sort du case 5 avec la fin d'une boucle infinie -> ça nous faire rentrer dans les autres cases)
				if(case5){
					break;
				}

				for( ; ; ){

					cout<<"Critères de chargement :"<<endl;
					cout<<"\t1:Sans critère de sélection"<<endl;
					cout<<"\t2:Selon le type des trajets"<<endl;
					cout<<"\t3:Selon la ville de départ"<<endl;
					cout<<"\t4:Selon la ville d'arrivée"<<endl;
					cout<<"\t5:Selon une sélection de trajets"<<endl;
					cout<<"\t0:Retour au menu"<<endl;
					cin>>lecture;
					case6=true;
					deleteE=true;

					switch (lecture)
					{

					case 0:
						cout<<"Retour menu principal"<<endl;
						break;
					case 1:
						cout<<"Nom du fichier de chargement : ";
						cin>>nomFichier;
						fChargement.open(nomFichier);
						if(fChargement)
						{
							for( ; ; )
							{
								fChargement.getline(id,2,':');

								if(fChargement.tellg()==-1)
								{
									break;
								}

								if (!strcmp(id,"S"))
								{	
									ChargementTrajetS(fChargement,c);
								}
								else
								{
									ChargementTrajetC(fChargement,c);
								}
							}
						}
						else
						{
							cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
						}
						fChargement.close();
						break;
					
					case 2:
						
						cout<<"Nom du fichier de chargement : ";
						cin>>nomFichier;
						fChargement.open(nomFichier);
						if(fChargement)
						{
							cout<<"Tapez 'S' pour charger les trajets simples, 'C' pour charger les trajets composés."<<endl;
							cout<<"Type de trajet : ";
							cin>>lettre;
							if (lettre=='S')
							{
								for( ; ; )
								{
									fChargement.getline(id,2,':');

									if(fChargement.tellg()==-1)
									{
										break;
									}

									if (!strcmp(id,"S"))
									{	ChargementTrajetS(fChargement,c);
									}
									else
									{
										//On avance dans le stream jusqu'à ce qu'on atteigne sa fin ou un autre trajetS, si oui il faut le rembobiner 
										for( ; ; )
										{
											fChargement.getline(ligne,610);
											if(fChargement.tellg()==-1){
												break;
											}
											if(ligne[0]=='S' && ligne[1]==':')
											{
												fChargement.seekg((int) fChargement.tellg()-strlen(ligne)-1);
												break;
											}
										}
									}
								}
							}
							else if(lettre=='C')
							{
								for( ; ; )
								{
									fChargement.getline(id,2,':');

									if(fChargement.tellg()==-1)
									{
										break;
									}
									if(!strcmp(id,"C"))
									{
										ChargementTrajetC(fChargement,c);
									}else{
										//On avance dans le stream jusqu'à ce qu'on atteigne sa fin ou un autre trajetC, si oui il faut le rembobiner 
										for( ; ; )
										{
											fChargement.getline(ligne,610);
											if(fChargement.tellg()==-1){
												break;
											}
											if(ligne[0]=='C' && ligne[1]==':')
											{
												fChargement.seekg((int) fChargement.tellg()-strlen(ligne)-1);
												break;
											}
										}
									}	
								}
							}
						}
						else
						{
							cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
						}
						fChargement.close();
						break;

					case 3:
						cout<<"Nom du fichier de chargement : ";
						cin>>nomFichier;
						fChargement.open(nomFichier);
						if(fChargement)
						{
							cout<<"Point de départ : ";
							cin>>findVille;
							for( ; ; )
							{
								fChargement.getline(id,2,':');
								if(fChargement.tellg()==-1){
									break;
								}
								fChargement.getline(villeD,200,'_');
								if(!strcmp(findVille,villeD))
								{
									if(!strcmp(id,"S"))
									{
										fChargement.seekg((int) fChargement.tellg()-strlen(villeD)-1); //On remet à jour la position car elle est biaisée
										ChargementTrajetS(fChargement,c);
									}
									else
									{
										ChargementTrajetC(fChargement,c);
									}
								}else{
									//On avance dans le stream jusqu'à ce qu'on atteigne sa fin ou un autre trajet, si oui il faut le rembobiner 
									RembobinerFlux(fChargement);
								}	
							}
						}else{
							cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
						}
						fChargement.close();
						break;

					case 4:
						cout<<"Nom du fichier de chargement : ";
						cin>>nomFichier;
						fChargement.open(nomFichier);
						if(fChargement)
						{
							cout<<"Point d'arrivée : ";
							cin>>findVille;
							for( ; ; )
							{
								fChargement.getline(id,2,':');
								if(fChargement.tellg()==-1){
									break;
								}
								fChargement.getline(villeD,200,'_');

								if(!strcmp(id,"S")){
									fChargement.getline(villeA,200,'_');
								}else{
									fChargement.getline(villeA,200,';');
								}

								if(!strcmp(findVille,villeA))
								{
									if(!strcmp(id,"S"))
									{
										fChargement.getline(transport,200,'\n');
										c->AjouterTrajetSimpleFin(villeD, villeA, transport);
									}
									else
									{
										ChargementTrajetC(fChargement,c);
									}
								}else{
									//On avance dans le stream jusqu'à ce qu'on atteigne sa fin ou un autre trajet, si oui il faut le rembobiner 
									RembobinerFlux(fChargement);
								}	
							}
						}else{
							cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
						}
						fChargement.close();
						break;

					case 5:
						cout<< "Tapez les deux bornes de l'intervalle de trajets que vous souhaitez charger"<<endl;
						cout<< "Début de l'intervalle: ";
						cin>>n;
						cout<< "Fin de l'intervalle: ";
						cin>>m;
						cout<<"Nom du fichier de chargement : ";
						cin>>nomFichier;
						fChargement.open(nomFichier);
						if(fChargement)
						{
							index=1;
							while (index<n)
							{
								++index;
								fChargement.getline(ligne,610);
							}//arriver à l'élément n du catalogue

							while(index<=m && fChargement.tellg()!=-1)
							{
								fChargement.getline(id,2,':');

								if(fChargement.tellg()==-1)
								{
									break;
								}

								if (!strcmp(id,"S"))
								{	
									ChargementTrajetS(fChargement,c);
									++index;
								}
								else if(!strcmp(id,"C"))
								{
									ChargementTrajetC(fChargement,c);
									++index;
								}
								else{
									//On avance dans le stream jusqu'à ce qu'on atteigne sa fin ou un autre trajet, si oui il faut le rembobiner 
									RembobinerFlux(fChargement);
								}	
							}
						}else{
							cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
						}
						fChargement.close();
						break;

					default:
						cout<<"Mauvais choix"<<endl;
						break;
						
					}
					
					if(lecture==0){
						break;
					}
				}
				
				default:

				if(!case6){
					cout<<"Mauvais choix"<<endl;
				}		
				break;
			}


		if(lecture==0 && !case6 && !case5){
			break;
		}
    }
	
	if(deleteE)
	{
		delete etapes;
	}
    delete c;
    return 0;
}//-----fin du main

/////////////////////////////////////////////////////////////////// SauvegardeTrajetS
void SauvegardeTrajetS(ofstream &fSauvegarde, Element* aSauvegarde)
{
	fSauvegarde<< "S:" << aSauvegarde->getTrajet()->getDepart() << "_" << aSauvegarde->getTrajet()->getArrivee() << "_" << aSauvegarde->getTrajet()->getTransport() <<endl;
}//-----fin de SauvegardeTrajetS

/////////////////////////////////////////////////////////////////// SauvegardeTrajetC
void SauvegardeTrajetC(ofstream &fSauvegarde, Element* aSauvegarde)
{
	fSauvegarde<< "C:" <<aSauvegarde->getTrajet()->getDepart() << "_" << aSauvegarde->getTrajet()->getArrivee()<< ";" <<endl;
	Element* listeEtapes=((TrajetCompose*) (aSauvegarde->getTrajet()))->getListeEtapes()->getPremierElement();
	while (listeEtapes!=nullptr)
	{
		fSauvegarde<<  listeEtapes->getTrajet()->getDepart() << "_" << listeEtapes->getTrajet()->getArrivee() << "_" << listeEtapes->getTrajet()->getTransport() <<endl;
		listeEtapes=listeEtapes->getNext();
	}
}//-----fin de SauvegardeTrajetC

/////////////////////////////////////////////////////////////////// ChargementTrajetS
void ChargementTrajetS(ifstream &fChargement, Catalogue* c)
{
	char villeD[200];
    char villeA[200];
    char transport[200];
    fChargement.getline(villeD,200,'_');
	fChargement.getline(villeA,200,'_');
	fChargement.getline(transport,200,'\n');
	c->AjouterTrajetSimpleFin(villeD, villeA, transport);  
}//-----fin de ChargementTrajetS

/////////////////////////////////////////////////////////////////// ChargementTrajetC
void ChargementTrajetC(ifstream &fChargement, Catalogue* c)
{
	char villeD[200];
    char villeA[200];
    char transport[200];
	etapes=new ListeTrajets();
	fChargement.getline(villeD,200); //On saute la première ligne qui ne nous sert à rien pour remplir le catalogue
	fChargement.getline(villeD,200,'_');
	while(fChargement.tellg()!=-1)
	{
		if(!strncmp(villeD,"C:",2) || !strncmp(villeD,"S:",2))
		{
			fChargement.seekg((int) fChargement.tellg()-strlen(villeD)-1); //On remet à jour la position car elle est biaisée
			break;
		}
		fChargement.getline(villeA,200,'_');
		fChargement.getline(transport,200);
		TrajetSimple* trajetS=new TrajetSimple(villeD,villeA,transport);
		etapes->AjouterTrajetFin(trajetS,false);
		fChargement.getline(villeD,200,'_');
	}
	c->AjouterTrajetComposeFin(etapes);
}//-----fin de ChargementTrajetC

/////////////////////////////////////////////////////////////////// RembobinerFlux
void RembobinerFlux(ifstream &fChargement)
{
	char ligne[610];
	for( ; ; )
	{
		fChargement.getline(ligne,610);
		if(fChargement.tellg()==-1){
			break;
		}
		if((ligne[0]=='C' && ligne[1]==':') || (ligne[0]=='S' && ligne[1]==':') )
		{
			fChargement.seekg((int) fChargement.tellg()-strlen(ligne)-1);
			break;
		}
	}
}//-----fin de RembobinerFlux