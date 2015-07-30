setwd("D:/cjgarcia/Escritorio")

dataGeiger <- read.table("geiger.txt",header=F,sep=";")
colnames(dataGeiger) <- c("Date","CPM","uSperh")
dataGeiger$Date <- as.POSIXct(as.character(dataGeiger$Date), format="%d/%m/%Y %H:%M:%S")

dataGeigerAverage <- aggregate(list(CPM = dataGeiger$CPM), list(hourofday = cut(dataGeiger$Date, "1 hour")), mean)
dataGeigerAverage$CPMNorm <- dataGeigerAverage$CPM/mean(dataGeigerAverage$CPM)

dataCalma <- read.table("calma.txt",header=F,sep=";")
colnames(dataCalma) <- c("Date","CPM")
dataCalma$Date <- as.POSIXct(as.character(dataCalma$Date), format="%Y-%m-%d %H:%M:%S")
dataCalma$CPMNorm <- dataCalma$CPM/mean(dataCalma$CPM)

plot(dataGeigerAverage$CPMNorm, xlab="Hour", ylab="CPM (%)", type="l",col="red", main="Relative CPM of Geiger Counter & CaLMa")
lines(dataCalma$CPMNorm,col="green")
legend("bottomright", legend=c("Geiger", "CaLMa"), col=c('red','green'), lty=1, bty = "n")

fitGeiger <- lm(dataGeigerAverage$CPMNorm ~ poly(seq(1:122), 4, raw=TRUE))
points(seq(1:122), predict(fitGeiger), type="l", col="red", lwd=2)

fitCalma <- lm(dataCalma$CPMNorm ~ poly(seq(1:122), 4, raw=TRUE))
points(seq(1:122), predict(fitCalma), type="l", col="green", lwd=2)
