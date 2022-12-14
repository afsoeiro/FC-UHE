//---------------------------------------------------------------------------
#include"TLista.h"
#ifndef TListaDeVariaveisH
#define TListaDeVariaveisH
//---------------------------------------------------------------------------
class TListaDeVariaveis : public TLista
{
private:
class TVariavel* __fastcall FGetVariaveis(int Indice);
void __fastcall FSetVariaveis(int Indice, class TVariavel* Var);
int FNumeroDeParametros;
int __fastcall FGetNumeroDeParametros(void);

protected:
public:
__fastcall TListaDeVariaveis(void);
__fastcall TListaDeVariaveis(class TObjeto *eDono);
__fastcall ~TListaDeVariaveis(void);
bool __fastcall Insere(class TVariavel *eVariavel);
bool __fastcall Insere(AnsiString eNome, double eValor);
class TVariavel* __fastcall Remove(AnsiString eNome);
class TVariavel* __fastcall Variavel(AnsiString eNome);
double __fastcall Valor(AnsiString eNome);
__property class TVariavel* Variaveis[int Indice] =\
            {read=FGetVariaveis,write=FSetVariaveis};
__property int NumeroDeParametros={read=FGetNumeroDeParametros};
bool __fastcall FNecessitaDados(void);
bool __fastcall Salva(AnsiString arquivo);
bool __fastcall Salva(int fHandle);
bool __fastcall Carrega(AnsiString arquivo);
bool __fastcall Carrega(int fHandle);

TListaDeVariaveis& operator = (TListaDeVariaveis& src);
};

#endif
