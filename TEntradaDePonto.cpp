//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "TEntradaDePonto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEntradaDePonto *EntradaDePonto;
//---------------------------------------------------------------------------
__fastcall TEntradaDePonto::TEntradaDePonto(TComponent* Owner)
        : TForm(Owner)
{
lVirgula1->Caption=";";
lP1e->Caption="(";
lP1d->Caption=")";
eX1->Left=lP1e->Left+lP1e->Width+2;
lVirgula1->Left=eX1->Left+eX1->Width+2;
eY1->Left=lVirgula1->Left+lVirgula1->Width+2;
lP1d->Left=eY1->Left+eY1->Width+2;
pPonto1->Width=lP1d->Left+lP1d->Width+8;
pPonto1->Height=eX1->Height+10;
gbPonto1->Width=pPonto1->Width+20;
gbPonto1->Height=pPonto1->Height+30;
lIntro->Caption="Favor entrar com os valores dos dois pontos que definem o"\
                "segmento de reta e clicar \"Ok\"";
gbPonto1->Top=lIntro->Height+10;

lVirgula2->Caption=";";
lP2e->Caption="(";
lP2d->Caption=")";
eX2->Left=lP2e->Left+lP2e->Width+2;
lVirgula2->Left=eX2->Left+eX2->Width+2;
eY2->Left=lVirgula2->Left+lVirgula2->Width+2;
lP2d->Left=eY2->Left+eY2->Width+2;
pPonto2->Width=lP2d->Left+lP2d->Width+8;
pPonto2->Height=eX2->Height+10;
gbPonto2->Width=pPonto2->Width+20;
gbPonto2->Height=pPonto2->Height+30;
gbPonto2->Top=gbPonto1->Top;
EntradaDePonto->ClientWidth=2*gbPonto2->Width+70;
gbPonto1->Left=(pJanela->ClientWidth-(2*gbPonto1->Width+20))/2;
gbPonto2->Left=gbPonto1->Left+gbPonto1->Width+20;
bOk->Top=gbPonto2->Top+gbPonto2->Height+6;
bCancela->Top=bOk->Top;
EntradaDePonto->ClientHeight=bOk->Top+bOk->Height+6;
bOk->Left=(pJanela->ClientWidth-(2*bOk->Width+30))/2;
bCancela->Left=bOk->Left+bOk->Width+30;
}
//---------------------------------------------------------------------------
char** TEntradaDePonto::PegaReta(void)
{
char **ret;
AnsiString Texto, Intervalo;
try{
if(this->ShowModal()==mrCancel)
  return NULL;
Texto="";
if(a)
  {
  Texto+=AnsiString(a);
  Texto+="*X";
  }
if(b<0)
  Texto+=AnsiString(b);
else
  if(b)
    Texto+="+"+AnsiString(b);

Intervalo="[";
Intervalo+=eX1->Text;
Intervalo+=";";
Intervalo+=eX2->Text;
Intervalo+="]";
ret=new char*[2];
ret[0]=new char[Texto.Length()+1];
strcpy(ret[0],Texto.c_str());
ret[1]=new char[Intervalo.Length()+1];
strcpy(ret[1],Intervalo.c_str());
return ret;
}
catch (EDivByZero& ediv) // Nao devia acontecer aqui...
 {
 ShowMessage("Aconteceu uma divisao por zero!\nOperação abortada!");
 if(ret) delete ret;
 return NULL;
 }
catch (EZeroDivide& ezero) // Nao devia acontecer aqui...
 {
 ShowMessage("Aconteceu uma divisao por zero! Operação abortada!");
 if(ret) delete ret;
 return NULL;
 }
catch (EConvertError& econv) // Nao devia acontecer aqui...
 {
 if(ret) delete ret;
 ShowMessage("Aconteceu um erro na conversao nao tratado no local apropriado!"\
             "Operação abortada!");
 return NULL;
 }
}
void __fastcall TEntradaDePonto::bOkClick(TObject *Sender)
{
try{
a=(eY2->Text.ToDouble()-eY1->Text.ToDouble())/\
  (eX2->Text.ToDouble()-eX1->Text.ToDouble());
b=eY1->Text.ToDouble()-a*eX1->Text.ToDouble();
}
catch (EDivByZero& ediv)
 {
 ShowMessage("Ocorreu uma divisão por zero!\nFavor verificar os valores de X2"\
             " e X1.");
 return;
 }
catch (EZeroDivide& ezero)
 {
 ShowMessage("Ocorreu uma divisão por zero!\nFavor verificar os valores de X2"\
             " e X1.");
 return;
 }
catch (EConvertError& econv)
 {
 ShowMessage("Problemas com os valores digitados para as coordenadas.\n"\
             "Favor verificar se os valores estão corretos e se o separador "\
             "decimal utilizado é '"+AnsiString(DecimalSeparator)+"'.");
 return;
 }
this->ModalResult=mrOk;
}
//---------------------------------------------------------------------------

