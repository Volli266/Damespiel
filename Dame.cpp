#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "Dame.hpp"


/** \brief  Festlegung des Input - Operators für die Klasse Dame
 *
 *          Deklaration der Zeichenkette eingabe, durch std::getline wird die Eingabe der Zeichenkette mit Leerzeichen realisiert.
 *          Die Zeichenkette wird an die Klasse übergeben und falls die eingabe = "-" ist, wird die Funktion beendet. Falls dies nicht
 *          der Fall ist, werden die Buchstaben und Zahlen an die Klasse übergeben
 *
 * \param eing std::istream& legt fest, dass durch >> eine Eingabe realisiert wird
 * \param com Dame& übergibt die Werte der Klasse
 * \return eing std::istream& keine Rückgabe, nur Beenden der Funktion
 *
 */
std::istream& operator>>(std::istream& eing, Dame& dam)
{
    std::string eingabe;
    std::getline(eing, eingabe);

    dam.eingab = eingabe;
    if(eingabe == "-")
    {
        return eing;
    }
    dam.ersterBuchstabe = eingabe.at(0);
    dam.ersteZahl = (int)eingabe.at(1) - 49;
    dam.zweiterBuchstabe = eingabe.at(3);
    dam.zweiteZahl = (int)eingabe.at(4) - 49;
}

/** \brief  Festlegung des Output - Operators für die Klasse Dame
 *
 *          Zuerst wird ein Array 16 x 16 als Brett realisiert, dass der Ausgabe dient, da jedes Feld einzeln 2x2 Elemente groß ist.
 *          Durch zwei for-Schleifen werden alle Elemente der Klasse entsprechend auf 'Brett' projiziert, entsprechend der Belegung.
 *          Im darauffolgenden werden die Buchstaben und Zahlen am Rand des Brettes realisiert und ausgegeben.
 *
 * \param ausg std::ostream& legt fest, welche Ausgabe durch >> realisiert wird
 * \param dam Dame übergibt die Werte der Klasse
 *
 */
void operator<<(std::ostream &ausg, Dame dam)
{
    char Brett[16][16];
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            if(dam.Belegung[i][j] == ' ')
            {
                Brett[2*i][2*j] = dam.Belegung[i][j];
                Brett[2*i+1][2*j] = dam.Belegung[i][j];
                Brett[2*i][2*j+1] = dam.Belegung[i][j];
                Brett[2*i+1][2*j+1] = dam.Belegung[i][j];
            } else {
                if(dam.Belegung[i][j] == 'S')
                {
                    Brett[2*i][2*j] = 192;
                    Brett[2*i+1][2*j] = 218;
                    Brett[2*i][2*j+1] = 217;
                    Brett[2*i+1][2*j+1] = 191;
                } else {
                    if(dam.Belegung[i][j] == 'W')
                    {
                    Brett[2*i][2*j] = 200;
                    Brett[2*i+1][2*j] = 201;
                    Brett[2*i][2*j+1] = 188;
                    Brett[2*i+1][2*j+1] = 187;
                    } else {
                        Brett[2*i][2*j] = 178;
                        Brett[2*i+1][2*j] = 178;
                        Brett[2*i][2*j+1] = 178;
                        Brett[2*i+1][2*j+1] = 178;
                    }
                }
            }
        }
    }
    for(int i = 15; i >= 0; i--)
    {
        if( (i % 2) == 1)
        {
            ausg << " " << (((i - (i % 2)) / 2 + 1)) << " ";
        } else {
            ausg << "   ";
        }
        for( int j = 0; j <= 15; j++)
        {
            ausg << Brett[i][j];
        }
            ausg << std::endl;
    }
        ausg << "   A B C D E F G H" << std::endl;
}

/** \brief  Test, ob ein entsprechender Zug gültig ist
 *
 *          Abhängig des spielenden Spielers, werden die Variablen Spieler und Gegner initialisiert.
 *          Falls der Abstand von Anfangs- und Endposiotion ein Feld auseinanderliegen und am Anfang der Spieler und am Ende niemand
 *          steht, wird true zurückgegeben und die Funktion beendet.
 *          Falls dazwischen zwei Felder liegen, wird geprüft, ob im Feld in der Mitte eine gegnerische Figur steht und das Endfeld
 *          frei ist und entsprechend true zurückgegeben. Dann wird der gegnerische Stein entfernt.
 *          Falls nichts eintritt, wird false zurückgegeben.
 *
 * \param eb char
 * \param ez int
 * \param zb char
 * \param zz int    sind die Anfangs- und Endposition des Zuges
 * \param dam Dame& Übergabe der Klasse Dame
 * \return bool     Rückgabe, ob der Zug gueltig ist, oder nicht
 *
 */
bool Gueltigkeit(char eb, int ez, char zb, int zz, Dame& dam)
{
    char Spieler, Gegner;
    if(dam.AmZug == 'S')
    {
        Spieler = 'S';
        Gegner = 'W';
    } else {

        Spieler = 'W';
        Gegner = 'S';
    }
    if ( ( abs( zb - eb ) == 1) && ( abs( zz - ez ) == 1) )
    {
        if ((dam.Belegung[ez][eb - 65] == Spieler) && (dam.Belegung[zz][zb-65] == ' '))
        {
            return true;
        }
    }
    if ( ( abs ( zb - eb ) == 2) && ( abs ( zz - ez ) == 2) )
    {
        if ((dam.Belegung[ez][eb - 65] == Spieler) && (dam.Belegung[zz][zb-65] == ' ') && (dam.Belegung[(ez + zz) / 2][((eb - 65) + (zb - 65)) / 2]) == Gegner)
        {
            dam.Belegung[(ez + zz) / 2][((eb - 65) + (zb - 65)) / 2] = ' ';
            return true;
        }
    }
    return false;
}

/** \brief  Setzen eines Steines
 *
 *          Falls Weiss am Zug ist, wird eine entsprechende Ausgabe vorgenommen und bei Schwarz ebenso, um festzulegen, welche Eingabe
 *          folgen soll. Danach wird auf die Eingabe der Anfangs- und Endposition gewartet. Falls "-" eingegeben wird, wird die Funktion
 *          beendet.
 *          Solange der Zug ungueltig ist, wird eine Fehlermeldung ausgegeben und die Eingabe wiederholt.
 *          Der Spielstein wird auf die Endposition gesetzt und von der Anfangsposition entfernt.
 *          Der derzeitige am Spiel befindliche Spieler wird geändert und die Anzahl der Zuege um 1 erhöht.
 *
 * \param dam Dame& Übergabe der Werte der Klasse
 * \return void
 *
 */
void Setzen(Dame& dam)
{
    if(dam.AmZug == 'W')
    {
        std::cout << "Weiss am Zug, Eingabe in der Form A1 B2, '-' fuer Wiederholung des letzten Zuges: " << std::endl;
    } else {
        std::cout << "Schwarz am Zug, Eingabe in der Form A1 B2, '-' fuer Wiederholung des letzten Zuges: " << std::endl;
    }
    std::cin >> dam;
    if (dam.eingab == "-")
    {
        return;
    }
    while (Gueltigkeit(dam.ersterBuchstabe, dam.ersteZahl, dam.zweiterBuchstabe, dam.zweiteZahl, dam) == false)
    {
        std::cout << "Ungueltige Eingabe, Erneuter Versuch:" << std::endl;
        std::cin >> dam;

    }
    dam.Belegung[dam.zweiteZahl][dam.zweiterBuchstabe - 65] = dam.Belegung[dam.ersteZahl][dam.ersterBuchstabe - 65];
    dam.Belegung[dam.ersteZahl][dam.ersterBuchstabe - 65] = ' ';
    if(dam.AmZug == 'W')
    {
        dam.AmZug = 'S';
    } else {
        dam.AmZug = 'W';
    }
    dam.Zuege += 1;
}

/** \brief  Prüft, ob ein Spieler besiegt wurde
 *
 *          Die Belegung der Klasse wird nacheinander einzeln geprüft und es wird false zurückgegeben, falls es wenigstens einen
 *          Spielstein gibt, der entweder ein Feld diagonal ziehen kann, oder in diagonaler Richtung einen gegnerischen Stein schlagen
 *          kann.
 *
 * \param dam Dame übergibt die Daten der Klasse
 * \return bool gibt den entsprechenden Wahrheitswert zurück
 *
 */
bool Besiegt(Dame dam)
{
    bool moeglichkeit = true;
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            if(dam.Belegung[i][j] == dam.AmZug)
            {
                if(dam.AmZug == 'W')
                {
                    if((dam.Belegung[i+1][j+1] == ' ') || (dam.Belegung[i+1][j-1] == ' ') ||
                       ((dam.Belegung[i+1][j+1] == 'S') && (dam.Belegung[i+2][j+2] == ' ')) ||
                       ((dam.Belegung[i+1][j-1] == 'S') && (dam.Belegung[i+2][j-2] == ' ')))
                    {
                        moeglichkeit = false;
                    }
                } else {
                    if((dam.Belegung[i-1][j+1] == ' ') || (dam.Belegung[i-1][j-1] == ' ') ||
                       ((dam.Belegung[i-1][j+1] == 'W') && (dam.Belegung[i-2][j+2] == ' ')) ||
                       ((dam.Belegung[i-1][j-1] == 'W') && (dam.Belegung[i-2][j-2] == ' ')))
                    {
                        moeglichkeit = false;
                    }
                }
            }
        }
    }
    return moeglichkeit;
}

