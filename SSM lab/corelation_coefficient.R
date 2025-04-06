set.seed(42)

x <- c(10, 22, 30, 45, 50, 60, 75, 80)
y <- c(12, 26, 29, 47, 58, 64, 71, 90) + rnorm(8, mean=0, sd=5)

pearson_cor <- cor(x, y, method="pearson")
spearman_cor <- cor(x, y, method="spearman")

cat("Pearson Correlation:", pearson_cor, "\n")
cat("Spearman Correlation:", spearman_cor, "\n")

plot(x, y, main="Pearson vs Spearman", col="blue", pch=19, xlab="X", ylab="Y")

abline(lm(y ~ x), col="red", lwd=3, lty=3)
lines(lowess(x, y), col="green", lwd=2)

legend("topleft", legend=c("Pearson (Linear)", "Spearman (Non-linear)"),
       col=c("red", "green"), lwd=2, lty=c(2,1), cex=0.8)
