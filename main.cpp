#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <fstream>
#include "Schueler.h"
#include "Hungarian.hpp"
#include "Wuensche.h"


using namespace std;

// clang-format on

Hungarian::Result runMunkres(const Hungarian::Matrix& cost) {
  Hungarian::Result r = Hungarian::Solve(cost, Hungarian::MODE_MINIMIZE_COST);

  /*cerr << "cost-matrix:";
  Hungarian::PrintMatrix(r.cost);*/

  if (!r.success) {
    cerr << "Failed to find solution :(" << endl;

  }

  /*cerr << "assignment:";
  Hungarian::PrintMatrix(r.assignment);*/

  
  return r;
}

int largestInCol(int **mat, int col, int rows) {
 int max_col_element = mat[0][col];

   for (int j = 1; j < rows; j++) {
      if (mat[j][col] > max_col_element)
         max_col_element = mat[j][col];
   }
   return max_col_element;
   }


int option1() {
int i = 0;
int preference = 0;
  int AnzahlSchueler = 0;
  cout << "\n Bitte geben Sie ein wie viele Schüler in der Klasse sind. ";
  cin >> AnzahlSchueler;

Hungarian::Result Test;


 

  // dynamic allocation
  int** ungarianMatrix = new int*[AnzahlSchueler];
  for(int i = 0; i < AnzahlSchueler; ++i)
      ungarianMatrix[i] = new int[AnzahlSchueler];
 


  int max[AnzahlSchueler];
  Schueler Schueler[AnzahlSchueler];
  Wuensche Wuensche[AnzahlSchueler];

  for (i = 0; i < AnzahlSchueler; i++) {
    cout << "\n Schüler Nr. " << i + 1;
    Schueler[i].GetData();
  }

  cout << "\nDetails zu den Schülern";
  for (i = 0; i < AnzahlSchueler; i++) {
    Schueler[i].PutData();
  }

  for (i = 0; i < AnzahlSchueler; i++) {
    cout << "\n Bitte geben sie die wünsche für den folgenden Schüler ein: ";
    Schueler[i].GetName();

    Wuensche[i].setwuensche();
  }

  for (i = 0; i < AnzahlSchueler; i++) {
    Schueler[i].GetName();
    cout << " hat folgende Wünsche: " << Wuensche[i].getwunsch1() + ", " << Wuensche[i].getwunsch2() << ", " << Wuensche[i].getwunsch3() << endl;
  }

    

     /*
    Array mit 0 Werten Initialisieren
    */
for (int i = 0; i < AnzahlSchueler; i++) {
    for (int j = 0; j < AnzahlSchueler; j++) {
      ungarianMatrix[i][j] = 0;
    }
  }

    cout << "\n Two Dimensional Array is : \n";
  for (int i = 0; i < AnzahlSchueler; i++) {
    for (int j = 0; j < AnzahlSchueler; j++) {
      cout << " " << ungarianMatrix[i][j] << " ";
    }
    cout << "\n";
  }


    /*
    Gewichtung wird jetzt vorgenommen, wenn man mehrmals die gleichen Geschenke hat dann folgt die Gewichtung aufeinander...
    */

  for (i = 0; i < AnzahlSchueler; i++) {
    for (int x = 0; x < AnzahlSchueler; x++) {
      if (Wuensche[i].getwunsch1() == Schueler[x].GetPresent())
       {
        preference += 1;
        ungarianMatrix[x][i] = preference;
      }
    }

    for (int x = 0; x < AnzahlSchueler; x++) {
      if (Wuensche[i].getwunsch2() == Schueler[x].GetPresent())
       {
        preference += 1;
        ungarianMatrix[x][i] = preference;
      }
    }

    for (int x = 0; x < AnzahlSchueler; x++) {
      if (Wuensche[i].getwunsch3() == Schueler[x].GetPresent())
       {
        preference += 1;
        ungarianMatrix[x][i] = preference;
      }
    }
    preference = 0;
  }


    /* 
    Restlichen Werte anhand von Maximum füllen
    */
       
for (int i = 0; i < AnzahlSchueler; i++) { 
int maximum = largestInCol(ungarianMatrix, i, AnzahlSchueler);
for (int x = 0; x < AnzahlSchueler; x++) { 
if (ungarianMatrix[x][i] == 0) {
 maximum += 1;
ungarianMatrix[x][i] = maximum;
} 
}
} 





vector< vector<int> > costMatrix ;


for (int i = 0; i < AnzahlSchueler; i++){        //creating row
        costMatrix.push_back(vector<int>());
    }

    for (int n = 0; n < AnzahlSchueler; n++){        //creating columns for the rows
        for (int m = 0; m < AnzahlSchueler; m++){    
            costMatrix[m].push_back(0);
        }
    }
    for (int m = 0; m < AnzahlSchueler; m++){        //storing and printing data
        for (int n = 0; n < AnzahlSchueler; n++){
        //  vec[n].push_back(arr[m][n]);
            costMatrix[m][n] = ungarianMatrix[m][n];
            cout << costMatrix[n][m];
        }
    }


const Hungarian::Matrix EXAMPLE1 = costMatrix ;


  Test = runMunkres(EXAMPLE1);

   


   for (int i = 0; i < AnzahlSchueler; i++){
      Schueler[i].GetName(); 
      cout << " bekommt :";
  for (int n = 0; n < AnzahlSchueler; n++){
if(Test.assignment[n][i] == 1) {
 cout << Schueler[n].GetPresent() <<endl;
 }
}
        }
  cerr << "--------------------" << endl;


// deallocate memory using delete[] operator
	for (int i = 0; i < AnzahlSchueler; i++)
		delete[] ungarianMatrix[i];

	delete[] ungarianMatrix;

	return 0;


}



int exit(){

  return 0;
}


int option2(){

vector<vector<int>> costMatrix;
Hungarian::Result Solution;
string ersteZeile;
int anzahlschueler;
int a, b, c;
ifstream stream("wichteln1.txt");
int buffer = 0;
int rest = 4;
 

/* Erste Zeile ermitteln, wo die Anzahl der Schüler steht */
getline(stream, ersteZeile);
anzahlschueler = stoi(ersteZeile); 
/* Vector mit der Anzahl an Spalten und Zeilen(Entspricht die Anzahl an Schülern) initialisieren */
costMatrix.resize(anzahlschueler, vector<int>(anzahlschueler, 0));

    
while (stream >> a >> b >> c)
{
/* cout << a << " " << b << " " << c << endl; 
 Jede Zeile entspricht ein Geschenk und jede Spalte einen Schüler */
    costMatrix[a - 1][buffer] = 1;
    costMatrix[b - 1][buffer] = 2;
    costMatrix[c - 1][buffer] = 3;
    buffer++; 
}


/* restlichen Preferenzen setzen da 1,2,3 schon bekannt, wird direkt mit 4 begonnen */
for (int i = 0; i < anzahlschueler; ++i)
    {
        for (int j = 0; j < anzahlschueler; ++j)
        {
           if (costMatrix[j][i] == 0)
         {costMatrix[j][i] = rest;  
         rest++;  
         }    
        }
        rest = 4;
    }


  Solution = runMunkres(costMatrix);
   

   for (int i = 0; i < anzahlschueler; i++){
      cout << "Schüler Nr. " << i + 1<< " bekommt das ";
  for (int n = 0; n < anzahlschueler; n++){
if(Solution.assignment[n][i] == 1) {
 cout << "Geschenk Nr. " << n + 1<< endl;
 }
}
        }
  cerr << "--------------------" << endl; 




  return 0;
}







int main() {
 
 int option = 0;
 int manuell;
 int automatisch;


 while(option == 0)
 {
cout << "Das Programm hat 2 Möglichkeiten " << endl;
cout << "1. Manuelle Eingabe mit Zuordnung nach der Hungarischen Methode(möglichst fair)" << endl;
cout << "2. Datei per Pfad einlesen" << endl;
cout << "3. Programm Verlassen" << endl;
cout << "Bitte treffen Sie eine Auswahl" << endl;
cin >> option;
} 

switch(option)
{
 case 1: manuell = option1();
 if(manuell == 0){
cout <<"Zuordnung erfolgreich" << endl;
cout <<"Möchten Sie wieder zurück zum Menü ?(0) Alternativ mit (3) das Programm Verlassen." << endl;
cin >> option;
 } 

case 2: automatisch = option2();
if(automatisch == 0){
cout <<"Zuordnung erfolgreich" << endl;
cout <<"Möchten Sie wieder zurück zum Menü ?(0) Alternativ mit (3) das Programm Verlassen." << endl;
cin >> option;
 } 
 case 3: exit();
}


  
};