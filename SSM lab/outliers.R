# Sample dataset: Salaries of 20 employees in thousands
salaries <- c(45, 50, 48, 152, 47, 51, 49, 53, 46, 48, 
              50, 47, 49, 51, 150, 48, 49, 47, 52, 50)
print("USING R INBUILT FUCNTION TO GET OUTLIERS")
outliers_r <-boxplot.stats(salaries)$out
print("Outliers:")
print(outliers_r)

print("MANUAL METHOD TO FIND OUTLIERS")
# Compute Q1, Q3, and IQR
Q1 <- quantile(salaries, 0.25)
Q3 <- quantile(salaries, 0.75)
IQR_value <- Q3 - Q1

# Compute lower and upper bounds for outlier detection
lower_bound <- Q1 - 1.5 * IQR_value
upper_bound <- Q3 + 1.5 * IQR_value

# Identify outliers
outliers <- salaries[salaries < lower_bound | salaries > upper_bound]

# Display results
print(paste("Lower Bound:", lower_bound))
print(paste("Upper Bound:", upper_bound))
print("Outliers detected in the dataset:")
print(outliers)

# Optional: Visual representation using a boxplot
boxplot(salaries, main="Salary Distribution with Outliers", col="skyblue", horizontal=TRUE)
