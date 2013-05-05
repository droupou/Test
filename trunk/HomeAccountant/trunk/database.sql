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

CREATE USER homeaccount CREATEDB PASSWORD 'h0m3fr0nt';

SET SESSION AUTHORIZATION 'homeaccount';

SET search_path = public, pg_catalog;

--
-- Bank Data will be stored here.
--
CREATE TABLE tb_bank(
	tk_bankid 	SERIAL,
	sz_name		character varying(30) NOT NULL UNIQUE,
	bn_pos		boolean
);

CREATE UNIQUE INDEX tb_bank_tk_bankid_idx ON tb_bank (tk_bankid);
--
--  End Bank Data
--

--
-- Account Types
--
CREATE TABLE tb_accountTypes(
	tk_accountTypeKey	SERIAL UNIQUE,
	sz_TypeName		character varying(10) UNIQUE
);
--
-- End Account Types
--

--
--  Account Register
--
CREATE TABLE tb_accountRegister(
	tk_accountKey	SERIAL UNIQUE,
	fk_accountKey	integer REFERENCES tb_accountRegister (tk_accountKey) ON DELETE RESTRICT,
	sz_accountName	character varying(30) UNIQUE,
	fk_AccountType	integer REFERENCES tb_accountTypes (tk_accountTypeKey) ON DELETE RESTRICT
);
--
-- End Account Register
--

--
--Check Register
--
CREATE TABLE tb_checkRegister(
	tk_CheckRegisterKey	SERIAL UNIQUE,
	dt_transDate		date NOT NULL,
	in_checkNum		integer,
	fk_bankId		integer REFERENCES tb_bank (tk_bankId) ON DELETE RESTRICT,
	fl_amount		float NOT NULL,
	fk_accountId		integer REFERENCES tb_accountRegister (tk_accountKey) ON DELETE RESTRICT,
	bn_isCleared		boolean NOT NULL DEFAULT FALSE
);
--
-- End Check Register
--

----------------------------
--   Stored Proceedures   --
----------------------------

CREATE FUNCTION createBank(varchar(30), boolean ) RETURNS boolean AS '
   INSERT INTO tb_bank (sz_name, bn_pos) VALUES($1, $1);
   RETURN FOUND;
' LANGUAGE 'plpgsql';

----------------------------
-- End Stored Proceedures --
----------------------------

SET SESSION AUTHORIZATION 'postgres';

--
-- TOC entry 3 (OID 2200)
-- Name: SCHEMA public; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON SCHEMA public IS 'Schema created by Rick Runowski for HomeAccountant Software.  All Rights Reserved (C) 2005';


