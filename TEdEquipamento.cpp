//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Defines.h"
#include "TFuncao.h"
#include "TEdFuncao.h"
#include "TVariavel.h"
#include "TEquipamento.h"
#include "TEdEquipamento.h"
#include "TEntradaDeDados.h"
#include "TListaDeVariaveis.h"
#include "TEscolhaParametro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEdEquipamento *EdEquipamento;
//---------------------------------------------------------------------------
__fastcall TEdEquipamento::TEdEquipamento(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TEdEquipamento::Limpa(void)
{
eNome->Text="Equipamento1";
mDescricao->Lines->Text="";
lbFuncoes->Clear();
mInfoFuncao->Lines->Text="";
lbListaDeVariaveis->Clear();
lbParametros->Clear();
lbOrdem->Clear();
mInfoVariavel->Lines->Text="";
lbNomesVariaveis->Clear();
}
//---------------------------------------------------------------------------
TListaDeVariaveis* __fastcall TEdEquipamento::GetListaDeVariaveis(void)
{
return FVars;
}
void __fastcall TEdEquipamento::SetListaDeVariaveis(TListaDeVariaveis* eLista)
{
FVars=eLista;
}
//---------------------------------------------------------------------------
void __fastcall TEdEquipamento::FormDestroy(TObject *Sender)
{
SAFEDEL(equipamento);
}
//---------------------------------------------------------------------------
void __fastcall TEdEquipamento::FormCreate(TObject *Sender)
{
equipamento=new TEquipamento();
FVars=equipamento->ListaDeVariaveis;
cbefdropping=false;
cbardropping=false;
VariavelEmEdicao=NULL;
lValorVariavel->Caption="Valor:";
}
//---------------------------------------------------------------------------
void __fastcall TEdEquipamento::miCalcularClick(TObject *Sender)
{
if(FVars->NumeroDeParametros)
  EntradaDeDados->PegaLista(FVars);
equipamento->Resolve();
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::miAbrirClick(TObject *Sender)
{
 OpenDialog->Filter = "Arquivos de Equipamento (*.EPM)|*.EPM";
 if(!OpenDialog->Execute())
   return;
 Limpa();
 equipamento->Carrega(OpenDialog->FileName);
 eNome->Text=equipamento->Nome;
 mDescricao->Lines->Text=equipamento->Ajuda;
 iFoto->Picture=equipamento->Foto;
 pcEquipamento->ActivePageIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::miSalvarClick(TObject *Sender)
{
 SaveDialog->Filter = "Arquivos de Equipamento (*.EPM)|*.EPM";
 if(!SaveDialog->Execute())
   return;
 equipamento->Salva(SaveDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TEdEquipamento::eNomeOnChange(TObject *Sender)
{
equipamento->Nome=eNome->Text;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bEscolherFiguraClick(TObject *Sender)
{
 OpenDialog->Filter = "Arquivos de Imagem Bitmap (*.BMP)|*.BMP";
 OpenDialog->Title = "Escolha a foto do equipamento...";
 if(!OpenDialog->Execute())
   return;
 equipamento->CarregaFoto(OpenDialog->FileName);
 iFoto->Picture=equipamento->Foto;
}
//---------------------------------------------------------------------------


void __fastcall TEdEquipamento::pOkCancelaResize(TObject *Sender)
{
int esquerda;//,espaco;
esquerda=(pOkCancela->Width-(bCancela->Width+bOk->Width+64))/2;
bOk->Left=esquerda;
bCancela->Left=esquerda+bOk->Width+64;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::tsGeralResize(TObject *Sender)
{
gbDescricao->Height=tsGeral->Height-69;
mDescricao->Height=gbDescricao->Height-31;
gbFigura->Height=tsGeral->Height-4;
gbNome->Width=tsGeral->Width/2-2;
gbDescricao->Width=gbNome->Width;
eNome->Width=gbNome->Width-20;
mDescricao->Width=gbDescricao->Width-20;
bEscolherFigura->Top=gbFigura->Height-36;
gbFigura->Left=gbDescricao->Width+4;
gbFigura->Width=gbDescricao->Width;
iFoto->Width=gbFigura->Width-20;
iFoto->Height=gbFigura->Height-66;
bEscolherFigura->Width=iFoto->Width;
lbFuncoes->Height=gbFuncoes->Height-34;
gbAjuda->Left=gbFuncoes->Width/2+3;
bNovaFuncao->Left=gbAjuda->Left;
bAbrirFuncaoDoDisco->Left=gbAjuda->Left;
bEditarFuncao->Left=gbAjuda->Left;
bRemoverFuncao->Left=gbAjuda->Left;
gbAjuda->Width=gbFuncoes->Width/2-12;
bNovaFuncao->Width=gbAjuda->Width;
bAbrirFuncaoDoDisco->Width=gbAjuda->Width;
bEditarFuncao->Width=gbAjuda->Width;
bRemoverFuncao->Width=gbAjuda->Width;
lbFuncoes->Width=gbAjuda->Width;
mInfoFuncao->Width=gbAjuda->Width-16;
bRemoverFuncao->Top=lbFuncoes->Height-6;
bEditarFuncao->Top=bRemoverFuncao->Top-32;
bAbrirFuncaoDoDisco->Top=bEditarFuncao->Top-32;
bNovaFuncao->Top=bAbrirFuncaoDoDisco->Top-32;
gbAjuda->Height=bNovaFuncao->Top-24;
mInfoFuncao->Height=gbAjuda->Height-32;
gbResolver->Width=gbAposEntrada->Width/2-10;
gbParametros->Width=gbResolver->Width;
gbMemoria->Width=gbResolver->Width;
bIncluir->Width=gbResolver->Width;
gbOrdem->Width=gbResolver->Width;
bSobe->Width=gbOrdem->Width-12;
lbOrdem->Width=bSobe->Width;
bDesce->Width=bSobe->Width;
bRemover->Width=bSobe->Width;
gbOrdem->Left=gbResolver->Width+14;
gbVariaveisDeEntrada->Height=pOkCancela->Top-36;
bRemoveEntrada->Top=gbVariaveisDeEntrada->Height-33;
lbListaDeVariaveis->Height=bRemoveEntrada->Top-62;
gbAposEntrada->Width=tsModoDeSolucao->Width-176;
gbAposEntrada->Height=gbVariaveisDeEntrada->Height;
gbOrdem->Height=gbAposEntrada->Height-24;
bIncluir->Top=gbAposEntrada->Height-32;
gbMemoria->Top=bIncluir->Top-64;
gbParametros->Height=gbMemoria->Top-78;
lbParametros->Height=gbParametros->Height-28;
cbEntradaDeFuncoes->Width=gbResolver->Width-16;
lbParametros->Width=cbEntradaDeFuncoes->Width;
eArmazenamento->Width=cbEntradaDeFuncoes->Width;
bRemover->Top=gbOrdem->Height-31;
bDesce->Top=bRemover->Top-28;
lbOrdem->Height=bDesce->Top-54;
lValorVariavel->Left=10;
eValor->Left=lValorVariavel->Left+lValorVariavel->Width+10;
eValor->Width=gbInfoVariaveis->Width-eValor->Left-10;
gbNomesVariaveis->Height=tsVariaveis->Height-1;
lbNomesVariaveis->Height=gbNomesVariaveis->Height-31;
gbInfoVariaveis->Height=gbNomesVariaveis->Height;
gbInfoVariaveis->Width=tsVariaveis->Width-gbInfoVariaveis->Left;
gbDescricaoDaVariavel->Height=gbInfoVariaveis->Height-69;
gbDescricaoDaVariavel->Width=gbInfoVariaveis->Width-14;
mInfoVariavel->Width=gbDescricaoDaVariavel->Width-14;
mInfoVariavel->Height=gbDescricaoDaVariavel->Height-33;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::cbEntradaDeFuncoesDown(TObject *Sender)
{
cbefdropping=true;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::cbEntradaDeFuncoesClick(TObject *Sender)
{
int num,i;
if(!cbefdropping)
  return;
num=equipamento->Funcao(cbEntradaDeFuncoes->Text)->ListaDeVariaveis->\
    NumeroDeParametros;
lbParametros->Clear();
for(i=0;i<num;i++)
  lbParametros->Items->Add("[Parm"+AnsiString(i+1)+"]");
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::cbEntradaDeFuncoesExit(TObject *Sender)
{
cbefdropping=false;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::eVariaveisKeyPress(TObject *Sender,
      char &Key)
{
class TVariavel *tvar;
if(Key!=13)
  return;
Key='\0';
if(!FVars->Variavel(eVariaveis->Text))
  {
  lbListaDeVariaveis->Items->Add(eVariaveis->Text);
  tvar=new TVariavel();
  tvar->Nome=eVariaveis->Text;
  tvar->DeEntrada=true;
  FVars->Insere(tvar);
  eVariaveis->Text="";
  }
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bRemoveEntradaClick(TObject *Sender)
{
int posicao;
if(lbListaDeVariaveis->ItemIndex==-1)
  return;
posicao=lbListaDeVariaveis->ItemIndex;
delete FVars->Remove(lbListaDeVariaveis->Items->Strings[posicao]);
lbListaDeVariaveis->Items->Delete(posicao);
if(lbListaDeVariaveis->Items->Count>posicao)
  lbListaDeVariaveis->ItemIndex=posicao;
else
  lbListaDeVariaveis->ItemIndex=posicao-1;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::mDescricaoOnChange(TObject *Sender)
{
equipamento->Ajuda=mDescricao->Lines->Text;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::tsVariaveisOnShow(TObject *Sender)
{
int i;
lbNomesVariaveis->Clear();
for(i=0;i<FVars->Numero;i++)
   lbNomesVariaveis->Items->Add(FVars->Nomes[i]);
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::lbNomesVariaveisOnClick(TObject *Sender)
{
int indice;
indice=lbNomesVariaveis->ItemIndex;
if(indice==-1)
  {
  VariavelEmEdicao=NULL;
  return;
  }
VariavelEmEdicao=FVars->Variavel(lbNomesVariaveis->Items->Strings[indice]);
if(!VariavelEmEdicao)
  return;
eValor->Text=VariavelEmEdicao->Valor;
mInfoVariavel->Lines->Text=VariavelEmEdicao->Info;
eValor->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::eValorOnChange(TObject *Sender)
{
if(!VariavelEmEdicao)
  return;
try {
 VariavelEmEdicao->Valor=eValor->Text.ToDouble();
 }
 catch(EConvertError& ece)
   {
   // Valor invalido. tenta fazer alguma coisa!
   }
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::eValorOnKeyPress(TObject *Sender,
      char &Key)
{
if(!VariavelEmEdicao)
  Key='\0';
if(Key==13)
  {
  Key='\0';
  mInfoVariavel->SetFocus();
  return;
  }
if(!isdigit(Key) && Key!=DecimalSeparator && toupper(Key)!='E' && Key!='+' &&\
   Key!='-' && Key != 8)
   Key='\0';
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::mInfoVariavelOnKeyPress(TObject *Sender,
      char &Key)
{
if(!VariavelEmEdicao)
  Key='\0';
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::mInfoVariavelOnChange(TObject *Sender)
{
if(!VariavelEmEdicao)
  return;
VariavelEmEdicao->Info=mInfoVariavel->Lines->Text;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::lbListaDeVariaveisOnDblClick(
      TObject *Sender)
{
int indice;
indice=lbListaDeVariaveis->ItemIndex;
if(indice==-1)
  return;
pcEquipamento->ActivePageIndex=3; // tsVariaveis->SetFocus();
lbNomesVariaveis->ItemIndex=indice;
lbNomesVariaveisOnClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bNovaFuncaoClick(TObject *Sender)
{
int i=0;
TFuncao *tfunc;
tfunc=new TFuncao();
while(equipamento->Funcao("NovaFuncao"+AnsiString(i)))
  i++;
tfunc->Nome="NovaFuncao"+AnsiString(i);
equipamento->Adiciona(tfunc);
lbFuncoes->Items->Add(tfunc->Nome);
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bEditarFuncaoOnClick(TObject *Sender)
{
int indice;
TFuncao *tfunc;
indice=lbFuncoes->ItemIndex;
if(indice==-1)
  return;
tfunc=equipamento->Funcao(lbFuncoes->Items->Strings[indice]);
if(!tfunc)
  return;
EdFuncao->Editar(tfunc);
lbFuncoes->Items->Strings[indice]=tfunc->Nome;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::lbFuncoesOnDblClick(TObject *Sender)
{
bEditarFuncaoOnClick(Sender);
lbFuncoesOnClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::lbFuncoesOnClick(TObject *Sender)
{
int indice;
TFuncao *tfunc;
indice=lbFuncoes->ItemIndex;
tfunc=equipamento->Funcao(lbFuncoes->Items->Strings[indice]);
if(!tfunc)
  return;
mInfoFuncao->Lines->Text=tfunc->Ajuda;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bAbrirFuncaoDoDiscoClick(TObject *Sender)
{
 TFuncao *nova;
 int i,c;
 OpenDialog->Filter = "Arquivos de Função (*.FN)|*.FN";
 OpenDialog->Title = "Escolha uma função a carregar...";
 if(!OpenDialog->Execute())
   return;
 nova=new TFuncao();
 nova->Dono=(TObjeto*)equipamento;
 nova->Carrega(OpenDialog->FileName);
 for(i=0,c=0;i<equipamento->Numero;i++)
    if(equipamento->Funcoes[i]->Nome==nova->Nome)
      c++;
 if(c)
   {
   i=0;
   while(equipamento->Funcao(nova->Nome+AnsiString(i)))
    i++;
   nova->Nome=nova->Nome+AnsiString(i);
   }
 equipamento->Adiciona(nova);
 lbFuncoes->Items->Add(nova->Nome);
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bRemoverFuncaoClick(TObject *Sender)
{
int indice;
indice=lbFuncoes->ItemIndex;
if(indice==-1)
  return;
try{
  delete equipamento->Remove(lbFuncoes->Items->Strings[indice]);
  lbFuncoes->Items->Delete(indice);
  if(lbFuncoes->Items->Count<=indice)
    lbFuncoes->ItemIndex=indice-1;
  else
    lbFuncoes->ItemIndex=indice;
  } catch(EAccessViolation& eav)
     {
     return;
     }
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::cbArmazenamentoClick(TObject *Sender)
{
if(!cbardropping)
  return;

}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::cbArmazenamentoDrop(TObject *Sender)
{
cbardropping=true;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::cbArmazenamentoExit(TObject *Sender)
{
cbefdropping=false;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::tsModoOnShow(TObject *Sender)
{
cbEntradaDeFuncoes->Items=lbFuncoes->Items;
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::SelecionaParametro(TObject *Sender)
{
TMouse *mouse;
TStringList *lista;
TPoint p;
int i;
mouse=new TMouse();
p=mouse->CursorPos;
delete mouse;
lista=new TStringList();
for(i=0;i<FVars->Numero;i++)
   lista->Add(FVars->Nomes[i]);
EscolhaParametro->ListBox1->Items=lista;
if(p.x+EscolhaParametro->Width<Screen->Width)
  EscolhaParametro->Left=p.x;
else
  EscolhaParametro->Left=Screen->Width-EscolhaParametro->Width;
if(p.y+EscolhaParametro->Height<Screen->Height)
  EscolhaParametro->Top=p.y;
else
  EscolhaParametro->Top=Screen->Height-EscolhaParametro->Height;
EscolhaParametro->ShowModal();
lbParametros->Items->Strings[lbParametros->ItemIndex]=\
                      EscolhaParametro->ListBox1->Items->Strings\
                        [EscolhaParametro->ListBox1->ItemIndex];
delete lista;
}
//---------------------------------------------------------------------------


void __fastcall TEdEquipamento::eArmazenamentoKeyPress(TObject *Sender,
      char &Key)
{
TVariavel *tvar;
if(Key==13)
  {
  Key='\0';
  if(eArmazenamento->Text!="")
    if(!FVars->Variavel(eArmazenamento->Text))
      {
      tvar=new TVariavel();
      tvar->Nome=eArmazenamento->Text;
      tvar->DeEntrada=false;
      FVars->Insere(tvar);
      }
  }
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bIncluirClick(TObject *Sender)
{
int i;
AnsiString item;
Comando *cm;
TVariavel *tvar;
cm=new Comando;
if(eArmazenamento->Text=="")
  return;
if(!FVars->Variavel(eArmazenamento->Text))
  {
  tvar=new TVariavel();
  tvar->Nome=eArmazenamento->Text;
  tvar->DeEntrada=false;
  FVars->Insere(tvar);
  }

for(i=0;i<lbParametros->Items->Count;i++)
   if(*(lbParametros->Items->Strings[i].c_str())=='[')
     return;
item=eArmazenamento->Text+AnsiString("=")+cbEntradaDeFuncoes->Text+\
     AnsiString("(");
cm->Funcao=cbEntradaDeFuncoes->Text;
cm->Variavel=eArmazenamento->Text;
cm->Parametros="";
for(i=0;i<lbParametros->Items->Count;i++)
   {
   if(i)
     {
     item+=";";
     cm->Parametros+=";";
     }
   item+=lbParametros->Items->Strings[i];
   cm->Parametros+=lbParametros->Items->Strings[i];
   }
item+=AnsiString(")");
lbOrdem->Items->Add(item);
equipamento->AdicionaComando(cm);
}

//---------------------------------------------------------------------------
void __fastcall TEdEquipamento::bRemoverClick(TObject *Sender)
{
int item;
item=lbOrdem->ItemIndex;
if(item<0)
  return;
delete equipamento->RemoveComando(item);
lbOrdem->Items->Delete(item);
if(lbOrdem->Items->Count<=item)
    lbOrdem->ItemIndex=item-1;
  else
    lbOrdem->ItemIndex=item;
}

//---------------------------------------------------------------------------
void __fastcall TEdEquipamento::bSobeClick(TObject *Sender)
{
int lbindice;
// Verifica se tem alguma variavel escolhida.
lbindice=lbOrdem->ItemIndex;
if(lbindice<=0)
  return;
lbOrdem->Items->Exchange(lbindice,lbindice-1);
equipamento->TrocaComandos(lbindice,lbindice-1);
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::bDesceClick(TObject *Sender)
{
int lbindice;
// Verifica se tem alguma variavel escolhida.
lbindice=lbOrdem->ItemIndex;
if(lbindice==lbOrdem->Items->Count-1)
  return;
lbOrdem->Items->Exchange(lbindice,lbindice+1);
equipamento->TrocaComandos(lbindice,lbindice+1);
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::miAtribuirImagemClick(TObject *Sender)
{
bEscolherFiguraClick(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TEdEquipamento::tsFuncoesOnShow(TObject *Sender)
{
int i;
AnsiString tmp;
if(equipamento->Numero && !lbFuncoes->Items->Count)
  for(i=0;i<equipamento->Numero;i++)
     lbFuncoes->Items->Add(equipamento->Nomes[i]);
if(FVars->NumeroDeParametros && !lbListaDeVariaveis->Items->Count)
  for(i=0;i<FVars->NumeroDeParametros;i++)
     lbListaDeVariaveis->Items->Add(FVars->Nomes[i]);
if(equipamento->NumeroDeComandos && !lbOrdem->Items->Count)
  for(i=0;i<equipamento->NumeroDeComandos;i++)
     {
     tmp=equipamento->Comandos[i]->Variavel;
     tmp+="=";
     tmp+=equipamento->Comandos[i]->Funcao;
     tmp+="(";
     tmp+=equipamento->Comandos[i]->Parametros;
     tmp+=");";
     lbOrdem->Items->Add(tmp);
     }
}
//---------------------------------------------------------------------------
bool __fastcall TEdEquipamento::Editar(TEquipamento *eEqui)
{
bool ret=true;
TEquipamento *backup1,*backup2;
backup1=equipamento;
backup2=new TEquipamento();
*backup2=*eEqui;
equipamento=eEqui;
eNome->Text=equipamento->Nome;
mDescricao->Lines->Text=equipamento->Ajuda;
iFoto->Picture=equipamento->Foto;
pcEquipamento->ActivePageIndex=0;
FVars=eEqui->ListaDeVariaveis;
if(ShowModal()!=mrOk)
  {
  *eEqui=*backup2;
  ret=false;
  }
delete backup2;
equipamento=backup1;
FVars=equipamento->ListaDeVariaveis;
return ret;
}

void __fastcall TEdEquipamento::miSairClick(TObject *Sender)
{
this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TEdEquipamento::miTopicosClick(TObject *Sender)
{
Application->HelpCommand(HELP_CONTENTS, 0);        
}
//---------------------------------------------------------------------------

