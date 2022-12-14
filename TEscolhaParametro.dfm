object EscolhaParametro: TEscolhaParametro
  Left = 195
  Top = 121
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'EscolhaParametro'
  ClientHeight = 243
  ClientWidth = 205
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  Scaled = False
  PixelsPerInch = 120
  TextHeight = 16
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 205
    Height = 243
    Align = alClient
    Shape = bsFrame
    Style = bsRaised
  end
  object ListBox1: TListBox
    Left = 6
    Top = 6
    Width = 193
    Height = 230
    ItemHeight = 16
    TabOrder = 0
    OnClick = ListClick
  end
end
