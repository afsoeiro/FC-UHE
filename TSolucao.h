//---------------------------------------------------------------------------

#ifndef TSolucaoH
#define TSolucaoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TSolucao : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu;
        TMenuItem *Arquivo;
        TBevel *Bevel1;
        TMenuItem *miSalvar;
        TSaveDialog *SaveDialog;
        TRichEdit *RichEdit1;
        void __fastcall miSalvarClick(TObject *Sender);
private:	// User declarations
        String Texto;
public:		// User declarations
        __fastcall TSolucao(TComponent* Owner);
        void __fastcall Mostra(AnsiString eTexto);
};
//---------------------------------------------------------------------------
extern PACKAGE TSolucao *Solucao;
//---------------------------------------------------------------------------
#endif
