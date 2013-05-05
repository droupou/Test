#ifndef SQLCONNECTION
#define SQLCONNECTION 1

#include <vcl.h>

#include <fstream.h>

#include <windows>
#include <winsock>
#include <mysql.h>
#include "PersonalSQL.cpp"

#pragma hdrstop
class sqlConnection{
private:
    String server, user, password;
    MYSQL mysql;

public:
    sqlConnection();
    ~sqlConnection();

    MYSQL_RES* query(String sql);
    bool execute(String sql);
};

sqlConnection::sqlConnection(){
    // Initialize the connector.
    if(!mysql_init(&mysql)){
        MessageDlg(mysql_error(&mysql), mtError, TMsgDlgButtons() << mbOK, 0);
        exit(1);
    }

    server = "localhost";
    user = "vrl";
    password = "vrlprog";

    //TODO:  Make this a configurable item.
    string db = "vrl";
    if(!mysql_real_connect(&mysql, server.c_str(), user.c_str(), password.c_str(), db.c_str(), 3306, NULL, 0)){
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
    if(mysql_query(&mysql, sql.c_str())){
        // Error message here.
        MessageDlg(mysql_error(&mysql), mtError, TMsgDlgButtons() << mbOK, 0);
        return false;
    }
    return true;
};

#endif
