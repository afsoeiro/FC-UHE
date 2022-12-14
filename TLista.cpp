//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TLista.h"
#include "TObjeto.h"
#include "TFuncao.h"
#include "TVariavel.h"
#include "TListaDeVariaveis.h"
#include "TBancoDeVariaveis.h"
#include "Defines.h"
#pragma package(smart_init)

int __fastcall TLista::FGetNumero(void)
{
return FNumero;
}

AnsiString __fastcall TLista::FGetNomes(int Indice)
{
AnsiString ret="";
Lista *lista;
lista=Cartorio;
if(Indice>=0 && Indice<Numero)
  {
  while(Indice && lista)
       {
       lista=lista->Proximo;
       Indice--;
       }
  if(lista)
    ret=lista->Elemento->Nome;
  }
return ret;
}

TObjeto* __fastcall TLista::FGetObjetos(int Indice)
{
Lista *lista;
lista=Cartorio;
if(Indice>=0 && Indice<Numero)
  {
  while(Indice && lista)
       {
       lista=lista->Proximo;
       Indice--;
       }
  if(lista)
    return lista->Elemento;
  }
return NULL;
}

void __fastcall TLista::FSetNomes(int Indice, AnsiString eNome)
{
Lista *lista;
lista=Cartorio;
if(Indice>=0 && Indice<Numero)
  {
  while(Indice && lista)
       {
       lista=lista->Proximo;
       Indice--;
       }
  if(lista)
    lista->Elemento->Nome=eNome;
  }
}

void __fastcall TLista::FSetObjetos(int Indice, TObjeto* Objeto)
{
Lista *lista;
lista=Cartorio;
if(Indice>=0 && Indice<Numero)
  {
  while(Indice && lista)
       {
       lista=lista->Proximo;
       Indice--;
       }
  if(lista)
    {
    if(lista->Elemento!=Objeto)
      {
      if(lista->Elemento)
        delete lista->Elemento;
      lista->Elemento=Objeto;
      }
    }
  }
}
void __fastcall TLista::FSetPtrObjetos(int Indice, TObjeto* Objeto)
{
Lista *lista;
lista=Cartorio;
if(Indice>=0 && Indice<Numero)
  {
  while(Indice && lista)
       {
       lista=lista->Proximo;
       Indice--;
       }
  if(lista)
    lista->Elemento=Objeto;
  }
}

__fastcall TLista::TLista(void) : TObjeto()
{
Cartorio=NULL;
FNumero=0;
Tipo=TP_LISTA;
}
__fastcall TLista::TLista(class TObjeto* eDono) : TObjeto(eDono)
{
Cartorio=NULL;
FNumero=0;
Tipo=TP_LISTA;
}
__fastcall TLista::~TLista(void)
{
Lista *lista;
while(Cartorio)
  {
  lista=Cartorio;
  Cartorio=Cartorio->Proximo;
  if(lista->Elemento)
    CastedDelete(lista->Elemento);
  delete lista;
  }
}

void __fastcall TLista::CastedDelete(TObjeto* Objeto)
{
switch(Objeto->Tipo)
  {
  case TP_OBJETO:
    delete (class TObjeto*)Objeto;
    break;
  case TP_VARIAVEL:
    delete (class TVariavel*)Objeto;
    break;
  case TP_LISTA:
    delete (class TLista*)Objeto;
    break;
  case TP_FUNCAO:
    delete (class TFuncao*)Objeto;
    break;
  case TP_LISTADEVARIAVEIS:
    delete (class TListaDeVariaveis*)Objeto;
    break;
  case TP_BANCODEVARIAVEIS:
    delete (class TBancoDeVariaveis*)Objeto;
    break;
  default:
    delete Objeto;
  }
}

bool __fastcall TLista::Insere(TObjeto* Objeto)
{
Lista *lista;
Lista **Cria;
if(!Cartorio)
  Cria=&Cartorio;
else
  {
  lista=Cartorio;
  while(lista)
    {
    if(lista->Elemento->Nome==Objeto->Nome)
      {
      if(lista->Elemento!=Objeto)
        {
        CastedDelete(lista->Elemento);
        lista->Elemento=Objeto;
        }
      return false;
      }
    if(lista->Proximo)
      lista=lista->Proximo;
    else
      {
      Cria=&(lista->Proximo);
      lista=lista->Proximo;
      }
    }
  }
*Cria=new Lista;
(*Cria)->Elemento=Objeto;
(*Cria)->Proximo=NULL;
FNumero++;
return true;
}

TObjeto* __fastcall TLista::Remove(AnsiString eNome)
{
Lista *lista;
Lista *del;
TObjeto *ret=NULL;
lista=Cartorio;
if(Cartorio->Elemento->Nome==eNome)
  {
  ret=Cartorio->Elemento;
  Cartorio->Elemento=NULL;
  Cartorio=Cartorio->Proximo;
  delete lista;
  FNumero--;
  return ret;
  }
while(lista->Proximo && lista->Proximo->Elemento->Nome!=eNome)
  lista=lista->Proximo;
if(lista->Proximo)
  {
  del=lista->Proximo;
  ret=del->Elemento;
  del->Elemento=NULL;
  lista->Proximo=del->Proximo;
  delete del;
  FNumero--;
  }
return ret;
}

int __fastcall TLista::Indice(AnsiString eNome)
{
Lista *lista;
int ret=-1;
lista=Cartorio;
while(lista)
     {
     ret++;
     if(lista->Elemento->Nome==eNome)
       return ret;
     lista=lista->Proximo;
     }
return -1;
}
bool __fastcall TLista::Troca(int eIndice1, int eIndice2)
{
TObjeto *tobj;
if(!PtrObjetos[eIndice1] || !PtrObjetos[eIndice2])
  return false;
tobj=PtrObjetos[eIndice1];
PtrObjetos[eIndice1]=PtrObjetos[eIndice2];
PtrObjetos[eIndice2]=tobj;
return true;
}
