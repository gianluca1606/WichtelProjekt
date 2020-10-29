#include <iostream>
#include "Schueler.h"
#include <string>

using namespace std;
void Schueler::GetData()
{
                    
                    cout<<"\n\tSchüler Name : ";
                    cin>>Name;

                    cout<<"\n\tMitgebrachtes Geschenk eingeben : ";
                    cin>>present;

              }


void Schueler::PutData()           //Statement 2 : Defining PutData()
              {
                    cout<<"\n"<<Name<<"\t"<<present;
              }


void Schueler::GetName()           //Statement 2 : Defining PutData()
              {
                    cout<<Name;
              }

 string Schueler::GetPresent()           //Statement 2 : Defining PutData()
              {
                    return present;
              }             