//
//  main.c
//  Projet3
//
//  Created by Saïd H on 15/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "calculatrice.h"
#include <math.h>
#include <ctype.h>
#include <gtk/gtk.h>


//Variables Globale pour les entrées
GtkWidget *pointeurEntree1; /*!<Pointeur de la première entrée de Nombre 1*/
GtkWidget *pointeurEntree2; /*!<Pointeur de la seconde entrée de Nombre 2*/

//Variable Globale pour afficher la reponse
GtkWidget *pointeurLabel3; /*!<pointeur du Troisème label "Qui donnera la réponse"*/

int main(int argc, char **argv){
    
    GtkWidget *pointeurFenetre; //Pointeur de la fenêtre

    GtkWidget *pointeurBouton; //Pointeur du bouton "Addition"
    
    GtkWidget *pointeurLabel1; //Pointeur du premier label "Nombre 1"
    GtkWidget *pointeurLabel2; //Pointeur du second label "Nombre 2"    
    GtkWidget *pointeurBoxVerticale; //Pointeur de la box Verticale
    
    GtkWidget *pointeurBoxHorizontale1; //Pointeur de la box Horizontale pour Label1 et Entree1
    GtkWidget *pointeurBoxHorizontale2; //Pointeur de la box Horizontale pour Label2 et Entree2
    GtkWidget *pointeurBoxHorizontale3; //Pointuer de la box Horizontale pour Bouton et Label3
    
    
    gtk_init(&argc, &argv); //Initialisation de GTK
    
    pointeurFenetre = creer_fenetre("Calculatrice"); //Création de la fenêtre
    
    /* -- Creation de la composition de la fenêtre -- */
    
    //Creation de la box Verticale
    pointeurBoxVerticale = gtk_vbox_new(TRUE, 0);
    
    //Creation du premier label
    pointeurLabel1 = gtk_label_new("Nombre 1:");
    
    //Creation du second label
    pointeurLabel2 = gtk_label_new("Nombre 2:");
    
    //Création de l'EntryBox 1
    pointeurEntree1 = gtk_entry_new();
    
    //Création de l'EntryBox2
    pointeurEntree2 = gtk_entry_new();
    
    //TEST
    pointeurLabel3 = gtk_label_new("La somme vaut :");
    
    //Création du bouton
    pointeurBouton = bouton_addition();
    
    //Creation de la première box Horizontale
    pointeurBoxHorizontale1 = gtk_hbox_new(TRUE, 0);
    
    //Creation de la seconde box Horizontale
    pointeurBoxHorizontale2 = gtk_hbox_new(TRUE, 0);
    
    //Creation de la 3 ème box Horizontale
    pointeurBoxHorizontale3 = gtk_hbox_new(TRUE, 0);
    
       
    /* -- Fin composition de la fenêtre -- */
    
    /* -- Manipulation -- */

    //imbrication de la première box horizontale dans la box verticale
    gtk_box_pack_start(GTK_BOX(pointeurBoxVerticale), pointeurBoxHorizontale1, TRUE, FALSE, 0);
    
    //Insertion du Label1 dans la première Box Horizontale
    gtk_box_pack_start(GTK_BOX(pointeurBoxHorizontale1), pointeurLabel1, TRUE, FALSE, 0);
    
    //Insertion de la boxEntry1 dans la première Box Horizontale
    gtk_box_pack_start(GTK_BOX(pointeurBoxHorizontale1), pointeurEntree1, TRUE, FALSE, 0);
    
    //Imbricaton de la seconde box horizontale dans la box verticale
    gtk_box_pack_start(GTK_BOX(pointeurBoxVerticale), pointeurBoxHorizontale2, TRUE, FALSE, 0);
    
    //Insertion du Label2 dans la seconde box Horizontale
    gtk_box_pack_start(GTK_BOX(pointeurBoxHorizontale2), pointeurLabel2, TRUE, FALSE, 0);
    
    //Insertion du BoxEntry2 dans la seconde box Horizontale
    gtk_box_pack_start(GTK_BOX(pointeurBoxHorizontale2), pointeurEntree2, TRUE, FALSE, 0);
    
    //Imbrication de la Troisième box Horizontale dans la box Verticale
    gtk_box_pack_start(GTK_BOX(pointeurBoxVerticale), pointeurBoxHorizontale3, TRUE, FALSE, 0);
    
    //Insertion du bouton dans la Troisième box Horizontale
    gtk_box_pack_start(GTK_BOX(pointeurBoxHorizontale3), pointeurBouton, TRUE, FALSE, 0);
    
    //Insertion du Label3 dans la Troisième box Horizontale
    gtk_box_pack_start(GTK_BOX(pointeurBoxHorizontale3), pointeurLabel3, TRUE, FALSE, 0);
    
    //Affiche les widget
    gtk_container_add(GTK_CONTAINER(pointeurFenetre), pointeurBoxVerticale);

    /* -- Fin Manipulation -- */
    
    gtk_widget_show_all(pointeurFenetre); //Affiche la fenêtre
    
    gtk_main(); // Lancement de la boucle de GTK

    return EXIT_SUCCESS;
}

