#include <iostream>
#include <fstream>

int main(){
  std::ifstream infile;
  infile.open("daten.txt");
  std::ofstream outfile("datensumme.txt");
  int a,b;
  while(! infile.eof()){
    infile >> a >> b;
    outfile << a+b << std::endl;
  

  }  

  infile.close();
  outfile.close();
}