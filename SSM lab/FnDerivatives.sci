function y = f(x)
    y = x.^3 - 5*x.^2 + 2*x + 10;
endfunction

// Define the analytical derivatives manually
disp("Original Function: f(x) = x^3 - 5x^2 + 2x + 10");

f1_x = "3*x^2 - 10*x + 2";  // First derivative
f2_x = "6*x - 10";          // Second derivative

disp("First Derivative: f1(x) = " + f1_x);
disp("Second Derivative: f2(x) = " + f2_x);

// Define the range of x values
x = linspace(-2, 5, 100); // Generates 100 points between -2 and 5

// Compute function values
y = f(x);

// Step size for numerical differentiation
h = 0.01; 

// Compute numerical derivatives using finite differences
df = (f(x + h) - f(x)) / h;  // First derivative (forward difference)
d2f = (f(x + h) - 2*f(x) + f(x - h)) / (h^2);  // Second derivative (central difference)

// Plot f(x), f'(x), and f''(x) on the same graph
figure();
plot(x, y, 'b', "LineWidth", 2);  // Function in blue
plot(x, df, 'r', "LineWidth", 2); // First derivative in red
plot(x, d2f, 'g', "LineWidth", 2); // Second derivative in green
xlabel("x-axis");
ylabel("Function & Derivatives");
title("Function and Its First & Second Derivatives");
legend("f(x)", "f1(x)", "f2(x)", "Location", "best");
xgrid();
