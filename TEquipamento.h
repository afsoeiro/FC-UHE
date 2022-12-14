#include "TLista.h"
//---------------------------------------------------------------------------
#ifndef TEquipamentoH
#define TEquipamentoH
struct COMANDO {
	AnsiString Funcao;
	AnsiString Parametros;
	AnsiString Variavel;
	bool __fastcall Salva(int fHandle)
	  {
	  int dado;
	  char *buffer;
	  dado=Funcao.Length()+1;
          FileWrite(fHandle,&dado,sizeof(dado));
          buffer=Funcao.c_str();
          FileWrite(fHandle,buffer,dado);
	  dado=Parametros.Length()+1;
          FileWrite(fHandle,&dado,sizeof(dado));
          buffer=Parametros.c_str();
          FileWrite(fHandle,buffer,dado);
	  dado=Variavel.Length()+1;
          FileWrite(fHandle,&dado,sizeof(dado));
          buffer=Variavel.c_str();
          FileWrite(fHandle,buffer,dado);
          return true;
	  }
	bool __fastcall Carrega(int fHandle)
	  {
	  int dado;
	  char *buffer;       
	  FileRead(fHandle,&dado,sizeof(dado));
	  buffer=new char[dado];
          FileRead(fHandle,buffer,dado);
          Funcao=buffer;
          delete[] buffer;

	  FileRead(fHandle,&dado,sizeof(dado));
	  buffer=new char[dado];
          FileRead(fHandle,buffer,dado);
          Parametros=buffer;
          delete[] buffer;

	  FileRead(fHandle,&dado,sizeof(dado));
	  buffer=new char[dado];
          FileRead(fHandle,buffer,dado);
          Variavel=buffer;
          delete[] buffer;

          return true;
	  }
};
typedef struct COMANDO Comando;

//---------------------------------------------------------------------------
class TEquipamento : public TLista
{
private:
TPicture *FFoto;
class TListaDeVariaveis *FVars;
TList *lComandos;
bool FStandAlone;
AnsiString FAjuda;
class TFuncao* __fastcall GetFuncoes(int eIndice);
void __fastcall SetFuncoes(int eIndice, class TFuncao* eFuncao);
void __fastcall SetFoto(TPicture* eFoto);
TPicture* __fastcall GetFoto(void);
class TListaDeVariaveis* __fastcall GetListaDeVariaveis(void);
void __fastcall SetListaDeVariaveis(class TListaDeVariaveis* eLista);
double* BuscaParametros(AnsiString eParms);
Comando* __fastcall FGetComandos(int Indice);
int __fastcall FGetNumeroDeComandos(void);
protected:
public:
__fastcall TEquipamento(void);
__fastcall ~TEquipamento(void);
bool __fastcall Adiciona(class TFuncao *equ);
TFuncao* __fastcall Remove(AnsiString nome);
TFuncao* __fastcall Remove(int numero);
void __fastcall AdicionaComando(Comando *eComando);
Comando* __fastcall RemoveComando(Comando *eComando);
Comando* __fastcall RemoveComando(int Indice);
void __fastcall TrocaComandos(int Indice1, int Indice2);

void __fastcall AdicionaComando(AnsiString Funcao, AnsiString Parametros,\
                                              AnsiString Variavel);
class TFuncao* __fastcall Funcao(AnsiString nome);
bool __fastcall Salva(AnsiString arquivo);
bool __fastcall Salva(int fHandle);
bool __fastcall Carrega(AnsiString arquivo);
bool __fastcall Carrega(int fHandle);
TMinhaException(EArquivoInvalido,"O arquivo a ser carregado é inválido!");
void __fastcall CarregaFoto(AnsiString eFoto);
bool __fastcall Resolve(void);
__property TPicture* Foto = {read=GetFoto, write=SetFoto};
__property AnsiString Ajuda= {read=FAjuda, write=FAjuda};
__property Comando* Comandos[int Indice]= {read=FGetComandos};
__property int NumeroDeComandos= {read=FGetNumeroDeComandos};
__property class TFuncao* Funcoes[int Indice] = {read=GetFuncoes,
                                                   write=SetFuncoes};
__property class TListaDeVariaveis* ListaDeVariaveis = {read=GetListaDeVariaveis,
                                                 write=SetListaDeVariaveis};
TEquipamento& operator = (TEquipamento& src);
};

#endif
