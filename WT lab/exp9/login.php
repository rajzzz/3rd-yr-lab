<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = trim($_POST['username']);
    $password = trim($_POST['password']);

    $file = "users.txt"; // File containing credentials
    $loginSuccess = false; // Flag for authentication

    if (file_exists($file)) {
        $users = file($file, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

        foreach ($users as $user) {
            list($stored_user, $stored_pass) = explode(":", $user);

            if ($username == $stored_user && $password == $stored_pass) {
                $loginSuccess = true;
                break;
            }
        }
    }

?>
    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Login Status</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
                background-color: #f4f4f4;
            }

            .message-box {
                padding: 20px;
                border-radius: 8px;
                text-align: center;
                width: 350px;
                font-size: 18px;
                box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
                background: white;
            }

            .success {
                border: 2px solid #28a745;
                color: #155724;
                background: #d4edda;
            }

            .error {
                border: 2px solid #dc3545;
                color: #721c24;
                background: #f8d7da;
            }

            .back-button {
                display: block;
                margin-top: 20px;
                padding: 10px;
                text-decoration: none;
                background: #007BFF;
                color: white;
                border-radius: 5px;
                transition: 0.3s;
            }

            .back-button:hover {
                background: #0056b3;
            }
        </style>
    </head>

    <body>
        <div class="message-box <?php echo $loginSuccess ? 'success' : 'error'; ?>">
            <?php
            if ($loginSuccess) {
                echo "<h2>✅ Login Successful!</h2><p>Welcome, <strong>$username</strong>.</p>";
            } else {
                echo "<h2>❌ Invalid Credentials</h2><p>Incorrect username or password.</p>";
            }
            ?>
            <a href="index.html" class="back-button">Back to Login</a>
        </div>
    </body>

    </html>
<?php
}
?>