<?php

class phone
{
  /**************************************************************************************************************
   *  By:               Rick Runowski                                                                           *
   *  On:               11/05/07                                                                                *
   *  Description:      The phone class will be used to manipulate the customers phone number data in the back  *
   *                    end.                                                                                    *
   **************************************************************************************************************/
   private $phoneid;
   private $CustomerID;
   private $phonenumber;
   private $ext;

   function New($CustomerID, $phonenumber, $ext)
   {
      $dbconn = ph_connect("host=localhost dbname=storefront user=storefront password=st0r3fr0nt")
        or die('Could not connect: ' . pg_last_error());

      $query = 'SELECT * FROM tb_phonedata WHERE cs_phonenumber = ' . $phonenumber;
      $result = pg_query($query) or die('Query failed: ' . pg_last_error());

      if(pg_affected_rows($result) == 1)
      {
        // Already Exists
      }
      else
      {
        // Insert query here.
      }

   }
}
