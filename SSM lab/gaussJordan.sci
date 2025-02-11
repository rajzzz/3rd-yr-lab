A = [2,3,1 ; 4,1,-2 ; -2,1,2];
B = [9;2;-3];
A1 = A;
B1 = B;

// Augment A and B
augmented = [A, B];
n = size(A, 1);

// Gauss-Jordan Elimination
for i = 1:n
    // Make the diagonal element 1
    augmented(i, :) = augmented(i, :) / augmented(i, i);
    
    // Make other elements in the column 0
    for j = 1:n
        if i ~= j then
            factor = augmented(j, i);
            augmented(j, :) = augmented(j, :) - factor * augmented(i, :);
        end
    end
end

disp('Augmented Matrix after Gauss-Jordan Elimination:');
disp(augmented);

// Extract solution
X = augmented(:, n+1);
disp('The solution using Gauss-Jordan Elimination is:');
disp(X);
