//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Defines.h"
#include "TVariavel.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

  __fastcall TVariavel::TVariavel() :TObjeto()
  {
  FData=0;
  FDescricao=new AnsiString("");
  FDeEntrada=true;
  Tipo=TP_VARIAVEL;
  }

  __fastcall TVariavel::TVariavel(class TObjeto *eDono) :TObjeto(eDono)
  {
  FData=0;
  FDescricao=new AnsiString("");
  FDeEntrada=true;
  Tipo=TP_VARIAVEL;
  }

  __fastcall TVariavel::TVariavel(double valor)
                      :TObjeto()
  {
  FData=valor;
  FDescricao=new AnsiString("");
  FDeEntrada=true;
  }

  __fastcall TVariavel::~TVariavel()
  {
  SAFEDEL(FDescricao);
  }
  TVariavel& TVariavel::operator =(TVariavel& src)
  {
  if(this==&src)
   return *this;
  Valor=src.Valor;
  Info=src.Info;
  Nome=src.Nome;
  DeEntrada=src.DeEntrada;
  Dono=src.Dono;
  return *this;
  }
  double __fastcall TVariavel::GetValor()
  {
  return FData;
  }
  void __fastcall TVariavel::SetValor(double valor)
  {
  FData=valor;
  }
  bool __fastcall TVariavel::GetDeEntrada()
  {
  return FDeEntrada;
  }
  void __fastcall TVariavel::SetDeEntrada(bool eDeEntrada)
  {
  FDeEntrada=eDeEntrada;
  }
  AnsiString __fastcall TVariavel::GetDescricao()
  {
  return *FDescricao;
  }
  void __fastcall TVariavel::SetDescricao(AnsiString eDescricao)
  {
  *FDescricao=eDescricao;
  }
bool __fastcall TVariavel::Salva(AnsiString arquivo)
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
  bool __fastcall TVariavel::Salva(int fHandle)
  {
  char *buffer;
  int dado=ID_VARIAVEL;
  if(fHandle==-1) Joga;
  try{
    FileWrite(fHandle,&dado,sizeof(dado));
    buffer=Nome.c_str();
    dado=strlen(buffer)+1;
    FileWrite(fHandle,&dado,sizeof(dado));
    FileWrite(fHandle,buffer,dado);
    FileWrite(fHandle,&FData,sizeof(FData));
    buffer=FDescricao->c_str();
    dado=strlen(buffer)+1;
    FileWrite(fHandle,&dado,sizeof(dado));
    FileWrite(fHandle,buffer,dado);
    FileWrite(fHandle,&FDeEntrada,sizeof(FDeEntrada));
    } catch(...)
       {
       ShowMessage("Problemas no salvamento de uma variável.");
       return false;
       }
  return true;
  }
bool __fastcall TVariavel::Carrega(AnsiString arquivo)
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
  bool __fastcall TVariavel::Carrega(int fHandle)
  {
  char *buffer;
  int dado;
  try {
      if(fHandle==-1) Joga;
      FileRead(fHandle,&dado,sizeof(dado));
      if(dado!=ID_VARIAVEL) return false;
      FileRead(fHandle,&dado,sizeof(dado));
      buffer=new char[dado];
      FileRead(fHandle,buffer,dado);
      Nome=buffer;
      delete[] buffer;
      FileRead(fHandle,&FData,sizeof(FData));
      FileRead(fHandle,&dado,sizeof(dado));
      buffer=new char[dado];
      FileRead(fHandle,buffer,dado);
      *FDescricao=buffer;
      delete[] buffer;
      FileRead(fHandle,&FDeEntrada,sizeof(FDeEntrada));
      } catch(...)
         {
         ShowMessage("Problemas na leitura de uma variável.");
         return false;
         }
  return true;
  }

