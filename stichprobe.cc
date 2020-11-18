#include<iostream>
#include<fstream>
#include<cmath>

double meanvalue(std::string filename){
  std::ifstream file(filename);
  double mean = 0;
  int N = 0;
  double a;
file >> a ;
  while(! file.eof()){    
    mean = mean + a;
    ++N;
    file >> a ;
  }  
  mean = mean / N ;
  file.close();
  return mean;
}

double variance(std::string filename, double mu){
  std::ifstream file(filename);
  double var = 0;
  int N = 0;
  double a;
file >> a ;
  while(! file.eof()){
    var = var + (a - mu)*(a - mu);
    ++N;
    file >> a ;
  }  
  var = var / N ;
  file.close();
  return var;
}


int main(){
double datenmean = meanvalue("datensumme.txt");
double datenvar = variance("datensumme.txt", datenmean);
std::cout << datenmean << std::endl;
std::cout << datenvar << std::endl;
double datenstd = std::sqrt(datenvar);
std::cout << datenstd << std::endl;

//infile.close();
}
