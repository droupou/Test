# MySQL-Front Dump 1.16 beta
#
# Host: localhost Database: vrl
#--------------------------------------------------------
# Server version 4.0.13-nt

#
#  Create Database
#
CREATE DATABASE VRL;
 
USE VRL;

#
# Table structure for table 'tb_employees'
#

CREATE TABLE tb_employees (
  tb_EmpKey int(3) unsigned NOT NULL auto_increment,
  tb_FirstName varchar(30) DEFAULT '0' ,
  tb_LastName varchar(30) DEFAULT '0' ,
  PRIMARY KEY (tb_EmpKey)
);


#
# Table structure for table 'tb_materials'
#

CREATE TABLE tb_materials (
  tb_MaterialKey int(3) unsigned NOT NULL auto_increment,
  tb_MaterialDesc varchar(255) NOT NULL DEFAULT '0' ,
  UNIQUE tb_MaterialKey (tb_MaterialKey)
);


#
# Table structure for table 'tb_period'
#

CREATE TABLE tb_period (
  tb_PDateKey int(3) unsigned NOT NULL auto_increment,
  tb_PDateDesc varchar(255) ,
  UNIQUE tb_PDateKey (tb_PDateKey)
);


#
# Table structure for table 'tb_slides'
#

CREATE TABLE tb_slides (
  tb_SlideKey bigint(3) unsigned NOT NULL auto_increment,
  tb_Header varchar(255) ,
  tb_Title varchar(255) ,
  tb_Title2 varchar(255) ,
  tb_MaterialKey int(3) unsigned DEFAULT '0' ,
  tb_PDateKey int(3) unsigned DEFAULT '0' ,
  tb_EDate datetime ,
  tb_EmpKey int(3) unsigned DEFAULT '0' ,
  tb_IsApproved tinyint(3) unsigned zerofill NOT NULL DEFAULT '000' ,
  tb_AppEmpKey int(3) unsigned DEFAULT '0' ,
  tb_Artist varchar(255) ,
  tb_Dimensions varchar(30) ,
  tb_Date date DEFAULT '0000-00-00' ,
  Picture VARCHAR(255) NOT NULL,
  PRIMARY KEY (tb_SlideKey),
  KEY tb_SlideKey_2 (tb_SlideKey),
  UNIQUE tb_SlideKey (tb_SlideKey)
);


