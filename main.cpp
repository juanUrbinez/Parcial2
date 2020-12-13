#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

struct dO
{
    float d;
    float Ho;
    float Xo=0;
    float Yo=Ho;
    float rd0=0,05*d;
};

struct dD
{
    float d;
    float Hd;
    float Xd=d;
    float Yd;
    float rdd=0,025d;

};



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
