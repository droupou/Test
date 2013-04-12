object EditMaterialFrm: TEditMaterialFrm
  Left = 829
  Top = 104
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Edit Material'
  ClientHeight = 75
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
  object ok_btn: TButton
    Left = 8
    Top = 48
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = ok_btnClick
  end
  object Cancel_btn: TButton
    Left = 104
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 1
    OnClick = Cancel_btnClick
  end
  object Material_drp: TComboBox
    Left = 0
    Top = 0
    Width = 185
    Height = 21
    ItemHeight = 13
    TabOrder = 2
    Text = '-- Select Material --'
    OnChange = Material_drpChange
    OnKeyUp = OnKeyUp
  end
  object NewMaterial_txt: TEdit
    Left = 0
    Top = 24
    Width = 185
    Height = 21
    TabOrder = 3
  end
end
