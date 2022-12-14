object EdFuncao: TEdFuncao
  Left = 224
  Top = 233
  Width = 520
  Height = 330
  Caption = 'Edição de uma função'
  Color = clBtnFace
  Constraints.MinHeight = 330
  Constraints.MinWidth = 520
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Arial'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnDeactivate = FormLostFocus
  PixelsPerInch = 120
  TextHeight = 16
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 512
    Height = 2
    Align = alTop
    Shape = bsTopLine
  end
  object pcMain: TPageControl
    Left = 0
    Top = 2
    Width = 512
    Height = 211
    ActivePage = tsAjuda
    Align = alClient
    TabOrder = 0
    object tsInformacoesGerais: TTabSheet
      Caption = 'Informações Gerais'
      OnResize = tsInformacoesGeraisOnResize
      object gbExpressoes: TGroupBox
        Left = 0
        Top = 48
        Width = 504
        Height = 132
        Align = alClient
        Caption = 'Expressões'
        TabOrder = 0
        object sgExpressoes: TStringGrid
          Left = 8
          Top = 15
          Width = 488
          Height = 80
          ColCount = 2
          FixedCols = 0
          RowCount = 2
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goTabs, goThumbTracking]
          PopupMenu = pmReta
          TabOrder = 0
          OnClick = sgExpressoesClick
          OnKeyUp = sgExpressoesOnKeyUp
          ColWidths = (
            336
            146)
        end
        object bAdicionarExpressao: TBitBtn
          Left = 66
          Top = 100
          Width = 180
          Height = 25
          Caption = 'Adicionar Expressao'
          TabOrder = 1
          OnClick = bAdicionarExpressaoClick
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
        object bRemoverExpressao: TBitBtn
          Left = 260
          Top = 100
          Width = 180
          Height = 25
          Caption = 'Remover Expressao'
          TabOrder = 2
          OnClick = bRemoverExpressaoClick
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
      object gbNome: TGroupBox
        Left = 0
        Top = 0
        Width = 504
        Height = 48
        Align = alTop
        Caption = 'Nome da Função'
        TabOrder = 1
        object eNomeDaFuncao: TEdit
          Left = 8
          Top = 17
          Width = 488
          Height = 24
          TabOrder = 0
          OnChange = eNomeDaFuncaoOnChange
          OnKeyPress = eNomeDaFuncaoOnKeyPress
        end
      end
    end
    object tsParametros: TTabSheet
      Caption = 'Seleção de Parâmetros'
      ImageIndex = 1
      OnResize = tsParametrosOnResize
      OnShow = tsParametrosOnShow
      object gbParametros: TGroupBox
        Left = 0
        Top = 0
        Width = 250
        Height = 180
        Caption = 'Parâmetros da função'
        TabOrder = 0
        object bSobe: TSpeedButton
          Left = 218
          Top = 23
          Width = 23
          Height = 65
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
          Left = 218
          Top = 91
          Width = 23
          Height = 53
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
        object lbParametros: TListBox
          Left = 11
          Top = 24
          Width = 202
          Height = 120
          ItemHeight = 16
          TabOrder = 0
        end
        object bDispensarVariavel: TBitBtn
          Left = 11
          Top = 148
          Width = 230
          Height = 25
          Caption = 'Dispensar Entrada da Variavel'
          TabOrder = 1
          OnClick = bDispensarVariavelClick
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
      object gbVariaveisInternas: TGroupBox
        Left = 255
        Top = 0
        Width = 250
        Height = 180
        Caption = 'Variáveis internas da função'
        TabOrder = 1
        object lbVariaveisInternas: TListBox
          Left = 11
          Top = 24
          Width = 230
          Height = 120
          ItemHeight = 16
          TabOrder = 0
        end
        object bExigirVariavel: TBitBtn
          Left = 11
          Top = 148
          Width = 230
          Height = 25
          Caption = 'Exigir Entrada da Variavel'
          TabOrder = 1
          OnClick = bExigirVariavelClick
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000120B0000120B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            33333333333333333333333333333333333333333333333333FF333333333333
            3000333333FFFFF3F77733333000003000B033333777773777F733330BFBFB00
            E00033337FFF3377F7773333000FBFB0E000333377733337F7773330FBFBFBF0
            E00033F7FFFF3337F7773000000FBFB0E000377777733337F7770BFBFBFBFBF0
            E00073FFFFFFFF37F777300000000FB0E000377777777337F7773333330BFB00
            000033333373FF77777733333330003333333333333777333333333333333333
            3333333333333333333333333333333333333333333333333333333333333333
            3333333333333333333333333333333333333333333333333333}
          NumGlyphs = 2
        end
      end
    end
    object tsVariaveisInternas: TTabSheet
      Caption = 'Edição de Variáveis'
      ImageIndex = 2
      OnExit = tsVariaveisInternasOnExit
      OnResize = tsVariaveisInternasOnResize
      OnShow = tsVariaveisInternasOnShow
      object gbNomesVariaveis: TGroupBox
        Left = 0
        Top = 0
        Width = 250
        Height = 180
        Caption = 'Nomes das Variáveis'
        TabOrder = 0
        object lbNomesVariaveis: TListBox
          Left = 8
          Top = 21
          Width = 230
          Height = 150
          ItemHeight = 16
          TabOrder = 0
          OnClick = lbNomesVariaveisClick
        end
      end
      object gbInfoVariaveis: TGroupBox
        Left = 255
        Top = 0
        Width = 250
        Height = 180
        Caption = 'Informações sobre a variável'
        TabOrder = 1
        object lValorVariavel: TLabel
          Left = 10
          Top = 29
          Width = 4
          Height = 16
          Caption = ':'
        end
        object eValor: TEdit
          Left = 62
          Top = 24
          Width = 171
          Height = 24
          TabOrder = 0
          OnChange = eValorOnChange
          OnExit = eValorOnExit
          OnKeyPress = eValorOnKeyPress
        end
        object gbDescricaoDaVariavel: TGroupBox
          Left = 8
          Top = 60
          Width = 235
          Height = 112
          Caption = 'Descrição da Variável'
          TabOrder = 1
          object mDescricao: TMemo
            Left = 7
            Top = 23
            Width = 220
            Height = 80
            TabOrder = 0
            OnChange = mDescricaoOnChange
          end
        end
      end
    end
    object tsAjuda: TTabSheet
      Caption = 'Informações Adicionais'
      ImageIndex = 3
      OnResize = tsAjudaResize
      OnShow = tsAjudaOnShow
      object gbInformacoesAdicionais: TGroupBox
        Left = 0
        Top = 0
        Width = 504
        Height = 180
        Align = alClient
        Caption = 'Informações Adicionais Sobre a Função'
        TabOrder = 0
        object mAjuda: TMemo
          Left = 10
          Top = 24
          Width = 479
          Height = 145
          Lines.Strings = (
            
              'Escreva aquí informações adicionais sobre a função, como finalid' +
              'ade, parâmetros '
            'requeridos, ordem destes, etc..')
          TabOrder = 0
          OnChange = mAjudaOnChange
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 255
    Width = 512
    Height = 19
    Panels = <>
    ParentColor = True
    ParentFont = True
    SimplePanel = False
    UseSystemFont = False
  end
  object pOkCancela: TPanel
    Left = 0
    Top = 213
    Width = 512
    Height = 42
    Align = alBottom
    BevelInner = bvLowered
    BorderWidth = 3
    TabOrder = 2
    OnResize = pOkCancelaResize
    object bOk: TBitBtn
      Left = 105
      Top = 8
      Width = 120
      Height = 25
      Caption = 'Ok'
      ModalResult = 1
      TabOrder = 0
      OnClick = bOkClick
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
      Left = 289
      Top = 8
      Width = 120
      Height = 25
      Caption = 'Cancela'
      TabOrder = 1
      Kind = bkCancel
    end
  end
  object MainMenu1: TMainMenu
    Left = 192
    object miArquivo: TMenuItem
      Caption = 'Arquivo'
      object miAbrir: TMenuItem
        Caption = 'Abrir...'
        OnClick = miAbrirClick
      end
      object miSalvar: TMenuItem
        Caption = 'Salvar...'
        OnClick = miSalvarClick
      end
    end
    object Ferramentas1: TMenuItem
      Caption = 'Ferramentas'
      object miCalcular: TMenuItem
        Caption = 'Calcular...'
        OnClick = miCalcularClick
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 48
    Top = 229
  end
  object SaveDialog1: TSaveDialog
    Left = 80
    Top = 229
  end
  object pmReta: TPopupMenu
    Left = 144
    Top = 8
    object miLinear: TMenuItem
      Caption = 'Definir segmento de reta...'
      OnClick = miLinearClick
    end
  end
end
