#include <iostream>
#include <string>
#include "Wuensche.h"


using namespace std;
void Wuensche::setwuensche()
{

           cout<<"\n\tWunsch Nr. 1: ";
         cin>> wunsch1;

          cout<<"\n\t Wunsch Nr. 2: ";
          cin>> wunsch2;

         cout<<"\n\t Wunsch Nr. 3: ";
         cin>> wunsch3;

              }

string Wuensche::getwunsch1() {


return wunsch1;

}
string Wuensche::getwunsch2() {


return wunsch2;
    }

string Wuensche::getwunsch3() {

return wunsch3;

}

