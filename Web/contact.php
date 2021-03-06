<!DOCTYPE html>
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

	<!--div class="content"-->
		<div class="container_12">
			<div class="text1 col2">
				<br>For any question about the balloon, its construction, SW coded, or HW used... 
				please write us using the following form. We will answer you by mail or blog entrance if its a good piece of 
				knowledge that we forgot to share.<br><br>Thanks for watching our web and showing interest in our project!!<br><br>Cheers!!<br><div style="margin: 30px">Icarus Team.</div>
			</div>
		</div>
	<!--/div-->
	
	<div class="gray_block"><br><br>
	<form name="contactform" method="post" action="send_form_email.php">
	
		<div class="container_12">
			<div class="grid_2">
				<label for="first_name">First Name *</label>
			</div>
		
			<div class="grid_10">
				<input  type="text" name="first_name" maxlength="50" size="30">
			</div>
		</div>
		<br>
		<div class="container_12">
			<div class="grid_2">
				<label for="last_name">Last Name *</label>
			</div>
		
			<div class="grid_10">
				<input  type="text" name="last_name" maxlength="50" size="30">
			</div>
		</div><br>
		<div class="container_12">
			<div class="grid_2">
				<label for="email">Email Address *</label>
			</div>
		
			<div class="grid_10">
				<input  type="text" name="email" maxlength="80" size="30">
			</div>
		</div><br>
		<div class="container_12">
			<div class="grid_2">
				<label for="comments">Comments *</label>
			</div>
		
			<div class="grid_10">
				<textarea  name="comments" maxlength="1000" cols="25" rows="6"></textarea>
			</div>
		</div>
		<div class="container_12">
				
				<input type="submit" value="Send...">   <!--a href="http://www.freecontactform.com/email_form.php"></a-->

 
			
		</div>
		
		
		
	</form>
	</div>
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