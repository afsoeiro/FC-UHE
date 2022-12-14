object Solucao: TSolucao
  Left = 202
  Top = 220
  Width = 696
  Height = 394
  Caption = 'Solução de um equipamento.'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 688
    Height = 2
    Align = alTop
    Shape = bsTopLine
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 2
    Width = 688
    Height = 336
    Align = alClient
    Lines.Strings = (
      'RichEdit1')
    TabOrder = 0
  end
  object MainMenu: TMainMenu
    Left = 16
    Top = 16
    object Arquivo: TMenuItem
      Caption = '&Arquivo'
      object miSalvar: TMenuItem
        Caption = '&Salvar...'
        OnClick = miSalvarClick
      end
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'RTF'
    Filter = 'Arquivos do tipo Rich Text|*.RTF'
    Options = [ofReadOnly, ofHideReadOnly, ofPathMustExist, ofNoReadOnlyReturn, ofEnableSizing]
    Title = 'Escolha o nome do arquivo a salvar...'
    Left = 112
    Top = 32
  end
end
