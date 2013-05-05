<?php
class state
{
  /**************************************************************************************************************
   *  By:               Rick Runowski                                                                           *
   *  On:               11/05/07                                                                                *
   *  Description:      The customer class will be used to manipulate the customers data in the back end.       *
   **************************************************************************************************************/
   private $stateid;
   private $state;
   private $state_abbr;
   private $postid;
   private $zipcode;
   private $city;


  /**************************************************************************************************************
   *  The new function will create a completely new record after checking to make sure the city/zip does not    *
   *  already exist.                                                                                            *
   **************************************************************************************************************/
  function New($state, $state_abbr, $zipcode, $city)
  {
    $dbconn = pg_connect("host=localhost dbname=storefront user=storefront password=st0r3fr0nt");
      or die('Could not connect: ' . pg_last_error());

    $query = 'SELECT * FROM tb_postalcode WHERE cs_zip = ' . $zipcode;
    $result = pg_query($query) or die ('Query failed: ' . pg_last_error());

    if(pg_affected_rows($result) == 0)
    {
      // check for state and insert accordingly.
      $query = 'SELECT * FROM tb_statecode WHERE sz_abbr = ' . $state_abbr
      $result = pg_query($query) or die ('Query failed: ' . pg_last_error());

      if !($row = pg_fetch_assoc($result))
      {
        $query = 'INSERT INTO tb_statecode (cs_state, sz_abr) VALUES(' . $state . ', ' . $state_abbr . ')';
        $result = pg_uery($query) or die ('Query failed: ' . pg_last_error());

        $query = 'SELECT * FROM tb_statecode WHERE sz_abbr = ' . $state_abbr
        $result = pg_query($query) or die ('Query failed: ' . pg_last_error());
      }
      
      $stateid = $row['tk_stateid'];
      $state = $row['cs_state'];

      $query = 'INSERT INTO tb_postalcode (cs_zip, cs_city, tk_stateid) VALUES(' . $zipcode . ', ' . $city . ', ' . $stateid . ')'
      $result = pg_query($query) or die ('Query failed: ' . pg_last_error());
      
      $query = 'SELECT * FROM tb_postalcode WHERE cs_zip = ' . $zipcode;
      $result = pg_query($query) or die ('Query failed: ' . pg_last_error());

      if ($row = pg_fetch_assoc($result))
      {
        $postid = $row['tk_postid'];
      }
    } 
    // else it doesn't need to have a new record inserted.
    
  }

  function Close(){
    pg_free_result($result);
    pg_close($dbconn);
  }

  /**************************************************************************************************************
   *  The getID function will return the pointer to this instance of state.                                     *
   **************************************************************************************************************/
  getID()
  {
    return $postid;
  }

  Update($state, $state_abbr, $postalcode, $city)
  {
    // verify state information.
    $query = 'SELECT * FROM tb_statecode WHERE sz_abbr = ' . $state_abbr
    $result = pg_query($query) or die ('Query failed: ' . pg_last_error());

    if !($row = pg_fetch_assoc($result))
    {
      $query = 'INSERT INTO tb_statecode (cs_state, sz_abr) VALUES(' . $state . ', ' . $state_abbr . ')';
      $result = pg_uery($query) or die ('Query failed: ' . pg_last_error());

      $query = 'SELECT * FROM tb_statecode WHERE sz_abbr = ' . $state_abbr
      $result = pg_query($query) or die ('Query failed: ' . pg_last_error());
    }

      $stateid = $row['tk_stateid'];
      $state = $row['cs_state'];

      $query = 'UPDATE tb_postalcode SET cs_zip = ' . $postalcode . ', cs_city = ' . $city . ', tk_stateid = ' . $stateid WHERE tk_postid = ' . $postid;
      $result = pg_query($query) or die ('Query failed: ' . pg_last_error());

  }

}
?>
