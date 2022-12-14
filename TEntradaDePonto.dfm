object EntradaDePonto: TEntradaDePonto
  Left = 31
  Top = 553
  ActiveControl = eX1
  BorderIcons = []
  BorderStyle = bsNone
  ClientHeight = 173
  ClientWidth = 607
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
  object pJanela: TPanel
    Left = 0
    Top = 0
    Width = 607
    Height = 173
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvNone
    BorderWidth = 1
    TabOrder = 0
    object lIntro: TLabel
      Left = 2
      Top = 2
      Width = 603
      Height = 16
      Align = alTop
      Alignment = taCenter
      WordWrap = True
    end
    object gbPonto1: TGroupBox
      Left = 16
      Top = 19
      Width = 281
      Height = 72
      Caption = '(X1; Y1)'
      TabOrder = 0
      object pPonto1: TPanel
        Left = 10
        Top = 20
        Width = 209
        Height = 41
        BevelOuter = bvLowered
        BevelWidth = 2
        BorderWidth = 1
        BorderStyle = bsSingle
        Color = clWindow
        TabOrder = 0
        object lVirgula1: TLabel
          Left = 88
          Top = 5
          Width = 4
          Height = 16
        end
        object lP1e: TLabel
          Left = 4
          Top = 5
          Width = 4
          Height = 16
        end
        object lP1d: TLabel
          Left = 192
          Top = 5
          Width = 4
          Height = 16
        end
        object eX1: TEdit
          Left = 8
          Top = 5
          Width = 89
          Height = 24
          BorderStyle = bsNone
          TabOrder = 0
        end
        object eY1: TEdit
          Left = 99
          Top = 5
          Width = 89
          Height = 24
          BorderStyle = bsNone
          TabOrder = 1
        end
      end
    end
    object gbPonto2: TGroupBox
      Left = 306
      Top = 18
      Width = 284
      Height = 73
      Caption = '(X2; Y2)'
      TabOrder = 1
      object pPonto2: TPanel
        Left = 10
        Top = 20
        Width = 209
        Height = 41
        BevelOuter = bvLowered
        BevelWidth = 2
        BorderWidth = 1
        BorderStyle = bsSingle
        Color = clWindow
        TabOrder = 0
        object lVirgula2: TLabel
          Left = 88
          Top = 5
          Width = 4
          Height = 16
        end
        object lP2e: TLabel
          Left = 4
          Top = 5
          Width = 4
          Height = 16
        end
        object lP2d: TLabel
          Left = 192
          Top = 5
          Width = 4
          Height = 16
        end
        object eX2: TEdit
          Left = 8
          Top = 5
          Width = 89
          Height = 24
          BorderStyle = bsNone
          TabOrder = 0
        end
        object eY2: TEdit
          Left = 99
          Top = 5
          Width = 89
          Height = 24
          BorderStyle = bsNone
          TabOrder = 1
        end
      end
    end
    object bOk: TBitBtn
      Left = 152
      Top = 128
      Width = 120
      Height = 25
      Caption = 'Ok'
      ModalResult = 1
      TabOrder = 2
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
      Left = 328
      Top = 128
      Width = 120
      Height = 25
      Caption = 'Cancela'
      TabOrder = 3
      Kind = bkCancel
    end
  end
end
