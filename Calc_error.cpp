#include "Calc_error.h"


using namespace std;

void Calc_error::handler() {
	try{
		throw;
	}

	catch(std::runtime_error* exception){
		cout<<" Zlapano wyjatek:"<<endl;
		while(exception){
			cout<<" -- z powodu: "<<exception->what();

			Calc_error *tmp = dynamic_cast<Calc_error*>(exception);
			if(tmp){
				cout<<", [plik = "<<tmp->m_file<<", linia = "<<tmp->m_line<<"]"<<endl;
				exception=tmp->m_previous;
				delete tmp;
			}
			else{
				cout<<endl;
				delete exception;
				exception = NULL;
			}
		}
	}
}
