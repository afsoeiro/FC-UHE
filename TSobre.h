//---------------------------------------------------------------------------

#ifndef TSobreH
#define TSobreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TSobre : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TImage *Image1;
  TBitBtn *BitBtn1;
        TLabel *Label3;
private:	// User declarations
public:		// User declarations
        __fastcall TSobre(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSobre *Sobre;
//---------------------------------------------------------------------------
#endif
