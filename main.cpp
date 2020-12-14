#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>

using namespace std;



struct dO
{
    float d=600;
    float Ho=100;
    float Xo=0;
    float Yo=Ho;
    float rd0=0,05*d;
};

struct dD
{
    float d=600;
    float Hd=200;
    float Xd=d;
    float Yd=Hd;
    float rdd=0,025d;

};


int PrimercasoDisparo(dO DisparoO,dD DisparoD)
{
    srand(time(NULL))
    V0=rand() %100+1;
    float x,y;
    float Vx0,Vy0;
    float V0;
    int t=0;
    int angulo;
    int V=V0;
    for (V=V0; ;V0+=5)
    {
        for(angulo=0;angulo <90;angulo++)
        {
            Vx0*cos(angulo*M_PI/180); //calculando velocidad en x
            Vy0*sin(angulo*M_PI/180); //calculando velocidad en y

        }
    }
}

int SegundoCasoDisparo()
{

}

int TercerCasoDisparo()
{

}

int CuartoCasoDisparo()
{

}

int QuintoCasoDisparo()
{

}


int main()
{
    dO DisparoO;
    dD DisparoD;

    return 0;
}
