//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TLista.h"
#include "Defines.h"
#include "TVariavel.h"
#include "TListaDeVariaveis.h"

#pragma package(smart_init)

__fastcall TListaDeVariaveis::TListaDeVariaveis(void):TLista()
{
Tipo=TP_LISTADEVARIAVEIS;
FNumeroDeParametros=0;
}

__fastcall TListaDeVariaveis::TListaDeVariaveis(class TObjeto *eDono)
                             :TLista(eDono)
{
Tipo=TP_LISTADEVARIAVEIS;
FNumeroDeParametros=0;
}

__fastcall TListaDeVariaveis::~TListaDeVariaveis(void)
{
}

bool __fastcall TListaDeVariaveis::Insere(class TVariavel *eVariavel)
{
if(eVariavel->Tipo==TP_VARIAVEL)
  return TLista::Insere((TObjeto*)eVariavel);
return false;
}

bool __fastcall TListaDeVariaveis::Insere(AnsiString eNome, double eValor)
{
TVariavel *variavel;
variavel=new TVariavel();
variavel->Nome=eNome;
variavel->Valor=eValor;
return Insere(variavel);
}
class TVariavel* __fastcall TListaDeVariaveis::Variavel(AnsiString eNome)
{
int i;
i=Indice(eNome);
if(i==-1)
  return NULL;
return Variaveis[i];
}
double __fastcall TListaDeVariaveis::Valor(AnsiString eNome)
{
TVariavel *variavel;
variavel=Variavel(eNome);
if(variavel)
  return variavel->Valor;
return 0;
}

bool __fastcall TListaDeVariaveis::FNecessitaDados(void)
{
if(NumeroDeParametros)
  return true;
return false;
}

int __fastcall TListaDeVariaveis::FGetNumeroDeParametros(void)
{
int i;
FNumeroDeParametros=0;
if(Numero)
  for(i=0;i<Numero;i++)
     if(Variaveis[i]->DeEntrada)
       FNumeroDeParametros++;
return FNumeroDeParametros;
}


TVariavel* __fastcall TListaDeVariaveis::Remove(AnsiString eNome)
{
TVariavel *ret;
ret=(TVariavel*)TLista::Remove(eNome);
return ret;
}

bool __fastcall TListaDeVariaveis::Salva(AnsiString arquivo)
{
int fHandle;
try {
    fHandle=FileCreate(arquivo);
    Salva(fHandle);
    FileClose(fHandle);
    } catch(...)
           {
           ShowMessage("Problemas no salvamento de uma equação.");
           return false;
           }
return true;
}

bool __fastcall TListaDeVariaveis::Salva(int fHandle)
{
  int dado=ID_LISTA_DE_VARIAVEIS;
  char *buffer;
  if(fHandle==-1) Joga;
  try{
    FileWrite(fHandle,&dado,sizeof(dado));
    buffer=Nome.c_str();
    dado=strlen(buffer)+1;
    FileWrite(fHandle,&dado,sizeof(dado));
    FileWrite(fHandle,buffer,dado);
    dado=Numero;
    FileWrite(fHandle,&dado,sizeof(dado));
    for(dado=0;dado<Numero;dado++)
       Variaveis[dado]->Salva(fHandle);
    } catch(...)
       {
       ShowMessage("Problemas no salvamento de uma variável.");
       return false;
       }
  return true;
}

bool __fastcall TListaDeVariaveis::Carrega(AnsiString arquivo)
{
int fHandle;
try {
    fHandle=FileOpen(arquivo, fmOpenRead);
    Carrega(fHandle);
    FileClose(fHandle);
    } catch(...)
           {
           ShowMessage("Problemas no carregamento de uma uma variavel.");
           return false;
           }
return true;
}

bool __fastcall TListaDeVariaveis::Carrega(int fHandle)
{
  int dado;
  char *buffer;
  int i;
  TVariavel *tvar;
  if(fHandle==-1) Joga;
  try{
    FileRead(fHandle,&dado,sizeof(dado));
    if(dado!=ID_LISTA_DE_VARIAVEIS)
      Joga; // Meu define, ate fazer os exceptions de verdade.
    FileRead(fHandle,&dado,sizeof(dado));
    buffer=new char[dado];
    FileRead(fHandle,buffer,dado);
    Nome=buffer;
    delete[] buffer;
    FileRead(fHandle,&dado,sizeof(dado));
    for(i=0;i<dado;i++)
       {
       tvar=new TVariavel();
       tvar->Carrega(fHandle);
       tvar->Dono=this->Dono;
       Insere(tvar);
       }
    } catch(...)
       {
       ShowMessage("Problemas no salvamento de uma variável.");
       return false;
       }
  return true;
}

TVariavel* __fastcall TListaDeVariaveis::FGetVariaveis(int Indice)
{
return (TVariavel*)TLista::Objetos[Indice];
}

void __fastcall TListaDeVariaveis::FSetVariaveis(int Indice,class TVariavel* Var)
{
if(TLista::Objetos[Indice])
  TLista::Objetos[Indice]=(TObjeto*)Var;
}

TListaDeVariaveis& TListaDeVariaveis::operator =(TListaDeVariaveis& src)
{
int i;
TVariavel *tvar;
if(this==&src)
 return *this;
while(Variaveis[0])
 delete Remove(Nomes[0]);
Nome=src.Nome;
Dono=src.Dono;
for(i=0;i<src.Numero;i++)
   {
   tvar=new TVariavel();
   *tvar=*(src.Variaveis[i]);
   Insere(tvar);
   }
return *this;
}
