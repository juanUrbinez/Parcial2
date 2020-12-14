#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>

#define g 9.81

using namespace std;



struct dO
{
    float d=600;
    float Ho=100;
    float Xo=0;
    float Yo=Ho;
    float rd0=0.05*d;
    string estado="ofensa";
};

struct dD
{
    float d=600;
    float Hd=200;
    float Xd=d;
    float Yd=Hd;
    float rdd=0.025d;
    string estado="defensa";

};

void ImprimirImpacto(int angulo,int VelocidadInicial,float x,float y,int t)
{
    cout << "Impacto con un angulo de " << angulo << " grados" << endl;
    cout << "Impacto con velocidad incial " << VelocidadInicial << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}

void Posicion_de_canon(float x,float y,string estado)
{
    cout <<"EL cañon de "<<estado<<endl;
    cout <<"Se encuentra en las coordenadas(x,y): ("<<x<<","<<y<<")"<<endl;
    cout <<endl;
}



int PrimercasoDisparo(dO DisparoO,dD DisparoD)
{
    srand(time(NULL));
    int V0=0;
    V0=rand() %100+1;
    float x,y;
    float Vx0,Vy0;
    int t=0;
    int angulo;
    int V=V0;
    int c=0;
    for (V=V0; ;V0+=5)

    {
        for(angulo=0;angulo <90;angulo++)
        {
            Vx0= V0*cos(angulo*M_PI/180); //calculando velocidad en x
            Vy0= V0*sin(angulo*M_PI/180); //calculando velocidad en y

            x=0.0;
            y=0.0;
            for(t=0;;t++)
            {
                x=Vx0*t;
                y=DisparoO.Yo + Vy0*t -(0.5*g*pow(t,2));
                if(sqrt(pow((DisparoD.Xd-x),2)+pow((DisparoD.Yd-y),2))< DisparoO.rd0)
                {
                    if(y<0) y=0;
                    ImprimirImpacto(angulo,V0,x,y,t);
                    c=c+1;
                    V0=V0+20;
                    break;
                }
                if (y<0){
                    break;
                }
            }
            if(c==3)
            {{
                break;
            }


        }
        if(c==3){
            break;
        }
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
    Posicion_de_canon(DisparoD.Xd,DisparoD.Yd,DisparoD.estado);

    PrimercasoDisparo(DisparoO,DisparoD);

    return 0;
}
