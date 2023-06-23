#include <cstdio>
#include <iostream>
#include "post.cpp"
using namespace std;


char lexema[40];
char tok;
bool salir = false;

std::string buffer="";
std::string buffer1;

//std::string buffer1="8+12-5+2*2;";

void Resto();
void Term();
void coma();
char scanner();
void error();
void parea(char);
void delSpace();
bool esDigito(char);
bool esSigno(char);

void Exp(){
    delSpace();
    if(esDigito(tok)){
        Term();
        Resto();
        coma();
    } else {
        error();
    }
}

void Resto(){
    delSpace();
    if(tok=='+'){
        parea(tok);
        Term();
        //printf("+");
        buffer += "+ ";
        Resto();
    } else if (tok=='-') {
        parea(tok);
        Term();
        //printf("-");
        buffer += "- ";
        Resto();
    } else if(tok=='*'){
        parea(tok);
        Term();
        //printf("*");
        buffer += "* ";
        Resto();
    } else if (tok=='/') {
        parea(tok);
        Term();
        //printf("/");
        buffer += "/ ";
        Resto();
    }
    else;
}


void Term(){
    delSpace();
    if (esDigito(tok)) {
      while(esDigito(tok)){
          //printf("%s",lexema);
          buffer += tok;
          parea(tok);
      }  
      buffer += " ";
    }
    else{
        error();
    }
}

void coma(){

    delSpace();
    if(tok==';'){
        printf("%s",lexema);
        parea(';');
    } else {
        error();
    }
}

void delSpace(){
  while (tok == ' ') {
    tok = getCaracter(buffer1); 
  }
}

void parea(char t){
  if (tok == t)
    tok = getCaracter(buffer1); 
  else
   error();
}

void error(){   
  printf(" ->Error de sintaxis.\n\n");
  salir = true;
}

char scanner(){
    char c = getCaracter(buffer1);
    int i;
    delSpace();

    if(esSigno(c))
        return c;
    if(esDigito(c)){
        i=0;
        do{ 
            lexema[i++] = c; 
            c = getCaracter(buffer1); 
        } while (esDigito(c));
        
        lexema[i] = 0;
        return c;
    }
    return 0;
}

//int main(){
//    //tok = scanner();
//    tok = getCaracter(buffer1);
//    cout<<tok<<endl;
//    Exp();
//    if(!salir){
//      cout<<"\nBuffer: "<<buffer<<endl;
//      cout<<"postFijo: \n";
//      inTOpost(buffer);
//    }
//
//
//      //cout<<"\nBuffer: "<<buffer<<endl;
//}
