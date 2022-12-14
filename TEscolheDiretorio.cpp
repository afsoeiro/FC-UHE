//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.Hpp>>
#pragma hdrstop
#include "Defines.h"
#include "TEquipamento.h"
#include "TEscolheDiretorio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEscolheDiretorio *EscolheDiretorio;
//---------------------------------------------------------------------------
__fastcall TEscolheDiretorio::TEscolheDiretorio(TComponent* Owner)
        : TForm(Owner)
{
IniEmAlteracao=NULL;
}
//---------------------------------------------------------------------------
bool __fastcall TEscolheDiretorio::Configura(TIniFile *IniFile)
{
if(ShowModal()!=mrOk)
  return false;
IniFile->WriteString("Equipamentos","local",this->Local->Caption);
return true;
}
//---------------------------------------------------------------------------


