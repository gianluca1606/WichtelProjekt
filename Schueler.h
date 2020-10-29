#ifndef SCHUELER_H
#define SCHUELER_H
#include <string>

 class Schueler
       {
             
              std::string Name;
              std::string present;

              public:
              void GetData();           //Statement 1 : Defining GetData()
               void PutData(); 
               void GetName();     
              std::string GetPresent();     

       };
#endif 