#include <iostream>
#include <string>

#include "Dame.hpp"

std::istream& operator>>(std::istream& eing, Dame& dam)
{
    std::string eingabe;

    eing >> eingabe;

    dam.ersterBuchstabe = eingabe.at(0);
    dam.ersteZahl = (int)eingabe.at(1);

    return eing;
}

Dame operator<<(std::ostream& ausg, Dame& dam)
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
