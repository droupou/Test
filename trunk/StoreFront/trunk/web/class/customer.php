<?php
include ("state.php");

class customer
{
  /**************************************************************************************************************
   *  By:               Rick Runowski                                                                           *
   *  On:               11/05/07                                                                                *
   *  Description:      The customer class will be used to manipulate the customers data in the back end.       *
   **************************************************************************************************************/
   private $custID;
   private $title;
   private $firstname;
   private $lastname;
   private $company;
   private $address1;
   private $address2;
   private $gender;
   private $contact;
   private $city;
   private $state;
   private $postalcode;
   private $state_abbr;
   private $CState;


  /**************************************************************************************************************
   *  The new function will create a completely new record after checking to make sure the person does not      *
   *  already exist.                                                                                            *
   **************************************************************************************************************/
  function New($ftitle, $first, $last, $co, $add1, $add2, $fgender, $fcontact, $fpostalcode)
  {
    // Verify the $fpostalcode exists and obtain the pointer reference.
    $CState = new state;
    $CState->new($state, $state_abbr, $postalcode, $city);

    // Determine if the client already exists.
    $dbconn = ph_connect("host=localhost dbname=storefront user=storefront password=st0r3fr0nt")
        or die('Could not connect: ' . pg_last_error());

    $query = 'SELECT * FROM tb_customer WHERE 'cs_lastname = ' . $lastname . ' AND cs_address1 = ' . $address1;
    $result = pg_query($query) or die('Query failed: ' . pg_last_error()); 

    if(pg_affected_rows($result) == 1)
    {
      // Already Exists
    }
    else
    {
      // Insert query here.
      $query = 'INSERT INTO tb_customer (cs_title, cs_firstname, cs_lastname, cs_companyname, cs_address1, cs_address2, ch_gender, bi_contact, tk_postid) VALUES('; 
      $query = $query . $title . ', ' . $firstname . ', ' . $lastname . ', ' . $company . ', ' . $address1 . ', ' . $address2 . ', ' . $gender . ', '; 
      $query = $query . $contact . ', ' . $CState->getID() . ')';
      
      $result = pg_query($query) or die('Query failed: ' . pg_last_error());
    }

    $query = 'SELECT * FROM tb_customer WHERE 'cs_lastname = ' . $lastname . ' AND cs_address1 = ' . $address1;
    $result = pg_query($query) or die('Query failed: ' . pg_last_error());

    if($row = pg_fetch_assoc($result))
    {
      $custID = $row['tk_custid];
    }
    else
    {
      // error message.
    }
  }


  /**************************************************************************************************************
   *  The update function will update all of the fields that have changed.                                      *
   **************************************************************************************************************/
  function Update($ftitle, $first, $last, $co, $add1, $add2, $fgender, $fcontact, $fcity, $fstate, $fpostalcode, $fstate_abbr)
  {
    // Verify the $fpostalcode exists and obtain the pointer reference.
    if($postalcode <> $fpostalcode)
    {
      $CState->Update($fstate, $fstate_abbr, $fpostalcode, $fcity);
      // Update the data.
      $query = 'UPDATE tb_customer SET cs_title = ' . $ftitle . ', cs_firstname = ' . $first . ', cs_lastname = ' . $last . ', cs_companyname = ' 
      $query = $query . $co . ', cs_address1 =  ' . $add1 . ', cs_address2 = ' . $add2 . ', ch_gender =  ' . $fgender . ', bi_contact =  ' . $fcontact 
      $query = $query . ', tk_postid = ' . $CState->getID()';
      $result = pg_query($query) or die('Query failed: ' . pg_last_error());
    }
  }

  function Close()
  {
    pg_free_result($result);
    pg_close($dbconn);
  }
}
?>


