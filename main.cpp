#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Dame.hpp"

void Ablauf()
/** \brief Allgemeiner Ablauf des Dame-Spiels
 *
 *         Zuerst wird die Liste als vektor von Zeichenketten deklariert. Das erste Element der Liste wird mit einer
 *         leeren Zeichenkette festgelegt. Danach wird der Konstruktor der Klasse Dame auf die Variable Damenspiel abgebildet.
 *         Im Folgenden wird die Überschrift durch std::cout und das Spielbrett dargestellt.
 *         Das folgende wird solange durchlaufen, bis die Funktion Besiegt den Wert true zurückgibt:
 *         Zuerst wird die Funktion Setzen aufgerufen und falls die Variable der Klasse eingab = "-" ist, wird geprüft, ob die Zahl
 *         der Zuege über 0 ist. Ist dies der Fall wird das Element der Liste aufgerufen, das an der Stelle der Anzahl der Zuege liegt
 *         und die Variablen der Buchstaben und Zahlen gleich der entsprechenden Werte der Liste gesetzt. Demzufolge wird der erste
 *         Buchstabe der Liste zum zweiten Buchstaben der Klasse usw. Dadurch und durch das darauffolgende wird praktisch der Spielstein
 *         wieder an seine vorherige Position gesetzt und falls ein Stein geschlagen wurde, jener wieder gesetzt werden. Weiterhin
 *         wird der Spieler, der am Zug ist, wieder gewechselt. Außerdem wird das letzte Element der Liste gelöscht und das Spielbrett
 *         ausgegeben.
 *         Falls Besiegt gleich true gesetzt wird, starten zwei ineinander verschachtelte Schleifen, die Zählen, wie viele Spielsteine
 *         von der jeweiligen Farbe noch auf dem Feld liegen. Der Spieler, der mehr Steine hat, wird demnach als Gewinnner festgelegt
 *         und dies wird ausgegeben.
 *         Danach beendet sich das Programm.
 *
 */
{
    std::vector < std::string > Liste;
    Liste.push_back("");

    Dame Damenspiel;
    std::cout << "                  Das DAME - Spiel" << std::endl << std::endl;

    std::cout << Damenspiel;
    while(Besiegt(Damenspiel) == false)
    {
        Setzen(Damenspiel);
        if(Damenspiel.eingab == "-")
        {

            if ( Damenspiel.Zuege > 0)
            {
                Liste.at(Damenspiel.Zuege);
                Damenspiel.ersterBuchstabe = Liste.at(Damenspiel.Zuege).at(3);
                Damenspiel.ersteZahl = (int)Liste.at(Damenspiel.Zuege).at(4) - 49;
                Damenspiel.zweiterBuchstabe = Liste.at(Damenspiel.Zuege).at(0);
                Damenspiel.zweiteZahl = (int)Liste.at(Damenspiel.Zuege).at(1) - 49;


                Damenspiel.Belegung[Damenspiel.zweiteZahl][Damenspiel.zweiterBuchstabe - 65] = Damenspiel.Belegung[Damenspiel.ersteZahl][Damenspiel.ersterBuchstabe - 65];
                Damenspiel.Belegung[Damenspiel.ersteZahl][Damenspiel.ersterBuchstabe - 65] = ' ';
                if(abs(Damenspiel.ersterBuchstabe - Damenspiel.zweiterBuchstabe) == 2)
                {
                    Damenspiel.Belegung[(Damenspiel.ersteZahl + Damenspiel.zweiteZahl) / 2][((Damenspiel.ersterBuchstabe - 65) + (Damenspiel.zweiterBuchstabe) - 65) / 2] = ' ';
                }
                if(Damenspiel.AmZug == 'W')
                {
                    Damenspiel.AmZug = 'S';
                } else {
                    Damenspiel.AmZug = 'W';
                }
                Liste.pop_back();
                Damenspiel.Zuege -= 1;
            } else {
                std::cout << "Zug kann nicht rueckgaengig gemacht werden" << std::endl;
            }
        } else {
        Liste.push_back(Damenspiel.eingab);
        }
        std::cout << Damenspiel;
    }
    int Weiss = 0, Schwarz = 0;
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            if(Damenspiel.Belegung[i][j] == 'W')
            {
                Weiss += 1;
            } else {
                if(Damenspiel.Belegung[i][j] == 'S')
                {
                    Schwarz += 1;
                }
            }
        }
    }
    if(Weiss < Schwarz)
    {
        std::cout << "Schwarz hat gewonnen!" << std::endl;
    } else {
        if(Weiss > Schwarz)
        {
            std::cout << "Weiss hat gewonnen!" << std::endl;
        }
    }
}


/** \brief Ruft die Funktion Ablauf auf
 *
 */
int main()
{
    Ablauf();
}
