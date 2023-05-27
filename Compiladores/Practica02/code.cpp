#include <iostream>
#include <vector>
using namespace std;
string nInicial = "q0";
vector<string>nFinal{"q1",};
vector<char>alfabeto{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9',};
struct Regla{
string nActual;
char simbolo;
string nSiguiente;
};
vector<Regla>rTransicion;
void llenarRTransicion(string a,char b,string c){
  Regla rule;
  rule.nActual = a;
  rule.simbolo = b;
  rule.nSiguiente = c;
  rTransicion.push_back(rule);
}
bool EsSimbolo(char c){
  bool es = false;
  for(char a:alfabeto){
    if (a == c){
       return true;
    }
  }
  return es;
}
void reconocerCadena(string cadena){
  string nodoActual=nInicial;
  for(char c:cadena){
  if(!EsSimbolo(c)){
    cout<<"La cadena "<<cadena<<" no es reconocida por el AFD."<<endl;
    return;
  }
  int in=0;
  int sizeR=rTransicion.size();
  for(Regla rule : rTransicion){
    if((rule.nActual == nodoActual)&&(rule.simbolo == c)){
      nodoActual = rule.nSiguiente;
      break;
    }
    in++;
    if(in == sizeR){
      cout<<"La cadena "<<cadena<<" no es reconocida por el AFD."<<endl;
      return;
    }
  }
  }
  for(string nf : nFinal){
    if(nf == nodoActual){
      cout<<"La cadena "<<cadena<<" es reconocida por el AFD."<<endl;
      return;
    }
  }
  cout<<"La cadena "<<cadena<<" no es reconocida por el AFD."<<endl;
}
int main(){
llenarRTransicion("q0",'a',"q1");
llenarRTransicion("q0",'b',"q1");
llenarRTransicion("q0",'c',"q1");
llenarRTransicion("q0",'d',"q1");
llenarRTransicion("q0",'e',"q1");
llenarRTransicion("q0",'f',"q1");
llenarRTransicion("q0",'g',"q1");
llenarRTransicion("q0",'h',"q1");
llenarRTransicion("q0",'i',"q1");
llenarRTransicion("q0",'j',"q1");
llenarRTransicion("q0",'k',"q1");
llenarRTransicion("q0",'l',"q1");
llenarRTransicion("q0",'m',"q1");
llenarRTransicion("q0",'n',"q1");
llenarRTransicion("q0",'o',"q1");
llenarRTransicion("q0",'p',"q1");
llenarRTransicion("q0",'q',"q1");
llenarRTransicion("q0",'r',"q1");
llenarRTransicion("q0",'s',"q1");
llenarRTransicion("q0",'t',"q1");
llenarRTransicion("q0",'u',"q1");
llenarRTransicion("q0",'v',"q1");
llenarRTransicion("q0",'w',"q1");
llenarRTransicion("q0",'x',"q1");
llenarRTransicion("q0",'y',"q1");
llenarRTransicion("q0",'z',"q1");
llenarRTransicion("q1",'a',"q1");
llenarRTransicion("q1",'b',"q1");
llenarRTransicion("q1",'c',"q1");
llenarRTransicion("q1",'d',"q1");
llenarRTransicion("q1",'e',"q1");
llenarRTransicion("q1",'f',"q1");
llenarRTransicion("q1",'g',"q1");
llenarRTransicion("q1",'h',"q1");
llenarRTransicion("q1",'i',"q1");
llenarRTransicion("q1",'j',"q1");
llenarRTransicion("q1",'k',"q1");
llenarRTransicion("q1",'l',"q1");
llenarRTransicion("q1",'m',"q1");
llenarRTransicion("q1",'n',"q1");
llenarRTransicion("q1",'o',"q1");
llenarRTransicion("q1",'p',"q1");
llenarRTransicion("q1",'q',"q1");
llenarRTransicion("q1",'r',"q1");
llenarRTransicion("q1",'s',"q1");
llenarRTransicion("q1",'t',"q1");
llenarRTransicion("q1",'u',"q1");
llenarRTransicion("q1",'v',"q1");
llenarRTransicion("q1",'w',"q1");
llenarRTransicion("q1",'x',"q1");
llenarRTransicion("q1",'y',"q1");
llenarRTransicion("q1",'z',"q1");
llenarRTransicion("q1",'0',"q1");
llenarRTransicion("q1",'1',"q1");
llenarRTransicion("q1",'2',"q1");
llenarRTransicion("q1",'3',"q1");
llenarRTransicion("q1",'4',"q1");
llenarRTransicion("q1",'5',"q1");
llenarRTransicion("q1",'6',"q1");
llenarRTransicion("q1",'7',"q1");
llenarRTransicion("q1",'8',"q1");
llenarRTransicion("q1",'9',"q1");
string input;
cout<<"Ingrese una cadena -> ";
getline(cin,input);
reconocerCadena(input);
return 0;
}