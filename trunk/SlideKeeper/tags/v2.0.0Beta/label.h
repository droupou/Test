/*  */
#ifndef Label#define Label

struct label{

        label *prev;        String header;
        String title;
        String title2;
        String Material;
        String PDate;
        String EDate;
        String Enter;
        bool Is_Approved;
        String Approve;
        String Artist;
        String Dimension;
        bool Is_select;
        String Pic;
        label *next;
};

/*  */
#endif