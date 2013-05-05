#ifndef SQLCONNECTION
#define SQLCONNECTION 1

#include <vcl.h>

#include <fstream.h>

#include <windows>
#include <winsock>
#include <mysql/mysql.h>
#include "PersonalSQL.cpp"

#pragma hdrstop
class sqlConnection{
private:
    String server;
    MYSQL mysql;

public:
    sqlConnection();
    ~sqlConnection();

    MYSQL_RES* query(String sql);
    bool execute(String sql);
};

sqlConnection::sqlConnection(){
    // Obtain data.
    ifstream in;
    char t[256];

    in.open("config.cfg");

    if(in.is_open()){
        in >> t;
        in >> t;
        server = t;
    }

    // Initialize the connector.
    if(!mysql_init(&mysql)){
        // Error message here.
        MessageDlg(mysql_error(&mysql), mtError, TMsgDlgButtons() << mbOK, 0);
        exit(1);
    }

    if(!mysql_real_connect(&mysql, server.c_str(), "root", "4nosferatu", "vrl",
        3306, NULL, 0)){
        // Error message here.
        MessageDlg(mysql_error(&mysql), mtError, TMsgDlgButtons() << mbOK, 0);
        exit(1);
    }
};

sqlConnection::~sqlConnection(){
    mysql_close(&mysql);
}
/*
 *
 */
MYSQL_RES* sqlConnection::query(String sql){
    MYSQL_RES *result;

    //sql = SQLParse(sql);

    if(mysql_query(&mysql, sql.c_str())){
        // Error message here.
        MessageDlg(mysql_error(&mysql), mtError, TMsgDlgButtons() << mbOK, 0);
        return NULL;
    }
    else{
        result = mysql_store_result(&mysql);
        return result;
    }
};

/*
 *
 */
bool sqlConnection::execute(String sql){
    // MessageDlg(sql.c_str(), mtError, TMsgDlgButtons() << mbOK, 0);

    //sql = SQLParse(sql);

    if(mysql_query(&mysql, sql.c_str())){
        // Error message here.
        MessageDlg(mysql_error(&mysql), mtError, TMsgDlgButtons() << mbOK, 0);
        return false;
    }
    return true;
};

#endif
