//---------------------------------------------------------------------------

#ifndef TEntradaDePontoH
#define TEntradaDePontoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TEntradaDePonto : public TForm
{
__published:	// IDE-managed Components
        TPanel *pJanela;
        TLabel *lIntro;
        TGroupBox *gbPonto1;
        TPanel *pPonto1;
        TLabel *lVirgula1;
        TLabel *lP1e;
        TLabel *lP1d;
        TEdit *eX1;
        TEdit *eY1;
        TGroupBox *gbPonto2;
        TPanel *pPonto2;
        TLabel *lVirgula2;
        TLabel *lP2e;
        TLabel *lP2d;
        TEdit *eX2;
        TEdit *eY2;
        TBitBtn *bOk;
        TBitBtn *bCancela;
  void __fastcall bOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TEntradaDePonto(TComponent* Owner);
        char **PegaReta(void);
        double a;
        double b;
};
//---------------------------------------------------------------------------
extern PACKAGE TEntradaDePonto *EntradaDePonto;
//---------------------------------------------------------------------------
#endif
