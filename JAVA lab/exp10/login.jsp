<%@ page contentType="text/html;charset=UTF-8" language="java" %>
    <html>

    <head>
        <title>Login Page</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
            }

            .login-container {
                background: white;
                padding: 20px;
                border-radius: 10px;
                box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.2);
                width: 300px;
                text-align: center;
            }

            input {
                width: 100%;
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
                transition: 0.3s;
            }

            button:hover {
                background: #0056b3;
            }

            .error {
                color: red;
                font-size: 14px;
            }
        </style>
    </head>

    <body>
        <div class="login-container">
            <h2>Login</h2>
            <form action="validateLogin.jsp" method="post">
                <input type="text" name="username" placeholder="Enter Username" required>
                <input type="password" name="password" placeholder="Enter Password" required>
                <button type="submit">Login</button>
            </form>
        </div>
    </body>

    </html>