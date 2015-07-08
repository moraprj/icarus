
<?php
session_start();
?><!DOCTYPE html>


<html lang="en">
	<head>
	
		<meta charset="utf-8">
		<title>About</title>
		<link rel="icon" href="images/favicon.ico">
		<link rel="shortcut icon" href="images/favicon.ico">
		<link rel="stylesheet" href="css/style.css">
		<script src="js/jquery.js"></script>
		<script src="js/jquery-migrate-1.1.1.js"></script>
		<script src="js/jquery.equalheights.js"></script>
		<script src="js/jquery.ui.totop.js"></script>
		<script src="js/jquery.easing.1.3.js"></script>
		<script>
		$(document).ready(function(){
			$().UItoTop({ easingType: 'easeOutQuart' });
		})
		</script>

	
	</head>
	<body class="pt0">
<!--==============================header=================================-->
	<header>
			<div class="container_12">
			
				<div class="grid_12">
					<!--h1><a href="index.html"><img src="images/logo.png" alt="Boo House"></a></h1-->
					<div class="menu_block">
						<nav id="bt-menu" class="bt-menu">
							<a href="#" class="bt-menu-trigger"><span>Menu</span></a>
							<ul>
								<li class="bt-icon"><a href="index.html">Home</a></li>
								<li class="bt-icon"><a href="about-us.html">About</a></li>
								<li class="bt-icon"><a href="gallery.php">Gallery</a></li>
								<li class="bt-icon"><a href="under_const.html">Science Data</a></li>
								<li class="bt-icon"><a href="under_const.html">Blog</a></li>
								<li class="current bt-icon"><a href="contact.php">Contacts</a></li>
							</ul>
						</nav>
						<div class="clear"></div>
					</div>
					<div class="clear"></div>
				</div>
			
			</div>
			<div>
				<h2_im>Icarus Project<h2_im/>
			</div>
		</header>		
	
<!--==============================Content=================================-->
		
					<?php
	if(isset($_POST['email'])) {    
 
    // EDIT THE 2 LINES BELOW AS REQUIRED
     $email_to = "icarusproject15@gmail.com";
     $email_subject = "Contact from Web";
     function died($error) {
         // your error code can go here
         echo "We are very sorry, but there were error(s) found with the form you submitted. ";
         echo "These errors appear below.<br /><br />";
         echo $error."<br /><br />";
         echo "Please go back and fix these errors.<br /><br /> <a href=\"contact.php\" class=\"btn bt1 \" >Back</a>";
         die();
     }
 
    // validation expected data exists
     if(!isset($_POST['first_name']) ||
         !isset($_POST['last_name']) ||
         !isset($_POST['email']) ||
         !isset($_POST['comments'])) {
         died('We are sorry, but there appears to be a problem with the form you submitted. ');       
     }
 
    $first_name = $_POST['first_name']; // required
     $last_name = $_POST['last_name']; // required
     $email_from = $_POST['email']; // required
     $comments = $_POST['comments']; // required
   
 
    $error_message = "";
     $email_exp = '/^[A-Za-z0-9._%-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$/';
   if(!preg_match($email_exp,$email_from)) {
     $error_message .= 'The Email Address you entered does not appear to be valid.<br /> ';
   }
     $string_exp = "/^[A-Za-z .'-]+$/";
   if(!preg_match($string_exp,$first_name)) {
     $error_message .= 'The First Name you entered does not appear to be valid.<br />';
   }
   if(!preg_match($string_exp,$last_name)) {
     $error_message .= 'The Last Name you entered does not appear to be valid.<br />';
   }
   if(strlen($comments) < 2) {
     $error_message .= 'The Comments you entered do not appear to be valid.<br />';
   }
   if(strlen($error_message) > 0) {
     died($error_message);
   }
     $email_message = "Form details below.\n\n";
     
     function clean_string($string) {
       $bad = array("content-type","bcc:","to:","cc:","href");
       return str_replace($bad,"",$string);
     }
      $email_message .= "First Name: ".clean_string($first_name)."\n";
     $email_message .= "Last Name: ".clean_string($last_name)."\n";
     $email_message .= "Email: ".clean_string($email_from)."\n";
     $email_message .= "Comments: ".clean_string($comments)."\n";
  
// create email headers
 $headers = 'From: '.$email_from."\r\n".
 'Reply-To: '.$email_from."\r\n" .
 'X-Mailer: PHP/' . phpversion();
 @mail($email_to, $email_subject, $email_message, $headers);  
 ?>
 
 
 
<!-- include your own success html here -->
 <div class="container_12">
			<div class="text1 col2">
				<br>Thank you for contacting us. We will be in touch with you very soon.<br>
			</div>
			<a href="contact.php" class="btn bt1 " >Back</a>
		</div>
 


 <?php
 
}
 
?>
 	
<!--==============================footer=================================-->
		<footer>
		
			<div class="container_12">
				<div class="grid_12">
					<div class="socials">
						<a href="#" class="fa fa-facebook"></a>
						<a href="https://twitter.com/IcarusUAH" class="fa fa-twitter"></a>
						<a href="#" class="fa fa-google-plus"></a>
					</div>
				</div>
			</div>
		
		</footer>
		<script>
		$(document).ready(function(){
			$(".bt-menu-trigger").toggle(
				function(){
					$('.bt-menu').addClass('bt-menu-open');
				}
			);
		});
		</script>
	</body>
</html>