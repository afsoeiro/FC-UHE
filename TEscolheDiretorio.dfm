object EscolheDiretorio: TEscolheDiretorio
  Left = 214
  Top = 187
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = 'Escolha o diretório desejado...'
  ClientHeight = 247
  ClientWidth = 299
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  PixelsPerInch = 120
  TextHeight = 16
  object bOk: TBitBtn
    Left = 34
    Top = 217
    Width = 106
    Height = 25
    TabOrder = 0
    Kind = bkOK
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 299
    Height = 212
    Align = alTop
    Caption = 'Local dos equipamentos:'
    TabOrder = 1
    object DirectoryListBox: TDirectoryListBox
      Left = 12
      Top = 48
      Width = 274
      Height = 114
      DirLabel = Local
      ItemHeight = 16
      TabOrder = 0
    end
    object DriveComboBox1: TDriveComboBox
      Left = 11
      Top = 20
      Width = 275
      Height = 22
      DirList = DirectoryListBox
      TabOrder = 1
    end
    object Panel1: TPanel
      Left = 12
      Top = 168
      Width = 274
      Height = 31
      BevelOuter = bvLowered
      BorderStyle = bsSingle
      Color = clWindow
      TabOrder = 2
      object Local: TLabel
        Left = 1
        Top = 1
        Width = 268
        Height = 25
        Align = alClient
        Caption = 'C:\Dados\Andre\Eletrica\Projeto final\pj'
        Layout = tlCenter
      end
    end
  end
  object BitBtn1: TBitBtn
    Left = 160
    Top = 217
    Width = 106
    Height = 25
    Caption = 'Cancela'
    TabOrder = 2
    Kind = bkCancel
  end
end
