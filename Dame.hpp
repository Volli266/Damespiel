#pragma once

#include <iostream>
#include <string>



/** \brief  Klasse des Damespiels
 *
 *          Besitzt als private Variablen die Anfangs- und Endposition bei einem Zug, die Realisierung des Brettes in Form eines
 *          8x8 Arrays, welcher Spieler gerade am Zug ist als char, sowie der wie vielte Zug derzeit gespielt wird als int und
 *          eine Zeichenkette, die die Eingabe übergibt.
 *
 *          Der Konstruktor legt die Anfangsbelegung des Brettes fest im Sinne der Standorte der jeweiligen Spielsteine. Außerdem
 *          wird Weiss als Beginner festgelegt und die Anzahl der Zuege auf 0 gesetzt.
 *
 *          Im Folgenden werden noch die genutzten Funktionen als friend festgelegt und die Klasse geschlossen.
 *
 */
class Dame
{

public:

    Dame()
    {
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            if (((i - j) % 2) == 0)
            {
                Belegung[i][j] = ' ';

                if(i < 3)
                {
                    Belegung[i][j] = 'W';
                } else {
                     if(i > 4)
                    {
                        Belegung[i][j] = 'S';
                    }
                }
            } else {
                Belegung[i][j] = 178;
            }
        }
    }
    AmZug = 'W';
    Zuege = 0;
    }


    friend std::istream& operator>>(std::istream& eing, Dame& dam);
    friend void operator<<(std::ostream &ausg, Dame dam);
    friend bool Gueltigkeit(char eb, int ez, char zb, int zz, Dame& dam);
    friend void Setzen(Dame& dam);
    friend void Ablauf();
    friend bool Besiegt(Dame dam);


private:
    char ersterBuchstabe;
    char zweiterBuchstabe;
    int ersteZahl;
    int zweiteZahl;
    char Belegung[8][8];
    char AmZug;
    int Zuege;
    std::string eingab;
};



