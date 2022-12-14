//---------------------------------------------------------------------------

#ifndef TEdEquipamentoH
#define TEdEquipamentoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TEdEquipamento : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *PopupGrid;
        TMenuItem *miNovaEquacao;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TStatusBar *StatusBar1;
        TMainMenu *MainMenu;
        TMenuItem *miArquivo;
        TMenuItem *miAjuda;
        TMenuItem *miTopicos;
        TBevel *bvMenu;
        TMenuItem *miAbrir;
        TMenuItem *miSalvar;
        TMenuItem *N1;
        TMenuItem *miSair;
        TMenuItem *miFerramentas;
        TMenuItem *miCalcular;
        TMenuItem *miAtribuirImagem;
        TMenuItem *miCarregarEquacaoDoDisco;
        TMenuItem *miRemoverEquacaoSelecionada;
  TPageControl *pcEquipamento;
  TTabSheet *tsGeral;
  TTabSheet *tsFuncoesDisponiveis;
  TTabSheet *tsModoDeSolucao;
  TGroupBox *gbVariaveisDeEntrada;
  TListBox *lbListaDeVariaveis;
  TGroupBox *gbAposEntrada;
  TGroupBox *gbResolver;
  TComboBox *cbEntradaDeFuncoes;
  TGroupBox *gbParametros;
  TListBox *lbParametros;
  TGroupBox *gbMemoria;
  TGroupBox *gbOrdem;
  TListBox *lbOrdem;
  TSpeedButton *bSobe;
  TSpeedButton *bDesce;
  TBitBtn *bIncluir;
  TBitBtn *bRemover;
  TGroupBox *gbFigura;
  TImage *iFoto;
  TGroupBox *gbNome;
  TEdit *eNome;
  TGroupBox *gbDescricao;
  TMemo *mDescricao;
        TGroupBox *gbFuncoes;
  TListBox *lbFuncoes;
  TBitBtn *bNovaFuncao;
  TBitBtn *bAbrirFuncaoDoDisco;
  TBitBtn *bEditarFuncao;
  TBitBtn *bRemoverFuncao;
  TBitBtn *bRemoveEntrada;
  TPanel *pOkCancela;
  TBitBtn *bOk;
  TBitBtn *bCancela;
  TEdit *eVariaveis;
  TGroupBox *gbAjuda;
  TMemo *mInfoFuncao;
  TTabSheet *tsVariaveis;
  TGroupBox *gbNomesVariaveis;
  TListBox *lbNomesVariaveis;
  TGroupBox *gbInfoVariaveis;
  TLabel *lValorVariavel;
  TEdit *eValor;
  TGroupBox *gbDescricaoDaVariavel;
  TMemo *mInfoVariavel;
        TEdit *eArmazenamento;
        TBitBtn *bEscolherFigura;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall miCalcularClick(TObject *Sender);
        void __fastcall miAbrirClick(TObject *Sender);
        void __fastcall miSalvarClick(TObject *Sender);
        void __fastcall eNomeOnChange(TObject *Sender);
        void __fastcall bEscolherFiguraClick(TObject *Sender);
  void __fastcall pOkCancelaResize(TObject *Sender);
  void __fastcall tsGeralResize(TObject *Sender);
  void __fastcall cbEntradaDeFuncoesDown(TObject *Sender);
  void __fastcall cbEntradaDeFuncoesClick(TObject *Sender);
  void __fastcall cbEntradaDeFuncoesExit(TObject *Sender);
  void __fastcall eVariaveisKeyPress(TObject *Sender, char &Key);
  void __fastcall bRemoveEntradaClick(TObject *Sender);
  void __fastcall mDescricaoOnChange(TObject *Sender);
  void __fastcall tsVariaveisOnShow(TObject *Sender);
  void __fastcall lbNomesVariaveisOnClick(TObject *Sender);
  void __fastcall eValorOnChange(TObject *Sender);
  void __fastcall eValorOnKeyPress(TObject *Sender, char &Key);
  void __fastcall mInfoVariavelOnKeyPress(TObject *Sender, char &Key);
  void __fastcall mInfoVariavelOnChange(TObject *Sender);
  void __fastcall lbListaDeVariaveisOnDblClick(TObject *Sender);
  void __fastcall bNovaFuncaoClick(TObject *Sender);
  void __fastcall bEditarFuncaoOnClick(TObject *Sender);
  void __fastcall lbFuncoesOnDblClick(TObject *Sender);
  void __fastcall lbFuncoesOnClick(TObject *Sender);
  void __fastcall bAbrirFuncaoDoDiscoClick(TObject *Sender);
  void __fastcall bRemoverFuncaoClick(TObject *Sender);
  void __fastcall cbArmazenamentoClick(TObject *Sender);
  void __fastcall cbArmazenamentoDrop(TObject *Sender);
  void __fastcall cbArmazenamentoExit(TObject *Sender);
  void __fastcall tsModoOnShow(TObject *Sender);
  void __fastcall SelecionaParametro(TObject *Sender);
  void __fastcall eArmazenamentoKeyPress(TObject *Sender, char &Key);
  void __fastcall bIncluirClick(TObject *Sender);
  void __fastcall bRemoverClick(TObject *Sender);
  void __fastcall miAtribuirImagemClick(TObject *Sender);
  void __fastcall tsFuncoesOnShow(TObject *Sender);
        void __fastcall bSobeClick(TObject *Sender);
        void __fastcall bDesceClick(TObject *Sender);
        void __fastcall miSairClick(TObject *Sender);
        void __fastcall miTopicosClick(TObject *Sender);
private:	// User declarations
        bool cbefdropping;
        bool cbardropping;
        class TEquipamento *equipamento;
        class TListaDeVariaveis *FVars;
        class TVariavel *VariavelEmEdicao;
        void __fastcall Limpa(void);
        class TListaDeVariaveis* __fastcall GetListaDeVariaveis(void);
        void __fastcall SetListaDeVariaveis(class TListaDeVariaveis* eLista);
public:		// User declarations
        __property class TListaDeVariaveis* ListaDeVariaveis =
                       {read=GetListaDeVariaveis, write=SetListaDeVariaveis};
        __fastcall TEdEquipamento(TComponent* Owner);
        bool __fastcall Editar(TEquipamento *eEqui);
};
//---------------------------------------------------------------------------
extern PACKAGE TEdEquipamento *EdEquipamento;
//---------------------------------------------------------------------------
#endif
