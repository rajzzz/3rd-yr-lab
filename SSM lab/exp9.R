library(ggplot2)
study_hours <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
exam_scores <- c(35, 45, 50, 55, 60, 65, 72, 78, 85, 90)

df <- data.frame(study_hours, exam_scores)

model <- lm(exam_scores ~ study_hours, data = df)

ggplot(df, aes(x = study_hours, y = exam_scores)) +
  geom_point(color = "blue", size = 3) +
  geom_smooth(method = "lm", se = FALSE, color = "red") +
  ggtitle("Scatter Plot") +
  xlab("Study Hours") +
  ylab("Exam Scores")

residuals_df <- data.frame(
  study_hours = df$study_hours,
  residuals = resid(model)
)

ggplot(residuals_df, aes(x = study_hours, y = residuals)) +
  geom_point(color = "darkgreen", size = 3) +
  geom_hline(yintercept = 0, linetype = "dashed", color = "red") +
  ggtitle("Residual Plot") +
  xlab("Study Hours") +
  ylab("Residuals")

leverage_df <- data.frame(
  index = 1:nrow(df),
  leverage = hatvalues(model)
)

ggplot(leverage_df, aes(x = index, y = leverage)) +
  geom_point(color = "purple", size = 3) +
  geom_hline(yintercept = 2 * mean(hatvalues(model)), linetype = "dashed", color = "red") +
  ggtitle("Leverage Plot (Hat Values)") +
  xlab("Index") +
  ylab("Leverage")

cooks_df <- data.frame(
  index = 1:nrow(df),
  cooks_distance = cooks.distance(model)
)

ggplot(cooks_df, aes(x = index, y = cooks_distance)) +
  geom_point(color = "orange", size = 3) +
  geom_hline(yintercept = 4 / nrow(df), linetype = "dashed", color = "red") +
  ggtitle("Cook's Distance (Influence Plot)") +
  xlab("Index") +
  ylab("Cook's Distance")
