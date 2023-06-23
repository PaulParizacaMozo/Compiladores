%option noyywrap
%{
	#include<stdio.h>
%}

/*DEFINICIONES*/

DIGITO    [0-9]
LETRA     [a-zA-Z]
INICIOLINEAL "//"
INICIOCOM "/*"
FINCOM    "*/"
ESPACIO   " "
ABRIRLLAVE   "{"
CERRARLLAVE   "}"
ABRIRPAR  "("
CERRARPAR   ")"
PUNTOCOMA   ";"

ASIGNACION   "="
MAS       "+"
MENOS     "-"
POR       "*"
DIV       "/"

IGUALDAD  "=="
DIFERENCIA  "!="
MENOR     "<" 
MAYOR     ">" 
MENORIGUAL  "<="
MAYORIGUAL  ">="

IDENTIFICADOR {LETRA}({LETRA}|{DIGITO})*
NUMERO        {DIGITO}+
NUMEROENTERO (-?[1-9]{DIGITO}*)
NUMEROFLOTANTE {NUMEROENTERO}["."][1-9]+
COMENTARIOLINEAL {INICIOLINEAL}({LETRA}|{DIGITO}|{ESPACIO})*
COMENTARIOBLOQUE {INICIOCOM}({LETRA}|{DIGITO}|{ESPACIO})*{FINCOM}

/*REGLAS*/
%%
"main"    { printf("(%s) Palabra reservada: main\n",yytext); }
"if"    { printf("(%s) Palabra reservada: if\n",yytext); }
"while" { printf("(%s) Palabra reservada: while\n",yytext); }
"for"   { printf("(%s) Palabra reservada: for\n",yytext); }
"int"   { printf("(%s) Palabra reservada: int\n",yytext); }
"float" { printf("(%s) Palabra reservada: float\n",yytext); }
"return" { printf("(%s) Palabra reservada: return\n",yytext); }

{PUNTOCOMA} { printf("(%s) Punto y coma: ;\n",yytext); }
{ASIGNACION}  { printf("(%s) Asignacion \n",yytext); }

{MAS} { printf("(%s) Operador aritmético: +\n",yytext); }
{MENOS} { printf("(%s) Operador aritmético: -\n",yytext); }
{POR} { printf("(%s) Operador aritmético: *\n",yytext); }
{DIV} { printf("(%s) Operador aritmético: /\n",yytext); }

{IGUALDAD}  { printf("(%s) Operador de comparación: ==\n",yytext); }
{DIFERENCIA}  { printf("(%s) Operador de comparación: !=\n",yytext); }
{MENOR}   { printf("(%s) Operador de comparación: <\n",yytext); }
{MAYOR}   { printf("(%s) Operador de comparación: >\n",yytext); }
{MENORIGUAL}  { printf("(%s) Operador de comparación: <=\n",yytext); }
{MAYORIGUAL}  { printf("(%s) Operador de comparación: >=\n",yytext); }

{ABRIRPAR}  {printf("(%s) PARI\n",yytext);}
{CERRARPAR}  {printf("(%s) PARD\n",yytext);}
{ABRIRLLAVE}  {printf("(%s) LLAVEI\n",yytext);}
{CERRARLLAVE}  {printf("(%s) LLAVED\n",yytext);}

{IDENTIFICADOR}   {printf("(%s) IDENTIFICADOR\n",yytext);}
{NUMERO}        {printf("(%s) NUMERO ENTERO\n",yytext);}
{NUMEROENTERO}   {printf("(%s) NUMERO ENTERO\n",yytext);}
{NUMEROFLOTANTE}   {printf("(%s) NUMERO FLOTANTE\n",yytext);}
{ESPACIO}         {printf("(%s) espacio\n",yytext);}
{COMENTARIOLINEAL} {printf("(%s) Comentario lineal\n",yytext);}
{COMENTARIOBLOQUE} {printf("(%s) Comentario en bloque\n",yytext);}

%%

int main()
{
  printf("****ANALIZADOR LEXICO**** \n");
	yyin=stdin;
	yylex();
	return 0;
}

