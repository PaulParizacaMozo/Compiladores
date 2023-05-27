#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAS '+'
#define MENOS '-'
#define POR '*'
#define DIV '/'
#define PUNTOYCOMA ';'
#define COMA ','
#define PARI '('
#define PARD ')'
#define CORI '['
#define CORD ']'
#define LLAVEI '{'
#define LLAVED '}'
//Identificador y Numero
#define ID 256
#define NUM 257
//op
#define MAYOR '>'
#define MENOR '<'
#define IGUAL '='
//OperadoresCombinados
#define MAYORIGUAL 258
#define MENORIGUAL 259
#define SON_IGUAL 260
#define NO_IGUAL 261
//Comentarios
#define COMENTARIO_LINEAL 262
#define COMENTARIO_BLOQUE 263
//Palabras reservadas
#define WHILE 300 
#define IF 301 
#define FOR 302 
#define ELSE 303 
#define CHAR 304 
#define INT 305
#define DOUBLE 306
#define FLOAT 307
#define STRING 308 
#define TRY 309
#define CATCH 310
#define BOOL 311
#define CLASS 312
#define STRUCT 313
#define PUBLIC 314
#define PRIVATE 315
#define PROTECTED 316
#define VOID 317

int scaner();
void mostrar(int);
int espalres();
FILE *f;

char lexema[80];
char comentario[80];
int main(int n, char *pal[])
{
  int token;
  f=stdin; //entrada estandar del teclado
  if(n==2) //si se especifico un archivo de lectura
  {
  f=fopen(pal[1],"rt"); //lectura modo texto
  if(f==NULL)
    f=stdin;
  }
  if(f==stdin) //la lectura sera desde la entrada estandar
   printf("Ingrese texto:  \n");
  while(1)
  {
  token=scaner();
  if(token==EOF) break;
  mostrar(token);
  //comentario[0]=0;
  }
  if(f !=stdin) // si la entrada fue de un archivo
  fclose(f);
}//fin del main
int scaner()
{
  int c;
  int i;
  do c=fgetc(f); while(isspace(c)); //ignora blancos
  if(c==EOF) return EOF;
  if(isalpha(c)){ //regla del ID  
    i=0;
    do{
      lexema[i++]=c;
      c=fgetc(f);
    } while(isalnum(c)||c=='_');
    lexema[i]=0;
    ungetc(c,f); //se devuelve c al flujo de entrada
    i=espalres(); // verifica si es palabra reservada
    if(i>=0)
     return i;
    return ID; // se trata de un ID
  }
  if(isdigit(c)) //regla del NUM
  {
    i=0;
    do{
      lexema[i++]=c;
      c=fgetc(f);
    }while(isdigit(c));
    lexema[i]=0;
    ungetc(c,f);
    return NUM;
  }
   //regla de ;,,,(,),{,},[,]
  if((c==';')||(c==',')||(c=='(')||(c==')')||(c=='[')||(c==']')||(c=='{')||(c=='}')) return c;
  
  //Operadores
  if((c=='+')||(c=='-')||(c=='*')) return c;
  if(c=='>'){//regla de ">" o ">="
    c=fgetc(f);
    if(c=='='){//return MAYORIGUAL
      lexema[0]='>'; lexema[1]='='; lexema[2]=0;
      return MAYORIGUAL;
    }
    ungetc(c,f);
    return MAYOR; //return MAYOR
  }
  if(c=='<'){//regla de "<" o "<="
    c=fgetc(f);
    if(c=='='){//return MENORIGUAL
      lexema[0]='<'; lexema[1]='='; lexema[2]=0;
      return MENORIGUAL;
    }
    ungetc(c,f);
    return MENOR; //return MENOR 
  }
  if(c=='='){//regla de "=" o "=="
    c=fgetc(f);
    if(c=='='){//return COMPARACION 
      lexema[0]='='; lexema[1]='='; lexema[2]=0;
      return SON_IGUAL;
    }
    ungetc(c,f);
    return IGUAL; //return IGUAL
  }
  if(c=='!'){//regla de "!="
    c=fgetc(f);
    if(c=='='){//return NO_IGUAL 
      lexema[0]='!'; lexema[1]='='; lexema[2]=0;
      return NO_IGUAL;
    }
    ungetc(c,f);
  }

  if(c=='/'){//regla de "//"
    c=fgetc(f);
    if(c=='/'){//return COMENTARIO_LINEAL 
      lexema[0]='/'; lexema[1]='/'; lexema[2]=0;
      int indice = 0;
      while(true){
        c=fgetc(f);
        comentario[indice]=c;
        indice++;
        if(c=='\n'){
          comentario[indice]=0;
          break;
        }
      }
      return COMENTARIO_LINEAL;
    }
    if(c=='*'){//return COMENTARIO_BLOQUE 
      lexema[0]='/'; lexema[1]='*'; lexema[2]='*';lexema[3]='/';lexema[4]=0;
      int indice = 0;
      while (true) {
        c=fgetc(f);
        if (c!='*') {
          comentario[indice]=c;
          indice++;
        }
        if(c=='*'){
          c=fgetc(f);
          if(c=='/'){
            comentario[indice]=0;
            break;
          }
        }
      } 
      return COMENTARIO_BLOQUE;
    }
    ungetc(c,f);
    return DIV; //return  DIV 
  }
  return 0; //me
}//fin de scaner

int espalres(){
  if(strcmp(lexema,"while")==0) return WHILE;
  if(strcmp(lexema,"if")==0) return IF;
  if(strcmp(lexema,"for")==0) return FOR;
  if(strcmp(lexema,"else")==0) return ELSE ;
  if(strcmp(lexema,"char")==0) return CHAR;
  if(strcmp(lexema,"int")==0) return INT;
  if(strcmp(lexema,"double")==0) return DOUBLE;
  if(strcmp(lexema,"float")==0) return FLOAT;
  if(strcmp(lexema,"string")==0) return STRING;
  if(strcmp(lexema,"try")==0) return TRY;
  if(strcmp(lexema,"catch")==0) return CATCH;
  if(strcmp(lexema,"bool")==0) return BOOL;
  if(strcmp(lexema,"class")==0) return CLASS;
  if(strcmp(lexema,"struct")==0) return STRUCT;
  if(strcmp(lexema,"public")==0) return PUBLIC;
  if(strcmp(lexema,"private")==0) return PRIVATE;
  if(strcmp(lexema,"protected")==0) return PROTECTED;
  if(strcmp(lexema,"void")==0) return VOID;
  return -1;
}

void mostrar(int token){
  switch(token)
  {
  //Identificador y num 
  case ID: printf("-> token = ID [%s] \n",lexema); break;
  case NUM: printf("-> token = NUM [%s] \n",lexema); break;
  //Operadores
  case MAS: printf("-> token = MAS [%c] \n",token); break;
  case MENOS: printf("-> token = MENOS [%c] \n",token); break;
  case POR: printf("-> token = POR [%c] \n",token); break;
  case DIV: printf("-> token = DIV [%c] \n",token); break;
  //Comentarios
  case COMENTARIO_LINEAL: printf("-> token = COMENTARIO_LINEAL [%s] Contenido del Comentario -> %s\n",lexema,comentario); break;
  case COMENTARIO_BLOQUE: printf("-> token = COMENTARIO_BLOQUE [%s] Contenido del Comentario -> %s\n",lexema,comentario); break;
  //Operadores de comparacion
  case MAYORIGUAL: printf("-> token = MAYORIGUAL [%s]\n",lexema); break;
  case MENORIGUAL: printf("-> token = MENORIGUAL [%s]\n",lexema); break;
  case SON_IGUAL: printf("-> token = SON_IGUAL [%s]\n",lexema); break;
  case NO_IGUAL: printf("-> token = NO_IGUAL [%s]\n",lexema); break;
  case MAYOR: printf("-> token = MAYOR [%c] \n",token); break;
  case MENOR: printf("-> token = MENOR [%c] \n",token); break;
  case IGUAL: printf("-> token = ASIGNACION [%c] \n",token); break;
  //Palabras reservadas
  case WHILE: printf("-> token = WHILE [%s] \n",lexema); break;
  case IF: printf("-> token = IF [%s] \n",lexema); break;
  case FOR: printf("-> token = FOR [%s] \n",lexema); break;
  case ELSE: printf("-> token = ELSE [%s] \n",lexema); break;
  case CHAR: printf("-> token = CHAR [%s] \n",lexema); break;
  case INT: printf("-> token = INT [%s] \n",lexema); break;
  case DOUBLE: printf("-> token = DOUBLE [%s] \n",lexema); break;
  case FLOAT: printf("-> token = FLOAT [%s] \n",lexema); break;
  case STRING: printf("-> token = STRING [%s] \n",lexema); break;
  case TRY: printf("-> token = TRY [%s] \n",lexema); break;
  case CATCH: printf("-> token = CATCH [%s] \n",lexema); break;
  case BOOL: printf("-> token = BOOL [%s] \n",lexema); break;
  case CLASS: printf("-> token = CLASS [%s] \n",lexema); break;
  case STRUCT: printf("-> token = STRUCT [%s] \n",lexema); break;
  case PUBLIC: printf("-> token = PUBLIC [%s] \n",lexema); break;
  case PRIVATE: printf("-> token = PRIVATE [%s] \n",lexema); break;
  case PROTECTED: printf("-> token = PROTECTED [%s] \n",lexema); break;
  //Simbolos
  case VOID: printf("-> token = VOID [%s] \n",lexema); break;
  case PARI: printf("-> token = PARI [%c] \n",token); break;
  case PARD: printf("-> token = PARD [%c] \n",token); break;
  case CORI: printf("-> token = CORI [%c] \n",token); break;
  case CORD: printf("-> token = CORD [%c] \n",token); break;
  case LLAVEI: printf("-> token = LLAVEI [%c] \n",token); break;
  case LLAVED: printf("-> token = LLAVED [%c] \n",token); break;
  case PUNTOYCOMA: printf("-> token = PUNTOYCOMA [%c]\n",token); break;
  case COMA: printf("-> token = COMA [%c]\n",token); break;
  }
}
