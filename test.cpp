#include <iostream>
#include <string>
#include "Dame.hpp"

    char Belegung[8][8];
    char Brett[16][16];


void Faerbung()
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

}

void Umwandlung()
{
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            if(Belegung[i][j] == ' ')
            {
                Brett[2*i][2*j] = Belegung[i][j];
                Brett[2*i+1][2*j] = Belegung[i][j];
                Brett[2*i][2*j+1] = Belegung[i][j];
                Brett[2*i+1][2*j+1] = Belegung[i][j];
            } else {
                if(Belegung[i][j] == 'S')
                {
                    Brett[2*i][2*j] = 192;
                    Brett[2*i+1][2*j] = 218;
                    Brett[2*i][2*j+1] = 217;
                    Brett[2*i+1][2*j+1] = 191;
                } else {
                    if(Belegung[i][j] == 'W')
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
}

void Ausgabe()
{
    for(int i = 15; i >= 0; i--)
    {
        if( (i % 2) == 1)
        {
            std::cout << " " << (8 - ((i - (i % 2)) / 2)) << " ";
        } else {
            std::cout << "   ";
        }
        for( int j = 0; j <= 15; j++)
        {
            std::cout << Brett[i][j];
        }
            std::cout << std::endl;

    }
        std::cout << "   A B C D E F G H" << std::endl;
}
/*
int main()
{

    Faerbung();
    Umwandlung();
    Ausgabe();
    char *pointer = &Belegung[1][1];
    std::cout << &pointer;
}*/
