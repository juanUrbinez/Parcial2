#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>

#define g 9.81

using namespace std;



struct dO
{
    float d=800;
    float Ho=150;
    float Xo=0;
    float Yo=Ho;
    float rd=0.05*d;
    float trd=0.075*d;
    float Municion_especial=0.005*d;
    string estado="ofensa";
};

struct dD
{
    float d=800;
    float Hd=200;
    float Xd=d;
    float Yd=Hd;
    float rd=0.025*d;
    float trd=0.075*d;




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
    for (V=V0; ;V+=5)
    {
        for(angulo=0;angulo <90;angulo++)
        {
            Vx0= V*cos(angulo*M_PI/180); //calculando velocidad en x
            Vy0= V*sin(angulo*M_PI/180); //calculando velocidad en y

            x=0.0;
            y=0.0;
            for(t=0;;t++)
            {
                x=Vx0*t;
                y=DisparoO.Yo + Vy0*t -(0.5*g*pow(t,2));

                if(sqrt(pow((DisparoD.Xd-x),2)+pow((DisparoD.Yd-y),2))< DisparoO.rd)
                {
                    if(y<0) y=0;
                    ImprimirImpacto(angulo,V,x,y,t);
                    c=c+1;
                    V=V+10;
                    break;
                }
                if (y<0){
                    break;
                }
            }
            if(c==3)           
            break;
        }
        if(c==3)
        break;
    }
}

int SegundoCasoDisparo(dO DisparoO,dD DisparoD)
{
    srand(time(NULL));
    int V0=0;
    V0=rand() %150+1;
    float x,y;
    float Vx0,Vy0;
    int t=0;
    int angulo;
    int V=V0;
    int c=0;
    for (V=V0; ;V+=5)
    {
         for(angulo=0;angulo <90;angulo++)
        {

            Vx0= -V*cos((angulo)*M_PI/180); //calculando velocidad en x
            Vy0= V*sin((angulo)*M_PI/180); //calculando velocidad en y

            x=0.0;
            y=0.0;
            for(t=0;;t++)
            {
                x=DisparoD.Xd+Vx0*t;
                y=DisparoD.Yd + Vy0*t -(0.5*g*pow(t,2));


                if(sqrt(pow((DisparoO.Xo-x),2)+pow((DisparoO.Yo-y),2))< DisparoD.rd)
                {
                    if(y<0) y=0;
                    ImprimirImpacto(angulo,V,x,y,t);
                    c=c+1;
                    V=V+10;
                    break;
                }
                if (y<0){
                    break;
                }
            }
            if(c==3)
            break;
        }
        if(c==3)
        break;
    }
}


int TercerCasoDisparo(dO DisparoO,dD DisparoD)
{
    bool Impacta=false;
    srand(time(NULL));
    int V0=0;
    V0=rand() %100+1;
    float x,y,x1,y1,y2,x2;
    float Vx0,Vy0,Vx02,Vy02;
    int t=0;
    int angulo;
    int V=V0;
    int c=0;
    for (V=V0; ;V+=5)
    {
        for(angulo=0;angulo <90;angulo++)
        {
            Vx0= V*cos(angulo*M_PI/180); //calculando velocidad en x
            Vy0= V*sin(angulo*M_PI/180); //calculando velocidad en y

            x=0.0;
            y=0.0;
            for(t=0;;t++)
            {
                Impacta=false;
                x=Vx0*t;
                y=DisparoO.Yo + Vy0*t -(0.5*g*pow(t,2));

                if(sqrt(pow((DisparoD.Xd-x),2)+pow((DisparoD.Yd-y),2))< DisparoO.rd)
                {
                    if(y<0) y=0;
                    //ImprimirImpacto(angulo,V,x,y,t);
                    Impacta=true;
                    c=c+1;
                    V=V+10;
                    break;
                }
                if (y<0){
                    break;
                }
            }
            if (Impacta)
            {
                for(int angulo2=0;(angulo2 <90);angulo2++)
                {
                Vx02= V*cos(angulo2*M_PI/180);
                Vy02= V*sin(angulo2*M_PI/180);
                    for(t=0;;t++)
                        {
                            x1=Vx0*(t+2);
                            y1=DisparoO.Yo + Vy0*(t+2) -(0.5*g*pow((t+2),2));
                            x2=DisparoD.Xd-Vx02*t;
                            y2=DisparoD.Yd + Vy02*t -(0.5*g*pow(t,2));
                            if(sqrt(pow((x1-x2),2)+pow((y1-y2),2))< DisparoO.trd)
                            {
                                if(y<0) {y=0;}
                                cout<<"Ofensa"<<endl;
                                ImprimirImpacto(angulo,V,x1,y1,t);
                                cout<<"Defensa"<<endl;
                                ImprimirImpacto(angulo2,V,x2,y2,t);
                                V=V+50;
                                Impacta=false;
                                break;
                            }
                                if (y2<0){
                                    break;
                                }

                        }
                }

            }

            if(c==3)
            break;
        }



        if(c==3)
        break;
    }
}


int CuartoCasoDisparo(dO DisparoO,dD DisparoD)
{
    {
        bool Impacta=false;
        srand(time(NULL));
        int V0=0;
        V0=rand() %100+1;
        float x,y,x1,y1,y2,x2;
        float Vx0,Vy0,Vx02,Vy02;
        int t=0;
        int angulo;
        int V=V0;
        int c=0;
        for (V=V0; ;V+=5)
        {
            for(angulo=0;angulo <90;angulo++)
            {
                Vx0= V*cos(angulo*M_PI/180); //calculando velocidad en x
                Vy0= V*sin(angulo*M_PI/180); //calculando velocidad en y

                x=0.0;
                y=0.0;
                for(t=0;;t++)
                {
                    Impacta=false;
                    x=Vx0*t;
                    y=DisparoO.Yo + Vy0*t -(0.5*g*pow(t,2));

                    if(sqrt(pow((DisparoD.Xd-x),2)+pow((DisparoD.Yd-y),2))< DisparoO.rd)
                    {
                        if(y<0) y=0;
                        //ImprimirImpacto(angulo,V,x,y,t);
                        Impacta=true;
                        c=c+1;
                        V=V+10;
                        break;
                    }
                    if (y<0){
                        break;
                    }
                }
                if (Impacta)
                {
                    for(int angulo2=0;(angulo2 <90);angulo2++)
                    {
                    Vx02= V*cos(angulo2*M_PI/180);
                    Vy02= V*sin(angulo2*M_PI/180);
                        for(t=0;;t++)
                            {
                                x1=Vx0*(t+2);
                                y1=DisparoO.Yo + Vy0*(t+2) -(0.5*g*pow((t+2),2));
                                x2=DisparoD.Xd-Vx02*t;
                                y2=DisparoD.Yd + Vy02*t -(0.5*g*pow(t,2));

                                if(sqrt(pow((DisparoO.Xo-x2),2)+pow((DisparoO.Yo-y2),2))> DisparoD.rd)
                                {

                                if(sqrt(pow((x1-x2),2)+pow((y1-y2),2))< DisparoO.trd)
                                {
                                    if(y<0) {y=0;}
                                    ImprimirImpacto(angulo,V,x1,y1,t);
                                    ImprimirImpacto(angulo2,V,x2,y2,t);
                                    V=V+50;
                                    Impacta=false;

                                    break;
                                }
                                }
                                    if (y2<0){
                                        break;
                                    }

                            }
                    }

                }

                if(c==3)
                break;
            }



            if(c==3)
            break;
        }
    }

}

int QuintoCasoDisparo(dO DisparoO,dD DisparoD)
{
    {
        bool Impacta=false;
        srand(time(NULL));
        int V0=0;
        V0=rand() %100+1;
        float x,y,x1,y1,y2,x2;
        float Vx0,Vy0,Vx02,Vy02;
        int t=0;
        int angulo;
        int V=V0;
        int c=0;
        for (V=V0; ;V+=5)
        {
            for(angulo=0;angulo <90;angulo++)
            {
                Vx0= V*cos(angulo*M_PI/180); //calculando velocidad en x
                Vy0= V*sin(angulo*M_PI/180); //calculando velocidad en y

                x=0.0;
                y=0.0;
                for(t=0;;t++)
                {
                    Impacta=false;
                    x=Vx0*t;
                    y=DisparoO.Yo + Vy0*t -(0.5*g*pow(t,2));

                    if(sqrt(pow((DisparoD.Xd-x),2)+pow((DisparoD.Yd-y),2))< DisparoO.rd)
                    {
                        if(y<0) y=0;
                        //ImprimirImpacto(angulo,V,x,y,t);
                        Impacta=true;
                        c=c+1;
                        V=V+10;
                        break;
                    }
                    if (y<0){
                        break;
                    }
                }
                if (Impacta)
                {
                    for(int angulo2=0;(angulo2 <90);angulo2++)
                    {
                    Vx02= V*cos(angulo2*M_PI/180);
                    Vy02= V*sin(angulo2*M_PI/180);
                        for(t=0;;t++)
                            {
                                x1=Vx0*(t+2);
                                y1=DisparoO.Yo + Vy0*(t+2) -(0.5*g*pow((t+2),2));
                                x2=DisparoD.Xd-Vx02*t;
                                y2=DisparoD.Yd + Vy02*t -(0.5*g*pow(t,2));
                                if(sqrt(pow((x1-x2),2)+pow((y1-y2),2))< DisparoO.trd)
                                {
                                    if(y<0) {y=0;}
                                    cout<<"Ofensa"<<endl;
                                    ImprimirImpacto(angulo,V,x1,y1,t);
                                    cout<<"Defensa"<<endl;
                                    ImprimirImpacto(angulo2,V,x2,y2,t);
                                    V=V+50;
                                    Impacta=false;
                                    ImpactaD=true;
                                    break;
                                }
                                    if (y2<0){
                                        break;
                                    }

                            }
                        if(ImpactaD)
                        {
                        for(int angulo3=0;(angulo3 <90);angulo3++)
                        {
                            Vx03= V*cos(angulo3*M_PI/180);
                            Vy03= V*sin(angulo3*M_PI/180);
                            for(t=0;;t++)
                            {
                                x2=DisparoD.Xd-Vx02*(t+1);
                                y2=DisparoD.Yd + Vy02*(t+1) -(0.5*g*pow((t+1),2));
                                x3=Vx03*t;
                                y3=DisparoO.Yo + Vy03*t+ -(0.5*g*pow(t+,2));
                                if(sqrt(pow((x2-x3),2)+pow((y2-y3),2))< DisparoO.Municion_especial)
                                {
                                    if (y<0) {y=0}
                                    cout<<"Municion especial de la ofensa"<<endl;
                                    ImprimirImpacto(angulo3,V,X3,Y3,t);
                                    cout<<"Defensa"<<endl;
                                    ImprimirImpacto(angulo3,V,x2,y2,t);
                                }
                            }
                        }


                        }

                    }

                }

                if(c==3)
                break;
            }



            if(c==3)
            break;
        }
    }

}


int main()
{
    cout<<"Cual caso va a emular 1-2-3-4-5"<<endl;
    int op=0;
    cin>>op;
    switch (op)
    {
    case 1:
    {
        dO DisparoO;
        dD DisparoD;
        Posicion_de_canon(DisparoD.Xd,DisparoD.Yd,DisparoD.estado);
        Posicion_de_canon(DisparoO.Xo,DisparoO.Yo,DisparoO.estado);
        PrimercasoDisparo(DisparoO,DisparoD);
        break;
    }
    case 2:
    {
        dO DisparoO;
        dD DisparoD;
        Posicion_de_canon(DisparoD.Xd,DisparoD.Yd,DisparoD.estado);
        Posicion_de_canon(DisparoO.Xo,DisparoO.Yo,DisparoO.estado);
        SegundoCasoDisparo(DisparoO,DisparoD);
        break;

    }
    case 3:
    {
        dO DisparoO;
        dD DisparoD;
        Posicion_de_canon(DisparoD.Xd,DisparoD.Yd,DisparoD.estado);
        Posicion_de_canon(DisparoO.Xo,DisparoO.Yo,DisparoO.estado);
        TercerCasoDisparo(DisparoO,DisparoD);
    }
    case 4:
{
    dO DisparoO;
    dD DisparoD;
    Posicion_de_canon(DisparoD.Xd,DisparoD.Yd,DisparoD.estado);
    Posicion_de_canon(DisparoO.Xo,DisparoO.Yo,DisparoO.estado);
    CuartoCasoDisparo(DisparoO,DisparoD);
    }
    case 5:
    {
        dO DisparoO;
        dD DisparoD;
        Posicion_de_canon(DisparoD.Xd,DisparoD.Yd,DisparoD.estado);
        Posicion_de_canon(DisparoO.Xo,DisparoO.Yo,DisparoO.estado);
        QuintoCasoDisparo(DisparoO,DisparoD);
    }



        break;

    }





    return 0;
}

