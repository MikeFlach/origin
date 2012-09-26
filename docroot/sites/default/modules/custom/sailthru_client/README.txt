SAILTHRU CLIENT MODULE FOR DRUPAL 6.x

Description
-----------

This module provides a very basic wrapper to the Sailthru PHP Client library provided by Sailthru. Sailthru provide email delivery services that can be accessed by their API.

This module is a time saver for developers wanting to integrate Sailthru with their module.


Features
--------

* Administration page for configuring Sailthru API Key and Secret.
* A single function that creates and returns a Sailthru_Client object for calling the Sailthru API

TODO
----

* Check Sailthru connectivity on status page

Installation
------------

This guide assumes you are installing the module in sites/all/modules/ - if not, please adjust accordingly

* Extract this module to your sites/all/modules/ folder
* Download the Sailthru PHP5 Library from https://github.com/sailthru/sailthru-php5-client/zipball/v1.04
  * Extract the contents of sailthru-sailthru-php5-client-31922d9/ to sites/all/modules/sailthru_client/lib/
  * Ensure the file sites/all/modules/sailthru_client/lib/sailthru/Sailthru_Client.php exists
* Install the module by visiting http://{yoursitedomain}/admin/build/modules - look for "Sailthu API Client"
* Visit http://{yoursitedomain}/admin/settings/sailthru-client and configure your Key and Secret


Example
-------

To use this module, you simply need to call:

<?php
  $sailthru = sailthru_client_get_client();

  if($sailthru == false) {
    // There has been an error - check your watchdog log
  }
  else {
    // You can now call the functions Sailthru_Client provides, e.g.
       $result = $sailthru->send('TEMPLATE_NAME',
                                 'receiver@example.com,
                                 array('variable1' => 'value1',
                                       'variable2' => 'value2',
                                      ),
                                 array(
                                       'reply_to' => 'reply@example.com,
                                 )
                                );

      if(isset($result['error'])) {
        // Check the error values, you can use http://docs.sailthru.com/api/errors for reference
      }
  }
?>

Thanks
------

This module was sponsored by New Zealand Post and built by Catalyst IT Ltd.
