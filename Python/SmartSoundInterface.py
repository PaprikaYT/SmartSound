__autor__="Michael Kirsch"
from Tkinter import *
import random
import logging
logging.getLogger().setLevel(logging.INFO)
import att_iot_client.ATT_IOT as IOT

width=1920
height=1080
photoname="back4.png"


IOT.DeviceId = "c3Sup5D8N5bCVCS4pdMPzO5D"
IOT.ClientId = "PaprikaYT_gcHaggvf"
IOT.ClientKey = "G0sFl3FM"
IOT.connect(httpServer='api.allthingstalk.io', secure=False)

master = Tk()
master.attributes("-fullscreen", True)
bool=True

def getint(asssetid):
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    b=int(b)
    return b

def getfloat(asssetid):
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    b=float(b)
    return b

def getstring(asssetid):
    x = IOT.getAssetState(asssetid, device=None)
    x = str(x)
    a, b = x.split(",")
    b = b.replace("}", "")
    b=b.replace("u'value':", "")
    return b

def output():
    w.delete("all")
    level=getint(0)
    sound = "Soundlevel:" + str(getint(1)) + "%"
    beer = "LEVEL:" + str(level)
    w.create_image(width, 0, anchor=NE, image=filename)
    w.create_text(width/2, height*0.3, text=sound, fill="#ff471a", font=('Ubuntu', '100', 'bold'))
    w.create_text(width/2,height*0.6,text=beer,fill="grey",font=("Ubuntu", 130))
    if level>=0 and level<10:
        message="You have nothing unlocked.\n   Someone should tell the guys to keep the noise down"
    elif level >= 10 and level < 20:
        message = "You only have one beer unlocked.\n   Keep quiet to get the next one!!"
    elif level >= 20 and level < 30:
        message = "You got the second reward, well done.\n  Keep quiet to get the next one!!"
    elif level >= 30 and level < 40:
        message = "Yeah the third one is unlocked, keep going !!"
    elif level >= 40 and level < 50:
        message = "four of them unlocked. Well done !! "
    elif level == 50:
        message = "EVERYTHING UNLOCKED!!! Congratulations !"
    w.create_text(width/2, height * 0.8, text=message, fill="white", font=("Ubuntu", 60))
    master.after(300, output)

def togglefullscreen(event):
    master.attributes("-fullscreen", False)

master.bind("<Key>", togglefullscreen)
w = Canvas(master, width=width, height=height)
filename = PhotoImage(file = photoname)
w.pack()
output()
mainloop()