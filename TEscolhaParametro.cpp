//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TEscolhaParametro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEscolhaParametro *EscolhaParametro;
//---------------------------------------------------------------------------
__fastcall TEscolhaParametro::TEscolhaParametro(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TEscolhaParametro::ListClick(TObject *Sender)
{
this->ModalResult=mrOk;
}
//---------------------------------------------------------------------------
