# Sample dataset: marks of students
scores <- c(85, 92, 88, 70, 75, 85, 92, 88, 70, 75, 95, 80, 85, 90, 92, 85, 70, 88, 75, 95)

# Create frequency table
freq_table <- table(scores)

print("Simple Frequency Table:")
print(freq_table)

# Bar plot of the frequency table
barplot(freq_table, 
        main = "Frequency Distribution of Scores", 
        xlab = "Scores", 
        ylab = "Frequency", 
        col = "skyblue",
        border = "black")