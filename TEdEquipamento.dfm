object EdEquipamento: TEdEquipamento
  Left = 301
  Top = 148
  Width = 640
  Height = 430
  Caption = 'Edição de um Equipamento'
  Color = clBtnFace
  Constraints.MinHeight = 430
  Constraints.MinWidth = 640
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Arial'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 120
  TextHeight = 16
  object bvMenu: TBevel
    Left = 0
    Top = 0
    Width = 632
    Height = 2
    Align = alTop
    Shape = bsTopLine
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 355
    Width = 632
    Height = 19
    AutoHint = True
    Panels = <>
    ParentColor = True
    ParentFont = True
    ParentShowHint = False
    ShowHint = True
    SimplePanel = True
    UseSystemFont = False
  end
  object pcEquipamento: TPageControl
    Left = 0
    Top = 2
    Width = 632
    Height = 311
    ActivePage = tsFuncoesDisponiveis
    Align = alClient
    TabOrder = 0
    object tsGeral: TTabSheet
      Caption = 'Geral'
      OnResize = tsGeralResize
      object gbFigura: TGroupBox
        Left = 314
        Top = 3
        Width = 310
        Height = 276
        Caption = 'Figura:'
        TabOrder = 0
        object iFoto: TImage
          Left = 10
          Top = 22
          Width = 290
          Height = 209
          Stretch = True
        end
        object bEscolherFigura: TBitBtn
          Left = 10
          Top = 240
          Width = 290
          Height = 25
          Caption = 'Escolher Figura...'
          TabOrder = 0
          OnClick = bEscolherFiguraClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033BBBBBBBBBB
            BB33337777777777777F33BB00BBBBBBBB33337F77333333F37F33BB0BBBBBB0
            BB33337F73F33337FF7F33BBB0BBBB000B33337F37FF3377737F33BBB00BB00B
            BB33337F377F3773337F33BBBB0B00BBBB33337F337F7733337F33BBBB000BBB
            BB33337F33777F33337F33EEEE000EEEEE33337F3F777FFF337F33EE0E80000E
            EE33337F73F77773337F33EEE0800EEEEE33337F37377F33337F33EEEE000EEE
            EE33337F33777F33337F33EEEEE00EEEEE33337F33377FF3337F33EEEEEE00EE
            EE33337F333377F3337F33EEEEEE00EEEE33337F33337733337F33EEEEEEEEEE
            EE33337FFFFFFFFFFF7F33EEEEEEEEEEEE333377777777777773}
          NumGlyphs = 2
        end
      end
      object gbNome: TGroupBox
        Left = 0
        Top = 4
        Width = 310
        Height = 59
        Caption = 'Nome do Equipamento'
        TabOrder = 1
        object eNome: TEdit
          Left = 10
          Top = 20
          Width = 290
          Height = 24
          TabOrder = 0
          Text = 'Equipamento1'
          OnChange = eNomeOnChange
        end
      end
      object gbDescricao: TGroupBox
        Left = 0
        Top = 68
        Width = 310
        Height = 211
        Caption = 'Descrição Sumária'
        TabOrder = 2
        object mDescricao: TMemo
          Left = 9
          Top = 21
          Width = 290
          Height = 180
          TabOrder = 0
          OnChange = mDescricaoOnChange
        end
      end
    end
    object tsFuncoesDisponiveis: TTabSheet
      Caption = 'Funções Disponíveis'
      ImageIndex = 1
      OnShow = tsFuncoesOnShow
      object gbFuncoes: TGroupBox
        Left = 0
        Top = 0
        Width = 624
        Height = 280
        Align = alClient
        Caption = 'Funções'
        TabOrder = 0
        object lbFuncoes: TListBox
          Left = 6
          Top = 20
          Width = 300
          Height = 248
          ItemHeight = 16
          TabOrder = 0
          OnClick = lbFuncoesOnClick
          OnDblClick = lbFuncoesOnDblClick
        end
        object bNovaFuncao: TBitBtn
          Left = 315
          Top = 146
          Width = 300
          Height = 26
          Caption = 'Nova Função'
          TabOrder = 1
          OnClick = bNovaFuncaoClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000130B0000130B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033333333B333
            333B33FF33337F3333F73BB3777BB7777BB3377FFFF77FFFF77333B000000000
            0B3333777777777777333330FFFFFFFF07333337F33333337F333330FFFFFFFF
            07333337F33333337F333330FFFFFFFF07333337F33333337F333330FFFFFFFF
            07333FF7F33333337FFFBBB0FFFFFFFF0BB37777F3333333777F3BB0FFFFFFFF
            0BBB3777F3333FFF77773330FFFF000003333337F333777773333330FFFF0FF0
            33333337F3337F37F3333330FFFF0F0B33333337F3337F77FF333330FFFF003B
            B3333337FFFF77377FF333B000000333BB33337777777F3377FF3BB3333BB333
            3BB33773333773333773B333333B3333333B7333333733333337}
          NumGlyphs = 2
        end
        object bAbrirFuncaoDoDisco: TBitBtn
          Left = 315
          Top = 178
          Width = 300
          Height = 26
          Caption = 'Abrir Função do disco...'
          TabOrder = 2
          OnClick = bAbrirFuncaoDoDiscoClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
            555555FFFFFFFFFF55555000000000055555577777777775FFFF00B8B8B8B8B0
            0000775F5555555777770B0B8B8B8B8B0FF07F75F555555575F70FB0B8B8B8B8
            B0F07F575FFFFFFFF7F70BFB0000000000F07F557777777777570FBFBF0FFFFF
            FFF07F55557F5FFFFFF70BFBFB0F000000F07F55557F777777570FBFBF0FFFFF
            FFF075F5557F5FFFFFF750FBFB0F000000F0575FFF7F777777575700000FFFFF
            FFF05577777F5FF55FF75555550F00FF00005555557F775577775555550FFFFF
            0F055555557F55557F755555550FFFFF00555555557FFFFF7755555555000000
            0555555555777777755555555555555555555555555555555555}
          NumGlyphs = 2
        end
        object bEditarFuncao: TBitBtn
          Left = 315
          Top = 210
          Width = 300
          Height = 26
          Caption = 'Editar Função...'
          TabOrder = 3
          OnClick = bEditarFuncaoOnClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00500000000055
            555557777777775F55550FFFFFFFFF0555557F5555555F7FFF5F0FEEEEEE0000
            05007F555555777775770FFFFFF0BFBFB00E7F5F5557FFF557770F0EEEE000FB
            FB0E7F75FF57775555770FF00F0FBFBFBF0E7F57757FFFF555770FE0B00000FB
            FB0E7F575777775555770FFF0FBFBFBFBF0E7F5575FFFFFFF5770FEEE0000000
            FB0E7F555777777755770FFFFF0B00BFB0007F55557577FFF7770FEEEEE0B000
            05557F555557577775550FFFFFFF0B0555557FF5F5F57575F55500F0F0F0F0B0
            555577F7F7F7F7F75F5550707070700B055557F7F7F7F7757FF5507070707050
            9055575757575757775505050505055505557575757575557555}
          NumGlyphs = 2
        end
        object bRemoverFuncao: TBitBtn
          Left = 315
          Top = 242
          Width = 300
          Height = 26
          Caption = 'Remover Função'
          TabOrder = 4
          OnClick = bRemoverFuncaoClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00500005000555
            555557777F777555F55500000000555055557777777755F75555005500055055
            555577F5777F57555555005550055555555577FF577F5FF55555500550050055
            5555577FF77577FF555555005050110555555577F757777FF555555505099910
            555555FF75777777FF555005550999910555577F5F77777775F5500505509990
            3055577F75F77777575F55005055090B030555775755777575755555555550B0
            B03055555F555757575755550555550B0B335555755555757555555555555550
            BBB35555F55555575F555550555555550BBB55575555555575F5555555555555
            50BB555555555555575F555555555555550B5555555555555575}
          NumGlyphs = 2
        end
        object gbAjuda: TGroupBox
          Left = 315
          Top = 16
          Width = 300
          Height = 121
          Caption = 'Informações Sobre a Função'
          TabOrder = 5
          object mInfoFuncao: TMemo
            Left = 8
            Top = 22
            Width = 284
            Height = 89
            Lines.Strings = (
              '')
            ReadOnly = True
            TabOrder = 0
          end
        end
      end
    end
    object tsModoDeSolucao: TTabSheet
      Caption = 'Modo de Solução'
      ImageIndex = 2
      OnShow = tsModoOnShow
      object gbVariaveisDeEntrada: TGroupBox
        Left = 0
        Top = 3
        Width = 172
        Height = 277
        Caption = 'Requisitar as variáveis:'
        TabOrder = 0
        object lbListaDeVariaveis: TListBox
          Left = 9
          Top = 56
          Width = 153
          Height = 182
          ExtendedSelect = False
          ItemHeight = 16
          TabOrder = 0
          OnDblClick = lbListaDeVariaveisOnDblClick
        end
        object bRemoveEntrada: TBitBtn
          Left = 9
          Top = 244
          Width = 153
          Height = 25
          Caption = 'Remover'
          TabOrder = 1
          OnClick = bRemoveEntradaClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00500005000555
            555557777F777555F55500000000555055557777777755F75555005500055055
            555577F5777F57555555005550055555555577FF577F5FF55555500550050055
            5555577FF77577FF555555005050110555555577F757777FF555555505099910
            555555FF75777777FF555005550999910555577F5F77777775F5500505509990
            3055577F75F77777575F55005055090B030555775755777575755555555550B0
            B03055555F555757575755550555550B0B335555755555757555555555555550
            BBB35555F55555575F555550555555550BBB55575555555575F5555555555555
            50BB555555555555575F555555555555550B5555555555555575}
          NumGlyphs = 2
        end
        object eVariaveis: TEdit
          Left = 9
          Top = 24
          Width = 153
          Height = 24
          TabOrder = 2
          OnKeyPress = eVariaveisKeyPress
        end
      end
      object gbAposEntrada: TGroupBox
        Left = 176
        Top = 3
        Width = 448
        Height = 277
        Caption = 'E após a requisição:'
        TabOrder = 1
        object gbResolver: TGroupBox
          Left = 8
          Top = 17
          Width = 212
          Height = 57
          Caption = 'Resolver:'
          TabOrder = 0
          object cbEntradaDeFuncoes: TComboBox
            Left = 8
            Top = 21
            Width = 196
            Height = 24
            ItemHeight = 0
            TabOrder = 0
            Text = '<Escolha Uma Funcao>'
            OnClick = cbEntradaDeFuncoesClick
            OnDropDown = cbEntradaDeFuncoesDown
            OnExit = cbEntradaDeFuncoesExit
          end
        end
        object gbParametros: TGroupBox
          Left = 8
          Top = 77
          Width = 212
          Height = 103
          Caption = 'Usando os parâmetros:'
          TabOrder = 1
          object lbParametros: TListBox
            Left = 7
            Top = 19
            Width = 195
            Height = 75
            ItemHeight = 16
            TabOrder = 0
            OnDblClick = SelecionaParametro
          end
        end
        object gbMemoria: TGroupBox
          Left = 8
          Top = 181
          Width = 212
          Height = 59
          Caption = 'Armazenando em:'
          TabOrder = 2
          object eArmazenamento: TEdit
            Left = 8
            Top = 24
            Width = 195
            Height = 24
            TabOrder = 0
            OnKeyPress = eArmazenamentoKeyPress
          end
        end
        object gbOrdem: TGroupBox
          Left = 226
          Top = 17
          Width = 212
          Height = 253
          Caption = 'Na Ordem:'
          TabOrder = 3
          object bSobe: TSpeedButton
            Left = 7
            Top = 20
            Width = 200
            Height = 25
            Caption = 'Executar este antes'
            Glyph.Data = {
              76010000424D7601000000000000760000002800000020000000100000000100
              04000000000000010000120B0000120B00001000000000000000000000000000
              800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333000333
              3333333333777F33333333333309033333333333337F7F333333333333090333
              33333333337F7F33333333333309033333333333337F7F333333333333090333
              33333333337F7F33333333333309033333333333FF7F7FFFF333333000090000
              3333333777737777F333333099999990333333373F3333373333333309999903
              333333337F33337F33333333099999033333333373F333733333333330999033
              3333333337F337F3333333333099903333333333373F37333333333333090333
              33333333337F7F33333333333309033333333333337373333333333333303333
              333333333337F333333333333330333333333333333733333333}
            NumGlyphs = 2
            OnClick = bSobeClick
          end
          object bDesce: TSpeedButton
            Left = 7
            Top = 194
            Width = 200
            Height = 25
            Caption = 'Executar este depois'
            Glyph.Data = {
              76010000424D7601000000000000760000002800000020000000100000000100
              04000000000000010000120B0000120B00001000000000000000000000000000
              800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333303333
              333333333337F33333333333333033333333333333373F333333333333090333
              33333333337F7F33333333333309033333333333337373F33333333330999033
              3333333337F337F33333333330999033333333333733373F3333333309999903
              333333337F33337F33333333099999033333333373333373F333333099999990
              33333337FFFF3FF7F33333300009000033333337777F77773333333333090333
              33333333337F7F33333333333309033333333333337F7F333333333333090333
              33333333337F7F33333333333309033333333333337F7F333333333333090333
              33333333337F7F33333333333300033333333333337773333333}
            NumGlyphs = 2
            OnClick = bDesceClick
          end
          object lbOrdem: TListBox
            Left = 7
            Top = 50
            Width = 200
            Height = 140
            ItemHeight = 16
            TabOrder = 0
          end
          object bRemover: TBitBtn
            Left = 7
            Top = 222
            Width = 200
            Height = 25
            Caption = 'Remover'
            TabOrder = 1
            OnClick = bRemoverClick
            Glyph.Data = {
              76010000424D7601000000000000760000002800000020000000100000000100
              04000000000000010000120B0000120B00001000000000000000000000000000
              800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00500005000555
              555557777F777555F55500000000555055557777777755F75555005500055055
              555577F5777F57555555005550055555555577FF577F5FF55555500550050055
              5555577FF77577FF555555005050110555555577F757777FF555555505099910
              555555FF75777777FF555005550999910555577F5F77777775F5500505509990
              3055577F75F77777575F55005055090B030555775755777575755555555550B0
              B03055555F555757575755550555550B0B335555755555757555555555555550
              BBB35555F55555575F555550555555550BBB55575555555575F5555555555555
              50BB555555555555575F555555555555550B5555555555555575}
            NumGlyphs = 2
          end
        end
        object bIncluir: TBitBtn
          Left = 8
          Top = 245
          Width = 212
          Height = 25
          Caption = 'Incluir'
          TabOrder = 4
          OnClick = bIncluirClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            3333333333333333333333333333333333333FFF333333333333000333333333
            3333777FFF3FFFFF33330B000300000333337F777F777773F333000E00BFBFB0
            3333777F773333F7F333000E0BFBF0003333777F7F3337773F33000E0FBFBFBF
            0333777F7F3333FF7FFF000E0BFBF0000003777F7F3337777773000E0FBFBFBF
            BFB0777F7F33FFFFFFF7000E0BF000000003777F7FF777777773000000BFB033
            33337777773FF733333333333300033333333333337773333333333333333333
            3333333333333333333333333333333333333333333333333333333333333333
            3333333333333333333333333333333333333333333333333333}
          Layout = blGlyphRight
          NumGlyphs = 2
        end
      end
    end
    object tsVariaveis: TTabSheet
      Caption = 'Edição de Variáveis'
      ImageIndex = 3
      OnShow = tsVariaveisOnShow
      object gbNomesVariaveis: TGroupBox
        Left = 0
        Top = 0
        Width = 217
        Height = 279
        Caption = 'Nomes das Variáveis'
        TabOrder = 0
        object lbNomesVariaveis: TListBox
          Left = 8
          Top = 21
          Width = 201
          Height = 248
          ItemHeight = 16
          TabOrder = 0
          OnClick = lbNomesVariaveisOnClick
        end
      end
      object gbInfoVariaveis: TGroupBox
        Left = 221
        Top = 0
        Width = 402
        Height = 279
        Caption = 'Informações sobre a variável'
        TabOrder = 1
        object lValorVariavel: TLabel
          Left = 10
          Top = 27
          Width = 5
          Height = 16
          Caption = 'v'
          Layout = tlCenter
        end
        object eValor: TEdit
          Left = 93
          Top = 24
          Width = 180
          Height = 24
          TabOrder = 0
          OnChange = eValorOnChange
          OnKeyPress = eValorOnKeyPress
        end
        object gbDescricaoDaVariavel: TGroupBox
          Left = 7
          Top = 60
          Width = 388
          Height = 210
          Caption = 'Descrição da Variável'
          TabOrder = 1
          object mInfoVariavel: TMemo
            Left = 7
            Top = 23
            Width = 374
            Height = 177
            TabOrder = 0
            OnChange = mInfoVariavelOnChange
            OnKeyPress = mInfoVariavelOnKeyPress
          end
        end
      end
    end
  end
  object pOkCancela: TPanel
    Left = 0
    Top = 313
    Width = 632
    Height = 42
    Align = alBottom
    BevelInner = bvLowered
    BorderWidth = 3
    TabOrder = 1
    OnResize = pOkCancelaResize
    object bOk: TBitBtn
      Left = 127
      Top = 8
      Width = 170
      Height = 25
      Caption = 'Ok'
      ModalResult = 1
      TabOrder = 0
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
    end
    object bCancela: TBitBtn
      Left = 335
      Top = 8
      Width = 170
      Height = 25
      Caption = 'Cancela'
      TabOrder = 1
      Kind = bkCancel
    end
  end
  object PopupGrid: TPopupMenu
    Left = 512
    Top = 65528
    object miNovaEquacao: TMenuItem
      Caption = '&Nova Equaçao'
    end
    object miRemoverEquacaoSelecionada: TMenuItem
      Caption = '&Remover Equação Selecionada'
      Hint = 'Remove a equação selecionada.'
    end
    object miCarregarEquacaoDoDisco: TMenuItem
      Caption = '&Carregar Equação do Disco...'
      Hint = 
        'Agrega uma equação previamente salva em disco à definição do equ' +
        'ipamento.'
    end
  end
  object OpenDialog: TOpenDialog
    Options = [ofHideReadOnly, ofFileMustExist, ofEnableSizing]
    Left = 448
    Top = 65528
  end
  object SaveDialog: TSaveDialog
    Left = 416
    Top = 65528
  end
  object MainMenu: TMainMenu
    Left = 480
    Top = 65528
    object miArquivo: TMenuItem
      Caption = '&Arquivo'
      object miAbrir: TMenuItem
        Caption = '&Abrir...'
        Hint = 'Abre um arquivo de definição de equipamentos...'
        OnClick = miAbrirClick
      end
      object miSalvar: TMenuItem
        Caption = '&Salvar...'
        Hint = 'Salva as definições do equipamento corrente em disco...'
        OnClick = miSalvarClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object miSair: TMenuItem
        Caption = 'Sai&r'
        Hint = 'Encerra o editor de equipamentos.'
        OnClick = miSairClick
      end
    end
    object miFerramentas: TMenuItem
      Caption = '&Ferramentas'
      object miCalcular: TMenuItem
        Caption = '&Calcular...'
        Hint = 'Realiza um cálculo de teste do equipamento.'
        OnClick = miCalcularClick
      end
      object miAtribuirImagem: TMenuItem
        Caption = 'Atribuir &Imagem...'
        Hint = 'Atribui uma imagem ao equipamento.'
        OnClick = miAtribuirImagemClick
      end
    end
    object miAjuda: TMenuItem
      Caption = 'A&juda'
      object miTopicos: TMenuItem
        Caption = '&Tópicos'
        OnClick = miTopicosClick
      end
    end
  end
end
