
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
								<li class="current bt-icon"><a href="gallery.php">Gallery</a></li>
								<li class="bt-icon"><a href="under_const.html">Science Data</a></li>
								<li class="bt-icon"><a href="under_const.html">Blog</a></li>
								<li class="bt-icon"><a href="contact.php">Contacts</a></li>
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
		
	<?php     echo "Hello World" . "\n"; ?>	
		
		
<!--==============================footer=================================-->
		<footer>
		
			<div class="container_12">
				<div class="grid_12">
					<div class="socials">
						<a href="#" class="fa fa-facebook"></a>
						<a href="#" class="fa fa-twitter"></a>
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