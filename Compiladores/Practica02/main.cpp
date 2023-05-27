#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Regla{
  string nActual;
  char simbolo;
  string nSiguiente;
};

class AFD
{
  public:
    string nInicial;
    vector<string>nFinal;
    vector<string>nodos;
    vector<char>alfabeto;
    vector<Regla>rTransicion;
  public:
    AFD (){}
    ~AFD (){}
    void showAFD(){
      cout<<"Nodos: "<<endl;
      for (string c : nodos) {
        cout<<" ->"<<c<<endl; 
      }
      cout<<"Nodo inicial: "<<nInicial<<endl;
      cout<<"Nodo(s) final(es): "<<endl;
      for (string c : nFinal) {
        cout<<" ->"<<c<<endl; 
      }
      cout<<"Simbolos del alfabeto: "<<endl;
      for (char c : alfabeto) {
        cout<<" ->"<<c<<endl; 
      }
      cout<<"Reglas de transicion: "<<endl;
      for(Regla rule: rTransicion){
        cout<<rule.nActual<<" - "<<rule.simbolo<<" - "<<rule.nSiguiente<<endl;
      }
    }

    void generateCode(string nameFile){
      ofstream file;
      file.open(nameFile+".cpp",ios::out);
      file<<"#include <iostream>\n#include <vector>\nusing namespace std;\n";//cabezera
      file<<"string nInicial = \""<<nInicial<<"\";\n";
      file<<"vector<string>nFinal{";
      for(string c:nFinal){
        file<<"\""<<c<<"\""<<",";
      }
      file<<"};\n";
      file<<"vector<char>alfabeto{";
      for (char c:alfabeto){
        file<<"'"<<c<<"'"<<",";
      }
      file<<"};\n";
      file<<"struct Regla{\nstring nActual;\nchar simbolo;\nstring nSiguiente;\n};\n";
      file<<"vector<Regla>rTransicion;\n";
      file<<"void llenarRTransicion(string a,char b,string c){\n  Regla rule;\n  rule.nActual = a;\n  rule.simbolo = b;\n  rule.nSiguiente = c;\n  rTransicion.push_back(rule);\n}\n";
      file<<"bool EsSimbolo(char c){\n  bool es = false;\n  for(char a:alfabeto){\n    if (a == c){\n       return true;\n    }\n  }\n  return es;\n}\n";
      file<<"void reconocerCadena(string cadena){\n  string nodoActual=nInicial;\n  for(char c:cadena){\n  if(!EsSimbolo(c)){\n    cout<<\"La cadena \"<<cadena<<\" no es reconocida por el AFD.\"<<endl;\n    return;\n  }\n  int in=0;\n  int sizeR=rTransicion.size();\n  for(Regla rule : rTransicion){\n    if((rule.nActual == nodoActual)&&(rule.simbolo == c)){\n      nodoActual = rule.nSiguiente;\n      break;\n    }\n    in++;\n    if(in == sizeR){\n      cout<<\"La cadena \"<<cadena<<\" no es reconocida por el AFD.\"<<endl;\n      return;\n    }\n  }\n  }\n  for(string nf : nFinal){\n    if(nf == nodoActual){\n      cout<<\"La cadena \"<<cadena<<\" es reconocida por el AFD.\"<<endl;\n      return;\n    }\n  }\n  cout<<\"La cadena \"<<cadena<<\" no es reconocida por el AFD.\"<<endl;\n}\n";
      file<<"int main(){\n";
      for (Regla rule: rTransicion){
      file<<"llenarRTransicion(";
      file<<"\""<<rule.nActual<<"\",";
      file<<"'"<<rule.simbolo<<"',";
      file<<"\""<<rule.nSiguiente<<"\"";
      file<<");\n";
      }
      file<<"string input;\ncout<<\"Ingrese una cadena -> \";\ngetline(cin,input);\nreconocerCadena(input);\nreturn 0;\n}";
      file.close();
      cout<<"\n->Archivo generado con exito."<<endl;
    }

    //reconocerCadena
    //bool EsSimbolo(char c){
    //  bool es = false;
    //  for(char a:alfabeto){
    //    if (a == c){
    //      return true;
    //    }
    //  }
    //  return es;
    //} 

    //void reconocerCadena(string cadena){
    //  string nodoActual=nInicial;
    //    for(char c:cadena){
    //    if(!EsSimbolo(c)){
    //      cout<<"No es cadena del AFD."<<endl;
    //      return;
    //    }
    //    cout<<nodoActual<<"-";
    //    for(Regla rule : rTransicion){
    //      if((rule.nActual == nodoActual)&&(rule.simbolo == c)){
    //        nodoActual = rule.nSiguiente;
    //        cout<<nodoActual<<"-";
    //        break;
    //      }
    //    }
    //    cout<<endl;
    //  }
    //  cout<<endl;
    //  for(string nf : nFinal){
    //    if(nf == nodoActual){
    //      cout<<"La cadena "<<cadena<<" es reconocida por el AFD."<<endl;
    //      return;
    //    }
    //  }
    //  cout<<"La cadena "<<cadena<<" no es reconocida por el AFD."<<endl;
    //}
    
};

void importFile(string nameFile,AFD & afd){
  ifstream file;
  string linea;
  string word;
  Regla rule;
  file.open(nameFile,ios::in);
  //Nodos
  getline(file,linea);
  stringstream str(linea);
  while(getline(str,word,',')){
    afd.nodos.push_back(word);
  }
  //Nodo inicial
  getline(file,linea);
  afd.nInicial = linea; 
  //Nodos Finales
  getline(file,linea);
  stringstream stream(linea);
  while(getline(stream,word,',')){
    afd.nFinal.push_back(word);
  }
  //Alfabeto
  getline(file,linea);
  stringstream stream1(linea);
  while(getline(stream1,word,',')){
    afd.alfabeto.push_back(word[0]);
  }
  //Reglas de transicion
  while (getline(file,linea)) {
    stringstream stream(linea);
    getline(stream,word,',');
    rule.nActual = word;
    getline(stream,word,',');
    rule.simbolo = word[0];
    getline(stream,word,',');
    rule.nSiguiente = word;
    afd.rTransicion.push_back(rule);
  }
  file.close();
}


int main()
{ 
  string nameFile = "input.txt";
  AFD afd;
  importFile(nameFile,afd);
  afd.showAFD();

  //afd.reconocerCadena("ababbab");

  afd.generateCode("code");

  return 0;
}
