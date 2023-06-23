#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "in.cpp"
using namespace std;


int main(int argc, char *argv[])
{
  bool ok = false;
  ifstream file;
  string linea;
  string namefile;
  cout<<"Ingrese el nombre del archivo -> ";
  getline(cin,namefile);
  cout<<"Archivo a usar -> "<<namefile<<endl;
  file.open(namefile);
  getline(file,linea);
  if(linea == "INICIO"){
    while (getline(file,linea)) {
      salir = false;
      if (linea == "FIN") {
        ok = true;
        break;
      }
      buffer1 = linea;
      cout<<" Forma infija: "<<linea<<endl;
      tok = getCaracter(buffer1);
      Exp();
      if(!salir){
        cout<<" Forma postfija: "<<buffer<<endl;
        inTOpost(buffer);
      }
      buffer="";
    }
  } 
  if (ok == false) {
    cout<<"Error de sintaxis\n";
  }
  else cout<<"Compilado con exito."<<endl;
  file.close();
  
  return 0;
}

