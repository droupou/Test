object MsgBox: TMsgBox
  Left = 232
  Top = 130
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'MsgBox'
  ClientHeight = 83
  ClientWidth = 391
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 0
    Width = 32
    Height = 13
    Alignment = taCenter
    Caption = 'Label1'
  end
  object Edit1: TEdit
    Left = 8
    Top = 24
    Width = 377
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object OK_btn: TButton
    Left = 152
    Top = 56
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = OK_btnClick
  end
end
