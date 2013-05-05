#ifndef SKPICTURE
#define SKPICTURE 1

#include <vcl.h>
#include <jpeg.hpp>

#include <fstream.h>

#include <windows>
#include <winsock>
#include <mysql/mysql.h>

#include "sqlConnection.h"

#pragma hdrstop
class skPicture{
private:
        TJPEGImage *jp;

        LPCTSTR nFilePath;
        LPCTSTR nFileName;
        LPCTSTR oFileName;
        BOOL bFailIfExists;
public:
        skPicture();
        ~skPicture();

        TJPEGImage* getPicture();
        void setPicture(TJPEGImage *tpic);
        bool savePicture(LPCTSTR filepath);
};

skPicture::skPicture(){
        MessageDlg("Test2", mtError, TMsgDlgButtons() << mbOK, 0);

        // Obtain data.
        ifstream in;
        char t[256];

        in.open("config.cfg");

        if(in.is_open()){
                //in >> t;
                in >> nFilePath;
                //nFilePath = t;
        }

        MessageDlg(nFilePath, mtError, TMsgDlgButtons() << mbOK, 0);
        //nFilePath = "c:\\VRL\\\0";
        nFileName = "default.jpg\0";
        oFileName = "";
        bFailIfExists = true;
        jp = NULL;
}

skPicture::~skPicture(){
        if(jp != NULL)
                delete(jp);
}

//TODO:  Finish this.
TJPEGImage* skPicture::getPicture(){
        return NULL;
}

void skPicture::setPicture(TJPEGImage *tpic){
        sqlConnection *conn = new sqlConnection();
        String sql;
        int fileCounter = 0;

        sql = "SELECT * FROM tb_PictureCounter";
}

//TODO:  Finish This.
bool savePicture(LPCTSTR filepath){
        return false;
}
#endif
 