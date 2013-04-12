--
-- PostgreSQL database dump
--

SET client_encoding = 'SQL_ASCII';
SET check_function_bodies = false;

SET SESSION AUTHORIZATION 'postgres';

--
-- TOC entry 4 (OID 2200)
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
GRANT ALL ON SCHEMA public TO PUBLIC;

CREATE USER storefront PASSWORD 'st0r3fr0nt';

SET SESSION AUTHORIZATION 'storefront';

SET search_path = public, pg_catalog;

--
-- TOC entry 16 (OID 17281)
-- Name: tb_statecode; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_statecode (
    tk_stateid integer NOT NULL,
    cs_state character varying(20) NOT NULL,
    sz_abbr  character varying(3) NOT NULL,
    CONSTRAINT statecode_seq PRIMARY KEY(tk_stateid),
    UNIQUE(cs_state, sz_abbr)
);


--
-- Manual addition
-- Name:  tb_statecode_tk_stateid_idx
--
CREATE UNIQUE INDEX tb_statecode_tk_stateid_idx ON tb_statecode (tk_stateid);


--
-- TOC entry 15 (OID 17276)
-- Name: tb_postalcode; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_postalcode (
    tk_postid integer NOT NULL,
    cs_zip character varying(20) NOT NULL,
    cs_city character varying(30) NOT NULL,
    tk_stateid integer references tb_statecode ON DELETE RESTRICT,
    CONSTRAINT postalcode_seq PRIMARY KEY (tk_postid),
    UNIQUE (cs_zip)
);

--
-- Manual addition
-- Name:  tb_postalcode_tk_postid_idx
--
CREATE UNIQUE INDEX tb_postalcode_tk_postid_idx ON tb_postalcode (tk_postid);


--
-- TOC entry 13 (OID 17258)
-- Name: tb_customer; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_customer (
    tk_custid integer NOT NULL,
    cs_title character varying(10),
    cs_firstname character varying(30) NOT NULL,
    cs_lastname character varying(30) NOT NULL,
    cs_companyname character varying(100),
    cs_address1 character varying(100) NOT NULL,
    cs_address2 character varying(100),
    ch_gender character varying(1) CONSTRAINT gender_lm_con CHECK (ch_gender = 'm'),
	CONSTRAINT ch_UM_gender CHECK (ch_gender = 'M'),
	CONSTRAINT ch_lf_gender CHECK (ch_gender = 'f'),
	CONSTRAINT ch_UF_gender CHECK (ch_gender = 'F'),
    bi_contact boolean NOT NULL,
    tk_postid integer references tb_postalcode ON DELETE RESTRICT,
    CONSTRAINT customer_seq PRIMARY KEY (tk_custid),
    UNIQUE (cs_lastname, cs_address1)
);


--
-- Manual Entry
-- Name: tb_customer_Backup;  Type:  TABLE; Schema: public; Owner;droupou
--
CREATE TABLE tb_customerBackup (
   tk_recId integer NOT NULL,
   tk_custid integer NOT NULL,
   cs_title character varying(10), 
   cs_firstname character varying(30) NOT NULL,
   cs_lastname character varying(30) NOT NULL,
   cs_companyname character varying(100),
   cs_address1 character varying(100) NOT NULL,
   cs_address2 character varying(100),
   ch_gender character varying(1),
   bi_contact boolean NOT NULL,
   tk_postid integer references tb_postalcode,
   CONSTRAINT customerBackup_seq PRIMARY KEY (tk_recId)
);

CREATE FUNCTION sp_customer_backup() RETURNS TRIGGER AS '
    BEGIN
	-- Backup the customer data
    	INSERT INTO tb_customerBackup (tk_custid, cs_title, cs_firstname, cs_lastname, 
	    cs_companyname, cs_address1, cs_address2, ch_gender, bi_contact, tk_postid)
	    (NEW.tk_custid, NEW.cs_title, NEW.cs_firstname, NEW.cs_lastname, 
	    NEW.cs_companyname, NEW.cs_address1, NEW.cs_address2, NEW.ch_gender, 
	    NEW.bi_contact, NEW.tk_postid);
	RETURN NEW;
    END;
'LANGUAGE plpgsql;

--
-- Manual addition
-- Name:  tb_customer_tk_custid_idx
--
CREATE UNIQUE INDEX tb_customer_tk_custid_idx ON tb_customer (tk_custid);
CREATE UNIQUE INDEX tb_customerback_tk_recId_idx ON tb_customerBackup (tk_recId);
CREATE TRIGGER tb_customer_backup_tr AFTER INSERT ON tb_customer FOR EACH ROW 
    EXECUTE PROCEDURE sp_customer_backup();

--
-- TOC entry 17 (OID 17286)
-- Name: tb_phonedata; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_phonedata (
    tk_phoneid integer NOT NULL,
    tk_custid integer NOT NULL references tb_customer ON DELETE CASCADE,
    cs_phonenumber character varying(20) NOT NULL,
    cs_ext character varying(5),
    CONSTRAINT phonedata_seq PRIMARY KEY(tk_phoneid),
    UNIQUE(cs_phonenumber)
);


--
-- Manual addition
-- Name:  tb_phonedata_tk_custid_idx
--
CREATE INDEX tb_phonedata_tk_custid_idx ON tb_phonedata (tk_custid);


--
-- TOC entry 18 (OID 17288)
-- Name: tb_email; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_email (
    tk_emailid integer NOT NULL PRIMARY KEY,
    tk_custid integer NOT NULL references tb_customer ON DELETE CASCADE,
    cs_emailaddress character varying(256) UNIQUE
);


--
-- Manual addition
-- Name:  tb_email_tk_custid_idx
--
CREATE INDEX tb_email_tk_custid_idx ON tb_email(tk_custid);


--
-- TOC entry 19 (OID 17290)
-- Name: tb_creditcard; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_creditcard (
    tk_creditcardID integer NOT NULL,
    tk_custid integer NOT NULL references tb_customer ON DELETE CASCADE,
    cs_creditcardnum character varying(60) NOT NULL,
    cs_expdate character varying(10),
    PRIMARY KEY (tk_creditcardID),
    UNIQUE (cs_creditcardnum)
);

CREATE TABLE tb_creditCardBackup (
    tk_ccfk integer PRIMARY KEY NOT NULL,
    tk_custid integer NOT NULL references tb_customer,
    cs_creditcardnum character varying(60) NOT NULL,
    cs_expdate character varying(10)
);

CREATE FUNCTION sp_creditCard_backup() RETURNS TRIGGER AS '
    BEGIN
	-- Backup the Credit Card table
    	INSERT INTO tb_creditCardBackup (tk_custid, cs_creditcardnum, cs_expdate)
            VALUE(NEW.tk_custid, NEW.cs_creditcardnum, NEW.cs_expdate);
    	RETURN NEW;
    END;
' LANGUAGE plpgsql;

--
-- Manual addition
-- Name:  tb_creditcard_tk_custid_idx
--
CREATE INDEX tb_creditcard_tk_custid_idx ON tb_creditcard (tk_custid);
CREATE TRIGGER tb_creditcard_backup_ins_tr AFTER INSERT ON tb_creditcard FOR EACH ROW
    EXECUTE PROCEDURE sp_creditCard_backup();
CREATE TRIGGER tb_creditcard_backup_upd_tr AFTER UPDATE ON tb_creditcard FOR EACH ROW
    EXECUTE PROCEDURE sp_creditCard_backup();

--
-- TOC entry 22 (OID 17304)
-- Name: tb_position; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_position (
    tk_positionid integer PRIMARY KEY NOT NULL,
    cs_positiondesc character varying(60)
);


--
-- Manual addition
-- Name:  tb_position_tk_positionid_idx
--
CREATE UNIQUE INDEX tb_position_tk_positionid_idx ON tb_position (tk_positionid);


--
-- TOC entry 21 (OID 17299)
-- Name: tb_department; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_department (
    tk_deptid integer PRIMARY KEY NOT NULL,
    cs_deptdescription character varying(60)
);


--
-- Manual addition
-- Name:  tb_department_tk_deptid_idx
--
CREATE UNIQUE INDEX tb_department_tk_deptid_idx ON tb_department (tk_deptid);


--
-- TOC entry 20 (OID 17294)
-- Name: tb_employee; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_employee (
    tk_empid integer PRIMARY KEY NOT NULL,
    cs_title character varying(20),
    cs_firstname character varying(30) NOT NULL,
    cs_lastname character varying(30) NOT NULL,
    cs_address1 character varying(100) NOT NULL,
    cs_address2 character varying(100),
    tk_postid integer references tb_postalcode ON DELETE RESTRICT,
    in_socialSecurityNumber int NOT NULL,
    tk_positionid integer NOT NULL references tb_position ON DELETE RESTRICT,
    tk_deptid integer NOT NULL references tb_department ON DELETE RESTRICT,
    tk_phoneid integer references tb_phonedata ON DELETE CASCADE,
    fk_supervisorid integer,
    cs_password character varying(60) NOT NULL,
    bt_clockin boolean
);


--
-- Manual addition
-- Name:  tb_employee_tk_empid_idx
--
CREATE UNIQUE INDEX tb_employee_tk_empid_idx ON tb_employee (tk_empid);



--
-- TOC entry 24 (OID 17313)
-- Name: tb_form; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_form (
    tk_formid integer PRIMARY KEY NOT NULL,
    cs_formdesc character varying(30)
);


--
-- Manual addition
-- Name:  tb_form_tk_formid_idx
--
CREATE UNIQUE INDEX tb_form_tk_formid_idx ON tb_form (tk_formid);


--
-- TOC entry 23 (OID 17311)
-- Name: tb_access; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_access (
    tk_empid integer NOT NULL references tb_employee ON DELETE CASCADE,
    tk_formid integer NOT NULL references tb_form ON DELETE CASCADE
);


--
-- Manual addition
-- Name:  tb_access_tk_empid_idx
--
CREATE UNIQUE INDEX tb_access_tk_empid_idx ON tb_access (tk_empid);

--
-- TOC entry 25 (OID 17318)
-- Name: tb_product; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_product (
    tk_productid integer PRIMARY KEY NOT NULL,
    cs_partnumber character varying(90) NOT NULL,
    cs_partdesc character varying(100),
    mo_cost money,
    mo_msrp money,
    UNIQUE(cs_partnumber)
);


--
-- Manual addition
-- Name:  tb_product_tk_productid_idx
--
CREATE UNIQUE INDEX tb_product_tk_productid_idx ON tb_product (tk_productid);


--
-- TOC entry 26 (OID 17323)
-- Name: tb_inventoryloc; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_inventoryloc (
    tk_invloc integer PRIMARY KEY NOT NULL,
    cs_locId character varying(60) NOT NULL,
    cs_locDesc character varying(150)
);


--
-- Manual addition
-- Name:  tb_inventoryloc_tk_invloc_idx
--
CREATE UNIQUE INDEX tb_inventoryloc_tk_invloc_idx ON tb_inventoryloc (tk_invloc);


--
-- TOC entry 27 (OID 17328)
-- Name: tb_invlevel; Type: TABLE; Schema: public; Owner: droupou
--
CREATE TABLE tb_invlevel (
    tk_invlvl integer PRIMARY KEY NOT NULL,
    tk_productid integer NOT NULL references tb_product ON DELETE RESTRICT,
    tk_invloc integer NOT NULL references tb_inventoryloc ON DELETE RESTRICT,
    sz_serialNumber character varying(60)
);

--
-- Create backup table for inventory levels.
-- Name:  tb_invlevelBack; Type: TABLE; Schema: public; Owner: droupou
--
CREATE TABLE tb_invLevelBackup (
   tk_invlvlBck integer PRIMARY KEY NOT NULL,
   tk_invlvl integer NOT NULL references tb_invlevel,
   tk_productid integer NOT NULL references tb_product,
   tk_invloc integer NOT NULL references tb_inventoryloc,
   sz_serialNumber character varying(60)
);

CREATE FUNCTION sp_invLevel_backup() RETURNS TRIGGER AS '
   BEGIN
	--Bacup the Credit Card table
	INSERT INTO tb_invlevelBackup(tk_invlvl, tk_productid, 
	    tk_invloc, sz_serialNumber)
	(NEW.tk_invlvl, NEW.tk_productid, NEW.tk_invloc, NEW.sz_serialNumber);
	RETURN NEW;
   END;
' LANGUAGE plpgsql;

--
-- Manual addition
-- Name:  tb_invlevel_tk_invlvl_idx
--
CREATE UNIQUE INDEX tb_invlevel_tk_invlvl_idx ON tb_invlevel (tk_invlvl);
CREATE INDEX tb_invlevel_tk_productid_idx on tb_invlevel (tk_productid);
CREATE UNIQUE INDEX tb_invlevelBackup_tk_invlvl_idx ON tb_invlevelBackup (tk_invlvlBck);
CREATE INDEX tb_invlevelBackup_tk_productid_idx on tb_invlevelBackup (tk_productid);
CREATE TRIGGER tb_invlevel_bacup_tr AFTER INSERT on tb_invLevel FOR EACH ROW
    EXECUTE Procedure sp_invLevel_backup();
CREATE TRIGGER tb_invlevel_backup_ud_tr AFTER UPDATE on tb_invLevel FOR EACH ROW
    EXECUTE Procedure sp_invLevel_backup();
--
-- TOC entry 29 (OID 17338)
-- Name: tb_shippers; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_shippers (
    tk_shipperid integer PRIMARY KEY NOT NULL,
    cs_description character varying(100)
);


--
-- Manual addition
-- Name:  tb_shippers_tk_shipperid_idx
--
CREATE UNIQUE INDEX tb_shippers_tk_shipperid_idx ON tb_shippers (tk_shipperid);


--
-- TOC entry 30 (OID 17343)
-- Name: tb_shipmethod; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_shipmethod (
    tk_shipmethodid integer PRIMARY KEY NOT NULL,
    cs_description character varying(20)
);


--
-- Manual addition
-- Name:  tb_shipmethod_tk_shipmethodid_idx
--
CREATE UNIQUE INDEX tb_shipmethod_tk_shipmethodid_idx ON tb_shipmethod (tk_shipmethodid);


--
-- TOC entry 31 (OID 17348)
-- Name: tb_coupons; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_coupons (
    tk_couponid integer PRIMARY KEY NOT NULL,
    cs_description character varying(100) NOT NULL,
    mo_value money NOT NULL
);

CREATE TABLE tb_couponsBackup (
    tk_couponBackupid integer PRIMARY KEY NOT NULL,
    tk_couponid integer, 
    cs_description character varying(100) NOT NULL,
    mo_value money NOT NULL
);

CREATE FUNCTION sp_coupons_backup() RETURNS TRIGGER AS '
    BEGIN
        -- Backup the coupon data.
        INSERT INTO tb_couponsBackup (tk_couponid, cs_description, mo_value)
        VALUES (NEW.tk_couponid, NEW cs_description, NEW.mo_value);
        RETURN NEW;
    END;
' LANGUAGE plpgsql;

--
-- Manual addition
-- Name:  tb_coupons_tk_couponid_idx
--
CREATE UNIQUE INDEX tb_coupons_tk_couponid_idx ON tb_coupons (tk_couponid);
CREATE TRIGGER tb_coupons_backup_tr AFTER INSERT ON tb_coupons FOR EACH ROW
    EXECUTE PROCEDURE sp_coupons_backup();


--
-- TOC entry 37 (OID 17384)
-- Name: tb_register; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_register (
    tk_registerid integer PRIMARY KEY NOT NULL,
    tk_empid integer NOT NULL references tb_employee ON DELETE RESTRICT,
    mo_cashonhand money NOT NULL,
    dt_lastaccessed timestamp,
    dt_lastsuperoverride timestamp,
    cs_location character varying(30),
    in_couponsonhand integer
);

CREATE TABLE tb_registerBackup (
    tk_registerbackupid integer PRIMARY KEY NOT NULL,
    tk_registerid integer NOT NULL, 
    mo_cashonhand money NOT NULL, 
    dt_lastaccessed timestamp, 
    dt_lastsuperoverride timestamp,
    cs_location character varying(30),
    in_couponsonhand integer
);

CREATE FUNCTION sp_register_backup() RETURNS TRIGGER AS '
    BEGIN
        --Backup the register data.
        INSERT INTO tb_registerBackup (tk_registerid, mo_cashonhand, dt_lastaccessed, 
	    dt_lastsuperoverride, cs_location, in_couponsonhand)
        (NEW.tk_registerid, NEW.rk_empid, NEW.mo_cashonhand, NEW.dt_lastaccessed, 
	    NEW.dt_lastsuperoverride, NEW.cs_location, NEW.in_couponsonhand)
    END;
' LANGUAGE plpgsql;

--
-- Manual addition
-- Name:  tb_register_tk_registerid_idx
--
CREATE UNIQUE INDEX tb_register_tk_registerid_idx ON tb_register (tk_registerid);
CREATE TRIGGER tb_register_backup_tr AFTER INSERT ON tb_customer FOR EACH ROW 
    EXECUTE PROCEDURE sp_register_backup();


--
-- TOC entry 28 (OID 17333)
-- Name: tb_purchaselog; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_purchaselog (
    tk_orderid integer PRIMARY KEY NOT NULL,
    tk_custid integer NOT NULL references tb_customer ON DELETE CASCADE,
    tk_productid integer NOT NULL references tb_product ON DELETE RESTRICT,
    tk_empid integer NOT NULL references tb_employee ON DELETE RESTRICT,
    tk_shipperid integer references tb_shippers ON DELETE RESTRICT,
    tk_shipmethodid integer references tb_shipmethod ON DELETE RESTRICT,
    dt_shipdate timestamp,
    tk_couponid integer references tb_coupons ON DELETE RESTRICT,
    mo_price money,
    cs_tracking character varying(50),
    tk_registerid integer references tb_register ON DELETE RESTRICT, 
    cs_serialnumber character varying(60),
    dt_orderdate timestamp
);


--
-- Manual addition
-- Name:  tb_purchaselog_tk_orderid_idx
--
CREATE UNIQUE INDEX tb_purchaselog_tk_orderid_idx ON tb_purchaselog (tk_orderid);


--
-- TOC entry 32 (OID 17353)
-- Name: tb_returns; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_returns (
    tk_returnid integer PRIMARY KEY NOT NULL,
    sz_returnnumber character varying(10),
    dt_receiveddate timestamp,
    dt_returndate timestamp,
    tk_shipperid integer references tb_shippers ON DELETE RESTRICT,
    tk_shippermethodid integer references tb_shipmethod ON DELETE RESTRICT,
    cs_comments text,
    UNIQUE(sz_returnnumber)
);


--
-- Manual addition
-- Name:  tb_returns_tk_returnid_idx
--
CREATE UNIQUE INDEX tb_returns_tk_returnid_idx ON tb_returns (tk_returnid);


--
-- TOC entry 34 (OID 17366)
-- Name: tb_testresults; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_testresults (
    tk_testresid integer PRIMARY KEY NOT NULL,
    cs_testresdescription character varying(50)
);


--
-- Manual addition
-- Name:  tb_testresults_tk_testresid_idx
--
CREATE UNIQUE INDEX tb_testresults_tk_testresid_idx ON tb_testresults (tk_testresid);


--
-- TOC entry 33 (OID 17361)
-- Name: tb_returndetails; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_returndetails (
    tk_returndetailsid integer PRIMARY KEY NOT NULL,
    tk_returnid integer NOT NULL references tb_returns ON DELETE CASCADE,
    tk_productid integer NOT NULL references tb_product ON DELETE RESTRICT,
    cs_serialnumber character varying(60),
    tk_orderid integer NOT NULL references tb_purchaselog ON DELETE RESTRICT,
    tk_testresultsid integer references tb_testresults ON DELETE RESTRICT,
    tk_empid integer references tb_employee ON DELETE RESTRICT,
    UNIQUE(tk_returnid, cs_serialnumber)
);


--
-- Manual addition
-- Name:  tb_returndetails_tk_returndetailsid_idx
--
CREATE UNIQUE INDEX tb_returndetails_tk_returndetailsid_idx ON tb_returndetails (tk_returndetailsid);


--
-- TOC entry 35 (OID 17371)
-- Name: tb_timelog; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_timelog (
    tk_timelogid integer PRIMARY KEY NOT NULL,
    tk_empid integer NOT NULL references tb_employee ON DELETE CASCADE,
    bl_in boolean NOT NULL,
    dt_datetime timestamp
);


--
-- Manual addition
-- Name:  tb_timelog_tk_timelogid_idx
--
CREATE UNIQUE INDEX tb_timelog_tk_timelogid_idx ON tb_timelog (tk_timelogid);


--
-- TOC entry 36 (OID 17376)
-- Name: tb_errorlog; Type: TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_errorlog (
    tk_lineid integer PRIMARY KEY NOT NULL,
    tk_empid integer NOT NULL references tb_employee ON DELETE CASCADE,
    dt_datetime timestamp NOT NULL,
    cs_errordesc text,
    cs_data text
);

--
-- Name:  tb_Reports; Type:  TABLE; Schema: public; Owner: droupou
--

CREATE TABLE tb_Reports (
    tk_ReportId integer NOT NULL,
    szSPName varchar(30) NOT NULL UNIQUE,
    tk_formid integer NOT NULL references tb_form ON DELETE CASCADE,
    CONSTRAINT report_seq PRIMARY KEY(tk_ReportID)
);

CREATE UNIQUE INDEX tb_Reports_tk_ReportID_idx ON tb_Reports (tk_ReportID);


SET SESSION AUTHORIZATION 'postgres';

--
-- TOC entry 3 (OID 2200)
-- Name: SCHEMA public; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON SCHEMA public IS 'Schema created by Rick Runowski for StoreFront Software.  All Rights Reserved (C) 2004';


