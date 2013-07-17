<!doctype html>
<!--[if IEMobile 7 ]>    <html class="no-js iem7" > <![endif]-->
<!--[if (gt IEMobile 7)|!(IEMobile)]><!-->
<html class="no-js" >
<!--<![endif]-->
<head>
<meta charset="utf-8">
<title>Home</title>
<meta property="og:restrictions:content" content="alcohol"/>
<meta name="description" content=""/>
<meta name="keywords" content=""/>
<meta name="HandheldFriendly" content="True"/>
<meta name="MobileOptimized" content="320"/>
<meta name="format-detection" content="telephone=yes"/>
<link href='//fonts.googleapis.com/css?family=Source+Sans+Pro:400,600' rel='stylesheet' type='text/css'>
<meta name="viewport" content="width=device-width,initial-scale=1.0,maximum-scale=1.0,maximum-scale=1.0,user-scalable=no">
<link rel="stylesheet" type="text/css" href="js/jquery/jquery.mobile.theme-1.1.0.min.css" />
<link rel="stylesheet" type="text/css" href="css/mobile-style.css">
<link rel="stylesheet" type="text/css" href="css/style.css">
<script>
var geocoder;
var map;
</script>
<script src="/sites/all/libraries/jquery/jquery-1.7.1.min.js"></script>
<script type="text/javascript" src="/sites/all/libraries/jquery/jquery.cookie.js"></script>
<script>
$(document).bind('mobileinit',function(){
	$.mobile.page.prototype.options.keepNative = "select, input, textarea, button";
	

$(document).on("submit", function(){
  $(this).find(":submit").attr("disabled","disabled");
});
	
});
</script>
<script type="text/javascript" src="js/jquery/jquery.mobile-1.1.0.min.js"></script>
<script src="js/mobile-js.js" type="text/javascript"></script>
<style>
#age {
	padding: 4px;
	background: url('images/formbg.png')no-repeat center center;
	-webkit-background-size: cover;
	-moz-background-size: cover;
	-o-background-size: cover;
	background-size: cover;
}
#age div {
	border: 2px #000 solid;
	padding: 35px 10px 15px;
	text-align: center;
	background: rgba(0,0,0, .70);
}
#dob-wrap {
	background: none !important;
	border: none !important;
}
#age div h1 {
	height: 120px;
	color: #931b1d;
	display: block;
	font-size: 37px;
	line-height: 38px;
	margin: 12px 0 15px 2px;
}
#age div h3 {
	color: #f0f0f0;
	text-transform: uppercase;
}
#age form#age-entry-form {
	text-transform: uppercase;
	overflow: visible;
	color: #fff;
	position: relative;
	text-align: center !important;
}
#day-tag, #month-tag, #year-tag {
	position: relative;
	display: inline-block;
}
#day-tag:after {
	content: "Day";
	position: absolute;
	top: -20px;
	left: 2px;
	color: #666;
	font-weight: bold;
}
#month-tag:after {
	content: "Month";
	position: absolute;
	top: -20px;
	left: 2px;
	color: #666;
	font-weight: bold;
}
#year-tag:after {
	content: "Year";
	position: absolute;
	top: -20px;
	left: 2px;
	color: #666;
	font-weight: bold;
}
label, input, select {
	display: block;
	margin-bottom: 10px;
}
select {
	display: inline-block;
	text-align: center;
}
label {
	color: #931b1d;
	font-family: 'Source Sans Pro', sans-serif;
	font-size: 2.4em;
	line-height: 38px;
	margin-top: 15px;
	font-weight: 600;
}
label.hide { display: none; }
#dob-wrap {
	overflow: hidden;
	position: relative;
}
.button-red {
	background: #d46061; /* Old browsers */
	background: -moz-linear-gradient(top, #d46061 0%, #9b2426 100%); /* FF3.6+ */
	background: -webkit-gradient(linear, left top, left bottom, color-stop(0%, #d46061), color-stop(100%, #9b2426)); /* Chrome,Safari4+ */
	background: -webkit-linear-gradient(top, #d46061 0%, #9b2426 100%); /* Chrome10+,Safari5.1+ */
	background: -o-linear-gradient(top, #d46061 0%, #9b2426 100%); /* Opera 11.10+ */
	background: -ms-linear-gradient(top, #d46061 0%, #9b2426 100%); /* IE10+ */
	background: linear-gradient(to bottom, #d46061 0%, #9b2426 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#d46061', endColorstr='#9b2426', GradientType=0 ); /* IE6-9 */
	-webkit-box-shadow: inset 0 1px 0 #E18789, 0 1px 0 #CFD1CE;
	border: 1px #5F0B0B solid;
	display: inline-block;
	color: #fff;
	font-size: 18px;
	width: 125px;
	text-align: center;
	text-transform: uppercase;
	font-family: 'Source Sans Pro', sans-serif;
	padding: 10px;
	-webkit-border-radius: 5px;
	-moz-border-radius: 5px;
	border-radius: 5px;
	cursor: pointer;
}
.button-red:hover {
	background: #d46061; /* Old browsers */
	background: -moz-linear-gradient(top, #d46061 0%, #9b2426 100%); /* FF3.6+ */
	background: -webkit-gradient(linear, left top, left bottom, color-stop(0%, #d46061), color-stop(100%, #9b2426)); /* Chrome,Safari4+ */
	background: -webkit-linear-gradient(top, #d46061 0%, #9b2426 100%); /* Chrome10+,Safari5.1+ */
	background: -o-linear-gradient(top, #d46061 0%, #9b2426 100%); /* Opera 11.10+ */
	background: -ms-linear-gradient(top, #d46061 0%, #9b2426 100%); /* IE10+ */
	background: linear-gradient(to bottom, #d46061 0%, #9b2426 100%); /* W3C */
filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#d46061', endColorstr='#9b2426', GradientType=0 ); /* IE6-9 */
}
</style>
</head>
<body data-role="body" >
<div style="display:block;width:100%;max-width:640px !important;margin:0px auto;">
<div data-role="page" id="index">
<ul class="column ui-sortable ui-droppable" style="visibility: visible;">
    <li rel="image" class="widget widget-type-image box-image " id="widget1" >
        <div class="widget-content">
            <div class="image"><img src="images/../images/jacobsGhost_Header.png" alt=""/></div>
        </div>
    </li>
    <li> 
        <!-- Age Gate -->
        <div id="age">
            <div>
                <h3>YOU MUST BE OF LEGAL DRINKING AGE<br>
                    TO ENJOY JIM BEAM PRODUCTS.</h3>
                <form id="age-entry-form" name="age-entry-form" autocomplete="off" action="/verify_age" method="post" onsubmit="return checkAge()">
                    <fieldset>
                        <label for="dob" class="dob">When were you born?</label>
                        <div id="dob-wrap">
                            <label for="dob-day" class="hide">Day</label>
                            <span id="day-tag">
                            <select id="dob-day" name="dob-day">
                                <option value="01">01</option>
                                <option value="02">02</option>
                                <option value="03">03</option>
                                <option value="04">04</option>
                                <option value="05">05</option>
                                <option value="06">06</option>
                                <option value="07">07</option>
                                <option value="08">08</option>
                                <option value="09">09</option>
                                <option value="10">10</option>
                                <option value="11">11</option>
                                <option value="12">12</option>
                                <option value="13">13</option>
                                <option value="14">14</option>
                                <option value="15">15</option>
                                <option value="16">16</option>
                                <option value="17">17</option>
                                <option value="18">18</option>
                                <option value="19">19</option>
                                <option value="20">20</option>
                                <option value="21">21</option>
                                <option value="22">22</option>
                                <option value="23">23</option>
                                <option value="24">24</option>
                                <option value="25">25</option>
                                <option value="26">26</option>
                                <option value="27">27</option>
                                <option value="28">28</option>
                                <option value="29">29</option>
                                <option value="30">30</option>
                                <option value="31">31</option>
                            </select>
                            </span>
                            <label for="dob-month" class="hide">Month</label>
                            <span id="month-tag">
                            <select id="dob-month" name="dob-month">
                                <option value="01">01 - January</option>
                                <option value="02">02 - February</option>
                                <option value="03">03 - March</option>
                                <option value="04">04 - April</option>
                                <option value="05">05 - May</option>
                                <option value="06">06 - June</option>
                                <option value="07">07 - July</option>
                                <option value="08">08 - August</option>
                                <option value="09">09 - September</option>
                                <option value="10">10 - October</option>
                                <option value="11">11 - November</option>
                                <option value="12">12 - December</option>
                            </select>
                            </span>
                            <label for="dob-year" class="hide">Year</label>
                            <span id="year-tag">
                            <select id="dob-year" name="dob-year">
                                <option value="2005">2005</option>
                                <option value="2004">2004</option>
                                <option value="2003">2003</option>
                                <option value="2002">2002</option>
                                <option value="2001">2001</option>
                                <option value="2000">2000</option>
                                <option value="1999">1999</option>
                                <option value="1998">1998</option>
                                <option value="1997">1997</option>
                                <option value="1996">1996</option>
                                <option value="1995">1995</option>
                                <option value="1994">1994</option>
                                <option value="1993">1993</option>
                                <option value="1992">1992</option>
                                <option value="1991">1991</option>
                                <option value="1990">1990</option>
                                <option value="1989">1989</option>
                                <option value="1988">1988</option>
                                <option value="1987">1987</option>
                                <option value="1986">1986</option>
                                <option value="1985">1985</option>
                                <option value="1984">1984</option>
                                <option value="1983">1983</option>
                                <option value="1982">1982</option>
                                <option value="1981">1981</option>
                                <option value="1980">1980</option>
                                <option value="1979">1979</option>
                                <option value="1978">1978</option>
                                <option value="1977">1977</option>
                                <option value="1976">1976</option>
                                <option value="1975">1975</option>
                                <option value="1974">1974</option>
                                <option value="1973">1973</option>
                                <option value="1972">1972</option>
                                <option value="1971">1971</option>
                                <option value="1970">1970</option>
                                <option value="1969">1969</option>
                                <option value="1968">1968</option>
                                <option value="1967">1967</option>
                                <option value="1966">1966</option>
                                <option value="1965">1965</option>
                                <option value="1964">1964</option>
                                <option value="1963">1963</option>
                                <option value="1962">1962</option>
                                <option value="1961">1961</option>
                                <option value="1960">1960</option>
                                <option value="1959">1959</option>
                                <option value="1958">1958</option>
                                <option value="1957">1957</option>
                                <option value="1956">1956</option>
                                <option value="1955">1955</option>
                                <option value="1954">1954</option>
                                <option value="1953">1953</option>
                                <option value="1952">1952</option>
                                <option value="1951">1951</option>
                                <option value="1950">1950</option>
                                <option value="1949">1949</option>
                                <option value="1948">1948</option>
                                <option value="1947">1947</option>
                                <option value="1946">1946</option>
                                <option value="1945">1945</option>
                                <option value="1944">1944</option>
                                <option value="1943">1943</option>
                                <option value="1942">1942</option>
                                <option value="1941">1941</option>
                                <option value="1940">1940</option>
                                <option value="1939">1939</option>
                                <option value="1938">1938</option>
                                <option value="1937">1937</option>
                                <option value="1936">1936</option>
                                <option value="1935">1935</option>
                                <option value="1934">1934</option>
                                <option value="1933">1933</option>
                                <option value="1932">1932</option>
                                <option value="1931">1931</option>
                                <option value="1930">1930</option>
                                <option value="1929">1929</option>
                                <option value="1928">1928</option>
                                <option value="1927">1927</option>
                                <option value="1926">1926</option>
                                <option value="1925">1925</option>
                                <option value="1924">1924</option>
                                <option value="1923">1923</option>
                                <option value="1922">1922</option>
                                <option value="1921">1921</option>
                                <option value="1920">1920</option>
                                <option value="1919">1919</option>
                                <option value="1918">1918</option>
                                <option value="1917">1917</option>
                                <option value="1916">1916</option>
                                <option value="1915">1915</option>
                                <option value="1914">1914</option>
                                <option value="1913">1913</option>
                                <option value="1912">1912</option>
                                <option value="1911">1911</option>
                                <option value="1910">1910</option>
                                <option value="1909">1909</option>
                                <option value="1908">1908</option>
                                <option value="1907">1907</option>
                                <option value="1906">1906</option>
                                <option value="1905">1905</option>
                                <option value="1904">1904</option>
                                <option value="1903">1903</option>
                                <option value="1902">1902</option>
                                <option value="1901">1901</option>
                                <option value="1900">1900</option>
                                <option value="1899">1899</option>
                                <option value="1898">1898</option>
                                <option value="1897">1897</option>
                                <option value="1896">1896</option>
                                <option value="1895">1895</option>
                            </select>
                            </span> </div>
                        <!-- dob wrap -->
                        
                        <label for="country">Where are you?</label>
                        <select id="country" name="country">
                            <option disabled="" value="0">Select your Country</option>
                            <option selected="" value="236">United States</option>
                            <option value="234">United Kingdom</option>
                            <option value="263">Canada</option>
                            <option value="268">Mexico</option>
                            <option value="269">Russia</option>
                            <option value="270">Australia</option>
                            <option value="124">Albania</option>
                            <option value="125">Algeria</option>
                            <option value="126">Argentina</option>
                            <option value="127">Armenia</option>
                            <option value="129">Australia</option>
                            <option value="130" data-redirect-url="http://www.jim-beam.de">Austria</option>
                            <option value="240">Azerbaijan</option>
                            <option value="132">Belarus</option>
                            <option value="133">Belgium</option>
                            <option value="241">Bolivia</option>
                            <option value="242">Bosnia and Herzegovina</option>
                            <option value="136">Brazil</option>
                            <option value="138">Bulgaria</option>
                            <option value="243">Cambodia</option>
                            <option value="139">Cameroon</option>
                            <option value="263">Canada</option>
                            <option value="142">Chile</option>
                            <option value="143">China</option>
                            <option value="144">Colombia</option>
                            <option value="146">Costa Rica</option>
                            <option value="147">Croatia</option>
                            <option value="148">Czech Republic</option>
                            <option value="149">Denmark</option>
                            <option value="150">Ecuador</option>
                            <option value="151">Egypt</option>
                            <option value="153">El Salvador</option>
                            <option value="244">Eritrea</option>
                            <option value="154">Estonia</option>
                            <option value="245">Ethiopia</option>
                            <option value="157">Finland</option>
                            <option value="158">France</option>
                            <option value="246">Georgia</option>
                            <option value="160" data-redirect-url="http://www.jim-beam.de">Germany</option>
                            <option value="161">Greece</option>
                            <option value="162">Guatemala</option>
                            <option value="247">Guyana</option>
                            <option value="163">Honduras</option>
                            <option value="164">Hong Kong</option>
                            <option value="165">Hungary</option>
                            <option value="166">Iceland</option>
                            <option value="167">India</option>
                            <option value="248">Indonesia</option>
                            <option value="249">Ireland</option>
                            <option value="170">Israel</option>
                            <option value="171">Italy</option>
                            <option value="172">Japan</option>
                            <option value="174">Kazakhstan</option>
                            <option value="175">Kenya</option>
                            <option value="177">Kyrgyzstan</option>
                            <option value="178">Latvia</option>
                            <option value="181">Liechtenstein</option>
                            <option value="182">Lithuania</option>
                            <option value="183">Luxembourg</option>
                            <option value="250">Macedonia</option>
                            <option value="184">Malaysia</option>
                            <option value="185">Malta</option>
                            <option value="186">Mauritius</option>
                            <option value="187">Mexico</option>
                            <option value="188">Moldova</option>
                            <option value="251">Mongolia</option>
                            <option value="252">Namibia</option>
                            <option value="193">Netherlands</option>
                            <option value="194">New Zealand</option>
                            <option value="195">Nicaragua</option>
                            <option value="253">Niger</option>
                            <option value="196">Nigeria</option>
                            <option value="197">Norway</option>
                            <option value="200">Palau</option>
                            <option value="201">Panama</option>
                            <option value="254">Papua New Guinea</option>
                            <option value="255">Paraguay</option>
                            <option value="203">Peru</option>
                            <option value="204">Philippines</option>
                            <option value="205">Poland</option>
                            <option value="206">Portugal</option>
                            <option value="207">Romania</option>
                            <option value="208">Russia</option>
                            <option value="209">Samoa</option>
                            <option value="212">Seychelles</option>
                            <option value="213">Singapore</option>
                            <option value="256">Slovak Republic</option>
                            <option value="215">Slovenia</option>
                            <option value="216">Solomon Islands</option>
                            <option value="217">South Africa</option>
                            <option value="218">South Korea</option>
                            <option value="219">Spain</option>
                            <option value="220">Sri Lanka</option>
                            <option value="257">Suriname</option>
                            <option value="223">Sweden</option>
                            <option value="224">Switzerland</option>
                            <option value="227">Thailand</option>
                            <option value="258">Trinidad and Tobago</option>
                            <option value="229">Turkey</option>
                            <option value="230">Turkmenistan</option>
                            <option value="232">Uganda</option>
                            <option value="233">Ukraine</option>
                            <option value="234">United Kingdom</option>
                            <option value="236">United States</option>
                            <option value="259">Uruguay</option>
                            <option value="260">Uzbekistan</option>
                            <option value="237">Vanuatu</option>
                            <option value="238">Venezuela</option>
                            <option value="261">Zambia</option>
                            <option value="239">Zimbabwe</option>
                            <option value="-1">Other</option>
                        </select>
                        <br class="clear">
                        <br class="clear">
                    </fieldset>
                    <input type="submit" name="_send_date_" value="Enter" class="button button-red yes" onclick="return checkAge()">
                    <br class="clear">
                    <br class="clear">
                </form>
            </div>
            <script language="javascript">

function checkAge()

{

/* the minumum age you want to allow in */

var min_age = 21;



var year = parseInt(document.forms["age-entry-form"]["dob-year"].value);

var month = parseInt(document.forms["age-entry-form"]["dob-month"].value) - 1;

var day = parseInt(document.forms["age-entry-form"]["dob-day"].value);



var theirDate = new Date((year + min_age), month, day);

var today = new Date;



var countrySelect = document.forms["age-entry-form"]["country"];

var redirectUrl = 'http://www.maxim.com/sites/default/libraries/jacobsghost/jacobs_storm/index.php';



if ( (today.getTime() - theirDate.getTime()) < 0) {

alert('You are not old enough to enter the site');

window.location = "http://www.centurycouncil.org/";

}

else {

  //SET COOKIE HERE

if (redirectUrl == null){

return true;

} else {
$.cookie('over_age', 'true', { path: '/' });
window.location = redirectUrl;
 
}

}

return false;

}

</script></div>
    </li>
    <div style="text-align:center"></div>
    <div style="text-align:center;color:#808080;font-size:x-small">
        <div style="text-align:center">
            <div><a style="font-weight:bold;color:#808080;font-size:xx-small" href="http://www.jimbeam.com/contact-us">Contact Us</a><span style="font-weight:bold;font-size:xx-small;color:#999999"> &nbsp; |  &nbsp; </span><a style="font-weight:bold;color:#808080;font-size:xx-small" href="http://www.jimbeam.com/privacy">Privacy Policy</a><span style="font-weight:bold;font-size:xx-small;color:#999999"> &nbsp; | &nbsp; </span><a style="font-weight:bold;color:#808080;font-size:xx-small" href="http://www.jimbeam.com/terms">Terms</a><br>
            </div>
        </div>
        <br>
        <span style="font-size:xx-small">Â©  2013 Beam Global Spirits and Wine, Inc. Deerfield, IL <br>
        Jim Beam Brands Co. | 510 Lake Cook Rd. | Deerfield, IL  60015-4964. <br>
        All trademarks are property of their   respective owners.</span><br>
        <br>
    </div>
    </div>
    </div>
    </li>
</ul>
</div>
</div>
</body>
</html>
