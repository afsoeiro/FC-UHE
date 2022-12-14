//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "TFuncao.h"
#include "Defines.h"
#include "TVariavel.h"
#include "TEdFuncao.h"
#include "TEquipamento.h"
#include "TEntradaDeDados.h"
#include "TEntradaDePonto.h"
#include "TListaDeVariaveis.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEdFuncao *EdFuncao;
//---------------------------------------------------------------------------
__fastcall TEdFuncao::TEdFuncao(TComponent* Owner)
  : TForm(Owner)
{
funcao=new TFuncao();
VariavelEmEdicao=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::cbVariavelPrincipalGetFocus(TObject *Sender)
{
if(MudouExpressao)
  {
  // Busca as variaveis da expressao e enche cbVariavelPrincipal.
  MudouExpressao=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::FormActivate(TObject *Sender)
{
this->Resize();
// Vai ocorrer quando a Form ganhar foco.
if(MudouExpressao)
  // Verificar se a form ganhou foco focalizando o combobox desejado.
  if(this->ActiveControl->Name=="cbVariavelPrincipal")
    cbVariavelPrincipalGetFocus(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::FormCreate(TObject *Sender)
{

this->sgExpressoes->Cells[0][0]="Expressao";
this->sgExpressoes->Cells[1][0]="Intervalo";
this->sgExpressoes->Cells[1][1]="(-INF;+INF)";
this->lValorVariavel->Caption="Valor:";
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::FormDestroy(TObject *Sender)
{
SAFEDEL(funcao);
}
//---------------------------------------------------------------------------


void __fastcall TEdFuncao::sgExpressoesOnExit(TObject *Sender)
{
AtualizaExpressoes();
// Fazer o processamento do sgExpressao, verificando se as expressoes sao
// válidas, e se os intervalos tambem sao validos.
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::FormLostFocus(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::AtualizaExpressoes(void)
{
// Fazer o processamento do sgExpressao, verificando se as expressoes sao
// válidas, e se os intervalos tambem sao validos.
int i;
int j;
TExpressao *texp;
while(funcao->Numero)
  delete funcao->Remove(0);
for(i=1,j=0;i<sgExpressoes->RowCount;i++)
   {
   texp=new TExpressao();
   texp->Texto=sgExpressoes->Cells[0][i];
   if(!funcao->IntervaloOk(sgExpressoes->Cells[1][i],texp->Limites,\
      texp->Extremos)|| !funcao->EValida(texp))
     {
     delete texp;
     continue;
     }
   else
     {
     texp->Nome="Expressao"+AnsiString(j++);
     funcao->Adiciona(texp);
     }
   }
funcao->IdentificaVars();
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::bAdicionarExpressaoClick(TObject *Sender)
{
sgExpressoes->RowCount++;
sgExpressoes->Cells[1][sgExpressoes->RowCount-1]="(-INF;+INF)";
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::bRemoverExpressaoClick(TObject *Sender)
{
int i;
if(sgExpressoes->RowCount==2)
  {
  ShowMessage("A função dada necessita de no mínimo uma expressão associada.");
  return;
  }
if(sgExpressoes->Row>0)
  {
  for(i=sgExpressoes->Row;i<sgExpressoes->RowCount-1;i++)
     {
     sgExpressoes->Cells[0][i]=sgExpressoes->Cells[0][i+1];
     sgExpressoes->Cells[1][i]=sgExpressoes->Cells[1][i+1];
     }
  sgExpressoes->Cells[0][i]="";
  sgExpressoes->Cells[1][i]="";
  sgExpressoes->RowCount--;
  }
sgExpressoes->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::eNomeDaFuncaoOnChange(TObject *Sender)
{
funcao->Nome=eNomeDaFuncao->Text;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::eNomeDaFuncaoOnKeyPress(TObject *Sender,
      char &Key)
{
if(Key=='\b')
  return;
if(!isalnum(Key) || (!eNomeDaFuncao->SelStart && isdigit(Key)))
  Key='\0';
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::pOkCancelaResize(TObject *Sender)
{
int esquerda;
esquerda=(pOkCancela->Width-(bCancela->Width+bOk->Width+64))/2;
bOk->Left=esquerda;
bCancela->Left=esquerda+bOk->Width+64;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::tsInformacoesGeraisOnResize(TObject *Sender)
{
int esquerda;
eNomeDaFuncao->Width=gbNome->Width-16;
sgExpressoes->Width=gbExpressoes->Width-16;
bAdicionarExpressao->Top=gbExpressoes->Height-32;
bRemoverExpressao->Top=gbExpressoes->Height-32;
sgExpressoes->Height=bRemoverExpressao->Top-20;
esquerda=(gbExpressoes->Width-(bAdicionarExpressao->Width+bRemoverExpressao\
                               ->Width+14))/2;
bAdicionarExpressao->Left=esquerda;
bRemoverExpressao->Left=esquerda+bAdicionarExpressao->Width+14;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::tsParametrosOnResize(TObject *Sender)
{
gbParametros->Width=tsParametros->Width/2-2;
gbVariaveisInternas->Width=gbParametros->Width;
gbVariaveisInternas->Left=gbParametros->Width+5;
gbParametros->Height=tsParametros->Height;
gbVariaveisInternas->Height=tsParametros->Height;
lbVariaveisInternas->Width=gbVariaveisInternas->Width-20;
bExigirVariavel->Width=gbVariaveisInternas->Width-20;
bExigirVariavel->Top=gbVariaveisInternas->Height-32;
lbVariaveisInternas->Height=bExigirVariavel->Top-28;
bDispensarVariavel->Width=gbParametros->Width-20;
bDispensarVariavel->Top=gbParametros->Height-32;
lbParametros->Height=bDispensarVariavel->Top-28;
bSobe->Left=gbParametros->Width-32;
bDesce->Left=gbParametros->Width-32;
lbParametros->Width=bSobe->Left-16;
bSobe->Top=lbParametros->Top;
bSobe->Height=lbParametros->Height/2-8;
bDesce->Top=bSobe->Top+bSobe->Height+16;
bDesce->Height=bSobe->Height;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::tsVariaveisInternasOnResize(TObject *Sender)
{
gbNomesVariaveis->Width=tsVariaveisInternas->Width/2-2;
gbInfoVariaveis->Width=gbNomesVariaveis->Width;
gbInfoVariaveis->Left=gbNomesVariaveis->Width+5;
gbNomesVariaveis->Height=tsVariaveisInternas->Height;
gbInfoVariaveis->Height=tsVariaveisInternas->Height;
lbNomesVariaveis->Height=gbNomesVariaveis->Height-30;
lbNomesVariaveis->Width=gbNomesVariaveis->Width-20;
gbDescricaoDaVariavel->Height=gbInfoVariaveis->Height-68;
gbDescricaoDaVariavel->Width=gbInfoVariaveis->Width-15;
mDescricao->Height=gbDescricaoDaVariavel->Height-32;
mDescricao->Width=gbDescricaoDaVariavel->Width-15;
eValor->Left=lValorVariavel->Left+lValorVariavel->Width+5;
eValor->Width=gbInfoVariaveis->Width-eValor->Left-10;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::tsParametrosOnShow(TObject *Sender)
{
lbParametros->Clear();
lbVariaveisInternas->Clear();
EncheTsParametros();
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::EncheTsParametros(void)
{
int i;
if(!funcao->NumeroDeVariaveis)
  return;
FVars=funcao->ListaDeVariaveis;
if(!FVars)
  return;
for(i=0;i<FVars->Numero;i++)
 {
 if(FVars->Variaveis[i])
   if(FVars->Variaveis[i]->DeEntrada)
     lbParametros->Items->Add(FVars->Nomes[i]);
   else
     lbVariaveisInternas->Items->Add(FVars->Nomes[i]);
 }
}
void __fastcall TEdFuncao::tsVariaveisInternasOnShow(TObject *Sender)
{
lbNomesVariaveis->Clear();
eValor->Text="";
mDescricao->Clear();
EncheTsVariaveisInternas();
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::EncheTsVariaveisInternas(void)
{
int i;
if(!funcao->NumeroDeVariaveis)
  return;
FVars=funcao->ListaDeVariaveis;
if(!FVars)
  return;
for(i=0;i<FVars->Numero;i++)
 if(FVars->Variaveis[i])
   lbNomesVariaveis->Items->Add(FVars->Nomes[i]);
}

void __fastcall TEdFuncao::bSobeClick(TObject *Sender)
{
int lbindice, indice1, indice2;
FVars=funcao->ListaDeVariaveis;
// Verifica se tem alguma variavel escolhida.
lbindice=lbParametros->ItemIndex;
if(lbindice<=0)
  return;
// Troca com a que esta em cima, tanto na lista quanto no listbox.
indice1=FVars->Indice(lbParametros->Items->Strings[lbindice]);
indice2=FVars->Indice(lbParametros->Items->Strings[lbindice-1]);
FVars->Troca(indice1,indice2);
RefreshTsParametros();
lbParametros->ItemIndex=lbindice-1;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::bDesceClick(TObject *Sender)
{
int lbindice, indice1, indice2;
FVars=funcao->ListaDeVariaveis;
// Verifica se tem alguma variavel escolhida.
lbindice=lbParametros->ItemIndex;
if(lbindice<0 || lbindice==lbParametros->Items->Count-1)
  return;
// Troca com a que esta em cima, tanto na lista quanto no listbox.
indice1=FVars->Indice(lbParametros->Items->Strings[lbindice]);
indice2=FVars->Indice(lbParametros->Items->Strings[lbindice+1]);
FVars->Troca(indice1,indice2);
RefreshTsParametros();
lbParametros->ItemIndex=lbindice+1;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::bDispensarVariavelClick(TObject *Sender)
{
TVariavel *tvar;
FVars=funcao->ListaDeVariaveis;
int posicao;
// verifica a variável escolhida.
if(lbParametros->ItemIndex==-1)
  return;
tvar=FVars->Variavel(lbParametros->Items->Strings[lbParametros->ItemIndex]);
posicao=lbParametros->ItemIndex;
if(tvar)
  tvar->DeEntrada=false;
RefreshTsParametros();
if(lbParametros->Items->Count<=posicao)
  lbParametros->ItemIndex=lbParametros->Items->Count-1;
else
  lbParametros->ItemIndex=posicao;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::bExigirVariavelClick(TObject *Sender)
{
// verifica a variável escolhida.
TVariavel *tvar;
FVars=funcao->ListaDeVariaveis;
int posicao;
// verifica a variável escolhida.
if(lbVariaveisInternas->ItemIndex==-1)
  return;
tvar=FVars->Variavel(lbVariaveisInternas->Items->Strings[lbVariaveisInternas\
                                                                  ->ItemIndex]);
posicao=lbVariaveisInternas->ItemIndex;
if(tvar)
  tvar->DeEntrada=true;
RefreshTsParametros();
if(lbVariaveisInternas->Items->Count<=posicao)
  lbVariaveisInternas->ItemIndex=lbVariaveisInternas->Items->Count-1;
else
  lbVariaveisInternas->ItemIndex=posicao;
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::RefreshTsParametros(void)
{
lbParametros->Clear();
lbVariaveisInternas->Clear();
EncheTsParametros();
}
void __fastcall TEdFuncao::lbNomesVariaveisClick(TObject *Sender)
{
// Ve qual a variavel selecionada e coloca em um valor TVar; Este valor vai ser
// diretamente modificado pelo onchange dos campos.
int lbindice;
FVars=funcao->ListaDeVariaveis;
// Verifica se tem alguma variavel escolhida.
lbindice=lbNomesVariaveis->ItemIndex;
VariavelEmEdicao=FVars->Variavel(lbNomesVariaveis->Items->Strings[lbindice]);
if(VariavelEmEdicao)
  {
  eValor->Text=VariavelEmEdicao->Valor;
  mDescricao->Text=VariavelEmEdicao->Info;
  eValor->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::mDescricaoOnChange(TObject *Sender)
{
if(VariavelEmEdicao)
  VariavelEmEdicao->Info=mDescricao->Text;
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::eValorOnExit(TObject *Sender)
{
if(lbNomesVariaveis->ItemIndex!=-1)
  try
   {
   eValor->Text.ToDouble();
   }
  catch (EConvertError& Erro)
    {
    ShowMessage("Atenção:\nFavor verificar os valores digitados e se as casas "\
                "decimais estão separadas por vírgula.");
    tsVariaveisInternas->SetFocus();
    eValor->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TEdFuncao::eValorOnChange(TObject *Sender)
{
if(VariavelEmEdicao)
  try
   {
   VariavelEmEdicao->Valor=eValor->Text.ToDouble();
   }
  catch (EConvertError& Erro)
    {
    }
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::tsVariaveisInternasOnExit(TObject *Sender)
{
lbNomesVariaveis->ItemIndex=-1;
VariavelEmEdicao=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::miCalcularClick(TObject *Sender)
{
int i,j;
int numero;
double *parms;
double resultado;
FVars=funcao->ListaDeVariaveis;
if(FVars)
  {
  numero=FVars->NumeroDeParametros;
  if(numero)
    EntradaDeDados->PegaLista(FVars);
  parms=new double[numero+1];
  parms[0]=(double)numero;
  for(i=0,j=1;i<FVars->Numero;i++)
    if(FVars->Variaveis[i]->DeEntrada)
      parms[j++]=FVars->Variaveis[i]->Valor;
  }
else
  {
  parms=new double[1];
  *parms=0;
  }
resultado=funcao->Calcula(parms);
delete[] parms;
ShowMessage(resultado);
}
//---------------------------------------------------------------------------


void __fastcall TEdFuncao::miAbrirClick(TObject *Sender)
{
if(!OpenDialog1->Execute())
  return;
if(!funcao->Carrega(OpenDialog1->FileName))
  return;
RefreshTsGeral();
tsInformacoesGerais->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::RefreshTsGeral(void)
{
int i;
AnsiString Dominio;
if(funcao)
  {
  eNomeDaFuncao->Text=funcao->Nome;
  if(funcao->Numero)
    {
    sgExpressoes->RowCount=1;
    for(i=0;i<funcao->Numero;i++)
       {
       sgExpressoes->RowCount++;
       if(funcao->Expressoes[i])
         {
         Dominio="";
         sgExpressoes->Cells[0][i+1]=funcao->Expressoes[i]->Texto;
         if(funcao->Expressoes[i]->Extremos[0])
           Dominio+="[";
         else
           Dominio+="(";
         Dominio+=AnsiString(funcao->Expressoes[i]->Limites[0]);
         Dominio+=";";
         Dominio+=AnsiString(funcao->Expressoes[i]->Limites[1]);
         if(funcao->Expressoes[i]->Extremos[1])
           Dominio+="]";
         else
           Dominio+=")";
         sgExpressoes->Cells[1][i+1]=Dominio;
         }
       }
    }
  if(sgExpressoes->RowCount<2)
    sgExpressoes->RowCount=2;
  sgExpressoes->FixedRows=1;
  }
}
void __fastcall TEdFuncao::miSalvarClick(TObject *Sender)
{
if(!SaveDialog1->Execute())
  return;
if(!funcao->Salva(SaveDialog1->FileName))
  ShowMessage("A funcao nao foi salva.");
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::miLinearClick(TObject *Sender)
{
char **nova;
try{
 nova=EntradaDePonto->PegaReta();
 bAdicionarExpressaoClick(Sender);
 sgExpressoes->Cells[0][sgExpressoes->RowCount-1]=nova[0];
 sgExpressoes->Cells[1][sgExpressoes->RowCount-1]=nova[1];
 delete[] nova[0];
 delete[] nova[1];
 delete[] nova;
 AtualizaExpressoes();
 }
catch(EAccessViolation& eav)
 {
 ShowMessage("O segmento de reta não pôde ser definido.");
 }
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::eValorOnKeyPress(TObject *Sender, char &Key)
{
if(lbNomesVariaveis->ItemIndex==-1)
  Key='\0';

}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::tsAjudaResize(TObject *Sender)
{
mAjuda->Width=tsAjuda->ClientWidth-20;
mAjuda->Height=tsAjuda->ClientHeight-35;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::mAjudaOnChange(TObject *Sender)
{
funcao->Ajuda=mAjuda->Lines->Text;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::tsAjudaOnShow(TObject *Sender)
{
if(funcao->Ajuda!="")
  mAjuda->Lines->Text=funcao->Ajuda;
else
  {
  mAjuda->Lines->Text="Escreva aquí informações adicionais sobre a função, como"\
                      " finalidade, parâmetros requeridos, ordem destes, etc..";
  mAjuda->SelectAll();
  mAjuda->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::Editar(TFuncao *eFunc)
{
TFuncao *backup1,*backup2;
backup1=funcao;
backup2=new TFuncao();
*backup2=*eFunc;
funcao=eFunc;
pcMain->ActivePageIndex=0;
RefreshTsGeral();
if(ShowModal()!=mrOk)
  *eFunc=*backup2;
delete backup2;
funcao=backup1;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::bOkClick(TObject *Sender)
{
TEquipamento *fDono;
int i,c;
try{
fDono=(TEquipamento*)funcao->Dono;
if(fDono->Tipo!=TP_EQUIPAMENTO)
  return;
for(i=0,c=0;i<fDono->Numero;i++)
   if(fDono->Funcoes[i]->Nome==funcao->Nome)
     c++;
if(c>1)
  {
  ShowMessage("Já existe outra função pertencente ao equipamento com este nom"\
              "e.\nFavor escolher outro nome.");
  pcMain->ActivePageIndex=0;
  eNomeDaFuncao->SetFocus();
  return;
  }
} catch(EAccessViolation& eav)
  {
  return;
  }
this->ModalResult=mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::sgExpressoesOnKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
AtualizaExpressoes();
}
//---------------------------------------------------------------------------

void __fastcall TEdFuncao::sgExpressoesClick(TObject *Sender)
{
AtualizaExpressoes();
}
//---------------------------------------------------------------------------

