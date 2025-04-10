<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Registration</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            background-color: #f4f4f4;
        }

        .container {
            background: white;
            padding: 25px;
            border-radius: 8px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
            width: 350px;
        }

        h2 {
            text-align: center;
            color: #333;
        }

        input {
            width: calc(100% - 24px);
            padding: 10px;
            margin: 10px 0;
            border: 1px solid #ccc;
            border-radius: 5px;
            font-size: 16px;
        }

        button {
            width: 100%;
            padding: 10px;
            background: #007BFF;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-size: 16px;
        }

        button:hover {
            background: #0056b3;
        }
    </style>
</head>

<body>

    <div class="container">
        <h2>User Registration</h2>
        <form action="store.php" method="POST">
            <input type="text" name="name" placeholder="Enter Name" required>
            <input type="text" name="address" placeholder="Enter Address" required>
            <input type="email" name="email" placeholder="Enter Email" required>
            <input type="text" name="mobile" placeholder="Enter Mobile No." required>
            <button type="submit">Register</button>
        </form>
    </div>

</body>

</html>