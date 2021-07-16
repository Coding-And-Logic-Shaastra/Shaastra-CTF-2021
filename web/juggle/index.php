<?php
if (isset($_GET['param'])) {
    if ($_GET['param'] === "240610708") {
        die('Did you think it was that easy?');
    }

    $hash = md5($_GET['param']);
    $answer = md5(240610708);

    if($hash == $answer) {
        include('flag.php');
        print $flag;
    } 
    
    else {
        print "Wrong parameter";
    }
} 

else {
   show_source(__FILE__);
}
?>