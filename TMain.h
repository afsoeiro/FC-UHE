//---------------------------------------------------------------------------

#ifndef TMainH
#define TMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <AxCtrls.hpp>
#include <OleCtrls.hpp>
#include <vcf1.hpp>
#include <IniFiles.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>


//---------------------------------------------------------------------------
class TMain : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TBevel *Bevel1;
        TMainMenu *MainMenu;
        TMenuItem *mEquipamentos;
  TMenuItem *mNovoEquipamento;
  TMenuItem *mModificarEquipamento;
        TMenuItem *mAnteprojeto;
        TMenuItem *mAjuda;
        TMenuItem *mSobre;
        TMenuItem *Indice1;
        TSaveDialog *SaveDialog;
        TMenuItem *miEscolherDiretorio;
        TMenuItem *N1;
        TImage *Image1;
        void __fastcall MainDestroy(TObject *Sender);
        void __fastcall mSobreClick(TObject *Sender);
  void __fastcall mNovoEquipamentoClick(TObject *Sender);
        void __fastcall miEscolherDiretorioClick(TObject *Sender);
        void __fastcall Indice1Click(TObject *Sender);

private:	// User declarations
       void __fastcall RefazMenus(void);
public:		// User declarations
        __fastcall TMain(TComponent* Owner);
        void __fastcall EquipamentosClick(TObject *Sender);
        void __fastcall ModificarEquipamentoClick(TObject *Sender);
        AnsiString *AppPath;
        AnsiString *IniFilePath;
        AnsiString *EqPath;
        TIniFile *IniFile;
        TStringList *Equipamentos;
        TStringList *Arquivos;
        class TLista *equipamentos;
};
//---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
//---------------------------------------------------------------------------
#endif
