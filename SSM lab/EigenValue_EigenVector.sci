//Eigen Values and Eigen Vectors 
A = [4, 1;2,3];  
[m, n] = size(A); 
if m ~= n then 
    disp("Error: The matrix is not square. Eigenvalues and eigenvectors cannot be computed."); 
else 
    disp("Matrix A:"); 
    disp(A); 
    [EigenVectors, EigenValues] = spec(A); 
    disp("Eigenvalues of A:"); 
    disp(diag(EigenValues)); 
    disp("Eigenvectors of A:"); 
    disp(EigenVectors); 
end