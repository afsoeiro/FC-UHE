//---------------------------------------------------------------------------
#include "TObjeto.h"
#ifndef TVariavelH
#define TVariavelH
//---------------------------------------------------------------------------

class TVariavel : public TObjeto
{
private:
double FData;
AnsiString *FDescricao;
bool FDeEntrada;
protected:
  double __fastcall GetValor();
  void __fastcall SetValor(double valor);
  bool __fastcall GetDeEntrada();
  void __fastcall SetDeEntrada(bool eDeEntrada);
  AnsiString __fastcall GetDescricao();
  void __fastcall SetDescricao(AnsiString eDescricao);

public:
  __fastcall TVariavel();
  __fastcall TVariavel(class TObjeto *eDono);
  __fastcall TVariavel(double valor);

  __fastcall ~TVariavel();
  __property double Valor = {read=GetValor, write=SetValor};
  __property bool DeEntrada = {read=GetDeEntrada, write=SetDeEntrada};
  __property AnsiString Info = {read=GetDescricao, write=SetDescricao};
  bool __fastcall Salva(AnsiString arquivo);
  bool __fastcall Salva(int fHandle);
  bool __fastcall Carrega(AnsiString arquivo);
  bool __fastcall Carrega(int fHandle);
  TVariavel& operator = (TVariavel& src);
};

#endif
