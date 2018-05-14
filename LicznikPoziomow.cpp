#include "LicznikPoziomow.h"

#include <iostream>

using namespace std;

LicznikPoziomow::LicznikPoziomow() {

    deep++;
    cout<<"Rozpoczynamy poziom numer "<<deep<<"."<<endl;
}

LicznikPoziomow::~LicznikPoziomow() {
    cout<<"Konczymy poziom numer "<<deep<<"."<<endl;
    deep--;

}
