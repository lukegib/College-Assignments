<html>
<head>
</head>
<body>
<?php
	$text = $_POST['txtarea'];
	$exp = explode(" ", $text);
	$words = count($exp);

	for ($i=0; $i<$words; $i++)
		echo $exp[$i] . "<br>";
?>
</body>
</html>