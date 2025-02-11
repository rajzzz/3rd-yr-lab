A = [2,3,1 ; 4,1,-2 ; -2,1,2];
B = [9;2;-3];
A1 = A;
B1 = B;
disp("Matrix A:", A);
disp("Matrix B:", B);

// Solve the system using Scilab's built-in function
X = A \ B;
disp('The solution using inbuilt functions is:', X);
disp("-----------------------------");

// Augment A and B
augmented = [A, B];
n = size(A, 1);

// Forward Elimination
for i = 1:n-1
    for j = i+1:n
        factor = augmented(j,i)/augmented(i,i);
        augmented(j,i:n+1) = augmented(j,i:n+1) - factor * augmented(i,i:n+1);
    end
end
disp('Augmented Matrix after Forward Elimination:');
disp(augmented);

// Backward Substitution
X = zeros(n, 1);
for i = n:-1:1
    X(i) = (augmented(i, n+1) - augmented(i, 1:n) * X) / augmented(i, i);
end
disp('The solution using Gauss Elimination is:', X);
