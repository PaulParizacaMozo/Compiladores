#include "stdio.h"
#include <ctype.h>
#include <iostream>
#include "post.cpp"
using namespace std;
#define MAS '+'
#define MENOS '-'
#define MULT '*'
#define DIV '/'
#define NUM 256
#define FIN -1

char lexema[40];
int tok;
bool salir = false;

std::string buffer="";

void parea(int);
void error();
void Resto();
void Term();
void coma();
int scanner();

void Exp(){
    if(tok==NUM){
        Term();
        Resto();
        coma();
    } else {
        error();
    }
}

void Resto(){
    if(tok==MAS){
        parea(MAS);
        Term();
        //printf("+ ");
        buffer += "+ ";
        Resto();
    } else if (tok==MENOS) {
        parea(MENOS);
        Term();
        //printf("- ");
        buffer += "- ";
        Resto();
    } else if(tok==MULT){
        parea(MULT);
        Term();
        //printf("* ");
        buffer += "* ";
        Resto();
    } else if (tok==DIV) {
        parea(DIV);
        Term();
        //printf("/ ");
        buffer += "/ ";
        Resto();
    }
    else;
}


void Term(){
    if(tok==NUM){
        //printf("%s ",lexema);
        buffer += lexema;
        buffer += " ";
        parea(NUM);
    } else {
        error();
    }
}

void coma(){
    if(tok==';'){
        //printf("%s ",lexema);
        parea(';');
    } else {
        error();
    }
}
void parea(int t){
  if (tok == t)
    tok = scanner(); 
  else
    error();
}

void error(){   
  printf("Error de sintaxis.");
  salir = true;
}

int scanner(){
    int c, i;
    do 
        c = getchar(); 
    while(c==' ');

    if(c=='\n')
        return FIN;

    if(c==MAS || c==MENOS || c==MULT || c==DIV || c==';')
        return c;
    if(isdigit(c)){
        i=0;
        do{ 
            lexema[i++] = c; 
            c = getchar(); 
        } while (isdigit(c));
        
        lexema[i] = 0;
        ungetc(c,stdin);
        //getchar();
        return NUM;
    }
    return 0;
}

int main(){

    cout<<"Forma Infija -> ";
    tok = scanner();
    Exp();
    if(!salir){
      cout<<"\nForma PostFija -> "<<buffer<<endl;
      inTOpost(buffer);
    }
}
