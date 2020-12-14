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
    float rdo=0.05*d;
    string estado="ofensa";
};

struct dD
{
    float d=600;
    float Hd=200;
    float Xd=d;
    float Yd=Hd;
    float rdd=0.25d;


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
        //cout<<"aaaaa"<<endl;
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
                if(sqrt(pow((DisparoD.Xd-x),2)+pow((DisparoD.Yd-y),2))< DisparoO.rdo)
                {
                    if(y<0) y=0;
                    ImprimirImpacto(angulo,V0,x,y,t);
                    c=c+1;
                    V0=V0+50;
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

int SegundoCasoDisparo(dO DisparoO,dD DisparoD)
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
        //cout<<"aaaaa"<<endl;
        for(angulo=0;angulo <90;angulo++)
        {
            Vx0= V0*cos(angulo*M_PI/180); //calculando velocidad en x
            Vy0= V0*sin(angulo*M_PI/180); //calculando velocidad en y

            x=0.0;
            y=0.0;
            for(t=0;;t++)
            {
                x=Vx0*t;
                y=DisparoD.Yd + Vy0*t -(0.5*g*pow(t,2));
                if(sqrt(pow((DisparoO.Xo-x),2)+pow((DisparoO.Yo-y),2))< DisparoD.rdd)
                {
                    if(y<0) y=0;
                    ImprimirImpacto(angulo,V0,x,y,t);
                    c=c+1;
                    V0=V0+50;
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
    Posicion_de_canon(DisparoO.Xo,DisparoO.Yo,DisparoO.estado);
    cout<<"Cual caso va a emular 1-2-3-4-5"<<endl;
    int op=0;
    cin>>op;
    switch (op)
    {
    case 1:
    {
        PrimercasoDisparo(DisparoO,DisparoD);
    }
    case 2:
    {
        SegundoCasoDisparo(DisparoO,DisparoD);
    }



        break;

    }





    return 0;
}
