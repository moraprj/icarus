library(shiny)

dataGiroscope <- read.csv(unz("giroscope.zip","giroscope.csv"),sep=";")
dataGeiger <- read.csv(unz("geiger.zip","geiger.csv"),sep=";")

shinyUI(fluidPage(
  titlePanel("Icarus 2015 Project Data Visualization"),
             
  sidebarLayout(
    
    sidebarPanel(
      
      radioButtons("radioInstrument", "Select Instrument:",
                   choices = list("Giroscope" = 1, "Geiger Counter" = 2),selected = 1),
      
      radioButtons("radioVisualization", "Select Visualization:",
                   choices = list("Show Table" = 1, "Show Plot" = 2),selected = 1),
      
      conditionalPanel(
        condition = "input.radioVisualization == 2 && input.radioInstrument == 1",
        selectInput("xaxisGiroscope", "X Axis:", choices = names(dataGiroscope)),
        selectInput("yaxisGiroscope", "Y Axis:", choices = c("NONE",names(dataGiroscope)))
      ),
      conditionalPanel(
        condition = "input.radioVisualization == 2 && input.radioInstrument == 2",
        selectInput("xaxisGeiger", "X Axis:", choices = names(dataGeiger)),
        selectInput("yaxisGeiger", "Y Axis:", choices = c("NONE",names(dataGeiger)))
      ),
      conditionalPanel(
        condition = "((input.radioInstrument==1 && input.yaxisGiroscope=='NONE') || (input.radioInstrument==2 && input.yaxisGeiger=='NONE')) && input.radioVisualization==2",
        p('Mean'),
        textOutput('textMean'),
        p(''),
        p('Standard Deviation'),
        textOutput('textDeviation')
      )
    ),
    mainPanel(
      conditionalPanel(
        condition = "input.radioVisualization == 1",
        tabsetPanel(
          tabPanel(dataTableOutput("mytable"))
        )
      ),      
      conditionalPanel(
        condition = "input.radioVisualization == 2",
        plotOutput('plot')
      )
    ) 
  )
))