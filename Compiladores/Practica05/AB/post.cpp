#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;
//Variables Globales
stack<int> pila; 
char preanalisis;
//Declaracion de funciones
bool esDigito(char);
bool esSigno(char);

char getCaracter(string &buffer){
  char c;
  string aux = "";
  c = buffer[0];
  for(auto i=1;i<(int)buffer.size(); i++){
    aux += buffer[i];
  }
  buffer = aux;
  return c;
}

//EJEMPLO = "12 12 + 15 * ";
//MAIN
void inTOpost(string buffer)
{
  //int i= 0;
  while (true) {
    preanalisis = getCaracter(buffer);
    if (esDigito(preanalisis)){
      string aux="";
      while (esDigito(preanalisis)) {
        aux += preanalisis;
        preanalisis = getCaracter(buffer);
      }
      pila.push(stoi(aux));
    }
    else if (esSigno(preanalisis)) {
      if (preanalisis == '+') {
        int n1,n2;
        n1 = pila.top();
        pila.pop();
        n2 = pila.top();
        pila.pop();
        pila.push(n1+n2);
      }
      else if (preanalisis == '-') {
        int n1,n2;
        n1 = pila.top();
        pila.pop();
        n2 = pila.top();
        pila.pop();
        pila.push(n2-n1);
      }
      else if (preanalisis == '*') {
        int n1,n2;
        n1 = pila.top();
        pila.pop();
        n2 = pila.top();
        pila.pop();
        pila.push(n1*n2);
      }
      else if (preanalisis == '/') {
        int n1,n2;
        n1 = pila.top();
        pila.pop();
        n2 = pila.top();
        pila.pop();
        pila.push(n2/n1);
      }
      preanalisis = getCaracter(buffer);
    }
    else {
      break;
    }
  }

  cout<<" El resultado es: "<<pila.top()<<endl<<endl;
}

bool esDigito(char c){
  if (c == '0')
    return true; 
  else if (c == '1')
    return true; 
  else if (c == '2')
    return true; 
  else if (c == '3')
    return true; 
  else if (c == '4')
    return true; 
  else if (c == '5')
    return true; 
  else if (c == '6')
    return true; 
  else if (c == '7')
    return true; 
  else if (c == '8')
    return true; 
  else if (c == '9')
    return true; 
  else
    return false; 
}
bool esSigno(char c){
  if (c == '+')
    return true; 
  else if (c == '-')
    return true; 
  else if (c == '*')
    return true; 
  else if (c == '/')
    return true; 
  else
    return false; 
}
