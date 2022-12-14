//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "TFuncao.h"
#include "TVariavel.h"
#include "TEntradaDeDados.h"
#include "TListaDeVariaveis.h"
#include "TBancoDeVariaveis.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEntradaDeDados *EntradaDeDados;
//---------------------------------------------------------------------------
__fastcall TEntradaDeDados::TEntradaDeDados(TComponent* Owner)
        : TForm(Owner)
{
Grid->Cells[0][0]="Nome";
Grid->Cells[1][0]="Valor";
Grid->Cells[2][0]="Descrição da variável";
}
//---------------------------------------------------------------------------
bool __fastcall TEntradaDeDados::PegaLista(TListaDeVariaveis *lista)
{
int i;
int j;
TListaDeVariaveis *pegar;

pegar=new TListaDeVariaveis();
*pegar=*lista;
Grid->RowCount=1;
Grid->RowCount+=pegar->NumeroDeParametros;
Grid->FixedRows=1;
for(i=0,j=0;j<pegar->NumeroDeParametros;i++)
 {
 if((pegar->Variaveis[i])->DeEntrada)
   {
   Grid->Cells[0][j+1]=pegar->Nomes[i];
   Grid->Cells[1][j+1]=(pegar->Variaveis[i])->Valor;
   Grid->Cells[2][j+1]=(pegar->Variaveis[i])->Info;
   j++;
   }
 }
 if(ShowModal()!=mrOk)
   {
   delete pegar;
   return false;
   }
 try
  {
  for(i=0,j=0;j<pegar->NumeroDeParametros;i++)
     if((pegar->Variaveis[i])->DeEntrada)
       {
       pegar->Variaveis[i]->Valor=Grid->Cells[1][j+1].ToDouble();
       j++;
       }
  }
 catch(EConvertError &ConvertError)
      {
      ShowMessage("Os campos de valor da variável devem ser preenchidos unicamente"\
          " com números, e o caractere '"+AnsiString(DecimalSeparator)+"'.");
      return false;
      }
*lista=*pegar;
delete pegar;
return true;
}

bool __fastcall TEntradaDeDados::PegaBanco(TBancoDeVariaveis *banco)
{
int i,j;
TLista *pegar;
pegar=new TLista();
Grid->RowCount=0;

for(i=0;i<banco->Numero;i++)
   for(j=0;j<banco->Listas[i]->Numero;j++)
      if(banco->Listas[i]->Variaveis[j]->DeEntrada)
        pegar->Insere((TObjeto*)banco->Listas[i]->Variaveis[j]);

Grid->RowCount=pegar->Numero+1;
Grid->FixedRows=1;

for(i=0;i<pegar->Numero;i++)
 {
 if(((TVariavel*)pegar->Objetos[i])->Dono)
   Grid->Cells[0][i+1]=((TVariavel*)pegar->Objetos[i])->Dono->Nome+":"+\
                       pegar->Nomes[i];
 else
   Grid->Cells[0][i+1]=AnsiString("Global")+":"+pegar->Nomes[i];
 Grid->Cells[1][i+1]=((TVariavel*)pegar->Objetos[i])->Valor;
 Grid->Cells[2][i+1]=((TVariavel*)pegar->Objetos[i])->Info;
 }
if(ShowModal()!=mrOk)
  {
  while(pegar->Numero)
    pegar->Remove(pegar->Nomes[0]);
  delete pegar;
  return false;
  }
try {
for(i=0;i<pegar->Numero;i++)
   ((TVariavel*)pegar->Objetos[i])->Valor=Grid->Cells[1][i+1].ToDouble();
} catch(EConvertError &ConvertError)
  {
  ShowMessage("Os campos de valor da variável devem ser preenchidos unicamente"\
          " com números, e o caractere '"+AnsiString(DecimalSeparator)+"'.");
  while(pegar->Numero)
    pegar->Remove(pegar->Nomes[0]);
  delete pegar;
  return false;
  }
while(pegar->Numero)
  pegar->Remove(pegar->Nomes[0]);
delete pegar;
return true;
}
bool __fastcall TEntradaDeDados::PegaVariavel(class TVariavel &var)
{
Caption=var.Nome;
return true;
}
void __fastcall TEntradaDeDados::bSegueClick(TObject *Sender)
{
int i;
try{
for(i=1;i<Grid->RowCount;i++)
   Grid->Cells[1][i].ToDouble();
} catch(EConvertError &ConvertError)
  {
  ShowMessage("Os campos de valor da variável devem ser preenchidos unicamente"\
          " com números, e o caractere '"+AnsiString(DecimalSeparator)+"'.");
  return;
  }
ModalResult=mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TEntradaDeDados::TEntradaDeDadosResize(TObject *Sender)
{
Grid->Height=StatusBar->Top-33;
}
//---------------------------------------------------------------------------

