<?php
$servername = "localhost";
$username = "root"; // Change this if necessary
$password = ""; // Change if you have set a password
$dbname = "pulkit";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Retrieve form data
$name = $_POST['name'];
$address = $_POST['address'];
$email = $_POST['email'];
$mobile = $_POST['mobile'];

// SQL query to insert data
$sql = "INSERT INTO users (name, address, email, mobile) VALUES ('$name', '$address', '$email', '$mobile')";

if ($conn->query($sql) === TRUE) {
    echo "<script>alert('Registration Successful!'); window.location.href='display.php';</script>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

// Close connection
$conn->close();
