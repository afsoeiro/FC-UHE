//---------------------------------------------------------------------------
#include "TLista.h"
#ifndef TBancoDeVariaveisH
#define TBancoDeVariaveisH
//---------------------------------------------------------------------------
class TBancoDeVariaveis : public TLista
{
private:
int FTotal;
class TListaDeVariaveis* __fastcall FGetListas(int Indice);
void __fastcall FSetListas(int Indice, class TListaDeVariaveis* Var);
bool __fastcall FNecessitaDados(void);

protected:
public:
__fastcall TBancoDeVariaveis(void);
__fastcall TBancoDeVariaveis(class TObjeto *eDono);
__fastcall ~TBancoDeVariaveis(void);
bool __fastcall Insere(class TListaDeVariaveis *eLista);
bool __fastcall Insere(class TVariavel *eVariavel);
class TListaDeVariaveis* __fastcall Remove(AnsiString eNome);
class TVariavel* __fastcall Remove(class TVariavel* eVariavel);
class TVariavel* __fastcall Remove(AnsiString eNome, TObjeto *eDono);
class TVariavel* __fastcall Variavel(AnsiString eNome, TObjeto *eDono);
double __fastcall Valor(AnsiString eNome, TObjeto *eDono);
__property class TListaDeVariaveis* Listas[int Indice] =\
                                             {read=FGetListas,write=FSetListas};
__property bool NecessitaDados = {read=FNecessitaDados};
__property int Total = {read=FTotal};
void __fastcall Globaliza(class TVariavel* eVariavel);
void __fastcall Localiza(class TVariavel* eVariavel, TObjeto *eDono);
TBancoDeVariaveis& operator = (TBancoDeVariaveis& src);
};

#endif
