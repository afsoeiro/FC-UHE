//---------------------------------------------------------------------------

#ifndef TEdFuncaoH
#define TEdFuncaoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TEdFuncao : public TForm
{
__published:	// IDE-managed Components
  TPageControl *pcMain;
  TMainMenu *MainMenu1;
  TMenuItem *miArquivo;
  TBevel *Bevel1;
  TTabSheet *tsInformacoesGerais;
  TTabSheet *tsParametros;
  TGroupBox *gbExpressoes;
  TStringGrid *sgExpressoes;
  TBitBtn *bAdicionarExpressao;
  TBitBtn *bRemoverExpressao;
  TTabSheet *tsVariaveisInternas;
  TStatusBar *StatusBar1;
  TGroupBox *gbNomesVariaveis;
  TListBox *lbNomesVariaveis;
  TGroupBox *gbInfoVariaveis;
  TLabel *lValorVariavel;
  TEdit *eValor;
  TGroupBox *gbDescricaoDaVariavel;
  TMemo *mDescricao;
  TGroupBox *gbParametros;
  TSpeedButton *bSobe;
  TSpeedButton *bDesce;
  TListBox *lbParametros;
  TBitBtn *bDispensarVariavel;
  TGroupBox *gbVariaveisInternas;
  TListBox *lbVariaveisInternas;
  TBitBtn *bExigirVariavel;
  TGroupBox *gbNome;
  TEdit *eNomeDaFuncao;
  TPanel *pOkCancela;
  TBitBtn *bOk;
  TBitBtn *bCancela;
  TMenuItem *miAbrir;
  TMenuItem *miSalvar;
  TMenuItem *Ferramentas1;
  TMenuItem *miCalcular;
  TOpenDialog *OpenDialog1;
  TSaveDialog *SaveDialog1;
  TPopupMenu *pmReta;
        TMenuItem *miLinear;
  TTabSheet *tsAjuda;
  TGroupBox *gbInformacoesAdicionais;
  TMemo *mAjuda;
  void __fastcall cbVariavelPrincipalGetFocus(TObject *Sender);
  void __fastcall FormActivate(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall sgExpressoesOnExit(TObject *Sender);
  void __fastcall FormLostFocus(TObject *Sender);
  void __fastcall bAdicionarExpressaoClick(TObject *Sender);
  void __fastcall bRemoverExpressaoClick(TObject *Sender);
  void __fastcall eNomeDaFuncaoOnChange(TObject *Sender);
  void __fastcall eNomeDaFuncaoOnKeyPress(TObject *Sender, char &Key);
  void __fastcall pOkCancelaResize(TObject *Sender);
  void __fastcall tsInformacoesGeraisOnResize(TObject *Sender);
  void __fastcall tsParametrosOnResize(TObject *Sender);
  void __fastcall tsVariaveisInternasOnResize(TObject *Sender);
  void __fastcall tsParametrosOnShow(TObject *Sender);
  void __fastcall tsVariaveisInternasOnShow(TObject *Sender);
  void __fastcall bSobeClick(TObject *Sender);
  void __fastcall bDesceClick(TObject *Sender);
  void __fastcall bDispensarVariavelClick(TObject *Sender);
  void __fastcall bExigirVariavelClick(TObject *Sender);
  void __fastcall lbNomesVariaveisClick(TObject *Sender);
  void __fastcall mDescricaoOnChange(TObject *Sender);
  void __fastcall eValorOnChange(TObject *Sender);
  void __fastcall tsVariaveisInternasOnExit(TObject *Sender);
  void __fastcall miCalcularClick(TObject *Sender);
  void __fastcall eValorOnExit(TObject *Sender);
  void __fastcall miAbrirClick(TObject *Sender);
  void __fastcall miSalvarClick(TObject *Sender);
  void __fastcall miLinearClick(TObject *Sender);
  void __fastcall eValorOnKeyPress(TObject *Sender, char &Key);
  void __fastcall tsAjudaResize(TObject *Sender);
  void __fastcall mAjudaOnChange(TObject *Sender);
  void __fastcall tsAjudaOnShow(TObject *Sender);
  void __fastcall bOkClick(TObject *Sender);
        void __fastcall sgExpressoesOnKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall sgExpressoesClick(TObject *Sender);
private:	// User declarations
bool MudouExpressao;
class TFuncao *funcao;
class TListaDeVariaveis *FVars;
class TVariavel *VariavelEmEdicao;
void __fastcall EncheTsParametros(void);
void __fastcall RefreshTsParametros(void);
void __fastcall RefreshTsGeral(void);
void __fastcall EncheTsVariaveisInternas(void);
public:		// User declarations
  __fastcall TEdFuncao(TComponent* Owner);
  void __fastcall AtualizaExpressoes(void);
  void __fastcall Editar(class TFuncao *eFunc);
};
//---------------------------------------------------------------------------
extern PACKAGE TEdFuncao *EdFuncao;
//---------------------------------------------------------------------------
#endif
