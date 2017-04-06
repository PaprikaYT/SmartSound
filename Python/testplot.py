import numpy # import library from Numerical python
import matplotlib.pyplot as plt # import Library from matplotlib
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
import logging
from drawnow import drawnow # import lib from drawnow
logging.getLogger().setLevel(logging.INFO)
import att_iot_client.ATT_IOT as IOT
import  time

IOT.DeviceId = "2nBGwv34DG7WMmxaznPBjKtk"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"
IOT.connect(httpServer='api.allthingstalk.io', secure=False)
ConF = [] # create an empty array for graphing
ConBeer = []
plt.ion() # tell matplotlib you want interactive mode to plot data
cnt = 0

def makeFig(): # creat a function to make plot
    plt.plot(ConF, 'go-',color="orange",linestyle="-",marker="",linewidth=2.5)
    #plt.plot(ConBeer, 'go-', color="black", linestyle="-", marker="", linewidth=5)
    plt.ylim([0, 100])
    plt.style.use('ggplot')
while True: # loop that lasts forever
    x = IOT.getAssetState(1, device=None)
    y = IOT.getAssetState(0, device=None)
    x = str(x)
    y = str(y)
    e, f = y.split(",")
    a, b = x.split(",")
    c = b.replace("}", "")
    g = f.replace("}", "")
    end2 = g.replace("u'value':", "")
    end = c.replace("u'value':", "")
    Con = float(end) # turn string into numbers
    ConF.append(Con) # addinf to the array.
    Conb = float(end2)
    ConBeer.append(Conb)
    drawnow(makeFig)  # call draw now to update
    #plt.pause(.001)
    cnt=cnt+1
    if(cnt>100):
         ConF.pop(0)