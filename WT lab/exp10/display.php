<?php
$servername = "localhost";
$username = "root"; // Change if necessary
$password = ""; // Change if you have set a password
$dbname = "pulkit";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// SQL query to retrieve users
$sql = "SELECT * FROM users";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registered Users</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            background-color: #f4f4f4;
        }

        table {
            width: 70%;
            margin: 20px auto;
            border-collapse: collapse;
            background: white;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
        }

        th,
        td {
            padding: 10px;
            border: 1px solid #ddd;
        }

        th {
            background: #007BFF;
            color: white;
        }
    </style>
</head>

<body>

    <h2>Registered Users</h2>
    <table>
        <tr>
            <th>Name</th>
            <th>Address</th>
            <th>Email</th>
            <th>Mobile No</th>
        </tr>
        <?php
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                echo "<tr><td>" . $row['name'] . "</td><td>" . $row['address'] . "</td><td>" . $row['email'] . "</td><td>" . $row['mobile'] . "</td></tr>";
            }
        } else {
            echo "<tr><td colspan='4'>No users found</td></tr>";
        }
        ?>
    </table>

</body>

</html>

<?php
$conn->close();
?>