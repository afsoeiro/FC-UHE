//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TObjeto.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
__fastcall TObjeto::TObjeto()
{
FDono=NULL;
FNome=new AnsiString();
}
__fastcall TObjeto::TObjeto(class TObjeto *eDono)
{
FDono=eDono;
FNome=new AnsiString(eDono->Nome);
}

__fastcall TObjeto::~TObjeto(void)
{
if(FNome) delete FNome;
}

AnsiString __fastcall TObjeto::GetNome(void)
{
if(FNome)
  return *FNome;
return "";
}

void __fastcall TObjeto::SetNome(AnsiString eNome)
{
if(FNome)
  *FNome=eNome;
else
  FNome=new AnsiString(eNome);
}

class TObjeto* __fastcall TObjeto::GetDono(void)
{
return FDono;
}

void __fastcall TObjeto::SetDono(class TObjeto* eObjeto)
{
FDono=eObjeto;
}

int __fastcall TObjeto::GetTipo(void)
{
return FTipo;
}

void __fastcall TObjeto::SetTipo(int eTipo)
{
FTipo=eTipo;
}

