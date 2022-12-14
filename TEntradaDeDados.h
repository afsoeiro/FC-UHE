//---------------------------------------------------------------------------

#ifndef TEntradaDeDadosH
#define TEntradaDeDadosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TEntradaDeDados : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *Grid;
        TPanel *pBotoes;
        TStatusBar *StatusBar;
        TBitBtn *bSegue;
        TBitBtn *bCancela;
        void __fastcall bSegueClick(TObject *Sender);
        void __fastcall TEntradaDeDadosResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TEntradaDeDados(TComponent* Owner);
        bool __fastcall PegaLista(TListaDeVariaveis *lista);
        bool __fastcall PegaBanco(class TBancoDeVariaveis *banco);
        bool __fastcall PegaVariavel(class TVariavel &var);
};
//---------------------------------------------------------------------------
extern PACKAGE TEntradaDeDados *EntradaDeDados;
//---------------------------------------------------------------------------
#endif
