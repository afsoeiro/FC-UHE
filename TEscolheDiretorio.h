//---------------------------------------------------------------------------

#ifndef TEscolheDiretorioH
#define TEscolheDiretorioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <FileCtrl.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TEscolheDiretorio : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *bOk;
        TGroupBox *GroupBox1;
        TDirectoryListBox *DirectoryListBox;
        TBitBtn *BitBtn1;
        TDriveComboBox *DriveComboBox1;
        TPanel *Panel1;
        TLabel *Local;
private:	// User declarations
public:		// User declarations
        TIniFile *IniEmAlteracao;
        __fastcall TEscolheDiretorio(TComponent* Owner);
        bool __fastcall Configura(TIniFile *IniFile);
};
//---------------------------------------------------------------------------
extern PACKAGE TEscolheDiretorio *EscolheDiretorio;
//---------------------------------------------------------------------------
#endif
