library(shiny)

dataGiroscope <- read.csv(unz("giroscope.zip","giroscope.csv"),sep=";")
dataGeiger <- read.csv(unz("geiger.zip","geiger.csv"),sep=";")

shinyServer(
  function(input, output) {
    
    output$textMean <- renderText({
      if(input$radioInstrument==1){
        x<-dataGiroscope[,input$xaxisGiroscope]
      }
      else{
        x<-dataGeiger[,input$xaxisGeiger]
      }
      mean(x)
    })
    output$textDeviation <- renderText({
      if(input$radioInstrument==1){
        x<-dataGiroscope[,input$xaxisGiroscope]
      }
      else{
        x<-dataGeiger[,input$xaxisGeiger]
      }
      sd(x)
    })
    
    output$mytable = renderDataTable({
      if(input$radioInstrument==1){
        dataGiroscope[,]
      }
      else{
        dataGeiger[,]
      }
    })
    
    output$plot <- renderPlot({
      if(input$radioInstrument==1){
        x<-dataGiroscope[,input$xaxisGiroscope]
        if(input$yaxisGiroscope=="NONE"){
          hist(x, xlab=input$xaxisGiroscope, col='lightblue',main='Histogram')        
        }
        else{
          if(input$radioInstrument==1){
            y<-dataGiroscope[,input$yaxisGiroscope]
          }
          else{
            y<-dataGeiger[,input$yaxisGiroscope]
          }        
          plot(x,y, xlab=input$xaxisGiroscope, ylab=input$yaxisGiroscope, col='lightblue')
          abline(lm(y~x), col='red')
        }
      }
      else{
        x<-dataGeiger[,input$xaxisGeiger]
        if(input$yaxisGeiger=="NONE"){
          hist(x, xlab=input$xaxisGeiger, col='lightblue',main='Histogram')        
        }
        else{
          if(input$radioInstrument==1){
            y<-dataGiroscope[,input$yaxisGeiger]
          }
          else{
            y<-dataGeiger[,input$yaxisGeiger]
          }        
          plot(x,y, xlab=input$xaxisGeiger, ylab=input$yaxisGeiger, col='lightblue')
          abline(lm(y~x), col='red')
        }
      }      
    })
  }
)