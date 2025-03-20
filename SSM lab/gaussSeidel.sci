A = [4,-1,1; -1,3,-1; 1,-1,3]; 
disp("Coefficients of A:");
disp(A);
b = [7; 4; 3]; 
disp("Constants:");
disp(b);
m = 3;               
x = zeros(m, 1);     
MaxIter = 10;         
disp("Iteration     x         y          z"); 
disp("------------------------------------------");
for Iter = 1:MaxIter 
    prev_x = x; 
     
    for i = 1:m 
        s = 0; 
        for j = 1:m 
            if i ~= j then 
                s = s + A(i, j) * x(j); 
            end 
        end 
        x(i) = (b(i) - s) / A(i, i); 
    end  
     
    disp(msprintf("\t%d    %f\t%f   %f", Iter, x(1), x(2), x(3))); 
    if norm(x - prev_x, "inf") < 0.0001 then 
        break; 
    end 
end 

disp("The approximate solutions are:"); 
disp("x = " + string(x(1)) ); 
disp("y = " + string(x(2)) ); 
disp("z = " + string(x(3)) );
