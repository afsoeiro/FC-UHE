//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TLista.h"
#include "Defines.h"
#include "TObjeto.h"
#include "TVariavel.h"
#include "TListaDeVariaveis.h"
#include "TBancoDeVariaveis.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TBancoDeVariaveis::TBancoDeVariaveis(void):TLista()
{
Tipo=TP_BANCODEVARIAVEIS;
FTotal=0;
}
__fastcall TBancoDeVariaveis::TBancoDeVariaveis(class TObjeto *eDono)
                             :TLista(eDono)
{
Tipo=TP_BANCODEVARIAVEIS;
FTotal=0;
}
__fastcall TBancoDeVariaveis::~TBancoDeVariaveis(void)
{
}

class TListaDeVariaveis* __fastcall TBancoDeVariaveis::FGetListas(int Indice)
{
return (TListaDeVariaveis*)TLista::Objetos[Indice];
}

void __fastcall TBancoDeVariaveis::FSetListas(int Indice,\
                                              class TListaDeVariaveis* Var)
{
TLista::Objetos[Indice]=(TObjeto*)Var;
}

bool __fastcall TBancoDeVariaveis::Insere(class TListaDeVariaveis *eLista)
{
if(eLista->Tipo!=TP_LISTADEVARIAVEIS)
  return false;
return TLista::Insere((TObjeto*)eLista);
}

bool __fastcall TBancoDeVariaveis::Insere(class TVariavel *eVariavel)
{
TListaDeVariaveis *listadevariaveis;
if(!eVariavel->Dono)
  {
  if(this->Indice("Globais")==-1)
    {
    listadevariaveis=new TListaDeVariaveis();
    listadevariaveis->Nome="Globais";
    if(!TLista::Insere((TObjeto*)listadevariaveis))
      return false;
    }
  else
    listadevariaveis=this->Listas[this->Indice("Globais")];
  }
else
  {
  if(this->Indice(eVariavel->Dono->Nome)==-1)
    {
    listadevariaveis=new TListaDeVariaveis(eVariavel->Dono);
    if(!TLista::Insere((TObjeto*)listadevariaveis))
      return false;
    }
  else
    listadevariaveis=this->Listas[this->Indice(eVariavel->Dono->Nome)];
  }
if(listadevariaveis)
  if(listadevariaveis->Insere(eVariavel))
    {
    FTotal++;
    return true;
    }
return false;
}

class TListaDeVariaveis* __fastcall TBancoDeVariaveis::Remove(AnsiString eNome)
{
TListaDeVariaveis *ret;
ret=(TListaDeVariaveis*)TLista::Remove(eNome);
if(ret)
  FTotal-=ret->Numero;
return ret;
}

TVariavel* __fastcall TBancoDeVariaveis::Remove(TVariavel *eVariavel)
{
TVariavel *ret;
TListaDeVariaveis *listadevariaveis;
if(!eVariavel)
  return NULL;
if(!eVariavel->Dono)
  listadevariaveis=Listas[Indice("Globais")];
else
  listadevariaveis=Listas[Indice(eVariavel->Dono->Nome)];
if(listadevariaveis)
  {
  ret=listadevariaveis->Remove(eVariavel->Nome);
  FTotal--;
  return ret;
  }
return NULL;
}

class TVariavel* __fastcall TBancoDeVariaveis::Remove(AnsiString eNome,\
                                                      TObjeto *eDono)
{
TVariavel variavel;
variavel.Nome=eNome;
variavel.Dono=eDono;
return Remove(&variavel);
}

class TVariavel* __fastcall TBancoDeVariaveis::Variavel(AnsiString eNome,\
                                                      TObjeto *eDono)
{
TListaDeVariaveis *lista;
int i;
if(!eDono)
  i=Indice("Globais");
else
  i=Indice(eDono->Nome);
if(i==-1)
  return NULL;
lista=Listas[i];
if(lista->Indice(eNome)==-1)
  return NULL;
return(lista->Variaveis[lista->Indice(eNome)]);
}
double __fastcall TBancoDeVariaveis::Valor(AnsiString eNome, TObjeto *eDono)
{
TVariavel *variavel;
variavel=Variavel(eNome, eDono);
if(variavel)
  return variavel->Valor;
return 0;
}

void __fastcall TBancoDeVariaveis::Globaliza(TVariavel* eVariavel)
{
TVariavel *tvar;
if(!eVariavel->Dono)
  return;
tvar=Remove(eVariavel->Nome,eVariavel->Dono);
if(tvar==NULL)
  return;
tvar->Dono=NULL;
Insere(tvar);
}

void __fastcall TBancoDeVariaveis::Localiza(TVariavel* eVariavel, TObjeto *eDono)
{
TVariavel *tvar;
if((tvar=this->Remove(eVariavel))==NULL)
  return;
tvar->Dono=eDono;
Insere(tvar);
}

bool __fastcall TBancoDeVariaveis::FNecessitaDados(void)
{
int i,j;
if(Numero)
  for(i=0;i<Numero;i++)
     if(Listas[i]->Numero)
       for(j=0;j<Listas[i]->Numero;j++)
          if(Listas[i]->Variaveis[j]->DeEntrada)
            return true;
return false;
}

TBancoDeVariaveis& TBancoDeVariaveis::operator =(TBancoDeVariaveis& src)
{
int i;
TListaDeVariaveis *tlista;
if(this==&src)
 return *this;
while(Listas[0])
 delete Remove(Nomes[0]);
Nome=src.Nome;
Dono=src.Dono;
for(i=0;i<src.Numero;i++)
   {
   tlista=new TListaDeVariaveis();
   *tlista=*(src.Listas[i]);
   Insere(tlista);
   }
return *this;
}
