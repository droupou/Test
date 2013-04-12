object EditUserFrm: TEditUserFrm
  Left = 409
  Top = 107
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Edit User'
  ClientHeight = 99
  ClientWidth = 187
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
  object Name_drp: TComboBox
    Left = 0
    Top = 0
    Width = 185
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = '--Select User to Edit --'
    OnChange = Name_drpChange
    OnKeyUp = OnKeyUp
  end
  object FirstName_txt: TEdit
    Left = 0
    Top = 24
    Width = 185
    Height = 21
    TabOrder = 1
    OnChange = FirstName_txtChange
  end
  object LastName_txt: TEdit
    Left = 0
    Top = 48
    Width = 185
    Height = 21
    TabOrder = 2
    OnChange = LastName_txtChange
  end
  object ok_btn: TButton
    Left = 8
    Top = 72
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 3
    OnClick = ok_btnClick
  end
  object Cancel_btn: TButton
    Left = 104
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 4
    OnClick = Cancel_btnClick
  end
end
