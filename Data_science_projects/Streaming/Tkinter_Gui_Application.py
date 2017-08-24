
# coding: utf-8


#By Ater Akrofi
#Python program to stream real time temperature updates for California and New Jersey
#This code was adapted from code for plotting live bitcoin prices (https://pythonprogramming.net/how-to-embed-matplotlib-graph-tkinter-gui/)

import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
import matplotlib.animation as animation
from matplotlib import style

import tkinter as tk
from tkinter import ttk
import requests
import urllib
import json
import datetime
import time
import pandas as pd
import numpy as np
from __future__ import division
from matplotlib import pyplot as plt


LARGE_FONT= ("Verdana", 12)
style.use("ggplot")

f = Figure()
a = f.add_subplot(111)


def animate(i):
    global refreshRate
    
    #Accessing Weather API for New Jersey
    d = json.loads(requests.get('http://api.openweathermap.org/data/2.5/forecast?id=5101760&APPID=0ca24c347e9df5abc1979107ee4b8454').text)
    
    #Accessing Weather API for California
    df = json.loads(requests.get('http://api.openweathermap.org/data/2.5/forecast?id=4350049&APPID=e7601f2ba29afc9fc889fceab3594771').text)
  
   #Extracting data from API using pandas
    Dlist=pd.DataFrame(d["list"])
    main = pd.DataFrame(Dlist["main"])
    
    Alist=pd.DataFrame(df["list"])
    main_1 = pd.DataFrame(Alist["main"])
    
    #Coverting json url to clean dataframe
    data = pd.read_json( (main['main']).to_json(), orient='index')
    data1 = pd.read_json( (main_1['main']).to_json(), orient='index')
    
    
    temp_max_CA = np.array(data1['temp_max']) #minimum temperature
    time=np.array(pd.DataFrame(Alist["dt"])) 
    time_stamp =time/1000    #coverting datetime to seconds
            
    
    temp_max_NJ = np.array(data['temp_max']) #minimum temperature
    time=np.array(pd.DataFrame(Dlist["dt"])) 
    time_stamp1 =time/1000    #coverting datetime to seconds

    a.clear()

    #Plotting 2 graphs, each with x-axis and y-axis
    a.plot_date(time_stamp, temp_max_CA, "#e84767", label="California")
    a.plot_date(time_stamp1, temp_max_NJ, "#2fad0c", label="New Jersey")
    a.set_xlabel('Timestamp')
    a.set_ylabel('Temperature')
    a.legend(bbox_to_anchor=(0, 1.02, 1, .102), loc=3,
             ncol=2, borderaxespad=0)
    
    #set header for graph with additional information
    header =data["temp"]
    header1 =data1["temp"]
    title ="Current Temp-NJ : " + str(header[0])
    title1 ="Current Temp-CA : " + str(header1[0])
    

    a.set_title(title)
 
    f.suptitle(title1)


    
    #Class to control frames
class Stream(tk.Tk):

    def __init__(self, *args, **kwargs):
        
        tk.Tk.__init__(self, *args, **kwargs)

        
        tk.Tk.wm_title(self, "Streamer App")
        
        
        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand = True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)


        

        self.frames = {}

        for F in (Main, Graph):

            frame = F(container, self)

            self.frames[F] = frame

            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(Main)

    def show_frame(self, cont):

        frame = self.frames[cont]
        frame.tkraise()

    
        # Main page
class Main(tk.Frame):

    #Initializing window
    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        
        
        #set labels to window
        label = tk.Label(self, text=("""Temperature Update"""), font=LARGE_FONT)
        label.pack(pady=10,padx=10)

       

        label = tk.Label(self, text=("""Application to demonstrate plotting live real time data"""), font=LARGE_FONT)
        label.pack(pady=50,padx=50)

         #creating buttons
        button1 = ttk.Button(self, text="Real time Update ",
                            command=lambda: controller.show_frame(Graph))
        button1.pack()

        button2 = ttk.Button(self, text="Exit",
                            command=quit)
        button2.pack()
        
#graph page
class Graph(tk.Frame):
        
        #Initializing Window
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        #Set Labels
        label = tk.Label(self, text="Temperature Readings", font=LARGE_FONT)
        label.pack(pady=10,padx=10)
        
        #Create Buttons
        button1 = ttk.Button(self, text="Back to Home",
                            command=lambda: controller.show_frame(Main))
        button1.pack()

        
        #Display Graph on canvas
        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.BOTTOM, fill=tk.BOTH, expand=True)

        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.TOP, fill=tk.BOTH, expand=True)



Gui = Stream()
Gui.geometry("1280x720")
streamer = animation.FuncAnimation(f, animate, interval=7200 )
Gui.mainloop()




