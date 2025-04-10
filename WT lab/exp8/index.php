<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Display Users from File</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            padding: 20px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th,
        td {
            border: 1px solid black;
            padding: 10px;
            text-align: left;
        }

        th {
            background-color: #f2f2f2;
        }
    </style>
</head>

<body>

    <h2>Users Information</h2>

    <table>
        <tr>
            <th>Name</th>
            <th>Password</th>
            <th>Email</th>
        </tr>

        <?php
        $file = "sample.txt"; // File name

        if (file_exists($file)) {
            $handle = fopen($file, "r"); // Open file for reading

            while (!feof($handle)) { // Loop until end of file
                $name = trim(fgets($handle)); // Read name line
                $password = trim(fgets($handle)); // Read password line
                $email = trim(fgets($handle)); // Read email line
                fgets($handle); // Read empty line (skip it)

                if (!empty($name) && !empty($password) && !empty($email)) {
                    echo "<tr>
                            <td>" . str_replace("Name: ", "", $name) . "</td>
                            <td>" . str_replace("Password: ", "", $password) . "</td>
                            <td>" . str_replace("Email: ", "", $email) . "</td>
                          </tr>";
                }
            }

            fclose($handle); // Close file
        } else {
            echo "<tr><td colspan='3'>File not found!</td></tr>";
        }
        ?>

    </table>

</body>

</html>