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


SET SESSION AUTHORIZATION 'droupou';

SET search_path = public, pg_catalog;

CREATE TABLE tb_UserLogin (
	tk_userId integer PRIMARY KEY NOT NULL,
	sz_userName character varying(16) NOT NULL,
	dt_lastConnected timestamp,
	in_rating integer,
	in_total integer,
	sz_password character varying(20) NOT NULL,
	unique(userName)
);

CREATE TABLE tb_Question(
	tk_questionId integer PRIMARY KEY NOT NULL,
	tx_questionTxt Text,
	dt_lastViewed timestamp,
	in_rating integer,
	in_total integer
);

CREATE TABLE tb_Answer(
	tk_answerId integer PRIMARY KEY NOT NULL,
	tx_answerText Text,
	dt_lastViewed timestamp,
	in_rating integer,
	in_total integer,
	bn_confirmed boolean
);

CREATE TABLE tb_Links(
  fk_answerId integer,
  fk_answerID integer
);
