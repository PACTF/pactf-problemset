<?php
	$user = 'Injection2';
	$password = 'injection2';
	$db = 'Injection2';
	$host = 'localhost';
	$port = '';

	$link = mysqli_connect("$host:$port", $user, $password);
  $uname = mysqli_real_escape_string($link, $_POST["username"]);
  $pswd = mysqli_real_escape_string($link, $_POST["password"]);

	// Check connection
	if ($link == false) {
	    die("Connection failed, please contact PACTF and let them know.");
	}

  // Nobody will be able to inject into our code now!
  mysqli_query('SET SQL_MODE="NO_BACKSLASH_ESCAPES"');
	$query = "SELECT * FROM users WHERE username='$uname' AND password='$pswd'";
  $result = mysqli_query($link, $query);

  if (mysqli_num_rows($result) === 1) {
    $row = mysqli_fetch_array($result);
    echo "<h1>Welcome!</h1>";
    if ($row["username"] === "admin") {
      echo "<p>Your flag is: PACTF{k4ppa_pR1d3}</p>";
    }
    else {
      echo "<p>Hey! You aren't admin! Get outta here!</p>";
    }
  }
  else {
    echo "<h1>Login Failed</h1>";
    echo "<p>Get outta here!</p>";
  }
?>
