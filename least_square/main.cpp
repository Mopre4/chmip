#include "fstream"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(){
  vector<double>x;
  vector<double>y;
  double ch;
  int n;
  double CX, CXX, CY, CXY, A, B, D;

  ifstream fin("input.txt");

  if (fin.is_open()) {  
	  fin >> n;
	  for (int i = 0; i < n; i++) {
		  fin >> ch;
		  x.push_back(ch);
	  }
	  for (int i = 0; i < n; i++) {
		  fin >> ch;
		  y.push_back(ch);
	  }
  }
  else { cout << "file didn't open" << endl; return 1; }
  fin.close();

  cout << "================================================================" << endl;
  cout << "X: ";
  for (auto& item : x) {
	  cout << item << " ";
  }
  cout << endl;
  cout << "================================================================" << endl;

  cout << "================================================================" << endl;
  cout << "Y: ";
  for (auto& item : y) {
	  cout << item << " ";
  }
  cout << endl;
  cout << "================================================================" << endl;


  CX = 0;
  for (int i = 0; i < n; i++) {
	  CX = CX + x[i];
  }

  CXX = 0;
  for (int i = 0; i < n; i++) {
	  CXX = CXX + (pow(x[i],2));
  }
  CY = 0;
  for (int i = 0; i < n; i++) {
	  CY = CY + y[i];
  }
  CXY = 0;
  
  for (int i = 0; i < n; i++) {
	  CXY = CXY + x[i]*y[i];
  }

  cout << "CX = " << CX << endl;
  cout << "CXX = " << CXX << endl;
  cout << "CY = " << CY << endl;
  cout << "CXY = " << CXY << endl;

  D = (n) * CXX - CX * CX; A = ((n) * CXY - CX * CY) / D;
  B = (CXX * CY - CX * CXY) / D;
  cout << "---------------------------------------------------------------" << endl;
  cout << "A = " << A << " B = " << B << endl;
  cout << "---------------------------------------------------------------" << endl;
  return 0;

}

