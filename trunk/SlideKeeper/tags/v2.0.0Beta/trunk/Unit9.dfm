object AddPeriodFrm: TAddPeriodFrm
  Left = 717
  Top = 106
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Add Period Date'
  ClientHeight = 56
  ClientWidth = 191
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 59
    Height = 13
    Caption = 'Period Date:'
  end
  object Date_txt: TEdit
    Left = 64
    Top = 0
    Width = 121
    Height = 21
    MaxLength = 255
    TabOrder = 0
  end
  object OK_btn: TButton
    Left = 8
    Top = 24
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = OK_btnClick
  end
  object Cancel_btn: TButton
    Left = 104
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = Cancel_btnClick
  end
end
