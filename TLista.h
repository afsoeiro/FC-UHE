//---------------------------------------------------------------------------
#include "TObjeto.h"
#ifndef TListaH
#define TListaH
//---------------------------------------------------------------------------
struct LISTA
{
class TObjeto *Elemento; // Elemento da lista.
struct LISTA *Proximo; // Proximo elemento da lista, se houver.
};
typedef struct LISTA Lista;

class TLista : public TObjeto
{
private:
int FNumero;
Lista *Cartorio;
int __fastcall FGetNumero(void);
AnsiString __fastcall FGetNomes(int Indice);
TObjeto* __fastcall FGetObjetos(int Indice);
void __fastcall FSetNomes(int Indice, AnsiString eNome);
void __fastcall FSetObjetos(int Indice, TObjeto* Objeto);
void __fastcall FSetPtrObjetos(int Indice, TObjeto* Objeto);
void __fastcall CastedDelete(TObjeto* Objeto);

protected:
public:
__fastcall TLista(void);
__fastcall TLista(class TObjeto* eDono);
__fastcall ~TLista(void);
bool __fastcall Insere(TObjeto* Objeto);
class TObjeto* __fastcall Remove(AnsiString eNome);
__property int Numero = {read=FGetNumero};
__property AnsiString Nomes[int Indice] = {read=FGetNomes,write=FSetNomes};
__property TObjeto* Objetos[int Indice] = {read=FGetObjetos,write=FSetObjetos};
__property TObjeto* PtrObjetos[int Indice] =\
                               {read=FGetObjetos,write=FSetPtrObjetos};
int __fastcall Indice(AnsiString eNome);
bool __fastcall Troca(int eIndice1, int eIndice2);
};

#endif
