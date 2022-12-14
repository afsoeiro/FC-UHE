//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "TSolucao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSolucao *Solucao;
//---------------------------------------------------------------------------
__fastcall TSolucao::TSolucao(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSolucao::Mostra(AnsiString eTexto)
{
TStringStream *formatado;
formatado=new TStringStream(eTexto);
Texto=eTexto;
RichEdit1->Lines->Clear();
RichEdit1->Lines->LoadFromStream(formatado);
ShowModal();
delete formatado;
}

void __fastcall TSolucao::miSalvarClick(TObject *Sender)
{
FILE *fp;
if(!SaveDialog->Execute())
  return;

fp=fopen(SaveDialog->FileName.c_str(),"wb");
fwrite(Texto.c_str(),Texto.Length(),1,fp);
fclose(fp);
}
//---------------------------------------------------------------------------

