//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Defines.h"
#include "TSolucao.h"
#include "TFuncao.h"
#include "Clipbrd.hpp"
#include "TVariavel.h"
#include "TEquipamento.h"
#include "TEntradaDeDados.h"
#include "TListaDeVariaveis.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
class TListaDeVariaveis* __fastcall TEquipamento::GetListaDeVariaveis(void)
{
return FVars;
}
void __fastcall TEquipamento::SetListaDeVariaveis(class TListaDeVariaveis* eLista)
{
FVars=eLista;
}
void __fastcall TEquipamento::SetFuncoes(int eIndice, TFuncao* eFuncao)
{
if(eIndice>=0 && eIndice<Numero)
  Objetos[eIndice]=(TObjeto*)eFuncao;
}
TFuncao* __fastcall TEquipamento::GetFuncoes(int eIndice)
{
TFuncao *ret;
ret=(TFuncao*)Objetos[eIndice];
return ret;
}
void __fastcall TEquipamento::SetFoto(TPicture* eFoto)
{
if(FFoto)
  delete FFoto;
FFoto=eFoto;
}
TPicture* __fastcall TEquipamento::GetFoto(void)
{
return FFoto;
}
void __fastcall TEquipamento::CarregaFoto(AnsiString eFoto)
{
if(FFoto)
  delete FFoto;
try
  {
  FFoto=new TPicture();
  FFoto->LoadFromFile(eFoto);
  }
catch(...)
  {
  ShowMessage("A fotografia do equipamento nao pode ser carregada.");
  if(FFoto)
    delete FFoto;
  }
}

__fastcall TEquipamento::TEquipamento(void):TLista()
{
FFoto=NULL;
FVars=new TListaDeVariaveis();
Tipo=TP_EQUIPAMENTO;
FStandAlone=false;
lComandos=new TList();
}

__fastcall TEquipamento::~TEquipamento(void)
{
SAFEDEL(FFoto);
while(lComandos->Count)
  delete (Comando*)(lComandos->Extract(lComandos->Items[0]));
SAFEDEL(lComandos);
SAFEDEL(FVars);
}
bool __fastcall TEquipamento::Adiciona(class TFuncao *func)
{
func->Dono=(TObjeto*)this;
return Insere((TObjeto*)func);
}

TFuncao* __fastcall TEquipamento::Remove(AnsiString nome)
{
TFuncao* ret;
ret=(TFuncao*)(TLista::Remove(nome));
ret->Dono=NULL;
return ret;
}

TFuncao* __fastcall TEquipamento::Remove(int numero)
{
TFuncao* ret;
ret=(TFuncao*)(TLista::Remove(Nomes[numero]));
ret->Dono=NULL;
return ret;
}

void __fastcall TEquipamento::AdicionaComando(Comando *eComando)
{
lComandos->Add(eComando);
}

void __fastcall TEquipamento::AdicionaComando(AnsiString Funcao,\
                                              AnsiString Parametros,\
                                              AnsiString Variavel)
{
Comando *tc;
tc=new Comando;
tc->Funcao=Funcao;
tc->Parametros=Parametros;
tc->Variavel=Variavel;
AdicionaComando(tc);
}
Comando* __fastcall TEquipamento::RemoveComando(int Indice)
{
if(Indice<0 || Indice>=lComandos->Count)
  return NULL;
return RemoveComando((Comando*)lComandos->Items[Indice]);
}
Comando* __fastcall TEquipamento::FGetComandos(int Indice)
{
if(Indice<0 || Indice>=lComandos->Count)
  return NULL;
return (Comando*)lComandos->Items[Indice];
}
void __fastcall TEquipamento::TrocaComandos(int Indice1, int Indice2)
{
if(Indice1<0 || Indice1>=lComandos->Count || Indice2<0 ||\
   Indice2>=lComandos->Count || Indice1==Indice2)
  return;
lComandos->Exchange(Indice1,Indice2);
}
int __fastcall TEquipamento::FGetNumeroDeComandos(void)
{
return lComandos->Count;
}

Comando* __fastcall TEquipamento::RemoveComando(Comando *eComando)
{
return (Comando*)lComandos->Extract(eComando);
}

TFuncao* __fastcall TEquipamento::Funcao(AnsiString nome)
{
TFuncao *ret;
ret=(TFuncao*)Objetos[Indice(nome)];
return ret;
}
bool __fastcall TEquipamento::Salva(AnsiString arquivo)
{
int fHandle;
try {
    fHandle=FileCreate(arquivo);
    FStandAlone=true;
    Salva(fHandle);
    FStandAlone=false;
    FileClose(fHandle);
    } catch(...)
           {
           ShowMessage("Problemas no salvamento de um equipamento.");
           return false;
           }
return true;
}

bool __fastcall TEquipamento::Salva(int fHandle)
{
int i;
int dado=ID_EQUIPAMENTO;
THandleStream *arquivo;
char *buffer;
try {
    FileWrite(fHandle,&dado,sizeof(dado));
    dado=Nome.Length()+1;
    FileWrite(fHandle,&dado,sizeof(dado));
    buffer=Nome.c_str();
    FileWrite(fHandle,buffer,dado);
    if(FFoto)
      {
      if(FFoto->Bitmap)
        {
        dado=1; // Tem foto.
        FileWrite(fHandle,&dado,sizeof(dado));
        arquivo=new THandleStream(fHandle);
        FFoto->Bitmap->SaveToStream(arquivo);
        delete arquivo;
        }
      }
    else
      {
      dado=0; // Não tem foto.
      FileWrite(fHandle,&dado,sizeof(dado));
      }
    dado=Numero;
    FileWrite(fHandle,&dado,sizeof(dado));
    for(i=0;i<Numero;i++)
       if(Funcoes[i])
         Funcoes[i]->Salva(fHandle);
    dado=lComandos->Count;
    FileWrite(fHandle,&dado,sizeof(dado));
    for(i=0;i<dado;i++)
       ((Comando*)lComandos->Items[i])->Salva(fHandle);
    // Agora para a lista de variaveis... Somente salva se tiver variaveis.
    dado=FVars->Numero;
    FileWrite(fHandle,&dado,sizeof(dado));
    if(dado)
      FVars->Salva(fHandle);
    dado=FAjuda.Length()+1;
    FileWrite(fHandle,&dado,sizeof(dado));
    buffer=FAjuda.c_str();
    FileWrite(fHandle,buffer,dado);
    } catch(...)
           {
           ShowMessage("Problemas no salvamento de um equipamento.");
           return false;
           }
return false;
}

bool __fastcall TEquipamento::Carrega(AnsiString arquivo)
{
int fHandle;
try {
    fHandle=FileOpen(arquivo, fmOpenRead);
    Carrega(fHandle);
    FileClose(fHandle);
    } catch(EArquivoInvalido &ArquivoInvalido)
      {
      ShowMessage("O arquivo '"+arquivo+"' não é um equipamento válido.");
      return false;
      }
return true;
}

bool __fastcall TEquipamento::Carrega(int fHandle)
{
int dado;
int i;
char *buffer;
TFuncao *func;
THandleStream *arquivo;
Comando *cmd;
while(lComandos->Count)
  delete (Comando*)lComandos->Extract(lComandos->First());
while(Numero)
  delete Remove(Nomes[0]);
try {
    FileRead(fHandle,&dado,sizeof(dado));
    if(dado!=ID_EQUIPAMENTO)
    throw EArquivoInvalido(this,"Equipamento desconhecido ou corompido.");
    while(Numero)
      delete Remove(Nomes[0]);
    FileRead(fHandle,&dado,sizeof(dado));
    buffer=new char[dado];
    FileRead(fHandle,buffer,dado);
    Nome=buffer;
    delete[] buffer;
    FileRead(fHandle,&dado,sizeof(dado));
    if(dado)
      {
      if(!FFoto)
        FFoto=new TPicture();
      arquivo=new THandleStream(fHandle);
      FFoto->Bitmap->LoadFromStream(arquivo);
      delete arquivo;
      }
    FileRead(fHandle,&dado,sizeof(dado));
    for(i=0;i<dado;i++)
       {
       func=new TFuncao(this);
//       tequ->BancoDeVariaveis=this->BancoDeVariaveis;
       func->Carrega(fHandle);
       Adiciona(func);
       }
    FileRead(fHandle,&dado,sizeof(dado));
    for(i=0;i<dado;i++)
       {
       cmd=new Comando;
       cmd->Carrega(fHandle);
       lComandos->Add(cmd);
       }
    FileRead(fHandle,&dado,sizeof(dado));
    if(dado)
      FVars->Carrega(fHandle);
    FileRead(fHandle,&dado,sizeof(dado));
    buffer=new char[dado];
    FileRead(fHandle,buffer,dado);
    FAjuda=buffer;
    delete[] buffer;
    }
 catch(...)
      {
      return false;
      }
return true;
}

bool __fastcall TEquipamento::Resolve(void)
{
int i,j;
AnsiString msg;
AnsiString unidade;
double *parms;
TVariavel *tvar;
char *tvarinfo;
// Solução: O usuário, no editor de equipamentos, vai
//   escolher qual a ordem de execução da solução, através de alguns drop down
//   ComboBoxes, no estilo:
//   . Requisitar entrada de dados das variaveis: [escolha de algumas]
//   . Resolver função [escolha] usando como parametros [multipla escolha]

if(!lComandos)
  {
  ShowMessage("Nada a resolver...");
  return false;
  }
msg="{\\rtf1\\ansi\\ansicpg1252\\deff0\\deflang1046{\\fonttbl{\\f0\\fnil\\fchar"
    "set0 Times New Roman;}}";
msg+="\\fs32\\qc Solução de ";
msg+=Nome;
msg+=":\\par\\fs24\\qj ";
/* Pra botar figura:
 {\*\shppict{\pict\[emfblip | pngblip | jpegblip | macpict | pmmetafile
                            | wmetafile | dibitmap | wbitmap] [Dados em hexa]}}
*/
if(Foto)
  {
  TMetafile *m;
  TMetafileCanvas *mc;
  TStringStream *stream;
  char *buffer;
  char tbuf[3];
  int tamanho;
  m=new TMetafile();
  m->Height=Foto->Graphic->Height;
  m->Width=Foto->Graphic->Width;
  mc=new TMetafileCanvas(m,0);
  mc->Draw(0,0,Foto->Graphic);
  delete mc;
  stream=new TStringStream("");
  m->SaveToStream(stream);
  delete m;
  buffer=(char*)malloc(tamanho=(stream->Size));
  memcpy(buffer,stream->DataString.c_str(),tamanho);
  msg+="\\qc{\\*\\shppict{\\pict\\emfblip\n";
  tbuf[2]='\0';
  for(i=0;i<tamanho;i++)
     {
     if(((unsigned char)buffer[i]%16)>9)
       tbuf[1]='a'+((unsigned char)buffer[i]%16)-10;
     else
       tbuf[1]='0'+((unsigned char)buffer[i]%16);
     if(((unsigned char)buffer[i]/16)>9)
       tbuf[0]='A'+((unsigned char)buffer[i]/16)-10;
     else
       tbuf[0]='0'+((unsigned char)buffer[i]/16);
     msg+=AnsiString(tbuf);
     }
  msg+="}}\\par\\qj ";
  }
if(Ajuda!="")
  {
  msg+=Ajuda;
  msg+="\\par\\qj ";
  }

// Resolvendo o equipamento segundo os comandos:
for(i=0;i<lComandos->Count;i++)
  {
  if(!lComandos->Items[i] || !Funcao(((Comando*)(lComandos->Items[i]))->Funcao))
    continue;
  parms=BuscaParametros(((Comando*)(lComandos->Items[i]))->Parametros);
  if(!parms)
    {
    ShowMessage("Sintaxe dos parametros invalida ou parametros"\
                " inexistentes para a função "+((Comando*)(lComandos->Items[i]))\
                ->Funcao+".");
    continue;
    }
  if(!FVars->Variavel(((Comando*)(lComandos->Items[i]))->Variavel))
    {
    tvar=new TVariavel();
    tvar->Nome=((Comando*)(lComandos->Items[i]))->Variavel;
    tvar->DeEntrada=false;
    FVars->Insere(tvar);
    }
  else
    tvar=FVars->Variavel(((Comando*)(lComandos->Items[i]))->Variavel);
  tvar->Valor=Funcao(((Comando*)(lComandos->Items[i]))->Funcao)->Calcula(parms);
  tvarinfo=tvar->Info.c_str();
  if(tvarinfo[0]!='\0')
    {
    j=0;
    unidade="";
    if(tvarinfo[j]=='[')
      for(;tvarinfo[j]!=']' && tvarinfo[j]!='\0';j++)
         if(tvarinfo[j]!='[')
           unidade+=tvarinfo[j];
    j++;
    msg+=(tvarinfo+j);
    msg+="\\par ";
    }
  msg+=tvar->Nome+" = "+AnsiString(tvar->Valor)+" "+unidade+".\\par \\par ";

  delete[] parms;
  }
msg+="}";
Solucao->Mostra(msg);
return true;
}
double* TEquipamento::BuscaParametros(AnsiString eParms)
{
// eParms vem separado por ponto-e-virgula
char *buffer;
double *ret;
AnsiString tmp;
int i,c,total;
buffer=eParms.c_str();
if(!isalpha(buffer[0]))
  return NULL;
for(i=0,c=1;buffer[i]!='\0';i++)
   {
   if(buffer[i]==';')
     c++;
   }
ret=new double[c+1];
ret[0]=(double)c;
total=c;
tmp="";
for(i=0,c=0;c<total;i++)
   if(buffer[i]==';' || buffer[i]=='\0')
     {
     ret[++c]=FVars->Valor(tmp);
     tmp="";
     }
   else
     tmp+=buffer[i];
return ret;
}

TEquipamento& TEquipamento::operator = (TEquipamento& src)
{
int i;
if(this==&src)
   return *this;
Nome=src.Nome;
*FVars=*(src.FVars);
FStandAlone=src.FStandAlone;
FAjuda=src.FAjuda;
while(Numero)
  delete(this->Remove(0));
if(src.Numero)
  for(i=0;i<src.Numero;i++)
    this->Adiciona(new TFuncao(src.Funcoes[i]));
while(lComandos->Count)
  delete(Comando*)lComandos->Extract(lComandos->First());
if(src.NumeroDeComandos)
  for(i=0;i<src.NumeroDeComandos;i++)
    this->lComandos->Add(new Comando(*(src.Comandos[i])));
return *this;
}
