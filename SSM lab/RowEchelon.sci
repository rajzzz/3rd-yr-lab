A=[2,3,1;4,1,-2;-2,1,2];
[n,m]=size(A);
if m~=n then
    disp("Error: the matrix is not square");
else 
    disp("Original Matrix:")
    disp(A);
    for i = 1:n
        A(i, :) = A(i, :) / A(i, i);
        
        for j = 1:n
            if i ~= j
                fact = A(j, i);
                A(j, :) = A(j, :) - fact * A(i, :);
            end
        end
    end
    disp("Reduced Echelon Form:");
    disp(A);
end