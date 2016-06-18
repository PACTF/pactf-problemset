<?php
	$user = 'localhost';
	$password = 'mVNPmVQmfHYU7Jaa';
	$db = 'Injection1';
	$host = '127.0.0.1';
	$port = 3306;

	$link = mysqli_connect("$host:$port", $user, $password);

	// Check connection
	if ($link == false) {
	    die("Connection failed, please contact pactf through irc.");
	}
	$query = "SELECT * FROM `Flags`";
	$result = mysqli_query($link, $query);
	echo("test: $result");
?>
