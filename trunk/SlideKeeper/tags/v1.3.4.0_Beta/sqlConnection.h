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
    String server, user, pass;
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
    String user, password;

     pass = "Password";

    in.open("config.cfg");

    if(in.is_open()){
        in >> t;
        in >> t;
        server = t;



        for(int i = 0; i < 256; i++)
             t[i] = '\0';

        in >> t;
        user = t;

        for(int i = 0; i < 256; i++)
             t[i] = '\0';

        in >> t;
        password = t;
    }

    // Initialize the connector.
    if(!mysql_init(&mysql)){
        // Error message here.
        MessageDlg(mysql_error(&mysql), mtError, TMsgDlgButtons() << mbOK, 0);
        exit(1);
    }

    //TODO:  Make this a configurable item.
    if(!mysql_real_connect(&mysql, server.c_str(), user.c_str(),
        password.c_str(), "vrl", 3306, NULL, 0)){
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
