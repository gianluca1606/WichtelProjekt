#ifndef WUENSCHE_H
#define WUENSCHE_H
#include <string>

 class Wuensche
       {
              int SchuelerId;
              std::string wunsch1;
              std::string wunsch2;
              std::string wunsch3;

              public:
              void setwuensche();           //Statement 1 : Defining GetData()
              std::string getwunsch1();
              std::string getwunsch2();
              std::string getwunsch3();
       };
#endif 