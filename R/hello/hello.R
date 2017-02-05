nba <- read.csv("nba_2013.csv")

dim(nba)

head(nba, 1)

sapply(nba, mean, na.rm=TRUE)
