//---------------------------------------------------------------------------

#include <vcl.h>
#include <dir.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "TMain.h"
#include "TSobre.h"
#include "TLista.h"
#include "Defines.h"
#include "TFuncao.h"
#include "TEdFuncao.h"
#include "TEquipamento.h"
#include "TEdEquipamento.h"
#include "TEntradaDeDados.h"
#include "TBancoDeVariaveis.h"
#include "TListaDeVariaveis.h"
#include "TEntradaDePonto.h"
#include "TEscolheDiretorio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain *Main;
//---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner)
        : TForm(Owner)
{
ThousandSeparator='.';
DecimalSeparator=',';
AppPath=new AnsiString(ExtractFilePath(Application->ExeName));
IniFilePath=new AnsiString();
(*IniFilePath)=ChangeFileExt(Application->ExeName, ".INI");
IniFile=new TIniFile(*IniFilePath);
Equipamentos=new TStringList();
RefazMenus();
}
void __fastcall TMain::RefazMenus(void)
{
int I;
TMenuItem *DelItem;
AnsiString *EqPath;
AnsiString SearchString;
TSearchRec sr;
TEquipamento *tequ;
EqPath=new AnsiString();
(*EqPath)=IniFile->ReadString("Equipamentos","local",".");
if(*(EqPath->AnsiLastChar())!='\\')
  (*EqPath)+="\\";
SearchString=(*EqPath)+"*.epm";
Equipamentos->Clear();

if(FindFirst(SearchString, 0, sr) == 0)
  {
  do
   {
   Equipamentos->Add((*EqPath)+sr.Name);
   }
  while(FindNext(sr) == 0);
  FindClose(sr);
  }
tequ=new TEquipamento();
while(mModificarEquipamento->Count)
  {
  DelItem=mModificarEquipamento->Items[0];
  mModificarEquipamento->Delete(0);
  delete DelItem;
  }
while(mAnteprojeto->Count)
  {
  DelItem=mAnteprojeto->Items[0];
  mAnteprojeto->Delete(0);
  delete DelItem;
  }
for (I = 0; I < Equipamentos->Count; I++)
    {
    if(!tequ->Carrega(Equipamentos->Strings[I]))
      {
      Equipamentos->Delete(I);
      I--;
      continue;
      }
    TMenuItem *NewItem;
    NewItem = new TMenuItem(mModificarEquipamento);
    NewItem->Caption=tequ->Nome;
    NewItem->Name = "me"+AnsiString(I);
    NewItem->OnClick = ModificarEquipamentoClick;
    NewItem->Tag=I;
    mModificarEquipamento->Add(NewItem);
    NewItem = new TMenuItem(mAnteprojeto);
    NewItem->Caption=tequ->Nome;
    NewItem->Name =  "ma"+AnsiString(I);
    NewItem->OnClick = EquipamentosClick;
    NewItem->Tag=I;
    mAnteprojeto->Add(NewItem);
    }
delete tequ;
}


//---------------------------------------------------------------------------
void __fastcall TMain::EquipamentosClick(TObject *Sender)
{
int indice;
TEquipamento *tequ;
TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
if(!ClickedItem)
  return;
indice=ClickedItem->Tag;
tequ=new TEquipamento();
tequ->Carrega(Equipamentos->Strings[indice]);
if(tequ->ListaDeVariaveis->NumeroDeParametros)
  if(EntradaDeDados->PegaLista(tequ->ListaDeVariaveis))
    tequ->Resolve();
delete tequ;
}
void __fastcall TMain::ModificarEquipamentoClick(TObject *Sender)
{
int indice;
TEquipamento *tequ;
TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
if(!ClickedItem)
  return;
indice=ClickedItem->Tag;
tequ=new TEquipamento();
if(!tequ->Carrega(Equipamentos->Strings[indice]))
  {
  ShowMessage("O Equipamento escohido é inválido ou não pode ser carregado.");
  return;
  }
if(EdEquipamento->Editar(tequ))
  tequ->Salva(Equipamentos->Strings[indice]);
delete tequ;
}

//
void __fastcall TMain::MainDestroy(TObject *Sender)
{
SAFEDEL(AppPath);
SAFEDEL(IniFile);
SAFEDEL(IniFilePath);
SAFEDEL(Equipamentos);
}
//---------------------------------------------------------------------------
void __fastcall TMain::mSobreClick(TObject *Sender)
{
Sobre->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMain::mNovoEquipamentoClick(TObject *Sender)
{
TEquipamento *tequ;
tequ=new TEquipamento();
tequ->Nome="Novo";
if(!EdEquipamento->Editar(tequ))
  return;
if(SaveDialog->Execute())
  if(!tequ->Salva(SaveDialog->FileName))
    ShowMessage("Atenção!\nO equipamento não foi salvo corretamente!");
Equipamentos->Add(SaveDialog->FileName);
TMenuItem *NewItem;
NewItem = new TMenuItem(mModificarEquipamento);
NewItem->Caption=tequ->Nome;
NewItem->Name = "me"+AnsiString(Equipamentos->Count-1);
NewItem->OnClick = ModificarEquipamentoClick;
NewItem->Tag=(Equipamentos->Count-1);
mModificarEquipamento->Add(NewItem);
NewItem = new TMenuItem(mAnteprojeto);
NewItem->Caption=tequ->Nome;
NewItem->Name =  "ma"+AnsiString(Equipamentos->Count-1);
NewItem->OnClick = EquipamentosClick;
NewItem->Tag=(Equipamentos->Count-1);
mAnteprojeto->Add(NewItem);
delete tequ;
}
//---------------------------------------------------------------------------

void __fastcall TMain::miEscolherDiretorioClick(TObject *Sender)
{
AnsiString Diretorio;
if(EscolheDiretorio->Configura(IniFile))
  RefazMenus();
}
//---------------------------------------------------------------------------
void __fastcall TMain::Indice1Click(TObject *Sender)
{
Application->HelpCommand(HELP_CONTENTS, 0);
}
//---------------------------------------------------------------------------

