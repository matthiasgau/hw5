#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>


using namespace std;

void Eulerback(double*,const int, const double);
void Eulerforward(double*, const int, const double);

int main(){
  const int n= 100; //step size
  const double pi= M_PI;
  const double dt= pi/n;
  const int N=20*n;
  double x[2*N]; //e.g. for forward
  double y[2*N]; //e.g. for backwards
  x[0]=1;
  x[N]=0;
  y[0]=1; //boundary conditions
  y[N]=0; 
  
  Eulerback(x,N,dt);
  Eulerforward(y,N,dt);
  
 
  ofstream out("Euler_back.txt");
  for(int i=0;i<N;i++){
    out << i*dt << "\t"<< x[i] << "\t" << x[N+i] <<endl;
  }
  out.close();
   ofstream peter("Euler_forward.txt");
   for(int i=0;i<N;i++){
     peter << i*dt << "\t"<< y[i] << "\t" << y[N+i] <<endl;
   }
   peter.close();
     
  
  
  
  return 0;
}

void Eulerback(double* p, const int N, const double dt){
  for(int i=0;i<N-1;i++){
    p[i+1]=(p[i]+p[N+i]*dt)/(1+dt*dt);
    p[N+i+1]=(p[N+i]-p[i]*dt)/(1+dt*dt);
  }
}
void Eulerforward(double* p, const int N, const double dt){
  for(int i=0;i<N-1;i++){
    p[i+1]=p[i]+dt*p[N+i];
    p[N+i+1]=p[N+i]-dt*p[i];
  }
}

