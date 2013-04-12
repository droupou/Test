object EditPDateFrm: TEditPDateFrm
  Left = 617
  Top = 104
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Edit Period Date'
  ClientHeight = 74
  ClientWidth = 186
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
  object PDate_drp: TComboBox
    Left = 0
    Top = 0
    Width = 185
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = '-- Select Period Date --'
    OnChange = PDate_drpChange
    OnKeyUp = OnKeyUp
  end
  object NewPDate_txt: TEdit
    Left = 0
    Top = 24
    Width = 185
    Height = 21
    TabOrder = 1
  end
  object ok_btn: TButton
    Left = 8
    Top = 48
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = ok_btnClick
  end
  object Cancel_btn: TButton
    Left = 104
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 3
    OnClick = Cancel_btnClick
  end
end
