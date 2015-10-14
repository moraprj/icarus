###Grafica de los datos geiger en crudo

setwd("D:/cjgarcia/Escritorio")

dataGeiger <- read.table("geiger.txt",header=F,sep=";")
colnames(dataGeiger) <- c("Date","CPM","uSperh")
dataGeiger$Date <- as.POSIXct(as.character(dataGeiger$Date), format="%d/%m/%Y %H:%M:%S")

dataGeigerAverage <- aggregate(list(CPM = dataGeiger$CPM), list(hourofday = cut(dataGeiger$Date, "1 hour")), mean)
dataGeigerAverage$Mean <- mean(dataGeigerAverage$CPM)
plot(dataGeigerAverage$CPM, xlab="Hour", ylab="CPM", type="l",col="red", main="Raw Data Geiger Counter")
lines(dataGeigerAverage$Mean,col="green")
legend("bottomright", legend=c(sprintf("%.2f",mean(dataGeigerAverage$CPM))), col=c('green'), lty=1, bty = "n")

###Grafica de los datos de calma en crudo

dataCalma <- read.table("calma.txt",header=F,sep=";")
colnames(dataCalma) <- c("Date","CPM")
dataCalma$Date <- as.POSIXct(as.character(dataCalma$Date), format="%Y-%m-%d %H:%M:%S")

dataCalma$Mean <- mean(dataCalma$CPM)

plot(dataCalma$CPM, xlab="Hour", ylab="CPM", type="l",col="red", main="Raw Data CaLMa")
lines(dataCalma$Mean,col="green")
legend("bottomright", legend=c(sprintf("%.2f",mean(dataCalma$CPM))), col=c('green'), lty=1, bty = "n")


###Grafica de los datos geiger normalizados
dataGeigerAverage$CPMNorm <- dataGeigerAverage$CPM/mean(dataGeigerAverage$CPM)

plot(dataGeigerAverage$CPMNorm, xlab="Hour", ylab="CPM (%)", type="l",col="red", main="Normalized Data Geiger Counter")

###Grafica de los calma normalizados

dataCalma$CPMNorm <- dataCalma$CPM/mean(dataCalma$CPM)

plot(dataCalma$CPMNorm, xlab="Hour", ylab="CPM (%)", type="l",col="red", main="Normalized Data CaLMa")


###Grafica de los datos normalizados conjuntos

plot(dataGeigerAverage$CPMNorm, xlab="Hour", ylab="CPM (%)", type="l",col="red", main="Normalized Data of Geiger Counter & CaLMa")
lines(dataCalma$CPMNorm,col="green")
legend("bottomright", legend=c("Geiger", "CaLMa"), col=c('red','green'), lty=1, bty = "n")


####################



dataPressure <- read.table("pressure.txt",header=F,sep=";")
colnames(dataPressure) <- c("Date","Pressure")
dataPressure$Date <- as.POSIXct(as.character(dataPressure$Date), format="%Y-%m-%d %H:%M:%S")

plot(dataPressure$Pressure, xlab="Hour", ylab="Bar", type="l",col="red", main="Pressure at CaLMa")

dataGeigerPreCorrected <- data.frame(log(dataGeigerAverage$CPM/mean(dataGeigerAverage$CPM)),dataPressure$Pressure-935)
colnames(dataGeigerPreCorrected) <- c("CPM","Pressure")

plot(dataGeigerPreCorrected$CPM ~ dataGeigerPreCorrected$Pressure, xlab="P-Po", ylab="ln(CPM/mean)", type="p",col="red")
abline(lm(dataGeigerPreCorrected$CPM ~ dataGeigerPreCorrected$Pressure))

beta <- coefficients(lm(dataGeigerPreCorrected$CPM ~ dataGeigerPreCorrected$Pressure))[2][[1]]

dataGeigerCorrected <- data.frame(dataGeigerAverage$hourofday,dataGeigerAverage$CPM*exp(beta*(dataPressure$Pressure-935)))
colnames(dataGeigerCorrected) <- c("Date","CPM")
dataGeigerCorrected$CPMNorm <- dataGeigerCorrected$CPM/mean(dataGeigerCorrected$CPM)

plot(dataGeigerCorrected$CPMNorm, xlab="Hour", ylab="CPM (%)", type="l",col="red", main="Corrected & Not Corrected Relative CPM of Geiger Counter")
lines(dataGeigerAverage$CPMNorm,col="green")
legend("bottomright", legend=c("Corrected", "Not Corrected"), col=c('red','green'), lty=1, bty = "n")




dataCalmaPreCorrected <- data.frame(log(dataCalma$CPM/mean(dataCalma$CPM)),dataPressure$Pressure-935)
colnames(dataCalmaPreCorrected) <- c("CPM","Pressure")

plot(dataCalmaPreCorrected$CPM ~ dataCalmaPreCorrected$Pressure, xlab="P-Po", ylab="ln(CPM/mean)", type="p",col="red")
abline(lm(dataCalmaPreCorrected$CPM ~ dataCalmaPreCorrected$Pressure))

beta <- coefficients(lm(dataCalmaPreCorrected$CPM ~ dataCalmaPreCorrected$Pressure))[2][[1]]

dataCalmaCorrected <- data.frame(dataCalma$Date,dataCalma$CPM*exp(beta*(dataPressure$Pressure-935)))
colnames(dataCalmaCorrected) <- c("Date","CPM")
dataCalmaCorrected$CPMNorm <- dataCalmaCorrected$CPM/mean(dataCalmaCorrected$CPM)

plot(dataCalmaCorrected$CPMNorm, xlab="Hour", ylab="CPM (%)", type="l",col="red", main="Corrected & Not Corrected Relative CPM of Calma")
lines(dataCalma$CPMNorm,col="green")
legend("bottomright", legend=c("Corrected", "Not Corrected"), col=c('red','green'), lty=1, bty = "n")



plot(dataGeigerCorrected$CPMNorm, xlab="Hour", ylab="CPM (%)", type="l",col="red", main="Relative Corrected CPM of Geiger Counter & CaLMa")
lines(dataCalmaCorrected$CPMNorm,col="green")
legend("bottomright", legend=c("Geiger", "CaLMa"), col=c('red','green'), lty=1, bty = "n")






fitGeiger <- lm(ataGeigerCorrected$CPMNorm ~ poly(seq(1:122), 4, raw=TRUE))
points(seq(1:122), predict(fitGeiger), type="l", col="red", lwd=2)

fitCalma <- lm(dataCalmaCorrected$CPMNorm ~ poly(seq(1:122), 4, raw=TRUE))
points(seq(1:122), predict(fitCalma), type="l", col="green", lwd=2)
