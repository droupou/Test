object NewUserFrm: TNewUserFrm
  Left = 197
  Top = 114
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'New User'
  ClientHeight = 97
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
  OnClose = Onclose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 8
    Width = 59
    Height = 13
    Caption = 'First Name:  '
  end
  object Label2: TLabel
    Left = 0
    Top = 32
    Width = 57
    Height = 13
    Caption = 'Last Name: '
  end
  object First_txt: TEdit
    Left = 64
    Top = 8
    Width = 121
    Height = 21
    MaxLength = 30
    TabOrder = 0
  end
  object Last_txt: TEdit
    Left = 64
    Top = 32
    Width = 121
    Height = 21
    MaxLength = 30
    TabOrder = 1
  end
  object OK_btn: TButton
    Left = 8
    Top = 56
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = OK_btnClick
  end
  object Cancel_btn: TButton
    Left = 104
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = Cancel_btnClick
  end
end
