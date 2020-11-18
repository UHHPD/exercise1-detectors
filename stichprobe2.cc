#include<iostream>
#include<fstream>
#include<cmath>

double meanvalue_nine(std::string filename, std::string outfilename){
  std::ifstream file(filename);
  std::ofstream outfile(outfilename);
  double mean = 0;
  double globalmean = 0;
  int N = 0;
  int globalN = 0;
  double a;
  while(! file.eof()){
    file >> a ;
    mean = mean + a;
    globalmean = globalmean + a;
    ++N;
    ++globalN;
    if(N==9){
      mean = mean / N ;
      outfile << mean << std::endl;
      N = 0;
      mean = 0;
    }
  }  
  globalmean = globalmean/globalN;
  file.close();
  return globalmean;
}

double variance_nine(std::string filename, std::string outfilename, std::string meanfilename){
  std::ifstream file(filename);
  std::ifstream meanfile(meanfilename);
  std::ofstream outfile(outfilename);
  double var = 0;
  int N = 0;
  double a;
  double mu;
  meanfile >> mu;
  while(! file.eof()){
    file >> a ;
    var = var + (a - mu)*(a - mu);
    ++N;
    if(N==9){
      var = var /N;
      outfile << var << std::endl;
      N = 0;
      meanfile >> mu;
    }
  }  
  file.close();
}

//infile.close();

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


int main(){
meanvalue_nine("datensumme.txt","mittelwerte.txt");
variance_nine("datensumme.txt","varianzen.txt", "mittelwerte.txt");
//std::cout << "habe fertig" << std::endl;

double meanmean = meanvalue("mittelwerte.txt");
double varmean = meanvalue("varianzen.txt");

//std::cout << meanmean << std::endl;
//std::cout << varmean << std::endl;
double besselvar = varmean *26/25;
//std::cout << besselvar << std::endl;

}

