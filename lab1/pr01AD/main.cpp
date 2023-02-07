#include <iostream>

using namespace std;
struct Interval
{
    double left;
    double right;
} rada[5];
double f(double x)
{
    return x*x*x + 5*x*x - 8*x -40;
}
double eps = 1e-9;
int Separation(double A, double B, double h);
double Bisection(double a, double b, int &k);

int main()
{
    int i, n;
    double A = -6;
    double B = 4;
    double h = 0.05;
    double x;
    cout << "Proiect nr1 elaborat de Adam Denis" << endl;
    n = Separation(A,B,h);
    for(i=0; i<n; i++)
    {
        cout << "O solutie separata se afla pe ["<< rada[i].left << ":" << rada[i].right << "]" << endl;
    }
    return 0;
}

int Separation(double A, double B, double h)
{
    int n = 0;
    double x0, x;
    x0 = A;
    do{
        x = x0 + h;
        //if(f(x)==0)...
        if(f(x0)*f(x) < 0){
            rada[n].left = x0;
            rada[n].right = x;
            n++;
        }
        x0 = x;

    } while(x<B);
    return n;
}
