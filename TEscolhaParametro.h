//---------------------------------------------------------------------------

#ifndef TEscolhaParametroH
#define TEscolhaParametroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TEscolhaParametro : public TForm
{
__published:	// IDE-managed Components
  TBevel *Bevel1;
  TListBox *ListBox1;
  void __fastcall ListClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TEscolhaParametro(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEscolhaParametro *EscolhaParametro;
//---------------------------------------------------------------------------
#endif
